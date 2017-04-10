//This program streams webcam video and saves snapshot
//images on keystroke for gathering training/test data

#include <opencv2/opencv.hpp>
#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <sstream>

#include "Camera.hpp"

using namespace cv;

int main() {

  // Initialise settings for ncurses input capture lib
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

  Camera C920_Cam;  // Camera Object

  VideoCapture stream1(1);   //0 is the id of video device.0 if you have only one camera.

  //Set lower resolution to ensure fast function
  stream1.set(CV_CAP_PROP_FRAME_WIDTH, 160);
  stream1.set(CV_CAP_PROP_FRAME_HEIGHT, 120);

  if (!stream1.isOpened()) { //check if video device has been initialised
    std::cout << "cannot open camera" << std::endl;
  }

  //unconditional loop
  while (true) {
    // Read next frame of webcam and display
    Mat cameraFrame;
    stream1.read(cameraFrame);
    imshow("cam", cameraFrame);

    // Save frame to CapturedImages on 's' Keystroke
    if (getch() == 's') {
      C920_Cam.SaveImage(cameraFrame);
    }

    if (waitKey(30) >= 0) {
      break;
    }
  }

  endwin(); // Restore terminal after ncurses activity

  return 0;
}
