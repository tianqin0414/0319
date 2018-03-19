//
//  FilterFactory.h
//  FilterShowcase
//
//  Created by Patrick Yang on 12-6-13.
//  Copyright (c) 2012年 Cell Phone. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GPUImageFilter.h"
#import "CPUImageFilter.h"

@interface MyCamFilterFactory : NSObject



+ (CPUImageFilter *)createCPUFilter:(int)filterId;
+ (GPUImageFilter *)createGPUFilter:(int)filterId;


@end
