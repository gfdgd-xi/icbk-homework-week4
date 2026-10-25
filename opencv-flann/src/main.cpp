#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    cv::Mat image = cv::imread("pic.png");
    cv::Mat g2;
    cv::cvtColor(image, g2, cv::COLOR_BGR2GRAY);
    cv::VideoCapture capture = cv::VideoCapture(0);
    cv::Ptr<cv::SiftFeatureDetector> sift = cv::SiftFeatureDetector::create();
    vector<cv::KeyPoint> kp2;
    cv::Mat des2;
    sift->detect(g2, kp2);
    sift->compute(g2, kp2, des2);
    while (1)
    {
        cv::Mat frame;
        bool ret = capture.read(frame);
        if (!ret) {
            cout << "Failed to read camera" << endl;
            return 0;
        }
        cv::Mat g1;
        cv::cvtColor(frame, g1, cv::COLOR_BGR2GRAY);
        vector<cv::KeyPoint> kp1;
        cv::Mat des1;
        sift->detect(g1, kp1);
        sift->compute(g1, kp1, des1);

        std::vector<std::vector<cv::DMatch>> matches;
        cv::FlannBasedMatcher flann;
        vector<cv::DMatch> good;
        flann.knnMatch(des1, des2, matches, 2);
        for (auto i: matches) {
            auto m = i[0];
            auto n = i[1];
            if (m.distance < 0.7 * n.distance) {
                good.push_back(m);
            }
        }
        cv::Mat retImg;
        cv::drawMatches(frame, kp1, image, kp2, good, retImg);
        cv::putText(retImg, to_string(good.size()), cv::Point(0, 100), 1, 5, cv::Scalar(0, 0, 255));
        cv::imshow("retImg", retImg);
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }
    capture.release();
    cv::destroyAllWindows();
}