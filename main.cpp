#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//////////////  Webcam face detection /////////////////
//
void main() {
    //Load face cascade
    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_default.xml");

    VideoCapture cap(0);
    //namedWindow("Face Detector", WINDOW_NORMAL);
    //resizeWindow("Face Detector", 1280, 1000);


    while (true) {
        cv::Mat frame;
        cap >> frame;

        // Detect faces in the current frame
        vector<Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

        // Draw rectangles around detected faces
        for (const Rect& face : faces) {
            rectangle(frame, face, Scalar(0, 255, 0), 2);
        }

        // Display the frame with detected faces
        imshow("Face Detector", frame);

        // Exit the loop when the 'q' key is pressed
        if (waitKey(1) == 'q') {
            break;
        }
    }
}
