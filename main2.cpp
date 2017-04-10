//This Program receives an input image and displays it
// in its RGB, HSV and HSL form to compare colorspace
//clarity

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <sstream>

#include "Camera.hpp"

using namespace cv;

int main( int argc, char** argv )
{
    Mat image, imageHLS, imageHSV;

    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(!image.data )                              // Check for invalid input
    {
        std::cout << "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Loaded Image", WINDOW_NORMAL);// Create a window for display.
    imshow("Loaded Image", image);

    cvtColor(image, imageHSV, CV_BGR2HSV);
    namedWindow( "Loaded Image: HSV", WINDOW_NORMAL);// Create a window for display.
    imshow("Loaded Image: HSV", imageHSV);

    cvtColor(image, imageHLS, CV_BGR2HLS);
    namedWindow("Loaded Image: HLS", WINDOW_NORMAL);// Create a window for display.
    imshow("Loaded Image: HLS", imageHLS);

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
