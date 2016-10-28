#include <iostream>
#include <unistd.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

int main(int argc, char** argv)
{
    if(argc!=2){
        std::cout<<"should be:\n"<<argv[0]<<" <output filename>\n";
        return 0;
    }

    cv::VideoCapture cap;
    cap.open(0);

    //check cam opened
    if( !cap.isOpened() )
    {
        std::cerr << "***Could not initialize capturing...***\n";
        std::cerr << "Current parameter's value: \n";
        return -1;
    }

    cv::Mat frame;
    while(1){
        cap >> frame;

        //check cam image
        if(frame.empty()){
            std::cerr<<"frame is empty"<<std::endl;
            break;
        }

        //wait for 5 seconds and then write to fileA
        sleep(5);
        std::cout<<"5 seconds, out"<<std::endl;
        cv::imwrite(argv[1],frame);
        break;
    }

    return 0;
}
