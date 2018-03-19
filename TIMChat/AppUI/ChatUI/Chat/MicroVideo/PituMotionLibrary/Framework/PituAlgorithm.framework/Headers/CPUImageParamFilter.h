//
//  CPUImageParamFilter.h
//  PituAlgorithm
//
//  Created by v_gyguo on 16/3/25.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPUImageFilter.h"

@interface CPUImageParamFilter : CPUImageFilter

@property (nonatomic, retain) NSMutableArray *baseFilters;
@property (nonatomic, retain) NSMutableArray *bridges;
@property (nonatomic, retain) NSString *bundlePath;

- (instancetype)initWithBaseFilters:(NSMutableArray *)baseFilters bridges:(NSMutableArray *)bridges bundlePath:(NSString *)bundlePath;

@end
