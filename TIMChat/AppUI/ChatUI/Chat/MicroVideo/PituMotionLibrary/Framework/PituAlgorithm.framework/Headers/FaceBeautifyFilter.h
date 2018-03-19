//
//  FaceBeautifyFilter.h
//  FilterEngine
//
//  Created by Patrick Yang on 15/1/15.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#ifndef FilterEngine_FaceBeautifyFilter_h
#define FilterEngine_FaceBeautifyFilter_h

typedef enum
{
    FBPF_NONE = 0,
    FBPF_ZIRAN,
    FBPF_HONGRUN,
    FBPF_BAIXI,
    FBPF_TIANMEI,
    FBPF_MENGHUAN,
    FBPF_YANGGUANG,
    FBPF_ROUNEN,
    FBPF_TOTAL
}FBPF_TYPE;

typedef enum
{
    FBPFQ_NONE = 0,
    FBPFQ_LOW,
    FBPFQ_MEDIUM,
    FBPFQ_HIGH,
}FBPF_QUALITY;

#endif
