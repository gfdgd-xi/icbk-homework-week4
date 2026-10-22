#include <opencv2/opencv.hpp>
using namespace std;

int main() {
    cv::Mat image = cv::imread("pic.png");
    cv::Mat blurImage;
    if (image.empty()) {
        cout << "Read error" << endl;
        return 1;
    }
    cv::GaussianBlur(image, blurImage, cv::Size(5, 5), 0);
    cv::threshold(blurImage, blurImage, 127, 256, cv::THRESH_BINARY);
    cv::threshold(image, image, 127, 256, cv::THRESH_BINARY);
    cv::imshow("Image(Old)", image);
    cv::imshow("Image(New)", blurImage);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}