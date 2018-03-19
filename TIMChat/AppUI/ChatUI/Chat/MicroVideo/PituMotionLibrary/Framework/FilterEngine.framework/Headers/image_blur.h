//
//  image_blur.h
//  FilterEngine
//
//  Created by  patyang on 14-2-24.
//  Copyright (c) 2014年 Microrapid. All rights reserved.
//

#ifndef FilterEngine_image_blur_h
#define FilterEngine_image_blur_h

#ifdef __cplusplus
extern "C"{
#endif

struct _Image;

struct _Image *scale_image3(struct _Image *image, int scale);
void average_round_blur(struct _Image *image, int radius);
    
void smooth_border(struct _Image *img_src,int smooth_size,int smooth_channel);
void gauss_blur_border(struct _Image *image,int radius);
void blurBorderForFace(unsigned char* image,unsigned char* dst,int width,int height,int bpp,int radius);
void blur_border(struct _Image *image,int radius);
void inplace_blur_8bit_process(unsigned char * data,int sizex,int sizey,float blur);
void inplace_blur_8bit_process_bpp1(unsigned char * data, int sizex, int sizey, float blur);
void fast_blur(struct _Image *dst, float blur);
#ifdef __cplusplus
};
#endif

#endif
