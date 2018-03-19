#ifndef SHAREDMSTTING_H
#define SHAREDMSTTING_H

#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>

#ifndef _DBG
#define _DBG        (0)

#if (_DBG)
#define MY_PRINT(x) log_printD x
#else
#define MY_PRINT(x)
#endif

#if (_DBG)
#define LOCATE_TIMER    int64 start_time, end_time
#define START_TIMER     do {start_time = clock();} while (0)
#define SHOW_TIMER(str) do {end_time = clock(); \
MY_PRINT(("[%.3f s] "#str, (double)(end_time - start_time) / CLOCKS_PER_SEC));    \
MY_PRINT(("\n"));} while (0)
#else
#define LOCATE_TIMER
#define START_TIMER
#define SHOW_TIMER(str)
#endif
#endif

using namespace std;

#define INNER_EDGE              (0x1)
#define OUTER_EDGE              (0x2)
#define BOTH_INNER_OUTER_EDGE   (INNER_EDGE | OUTER_EDGE)

struct labelPoint
{
	int x;
	int y;
	int label;
};

struct Tuple
{
	CvScalar f;
	CvScalar b;
	double   sigmaf;
	double   sigmab;

	int flag;

};

struct Ftuple
{
	CvScalar f;
	CvScalar b;
	double   alphar;
	double   confidence;
};

IplImage *fnGenerate_Trimap(IplImage *mask, const uchar cu8mVal, const int s32EdgeR_inner, const int s32EdgeR_outer, const int edgeFlag);
IplImage *fnGenerate_Trimap(IplImage *mask, const uchar cu8mVal, const int s32EdgeR, const int edgeFlag);

/*�������϶�cvPoint�� xΪ�У�yΪ�У����ܴ��󣬵��Գ�����û��Ӱ��*/
class SharedMatting
{
public:
	SharedMatting();
	~SharedMatting();

    void setImage(IplImage *image);
    void setTrimap(IplImage *trimap);
	void expandKnown();
	void sample(CvPoint p, vector<CvPoint>& f, vector<CvPoint>& b);
	void gathering();
	void refineSample();
	void localSmooth();
	void solveAlpha();
	void Sample(std::vector<vector<CvPoint> > &F, std::vector<vector<CvPoint> > &B);
	IplImage * getMatte();
	void release();
    
    IplImage *Run(IplImage *image, IplImage *mask, const int radius_inner=3, const int radius_outer=3, const int edgeFlag = BOTH_INNER_OUTER_EDGE);
    IplImage *Run(IplImage *image, IplImage *mask, const int radius = 3, const int edgeFlag = BOTH_INNER_OUTER_EDGE);

	double mP(int i, int j, CvScalar f, CvScalar b);
	double nP(int i, int j, CvScalar f, CvScalar b);
	double eP(int i1, int j1, int i2, int j2);
	double pfP(CvPoint p, vector<CvPoint>& f, vector<CvPoint>& b);
	double aP(int i, int j, double pf, CvScalar f, CvScalar b);
	double gP(CvPoint p, CvPoint fp, CvPoint bp, double pf);
	double gP(CvPoint p, CvPoint fp, CvPoint bp, double dpf, double pf);
	double dP(CvPoint s, CvPoint d);
	double sigma2(CvPoint p);
	double distanceColor2(CvScalar cs1, CvScalar cs2);
	double comalpha(CvScalar c, CvScalar f, CvScalar b);

    IplImage *graphcuttest(IplImage *src, IplImage *mask, int r);

private:
	IplImage * pImg;
	IplImage * trimap;
	IplImage * matte;

	vector<CvPoint> uT;
	vector<struct Tuple> tuples;
	vector<struct Ftuple> ftuples;

	int height;
	int width;
	int kI;
	int kG;
	int ** unknownIndex;//Unknown��������Ϣ��
	int ** tri;
	int ** alpha;
	double kC;

	int step;
	int channels;
	uchar* data;

};



#endif
