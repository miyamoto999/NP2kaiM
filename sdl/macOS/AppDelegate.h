#import <Cocoa/Cocoa.h>

@interface AppDelegate:NSObject<NSApplicationDelegate>

@property (strong) NSObject *delegate;

- (void)installAsDelegateForApplication:(NSApplication *)application;

@end