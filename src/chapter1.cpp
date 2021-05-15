#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/cvdef.h>
#include <opencv2/core/version.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


void displayImage(){

    std::string path = "/home/grant/Projects/attendance/data/whiteboard.jpg";
    
    std::cout << "Hello, World!" << std::endl;

    cv::Mat x = cv::imread(path, cv::IMREAD_COLOR);

    cv::imshow("image", x);

    cv::waitKey(0);

}

void displayVideo(){

    std::string path = "/home/grant/Projects/attendance/data/euclid-proposition-35.mp4";
    cv::VideoCapture cap(path);
    cv::Mat img;

    while(true){
        cap.read(img);

        cv::imshow("image", img);
        cv::waitKey(30);
    }

}

void displayWebCam(){
    
    cv::VideoCapture cap(0);
    cv::Mat img;

    while(true){
        cap.read(img);

        cv::imshow("image", img);
        cv::waitKey(30);
    }
}


int main(){

    //displayImage();
    //displayVideo();
    displayWebCam();

    return 0;
}
