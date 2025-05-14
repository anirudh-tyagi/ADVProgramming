#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <iostream>
#include "attendance.h"

using namespace std;
using namespace cv;
using namespace cv::face;

int main() {
    CascadeClassifier face_cascade;
    face_cascade.load("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_default.xml"); 

    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Error: Could not access the camera" << endl;
        return -1;
    }

    Ptr<LBPHFaceRecognizer> recognizer = LBPHFaceRecognizer::create();
    recognizer->read("models/face_model.yml");

    Mat frame, gray;
    while (true) {
        cap >> frame;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.1, 4, CASCADE_SCALE_IMAGE, Size(30, 30));

        for (auto face : faces) {
            Mat faceROI = gray(face);
            int label;
            double confidence;
            recognizer->predict(faceROI, label, confidence);

            if (confidence < 50) {  
                putText(frame, "User " + to_string(label), Point(face.x, face.y - 10), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0), 2);
                logAttendance(label);
            } else {
                putText(frame, "Unknown", Point(face.x, face.y - 10), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 255), 2);
            }
            rectangle(frame, face, Scalar(255, 0, 0), 2);
        }

        imshow("Face Recognition Attendance System", frame);
        if (waitKey(1) == 27) break;
    }

    return 0;
}
