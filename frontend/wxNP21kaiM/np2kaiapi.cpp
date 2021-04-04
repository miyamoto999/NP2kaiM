#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#ifdef _WIN32
#define DLOPEN(f)       LoadLibraryA(f)
#define DLCLOSE(h)      FreeLibrary(h)
#define DLSYM(h, s)     GetProcAddress(h, s)
#else
#include <dlfcn.h>
#define DLOPEN(f)       dlopen(f, RTLD_LAZY)
#define DLCLOSE(h)      dlclose(h)
#define DLSYM(h, s)     dlsym(h, s)
#endif
#include "np2kaiapi.h"

NP2kaiapi::NP2kaiapi()
{
    _np2api_main = NULL;
    _np2api_end = NULL;
    _np2api_exec = NULL;
    m_dllcore = NULL;
}

NP2kaiapi::~NP2kaiapi()
{
    if(m_dllcore) {
        DLCLOSE(m_dllcore);
        m_dllcore = NULL;
    }
}

bool NP2kaiapi::load()
{
    m_dllcore = DLOPEN("libNP21kaiM_core.dylib");
    if(!m_dllcore) {
        m_dllcore = DLOPEN("libNP21kaiM_core.so");
        if(!m_dllcore) {
            m_dllcore = DLOPEN("NP21kaiM_core.dll");
            if(!m_dllcore) {
                fprintf(stderr, "NP21kaiM_core DLL load ERROR\n");
                return false;
            }
        }
    }
    _np2api_main = (NP2API_MAIN)DLSYM(m_dllcore, "np2api_main");
    if(!_np2api_main) {
        fprintf(stderr, "np2api_main func resolve ERROR\n");
        unload();
        return false;
    }
    _np2api_end = (NP2API_END)DLSYM(m_dllcore, "np2api_end");
    if(!_np2api_end) {
        fprintf(stderr, "np2api_end func resolve ERROR\n");
        unload();
        return false;
    }
    _np2api_exec = (NP2API_EXEC)DLSYM(m_dllcore, "np2api_exec");
    if(!_np2api_exec) {
        fprintf(stderr, "np2api_exec func resolve ERROR\n");
        unload();
        return false;
    }

    return true;
}
