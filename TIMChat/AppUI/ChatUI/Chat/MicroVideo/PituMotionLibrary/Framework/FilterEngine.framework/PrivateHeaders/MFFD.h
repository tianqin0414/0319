#pragma once
#include "FFD.h"

class MFFD
{
public:
	MFFD(void);
	~MFFD(void);


    bool hasProcess;
    void reset()
    {
        hasProcess = false;
        ffdArr.clear();
    }
	double process( int w,int h,double latticeDistMax,double latticeDistMin,const std::vector<FFDPoint> &P,const std::vector<FFDPoint> &Q , double threshold, double alpha);
	FFDPoint warp(FFDPoint p) const;
    FFDPoint warpex( FFDPoint p ) const;
	std::vector<FFDPoint> warp(const std::vector<FFDPoint> &P) const;

	std::vector<FFD> ffdArr;
};
