cmake_minimum_required(VERSION 3.10)
project(FaceRecognition)

find_package(OpenCV REQUIRED)

add_executable(face_train face_train.cpp)
target_link_libraries(face_train ${OpenCV_LIBS})

add_executable(main main.cpp attendance.cpp)
target_link_libraries(main ${OpenCV_LIBS})
