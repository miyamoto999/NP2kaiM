/**
 * @brief キーコード表示ダイアログ
 *
 * キーコード表示ダイアログクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/5/21
 * @details
 *      設定されいるキーコードを表示するダイアログクラス
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/5/21: M.Miyamoto.:
 */
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "keydialog.h"
#include "inputkeydialog.h"
#include "inputkeyframe.h"

/**
 * @brief コンストラクタ
 * @details
 *      コンストラクタ
 *
 * @param[in] 	    parent      	親ウィジェット
 * @param[in] 	    keydata      	キーデータ
 */
KeyDialog::KeyDialog( wxWindow* parent, const KEYDATA &keydata)
        :KeyDialogBase(parent),
        m_keydata(keydata),
        m_deleteKeyBinding(false)
#ifdef __WXMSW__
        , m_inputkeyframe(this, keydata)
#endif
{
    updateUI();
#ifdef __WXMSW__
    m_inputkeyframe.Bind(INPUTKEYCLOSE_EVENT, &KeyDialog::OnInputkey, this);
#endif
}

/**
 * @brief デストラクタ
 * @details
 *      デストラクタ
 *
 */
KeyDialog::~KeyDialog()
{
}

/**
 * @brief キーデータの設定
 * @details
 *      キーデータを設定して表示を更新する。
 *
 * @param[in] 	    keydata      	キーデータ
 *
 */
void KeyDialog::setKeydata(const KEYDATA &keydata)
{
    m_keydata = keydata;
    updateUI();
}

/**
 * @brief UI表示の更新
 * @details
 *      m_keydataに設定されたキーデータでUI表示を更新する。
 *
 */
void KeyDialog::updateUI()
{
    m_staticKeyname->SetLabelText(m_keydata.keyname);
    wxString tmp;
    tmp.sprintf("0x%x", m_keydata.key);
    m_staticKey->SetLabelText(tmp);
    tmp.sprintf("0x%x", m_keydata.modifiers);
    m_staticModifiers->SetLabelText(tmp);
    tmp.sprintf("0x%x", m_keydata.rawKeyCode);
    m_staticRawKeyCode->SetLabelText(tmp);
    tmp.sprintf("0x%x", m_keydata.rawKeyFlags);
    m_staticRawKeyFlags->SetLabelText(tmp);
    tmp.sprintf("0x%x", m_keydata.rawUnicodeKey);
    m_staticRawUnicodeKey->SetLabelText(tmp);
}

/**
 * @brief キー入力ボタンクリック処理
 * @details
 *      キー入力ダイアログを表示し、入力されたキーデータでUI表示を更新する。
 *      Windowsの場合、このダイアログを入力やアクディブにできないようにして
 *      キー入力ダイアログ(Frameベース)を表示する。キー入力ダイアログで入力した
 *      キー情報はイベントで受け取りそのイベントでキー入力ダイアログを非表示にしたり
 *      このダイアログを入力やアクティブにできないようにしているのを
 *      元に戻している。macOS、Linuxの場合、キー入力ダイアログはモーダルダイアログとして
 *      表示しているのでこのダイアログでは入力などできなくなっている。
 * @param[in]   event       イベント情報
 *      
 */
void KeyDialog::OnInputKeyClick( wxCommandEvent& event )
{
#ifdef __WXMSW__
    this->Disable();
    m_inputkeyframe.Show();
#else
    InputKeyDialog dlg(this, m_keydata);

    if(dlg.ShowModal() == wxID_OK) {
        setKeydata(dlg.getKeydata());
        updateUI();
    }
#endif
}

/**
 * @brief キーバインド削除ボタンクリック処理
 * @details
 *      キーデータを初期化して、キーバインド削除フラグを立てる。
 * @param[in]   event       イベント情報
 *
 */
void KeyDialog::OnDelKeyBindingClick( wxCommandEvent& event )
{
    m_keydata.key = 0;
    m_keydata.modifiers = 0;
    m_keydata.rawKeyCode = 0;
    m_keydata.rawKeyFlags = 0;
    m_keydata.rawUnicodeKey = 0;
    m_deleteKeyBinding = true;
    updateUI();
}

/**
 * @brief キャンセルボタンを押されたときの処理
 * @details
 *      キャンセルボタンを押されたときの処理を行う。
 *      ダイアログを閉じ、wxID_CANCELを返す。
 * @param[in]   event       イベント情報
 *
 */
void KeyDialog::OnCancelButtonClick( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

/**
 * @brief OKボタンを押されたときの処理
 * @details
 *      OKボタンを押されたときの処理を行う。
 *      ダイアログを閉じ、wxID_OKを返す。
 * @param[in]   event       イベント情報
 *
 */
void KeyDialog::OnOKButtonClick( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

/**
 * @brief キー入力ダイアログがクローズされようとしたときの処理(Windows用)
 * @details
 *     キー入力ダイアログがクローズされようとしたときに発生するイベントでの処理。
 *     キー入力されて閉じようとされた場合はキー情報を更新して、キー入力ダイアログを
 *      非表示にする。
 * @param[in]   event       イベント情報
 *
 */
void KeyDialog::OnInputkey(InputKeyCloseEvent &event)
{
#ifdef __WXMSW__
    this->Enable();
    if(event.GetStatus()) {
        setKeydata(m_inputkeyframe.getKeydata());
        updateUI();
    }
    m_inputkeyframe.Show(false);
#endif
}
