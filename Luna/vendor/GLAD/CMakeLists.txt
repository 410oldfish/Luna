cmake_minimum_required(VERSION 3.30)
project(GLAD)

# 创建 GLAD 库
add_library(glad src/glad.c)

# 设置包含目录
target_include_directories(glad PUBLIC include)
