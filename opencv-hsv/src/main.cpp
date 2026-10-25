#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;

int main() {
    cv::Mat image = cv::imread("pic.png");
    if (image.empty()) {
        cout << "Read error" << endl;
        return 1;
    }
    cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
    vector<cv::Mat> channels;
    cv::split(image, channels);
    cv::imshow("H", channels.at(0));
    cv::imshow("S", channels.at(1));
    cv::imshow("V", channels.at(2));
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}