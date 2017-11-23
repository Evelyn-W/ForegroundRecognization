
#pragma once

#include <cv.h>

#define GRID_SIZE_W (32)
#define GRID_SIZE_H (24)

typedef unsigned char BYTE;

class KLTWrapper {
 private:
	IplImage * eig;
	IplImage *temp;
	IplImage *maskimg;

	// For LK
	IplImage *image;
	IplImage *imgPrevGray, *pyramid, *prev_pyramid, *swap_temp;
	int win_size;
	int MAX_COUNT;
	CvPoint2D32f *points[2], *swap_points;
	char *status;
	int count;
	int flags;

	// For Homography Matrix
	double matH[9];

 private:
	void SwapData(IplImage * imgGray);
	void MakeHomoGraphy(int *pnMatch, int nCnt);

 public:
	 KLTWrapper(void);
	~KLTWrapper(void);

	void Init(IplImage * imgGray);
	void InitFeatures(IplImage * imgGray);
	void RunTrack(IplImage * imgGray, IplImage * prevGray);	// with MakeHomography
	void GetHomography(double *pmatH);
};
