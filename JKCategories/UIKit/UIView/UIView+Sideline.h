//
//  UIView+Sideline.h
//  JKCategories-Demo
//
//  Created by iflashbuy_dev on 2017/5/17.
//  Copyright © 2017年 www.skyfox.org. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_OPTIONS(NSUInteger, SideType) {
    UIViewSideTop     = 1 << 0,
    UIViewSideLeft    = 1 << 1,
    UIViewSideBottom  = 1 << 2,
    UIViewSideRight   = 1 << 3,
    UIViewSideAll = ~0UL
};

@interface UIView (Sideline)

// 为view某个方向的边描线
- (void)setLine:(SideType)types Color:(UIColor *)color;

// 为view某个方向的边描虚线
- (void)setDashLine:(SideType)types Color:(UIColor *)color;


@end
