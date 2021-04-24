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

    circle(image, Point(155, 100), 65, 0, 3);
    putText(image, "Mist", Point(40, 200), FONT_HERSHEY_PLAIN, 2.0, 255, 2);

    imshow("Original Image", image);
    // https://docs.opencv.org/3.4/d7/dfc/group__highgui.html#ga89e7806b0a616f6f1d502bd8c183ad3e
    setMouseCallback("Original Image", onMouse, reinterpret_cast<void*>(&image));    

    // These two must come before the imshow.
    // circle(image, Point(155, 100), 65, 0, 3);
    // putText(image, "Mist", Point(40, 200), FONT_HERSHEY_PLAIN, 2.0, 255, 2);

    waitKey(0);
    
    return 0;
}