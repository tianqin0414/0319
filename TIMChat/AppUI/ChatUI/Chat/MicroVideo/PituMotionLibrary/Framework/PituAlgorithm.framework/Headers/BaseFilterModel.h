//
//  BaseFilterModel.h
//  ttpic
//
//  Created by v_gyguo on 16/3/9.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BaseFilterModel : NSObject

@property (nonatomic, assign) NSInteger baseFilterId;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, retain) NSMutableArray *params;

+ (BaseFilterModel *)parseDictionnary:(NSDictionary *)dict;
+ (BaseFilterModel *)createNoneModel;

@end
