//
//  UIColor+AFExtension.h
//  AppFactory
//
//  Created by alan on 2017/10/16.
//  Copyright © 2017年 alan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor(AFExtension)

+ (UIColor *)colorWithHex:(UInt32)hex;
+ (UIColor *)colorWithHex:(UInt32)hex andAlpha:(CGFloat)alpha;
+(UIColor *)color24WithR:(float)r G:(float)g  B:(float)b A:(float)a;
+(UIColor *)hexRGBA:(UInt32)hex;
+(UIColor *)random;
-(UIColor * (^)(CGFloat))withAlpha;
+(UIColor *)fadeFromColor:(UIColor *)fromColor toColor:(UIColor *)toColor withPercentage:(CGFloat)percentage;

@end
