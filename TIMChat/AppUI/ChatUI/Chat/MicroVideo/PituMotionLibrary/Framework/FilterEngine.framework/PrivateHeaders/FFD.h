#pragma once
#include <vector>
#include "FFDPoint.h"

#define USE_TABLE_LOOKUP 0
class FFD
{
	static const int B_MAP_SIZE = 100;
public:
	FFD(void);
	~FFD(void);
	double process(int w,int h,double latticeDist,std::vector<FFDPoint> P,std::vector<FFDPoint> Q);
	FFDPoint warp(FFDPoint p) const;
    FFDPoint warpex( FFDPoint p ) const;
	std::vector<FFDPoint> warp(const std::vector<FFDPoint> &P) const;

	static double error(const std::vector<FFDPoint> &P,const std::vector<FFDPoint> &Q);
// Get methods
    int GetRow() const;
    int GetCol() const;
    int GetDist() const;
    const std::vector<FFDPoint> &GetFi() const;
    const std::vector<FFDPoint> &GetDeltaFi() const;
private:
	static double Weight(int k,int l,double s,double t);
	static double B(int i,double t);
	// use table look-up to speed up Bernstein polynomial calculation
	static inline double B2(int i,double t);
	static double (*bMap)[B_MAP_SIZE];

	unsigned char * srcData;
	unsigned char * dstData;
	int row,col;
	double dist;

	std::vector<FFDPoint> fi;
	std::vector<FFDPoint> deltaFi;
};

// Inline trivial functions
inline int FFD::GetRow() const
{
    return row;
}

inline int FFD::GetCol() const
{
    return col;
}

inline int FFD::GetDist() const
{
    return dist;
}

inline const std::vector<FFDPoint> &FFD::GetFi() const
{
    return fi;
}

inline const std::vector<FFDPoint> &FFD::GetDeltaFi() const
{
    return deltaFi;
}