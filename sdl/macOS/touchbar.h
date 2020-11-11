#ifndef __SDL_MACOS_TOUCHBAR_H__
#define __SDL_MACOS_TOUCHBAR_H__

enum _enumTouchbarType {
    NP2_TB_TYPE_IMAGE,
    NP2_TB_TYPE_BUTTON,
    NP2_TB_TYPE_KANA_BUTTON,
};

typedef struct tagTouchbarItem {
    char *id;
    char *caption;
    void (*action)(void *sender);
    int type;
} TOUCHBAR_ITEM;

extern TOUCHBAR_ITEM touchbar_table[];

#ifdef __cplusplus
extern "C" {
#endif

void touchbar_init(void *winid, TOUCHBAR_ITEM *tbtable);
void touchbar_button_onoff(void *button, char val);
void touchbar_kana_led(char val);

#ifdef __cplusplus
}
#endif

#endif /* __SDL_MACOS_TOUCHBAR_H__ */

