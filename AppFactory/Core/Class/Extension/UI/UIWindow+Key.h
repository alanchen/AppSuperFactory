//
//  UIWindow+Key.h
//  AppFactory
//
//  Created by Alan on 2024/5/30.
//  Copyright © 2024 alan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIWindow(Key)

+(NSArray *)appActiveWindowScenes;
+(NSArray *)appWindowScenes;
+(UIWindowScene *)appFirstActiveWindowScene;

+(NSArray *)appWindows;
+(UIWindow *)appKeyWindow;

+(UIInterfaceOrientation)appStatusBarOrientation;
+(BOOL)appIsStatusBarHidden;

@end

