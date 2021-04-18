/**
 * @brief キーコード表示ダイアログ
 *
 * キーコード表示ダイアログクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/4/18
 * @details
 *      設定されいるキーコードを表示するダイアログクラス
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/4/18: M.Miyamoto.:
 */
#ifndef KEYDIALOG_H
#define KEYDIALOG_H

#include <QDialog>
#include "keydata.h"

namespace Ui {
class KeyDialog;
}

/**
* @brief キーコード表示ダイアログクラス
* @details
*       指定したキーに設定されいるキーコードなどを表示するダイアログクラス。
*/
class KeyDialog : public QDialog
{
    Q_OBJECT

public:
    // コンストラクタ
    explicit KeyDialog(QWidget *parent, const KEYDATA &keydata);
    // デストラクタ
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
private slots:
    void on_pushButton_clicked();

    void on_deleteKeyBinding_clicked();

private:
    Ui::KeyDialog *ui;

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
};

#endif // KEYDIALOG_H
