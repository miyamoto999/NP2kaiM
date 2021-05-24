/**
 * @brief アプリケーションクラス
 *
 *　アプリケーションクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/5/22
 * @details
 *      アプリケーションクラスを定義する。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/5/22: M.Miyamoto.:
 */
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "wx98KeymapApp.h"
#include "wx98keymap.h"

/**
 * @brief 初期化処理
 * @details
 *      デフォルト言語のローカライズファイルを読み込み、
 *      メインウインドウを表示する。
 */
bool wx98KeymapApp::OnInit()
{
    locale.Init(wxLANGUAGE_DEFAULT);
    locale.AddCatalogLookupPathPrefix(_T("."));
    locale.AddCatalogLookupPathPrefix(_T("./locale/"));
    locale.AddCatalog(_T("wx98keymap"));

    wx98keymap *frame = new wx98keymap(NULL);
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(wx98KeymapApp);

