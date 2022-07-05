cmake_minimum_required(VERSION 3.0.0)

project(DisplayImage)

find_package(OpenCV REQUIRED)

add_executable(DisplayImage main.cpp)

message("OpenCV_INCLUDE_DIRS=${OpenCV_INCLUDE_DIRS}")
target_include_directories(DisplayImage PRIVATE ${OpenCV_INCLUDE_DIRS})

message("OpenCV_LIBS=${OpenCV_LIBS}")
target_link_libraries(DisplayImage ${OpenCV_LIBS})
