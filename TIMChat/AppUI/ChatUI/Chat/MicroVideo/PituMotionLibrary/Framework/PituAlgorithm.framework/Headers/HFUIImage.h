//
//  HFUIImage.h
//  FilterEngine
//
//  Created by Patrick Yang on 15/3/20.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

struct _Image;

@interface HFUIImage : NSObject

@property (nonatomic, strong) UIImage *UIImage;
@property (nonatomic, assign) struct _Image *image;

+ (HFUIImage *)image;
+ (HFUIImage *)imageWithUIImage:(UIImage *)image;
+ (HFUIImage *)imageWithImage:(struct _Image *)image;
- (id)initWithUIImage:(UIImage *)image;
- (id)initWithImage:(struct _Image *)image;

- (id)copy;

@end
