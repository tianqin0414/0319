#ifndef IMAGE_HDR_H
#define IMAGE_HDR_H
#include "type_common.h"

#ifdef __cplusplus
extern "C"
{
#endif
//power 0 ~ 100
//blur 0 ~ 2000
void image_filter_hdr(Image *srcImage, Image *dstImage, float power, float blur,int colorTable); 
void image_filter_hdr_hsv(Image *srcImage, Image *dstImage, float power, float blur, float usm_power);
#ifdef __cplusplus
}
#endif

#endif