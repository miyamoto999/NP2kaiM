/**
 * @brief キーボード表示ウィジェットクラス
 *
 * PC-98キーボード表示ウィジェットクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/5/21
 * @details
 *      PC-98キーボード表示ウィジェットクラスを定義する。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 * @par 変更履歴
 * - 2021/5/21: M.Miyamoto.:
 */
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include "keywidget.h"
#include "keydata.h"

wxDEFINE_EVENT(KEYMAP_CLICK, KeymapClickEvent);

/**
 * @brief コンストラクタ
 * @details
 *      コンストラクタ
 *
 * @param[in] 	    parent      	親ウィジェット
 * @param[in]       id              コントロールID
 * @param[in]       pos             位置
 * @param[in]       size            サイズ
 * @param[in]       style           スタイル
 * @param[in]       validator       バリデータ
 * @param[in]       name            コントロール名
 *
 */
KeyWidget::KeyWidget(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxValidator &validator, const wxString &name):
                wxControl(parent, id, pos, size, style, validator, name)
{    
    Bind(wxEVT_PAINT, &KeyWidget::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &KeyWidget::OnMouseDown, this);
    Bind(wxEVT_SIZE, &KeyWidget::OnSize, this);

    m_keyboardRect = keydatas_getKeyboardWhole();

    wxSize keySize(m_keyboardRect.GetWidth() + margin * 2, 
            m_keyboardRect.GetHeight() + margin * 2);
    m_keyboardImage = new wxBitmap(keySize);

    drawKeyboardImage();
}

/**
 * @brief デストラクタ
 * @details
 *      デストラクタ
 *
 */
KeyWidget::~KeyWidget()
{
    delete m_keyboardImage;
}

/**
 * @brief キーボードイメージの生成
 * @details
 *      キーボードのイメージを生成する。
 *
 */
void KeyWidget::drawKeyboardImage()
{
    wxMemoryDC dc(*m_keyboardImage);

    dc.SetBackground(*wxWHITE_BRUSH);

    dc.Clear();

    int i = 0;
    while(!keydatas[i].keyname.empty()) {
        wxRect r(keydatas[i].rect.GetX() + margin, keydatas[i].rect.GetY() + margin, keydatas[i].rect.GetWidth(), keydatas[i].rect.GetHeight());

        dc.SetPen(*wxBLACK_PEN);
        if(keydatas[i].flag & KEYDATA_INPUT_KEY) {
            dc.SetBrush(*wxCYAN_BRUSH);
            dc.DrawRectangle(r);
        } else if(keydatas[i].flag & KEYDATA_HAVE_DATA) {
            dc.SetBrush(*wxYELLOW_BRUSH);
            dc.DrawRectangle(r);
        } else {
            dc.SetBrush(*wxWHITE_BRUSH);
            dc.DrawRectangle(r);
        }
        dc.DrawLabel(keydatas[i].keytop, r, wxALIGN_CENTER);
        i++;
    }
    wxRect clientRect = this->GetClientRect();

    double ratex = (double)clientRect.GetWidth() / m_keyboardImage->GetWidth();
    double ratey = (double)clientRect.GetHeight() / m_keyboardImage->GetHeight();
    m_rate = ratex < ratey ? ratex:ratey;
    m_offx = (clientRect.GetWidth() - m_keyboardImage->GetWidth() * m_rate) / 2;
    m_offy = (clientRect.GetHeight() - m_keyboardImage->GetHeight() * m_rate) / 2;

    wxImage img = m_keyboardImage->ConvertToImage();
    m_keyboardScaleImage = img.Scale(m_keyboardImage->GetWidth() * m_rate, m_keyboardImage->GetHeight() * m_rate, wxIMAGE_QUALITY_HIGH);
}

/**
 * @brief 描画イベントの処理
 * @details
 *          描画イベント。ウィジェット内に入るようにキーボードイメージを描画する。
 *
 * @param[in] 	   event      描画イベントのパラメータ
 */
void KeyWidget::OnPaint(wxPaintEvent& event)
{
    drawKeyboardImage();

    wxBitmap bmp = wxBitmap(m_keyboardScaleImage);
    wxPaintDC dc(this);
    dc.Clear();
    wxMemoryDC imageDc(bmp);
    dc.Blit(m_offx, m_offy, bmp.GetWidth(), bmp.GetHeight(), &imageDc, 0, 0);
}

/**
 * @brief マウスダウンイベントの処理
 * @details
 *      マウスダウンした座標位置のキーを検索してKEYMAP_CLICKイベントを発生する。
 *
 * @param[in] 	    event      	マウスダウンイベントパラメータ
 *
 */
void KeyWidget::OnMouseDown(wxMouseEvent &event)
{
    int x = (int)((double)(event.GetX() - m_offx) / m_rate - margin);
    int y = (int)((double)(event.GetY() - m_offy) / m_rate - margin);

    int i = 0;
    while(!keydatas[i].keyname.empty()) {
        if(keydatas[i].rect.Contains(x, y)) {
            SendKeymapClick(i);
            break;
        }
        i++;
    }
}

/**
 * @brief KEYMAP_CLICKイベントを発生
 * @details
 *          KEYMAP_CLICKイベントを発生させる。
 * @param[in] 	    index      	クリックしたキーのkeydatasのインデックス
 *
 */
void KeyWidget::SendKeymapClick(int index)
{
    KeymapClickEvent keymapEvent(KEYMAP_CLICK, GetId(), index);
    keymapEvent.SetEventObject(this);
    ProcessWindowEvent(keymapEvent);
}

/**
 * @brief サイス変更イベントの処理
 * @details
 *      ウィンドウの再描画を行う。
 *
 * @param[in] 	    event      	イベント情報
 *
 */
void KeyWidget::OnSize( wxSizeEvent& event )
{
    Refresh();
}
