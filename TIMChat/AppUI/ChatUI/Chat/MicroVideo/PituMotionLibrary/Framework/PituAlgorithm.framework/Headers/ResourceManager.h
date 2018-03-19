//
//  ResourceManager.h
//  FilterEngine
//
//  Created by patyang on 14/12/15.
//  Copyright (c) 2014年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FilterEngine/type_common.h>

@interface ResourceManager : NSObject

@property (nonatomic, strong) NSString *bundleDirctory;

+ (ResourceManager *)shareManager;
- (NSString *)root;
- (NSString *)locateResource:(NSString *)relative;
- (UIImage *)loadUIImageResource:(NSString *)relative;
- (UIImage *)loadUIImageResource:(NSString *)relative bundlePath:(NSString *)bundlePath;
- (Image *)loadDataResource:(NSString *)relative;
- (Image *)loadImageResource:(NSString *)relative;
- (Image *)loadFilterResource:(NSString *)relative;
- (Image *)loadFilterResource:(NSString *)relative bundlePath:(NSString *)bundlePath;
- (Image *)loadFaceJpgResource:(NSString *)relative;
- (Image *)loadFaceRawResource:(NSString *)relative width:(NSInteger)width height:(NSInteger)height;
- (Image *)loadFaceBmpResource:(NSString *)relative;
- (Image *)loadCurveResource:(NSString *)relative;
- (Image *)loadCurve1DData:(U8 *)data;

@end
