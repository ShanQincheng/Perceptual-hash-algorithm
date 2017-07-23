// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

unsigned long long int GenerateTextureFingerprint(Mat texturePic);
void DetermineSimilarPicture(Mat pic1, Mat pic2);
int hamming(unsigned long long int h1, unsigned long long int h2);

// TODO: reference additional headers your program requires here
