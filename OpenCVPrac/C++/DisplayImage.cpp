#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

Mat getImage() {
   // create image
   cv::Mat ima(500,500,CV_8U,50);
   // return it
   return ima;
}

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
    
    Mat image1(240, 320, CV_8U, 100);
    imshow("Image", image1);

    waitKey(0);

    image1.create(200,200,CV_8U);
	image1 = 200;

    imshow("Image", image1);
    waitKey(0);

    Mat image2(240,320,CV_8UC3,cv::Scalar(0,0,255));

    imshow("Image", image2);
    waitKey(0);

    Mat image3 = imread("mist.jpg");
    Mat image4(image3);
    image1 = image3;

    image3.copyTo(image2);
    Mat image5 = image3.clone();

    flip(image3, image3, 1);

    imshow("Image 3", image3);
    imshow("Image 1", image1);
    imshow("Image 2", image2);
    imshow("Image 4", image4);
    imshow("Image 5", image5);

    waitKey(0);

    Mat gray = getImage();

    imshow("Image", gray);
    waitKey(0);

    image1 = imread("mist.jpg", IMREAD_GRAYSCALE);
    image1.convertTo(image2, CV_32F, 1/255.0, 0.0);
    imshow("Image", image2);

    Matx33d matrix(3.0, 2.0, 1.0,
		            2.0, 1.0, 3.0,
		            1.0, 2.0, 3.0);

    Matx31d vector(5.0, 1.0, 3.0);
    Matx31d result = matrix * vector;

    cout << result;

    waitKey(0);

    return 0;
}