#include <iostream>
#include <string>
#include <sstream>

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    Mat color = imread("./yisunshinportrait.jpg");
    // https://github.com/NVIDIA/DALI/issues/443
    // The below doesn't work anymore.
    // Mat gray = imread("./somepicture.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    Mat gray = imread("./yisunshinportrait.jpg", cv::IMREAD_GRAYSCALE);

    if (!color.data) {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    imwrite("./yisunshinportraitGray.jpg", gray);

    int myRow = color.cols - 1;
    int myCol = color.rows - 1;
    Vec3b pixel = color.at<Vec3b>(myRow, myCol);
    cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl; 

    // show images 
    imshow("BGR", color); 
    imshow("gray", gray); 
    // wait for any key press 
    waitKey(0);

    return 0;
}