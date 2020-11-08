#ifndef __OSDMNG_H__
#define __OSDMNG_H__

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__LIBRETRO__)
VRAMHDL osd_getHandle();
BOOL osd_carete(int width, int height, int bpp);
void osd_clear(VRAMHDL handle);
void osd_update(SDL_Surface *disp, int bpp);
BOOL osd_getEnable();
void osd_setEnable(BOOL val);
void osd_destroy();
#endif

#ifdef __cplusplus
}
#endif

#endif
