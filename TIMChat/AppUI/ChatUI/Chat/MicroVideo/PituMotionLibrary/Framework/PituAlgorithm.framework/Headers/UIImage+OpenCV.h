//
//  UIImage+OpenCV.h
//  FilterEngine
//
//  Created by patyang on 14/9/24.
//  Copyright (c) 2014年 Microrapid. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifdef __cplusplus
extern "C"{
#endif

struct _IplImage;

struct _IplImage *IplImageFromUIImage(UIImage *image);
UIImage *UIImageFromIplImage(const struct _IplImage *image, UIImageOrientation orientation);
struct _IplImage *IplImageFromUIImageWithAlpha(UIImage *image);

#ifdef __cplusplus
};
#endif