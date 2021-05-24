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
#ifndef __KEYWIDGET_H__
#define __KEYWIDGET_H__

#include <wx/control.h>

/**
 * @brief キーマップクリックイベントクラス
 * @details
 *       キーマップクリックイベントクラス。
 *      キーマップをクリックしたときに発生するイベントで
 *      使用するイベントクラス。
 */
class KeymapClickEvent:public wxEvent
{
public:
    /**
     * @brief コンストラクタ
     */
    KeymapClickEvent(wxEventType eventType, int winid, const int index):
        wxEvent(winid, eventType),
        m_index(index)
    {
        
    }

    /**
     * @brief デストラクタ
     */
    int GetIndex() const {
        return m_index;
    }

    /**
     * @brief オブジェクトのコピーを生成
     */
    virtual wxEvent *Clone() const {
        return new KeymapClickEvent(*this);
    }
private:
    /**
     * @brief  keydatasのインデックス
     */
    const int m_index;
};

wxDECLARE_EVENT(KEYMAP_CLICK, KeymapClickEvent);

#define KeymapClickEventHandler(func) (&func)


/**
* @brief キーボード表示ウィジェットクラス
* @details
*       キーボード表示ウィジェットクラス
*/
class KeyWidget:public wxControl
{
public:
    KeyWidget(wxWindow *parent, wxWindowID id, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = 0, const wxValidator &validator = wxDefaultValidator, const wxString &name = wxControlNameStr);
    virtual ~KeyWidget();

private:
    /**
    * キーボード全体の矩形
    */
    wxRect m_keyboardRect;
    /**
    * キーボードのイメージ
    */
    wxBitmap *m_keyboardImage;

    /**
    * マージン
    */
    static const int margin = 10;
    /**
    * 表示拡縮率
    */
    double m_rate;
    /**
    * 表示位置の座標
    */
    int m_offx, m_offy;

    /**
     * キーボードの拡縮イメージ
     */
    wxImage m_keyboardScaleImage;

    // イメージにキーボードを描画する
    void drawKeyboardImage();

    void SendKeymapClick(int index);
protected:
	void OnPaint(wxPaintEvent& event);
    void OnMouseDown(wxMouseEvent &event);
	void OnSize( wxSizeEvent& event );
};

#endif