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
#ifndef __INPUTKEYFRAME_H__
#define __INPUTKEYFRAME_H__

#include "wx98keymapForms.h"
#include "keydata.h"

/**
 * @brief キー入力ダイアログクローズイベントクラス
 * @details
 *       キー入力ダイアログクローズイベントクラス。
 *       キー入力ダイアログをクローズしたときに発生するイベントのイベント情報クラスになる。
 *       キー入力ダイアログがキー入力を受け付けて閉じたとき、GetStatus()の値がtureになる
 *       INPUTKEYCLOSE_EVENTが発生する。
 */
class InputKeyCloseEvent:public wxEvent
{
public:
    /**
     * @brief コンストラクタ
     * @details
     *  コンストラクタ
     *
     * @param[in] 	eventType 	イベントタイプ
     * @param[in]   winid       ウィンドウID
     * @param[in]   status      ステータス
     *
     */
    InputKeyCloseEvent(wxEventType eventType, int winid, const bool status):
        wxEvent(winid, eventType),
        m_status(status)
    {
        
    }

    /**
     *  @brief 状態の取得
     *  @details
     *      設定されいる状態を返す。
     *  @retval true    キー入力ダイアログでキー入力が行われてクローズされた
     */
    int GetStatus() const {
        return m_status;
    }

    /**
     *  @brief 複製
     *  @details
     *      オブジェクトの複製を生成する。
     *  @return 複製したオブジェクト 
     */
    virtual wxEvent *Clone() const {
        return new InputKeyCloseEvent(*this);
    }
private:
    /**
     * @brief 状態
     * @details
     *      キー入力ダイアログがキー入力を受け付けて閉じたとき、
     *      trueをセットされてイベントに渡される。
     */
    const bool m_status;
};

wxDECLARE_EVENT(INPUTKEYCLOSE_EVENT, InputKeyCloseEvent);

#define InputKeyEventHandler(func) (&func)

/**
 * 
 * @brief キー入力ダイアログクラス(Windows用)
 * @details
 *       キー入力ダイアログクラス。WindowsではwxDialogを継承したダイアログだと
 *      問題があったためwxFrameを継承した代わりのものを用意した。
 */
class InputKeyFrame:public InputKeyFrameBase {
    public:
        InputKeyFrame(wxWindow *parent, const KEYDATA &keydata);

        ~InputKeyFrame();

        /**
         * @brief 入力されたキーコード取得
         * @details
         *      ダイアログ表示後、入力されたキーコードを返す。
         *
         * @return 入力されたキーコードを設定したKEYDATA構造体
         *
         */
        KEYDATA &getKeydata() {
            return m_keydata;
        }

        /**
         * @brief キーデータの設定
         * @details
         *      キーデータを設定する。
         */
        void setKeydata(const KEYDATA &keydata) {
            m_keydata = keydata;
        }

        /**
         * @brief キー入力されたかどうかを返す。
         */
        bool getInputKeyFlag() {
            return m_inputkey_flag;
        }

    protected:
		virtual void OnKeyDown( wxKeyEvent& event );
		virtual void OnKeyUp( wxKeyEvent& event );
        virtual void OnInputKeyControlPaint( wxPaintEvent& event );
		virtual void OnClose( wxCloseEvent& event );
		virtual void OnShow( wxShowEvent& event );

    private:
        /**
        * 入力されたキーコードを設定する変数
        */
        KEYDATA m_keydata;

        /**
         * @brief キー入力されたかどうかを設定する
         */
        bool m_inputkey_flag;
};

#endif