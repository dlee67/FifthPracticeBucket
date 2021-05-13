#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    Mat image;
    image = imread("mist.jpg");
    resize(image, image, Size(), 0.75, 0.75);

    if (image.empty()) {
        return 0;
    }

    Mat smallLogo = imread("logo.png");
    // https://docs.opencv.org/3.4/d2/d44/classcv_1_1Rect__.html#a5a41149f4b012b9f323b5913454375a1
    //          x and y placements                                    the size of the rectangle.
    Rect roiBox(image.cols-smallLogo.cols, image.rows-smallLogo.rows, smallLogo.cols, smallLogo.rows);

    // 04/28/21 Gotta figure this dash operator.
    // 04/29/21 I am an idiot, that's a minus sign.
    Mat regionOfInterest(image, roiBox);

    // https://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html#a626fe5f96d02525e2604d2ad46dd574f
    // Can use copyTo() to mask something over.
    smallLogo.copyTo(regionOfInterest);

    imshow("Image", image);

    waitKey(0);

    return 0;
}