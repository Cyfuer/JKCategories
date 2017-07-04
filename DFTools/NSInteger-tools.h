//
//  NSInteger-tools.h
//  JKCategories-Demo
//
//  Created by Cyfuer on 2017/6/2.
//  Copyright © 2017年 Cyfuer. All rights reserved.
//

#ifndef NSInteger_tools_h
#define NSInteger_tools_h

/**
 *  算余除法
 *
 *  @param dividend 被除数
 *  @param divisor 除数
 *
 *  @return 计算出被除数除以除数的结果，如果余数不等于0，结果加一
 */
NSInteger residueDivision(NSInteger dividend,NSInteger divisor) {
    return (dividend / divisor) + (dividend % divisor > 0 ? 1 : 0);
}

#endif /* NSInteger_tools_h */
