#include <opencv2/opencv.hpp>
using namespace std;

int main() {
    cv::Mat image = cv::imread("pic.png");
    if (image.empty()) {
        cout << "Read error" << endl;
        return 1;
    }
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    cv::threshold(image, image, 127, 256, cv::THRESH_BINARY);
    cout << "处理后非0像素数量：" << cv::countNonZero(image) << endl;
    cv::imwrite("new.png", image);
    cout << "已保存 new.png" << endl;
    cv::imshow("Image", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}