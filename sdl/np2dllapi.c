#include "np2.h"
#include "np2dllapi.h"
#include "keystat.h"


DLLEXPORT int np2api_main(int argc, char *argv[], void *winid)
{
    return np2_main(argc, argv, winid);
}

DLLEXPORT int np2api_end()
{
    return np2_end();
}

DLLEXPORT void np2api_exec()
{
    np2_core_exec();    
}

DLLEXPORT void np2api_keydown(uint8_t keycode98)
{
    keystat_senddata(keycode98);
}
DLLEXPORT void np2api_keyup(uint8_t keycode98)
{
    keystat_senddata(keycode98 | 0x80);    
}
