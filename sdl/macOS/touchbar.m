// https://github.com/msorvig/qt-touchbar
// のコードを真似て実装しました。
#import <AppKit/AppKit.h>
#import <stdio.h>
#import "touchbar.h"
#import "AppDelegate.h"

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
    if(!self->touchbar_table) {
        return nil;
    }
    for(int i = 0; self->touchbar_table[i].id; i++) {
        const char *cid = self->touchbar_table[i].id;
        NSString *id = [[NSString alloc] initWithUTF8String:cid];
        if([identifier isEqualToString:id]) {
            const char *caption = self->touchbar_table[i].caption;
            NSString *title = [[NSString alloc] initWithUTF8String:caption];
            NSCustomTouchBarItem *item = [[NSCustomTouchBarItem alloc] initWithIdentifier:identifier];
            NSButton *button = [NSButton buttonWithTitle:title target:self
                                            action:@selector(buttonClicked:)];
            item.view =  button;
            [self.touchBarButtons addObject:button];
            [self.touchBarItems addObject:item];
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
    const char *title = [[sender title] UTF8String];
    for(int i = 0; self->touchbar_table[i].id; i++) {
        if(strcmp(title, self->touchbar_table[i].caption) == 0) {
            self->touchbar_table[i].action();
            return;
        }
    }
}

@end


void touchbar_init(void *winid, TOUCHBAR_ITEM *tbtable) {
    AppDelegate *appdelegate = [[AppDelegate alloc] init];
    [appdelegate installAsDelegateForApplication:[NSApplication sharedApplication]];

    TouchBarProvider *touchBarProvider = [[TouchBarProvider alloc] initWithTable:tbtable];
    [touchBarProvider installAsDelegateForWindow:winid];
}
