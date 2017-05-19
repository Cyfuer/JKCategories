//
//  NSString-tools.h
//  JKCategories-Demo
//  需要注意的是C语言方法就算在两个完全无关联的类里面同名都会报重复定义的错
//  Created by Cyfuer on 2017/5/17.
//  Copyright © 2017年 Cyfuer. All rights reserved.
//


#import <Foundation/Foundation.h>

/**
 *  判断字符串是否为空
 *
 *  @param string 字符串
 *
 *  @return string 为空,返回 YES
            string 不为空,返回 NO
 */
BOOL isEmpty_str(NSString *string) {
    if ([string isKindOfClass:[NSString class]] || [string isKindOfClass:[NSNull class]]) {
        return (string == nil) || [string isEqual:[NSNull null]] || (string.length == 0) ;
    } else {
        return YES;
    }
}

/**
 *  带默认字符串判空显示
 *
 *  @param displayStr 要显示的字符串
 *  @param defaultStr 默认的字符串
 *
 *  @return displayStr 为空，返回 defaultStr
            displayStr 不为空，返回 displayStr
 */
NSString *deal_emptystr_withDefaultStr(NSString *displayStr, NSString *defaultStr) {
    if (isEmpty_str(displayStr)) {
        return defaultStr;
    } else {
        return displayStr;
    }
}

/**
 *  带空字符串判空显示
 *
 *  @param displayStr 要显示的字符串
 *
 *  @return displayStr 为空，返回 空字符串
            displayStr 不为空，返回 displayStr
 */
NSString *deal_emptystr(NSString *displayStr) {
    if (isEmpty_str(displayStr)) {
        return @"";
    } else {
        return displayStr;
    }
}

/**
 *  拼接字符串
 *
 *  @param str 字符串，可放任意个数
 *
 *  @return 拼接起来的字符串
 */
NSString *link_strs(NSString *str,...) {
    // 根据可变参数获取数组
    NSMutableString *mutableStr = [NSMutableString string];
    if (str && ![str isEqual:[NSNull null]]) {
        id eachObject;
        va_list argumentList;
        
        [mutableStr appendString:null(str, @"")];
        va_start(argumentList, str);
        while ((eachObject = va_arg(argumentList, id))) {
            [mutableStr appendString:null(eachObject, @"")];
        }
        va_end(argumentList);
    }
    
    return (NSString *)mutableStr;
}

/**
 *  把字符串转换成NSURL对象
 */
NSURL *url_str(NSString *urlStr) {
    if (isEmpty_str(urlStr)) {
        return nil;
    }
    else {
        return [NSURL URLWithString:urlStr];
    }
}
