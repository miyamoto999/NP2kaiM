#include "kbddrv.h"

static quint8 trans_table106[] = {
    KEYCODE98_A, KEYCODE98_S, KEYCODE98_D, KEYCODE98_F, KEYCODE98_H, KEYCODE98_G, KEYCODE98_Z, KEYCODE98_X, KEYCODE98_C, KEYCODE98_V, KEYCODE98_NC, KEYCODE98_B, KEYCODE98_Q, KEYCODE98_W, KEYCODE98_E, KEYCODE98_R,
    KEYCODE98_Y, KEYCODE98_T, KEYCODE98_1, KEYCODE98_2, KEYCODE98_3, KEYCODE98_4, KEYCODE98_6, KEYCODE98_5, KEYCODE98_CARET, KEYCODE98_9, KEYCODE98_7, KEYCODE98_MINUS, KEYCODE98_8, KEYCODE98_0, KEYCODE98_LBRACKET, KEYCODE98_O,
    KEYCODE98_U, KEYCODE98_ATMARK, KEYCODE98_I, KEYCODE98_P, KEYCODE98_RET, KEYCODE98_L, KEYCODE98_J, KEYCODE98_COLON, KEYCODE98_K, KEYCODE98_SEMICOLON, KEYCODE98_RBRACKET, KEYCODE98_COMMA, KEYCODE98_SLASH, KEYCODE98_N, KEYCODE98_M, KEYCODE98_PERIOD,
    KEYCODE98_TAB, KEYCODE98_SPACE, KEYCODE98_NC, KEYCODE98_BS, KEYCODE98_NC, KEYCODE98_ESC, KEYCODE98_XFER, KEYCODE98_NFER, KEYCODE98_LSHIFT, KEYCODE98_CAPS, KEYCODE98_GRPH, KEYCODE98_CTRL, KEYCODE98_RSHIFT, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_TENKEY_PERIOD, KEYCODE98_NC, KEYCODE98_TENKEY_ASTERISK, KEYCODE98_NC, KEYCODE98_TENKEY_PLUS, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_TENKEY_SLASH, KEYCODE98_TENKEY_RET, KEYCODE98_NC, KEYCODE98_TENKEY_MINUS, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_TENKEY_EQUAL, KEYCODE98_TENKEY_0, KEYCODE98_TENKEY_1, KEYCODE98_TENKEY_2, KEYCODE98_TENKEY_3, KEYCODE98_TENKEY_4, KEYCODE98_TENKEY_5, KEYCODE98_TENKEY_6, KEYCODE98_TENKEY_7, KEYCODE98_NC, KEYCODE98_TENKEY_8, KEYCODE98_TENKEY_9, KEYCODE98_YEN, KEYCODE98_BACKSLASH, KEYCODE98_TENKKEY_COMMA,
    KEYCODE98_F5, KEYCODE98_F6, KEYCODE98_F7, KEYCODE98_F3, KEYCODE98_F8, KEYCODE98_F9, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_COPY, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_F10, KEYCODE98_NC, KEYCODE98_STOP,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_CLR, KEYCODE98_ROLLUP, KEYCODE98_DEL, KEYCODE98_F4, KEYCODE98_HELP, KEYCODE98_F2, KEYCODE98_ROLLDOWN, KEYCODE98_F1, KEYCODE98_LEFT, KEYCODE98_RIGHT, KEYCODE98_DOWN, KEYCODE98_UP, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
    KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC, KEYCODE98_NC,
};


quint8 KbdDrv::keycodeTransrate(quint32 nativeVirtualKey)
{
    if(nativeVirtualKey > 0xff) {
        fprintf(stderr, "Not support key\n");
        return KEYCODE98_NC;
    }
    return trans_table106[nativeVirtualKey & 0xff];
}
