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
#ifndef __WX98KEYMAPAPP_H__
#define __WX98KEYMAPAPP_H__

/**
 * @brief アプリケーションクラス
 */
class wx98KeymapApp:public wxApp
{
public:
    virtual bool OnInit();

private:
    wxLocale locale;
};
wxDECLARE_APP(wx98KeymapApp);

#endif