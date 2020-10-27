#include <compiler.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysmenu.h>
#include  <embed/vramhdl.h>
#include  <embed/menubase/menubase.h>
#include <keystat.h>
#include "touchbar.h"

static void clicked_menu() {
    if (menuvram == NULL) {
        sysmenu_menuopen(0, 0, 0);
    }
    else {
        menubase_close();
    }
}

static void clicked_stop() {
    keystat_senddata(0x60);
    keystat_senddata(0x60 | 0x80);    
}

static void clicked_copy() {
    keystat_senddata(0x61);
    keystat_senddata(0x61 | 0x80);    
}

static void clicked_kana() {
    keystat_senddata(0x72);
    keystat_senddata(0x72 | 0x80);    
}

static void clicked_ins() {
    keystat_senddata(0x38);
    keystat_senddata(0x38 | 0x80);    
}

static void clicked_del() {
    keystat_senddata(0x39);
    keystat_senddata(0x39 | 0x80);    
}

static void clicked_home() {
    keystat_senddata(0x3e);
    keystat_senddata(0x3e | 0x80);    
}

static void clicked_help() {
    keystat_senddata(0x3f);
    keystat_senddata(0x3f | 0x80);    
}

TOUCHBAR_ITEM touchbar_table[] = {
    { "jp.hemohemo.Np21kaiM.btnMENU", "MENU", clicked_menu},
    { "jp.hemohemo.Np21kaiM.btnSTOP", "STOP", clicked_stop},
    { "jp.hemohemo.Np21kaiM.btnCOPY", "COPY", clicked_copy},
    { "jp.hemohemo.Np21kaiM.btnKANA", "KANA", clicked_kana},
    { "jp.hemohemo.Np21kaiM.btnINS", "INS", clicked_ins},
    { "jp.hemohemo.Np21kaiM.btnDEL", "DEL", clicked_del},
    { "jp.hemohemo.Np21kaiM.btnHOME", "H/C", clicked_home},
    { "jp.hemohemo.Np21kaiM.btnHELP", "HELP", clicked_help},
    { NULL, NULL, NULL}
};
