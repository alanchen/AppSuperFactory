//
//  UIWindow+Key.m
//  AppFactory
//
//  Created by Alan on 2024/5/30.
//  Copyright © 2024 alan. All rights reserved.
//

#import "UIWindow+Key.h"
#import "BlocksKit.h"

@implementation UIWindow(Key)

+(NSArray *)appActiveWindowScenes
{
    NSSet *connectedScenes = [UIApplication sharedApplication].connectedScenes;
    NSSet *activeScenes = [connectedScenes bk_select:^BOOL(UIScene *s) {
        return s.activationState == UISceneActivationStateForegroundActive && [s isKindOfClass:[UIWindowScene class]];
    }];
    return [activeScenes allObjects];
}

+(NSArray *)appWindowScenes
{
    NSSet *connectedScenes = [UIApplication sharedApplication].connectedScenes;
    NSSet *scenes = [connectedScenes bk_select:^BOOL(UIScene *s) {
        return [s isKindOfClass:[UIWindowScene class]];
    }];
    return [scenes allObjects];
}

+(UIWindowScene *)appFirstActiveWindowScene
{
    NSArray *activeScenes = [self appActiveWindowScenes];
    return [activeScenes firstObject];
}

+(UIWindow *)appKeyWindow
{
    NSArray *activeScenes = [self appActiveWindowScenes];
    for (UIWindowScene *windowScene in activeScenes) {
        for (UIWindow *window in windowScene.windows) {
            if (window.isKeyWindow) {
                return window;
            }
        }
    }
    
    NSArray *fallbackScenes = [self appWindowScenes];

    return [((UIWindowScene *)[fallbackScenes firstObject]).windows firstObject];
}

+(NSArray *)appWindows
{
    NSArray *activeScenes = [self appActiveWindowScenes];
    for (UIWindowScene *windowScene in activeScenes) {
        if([windowScene.windows count]){
            return windowScene.windows;
        }
    }
    
    NSArray *fallbackScenes = [self appWindowScenes];
    
    return ((UIWindowScene *)[fallbackScenes firstObject]).windows;
}

+(UIInterfaceOrientation)appStatusBarOrientation
{
    UIWindowScene *s = [self appFirstActiveWindowScene];
    return s.interfaceOrientation;
}

+(BOOL)appIsStatusBarHidden
{
    UIWindowScene *windowScene = [UIWindow appFirstActiveWindowScene];
    return windowScene.statusBarManager.isStatusBarHidden;
}

@end
