#ifndef IMAGE_NIGHT_H
#define IMAGE_NIGHT_H
#include "type_common.h"
#ifdef __cplusplus
extern "C"
{
#endif
	void getImageAutoThreshold(Image *srcImage, int *blackThreshold, int *whiteThreshHold, double *gamma);
	void image_match_blend_nomatch7(Image **srcImage, Image *dstImage);
	void image_match_deblur(Image **srcImage, Image *dstImage, int num_image);
	void imageLevel(Image *srcImage, Image *dstImage ); 
	//void image_match_blend(Image **srcImage, Image *dstImage, int num_image);
    
    void image_filter_people(Image *image, Image *people);
    void image_filter_flash(Image *image, Image *flash);
	
#ifdef __cplusplus
}
#endif

#endif