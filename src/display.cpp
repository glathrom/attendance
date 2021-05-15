#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/cvdef.h>
#include <opencv2/core/version.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


void displayImage(char *path){

    std::cout << "Hello, World!" << std::endl;

    cv::Mat x = cv::imread(path, cv::IMREAD_COLOR);

    cv::imshow("image", x);

    cv::waitKey(0);

}

void displayVideo(char *path){
    
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


int main(int argc, char **argv){

    if( argc < 2 ){
        std::cout << "displaying webcam" << std::endl;
        displayWebCam();        
    } else {
        displayImage(argv[1]);
        //displayVideo(argv[1]);
    }


    return 0;
}
