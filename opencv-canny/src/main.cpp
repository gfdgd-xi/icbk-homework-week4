#include <opencv2/opencv.hpp>
using namespace std;

int main() {
    cv::Mat image = cv::imread("pic.png");
    cv::Mat gray;
    cv::Mat output;
    if (image.empty()) {
        cout << "Read error" << endl;
        return 1;
    }
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, output, 100, 200);
    cv::imwrite("new.png", output);
    cv::imshow("Image", output);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}