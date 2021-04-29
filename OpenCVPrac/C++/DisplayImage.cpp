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

    // Gotta figure this dash operator.
    Mat regionOfInterest(image, Rect(
        image.cols-smallLogo.cols,
        image.rows-smallLogo.rows,
        smallLogo.cols,
        smallLogo.rows
    ));

    logo.copyTo(regionOfInterest);

    imshow("Image", image);

    waitKey(0);

    return 0;
}