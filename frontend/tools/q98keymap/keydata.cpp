/**
 * @brief キーコード定義
 *
 * PC-98のキーコード、キーボード矩形などの配列の初期化および操作関数群
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/4/18
 * @details
 *      PC-98のキーコード、キーボード矩形などの配列の初期化および操作関数群。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/4/18: M.Miyamoto.:
 */
#include "keydata.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

/**
* キーデータ配列
*/
KEYDATA keydatas[] ={
    { QString("KEYCODE98_ESC"), QString("ESC"), 0x0, QRect(0, 60, 60, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_1"), QString("1"), 0x1, QRect(60, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_2"), QString("2"), 0x2, QRect(100, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_3"), QString("3"), 0x3, QRect(140, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_4"), QString("4"), 0x4, QRect(180, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_5"), QString("5"), 0x5, QRect(220, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_6"), QString("6"), 0x6, QRect(260, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_7"), QString("7"), 0x7, QRect(300, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_8"), QString("8"), 0x8, QRect(340, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_9"), QString("9"), 0x9, QRect(380, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_0"), QString("0"), 0xa, QRect(420, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_MINUS"), QString("-"), 0xb, QRect(460, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_CARET"), QString("^"), 0xc, QRect(500, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_YEN"), QString("\\"), 0xd, QRect(540, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_BS"), QString("BS"), 0xe, QRect(580, 60, 60, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TAB"), QString("TAB"), 0xf, QRect(0, 100, 70, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_Q"), QString("Q"), 0x10, QRect(70, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_W"), QString("W"), 0x11, QRect(110, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_E"), QString("E"), 0x12, QRect(150, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_R"), QString("R"), 0x13, QRect(190, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_T"), QString("T"), 0x14, QRect(230, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_Y"), QString("Y"), 0x15, QRect(270, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_U"), QString("U"), 0x16, QRect(310, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_I"), QString("I"), 0x17, QRect(350, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_O"), QString("O"), 0x18, QRect(390, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_P"), QString("P"), 0x19, QRect(430, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_ATMARK"), QString("@"), 0x1a, QRect(470, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_LBRACKET"), QString("["), 0x1b, QRect(510, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RET"), QString("RET"), 0x1c, QRect(560, 100, 80, 80), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RET"), QString("RET"), 0x1c, QRect(880, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_A"), QString("A"), 0x1d, QRect(80, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_S"), QString("S"), 0x1e, QRect(120, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_D"), QString("D"), 0x1f, QRect(160, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F"), QString("F"), 0x20, QRect(200, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_G"), QString("G"), 0x21, QRect(240, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_H"), QString("H"), 0x22, QRect(280, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_J"), QString("J"), 0x23, QRect(320, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_K"), QString("K"), 0x24, QRect(360, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_L"), QString("L"), 0x25, QRect(400, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_SEMICOLON"), QString(";"), 0x26, QRect(440, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_COLON"), QString(":"), 0x27, QRect(480, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RBRACKET"), QString("]"), 0x28, QRect(520, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_Z"), QString("Z"), 0x29, QRect(100, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_X"), QString("X"), 0x2a, QRect(140, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_C"), QString("C"), 0x2b, QRect(180, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_V"), QString("V"), 0x2c, QRect(220, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_B"), QString("B"), 0x2d, QRect(260, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_N"), QString("N"), 0x2e, QRect(300, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_M"), QString("M"), 0x2f, QRect(340, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_COMMA"), QString(","), 0x30, QRect(380, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_PERIOD"), QString("."), 0x31, QRect(420, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_SLASH"), QString("/"), 0x32, QRect(460, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_BACKSLASH"), QString("\\"), 0x33, QRect(500, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_SPACE"), QString("SPACE"), 0x34, QRect(220, 220, 260, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_XFER"), QString("XFER"), 0x35, QRect(480, 220, 60, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_ROLLUP"), QString("RU"), 0x36, QRect(660, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_ROLLDOWN"), QString("RD"), 0x37, QRect(700, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_INS"), QString("INS"), 0x38, QRect(660, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_DEL"), QString("DEL"), 0x39, QRect(700, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_UP"), QString("UP"), 0x3a, QRect(660, 140, 80, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_LEFT"), QString("LEFT"), 0x3b, QRect(660, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RIGHT"), QString("RIGHT"), 0x3c, QRect(700, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_DOWN"), QString("DOWN"), 0x3d, QRect(660, 220, 80, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_CLR"), QString("CLR"), 0x3e, QRect(760, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_HELP"), QString("HELP"), 0x3f, QRect(800, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_MINUS"), QString("-"), 0x40, QRect(840, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_SLASH"), QString("/"), 0x41, QRect(880, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_7"), QString("7"), 0x42, QRect(760, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_8"), QString("8"), 0x43, QRect(800, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_9"), QString("9"), 0x44, QRect(840, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_ASTERISK"), QString("*"), 0x45, QRect(880, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_4"), QString("4"), 0x46, QRect(760, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_5"), QString("5"), 0x47, QRect(800, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_6"), QString("6"), 0x48, QRect(840, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_PLUS"), QString("+"), 0x49, QRect(880, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_1"), QString("1"), 0x4a, QRect(760, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_2"), QString("2"), 0x4b, QRect(800, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_3"), QString("3"), 0x4c, QRect(840, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_EQUAL"), QString("="), 0x4d, QRect(880, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_0"), QString("0"), 0x4e, QRect(760, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKKEY_COMMA"), QString(","), 0x4f, QRect(800, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_PERIOD"), QString("."), 0x50, QRect(840, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_NFER"), QString("NFER"), 0x51, QRect(160, 220, 60, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF1"), QString("vf1"), 0x52, QRect(670, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF2"), QString("vf2"), 0x53, QRect(720, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF3"), QString("vf3"), 0x54, QRect(770, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF4"), QString("vf4"), 0x55, QRect(820, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF5"), QString("vf5"), 0x56, QRect(870, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_STOP"), QString("STOP"), 0x60, QRect(0, 0, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_COPY"), QString("COPY"), 0x61, QRect(60, 0, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F1"), QString("f1"), 0x62, QRect(120, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F2"), QString("f2"), 0x63, QRect(170, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F3"), QString("f3"), 0x64, QRect(220, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F4"), QString("f4"), 0x65, QRect(270, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F5"), QString("f5"), 0x66, QRect(320, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F6"), QString("f6"), 0x67, QRect(390, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F7"), QString("f7"), 0x68, QRect(440, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F8"), QString("f8"), 0x69, QRect(490, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F9"), QString("f9"), 0x6a, QRect(540, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F10"), QString("f10"), 0x6b, QRect(590, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_LSHIFT"), QString("SHIFT"), 0x70, QRect(0, 180, 100, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_CAPS"), QString("CAPS"), 0x71, QRect(40, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_KANA"), QString("kana"), 0x72, QRect(80, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_GRPH"), QString("GRPH"), 0x73, QRect(120, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_CTRL"), QString("CTRL"), 0x74, QRect(0, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RSHIFT"), QString("SHIFT"), 0x7d, QRect(540, 180, 100, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString(), QString(), 0, QRect(-1,-1,-1,-1), 0, Qt::NoModifier, 0, 0, 0, 0 }
};

bool keydatas_update = false;

/**
 * @brief キーボード全体の矩形の取得
 * @details
 *      キーボード全体の矩形を返す
 *
 * @return  キーボード全体の矩形
 *
 */
QRect keydatas_getKeyboardWhole()
{
    int i;
    QRect ret;
    i = 0;
    ret = keydatas[i].rect;
    i++;

    while(!keydatas[i].keyname.isEmpty()) {
        ret.setX(qMin<int>(ret.x(), keydatas[i].rect.x()));
        ret.setY(qMin<int>(ret.y(), keydatas[i].rect.y()));
        ret.setWidth(qMax<int>(ret.width(), keydatas[i].rect.x() + keydatas[i].rect.width()));
        ret.setHeight(qMax<int>(ret.height(), keydatas[i].rect.y() + keydatas[i].rect.height()));
        i++;
    }
    return ret;
}

/**
 * @brief キーコードから対象のキーデータ配列のインデックスの取得
 * @details
 *      指定されたキーコードから対象のキーデータ配列のインデックスを返す。
 *
 * @param[in] 	    keycode      	キーコード
 * @return  キーデータ配列のインデックス
 *
 */
int keydatas_searchKeyDataFromKey(int keycode)
{
    int i;

    i = 0;
    while(!keydatas[i].keyname.isEmpty()) {
        if(keydatas[i].key == keycode) {
            return i;
        }
        i++;
    }
    return -1;
}


/**
 * @brief キーデータの保存
 * @details
 *      キーデータをファイルに保存する。
 *
 * @param[in] 	    filename      	ファイル名
 * @retval TRUE 成功
 * @retval FALSE 失敗
 *
 */
bool keydatas_saveFile(const QString &filename)
{
    QFile file(filename);

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        return false;
    }
    QTextStream out(&file);

    int i = 0;
    while(!keydatas[i].keyname.isEmpty()) {
        out << keydatas[i].keyname << "\t";
        out << keydatas[i].keycode98 << "\t";
        out << keydatas[i].flag << "\t";
        out << keydatas[i].key << "\t";
        out << keydatas[i].modifiers << "\t";
        out << keydatas[i].nativeModifiers << "\t";
        out << keydatas[i].nativeScanCode << "\t";
        out << keydatas[i].nativeVirtualKey << Qt::endl;
        i++;
    }
    file.close();
    return true;
}

/**
 * @brief キーデータファイルを読み込む
 * @details
 *      キーデータファイルを読み込む
 *
 * @param[in] 	    filename      	ファイル名
 * @retval TRUE 成功
 * @retval FALSE 失敗
 *
 */
bool keydatas_openFile(const QString &filename)
{
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        return false;
    }

    QTextStream in(&file);

    KEYDATA keydata;
    int modifiers;

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList datas = line.split("\t");
        keydata.keyname = datas[0];
        keydata.keycode98 = datas[1].toInt();
        keydata.flag = datas[2].toInt();
        keydata.key = datas[3].toInt();
        keydata.modifiers = (Qt::KeyboardModifiers)datas[4].toInt();
        keydata.nativeModifiers = datas[5].toInt();
        keydata.nativeScanCode = datas[6].toInt();
        keydata.nativeVirtualKey = datas[7].toInt();
        keydatas_keydataupdate(keydata.keycode98, keydata);
    }
    file.close();
    keydatas_update = false;
    return true;
}

/**
 * @brief キーデータの初期化
 * @details
 *      キーデータの初期化
 */
void keydatas_clearData()
{
    int i = 0;

    while(!keydatas[i].keyname.isEmpty()) {
        keydatas[i].key = 0;
        keydatas[i].modifiers = Qt::NoModifier;
        keydatas[i].nativeModifiers = 0;
        keydatas[i].nativeScanCode = 0;
        keydatas[i].nativeVirtualKey = 0;
        keydatas[i].flag = 0;
        i++;
    }
    keydatas_update = false;
}

/**
 * @brief キーデータをキーダウン状態にする。
 * @details
 *      指定キーコードが設定されているキーデータのフラグをキーダウン状態にする。
 *
 * @param[in] 	    key      	キーコード
 */
void keydatas_keydown(int key)
{
    int i = 0;

    while(!keydatas[i].keyname.isEmpty()) {
        if(keydatas[i].key == key) {
            keydatas[i].flag |= KEYDATA_INPUT_KEY;
        }
        i++;
    }
}

/**
 * @brief キーデータをキーアップ状態にする。
 * @details
 *      指定キーコードが設定されているキーデータのフラグをキーアップ状態にする。
 *
 * @param[in] 	    key      	キーコード
 */
void keydatas_keyup(int key)
{
    int i = 0;

    while(!keydatas[i].keyname.isEmpty()) {
        if(keydatas[i].key == key) {
            keydatas[i].flag &= (~KEYDATA_INPUT_KEY);
        }
        i++;
    }
}

/**
 * @brief キーデータを更新する。
 * @details
 *      指定PC-98キーコードのデータを更新する。
 *
 * @param[in] 	    keycode98      	PC-98のキーコード
 * @param[in]       data       更新するキーデータ
 *
 */
void keydatas_keydataupdate(const int keycode98, const KEYDATA &data)
{
    int i = 0;

    while(!keydatas[i].keyname.isEmpty()) {
        if(keydatas[i].keycode98 == keycode98) {
            keydatas[i].flag = data.flag;
            keydatas[i].key = data.key;
            keydatas[i].modifiers = data.modifiers;
            keydatas[i].nativeModifiers = data.nativeModifiers;
            keydatas[i].nativeScanCode = data.nativeScanCode;
            keydatas[i].nativeVirtualKey = data.nativeVirtualKey;
            keydatas_update = true;
        }
        i++;
    }
}
