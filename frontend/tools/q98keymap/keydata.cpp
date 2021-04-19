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
    { QString("KEYCODE98_ESC"), QString("ESC"), KEYCODE98_ESC, QRect(0, 60, 60, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_1"), QString("1"), KEYCODE98_1, QRect(60, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_2"), QString("2"), KEYCODE98_2, QRect(100, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_3"), QString("3"), KEYCODE98_3, QRect(140, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_4"), QString("4"), KEYCODE98_4, QRect(180, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_5"), QString("5"), KEYCODE98_5, QRect(220, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_6"), QString("6"), KEYCODE98_6, QRect(260, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_7"), QString("7"), KEYCODE98_7, QRect(300, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_8"), QString("8"), KEYCODE98_8, QRect(340, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_9"), QString("9"), KEYCODE98_9, QRect(380, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_0"), QString("0"), KEYCODE98_0, QRect(420, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_MINUS"), QString("-"), KEYCODE98_MINUS, QRect(460, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_CARET"), QString("^"), KEYCODE98_CARET, QRect(500, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_YEN"), QString("\\"), KEYCODE98_YEN, QRect(540, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_BS"), QString("BS"), KEYCODE98_BS, QRect(580, 60, 60, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TAB"), QString("TAB"), KEYCODE98_TAB, QRect(0, 100, 70, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_Q"), QString("Q"), KEYCODE98_Q, QRect(70, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_W"), QString("W"), KEYCODE98_W, QRect(110, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_E"), QString("E"), KEYCODE98_E, QRect(150, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_R"), QString("R"), KEYCODE98_R, QRect(190, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_T"), QString("T"), KEYCODE98_T, QRect(230, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_Y"), QString("Y"), KEYCODE98_Y, QRect(270, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_U"), QString("U"), KEYCODE98_U, QRect(310, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_I"), QString("I"), KEYCODE98_I, QRect(350, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_O"), QString("O"), KEYCODE98_O, QRect(390, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_P"), QString("P"), KEYCODE98_P, QRect(430, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_ATMARK"), QString("@"), KEYCODE98_ATMARK, QRect(470, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_LBRACKET"), QString("["), KEYCODE98_LBRACKET, QRect(510, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RET"), QString("RET"), KEYCODE98_RET, QRect(560, 100, 80, 80), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_RET"), QString("RET"), KEYCODE98_TENKEY_RET, QRect(880, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_A"), QString("A"), KEYCODE98_A, QRect(80, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_S"), QString("S"), KEYCODE98_S, QRect(120, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_D"), QString("D"), KEYCODE98_D, QRect(160, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F"), QString("F"), KEYCODE98_F, QRect(200, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_G"), QString("G"), KEYCODE98_G, QRect(240, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_H"), QString("H"), KEYCODE98_H, QRect(280, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_J"), QString("J"), KEYCODE98_J, QRect(320, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_K"), QString("K"), KEYCODE98_K, QRect(360, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_L"), QString("L"), KEYCODE98_L, QRect(400, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_SEMICOLON"), QString(";"), KEYCODE98_SEMICOLON, QRect(440, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_COLON"), QString(":"), KEYCODE98_COLON, QRect(480, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RBRACKET"), QString("]"), KEYCODE98_RBRACKET, QRect(520, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_Z"), QString("Z"), KEYCODE98_Z, QRect(100, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_X"), QString("X"), KEYCODE98_X, QRect(140, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_C"), QString("C"), KEYCODE98_C, QRect(180, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_V"), QString("V"), KEYCODE98_V, QRect(220, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_B"), QString("B"), KEYCODE98_B, QRect(260, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_N"), QString("N"), KEYCODE98_N, QRect(300, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_M"), QString("M"), KEYCODE98_M, QRect(340, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_COMMA"), QString(","), KEYCODE98_COMMA, QRect(380, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_PERIOD"), QString("."), KEYCODE98_PERIOD, QRect(420, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_SLASH"), QString("/"), KEYCODE98_SLASH, QRect(460, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_BACKSLASH"), QString("\\"), KEYCODE98_BACKSLASH, QRect(500, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_SPACE"), QString("SPACE"), KEYCODE98_SPACE, QRect(220, 220, 260, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_XFER"), QString("XFER"), KEYCODE98_XFER, QRect(480, 220, 60, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_ROLLUP"), QString("RU"), KEYCODE98_ROLLUP, QRect(660, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_ROLLDOWN"), QString("RD"), KEYCODE98_ROLLDOWN, QRect(700, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_INS"), QString("INS"), KEYCODE98_INS, QRect(660, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_DEL"), QString("DEL"), KEYCODE98_DEL, QRect(700, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_UP"), QString("UP"), KEYCODE98_UP, QRect(660, 140, 80, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_LEFT"), QString("LEFT"), KEYCODE98_LEFT, QRect(660, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RIGHT"), QString("RIGHT"), KEYCODE98_RIGHT, QRect(700, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_DOWN"), QString("DOWN"), KEYCODE98_DOWN, QRect(660, 220, 80, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_CLR"), QString("CLR"), KEYCODE98_CLR, QRect(760, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_HELP"), QString("HELP"), KEYCODE98_HELP, QRect(800, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_MINUS"), QString("-"), KEYCODE98_TENKEY_MINUS, QRect(840, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_SLASH"), QString("/"), KEYCODE98_TENKEY_SLASH, QRect(880, 60, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_7"), QString("7"), KEYCODE98_TENKEY_7, QRect(760, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_8"), QString("8"), KEYCODE98_TENKEY_8, QRect(800, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_9"), QString("9"), KEYCODE98_TENKEY_9, QRect(840, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_ASTERISK"), QString("*"), KEYCODE98_TENKEY_ASTERISK, QRect(880, 100, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_4"), QString("4"), KEYCODE98_TENKEY_4, QRect(760, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_5"), QString("5"), KEYCODE98_TENKEY_5, QRect(800, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_6"), QString("6"), KEYCODE98_TENKEY_6, QRect(840, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_PLUS"), QString("+"), KEYCODE98_TENKEY_PLUS, QRect(880, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_1"), QString("1"), KEYCODE98_TENKEY_1, QRect(760, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_2"), QString("2"), KEYCODE98_TENKEY_2, QRect(800, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_3"), QString("3"), KEYCODE98_TENKEY_3, QRect(840, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_EQUAL"), QString("="), KEYCODE98_TENKEY_EQUAL, QRect(880, 180, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_0"), QString("0"), KEYCODE98_TENKEY_0, QRect(760, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKKEY_COMMA"), QString(","), KEYCODE98_TENKKEY_COMMA, QRect(800, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_TENKEY_PERIOD"), QString("."), KEYCODE98_TENKEY_PERIOD, QRect(840, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_NFER"), QString("NFER"), KEYCODE98_NFER, QRect(160, 220, 60, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF1"), QString("vf1"), KEYCODE98_VF1, QRect(670, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF2"), QString("vf2"), KEYCODE98_VF2, QRect(720, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF3"), QString("vf3"), KEYCODE98_VF3, QRect(770, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF4"), QString("vf4"), KEYCODE98_VF4, QRect(820, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_VF5"), QString("vf5"), KEYCODE98_VF5, QRect(870, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_STOP"), QString("STOP"), KEYCODE98_STOP, QRect(0, 0, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_COPY"), QString("COPY"), KEYCODE98_COPY, QRect(60, 0, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F1"), QString("f1"), KEYCODE98_F1, QRect(120, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F2"), QString("f2"), KEYCODE98_F2, QRect(170, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F3"), QString("f3"), KEYCODE98_F3, QRect(220, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F4"), QString("f4"), KEYCODE98_F4, QRect(270, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F5"), QString("f5"), KEYCODE98_F5, QRect(320, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F6"), QString("f6"), KEYCODE98_F6, QRect(390, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F7"), QString("f7"), KEYCODE98_F7, QRect(440, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F8"), QString("f8"), KEYCODE98_F8, QRect(490, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F9"), QString("f9"), KEYCODE98_F9, QRect(540, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_F10"), QString("f10"), KEYCODE98_F10, QRect(590, 0, 50, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_LSHIFT"), QString("SHIFT"), KEYCODE98_LSHIFT, QRect(0, 180, 100, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_CAPS"), QString("CAPS"), KEYCODE98_CAPS, QRect(40, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_KANA"), QString("kana"), KEYCODE98_KANA, QRect(80, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_GRPH"), QString("GRPH"), KEYCODE98_GRPH, QRect(120, 220, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_CTRL"), QString("CTRL"), KEYCODE98_CTRL, QRect(0, 140, 40, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
    { QString("KEYCODE98_RSHIFT"), QString("SHIFT"), KEYCODE98_RSHIFT, QRect(540, 180, 100, 40), 0, Qt::NoModifier, 0, 0, 0, 0 },
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
        keydatas_keydataupdate(keydata.keyname, keydata);
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
 *      指定キー名のデータを更新する。
 *
 * @param[in] 	    keyname      	キー名
 * @param[in]       data       更新するキーデータ
 *
 */
void keydatas_keydataupdate(const QString &keyname, const KEYDATA &data)
{
    int i = 0;

    while(!keydatas[i].keyname.isEmpty()) {
        if(keydatas[i].keyname == keyname) {
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
