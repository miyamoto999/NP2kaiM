#include <compiler.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysmenu.h>
#include  <embed/vramhdl.h>
#include  <embed/menubase/menubase.h>
#include <keystat.h>
#include "touchbar.h"

static void clicked_menu(void *sender) {
    if (menuvram == NULL) {
        sysmenu_menuopen(0, 0, 0);
    }
    else {
        menubase_close();
    }
}

static void clicked_stop(void *sender) {
    keystat_senddata(0x60);
    keystat_senddata(0x60 | 0x80);    
}

static void clicked_copy(void *sender) {
    keystat_senddata(0x61);
    keystat_senddata(0x61 | 0x80);    
}

static void clicked_kana(void *sender) {
    keystat_senddata(0x72);
    keystat_senddata(0x72 | 0x80);
    touchbar_kana_led(keystat_kanaled());
}

static void clicked_ins(void *sender) {
    keystat_senddata(0x38);
    keystat_senddata(0x38 | 0x80);
}

static void clicked_del(void *sender) {
    keystat_senddata(0x39);
    keystat_senddata(0x39 | 0x80);    
}

static void clicked_home(void *sender) {
    keystat_senddata(0x3e);
    keystat_senddata(0x3e | 0x80);    
}

static void clicked_help(void *sender) {
    keystat_senddata(0x3f);
    keystat_senddata(0x3f | 0x80);    
}

TOUCHBAR_ITEM touchbar_table[] = {
    { "jp.hemohemo.Np21kaiM.btnMENU", "MENU", clicked_menu, NP2_TB_TYPE_IMAGE},
    { "jp.hemohemo.Np21kaiM.btnSTOP", "STOP", clicked_stop, NP2_TB_TYPE_BUTTON},
    { "jp.hemohemo.Np21kaiM.btnCOPY", "COPY", clicked_copy, NP2_TB_TYPE_BUTTON},
    { "jp.hemohemo.Np21kaiM.btnKANA", "KANA", clicked_kana, NP2_TB_TYPE_KANA_BUTTON},
    { "jp.hemohemo.Np21kaiM.btnINS", "INS", clicked_ins, NP2_TB_TYPE_BUTTON},
    { "jp.hemohemo.Np21kaiM.btnDEL", "DEL", clicked_del, NP2_TB_TYPE_BUTTON},
    { "jp.hemohemo.Np21kaiM.btnHOME", "H/C", clicked_home, NP2_TB_TYPE_BUTTON},
    { "jp.hemohemo.Np21kaiM.btnHELP", "HELP", clicked_help, NP2_TB_TYPE_BUTTON},
    { NULL, NULL, NULL}
};
