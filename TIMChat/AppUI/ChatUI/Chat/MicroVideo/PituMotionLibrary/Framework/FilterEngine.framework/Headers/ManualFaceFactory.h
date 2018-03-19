//
//  ManualFaceFactory.h
//  FilterEngine
//
//  Created by jasonysliu on 15/8/4.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#ifndef __FilterEngine__ManualFaceFactory__
#define __FilterEngine__ManualFaceFactory__

#include "ManualHandleBase.hpp"
#include <stdio.h>
typedef enum {
    ManualFace_None = -1,
    ManualFace_EnlargeEye,
    ManualFace_LightEye,
    ManualFace_Patch,
    ManualFace_Pouch,
    ManualFace_Reshape,
    ManualFace_Smooth,
    ManualFace_Whiten,
    ManualFace_WhitenTooth,
    ManualFace_LongLeg,
    ManualFace_SlimNose
} ManualFaceType;

ManualHandleBase* createManualHandle(Image *srcImage,ManualFaceType type);

#endif /* defined(__FilterEngine__ManualFaceFactory__) */
