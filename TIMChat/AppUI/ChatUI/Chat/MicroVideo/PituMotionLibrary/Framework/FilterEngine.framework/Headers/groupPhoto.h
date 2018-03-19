#ifndef GROUPPHOTO_H
#define GROUPPHOTO_H

#include "type_common.h"
#include <opencv2/core/core_c.h>
#include <opencv2/core/types_c.h>
#include <opencv2/imgproc/imgproc_c.h>

#ifdef __cplusplus
extern "C"
{
#endif
    void GetMaskMidWidth(IplImage *mask, int &midx);
    void GetMaskRect(IplImage *mask, CvRect &rect);
    void callHistMatch(IplImage *src, IplImage *dst, int flag);
    IplImage *DeepSegProcess(IplImage *src, IplImage* mask);     //return src roi
    IplImage *DeepSegMaskProcess(IplImage *src, IplImage* mask); //return mask
    IplImage *MergeProcess(IplImage *foreimg, IplImage *midimg, IplImage *bgimg, CvRect midroi);
    IplImage *MergeProcess2(IplImage *midimg, IplImage *bgimg, CvRect midroi);
    CvRect intersectcvRect(CvRect *r1, CvRect *r2);
    void mergeAlpha(IplImage *rgb, IplImage *alpha);
    void cutAlpha(IplImage *src, IplImage *rgb, IplImage *alpha);
    
    IplImage *buildBodyForeImage(IplImage *src, IplImage *mask);
    IplImage *DeepSegHair(IplImage *src, IplImage* mask);
    
#ifdef __cplusplus
}
#endif

#endif