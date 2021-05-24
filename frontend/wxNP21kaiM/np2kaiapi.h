#ifndef NP2KAIAPI_H
#define NP2KAIAPI_H

#ifdef _WIN32
#define DLLMODULE   HMODULE
#else
#define DLLMODULE   void *
#define WINAPI
#endif

typedef int WINAPI (*NP2API_MAIN)(int argc, char *argv[], void *winid);
typedef int WINAPI (*NP2API_END)();
typedef void WINAPI (*NP2API_EXEC)();
typedef void (*NP2API_KEYUPDOWN)(uint8_t keycode98);

class NP2kaiapi
{
public:
    NP2kaiapi();
    ~NP2kaiapi();

    int np2api_main(int argc, char *argv[], void *winid) {
        if(!_np2api_main) {
            return 1;
        }
        return _np2api_main(argc, argv, winid);
    }
    int np2api_end() {
        if(!_np2api_end) {
            return 1;
        }
        return _np2api_end();
    }
    void np2api_exec() {
        if(!_np2api_exec) {
            return;
        }
        _np2api_exec();
    }
    void np2api_keyup(uint8_t keycode98) {
        if(!_np2api_keyup) {
            return;
        }
        _np2api_keyup(keycode98);
    }
    void np2api_keydown(uint8_t keycode98) {
        if(!_np2api_keydown) {
            return;
        }
        _np2api_keydown(keycode98);
    }
    bool load();

    void unload() {
        _np2api_main = NULL;
        _np2api_end = NULL;
        _np2api_exec = NULL;
        _np2api_keyup = NULL;
        _np2api_keydown = NULL;
    }
private:
    NP2API_MAIN _np2api_main;
    NP2API_END _np2api_end;
    NP2API_EXEC _np2api_exec;
    NP2API_KEYUPDOWN _np2api_keydown;
    NP2API_KEYUPDOWN _np2api_keyup;
    DLLMODULE m_dllcore;
};

#endif // NP2KAIAPI_H
