#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    namedWindow("Image");

    Mat image = imread("mist.jpg");
    Mat smallLogo = imread("logo.png");
    Mat mask(smallLogo);

    if (image.empty() || smallLogo.empty()) {
        return 0;
    }
    
    resize(image, image, Size(), 0.75, 0.75);

    // 04/28/21 Gotta figure this dash operator.
    // 04/29/21 I am an idiot, that's a minus sign.
    Mat regionOfInterest(image, Rect(
        image.cols-smallLogo.cols,
        image.rows-smallLogo.rows,
        smallLogo.cols,
        smallLogo.rows
    ));
    smallLogo.copyTo(regionOfInterest, mask);

    imshow("Image", image);

    waitKey(0);

    return 0;
}