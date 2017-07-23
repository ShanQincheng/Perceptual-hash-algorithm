#include "stdafx.h"

unsigned long long int GenerateTextureFingerprint(Mat texturePic)
{
	int textureCols = texturePic.cols; // the cols number of texture picture
	int textureRows = texturePic.rows; // the rows number of texture picture
	Mat texturePicResize, texturePicResizeGray;

	texturePicResize.create(8, 8, CV_8UC3);
	resize(texturePic, texturePicResize, texturePicResize.size(), 0, 0, CV_INTER_LINEAR); // resize to 8 * 8 picture
	cvtColor(texturePicResize, texturePicResizeGray, CV_BGR2GRAY, 0);  // colored currentPatchResize patch was transferred to gray patch

	int pixelsValue = 0, averagePixelsValue = 0;;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pixelsValue += texturePicResizeGray.at<uchar>(i, j);
		}
	}	
	averagePixelsValue = pixelsValue / 64;
	
	unsigned long long int fingerprint = 0;
	for (int y = 0; y < 8; y++)
	{
		for (int z = 0; z < 8; z++)
		{
			if (texturePicResizeGray.at<uchar>(y, z) > averagePixelsValue)
				fingerprint = fingerprint * 2 + 1;
			else
				fingerprint = fingerprint * 2 + 0;
		}
	}

	return fingerprint;
}


void DetermineSimilarPicture(Mat pic1, Mat pic2)
{
	unsigned long long int fingerprint1 = GenerateTextureFingerprint(pic1);
	unsigned long long int fingerprint2 = GenerateTextureFingerprint(pic2);

	if (hamming(fingerprint1, fingerprint2) >= 0 && hamming(fingerprint1, fingerprint2) <= 5)
	{
		printf("Extremely similar\n");
	}
	else if (hamming(fingerprint1, fingerprint2) >= 0 && hamming(fingerprint1, fingerprint2) <= 10) {
		printf("Similar\n");
	}
	else {
		printf("Not similar\n");
	}

	
	return;
}

int hamming(unsigned long long int h1, unsigned long long int h2)
{
	int h = 0;
	unsigned long long int d = h1 ^ h2;
	while (d)
	{
		h++;
		d &= d - 1;
	}

	return h;
}