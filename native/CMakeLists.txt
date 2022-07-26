 cmake_minimum_required(VERSION 3.22)
project(native)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/lib")
add_subdirectory(lib)
link_directories("${PROJECT_SOURCE_DIR}/graal")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} GraalSample NativeTest)
