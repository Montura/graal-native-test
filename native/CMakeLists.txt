cmake_minimum_required(VERSION 3.15)
project(native_app)

set(CMAKE_CXX_STANDARD 14)

set(JAVA_HOME /Users/Andrey.Mikhalev/Documents/Tools/labsjdk-ce-11.0.15-jvmci-22.1-b06/Contents/Home)
set(JNI_COMMON_INCLUDE ${JAVA_HOME}/include)

add_subdirectory(jni-lib)
message(JNI_INCLUDE: " ${JNI_INCLUDE}")
message(API_INCLUDE: " ${API_INCLUDE}")

include_directories(${PROJECT_NAME} INTERFACE ${JNI_INCLUDE})
include_directories(${PROJECT_NAME} INTERFACE ${API_INCLUDE})
include_directories(${PROJECT_NAME} INTERFACE jni-lib)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} native_jni)