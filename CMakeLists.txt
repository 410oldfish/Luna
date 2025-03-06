cmake_minimum_required(VERSION 3.30)
project(Luna)

set(CMAKE_CXX_STANDARD 26)

# 设置中间目录
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR}/bin-int/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})

# 自动添加 src 目录中的所有 .cpp 文件
file(GLOB_RECURSE SOURCES
        "Luna/src/*.cpp"
        "Luna/src/Platform/Windows/*.cpp"
        "Luna/src/Luna/*.cpp")

# 添加预编译头文件
set(PCH_HEADER "Luna/src/lunaPch.h")
set(PCH_SOURCE "Luna/src/lunaPch.cpp")  # 你需要创建这个文件

# 创建预编译头文件库
add_library(PCH STATIC ${PCH_HEADER} ${PCH_SOURCE})

# 添加 Luna 库
add_library(Luna SHARED ${SOURCES})

# 添加预处理器定义
target_compile_definitions(Luna PRIVATE LUNA_PLATFORM_WINDOWS LUNA_BUILD_DLL)

# 链接预编译头文件库
target_link_libraries(Luna PRIVATE PCH)

# 添加 GLFW 的子目录
add_subdirectory(Luna/vendor/GLFW)

# 链接 GLFW 库
target_link_libraries(Luna PRIVATE glfw)

# 链接 OpenGL 库
target_link_libraries(Luna PRIVATE opengl32)

# Additional Includes
target_include_directories(Luna PRIVATE
        ${CMAKE_SOURCE_DIR}/Luna/vendor/spdlog/include
        ${CMAKE_SOURCE_DIR}/Luna/vendor/GLFW/include
        ${CMAKE_SOURCE_DIR}/Luna/src)

# 添加子目录
add_subdirectory(SandBox)

# 设置预编译头文件
target_precompile_headers(Luna PRIVATE ${PCH_HEADER})
