cmake_minimum_required(VERSION 3.30)
project(Luna)

set(CMAKE_CXX_STANDARD 26)

# 设置中间目录
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR}/bin-int/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})

add_library(Luna SHARED src/Luna/Application.cpp)
# 添加预处理器定义
target_compile_definitions(Luna PRIVATE LUNA_PLATFORM_WINDOWS LUNA_BUILD_DLL)

add_subdirectory(SandBox)
