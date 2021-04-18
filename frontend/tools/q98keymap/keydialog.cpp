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
#include "keydialog.h"
#include "ui_keydialog.h"
#include "inputkeydialog.h"
#include <QDebug>

/**
 * @brief コンストラクタ
 * @details
 *      コンストラクタ
 *
 * @param[in] 	    parent      	親ウィジェット
 * @param[in] 	    keydata      	キーデータ
 */
KeyDialog::KeyDialog(QWidget *parent, const KEYDATA &keydata) :
    QDialog(parent),
    ui(new Ui::KeyDialog),m_keydata(keydata),
    m_deleteKeyBinding(false)
{
    ui->setupUi(this);
    updateUI();
}

/**
 * @brief デストラクタ
 * @details
 *      デストラクタ
 *
 */
KeyDialog::~KeyDialog()
{
    delete ui;
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
    ui->labelKeyname->setText(m_keydata.keyname);
    ui->labelKey->setText("0x" + QString::number(m_keydata.key, 16));
    ui->labelModifiers->setText("0x" + QString::number(m_keydata.modifiers, 16));
    ui->labelNativeModifiers->setText("0x" + QString::number(m_keydata.nativeModifiers, 16));
    ui->labelNativeScanCode->setText("0x" + QString::number(m_keydata.nativeScanCode, 16));
    ui->labelNativeVirtualKey->setText("0x" + QString::number(m_keydata.nativeVirtualKey, 16));
}

/**
 * @brief キー入力ボタンクリック処理
 * @details
 *      キー入力ダイアログを表示し、入力されたキーデータでUI表示を更新する。
 *
 */
void KeyDialog::on_pushButton_clicked()
{
    InputKeyDialog dlg(this);
    if(dlg.exec() == QDialog::Accepted) {
        m_keydata.key = dlg.getKeydata().key;
        m_keydata.modifiers = dlg.getKeydata().modifiers;
        m_keydata.nativeModifiers = dlg.getKeydata().nativeModifiers;
        m_keydata.nativeScanCode = dlg.getKeydata().nativeScanCode;
        m_keydata.nativeVirtualKey = dlg.getKeydata().nativeVirtualKey;
        m_keydata.flag |= KEYDATA_HAVE_DATA;
        m_deleteKeyBinding = false;
        updateUI();
    }
}

/**
 * @brief キーバインド削除ボタンクリック処理
 * @details
 *      キーデータを初期化して、キーバインド削除フラグを立てる。
 *
 */
void KeyDialog::on_deleteKeyBinding_clicked()
{
    m_keydata.key = 0;
    m_keydata.modifiers = Qt::NoModifier;
    m_keydata.nativeModifiers = 0;
    m_keydata.nativeScanCode = 0;
    m_keydata.nativeVirtualKey = 0;
    m_deleteKeyBinding = true;
    updateUI();
}
