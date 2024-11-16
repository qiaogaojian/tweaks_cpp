# ********************************* 基础项目配置 *********************************
cmake_minimum_required(VERSION 3.10)
project(cpp_project VERSION 1.0.0 LANGUAGES CXX)

# ********************************* 编译器和标准设置 *********************************
# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# ********************************* 输出目录配置 *********************************
# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ********************************* 依赖和包含配置 *********************************
# 添加include目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 收集源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# ********************************* 目标构建配置 *********************************
# 创建核心库
add_library(core_lib
    src/core/message.cpp
)

# 修改可执行文件链接
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE core_lib)

# ********************************* 测试配置 *********************************
# 添加测试
enable_testing()
add_subdirectory(tests)
