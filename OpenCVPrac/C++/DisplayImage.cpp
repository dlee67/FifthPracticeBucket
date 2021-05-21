#include <iostream>
#include <random>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void salt(Mat image, int n) {
	// http://www.cplusplus.com/reference/random/uniform_int_distribution/uniform_int_distribution/
	// This works because images of OpenCV are treated like a matrix.
    default_random_engine generator;
	uniform_int_distribution<int> randomRow(0, image.rows - 1);
	uniform_int_distribution<int> randomCol(0, image.cols - 1);

	int i,j;
	for (int k=0; k<n; k++) {
		// random image coordinate
		i = randomCol(generator);
		j = randomRow(generator); 
		
		// Assumes the image is colored (CV_8UC3).
		// Unlike Java or Python, type must be know for everything in C++.
		//R
		image.at<Vec3b>(j,i)[0]= 255;
		//G 
		image.at<Vec3b>(j,i)[1]= 255;
		//B
		image.at<Vec3b>(j,i)[2]= 255;
		// https://stackoverflow.com/questions/32190494/what-is-the-vec3b-type/32197304
		// When it comes to interacting with colored images in OpenCV,
		// Vec3b appears a lot because that's how RGB is interacted with. 
	}
}

void colorReduce(Mat image, int div=64) {
      int nl = image.rows; // number of lines
	  // The second answer.
	  // https://answers.opencv.org/question/7585/meaning-of-channels/#:~:text=2%20answers&text=Channels%20are%20different%20dimensions%20of,value%20for%20a%20single%20pixel.
	  // total number of pixels per line.
	  // https://stackoverflow.com/questions/28324125/opencv-number-of-pixels-vs-rowscolumns
      // The above is the reason why image.col in itself isn't enough to grab all the pixels.
	  int nc = image.cols * image.channels();
      for (int j=0; j<nl; j++) {
		  // uchar is a data type specific to OpenCV.
          uchar* data= image.ptr<uchar>(j); // Points at the beginning of a row.
          for (int i=0; i<nc; i++) {
            data[i]= data[i]/div * div + div/2; // I mean, we are just essentially changing the colors here.
												// THe book states it as, "reducing the color."
          }
      }
}

void combineImages(Mat imageOne, Mat imageTwo) {
	Mat result;
	addWeighted(imageOne, 0.7, imageTwo, 0.9, 0.0, result);
	namedWindow("result");
	imshow("result", result);
}

int main()
{
    // https://docs.opencv.org/3.4/d8/d6a/group__imgcodecs__flags.html#gga61d9b0126a3e57d9277ac48327799c80af660544735200cbe942eea09232eb822
    // IMREAD_COLOR = 1
    Mat mist = imread("mist.jpg");
	Mat rain = imread("rain.jpg");	
	
	Mat resizedRain;
	resize(rain, resizedRain, mist.size());

    // salt(mist, 3000);
	// colorReduce(mist, 64);

    // namedWindow("mist");
    // imshow("mist", mist);
	combineImages(mist, resizedRain);

    waitKey(0);

    return 0;
}