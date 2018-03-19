/********************************************************************
	created:	2013/12/04
	author:		mionyu
	
	purpose:	functions assist to use qimage 
				tested in visual studio 2012
*********************************************************************/

#pragma once
//#include <QtCore/QtCore>
//#include <QtGui/QtGui>
#include "type_common.h"
//#include <cv.h>
#include <opencv2/core/core.hpp>

cv::Mat createMatFromImage(Image const& img);
Image createImageFromMat(cv::Mat const &mat);

cv::Mat Image2Mat( const Image *img, int dataType);
Image* mat2Image(cv::Mat const &mat);

IplImage* Image2IplImage(const Image *img);
Image *IplImage2Image( const IplImage *ipl);
