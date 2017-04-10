#include "Camera.hpp"

Camera::Camera(){
  SnapIndex = 0;
}

Camera::~Camera(){

}

void Camera::SaveImage(Mat frame){
    std::ostringstream name;
    name << "CapturedImages/Image_" << SnapIndex << ".png";
    cv::imwrite(name.str(), frame);
    std::cout << "Image_" << SnapIndex << ".png Saved" << std::endl;
    SnapIndex++;
}
