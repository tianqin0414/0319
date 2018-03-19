//
//  HFType.h
//  FilterEngine
//
//  Created by Patrick Yang on 15/6/12.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#ifndef __FilterEngine__HFType__
#define __FilterEngine__HFType__

#include <stdio.h>

struct HFSize {
    int width;
    int height;
};

typedef struct HFSize HFSize;

typedef struct _RECT_T {
    int x0;
    int y0;
    int x1;
    int y1;
} RECT_T;

typedef struct _Rect {
    int x;
    int y;
    int w;
    int h;
} MRect;

typedef struct
{
    int x;
    int y;
}MPoint;


#endif /* defined(__FilterEngine__HFType__) */
