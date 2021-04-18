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
#include "inputkeydialog.h"
#include "ui_inputkeydialog.h"
#include "keydata.h"
#include <QDebug>
#include <QKeyEvent>

/**
 * @brief コンストラクタ
 * @details
 *  コンストラクタ
 *
 * @param[in] 	parent 	親ウィジェット
 *
 */
InputKeyDialog::InputKeyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputKeyDialog)
{
    ui->setupUi(this);

;}

/**
 * @brief デストラクタ
 * @details
 *  デストラクタ
 *
 */
InputKeyDialog::~InputKeyDialog()
{
    delete ui;
}

/**
 * @brief キープレスイベント
 * @details
 *      キープレスで呼ばれる関数。
 *      入力されたキーのキーコードを変数に設定してダイアログを閉じる
 *
 * @param[in] 	event 	キープレスイベント情報
 *
 */
void InputKeyDialog::keyPressEvent(QKeyEvent *event)
{
    m_keydata.key = event->key();
    m_keydata.modifiers = event->modifiers();
    m_keydata.nativeModifiers = event->nativeModifiers();
    m_keydata.nativeScanCode = event->nativeScanCode();
    m_keydata.nativeVirtualKey = event->nativeVirtualKey();
    m_keydata.flag |= KEYDATA_HAVE_DATA;

    accept();
}

