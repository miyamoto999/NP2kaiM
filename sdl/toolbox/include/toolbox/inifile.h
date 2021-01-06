/**
 * @brief iniファイル操作関係
 * @details
 * Windowsのiniファイルを読み書きする機能を提供する。
 * WIN32 APIのWritePrivateProfileString()とGetPrivateProfileString()関数
 * と同等の動きをする関数を提供する。(完全互換ではないと思う。)
 *
 * @author Masanori Miyamoto.
 * @date 2020/11/22
 * 
 * @file
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
#ifndef __TOOLBOX_INIFILE_H__
#define __TOOLBOX_INIFILE_H__

#ifndef TB_BOOL
#define TB_BOOL char
#endif
#ifndef TB_TRUE
#define TB_TRUE    1
#endif
#ifndef TB_FALSE
#define TB_FALSE   0
#endif


#ifdef __cplusplus
extern "C" {
#endif

int tb_iniGetPrivateProfileString(const char *section, const char *key, const char *defString, char *retString, int size, const char *filename);
TB_BOOL tb_iniWritePrivateProfileString(const char *section, const char *key, const char *val, const char *filename);

void tb_iniFreeCache();

#ifdef __cplusplus
}
#endif

#endif

