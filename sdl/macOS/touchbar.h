#ifndef __SDL_MACOS_TOUCHBAR_H__
#define __SDL_MACOS_TOUCHBAR_H__


typedef struct tagTouchbarItem {
    char *id;
    char *caption;
    void (*action)();
} TOUCHBAR_ITEM;

extern TOUCHBAR_ITEM touchbar_table[];

#ifdef __cplusplus
extern "C" {
#endif

void touchbar_init(void *winid, TOUCHBAR_ITEM *tbtable);

#ifdef __cplusplus
}
#endif

#endif /* __SDL_MACOS_TOUCHBAR_H__ */

