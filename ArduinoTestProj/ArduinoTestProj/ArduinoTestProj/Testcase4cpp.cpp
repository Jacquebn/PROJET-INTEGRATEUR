#include <opencv2/opencv.hpp>
#include <iostream>
#include <gtest/gtest.h>
#include "C++_code_to_stop.cpp"

using namespace std;
using namespace cv;

Mat frame, framePers, frameGray, frameThresh, frameEdge, frameFinal, frameFinalDuplicate;

void Threshold(Mat& frame, Mat& framePers, Mat& frameGray, Mat& frameThresh, Mat& frameEdge, Mat& frameFinal, Mat& frameFinalDuplicate)
{
    cvtColor(framePers, frameGray, COLOR_RGB2GRAY);
    inRange(frameGray, 230, 255, frameThresh);
    Canny(frameGray, frameEdge, 900, 900, 3, false);
    add(frameThresh, frameEdge, frameFinal);
    cvtColor(frameFinal, frameFinal, COLOR_GRAY2RGB);
    cvtColor(frameFinal, frameFinalDuplicate, COLOR_RGB2BGR);   //used in histrogram function only
}

TEST(ThresholdTest, CheckThreshold) {
    Mat testFrame = imread("test_frame.jpg", IMREAD_COLOR);
    Mat testFramePers(testFrame.size(), testFrame.type());
    Mat testFrameGray(testFrame.size(), testFrame.type());
    Mat testFrameThresh(testFrame.size(), testFrame.type());
    Mat testFrameEdge(testFrame.size(), testFrame.type());
    Mat testFrameFinal(testFrame.size(), testFrame.type());
    Mat testFrameFinalDuplicate(testFrame.size(), testFrame.type());

    Threshold(testFrame, testFramePers, testFrameGray, testFrameThresh, testFrameEdge, testFrameFinal, testFrameFinalDuplicate);

    Mat expectedFrameThresh = imread("expected_frame_thresh.jpg", IMREAD_COLOR);
    Mat expectedFrameEdge = imread("expected_frame_edge.jpg", IMREAD_COLOR);
    Mat expectedFrameFinal = imread("expected_frame_final.jpg", IMREAD_COLOR);
    Mat expectedFrameFinalDuplicate = imread("expected_frame_final_duplicate.jpg", IMREAD_COLOR);

    //Check if frameThresh is the same as expectedFrameThresh
    for (int i = 0; i < testFrameThresh.rows; i++) {
        for (int j = 0; j < testFrameThresh.cols; j++) {
            EXPECT_EQ(testFrameThresh.at<Vec3b>(i, j), expectedFrameThresh.at<Vec3b>(i, j));
        }
    }

    //Check if frameEdge is the same as expectedFrameEdge
    for (int i = 0; i < testFrameEdge.rows; i++) {
        for (int j = 0; j < testFrameEdge.cols; j++) {
            EXPECT_EQ(testFrameEdge.at<Vec3b>(i, j), expectedFrameEdge.at<Vec3b>(i, j));
        }
    }

   