/**
 * @brief キー入力ダイアログ
 *
 * キー入力ダイアログクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/4/18
 * @details
 *      キーコード表示ダイアログのキー入力ボタンをクリックした時に
 *      表示するダイアログクラス
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/4/18: M.Miyamoto.:
 */
#ifndef INPUTKEYDIALOG_H
#define INPUTKEYDIALOG_H

#include <QDialog>
#include "keydata.h"

namespace Ui {
class InputKeyDialog;
}

/**
* @brief キー入力ダイアログクラス
* @details
*       キー入力ダイアログクラス
*/
class InputKeyDialog : public QDialog
{
    Q_OBJECT

public:
    // コンストラクタ
    explicit InputKeyDialog(QWidget *parent);
    // デストラクタ
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

private:
    Ui::InputKeyDialog *ui;

    /**
    * 入力されたキーコードを設定する変数
    */
    KEYDATA m_keydata;

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // INPUTKEYDIALOG_H
