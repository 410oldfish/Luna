cmake_minimum_required(VERSION 3.30)
project(SandBox)

set(CMAKE_CXX_STANDARD 26)

# 设置中间目录
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR}/bin-int/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})

add_executable(SandBox src/SandBoxApp.cpp)
# 添加预处理器定义
target_compile_definitions(SandBox PRIVATE LUNA_PLATFORM_WINDOWS)
# 如果需要链接 Luna 库，可以添加以下行
target_link_libraries(SandBox PRIVATE Luna)
# 添加额外的包含目录
target_include_directories(SandBox PRIVATE
        ${CMAKE_SOURCE_DIR}/Luna/src
        ${CMAKE_SOURCE_DIR}/Luna/vendor/spdlog/include
        ${CMAKE_SOURCE_DIR}/Luna/vendor/glm
)

