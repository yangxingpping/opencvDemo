
#include "spdlog/spdlog.h"
#include "fmt/format.h"
#include "tao/pegtl.hpp"
#include "absl/hash/hash.h"
#include "opencv4/opencv2/opencv.hpp"

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
    namedWindow("hehe", WINDOW_NORMAL);
    resizeWindow("hehe", 800, 600);
    imshow("hehe", edges);
    waitKey(0);
	SPDLOG_INFO("hello,world {}", fmt::format("{} next", 0.1));
	return 0;
}
