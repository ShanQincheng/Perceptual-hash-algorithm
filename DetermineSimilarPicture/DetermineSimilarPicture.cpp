// DetermineSimilarPicture.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char** argv)
{

	string pic1Name, pic2Name;
	
	for (int i = 0; i < 4; i++)
	{
		if (strcmp("-p1", argv[i + 1]) == 0)
		{
			pic1Name = argv[i + 2];

			i++;
		}
		else if (strcmp("-p2", argv[i + 1]) == 0)
		{
			pic2Name = argv[i + 2];
			i++;
		}
		else {
			exit(0);
		}
	}
	/*
	pic1Name = "Lily_Aldrin.jpg";
	pic2Name = "AlysonHannigan.jpg";
	*/

	Mat pic1, pic2;
	pic1 = imread(pic1Name);
	pic2 = imread(pic2Name);

	DetermineSimilarPicture(pic1, pic2);

	
	waitKey(0);
	
	return 0;
}

