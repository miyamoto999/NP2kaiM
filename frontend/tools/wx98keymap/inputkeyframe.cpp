/**
 * @brief キー入力ダイアログ(Windows用)
 *
 * キー入力ダイアログクラス。実際にはダイアログではなくwxFrameを継承したものである。
 * wxDialogを継承したものの場合、キーダウンイベントでtabキーの入力ができないなどの
 * 問題があったのでwxFrameを継承してダイアログ代わりに使用した。
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
#include "inputkeyframe.h"

wxDEFINE_EVENT(INPUTKEYCLOSE_EVENT, InputKeyCloseEvent);

/**
 * @brief コンストラクタ
 * @details
 *  コンストラクタ
 *
 * @param[in] 	parent 	親ウィジェット
 * @param[in]   keydata 変更前のキーコードなどのデータ
 *
 */
InputKeyFrame::InputKeyFrame(wxWindow *parent, const KEYDATA &keydata)
        :InputKeyFrameBase(parent),
        m_keydata(keydata), m_inputkey_flag(false)
{
}

/**
 * @brief デストラクタ
 * @details
 *  デストラクタ
 *
 */
InputKeyFrame::~InputKeyFrame()
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
void InputKeyFrame::OnInputKeyControlPaint( wxPaintEvent& event )
{
    wxPaintDC dc(m_inputKeyControl);

    dc.Clear();
    dc.SetTextForeground(*wxBLACK);
    dc.DrawText(_("Enter the key."), 10, 10);
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
void InputKeyFrame::OnKeyDown( wxKeyEvent& event )
{
    m_keydata.key = event.GetKeyCode();
    m_keydata.modifiers = event.GetModifiers();
    m_keydata.rawKeyCode = event.GetRawKeyCode();
    m_keydata.rawKeyFlags = event.GetRawKeyFlags();
    m_keydata.rawUnicodeKey = event.GetUnicodeKey();
    m_keydata.flag |= KEYDATA_HAVE_DATA;
    m_inputkey_flag = true;

    Close();
}

/**
 * @brief キーアップイベント
 * @details
 *      キーアップで呼ばれる関数。
 *
 * @param[in] 	event 	キーダウンイベント情報
 *
 */
void InputKeyFrame::OnKeyUp( wxKeyEvent& event )
{
}

/**
 * @brief クローズイベント
 * @details
 *      ウィンドウをクローズするときに呼ばれる。
 *      inputkeyEventを発生する。
 *
 * @param[in] 	event 	クローズイベント情報
 *
 */
void InputKeyFrame::OnClose( wxCloseEvent& event )
{
    InputKeyCloseEvent inputkeyCloseEvent(INPUTKEYCLOSE_EVENT, GetId(), m_inputkey_flag);
    inputkeyCloseEvent.SetEventObject(this);
    ProcessWindowEvent(inputkeyCloseEvent);
}

/**
 * @brief ショーイベント
 * @details
 *      ウィンドウの表示or非表示で呼ばれる。
 *      表示時に入力済みフラグを初期化する。
 *
 * @param[in] 	event 	ショーイベント情報
 *
 */
void InputKeyFrame::OnShow( wxShowEvent& event )
{
    if(event.IsShown()) {
        m_inputkey_flag = false;
    }
}