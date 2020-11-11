// https://github.com/msorvig/qt-touchbar
// のコードを真似て実装しました。
#import <AppKit/AppKit.h>
#import <stdio.h>
#import "touchbar.h"
#import "AppDelegate.h"
#import "np2png.h"

NSButton *kana_button;

@interface TouchBarProvider: NSResponder <NSTouchBarDelegate, NSWindowDelegate> {
@private
    TOUCHBAR_ITEM *touchbar_table;
}

@property (strong) NSMutableArray<NSCustomTouchBarItem*> *touchBarItems;
@property (strong) NSMutableArray<NSButton*> *touchBarButtons;
@property (strong) NSObject *delegate;

@end

@implementation TouchBarProvider

- (id)init:(TOUCHBAR_ITEM*)tbtable
{
    self = [super init];
    if(self) {
        self.touchBarItems = [[NSMutableArray alloc] init];
        self.touchBarButtons = [[NSMutableArray alloc] init];
        self->touchbar_table = nil;
    }

    return self;
}

- (id)initWithTable:(TOUCHBAR_ITEM*)tbtable
{
    self = [self init];
    if(self) {
        self->touchbar_table = tbtable;
    }

    return self;
}

- (NSTouchBar *)makeTouchBar
{
    if(!self->touchbar_table) {
        return nil;
    }
    NSTouchBar *bar = [[NSTouchBar alloc] init];
    bar.delegate = self;

    NSMutableArray<NSTouchBarItemIdentifier> *ids = [[NSMutableArray alloc] init];
    for(int i = 0; self->touchbar_table[i].id; i++) {
        const char *id = self->touchbar_table[i].id;
        [ids addObject:[[NSString alloc] initWithUTF8String:id]];
    }

    bar.defaultItemIdentifiers = ids;

    return bar;
}

- (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier
{
    NSData *imgData;
    NSImage *img;
    NSButton *button;

    if(!self->touchbar_table) {
        return nil;
    }
    for(int i = 0; self->touchbar_table[i].id; i++) {
        const char *cid = self->touchbar_table[i].id;
        const int type = self->touchbar_table[i].type;
        NSString *id = [[NSString alloc] initWithUTF8String:cid];
        if([identifier isEqualToString:id]) {
            const char *caption = self->touchbar_table[i].caption;
            NSString *title = [[NSString alloc] initWithUTF8String:caption];
            NSCustomTouchBarItem *item = [[NSCustomTouchBarItem alloc] 
                            initWithIdentifier:identifier];
            switch(type) {
                case NP2_TB_TYPE_IMAGE:
                    imgData = [NSData dataWithBytes:g_np2png length:g_np2png_len];
                    img = [[NSImage alloc] initWithData:imgData];
                    button = [NSButton buttonWithImage:img target:self 
                                            action:@selector(buttonClicked:)];
                    break;
                case NP2_TB_TYPE_BUTTON:
                case NP2_TB_TYPE_KANA_BUTTON:
                    button = [NSButton buttonWithTitle:title target:self
                                            action:@selector(buttonClicked:)];
                    if(type == NP2_TB_TYPE_KANA_BUTTON) {
                        kana_button = button;
                    }
                    break;
            }
            button.tag = i;
            item.view = button;
            [self.touchBarButtons addObject:button];
            [self.touchBarItems addObject:item];
            button.bezelColor = NSColor.clearColor;

            return item;
        }
    }
   return nil;
}

- (void)installAsDelegateForWindow:(NSWindow *)window
{
    _delegate = window.delegate;
    window.delegate = self;
}

- (BOOL)respondsToSelector:(SEL)aSelector
{
    return [_delegate respondsToSelector:aSelector] || [super respondsToSelector:aSelector];
}

- (void)forwardInvocation:(NSInvocation *)anInvocation
{
    [anInvocation invokeWithTarget:_delegate];
}

- (void)buttonClicked:(NSButton*)sender
{
    int idx = sender.tag;
    self->touchbar_table[idx].action(sender);
}

@end


void touchbar_init(void *winid, TOUCHBAR_ITEM *tbtable) {
    AppDelegate *appdelegate = [[AppDelegate alloc] init];
    [appdelegate installAsDelegateForApplication:[NSApplication sharedApplication]];

    TouchBarProvider *touchBarProvider = [[TouchBarProvider alloc] initWithTable:tbtable];
    [touchBarProvider installAsDelegateForWindow:winid];
}

void touchbar_button_onoff(void *button, char val)
{
    if(!button) {
        return;
    }
    NSButton *btn = (NSButton*)button;
    if(val) {
        btn.bezelColor = NSColor.systemYellowColor;
    } else {
        btn.bezelColor = NSColor.clearColor;
    }
}

void touchbar_kana_led(char val) {
    touchbar_button_onoff(kana_button, val);
}
