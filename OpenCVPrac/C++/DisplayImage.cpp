#include <iostream>
#include <random>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void salt(Mat image, int n) {
    default_random_engine generator;
	uniform_int_distribution<int> randomRow(0, image.rows - 1);
	uniform_int_distribution<int> randomCol(0, image.cols - 1);

	int i,j;
	for (int k=0; k<n; k++) {
		// random image coordinate
		i= randomCol(generator);
		j= randomRow(generator);
		if (image.type() == CV_8UC1) { // gray-level image
			// single-channel 8-bit image
			image.at<uchar>(j,i)= 255; 
		} else if (image.type() == CV_8UC3) { // color image
			// 3-channel image
			image.at<Vec3b>(j,i)[0]= 255; 
			image.at<Vec3b>(j,i)[1]= 255; 
			image.at<Vec3b>(j,i)[2]= 255; 
			// or simply:
			// image.at<cv::Vec3b>(j, i) = cv::Vec3b(255, 255, 255);
		}
	}
}

int main(int argc, char** argv )
{
    // https://docs.opencv.org/3.4/d8/d6a/group__imgcodecs__flags.html#gga61d9b0126a3e57d9277ac48327799c80af660544735200cbe942eea09232eb822
    // IMREAD_COLOR = 1
    Mat image = imread("mist.jpg", 1);
    if (image.empty()) {
        return 0;
    }

    salt(image, 3000);

    namedWindow("Image");
    imshow("Image", image);

    waitKey(0);

    return 0;
}