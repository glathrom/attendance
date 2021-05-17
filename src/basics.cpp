#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/cvdef.h>
#include <opencv2/core/version.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


void greyOut(char *path){

    cv::Mat img = cv::imread(path);
    cv::Mat imgGrey;

    cv::cvtColor(img, imgGrey, cv::COLOR_BGR2GRAY);

    cv::imshow("image", imgGrey);
    cv::imshow("original", img);
    cv::waitKey(0);

}

void myBlur(char *path){
    cv::Mat img = cv::imread(path);
    cv::Mat blurred;

    cv::GaussianBlur(img, blurred, cv::Size(31,31), 70, 50);

    cv::imshow("image", img);
    cv::imshow("image2", blurred);
    cv::waitKey(0);
}


int main(int argc, char **argv){

    if( argc < 2 ){
        std::cout << "need path parameter" << std::endl;
        return 1;
    }

    //greyOut(argv[1]);
    myBlur(argv[1]);


    return 0;
}
