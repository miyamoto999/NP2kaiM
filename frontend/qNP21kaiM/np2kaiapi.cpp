#include <QMessageBox>
#include <QLibrary>
#include "np2kaiapi.h"

NP2kaiapi::NP2kaiapi()
{
    _np2api_main = NULL;
    _np2api_end = NULL;
    _np2api_exec = NULL;
    _np2api_keyup = NULL;
    _np2api_keydown = NULL;
}

bool NP2kaiapi::load()
{
    QLibrary dllcore("libNP21kaiM_core.so");

    if(!dllcore.load()) {
        dllcore.setFileName("NP21kaiM_core");
        if(!dllcore.load()) {
            fprintf(stderr, "NP21kaiM_core DLL load ERROR\n");
            unload();
            return false;
        }
    }

    _np2api_main = (NP2API_MAIN)dllcore.resolve("np2api_main");
    if(!_np2api_main) {
        fprintf(stderr, "np2api_main func resolve ERROR\n");
        unload();
        return false;
    }
    _np2api_end = (NP2API_END)dllcore.resolve("np2api_end");
    if(!_np2api_end) {
        fprintf(stderr, "np2api_end func resolve ERROR\n");
        unload();
        return false;
    }
    _np2api_exec = (NP2API_EXEC)dllcore.resolve("np2api_exec");
    if(!_np2api_exec) {
        fprintf(stderr, "np2api_exec func resolve ERROR\n");
        unload();
        return false;
    }

    _np2api_keyup = (NP2API_KEYUPDOWN)dllcore.resolve("np2api_keyup");
    if(!_np2api_keyup) {
        fprintf(stderr, "np2api_keyup func resolve ERROR\n");
        unload();
        return false;
    }

    _np2api_keydown = (NP2API_KEYUPDOWN)dllcore.resolve("np2api_keydown");
    if(!_np2api_keydown) {
        fprintf(stderr, "np2api_keyudown func resolve ERROR\n");
        unload();
        return false;
    }

    return true;
}
