cmake_minimum_required(VERSION 3.0.0)

project(GTK_PC)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

add_executable(${PROJECT_NAME}_app main.cpp)

message("GTK3_INCLUDE_DIRS=${GTK3_INCLUDE_DIRS}")
target_include_directories(${PROJECT_NAME}_app PRIVATE ${GTK3_INCLUDE_DIRS})

message("GTK3_LIBRARIES=${GTK3_LIBRARIES}")
target_link_libraries(${PROJECT_NAME}_app PRIVATE ${GTK3_LIBRARIES})
