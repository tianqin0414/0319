//
//  BaseFilterParam.h
//  ttpic
//
//  Created by v_gyguo on 16/3/9.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BaseFilterParam : NSObject

@property (nonatomic, retain) NSString *type;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *value;

+ (BaseFilterParam *)parseDictionary:(NSDictionary *)dict;  //生产方法
+ (BaseFilterParam *)createNoneModel;

@end
