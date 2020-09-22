/*
 * File     : labo01.cpp
 * Author   : Pierre BRESSY
 * Company  : HEIG-VD
 * Created  : Thu Sep 20 23:43:56 2012
 * Purpose  : VIN / Labo01 
 
 |   Date   | By  | Description of changes in main.cpp
 +----------+-----+-----------------------------------------------------------+
 |          |     |
 
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#define WINDOW_NAME "Photo"
#define INPUT_FILENAME "../data/photo.jpg"
#define OUTPUT_FILENAME "../data/photoModifiee.jpg"

#define IMG_WIDTH 28
#define IMG_HEIGHT 28


int main()
{
	Mat image;
	Scalar whiteColor(255,255,255);
	Scalar greenColor(0,255,0);
	Point tlCorner(510,280);
	Point brCorner(670,390);

	double t = (double)getTickCount();

	image=imread(INPUT_FILENAME);
	if(image.data==NULL) {
		printf("Unable to open input file "INPUT_FILENAME"\n");
		return -1;
	}

	printf("Image dimensions : %d rows x %d cols - type : %d (%d) - channels:%d\n",image.rows, image.cols,image.type(),CV_8UC3,image.channels());

	memset(image.data+(image.rows-20)*image.channels()*image.cols,0x30,image.cols*image.channels()*20);
	putText(image, "Appuyez sur un touche pour terminer.", Point(0, image.rows-5), CV_FONT_HERSHEY_PLAIN, 1, whiteColor );
	rectangle(image, tlCorner, brCorner, greenColor, 4, 8,0);

	imwrite(OUTPUT_FILENAME,image);

	imshow( WINDOW_NAME, image );

	t = ((double)getTickCount() - t)/getTickFrequency();
	printf("Processing time : %.3lf[s]\n", t );

	cvWaitKey(0);

	// Free the resources.
	cvDestroyWindow(WINDOW_NAME);
        
	return 0;
}
