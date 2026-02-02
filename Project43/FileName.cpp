
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
    cv::VideoCapture cap("1.mkv");
    cv::VideoWriter writer;

    int fps = cap.get(cv::CAP_PROP_FPS);
    cv::Size size(cap.get(cv::CAP_PROP_FRAME_WIDTH),
        cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    writer.open("output.mp4",
        cv::VideoWriter::fourcc('H', '2', '6', '4'),
        fps, size);

    cv::Mat frame;
    while (cap.read(frame)) {
        // 处理帧
        cv::cvtColor(frame, frame, cv::COLOR_BGRA2RGBA);
        writer.write(frame);
    }

    cap.release();
    writer.release();
	return 0;
}
