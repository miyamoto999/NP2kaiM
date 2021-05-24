/**
 * @brief キー入力ダイアログ(macOS、Linux用)
 *
 * キー入力ダイアログクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/5/17
 * @details
 *      キーコード表示ダイアログのキー入力ボタンをクリックした時に
 *      表示するダイアログクラス
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/5/17: M.Miyamoto.:
 */
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "inputkeydialog.h"

/**
 * @brief コンストラクタ
 * @details
 *  コンストラクタ
 *
 * @param[in] 	parent 	親ウィジェット
 * @param[in]   keydata 変更前のキーコードなどのデータ
 *
 */
InputKeyDialog::InputKeyDialog( wxWindow* parent, const KEYDATA &keydata)
        :InputKeyDialogBase(parent),
        m_keydata(keydata)
{

}

/**
 * @brief デストラクタ
 * @details
 *  デストラクタ
 *
 */
InputKeyDialog::~InputKeyDialog()
{

}

/**
 * @brief キーダウンイベント処理
 * @details
 *      キーダウンイベントで呼ばれる関数。
 *      入力されたキーのキーコードを変数に設定してダイアログを閉じる
 *
 * @param[in] 	event 	キーダウンイベント情報
 *
 */
void InputKeyDialog::OnKeyDown( wxKeyEvent& event )
{
    m_keydata.key = event.GetKeyCode();
    m_keydata.modifiers = event.GetModifiers();
    m_keydata.rawKeyCode = event.GetRawKeyCode();
    m_keydata.rawKeyFlags = event.GetRawKeyFlags();
    m_keydata.rawUnicodeKey = event.GetUnicodeKey();
    m_keydata.flag |= KEYDATA_HAVE_DATA;

    EndModal(wxID_OK);
}

/**
 * @brief キーアップイベント
 * @details
 *      キーアップで呼ばれる関数。
 *
 * @param[in] 	event 	キーダウンイベント情報
 *
 */
void InputKeyDialog::OnKeyUp( wxKeyEvent& event )
{
}

/**
 * @brief キー入力コントロール描画処理
 * @details
 *      キー入力を受け取るためのコントロールの描画を行う。
 *
 * @param[in] 	event 	描画イベント情報
 *
 */
void InputKeyDialog::OnInputKeyControlPaint( wxPaintEvent& event )
{
    wxPaintDC dc(m_inputKeyControl);

    dc.Clear();
    dc.SetTextForeground(*wxBLACK);
    dc.DrawText(_("Enter the key."), 10, 10);
}
