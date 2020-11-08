/* On display screen管理
 * 98の画面にオーバーラップするかたちで情報などを表示する機能。SDLのみで使用。
 * 
 * たいそうな名前を付けたが現時点(2020/11/8)ではメニュー表示時のファンクションキー表示を行う。
 * また、SDLのメニューやファイル選択ダイアログはオリジナルのまま別のレイヤーに描画している。
 */
#include <compiler.h>
#include <cpucore.h>
#include <stdlib.h>
#include <string.h>
#include "common/rect.h"
#include "embed/vramhdl.h"
#include "osdmng.h"
#include <font/font.h>
#include "keystat.h"
#include "kbdmng.h"
#include "pccore.h"

#if !defined(__LIBRETRO__)
static void osd_drawFuncKey(const VRAMHDL vram, const OEMCHAR *funckey[]);
static void osd_drawAnkText(const VRAMHDL vram, const int posx, const int posy,
			const OEMCHAR *text, const UINT32 forecolor, const UINT32 backcolor);
static void osd_drawAnkChar(const VRAMHDL vram, const int posx, const int posy,
			const OEMCHAR code, const UINT32 forecolor, const UINT32 backcolor);


static VRAMHDL s_odscrn = NULL;
static BOOL s_osd_enable = FALSE;

static const OEMCHAR *funckey[10] = {
	OEMTEXT(" STOP "),
	OEMTEXT(" COPY "),
	OEMTEXT(" KANA "),
	OEMTEXT(" INS  "),
	OEMTEXT(" DEL  "),
	
	OEMTEXT(" H/C  "),
	OEMTEXT(" HELP "),
	OEMTEXT("      "),
	OEMTEXT("      "),
	OEMTEXT("TENKEY"),
};

/* osdのハンドルの取得 */
VRAMHDL osd_getHandle() {
    return s_odscrn;
}

/* osdの生成 */
BOOL osd_carete(int width, int height, int bpp)
{
    s_odscrn = vram_create(width, height, TRUE, bpp);
    if(s_odscrn) {
        osd_clear(s_odscrn);
    }
    return s_odscrn ? TRUE:FALSE;
}

/* osdをクリアする。 */
void osd_clear(VRAMHDL vram) {
    if(!vram) {
        return;
    }
    memset(vram->ptr, 0, vram->yalign * vram->height);
	memset(vram->alpha, 0, vram->width * vram->height);
}

/* osdの破棄 */
void osd_destroy()
{
    if(!s_odscrn) {
        vram_destroy(s_odscrn);
        s_odscrn = NULL;
    }
}

/* 表示用サーフェスにosdの内容を反映する */
void osd_update(SDL_Surface *disp, int bpp)
{
    void* pc98surf;
    void* dispsurf;
    const UINT8* q;
    UINT8* r;
    UINT8* a;
    int salign;
    int dalign;
    int x;
	int height;

    if(!s_odscrn) {
        return;
    }
    if(s_osd_enable) {
        osd_drawFuncKey(s_odscrn, funckey);
    } else {
        osd_clear(s_odscrn);
    }

	height = s_odscrn->height;
    SDL_LockSurface(disp);
    dispsurf = disp->pixels;
    switch(bpp) {
#if defined(SUPPORT_16BPP)
        case 16:
            q = s_odscrn->ptr;
            r = (UINT8*)dispsurf;
            a = s_odscrn->alpha;
            salign = s_odscrn->width;
            dalign = s_odscrn->yalign - (s_odscrn->width * s_odscrn->xalign);
            do {
                x = 0;
                do {
                    if(a[x]) {
						*(UINT32*)r = *(UINT32*)(q + (x * 2));
                    }
                    r += s_odscrn->xalign;
                } while(++x < s_odscrn->width);
                q += salign * 2;
                r += dalign;
                a += salign;
            } while(--height);
            break;
#endif
#if defined(SUPPORT_32BPP)
		case 32:
			q = s_odscrn->ptr;
			r = (UINT8*)dispsurf;
			a = s_odscrn->alpha;
			salign = s_odscrn->width;
			dalign = s_odscrn->yalign - (s_odscrn->width * s_odscrn->xalign);
			do {
				x = 0;
				do {
					if(a[x]) {
						*(UINT32*)r = *(UINT32*)(q + (x * 4));
					}
					r += s_odscrn->xalign;
				} while(++x < s_odscrn->width);
				q += salign * 4;
				r += dalign;
				a += salign;
			} while(--height);
			break;
#endif
	}
	SDL_UnlockSurface(disp);
}

/* osdの状態を返す */
BOOL osd_getEnable()
{
    return s_osd_enable;
}

/* osdの状態を設定する */
void osd_setEnable(BOOL val)
{
    s_osd_enable = val;

    if(!s_odscrn) {
        return;
    }
	setScreenUpdateFlag();
}

/* ファンクションキーの割り当て情報をosd描画する */
static void osd_drawFuncKey(const VRAMHDL vram, const OEMCHAR *funckey[]) {
	int x = 0;
	int y = vram->height - 16;
	const UINT32 black = RGB32D(0, 0, 0);
	const UINT32 light_blue = RGB32D(24, 235, 249);
	const UINT32 yellow = RGB32D(255, 235, 0);
	osd_drawAnkText(vram, x, y, "    ", black, black);
	x = 4 * 8;
	for(int i = 0; i < 5; i++) {
		if(i == 2 && keystat_kanaled())  {	
					// かなロック中の場合、F3の
					// ファンクションキー表示の背景色を黄色にする
			osd_drawAnkText(vram, x, y, funckey[i], black, yellow);
		} else {
			osd_drawAnkText(vram, x, y, funckey[i], black, light_blue);
		}
		x += strlen(funckey[i]) * 8;
		osd_drawAnkText(vram, x, y, " ", black, black);
		x += 8;
	}
	osd_drawAnkText(vram, x, y, "   ", black, black);
	x += 8 * 3;
	for(int i = 5; i < 10; i++) {
		if(i == 9 && g_tenkey)  {	
					// テンキーモード中の場合、F10の
					// ファンクションキー表示の背景色を黄色にする
			osd_drawAnkText(vram, x, y, funckey[i], black, yellow);
		} else {
			osd_drawAnkText(vram, x, y, funckey[i], black, light_blue);
		}
		x += strlen(funckey[i]) * 8;
		osd_drawAnkText(vram, x, y, " ", black, black);
		x += 8;
	}
	osd_drawAnkText(vram, x, y, "   ", black, black);
}

/* ANK文字列をVRAMHDLに描画する。(98のフォントを使う) */
static void osd_drawAnkText(const VRAMHDL vram, const int posx, const int posy,
			const OEMCHAR *text, const UINT32 forecolor, const UINT32 backcolor) {
	for(int i = 0; i < strlen(text); i++) {
		osd_drawAnkChar(vram, posx + i * 8, posy, text[i], forecolor, backcolor);
	}
}

/* ANK文字をVRAMHDLに描画する。(98のフォントを使う) */
static void osd_drawAnkChar(const VRAMHDL vram, const int posx, const int posy,
			const OEMCHAR code, const UINT32 forecolor, const UINT32 backcolor) {
#ifdef SUPPORT_16BPP
	UINT16 forecolor16 = MAKE16PAL(forecolor);
	UINT16 backcolor16 = MAKE16PAL(backcolor);
#endif
#if defined(SUPPORT_24BPP) || defined(SUPPORT_32BPP)
	UINT8 forecolor24[] = {
		(UINT8)(forecolor),
		(UINT8)(forecolor >> 8),
		(UINT8)(forecolor >> 16),
	};
	UINT8 backcolor24[] = {
		(UINT8)(backcolor),
		(UINT8)(backcolor >> 8),
		(UINT8)(backcolor >> 16),
	};
#endif
	UINT8 *p = &fontrom[0x80000 + (code << 4)];

	for(int y = 0; y < 16; y++) {
		UINT8 pt = *p;
		for(int x = 0; x < 8; x++) {
			int xx = posx + x;
			int yy = posy + y;
			if(xx < vram->posx || yy < vram->posy
					|| xx >= vram->width || yy >= vram->height) {
				continue;
			}
			UINT8 *p = vram->ptr + (xx - vram->posx) * vram->xalign 
						+ (yy - vram->posy) * vram->yalign;
			UINT8 *a = vram->alpha + xx - vram->posx
						+ (yy - vram->posy) * vram->width;
			switch (vram->bpp)
			{
#ifdef SUPPORT_16BPP
			case 16:
				if(pt & 0x80) {
					*(UINT16*)p = forecolor16;
				} else {
					*(UINT16*)p = backcolor16;
				}
				break;
#endif
#if defined(SUPPORT_24BPP) || defined(SUPPORT_32BPP)
			case 24:
			case 32:
				if(pt & 0x80) {
					p[0] = forecolor24[0];
					p[1] = forecolor24[1];
					p[2] = forecolor24[2];
				} else {
					p[0] = backcolor24[0];
					p[1] = backcolor24[1];
					p[2] = backcolor24[2];
				}
				break;
#endif
			}
			*a = 0xff;
			pt <<= 1;
		}
		p++;
	}
}
#endif