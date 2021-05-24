/**
 * @brief メインウィンドウクラス
 *
 *　メインウィンドウクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/5/22
 * @details
 *      メインウィンドウクラスを定義する。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/5/22: M.Miyamoto.:
 */
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/stdpaths.h>
#include "wx98keymap.h"
#include "keywidget.h"
#include "keydialog.h"

/**
 * @brief コンストラクタ
 * 
 * @param[in]   parent  親ウインドウ
 */
wx98keymap::wx98keymap(wxWindow* parent):
        wx98keymapBase(parent)
{
    this->m_keywidget->Bind(KEYMAP_CLICK, &wx98keymap::OnKeymapClick, this);
}

/**
 * @brief デストラクタ
 */
wx98keymap::~wx98keymap()
{

}

/**
 * @brief キーダウンイベント処理
 * @details
 *      キーコードの表示、キーコードが設定されているキーの色を更新する。
 * @param[in]   event イベント情報
 */
void wx98keymap::OnKeyDown( wxKeyEvent& event )
{
    printf("#### OnKeyDown\n");
    printf("KeyCode:0x%x\n", event.GetKeyCode());
    printf("KeyRawCode:0x%x\n", event.GetRawKeyCode());

    wxString tmp;
    tmp.sprintf("0x%x", event.GetKeyCode());
    m_staticKeycode->SetLabel(tmp);
    tmp.sprintf("0x%x", event.GetModifiers());
    m_staticModifiers->SetLabel(tmp);
    tmp.sprintf("0x%x", event.GetRawKeyCode());
    m_staticRawKeyCode->SetLabel(tmp);
    tmp.sprintf("0x%x", event.GetRawKeyFlags());
    m_staticRawKeyFlags->SetLabel(tmp);
    tmp.sprintf("0x%x", event.GetUnicodeKey());
    m_staticUnicodeKey->SetLabel(tmp);

#if defined(__WXMAC__) || defined(__WXGTK__)    
    keydatas_keydown(event.GetRawKeyCode());
#elif defined(__WXMSW__)
    keydatas_keydown((event.GetRawKeyFlags() >> 16) & 0x1ff);
#endif
    Refresh();
}

/**
 * @brief キーアップイベント処理
 * @details
 *      キーコードが設定されているキーの色を元に戻す。
 *
 * @param[in] 	   event      イベント情報
 *
 */
void wx98keymap::OnKeyUp( wxKeyEvent& event )
{
    printf("#### OnKeyUp\n");
    printf("KeyCode:0x%x\n", event.GetKeyCode());
    printf("KeyRawCode:0x%x\n", event.GetRawKeyCode());

#if defined(__WXMAC__) || defined(__WXGTK__)    
    keydatas_keyup(event.GetRawKeyCode());
#elif defined(__WXMSW__)
    keydatas_keyup((event.GetRawKeyFlags() >> 16) & 0x1ff);
#endif
    Refresh();
}

/**
 * @brief KeyWidgetクリックイベント処理
 * @details
 *      KeyWidetで表示されるキーをクリックした時に発生するイベントを
 *      受ける。キー表示ダイアログを表示し、キーが更新されたら
 *      キーデータ配列の対象キーのキーデータを更新する。
 *
 * @param[in] 	   evnet      イベント情報
 *
 */
void wx98keymap::OnKeymapClick(KeymapClickEvent &event)
{
    const int index = event.GetIndex();
    KeyDialog dlg(this, keydatas[index]);
    if(dlg.ShowModal() == wxID_OK) {
        KEYDATA data = dlg.getKeydata();
        if(dlg.getDeleteKeyBinding()) {
            data.flag = 0;
        } else {
            data.flag |= KEYDATA_HAVE_DATA;
        }
        keydatas_keydataupdate(keydatas[index].keyname, data);
        Refresh();
    }
}

/**
 * @brief メニューの開くを選択されたときの処理
 * @details
 *      ファイルオープンダイアログを表示し、選択されたファイルを読み込む。
 * @param[in]   event イベント情報
 *
 */
void wx98keymap::OnMenuOpen( wxCommandEvent& event )
{
    if(keydatas_update) {
        if(wxMessageBox(_("Your changes have not been saved yet.\nAre you sure?"), _("Open"), wxICON_QUESTION | wxYES_NO) == wxNO) {
            return;
        }
    }
 
    wxFileDialog fileDlg(this, _("Open"), wxStandardPaths::Get().GetDocumentsDir(), "", _("Text file(*.txt)|*.txt"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if(fileDlg.ShowModal() == wxID_OK) {
        keydatas_clearData();
        m_openFilename = wxString();
        if(!keydatas_openFile(fileDlg.GetPath())) {
            wxMessageBox(_("File Open ERROR"), _("Open"));
        } else {
            m_openFilename = fileDlg.GetPath();
        }
        Refresh();
    }
}

/**
 * @brief メニューの保存を選択されたときの処理
 * @details
 *      ファイルを読み込んでいる場合は、読み込んだファイル名で上書き保存し、
 *      読み込んでない場合は、名前を付けて保存ダイアログを表示し、入力されたファイル名で
 *      保存する。
 * @param[in]       event   イベント情報
 *
 */
void wx98keymap::OnMenuSave( wxCommandEvent& event )
{
    if(m_openFilename.empty()) {
        OnMenuSaveAs(event);
    } else {
        if(!keydatas_saveFile(m_openFilename)) {
            wxMessageBox(_("File save ERROR"), _("Save"));
        } else {
            keydatas_update = false;
        }
    }
}

/**
 * @brief メニューの名前を付けて保存を選択されたときの処理
 * @details
 *      名前を付けて保存ダイアログを表示し、入力されたファイル名で保存する。
 * @param[in]   event   イベント情報
 *
 */
void wx98keymap::OnMenuSaveAs( wxCommandEvent& event )
{
    wxFileDialog fileDlg(this, _("Save"), wxStandardPaths::Get().GetDocumentsDir(), "", _("Text file(*.txt)|*.txt"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if(fileDlg.ShowModal() == wxID_OK) {
       if(!keydatas_saveFile(fileDlg.GetPath())) {
            wxMessageBox(_("File save ERROR"), _("Save As"));
       } else {
           m_openFilename = fileDlg.GetPath();
           keydatas_update = false;
       }
    }
}

/**
 * @brief メニューの閉じるを選択されたときの処理
 * @details
 *      データを初期化する。
 * @param[in]   event       イベント情報
 *
 */
void wx98keymap::OnMenuClose( wxCommandEvent& event )
{
    if(keydatas_update) {
        if(wxMessageBox(_("Your changes have not been saved yet.\nAre you sure?"), _("Close"), wxICON_QUESTION | wxYES_NO) == wxNO) {
            return;
        }
    }
    keydatas_clearData();
    m_openFilename = wxString();
    Refresh();
}

/**
 * @brief メニューの終了を選択されたときの処理
 * @details
 *      ウィンドウを閉じる。メインウィンドウなのでアプリケーション終了する。
 * @param[in]   event       イベント情報
 *
 */
void wx98keymap::OnMenuQuit( wxCommandEvent& event )
{
    Close();
}

/**
 * @brief ウィンドウを閉じようとしたときのイベント処理
 * @details
 *      データ更新されていて、ファイルに保存されていない時は、保存していないことを
 *      表示し、それでも終了していい場合は終了するようにする。
 * @param[in]   event   イベント情報
 *
 */
void wx98keymap::OnClose( wxCloseEvent& event )
{
    if(event.CanVeto() && keydatas_update) {
        int ret = wxMessageBox(_("Your changes have not been saved yet.\nAre you sure?"),
                _("Close"), wxICON_QUESTION | wxYES_NO);
        if(ret != wxYES) {
            event.Veto();
            return;
        }
    }
    Destroy();
}

