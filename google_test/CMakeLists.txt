# 添加所有的源文件
add_library(gtest gtest-all.cc)

# 设置头文件目录
target_include_directories(gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 将sort库链接到主可执行文件

