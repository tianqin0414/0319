#ifndef ILLUMREMOVE_H
#define ILLUMREMOVE_H

#include "type_common.h"
#include <opencv2/core/core_c.h>
#include <opencv2/core/types_c.h>
#include <opencv2/imgproc/imgproc_c.h>

#ifdef __cplusplus
extern "C"
{
#endif
    void histMatch(IplImage *src, IplImage *dst, IplImage *skinModel, int flag);
#ifdef __cplusplus
}
#endif

#endif