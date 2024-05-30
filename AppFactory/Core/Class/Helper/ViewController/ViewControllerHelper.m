//
//  ViewControllerHelper.m
//  AppFactory
//
//  Created by alan on 2017/10/9.
//  Copyright © 2017年 alan. All rights reserved.
//

#import "ViewControllerHelper.h"
#import "UIApplication+AFExtension.h"
#import "UIWindow+Key.h"

@implementation ViewControllerHelper

+(UIViewController *)currentViewController
{
    return [[UIApplication sharedApplication] visibleViewController];
}

+(UIViewController *)currentViewControllerWithWindow:(UIWindow *)window
{
    UIViewController *rootViewController = window.rootViewController;
    return [[UIApplication sharedApplication] getVisibleViewController:rootViewController];
}

+(void)switchMainTabBarToSelectedIndex:(NSUInteger)selectedIndex
                             popToRoot:(BOOL)popToRoot
                        withCompletion:(void (^)(void))completion
{
    UITabBarController *tabVC = (UITabBarController *)[UIWindow appKeyWindow].rootViewController;
    if([tabVC isKindOfClass:[UITabBarController class]]){
        [tabVC switchToSelectedIndex:selectedIndex popToRootWithCompletion:^{
            if(completion)completion();
        }];
    }else{
        if(completion)completion();
    }
}

@end
