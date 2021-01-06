/**
 * @brief iniファイル操作関係
 * 
 * @details
 * Windowsのiniファイルを読み書きする機能を提供する。
 * WIN32 APIのWritePrivateProfileString()とGetPrivateProfileString()関数
 * と同等の動きをする関数を提供する。(完全互換ではないと思う。)
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2020/11/22
 * 
 * @copyright 2020, Masanori Miyamoto. All rights reserved.
 * 
 * @par 変更履歴
 * - 2020/11/22: M.Miyamoto.: 
 */

/*
 * MIT License
 * 
 * Copyright (c) 2020 Masanori Miyamoto
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdio.h>
#include <stdlib.h>
#if !defined(LSI_C) && !defined(_MSC_VER) && !defined(__XC__)
#include <unistd.h>
#endif
#include <limits.h>
#include <string.h>
#ifndef NP2_SDL
#include "toolbox/toolbox.h"
#include "toolbox/memchk.h"
#endif
#include "toolbox/inifile.h"

/** 
 * @brief Key-Value型
 */
typedef struct _ini_keyvalue INI_KEYVALUE;
/** 
 * @brief セクション型
 */
typedef struct _ini_section INI_SECTION;

/** 
 * @brief Key-Value情報
 * @details
 * キーに対する値を保存する構造体
 */
struct _ini_keyvalue {
    char *key;          /**< キー文字列 */
    char *val;          /**< 値 */
    char *line;         /**< 行データ。mallocで確保して'='の部分を'\0'にして
                          keyとvalにそれぞれの先頭アドレスを設定する */
    INI_KEYVALUE *next; /**< 次のKey-Value情報。NULLなら最後の情報 */
};

/** 
 * @brief セクション情報
 * @details
 * セクション名、セクション内のKey-Value情報を保存する構造体
 */
struct _ini_section {
    char *sectionName;          /**< セクション名 */
    INI_KEYVALUE *keyValue;     /**< Key-Valueリストへのポインタ */
    INI_SECTION *next;          /**< 次のセクション情報。NULLなら最後の情報 */
};

/** @name ファイル内ローカル変数
 */
/** @{ */
/** 
 * @brief iniファイル情報のキャッシュ
 * @details
 * 読み込んだiniファイル情報へのポインタ変数
 */
static INI_SECTION *s_section = NULL;
/** @brief キャッシュしているiniファイル名 */
static char s_inifilename[PATH_MAX] = { 0 };
/** @brief キャッシュしている情報更新フラグ */
static TB_BOOL s_update_flag = TB_FALSE;
/** @brief 行読み込みバッファ */
static char *read_line_buf = NULL;
/** @brief 行読み込みバッファ確保済みメモリブロック数 */
static int read_line_block_len = 0;
/** @} */

static TB_BOOL addSection(const char *section);
static INI_SECTION *searchSection(const char *section);
static TB_BOOL addKeyValue(INI_SECTION *ini_section, const char *key, const char *value, const char *line);
static INI_KEYVALUE *searchKeyValue(const INI_SECTION *ini_section, const char *key);
static void freeKeyValue(INI_KEYVALUE *ini_keyvalue);
static void freeSection(INI_SECTION *ini_section);
static char *readLine(FILE *fp);
static TB_BOOL loadIniFile(const char *filename);
static TB_BOOL saveIniFile(const char *filename);
static void print_ini();


/** @name ファイル内ローカル関数
 */
/** @{ */
/**
 * @brief 文字列のコピー
 * @details
 * str2からstr1へ文字列をコピーする。
 * strncpyとの違いは、str2文字列がnバイト以上なら
 * n-1バイトコピーし、最後に0を入れようになっている。
 * 
 * @param[out] 	str1 	文字列のコピー先のアドレス
 * @param[in] 	str2 	文字列のコピー元のアドレス
 * @param[in] 	n 	    コピーサイズ
 * @return コピー先の先頭アドレス
 * 
 */
static char *tb_strncpy(char *str1, const char *str2, size_t n)
{
    char *ret;

    ret = strncpy(str1, str2, n);
    if(ret[n-1] != 0) {
        ret[n-1] = 0;
    }
    return ret;
}

/**
 * @brief 文字列のトリム
 * @details
 * 文字列の先頭と最後にあるスペースおよび制御コード(0x20以下のコード)を
 * カットする。
 * - 具体的には、文字列の最後から先頭方向に向かってにスペースおよび
 *   制御コード以外が出現するまで0で埋める。
 * - 文字列の先頭からスペースおよび制御コード以外が出現するアドレスを
 *   関数の戻り値として返す。文字列の先頭側は0では埋めない。
 * 
 * @param[in] 	str 	トリムする文字列(内容は潰れる)
 * @return トリムした文字列の先頭アドレス
 * 
 */
static char *trim(char *str)
{
    char *ret = str;
    int i;
    size_t len;

    len = strlen(str);
    for(i = 0; i < len; i++) {
        if((str[i] & 0xff) > 0x20) {
            ret = &str[i];
            break;
        }
    }

    if(len != 0) {
        for(i = len - 1; len >= 0; i--) {
            if((str[i] & 0xff) > 0x20) {
                break;
            } else {
                str[i] = 0;
            }
        }
    }
    return ret;
}

/**
 * @brief キャッシュしているiniファイル情報にセクションを追加
 * @details
 * キャッシュしているiniファイル情報にセクションを追加する。
 * 
 * @param[in] 	section 	セクション名
 * @retval TRUE 成功
 * @retval FALSE 失敗
 * 
 */
static TB_BOOL addSection(const char *section)
{
    INI_SECTION *new_item, *tmp;
    size_t len;

    /* 同じ名前のセクションがあったら終了 */
    if(searchSection(section)) {
        return TB_FALSE;
    }

    /* セクションのメモリを生成 */
    new_item = (INI_SECTION*)calloc(1, sizeof(INI_SECTION));
    if(!new_item) {
        return TB_FALSE;
    }
    if(section) {
        /* セクション名を入れるメモリを生成してコピー */
        len = strlen(section);
        new_item->sectionName = (char *)calloc(len + 1, sizeof(char));
        if(!new_item->sectionName) {
            free(new_item);
            return TB_FALSE;
        }
        strcpy(new_item->sectionName, section);
    }

    /* 最後に新しいセクションを追加 */
    if(s_section) {
        tmp = s_section;
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new_item;
    } else {
        s_section = new_item;
    }
    s_update_flag = TB_TRUE;
    
    return TB_TRUE;
}

/**
 * @brief キャッシュしているiniファイル情報からセクションを探す。
 * @details
 * キャッシュしているiniファイル情報にセクションを探す。
 * 
 * @param[in] 	section 	セクション名
 * @retval 見つけたセッション情報のアドレスを返す。
 * @retval NULL 失敗(見つからなかった)
 * 
 */
static INI_SECTION *searchSection(const char *section) 
{
    INI_SECTION *ret;

    if(!s_section) {
        return NULL;
    }
    ret = s_section;
    while(ret) {
        if(!ret->sectionName && !section) {
            break;
        } else if(ret->sectionName && strcmp(ret->sectionName, section) == 0) {
            break;
        }
        ret = ret->next;
    }
    return ret;
}

/**
 * @brief セクション情報にキーと値を追加または更新
 * @details
 * セクション情報にキーと値を追加または更新を行う。
 * key、value引数がNULLでない場合、キー、値を追加または更新を行う。
 * この動作を行う場合は、line引数にNULLを指定する必要がある。
 * line引数は、iniファイルの読み込み時に使用し、line引数で渡された文字列を
 * 解析しキーと値を取り出しそれを使って追加または更新を行う。
 * 
 * @param[in,out] 	ini_section  セクション情報
 * @param[in] 	    key      	キー
 * @param[in]       value       値
 * @param[in]       line        iniファイル内の1行(セクション名が書かれている行以外)
 * @retval TRUE 成功
 * @retval FALSE 失敗
 * 
 */
static TB_BOOL addKeyValue(INI_SECTION *ini_section, const char *key, const char *value, const char *line)
{
    INI_KEYVALUE *new_item, *tmp;
    char *new_key, *new_value, *new_line;
    size_t len, key_len, value_len;
    int i;

    if(!line && (!key || !value)) {
        return TB_FALSE;
    }

    if(line) {  /* lineが指定されていたら、lineをkey-valueに分解して使用する */
        /* 行の文字列を入れるメモリを確保してコピー */
        len = strlen(line);
        new_line = (char *)calloc(len + 1, sizeof(char));
        if(!new_line) {
            return TB_FALSE;
        }
        strcpy(new_line, line);

        /* キー部分と値部分を分離 */
        new_key = trim(new_line);
        new_value = NULL;
        for(i = 0; i < len; i++) {
            if(new_line[i] == '=') {
                new_value = &new_line[i+1];
                new_line[i] = 0;
                break;
            }
        }
        if(!new_value) {
            new_key = NULL;
        }
        if(new_key) {
            new_key = trim(new_key);
        }
        if(new_value) {
            new_value = trim(new_value);
        }
    } else {    /* lineが指定されていないなら、key,valueを使用する。 */
        key_len = strlen(key);
        value_len = strlen(value);
        new_line = (char *)calloc(key_len + value_len + 2, sizeof(char));
        if(!new_line) {
            return TB_FALSE;
        }
        sprintf(new_line, "%s=%s", key, value);
        new_line[key_len] = 0;
        new_key = trim(new_line);
        new_value = trim(&new_line[key_len + 1]);
    }

    if(new_key) {
        /* キーを探してあればデータを更新 */
        new_item = searchKeyValue(ini_section, new_key);
        if(new_item) {
            if(strcmp(new_item->val, new_value) != 0) {
                if(new_item->line) {
                    free(new_item->line);
                }
                new_item->key = new_key;
                new_item->val = new_value;
                new_item->line = new_line;
                s_update_flag = TB_TRUE;
            } else {
                free(new_line);
            }
            return TB_TRUE;
        }
    }

    /* 新しいKeyValueのメモリを確保する */
    new_item = (INI_KEYVALUE*)calloc(1, sizeof(INI_KEYVALUE));
    if(!new_item) {
        free(new_line);
        return TB_FALSE;
    }
    /* キー、値をコピー */
    new_item->key = new_key;
    new_item->val = new_value;
    new_item->line = new_line;
    s_update_flag = TB_TRUE;

    /* KeyValueを最後に追加 */
    if(ini_section->keyValue) {
        tmp = ini_section->keyValue;
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new_item;
    } else {
        ini_section->keyValue = new_item;
    }
    return TB_TRUE;
}

/**
 * @brief セクション情報からキーを削除
 * @details
 * セクション情報からキーを削除する。
 * 
 * @param[in,out] 	ini_section 	セクション情報
 * @param[in] 	    key      	キー
 * @retval TRUE 成功
 * @retval FALSE 失敗
 * 
 */
static TB_BOOL removeKey(INI_SECTION *ini_section, const char *key)
{
    INI_KEYVALUE *key_item;

    if(!key) {
        return TB_FALSE;
    }

    key_item = searchKeyValue(ini_section, key);
    if(key_item && key_item->val) {
        key_item->val = NULL;
        s_update_flag = TB_TRUE;
    }
    return TB_TRUE;
}

/**
 * @brief セクション情報からキーを検索
 * @details
 * セクション情報からキーを検索する。
 * 
 * @param[in]    	ini_section 	セクション情報
 * @param[in] 	    key      	キー
 * @return 見つかったKeyValue情報
 * @retval NULL 失敗
 * 
 */
static INI_KEYVALUE *searchKeyValue(const INI_SECTION *ini_section, const char *key)
{
    INI_KEYVALUE *ret;

    ret = ini_section->keyValue;
    while(ret) {
        if(ret->key) {
            if(strcmp(ret->key, key) == 0) {
                break;
            }
        }
        ret = ret->next;
    }
    return ret;
}

/**
 * @brief KeyValue情報のメモリを解放
 * @details
 * KeyValue情報のメモリを解放する。
 * 
 * @param[in,out]    	ini_keyvalue 	KeyValue情報
 * @return なし
 * 
 */
static void freeKeyValue(INI_KEYVALUE *ini_keyvalue)
{
    if(ini_keyvalue->line) {
        free(ini_keyvalue->line);
    }
    free(ini_keyvalue);
}

/**
 * @brief セクション情報のメモリを解放
 * @details
 * セクション情報のメモリを解放する。
 * 
 * @param[in,out]    	ini_section 	セクション情報
 * @return なし
 * 
 */
static void freeSection(INI_SECTION *ini_section)
{
    INI_KEYVALUE *tmp, *next;

    tmp = ini_section->keyValue;
    while(tmp) {
        next = tmp->next;
        freeKeyValue(tmp);
        tmp = next;
    }
    if(ini_section->sectionName) {
        free(ini_section->sectionName);
    }
    free(ini_section);
}

/**
 * @brief ファイルストリームから1行入力
 * @details
 * ファイルストリームから1行入力する。
 * 
 * @param[in]    	fp 	ファイルストリーム
 * @retval 1行入力した文字列
 * @retval NULL     エラーまたはEOF
 * 
 */
static char *readLine(FILE *fp)
{
    char *tmp;
    int ch;
    const int BUF_SIZE = 64;
    size_t len = 0;

    /* 行バッファがまだ用意されていなければ用意する。 */
    if(!read_line_buf) {
        read_line_buf = (char*)malloc(BUF_SIZE);
        if(!read_line_buf) {
            return NULL;
        }
        read_line_block_len = 1;
    }
    read_line_buf[0] = 0;

    while((ch = fgetc(fp)) != EOF) {    /* 1文字入力 */
        if(ch == '\n') {    /* 改行コード(LF)ならループを抜ける */
            break;
        }
        /* 文字数が行バッファを越えるなら行バッファを拡張 */
        if(len + 2 > BUF_SIZE * read_line_block_len) {
            tmp = (char*)realloc(read_line_buf, (read_line_block_len + 1) * BUF_SIZE);
            if(!tmp) {
                return NULL;
            }
            read_line_block_len++;
            read_line_buf = tmp;
        }
        /* 行バッファに入力した1文字を追加 */
        read_line_buf[len] = ch;
        read_line_buf[len+1] = 0;
        len++;
    }
    /* 行バッファの最後が改行コード(CR)なら削除する。 */
    if(len != 0 && read_line_buf[len-1] == 0x0d) {
        read_line_buf[len-1] = 0;
    }
    if(len == 0 && ch == EOF) {
        return NULL;
    }
        
    return read_line_buf;
}

/**
 * @brief iniファイルの読み込み
 * @details
 * iniファイルをキャッシュに読み込む。
 * 
 * @param[in]    	filename 	ファイルストリーム
 * @retval TRUE     成功
 * @retval FALSE    失敗
 * 
 */
static TB_BOOL loadIniFile(const char *filename)
{
    FILE *fp;
    char *line;
    size_t len;
    char *now_section = NULL;
    size_t now_section_len = 0;
    char *tmp;
    INI_SECTION *ini_section;

    s_update_flag = TB_FALSE;

    /* ファイルオープン */
    fp = fopen(filename, "r");
    if(!fp) {
        return TB_FALSE;
    }

    while((line = readLine(fp))) {  /* 1行読み込み */
        line = trim(line);
        len = strlen(line);
        if(len != 0 && line[0] == '[' && line[len - 1] == ']') { /* セクションなら */
            line[len - 1] = 0;
            /* セクションを追加 */
            if(!addSection(&line[1])) {
                tb_iniFreeCache();
                fclose(fp);
                if(now_section) {
                    free(now_section);
                }
                return TB_FALSE;
            }
            len = strlen(&line[1]);
            if(now_section == NULL || (now_section != NULL 
                    && strcmp(now_section, &line[1]) != 0)) {
                                /* 始めのセクションかセクションが変わったら */
                /* 新しいセクション名を入れる配列が足りなければ拡張する */
                if(now_section_len < len) {
                    tmp = (char *)realloc(now_section, len + 1);
                    if(!tmp) {
                        tb_iniFreeCache();
                        fclose(fp);
                        if(now_section) {
                            free(now_section);
                        }
                        return TB_FALSE;
                    }
                    now_section = tmp;
                }
                /* 新しいセクション名を保存 */
                strcpy(now_section, &line[1]);
                now_section_len = len;
            }
        } else { /* セクションでないなら */
            /* 現在のセクション情報を取得する */
            ini_section = searchSection(now_section);
            if(!ini_section && !now_section) {  /* iniファイルにセクション名が
                                                出てくる前なら */
                /* セクション名なしのセクションを追加する。 */
                if(!addSection(NULL)) {
                    tb_iniFreeCache();
                    fclose(fp);
                    if(now_section) {
                        free(now_section);
                    }
                    return TB_FALSE;
                }
                ini_section = searchSection(now_section);
            }
            /* 1行入力した文字列(key=valueになっている場合はKey,valueを追加)をセクションに追加 */
            if(!addKeyValue(ini_section, NULL, NULL, line)) {
                tb_iniFreeCache();
                fclose(fp);
                if(now_section) {
                    free(now_section);
                }
                return TB_FALSE;
            }
        }
    }
    fclose(fp);
    strcpy(s_inifilename, filename);

    if(now_section) {
        free(now_section);
    }
    s_update_flag = TB_FALSE;
    
    return TB_TRUE;
}

/**
 * @brief キャッシュの内容をiniファイルに書き出す
 * @details
 * キャッシュの内容をiniファイルに書き出す。
 * 
 * @param[in]    	filename 	ファイルストリーム
 * @retval TRUE     成功
 * @retval FALSE    失敗
 * 
 */
static TB_BOOL saveIniFile(const char *filename)
{
    INI_SECTION *ini_section;
    INI_KEYVALUE *ini_keyvalue;
    FILE *fp;

    unlink(filename);
    /* ファイルオープン */
    fp = fopen(filename, "w");
    if(!fp) {
        return TB_FALSE;
    }

    ini_section = s_section;
    while(ini_section) {    /* セクションの数ループ(することになる) */
        /* セクション名があれば出力する */
        if(ini_section->sectionName) {  
            fprintf(fp, "[%s]\n", ini_section->sectionName);
        }
        ini_keyvalue = ini_section->keyValue;
        while(ini_keyvalue) {   /* セクション内のKeyValue数ループ */
            /* keyValueが設定されていれば key=val の形式で出力 */
            if(ini_keyvalue->key) {
                if(ini_keyvalue->val) {
                    fprintf(fp, "%s=%s\n", ini_keyvalue->key, ini_keyvalue->val);
                }
            } else {    /* KeyValueが設定されていなければ、1行の文字列を出力 */
                fprintf(fp, "%s\n", ini_keyvalue->line);
            }
            ini_keyvalue = ini_keyvalue->next;
        }
        ini_section = ini_section->next;
    }
    fclose(fp);

    s_update_flag = TB_FALSE;
    
    return TB_TRUE;
}
/** @} */


/**
 * @brief iniファイル内のキーに設定された値の取得
 * @details
 * iniファイルをキャッシュに読み込み、指定されたセクションの
 * キーに設定された値を取得する。
 * WIN32 APIのGetPrivateProfileStringと同等の関数。(完全互換ではないと思う)
 * 
 * @param[in]    	section 	セクション名
 * @param[in]       key         キー
 * @param[in]       defstring   キーがなかった場合に設定するデフォルト値
 * @param[out]      retString   キーに設定された値が設定される
 * @param[in]       size        retStringのバッファサイズ
 * @param[in]       filename    iniファイル名
 * @return 取得した値の文字列サイズ
 * 
 */
int tb_iniGetPrivateProfileString(const char *section, const char *key, const char *defstring,  char *retString, int size, const char *filename)
{
    INI_SECTION *ini_section;
    INI_KEYVALUE *ini_keyvalue;

    /* キャッシュにiniファイルが読み込まれていなければ読み込む */
    if(strcmp(filename, s_inifilename) != 0) {
        if(s_update_flag) {
            saveIniFile(s_inifilename);
        }
        tb_iniFreeCache();
        loadIniFile(filename);
        strcpy(s_inifilename, filename);
    }
    tb_strncpy(retString, defstring, size);
    /* セクションを探す。 */
    ini_section = searchSection(section);
    if(!ini_section) {
        return strlen(retString);
    }
    /* KeyValueを探す。 */
    ini_keyvalue = searchKeyValue(ini_section, key);
    if(!ini_keyvalue) { /* なければデフォルト値を返す */
        return strlen(retString);
    }
    /* あれば、値をコピーして返す。 */
    tb_strncpy(retString, ini_keyvalue->val, size);

    return strlen(retString);
}

/**
 * @brief iniファイルにキーに対する値を設定し保存する。
 * @details
 * iniファイルがキャッシュに読み込まれていなければ、
 * キーに対する値を設定してファイルに保存する。
 * WIN32 APIのWritePrivateProfileStringと同等の関数。(完全互換ではないと思う)
 * 
 * @param[in]    	section 	セクション名
 * @param[in]       key         キー
 * @param[in]       val         キーに設定する値
 * @param[in]       filename    iniファイル名
 * @retval TRUE     成功
 * @retval FALSE    失敗
 * 
 */
TB_BOOL tb_iniWritePrivateProfileString(const char *section, const char *key, const char *val, const char *filename)
{
    INI_SECTION *ini_section;

    /* キャッシュにiniファイルが読み込まれていなければ読み込む */
    if(strcmp(filename, s_inifilename) != 0) {
        if(s_update_flag) {
            saveIniFile(s_inifilename);
        }
        tb_iniFreeCache();
        loadIniFile(filename);
        strcpy(s_inifilename, filename);
    }
    /* セクションを探す。 */
    ini_section = searchSection(section);
    if(!ini_section) {
        if(!addSection(section)) {
            return TB_FALSE;
        }
        ini_section = searchSection(section);
        if(!ini_section) {
            return TB_FALSE;
        }
    }

    if(val) { /* valが指定されているなら、キーに対する値を追加または更新 */
        if(!addKeyValue(ini_section, key, val, NULL)) {
            return TB_FALSE;
        }
    } else {  /* valがNULLなら削除 */
        if(!removeKey(ini_section, key)) {
            return TB_FALSE;
        }
    }

    /* 更新されているなら、ファイルに保存 */
    if(s_update_flag) {
        if(!saveIniFile(filename)) {
            return TB_FALSE;
        }
    }
    return TB_TRUE;
}


/**
 * @brief iniファイルを読み込んだキャッシュメモリの解放
 * @details
 * iniファイイルを読み込んだキャッシュメモリを解放する。
 * 
 * @return なし
 * 
 */
void tb_iniFreeCache()
{
    INI_SECTION *tmp, *next;

    tmp = s_section;
    while(tmp) {
        next = tmp->next;
        freeSection(tmp);
        tmp = next;
    }
    s_section = NULL;

    if(read_line_buf) {
        free(read_line_buf);
        read_line_buf = NULL;
        read_line_block_len = 0;
    }
    s_update_flag = TB_FALSE;
    s_inifilename[0] = 0;
}


static void print_ini()
{
    INI_SECTION *tmp;
    INI_KEYVALUE *tmp2;

    tmp = s_section;
    while(tmp) {
        printf("Section:%s\n", tmp->sectionName);
        tmp2 = tmp->keyValue;
        while(tmp2) {
            if(tmp2->key) {
                printf("# %s=%s\n", tmp2->key, tmp2->val);
            } else {
                printf("## %s\n", tmp2->line);
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }

}