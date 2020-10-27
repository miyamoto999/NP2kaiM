#import "AppDelegate.h"
#import <stdio.h>

@implementation AppDelegate

- (void)installAsDelegateForApplication:(NSApplication *)application
{
    _delegate = application.delegate; // Save current delegate for forwarding
    application.delegate = self;
}

- (BOOL)respondsToSelector:(SEL)aSelector
{
    return [_delegate respondsToSelector:aSelector] || [super respondsToSelector:aSelector];
}

- (void)forwardInvocation:(NSInvocation *)anInvocation
{
    [anInvocation invokeWithTarget:_delegate];
}

@end