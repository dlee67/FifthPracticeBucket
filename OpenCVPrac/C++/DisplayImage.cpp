#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void onMouse( int event, int x, int y, int flags, void* param)  { 
 
    Mat *im= reinterpret_cast<Mat*>(param); 
    switch (event) {  // dispatch the event 
        case EVENT_LBUTTONDOWN: // left mouse button down event 
        // display pixel value at (x,y) 
        cout << "at (" << x << "," << y << ") value is: " 
                << static_cast<int>(im->at<uchar>(Point(x,y))) << endl; 
        break; 
    } 
} 

int main(int argc, char** argv )
{
    Mat image;
    image = imread("mist.jpg", IMREAD_GRAYSCALE);

    if (image.empty()) {
        return 0;
    }

    imshow("Original Image", image);
    setMouseCallback("Original Image", onMouse, reinterpret_cast<void*>(&image));    

    waitKey(0);
    
    return 0;
}