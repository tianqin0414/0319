//
//  MultiFilterParamConnect.h
//  PituAlgorithm
//
//  Created by zijun on 16/3/15.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import "MultiFilterConnect.h"

@interface MultiFilterParamConnect : MultiFilterConnect

@property (nonatomic, retain) NSMutableArray *baseFilters;
@property (nonatomic, retain) NSMutableArray *bridges;
@property (nonatomic, retain) NSString *bundlePath;

- (instancetype)initWithBaseFilters:(NSMutableArray *)baseFilters bridges:(NSMutableArray *)bridges bundlePath:(NSString *)bundlePath;

@end
