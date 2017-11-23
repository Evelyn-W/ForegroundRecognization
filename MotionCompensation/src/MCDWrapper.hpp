
#ifndef	_MCDWRAPPER_H_
#define	_MCDWRAPPER_H_

/************************************************************************/
/* Basic Includes                                                       */
/************************************************************************/
#include	<iostream>
#include	<cstdlib>
#include	<cstring>
#include	<vector>
#include	<algorithm>
/************************************************************************/
/* Includes for the OpenCV                                              */
/************************************************************************/
#include	<cv.h>
#include	<highgui.h>
#include	<opencv2/features2d/features2d.hpp>

// Inlcludes for this wrapper
#include "KLTWrapper.hpp"
#include "prob_model.hpp"

using namespace std;
using namespace cv;

class MCDWrapper {

/************************************************************************/
/*  Internal Variables					                                */
/************************************************************************/
 public:

	int frm_cnt;

	IplImage *detect_img;

	/* Note that the variable names are legacy */
	KLTWrapper m_LucasKanade;
	IplImage *imgIpl;
	IplImage *imgIplTemp;
	IplImage *imgGray;
	IplImage *imgGrayPrev;

	IplImage *imgGaussLarge;
	IplImage *imgGaussSmall;
	IplImage *imgDOG;

	IplImage *debugCopy;
	IplImage *debugDisp;

	ProbModel BGModel;

/************************************************************************/
/*  Methods								                                */
/************************************************************************/
 public:

	 MCDWrapper();
	~MCDWrapper();

	void Init(IplImage * in_imgIpl);
	void Run();

};

#endif				//_MCDWRAPPER_H_
