#include <opencv2/opencv.hpp>
using namespace std;

int main() {
    cv::Mat image = cv::imread("pic.png");
    if (image.empty()) {
        cout << "Read error" << endl;
        return 1;
    }
    cv::resize(image, image, cv::Size(), 0.5, 0.5);
    cv::imshow("Image", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}