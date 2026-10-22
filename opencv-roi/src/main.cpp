#include <opencv2/opencv.hpp>
using namespace std;

int main() {
    cv::Mat image = cv::imread("pic.png");
    if (image.empty()) {
        cout << "Read error" << endl;
        return 1;
    }
    cv::Rect rect(200, 0, 400, 400);
    cv::Mat roi = image(rect);
    cv::imshow("Image", roi);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}