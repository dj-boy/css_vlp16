// util.h
#ifndef CSS_H
#define CSS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include <pcl/common/common_headers.h>
#include <pcl/common/distances.h>

#include "util.h"

#define SIGMA_SIZE 7
#define WIDTH_SIZE 7

using namespace std;
using namespace pcl;
using namespace Eigen;

typedef struct curvatureTriplet
{
	int index;
	float sIndex;
	float curvature;
}CurvatureTriplet;

bool compareCurvatureTriplet (CurvatureTriplet i, CurvatureTriplet j);

typedef struct curvatureCounter
{
	float index;
	int counter;
	float curvature;
}CurvatureCounter;

struct CompareSet {
  bool operator() (const float& lhs, const float& rhs) const
  {
  	return lhs<rhs;
  }
};

bool compareCurvatureCounter (CurvatureCounter i, CurvatureCounter j);

void printKeypoints(vector<CurvatureTriplet> keypoints);
int findByThreshold(CurvatureTriplet a, vector<CurvatureTriplet> vec, float threshold);
int findCurvatureTriplet (vector<CurvatureTriplet> vec, CurvatureTriplet c);
void parametrizeCurve(PointCloud<PointXYZ> in, vector<float> &s);
void getCurvatureExtrema(vector<float> curvature, vector<float> s, vector<CurvatureTriplet>& keypoints);
void computeCurvature(PointCloud<PointXYZ> in, int kernelWidth, float sigma, vector<float>& curvature, vector<float>& s, vector<CurvatureTriplet>& keypoints);
void computeScaleSpace(PointCloud<PointXYZ> in, vector<CurvatureTriplet> keypoints[SIGMA_SIZE][WIDTH_SIZE], vector<CurvatureTriplet>& keypointsFinestScale);
void getKeypointsAtFinestScale(vector<CurvatureTriplet> keypointsFinestScale, vector<CurvatureTriplet> keypointsAtLastWidth, vector<CurvatureTriplet>& selectedKeypointsFinestScale);
void getFinalKeypoints(PointCloud<PointXYZ> in, vector<CurvatureTriplet> selectedKeypointsFinestScale, vector<CurvatureTriplet> keypoints[SIGMA_SIZE][WIDTH_SIZE],
					   PointCloud<PointXYZ>& keypointsCloud, vector<CurvatureCounter>& curvatureCounter);

#endif
