//
//  BridgeModel.h
//  ttpic
//
//  Created by v_gyguo on 16/3/9.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BridgeModel : NSObject

@property (nonatomic, assign) NSInteger input;  // NSUInteger
@property (nonatomic, assign) NSInteger output;
@property (nonatomic, assign) NSInteger index;

+ (BridgeModel *)parseDictionnary:(NSDictionary *)dict;
+ (BridgeModel *)createNoneModel;

@end
