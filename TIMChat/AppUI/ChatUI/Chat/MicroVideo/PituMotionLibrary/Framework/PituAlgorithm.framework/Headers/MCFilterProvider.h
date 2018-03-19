//
//  MCFilterProvider.h
//  ttpic
//
//  Created by billwang on 16/3/8.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCTmplItem.h"
#import "MCBaseFilter.h"

@interface MCFilterProvider : NSObject

@property (nonatomic, copy) NSString *resourceFolder;
@property (nonatomic, strong) MCBaseFilter *currentFilter;

- (id)initWithResourceFolder:(NSString *)resourceFolder;

- (MCBaseFilter *)filterWithTmplItem:(MCTmplItem *)tmplItem;

@end
