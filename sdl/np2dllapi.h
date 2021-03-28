#ifndef __NP2API_H__
#define __NP2API_H__


#ifdef _WINDOWS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT 
#endif

#ifdef __cplusplus
extern "C" {
#endif

DLLEXPORT int np2api_main(int argc, char *argv[], void *winid);
DLLEXPORT int np2api_end();
DLLEXPORT void np2api_exec();

#ifdef __cplusplus
}
#endif

#endif