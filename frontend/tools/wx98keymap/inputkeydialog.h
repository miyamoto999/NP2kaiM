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
#ifndef __INPUTKEYDIALOG_H__
#define __INPUTKEYDIALOG_H__

#include "wx98keymapForms.h"
#include "keydata.h"

/**
* @brief キー入力ダイアログクラス(macOS、Linux用)
* @details
*       キー入力ダイアログクラス
*/
class InputKeyDialog : public InputKeyDialogBase
{
	private:
        /**
        * 入力されたキーコードを設定する変数
        */
        KEYDATA m_keydata;

	protected:
		virtual void OnKeyDown( wxKeyEvent& event );
		virtual void OnKeyUp( wxKeyEvent& event );
		virtual void OnInputKeyControlPaint( wxPaintEvent& event );

	public:

		InputKeyDialog( wxWindow* parent, const KEYDATA &keydata);
		~InputKeyDialog();

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
};


#endif
