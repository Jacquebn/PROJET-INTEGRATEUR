#include <gtest/gtest.h>
#include "load_xml_file.cpp"

TEST(CaptureTest, TestCapture) {
    // Arrange
    RaspiCam_Cv Camera;
    Setup(0, nullptr, Camera);
    Mat expectedFrame;

    // Act
    Capture();
    Camera.retrieve(expectedFrame);

    // Assert
    EXPECT_EQ(frame.size(), expectedFrame.size());
    for (int i = 0; i < frame.rows; i++) {
        for (int j = 0; j < frame.cols; j++) {
            EXPECT_EQ(frame.at<Vec3b>(i, j), expectedFrame.at<Vec3b>(i, j));
        }
    }
}
