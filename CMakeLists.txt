cmake_minimum_required(VERSION 3.10)

project(my_project)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加main.cpp作为可执行文件
add_executable(my_project main.cc)

# 添加子目录，将子目录的CMakeLists.txt包含进来
add_subdirectory(google_test)

target_link_libraries(my_project  gtest pthread)