/**
 * @brief キーコード定義
 *
 * PC-98のキーコード、キーボード矩形などの配列の初期化および操作関数群
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/5/18
 * @details
 *      PC-98のキーコード、キーボード矩形などの配列の初期化および操作関数群。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/5/18: M.Miyamoto.:
 */
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/textfile.h>
#include <string>
#include <cstdio>
#include <vector>
#include <sstream>
#include "keydata.h"

/**
* キーデータ配列
*/
KEYDATA keydatas[] ={
	{ wxString("KEYCODE98_ESC"), wxString("ESC"), KEYCODE98_ESC, wxRect(0, 60, 60, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_1"), wxString("1"), KEYCODE98_1, wxRect(60, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_2"), wxString("2"), KEYCODE98_2, wxRect(100, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_3"), wxString("3"), KEYCODE98_3, wxRect(140, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_4"), wxString("4"), KEYCODE98_4, wxRect(180, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_5"), wxString("5"), KEYCODE98_5, wxRect(220, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_6"), wxString("6"), KEYCODE98_6, wxRect(260, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_7"), wxString("7"), KEYCODE98_7, wxRect(300, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_8"), wxString("8"), KEYCODE98_8, wxRect(340, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_9"), wxString("9"), KEYCODE98_9, wxRect(380, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_0"), wxString("0"), KEYCODE98_0, wxRect(420, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_MINUS"), wxString("-"), KEYCODE98_MINUS, wxRect(460, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_CARET"), wxString("^"), KEYCODE98_CARET, wxRect(500, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_YEN"), wxString("\\"), KEYCODE98_YEN, wxRect(540, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_BS"), wxString("BS"), KEYCODE98_BS, wxRect(580, 60, 60, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TAB"), wxString("TAB"), KEYCODE98_TAB, wxRect(0, 100, 70, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_Q"), wxString("Q"), KEYCODE98_Q, wxRect(70, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_W"), wxString("W"), KEYCODE98_W, wxRect(110, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_E"), wxString("E"), KEYCODE98_E, wxRect(150, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_R"), wxString("R"), KEYCODE98_R, wxRect(190, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_T"), wxString("T"), KEYCODE98_T, wxRect(230, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_Y"), wxString("Y"), KEYCODE98_Y, wxRect(270, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_U"), wxString("U"), KEYCODE98_U, wxRect(310, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_I"), wxString("I"), KEYCODE98_I, wxRect(350, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_O"), wxString("O"), KEYCODE98_O, wxRect(390, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_P"), wxString("P"), KEYCODE98_P, wxRect(430, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_ATMARK"), wxString("@"), KEYCODE98_ATMARK, wxRect(470, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_LBRACKET"), wxString("["), KEYCODE98_LBRACKET, wxRect(510, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_RET"), wxString("RET"), KEYCODE98_RET, wxRect(560, 100, 80, 80), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_RET"), wxString("RET"), KEYCODE98_TENKEY_RET, wxRect(880, 220, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_A"), wxString("A"), KEYCODE98_A, wxRect(80, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_S"), wxString("S"), KEYCODE98_S, wxRect(120, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_D"), wxString("D"), KEYCODE98_D, wxRect(160, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F"), wxString("F"), KEYCODE98_F, wxRect(200, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_G"), wxString("G"), KEYCODE98_G, wxRect(240, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_H"), wxString("H"), KEYCODE98_H, wxRect(280, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_J"), wxString("J"), KEYCODE98_J, wxRect(320, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_K"), wxString("K"), KEYCODE98_K, wxRect(360, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_L"), wxString("L"), KEYCODE98_L, wxRect(400, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_SEMICOLON"), wxString(";"), KEYCODE98_SEMICOLON, wxRect(440, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_COLON"), wxString(":"), KEYCODE98_COLON, wxRect(480, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_RBRACKET"), wxString("]"), KEYCODE98_RBRACKET, wxRect(520, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_Z"), wxString("Z"), KEYCODE98_Z, wxRect(100, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_X"), wxString("X"), KEYCODE98_X, wxRect(140, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_C"), wxString("C"), KEYCODE98_C, wxRect(180, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_V"), wxString("V"), KEYCODE98_V, wxRect(220, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_B"), wxString("B"), KEYCODE98_B, wxRect(260, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_N"), wxString("N"), KEYCODE98_N, wxRect(300, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_M"), wxString("M"), KEYCODE98_M, wxRect(340, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_COMMA"), wxString(","), KEYCODE98_COMMA, wxRect(380, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_PERIOD"), wxString("."), KEYCODE98_PERIOD, wxRect(420, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_SLASH"), wxString("/"), KEYCODE98_SLASH, wxRect(460, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_BACKSLASH"), wxString("\\"), KEYCODE98_BACKSLASH, wxRect(500, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_SPACE"), wxString("SPACE"), KEYCODE98_SPACE, wxRect(220, 220, 260, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_XFER"), wxString("XFER"), KEYCODE98_XFER, wxRect(480, 220, 60, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_ROLLUP"), wxString("RU"), KEYCODE98_ROLLUP, wxRect(660, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_ROLLDOWN"), wxString("RD"), KEYCODE98_ROLLDOWN, wxRect(700, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_INS"), wxString("INS"), KEYCODE98_INS, wxRect(660, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_DEL"), wxString("DEL"), KEYCODE98_DEL, wxRect(700, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_UP"), wxString("UP"), KEYCODE98_UP, wxRect(660, 140, 80, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_LEFT"), wxString("LEFT"), KEYCODE98_LEFT, wxRect(660, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_RIGHT"), wxString("RIGHT"), KEYCODE98_RIGHT, wxRect(700, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_DOWN"), wxString("DOWN"), KEYCODE98_DOWN, wxRect(660, 220, 80, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_CLR"), wxString("CLR"), KEYCODE98_CLR, wxRect(760, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_HELP"), wxString("HELP"), KEYCODE98_HELP, wxRect(800, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_MINUS"), wxString("-"), KEYCODE98_TENKEY_MINUS, wxRect(840, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_SLASH"), wxString("/"), KEYCODE98_TENKEY_SLASH, wxRect(880, 60, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_7"), wxString("7"), KEYCODE98_TENKEY_7, wxRect(760, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_8"), wxString("8"), KEYCODE98_TENKEY_8, wxRect(800, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_9"), wxString("9"), KEYCODE98_TENKEY_9, wxRect(840, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_ASTERISK"), wxString("*"), KEYCODE98_TENKEY_ASTERISK, wxRect(880, 100, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_4"), wxString("4"), KEYCODE98_TENKEY_4, wxRect(760, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_5"), wxString("5"), KEYCODE98_TENKEY_5, wxRect(800, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_6"), wxString("6"), KEYCODE98_TENKEY_6, wxRect(840, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_PLUS"), wxString("+"), KEYCODE98_TENKEY_PLUS, wxRect(880, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_1"), wxString("1"), KEYCODE98_TENKEY_1, wxRect(760, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_2"), wxString("2"), KEYCODE98_TENKEY_2, wxRect(800, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_3"), wxString("3"), KEYCODE98_TENKEY_3, wxRect(840, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_EQUAL"), wxString("="), KEYCODE98_TENKEY_EQUAL, wxRect(880, 180, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_0"), wxString("0"), KEYCODE98_TENKEY_0, wxRect(760, 220, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKKEY_COMMA"), wxString(","), KEYCODE98_TENKKEY_COMMA, wxRect(800, 220, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_TENKEY_PERIOD"), wxString("."), KEYCODE98_TENKEY_PERIOD, wxRect(840, 220, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_NFER"), wxString("NFER"), KEYCODE98_NFER, wxRect(160, 220, 60, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_VF1"), wxString("vf1"), KEYCODE98_VF1, wxRect(670, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_VF2"), wxString("vf2"), KEYCODE98_VF2, wxRect(720, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_VF3"), wxString("vf3"), KEYCODE98_VF3, wxRect(770, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_VF4"), wxString("vf4"), KEYCODE98_VF4, wxRect(820, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_VF5"), wxString("vf5"), KEYCODE98_VF5, wxRect(870, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_STOP"), wxString("STOP"), KEYCODE98_STOP, wxRect(0, 0, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_COPY"), wxString("COPY"), KEYCODE98_COPY, wxRect(60, 0, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F1"), wxString("f1"), KEYCODE98_F1, wxRect(120, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F2"), wxString("f2"), KEYCODE98_F2, wxRect(170, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F3"), wxString("f3"), KEYCODE98_F3, wxRect(220, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F4"), wxString("f4"), KEYCODE98_F4, wxRect(270, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F5"), wxString("f5"), KEYCODE98_F5, wxRect(320, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F6"), wxString("f6"), KEYCODE98_F6, wxRect(390, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F7"), wxString("f7"), KEYCODE98_F7, wxRect(440, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F8"), wxString("f8"), KEYCODE98_F8, wxRect(490, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F9"), wxString("f9"), KEYCODE98_F9, wxRect(540, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_F10"), wxString("f10"), KEYCODE98_F10, wxRect(590, 0, 50, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_LSHIFT"), wxString("SHIFT"), KEYCODE98_LSHIFT, wxRect(0, 180, 100, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_CAPS"), wxString("CAPS"), KEYCODE98_CAPS, wxRect(40, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_KANA"), wxString("kana"), KEYCODE98_KANA, wxRect(80, 220, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_GRPH"), wxString("GRPH"), KEYCODE98_GRPH, wxRect(120, 220, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_CTRL"), wxString("CTRL"), KEYCODE98_CTRL, wxRect(0, 140, 40, 40), 0, 0, 0, 0, 0 },
	{ wxString("KEYCODE98_RSHIFT"), wxString("SHIFT"), KEYCODE98_RSHIFT, wxRect(540, 180, 100, 40), 0, 0, 0, 0, 0 },
	{ wxString(), wxString(), 0, wxRect(-1,-1,-1,-1), 0, 0, 0, 0, 0 }
};

bool keydatas_update = false;

/**
 * @brief 文字列を分解する
 * @details
 * 		sepで指定した文字で文字列を分解して配列(vector)で返す。
 * @return sepで分解した文字列の配列(vector)
 */
static inline std::vector<std::string> split(const std::string &str, char sep)
{
	std::vector<std::string> ret;
	std::stringstream stream(str);
	std::string buf;

	while(std::getline(stream, buf, sep)) {
		ret.push_back(buf);
	}
	return ret;
}

/**
 * @brief キーボード全体の矩形の取得
 * @details
 *      キーボード全体の矩形を返す
 *
 * @return  キーボード全体の矩形
 *
 */
wxRect keydatas_getKeyboardWhole()
{
    int i;
    wxRect ret;
    i = 0;
    ret = keydatas[i].rect;
    i++;

    while(!keydatas[i].keyname.empty()) {
        ret.SetX(std::min(ret.GetX(), keydatas[i].rect.GetX()));
        ret.SetY(std::min(ret.GetY(), keydatas[i].rect.GetY()));
        ret.SetWidth(std::max(ret.GetWidth(), keydatas[i].rect.GetX() + keydatas[i].rect.GetWidth()));
        ret.SetHeight(std::max(ret.GetHeight(), keydatas[i].rect.GetY() + keydatas[i].rect.GetHeight()));
        i++;
    }
    return ret;
}

/**
 * @brief キーコードから対象のキーデータ配列のインデックスの取得
 * @details
 *      指定されたキーコードから対象のキーデータ配列のインデックスを返す。
 *
 * @param[in] 	    keycode      	キーコード
 * @return  キーデータ配列のインデックス
 *
 */
int keydatas_searchKeyDataFromKey(int keycode)
{
    int i;

    i = 0;
    while(!keydatas[i].keyname.empty()) {
        if(keydatas[i].key == keycode) {
            return i;
        }
        i++;
    }
    return -1;
}

/**
 * @brief キーデータの保存
 * @details
 *      キーデータをファイルに保存する。
 *
 * @param[in] 	    filename      	ファイル名
 * @retval TRUE 成功
 * @retval FALSE 失敗
 *
 */
bool keydatas_saveFile(const wxString &filename)
{
    wxTextFile file(filename);
	
	if(file.Exists()) {
		wxRemoveFile(filename);
	}
	if(!file.Create()) {
		return false;
	}
    int i = 0;
    while(!keydatas[i].keyname.empty()) {
		wxString str;
		str << keydatas[i].keyname << "\t";
		str << keydatas[i].keycode98 << "\t";
		str << keydatas[i].flag << "\t";
		str << keydatas[i].key << "\t";
		str << keydatas[i].modifiers << "\t";
		str << keydatas[i].rawKeyCode << "\t";
		str << keydatas[i].rawKeyFlags << "\t";
		str << keydatas[i].rawUnicodeKey;
		file.AddLine(str);
        i++;
    }
	file.Write();
    file.Close();
    return true;
}

/**
 * @brief キーデータファイルを読み込む
 * @details
 *      キーデータファイルを読み込む
 *
 * @param[in] 	    filename      	ファイル名
 * @retval TRUE 成功
 * @retval FALSE 失敗
 *
 */
bool keydatas_openFile(const wxString &filename)
{
    wxTextFile file(filename);

    if(!file.Open()) {
        return false;
    }

    KEYDATA keydata;

	for(wxString line = file.GetFirstLine(); !file.Eof(); line = file.GetNextLine()) {
		std::vector<std::string> datas = split(line.ToStdString(), '\t');
        keydata.keyname = datas[0];
        keydata.keycode98 = stoi(datas[1]);
        keydata.flag = stoi(datas[2]);
        keydata.key = stoi(datas[3]);
        keydata.modifiers = stoi(datas[4]);		
		keydata.rawKeyCode = stoul(datas[5]);
		keydata.rawKeyFlags = stoul(datas[6]);
		keydatas->rawUnicodeKey = stoul(datas[7]);
        keydatas_keydataupdate(keydata.keyname, keydata);
    }
    file.Close();
    keydatas_update = false;
    return true;
}

/**
 * @brief キーデータの初期化
 * @details
 *      キーデータの初期化
 */
void keydatas_clearData()
{
    int i = 0;

    while(!keydatas[i].keyname.empty()) {
        keydatas[i].key = 0;
		keydatas[i].modifiers = 0;
		keydatas[i].rawKeyCode = 0;
		keydatas[i].rawKeyFlags = 0;
		keydatas[i].rawUnicodeKey = 0;
        keydatas[i].flag = 0;
        i++;
    }
    keydatas_update = false;
}

/**
 * @brief キーデータをキーダウン状態にする。
 * @details
 *      指定キーコードが設定されているキーデータのフラグをキーダウン状態にする。
 *
 * @param[in] 	    key      	キーコード
 */
void keydatas_keydown(uint32_t key)
{
    int i = 0;

    while(!keydatas[i].keyname.empty()) {
#if defined(__WXMAC__) || defined(__WXGTK__)
        if(keydatas[i].rawKeyCode == key) {
#elif defined(__WXMSW__)
        if(((keydatas[i].rawKeyFlags >> 16) & 0x1ff) == key) {
#endif
            keydatas[i].flag |= KEYDATA_INPUT_KEY;
        }
        i++;
    }
}

/**
 * @brief キーデータをキーアップ状態にする。
 * @details
 *      指定キーコードが設定されているキーデータのフラグをキーアップ状態にする。
 *
 * @param[in] 	    key      	キーコード
 */
void keydatas_keyup(uint32_t key)
{
    int i = 0;

    while(!keydatas[i].keyname.empty()) {
#if defined(__WXMAC__) || defined(__WXGTK__) 
        if(keydatas[i].rawKeyCode == key) {
#elif defined(__WXMSW__)
        if(((keydatas[i].rawKeyFlags >> 16) & 0x1ff) == key) {
#endif
            keydatas[i].flag &= (~KEYDATA_INPUT_KEY);
        }
        i++;
    }
}

/**
 * @brief キーデータを更新する。
 * @details
 *      指定キー名のデータを更新する。
 *
 * @param[in] 	    keyname      	キー名
 * @param[in]       data       更新するキーデータ
 *
 */
void keydatas_keydataupdate(const wxString &keyname, const KEYDATA &data)
{
    int i = 0;

    while(!keydatas[i].keyname.empty()) {
        if(keydatas[i].keyname == keyname) {
            keydatas[i].flag = data.flag;
            keydatas[i].key = data.key;
			keydatas[i].modifiers = data.modifiers;
			keydatas[i].rawKeyCode = data.rawKeyCode;
			keydatas[i].rawKeyFlags = data.rawKeyFlags;
			keydatas[i].rawUnicodeKey = data.rawUnicodeKey;
            keydatas_update = true;
        }
        i++;
    }
}
