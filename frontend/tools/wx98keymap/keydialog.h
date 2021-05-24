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
#ifndef __KEYDIALOG_H__
#define __KEYDIALOG_H__

#include "wx98keymapForms.h"
#include "inputkeyframe.h"
#include "keydata.h"

/**
* @brief キーコード表示ダイアログクラス
* @details
*       指定したキーに設定されいるキーコードなどを表示するダイアログクラス。
*/
class KeyDialog : public KeyDialogBase
{
	private:
        // UI表示情報を更新
        void updateUI();

        /**
        * 表示するキーコードを設定する変数
        */
        KEYDATA m_keydata;
        /**
        * キーバインド削除ボタンが押されたかどうかの状態を設定する変数
        */
        bool m_deleteKeyBinding;

#ifdef __WXMSW__
        /**
         *  キー入力ダイアログ
         */
        InputKeyFrame m_inputkeyframe;
#endif

	protected:
		virtual void OnInputKeyClick( wxCommandEvent& event );
		virtual void OnDelKeyBindingClick( wxCommandEvent& event );
		virtual void OnCancelButtonClick( wxCommandEvent& event );
		virtual void OnOKButtonClick( wxCommandEvent& event );
        virtual void OnInputkey(InputKeyCloseEvent &event);

	public:

		KeyDialog( wxWindow* parent, const KEYDATA &keydata);
		~KeyDialog();

        // キーデータの設定
        void setKeydata(const KEYDATA &keydata);

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
         * @brief キー設定削除状態の取得
         * @details
         *      ダイアログでキーバインド削除ボタンが押されたどうかを返す。
         *
         * @retval true キーバインド削除ボタンが押された
         * @retval false    キーバインド削除ボタンが押されいない
         *
         */
        bool getDeleteKeyBinding() {
            return m_deleteKeyBinding;
        }
};


#endif