
#include "spdlog/spdlog.h"
#include "fmt/format.h"
#include "tao/pegtl.hpp"
#include "absl/hash/hash.h"
#include "opencv4/opencv2/opencv.hpp"
#include <vector>

using std::vector;
using namespace cv;

int main(void)
{
    Mat image = imread("1.jpg");
    Mat gray;
    Mat edges;
    if (image.empty()) 
    {
        SPDLOG_INFO("import file failed");
        return -1;
    }
	cvtColor(image, gray, COLOR_BGR2GRAY);
	Canny(gray, edges, 100, 200);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(edges, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    Mat result = image.clone();
    drawContours(result, contours, -1, Scalar(0, 255, 0), 2);
    namedWindow("hehe", WINDOW_NORMAL);
    resizeWindow("hehe", 800, 600);
    imshow("hehe", result);
    waitKey(0);
	SPDLOG_INFO("hello,world {}", fmt::format("{} next", 0.1));
	return 0;
}
