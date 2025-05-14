#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::face;

void trainModel() {
    Ptr<LBPHFaceRecognizer> recognizer = LBPHFaceRecognizer::create();
    vector<Mat> images;
    vector<int> labels;

    for (int i = 1; i <= 5; i++) {
        string filename = "dataset/" + to_string(i) + ".jpg";
        Mat img = imread(filename, IMREAD_GRAYSCALE);
        if (!img.empty()) {
            images.push_back(img);
            labels.push_back(i);
        }
    }

    recognizer->train(images, labels);
    recognizer->save("models/face_model.yml");
    cout << "Training complete. Model saved!" << endl;
}

int main() {
    trainModel();
    return 0;
}
