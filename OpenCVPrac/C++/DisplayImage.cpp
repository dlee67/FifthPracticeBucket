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

void combineImages(Mat image1, Mat image2) {
	Mat result;
	addWeighted(image1, 0.7, image2, 0.9, 0.0, result);
	namedWindow("result");
	imshow("result", result);
	
	waitKey(0);

	// result = 0.7 * image1 + 0.9 * image2;
	// namedWindow("result with operators");
	// imshow("result with operators",result);

	// waitKey(0);

	// cv::IMREAD_GRAYSCALE = 0
	// In order to merge images, all colors must be removed.
	image2 = imread("rain.jpg", 0);
	resize(image2, image2, image1.size());

	// https://www.pyimagesearch.com/2021/01/23/splitting-and-merging-channels-with-opencv/
	// The above article explains split and merge in more depth.
	vector<Mat> planes;
	split(image1, planes);
	// Channles in OpenCV aren't arranged in RGB, but in BGR.
	// Meaning, planes[2] would have the red channel, where we get a seg-fault if we try to go beyond that.
	planes[0] += image2; // Remember, this works because all images are represented in mathematical matrix.
	merge(planes, result);

	namedWindow("Result on blue channel");
	imshow("Result on blue channel",result);

	waitKey(0);
}

// https://www.khanacademy.org/math/statistics-probability/displaying-describing-data/quantitative-data-graphs/a/histograms-review#:~:text=A%20histogram%20displays%20numerical%20data,%22%2C%20or%20%22buckets%22.
// https://hub.packtpub.com/basics-image-histograms-opencv/#:~:text=The%20data%2C%20in%20this%20case,counts%20along%20the%20y%20axis.
void histogramPrac(Mat src) {
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	int histSize = 256;
	float range[] = {0, 256};
	const float* histRange = { range };

    Mat b_hist;
	// https://docs.opencv.org/3.4/d6/dc7/group__imgproc__hist.html#ga4b2b5fd75503ff9e6844cc4dcdaed35d
	// histSize dictates the number of histogram bins to use for each channel.
	// histRange is literally the range, the maximum y-axis. 
    calcHist( &bgr_planes[0], 1, 0, Mat(), 
		b_hist, // The output. 
		1, &histSize, &histRange);

    int hist_w = 512; 
	int hist_h = 400;
	// https://docs.opencv.org/3.4/db/de0/group__core__utils.html#ga085eca238176984a0b72df2818598d85
    int bin_w = cvRound( (double) hist_w/histSize ); // Literally, cvRound "floors" the value.
	
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
	// This I don't get.
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    
	for( int i = 1; i < histSize; i++ )
    {
		// https://docs.opencv.org/master/d6/d6e/group__imgproc__draw.html#ga7078a9fae8c7e7d13d24dac2520ae4a2
        line(histImage, 
			Point(bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1))), // First point of the line segment.
            Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), // The second.
            Scalar(255, 0, 0));
    }

    imshow("Source image", src );
    imshow("calcHist Demo", histImage );
    waitKey();
}

int main()
{
    // https://docs.opencv.org/3.4/d8/d6a/group__imgcodecs__flags.html#gga61d9b0126a3e57d9277ac48327799c80af660544735200cbe942eea09232eb822
    // IMREAD_COLOR = 1
    Mat mist = imread("mist.jpg");
	Mat rain = imread("rain.jpg");	
	
	// addWeighted won't work unless two images are the same size.
	Mat resizedRain;
	resize(rain, resizedRain, mist.size());

    // salt(mist, 3000);
	// colorReduce(mist, 64);

    // namedWindow("mist");
    // imshow("mist", mist);
	// combineImages(mist, resizedRain);
	histogramPrac(mist);

    return 0;
}