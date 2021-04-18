/**
 * @brief キーコード定義ヘッダ
 *
 *  PC-98のキーコードとキーコード名の定義および、キーボード表示用の矩形情報や
 *  Qtのキーコードなどをまとめた構造体の定義
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/4/18
 * @details
 *      PC-98のキーコードとキーコード名の定義および、キーボード表示用の矩形情報や
 *      Qtのキーコードなどをまとめた構造体を定義する。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/4/18: M.Miyamoto.:
 */
#ifndef KEYDATA_H
#define KEYDATA_H

#include <QRect>
#include <QString>

/**
 * @enum _keycode98
 *      PC-98のキーコード
 */
enum _keycode98 {
    KEYCODE98_ESC = 0x0,
    KEYCODE98_1 = 0x1,
    KEYCODE98_2 = 0x2,
    KEYCODE98_3 = 0x3,
    KEYCODE98_4 = 0x4,
    KEYCODE98_5 = 0x5,
    KEYCODE98_6 = 0x6,
    KEYCODE98_7 = 0x7,
    KEYCODE98_8 = 0x8,
    KEYCODE98_9 = 0x9,
    KEYCODE98_0 = 0xa,
    KEYCODE98_MINUS = 0xb,
    KEYCODE98_CARET = 0xc,
    KEYCODE98_YEN = 0xd,
    KEYCODE98_BS = 0xe,
    KEYCODE98_TAB = 0xf,
    KEYCODE98_Q = 0x10,
    KEYCODE98_W = 0x11,
    KEYCODE98_E = 0x12,
    KEYCODE98_R = 0x13,
    KEYCODE98_T = 0x14,
    KEYCODE98_Y = 0x15,
    KEYCODE98_U = 0x16,
    KEYCODE98_I = 0x17,
    KEYCODE98_O = 0x18,
    KEYCODE98_P = 0x19,
    KEYCODE98_ATMARK = 0x1a,
    KEYCODE98_LBRACKET = 0x1b,
    KEYCODE98_RET = 0x1c,
    KEYCODE98_A = 0x1d,
    KEYCODE98_S = 0x1e,
    KEYCODE98_D = 0x1f,
    KEYCODE98_F = 0x20,
    KEYCODE98_G = 0x21,
    KEYCODE98_H = 0x22,
    KEYCODE98_J = 0x23,
    KEYCODE98_K = 0x24,
    KEYCODE98_L = 0x25,
    KEYCODE98_SEMICOLON = 0x26,
    KEYCODE98_COLON = 0x27,
    KEYCODE98_RBRACKET = 0x28,
    KEYCODE98_Z = 0x29,
    KEYCODE98_X = 0x2a,
    KEYCODE98_C = 0x2b,
    KEYCODE98_V = 0x2c,
    KEYCODE98_B = 0x2d,
    KEYCODE98_N = 0x2e,
    KEYCODE98_M = 0x2f,
    KEYCODE98_COMMA = 0x30,
    KEYCODE98_PERIOD = 0x31,
    KEYCODE98_SLASH = 0x32,
    KEYCODE98_BACKSLASH = 0x33,
    KEYCODE98_SPACE = 0x34,
    KEYCODE98_XFER = 0x35,
    KEYCODE98_ROLLUP = 0x36,
    KEYCODE98_ROLLDOWN = 0x37,
    KEYCODE98_INS = 0x38,
    KEYCODE98_DEL = 0x39,
    KEYCODE98_UP = 0x3a,
    KEYCODE98_LEFT = 0x3b,
    KEYCODE98_RIGHT = 0x3c,
    KEYCODE98_DOWN = 0x3d,
    KEYCODE98_CLR = 0x3e,
    KEYCODE98_HELP = 0x3f,
    KEYCODE98_TENKEY_MINUS = 0x40,
    KEYCODE98_TENKEY_SLASH = 0x41,
    KEYCODE98_TENKEY_7 = 0x42,
    KEYCODE98_TENKEY_8 = 0x43,
    KEYCODE98_TENKEY_9 = 0x44,
    KEYCODE98_TENKEY_ASTERISK = 0x45,
    KEYCODE98_TENKEY_4 = 0x46,
    KEYCODE98_TENKEY_5 = 0x47,
    KEYCODE98_TENKEY_6 = 0x48,
    KEYCODE98_TENKEY_PLUS = 0x49,
    KEYCODE98_TENKEY_1 = 0x4a,
    KEYCODE98_TENKEY_2 = 0x4b,
    KEYCODE98_TENKEY_3 = 0x4c,
    KEYCODE98_TENKEY_EQUAL = 0x4d,
    KEYCODE98_TENKEY_0 = 0x4e,
    KEYCODE98_TENKKEY_COMMA = 0x4f,
    KEYCODE98_TENKEY_PERIOD = 0x50,
    KEYCODE98_NFER = 0x51,
    KEYCODE98_VF1 = 0x52,
    KEYCODE98_VF2 = 0x53,
    KEYCODE98_VF3 = 0x54,
    KEYCODE98_VF4 = 0x55,
    KEYCODE98_VF5 = 0x56,
    KEYCODE98_STOP = 0x60,
    KEYCODE98_COPY = 0x61,
    KEYCODE98_F1 = 0x62,
    KEYCODE98_F2 = 0x63,
    KEYCODE98_F3 = 0x64,
    KEYCODE98_F4 = 0x65,
    KEYCODE98_F5 = 0x66,
    KEYCODE98_F6 = 0x67,
    KEYCODE98_F7 = 0x68,
    KEYCODE98_F8 = 0x69,
    KEYCODE98_F9 = 0x6a,
    KEYCODE98_F10 = 0x6b,
    KEYCODE98_LSHIFT = 0x70,
    KEYCODE98_CAPS = 0x71,
    KEYCODE98_KANA = 0x72,
    KEYCODE98_GRPH = 0x73,
    KEYCODE98_CTRL = 0x74,
    KEYCODE98_RSHIFT = 0x7d,
};

typedef struct _keydata {
    QString keyname;                                // キー名称
    QString keytop;
    int keycode98;
    QRect rect;                                             // キーの座標
    int key;                                                    // キーコード
    Qt::KeyboardModifiers modifiers;
    quint32 nativeModifiers;
    quint32 nativeScanCode;
    quint32 nativeVirtualKey;
    int flag;
} KEYDATA;

extern KEYDATA keydatas[];

/**
  * @enum _keydataflag
  *      KEYDATA内のflagに設定する値(orで複数設定される)
  */
enum _keydataflag {
    KEYDATA_HAVE_DATA =     0b00000001,             //! スキャンコードのデータを持っている場合設定する。
    KEYDATA_INPUT_KEY =        0b00000010,              //!  キー入力中(KeyDown ->KeyUp)に設定する。
};

// キーボード矩形の全体座標(矩形)を取得する。
QRect keydatas_getKeyboardWhole();
// キーデータを保存する。
bool keydatas_saveFile(const QString &filename);
// キーデータを読み込む
bool keydatas_openFile(const QString &filename);
// キーデータをキーダウン状態にする。
void keydatas_keydown(int key);
// キーデータをキーアップ状態にする。
void keydatas_keyup(int key);
// キーデータを更新にする。
void keydatas_keydataupdate(const int keycode98, const KEYDATA &data);
// 指定キーコードのキーデータのインデックスを返す。
int keydatas_searchKeyDataFromKey(int keycode);
// キーデータをクリアする。
void keydatas_clearData();

extern bool keydatas_update;

#endif // KEYDATA_H
