#include "np2.h"
#include "np2dllapi.h"

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
    np2_exec();    
}