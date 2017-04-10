#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>

using namespace cv;

class Camera {
private:
  int SnapIndex;
public:
  Camera();
  ~Camera();
  void SaveImage(Mat frame);
};

#endif
