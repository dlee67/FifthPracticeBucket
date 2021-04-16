#include <iostream>
#include <string>
#include <sstream>

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

// Materials from "Building Computer Vision Projects with OpenCV 4 and C++," published by Packt.
int main(int argc, char** argv )
{
    // https://docs.opencv.org/4.1.1/d8/dfe/classcv_1_1VideoCapture.html#a5d5f5dacb77bbebdcbfb341e3d4355c1
    // https://answers.opencv.org/question/190710/how-do-i-choose-which-camera-i-am-accessing/
    // There's actually technical reason why we passs 0 in the parameter.
    VideoCapture cap(0);
    
    if(!cap.isOpened())
    {
        cerr << "Unable to open the webcam. Exiting!" << endl;
        return -1;
    }
    
    // https://docs.opencv.org/3.4/d6/d6d/tutorial_mat_the_basic_image_container.html
    Mat frame, hsvImage, mask, outputImage;
    char ch;
    
    // Image size scaling factor for the input frames from the webcam
    float scalingFactor = 0.75;
    
    // Iterate until the user presses the Esc key
    while(true)
    {
        // Initialize the output image before each iteration
        outputImage = Scalar(0,0,0);
        
        // Capture the current frame
        cap >> frame;
    
        // Check if 'frame' is empty
        if(frame.empty())
            break;
        
        // Resize the frame
        resize(frame, frame, Size(), scalingFactor, scalingFactor, INTER_AREA);
    
        // Convert to HSV colorspace
        cvtColor(frame, hsvImage, COLOR_BGR2HSV);
        
        // Define the range of "blue" color in HSV colorspace
        Scalar lowerLimit = Scalar(60,100,100);
        Scalar upperLimit = Scalar(180,255,255);
        
        // Threshold the HSV image to get only blue color
        inRange(hsvImage, lowerLimit, upperLimit, mask);
        
        // Compute bitwise-AND of input image and mask
        bitwise_and(frame, frame, outputImage, mask=mask);
        
        // Run median filter on the output to smoothen it
        medianBlur(outputImage, outputImage, 5);
        
        // Display the input and output image
        imshow("Input", frame);
        imshow("Output", outputImage);
        
        // Get the keyboard input and check if it's 'Esc'
        // 30 -> wait for 30 ms
        // 27 -> ASCII value of 'ESC' key
        ch = waitKey(30);
        if (ch == 27) {
            break;
        }
    }
    return 0;
}