#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/cvdef.h>
#include <opencv2/core/version.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>




int main(int argc, char **argv){
    
    char cascadefile[] = "../data/haarcascades/haarcascade_frontalface_default.xml";
    cv::CascadeClassifier faceCascade;
    cv::Mat grey;
    cv::Size msize(0,0);
    std::vector<cv::Rect> faces;

    faceCascade.load(cascadefile);

    std::cout << argv[0] << std::endl;

    if( argc == 1 ){

        cv::Mat img;

        cv::VideoCapture cap(0);

        while(true){
            cap.read(img);

            cv::cvtColor(img, grey, cv::COLOR_BGR2GRAY);

            faceCascade.detectMultiScale(grey, faces, 1.1, 3, 0, msize, msize); 

            std::cout << "Number of Faces Found: " << faces.size() << std::endl;

            for( std::vector<cv::Rect>::iterator  face = faces.begin(); face < faces.end(); face++ ){
                std::cout << "Inside Loop" << std::endl;
                cv::Point upperleft(face->x, face->y);
                cv::Point lowerright(face->x+face->width, face->y+face->height);
                cv::rectangle(img, upperleft, lowerright, cv::Scalar(255,0,255),3);
            }
            faces.clear();

            cv::imshow("image", img);
            cv::waitKey(5);
        }

    } else {
        cv::Mat img = cv::imread(argv[1], cv::IMREAD_COLOR);
        cv::cvtColor(img, grey, cv::COLOR_BGR2GRAY);

        faceCascade.detectMultiScale(grey, faces, 1.1, 3, 0, msize, msize); 

        std::cout << "Number of Faces Found: " << faces.size() << std::endl;

        for( std::vector<cv::Rect>::iterator  face = faces.begin(); face < faces.end(); face++ ){
            cv::Point upperleft(face->x, face->y);
            cv::Point lowerright(face->x+face->width, face->y+face->height);
            cv::rectangle(img, upperleft, lowerright, cv::Scalar(255,0,255),3);
        }
        faces.clear();

        cv::imshow("image", img);
        cv::waitKey(0);
    }
    
    return 0;
}
