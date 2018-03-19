#include <opencv2/core/core_c.h>
#include <opencv2/core/types_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include "ImageDefine.h"


class hairGabor{
public:
    hairGabor();
    ~hairGabor();
    
    void initialize(const IplImage *img, const IplImage *const mask, int faceFeature[][2], int flag);
    
    void setStripeMask(IplImage *img);
    bool hasStripeMask();
    
    void lightHairlines(IplImage *img, IplImage *bodyMask, IplImage *backImg, int faceFeature[][2]);
    void dyeHairlines(IplImage *img, IplImage *colorModel, U8 color[], int faceFeature[][2], double mag);
    
    int stripeCnt;
    bool shortHair;
    
private:
    bool emptyMask;
    bool bInitialize;
    IplImage *gb;
    IplImage *wt;
    IplImage *hairMask;
    IplImage *stripeModel;
    IplImage *stripeImgMask;
    CvRect hairRect;
    
    void calcGaborCrop(const IplImage *img, CvRect rect, const IplImage *mask, IplImage *gbImg, IplImage *wtImg, int flag);
    void smoothBilateral(IplImage *image, IplImage *hairMask, int radius, int faceFeature[][2]);
    void releaseRss();
};