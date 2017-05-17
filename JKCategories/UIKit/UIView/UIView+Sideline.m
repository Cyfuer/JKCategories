//
//  UIView+Sideline.m
//  JKCategories-Demo
//
//  Created by iflashbuy_dev on 2017/5/17.
//  Copyright © 2017年 www.skyfox.org. All rights reserved.
//

#import "UIView+Sideline.h"

@implementation UIView (Sideline)

- (void)setLine:(SideType)types {
    [self addLayerWithSides:types isDash:NO];
}

- (void)setDashLine:(SideType)types {
    [self addLayerWithSides:types isDash:YES];
}

- (void)addLayerWithSides:(SideType)sides isDash:(BOOL)isDash {
    if (sides & UIViewSideTop) {
        CAShapeLayer *layer = [self shapeLayerWithSide:UIViewSideTop isDash:isDash];
        [self.layer addSublayer:layer];
    }
    
    if (sides & UIViewSideLeft) {
        CAShapeLayer *layer = [self shapeLayerWithSide:UIViewSideLeft isDash:isDash];
        [self.layer addSublayer:layer];
    }
    
    if (sides & UIViewSideBottom) {
        CAShapeLayer *layer = [self shapeLayerWithSide:UIViewSideBottom isDash:isDash];
        [self.layer addSublayer:layer];
    }
    
    if (sides & UIViewSideRight) {
        CAShapeLayer *layer = [self shapeLayerWithSide:UIViewSideRight isDash:isDash];
        [self.layer addSublayer:layer];
    }
}

- (CAShapeLayer *)shapeLayerWithSide:(SideType)side isDash:(BOOL)isDash {
    UIBezierPath *path = [UIBezierPath bezierPath];
    switch (side) {
        case UIViewSideTop:
        {
            [path moveToPoint:CGPointMake(0, 0)];
            [path addLineToPoint:CGPointMake(self.bounds.size.width, 0)];
        }
            break;
        case UIViewSideLeft:
        {
            [path moveToPoint:CGPointMake(0, 0)];
            [path addLineToPoint:CGPointMake(0, self.bounds.size.height)];
        }
            break;
        case UIViewSideBottom:
        {
            [path moveToPoint:CGPointMake(0, self.bounds.size.height)];
            [path addLineToPoint:CGPointMake(self.bounds.size.width, self.bounds.size.height)];
        }
            break;
        case UIViewSideRight:
        {
            [path moveToPoint:CGPointMake(self.bounds.size.width, 0)];
            [path addLineToPoint:CGPointMake(self.bounds.size.width, self.bounds.size.height)];
        }
            break;
            
        default:
            break;
    }
    
    // 最后的闭合线是可以通过调用closePath方法来自动生成的，也可以调用-addLineToPoint:方法来添加
    //[path closePath];
    
    // 创建图层
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    shapeLayer.strokeColor = [UIColor colorWithRed:0.88 green:0.88 blue:0.88 alpha:1.00].CGColor;
    shapeLayer.fillColor = [UIColor colorWithRed:0.88 green:0.88 blue:0.88 alpha:1.00].CGColor;
    //  设置线宽，线间距
    if (isDash) {
        [shapeLayer setLineDashPattern:[NSArray arrayWithObjects:[NSNumber numberWithInt:5], [NSNumber numberWithInt:1], nil]];
        shapeLayer.lineJoin = kCALineJoinRound;
        shapeLayer.lineCap = kCALineCapRound;
    }
    
    shapeLayer.lineWidth = .5;
    shapeLayer.path = path.CGPath;
    
    return shapeLayer;
}


@end
