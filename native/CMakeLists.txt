cmake_minimum_required(VERSION 3.15)
project(native_app)

set(CMAKE_CXX_STANDARD 17)

#set(JAVA_HOME /Users/Andrey.Mikhalev/Downloads/labsjdk-ce-11.0.18-jvmci-22.3-b13/Contents/Home)
set(JAVA_HOME D:/Tools/labsjdk-ce-17.0.6-jvmci-22.3-b13)
set(JNI_COMMON_INCLUDE ${JAVA_HOME}/include)

add_subdirectory(jni-lib)
message(JNI_INCLUDE: " ${JNI_INCLUDE}")
message(API_INCLUDE: " ${API_INCLUDE}")

include_directories(${PROJECT_NAME} INTERFACE ${JNI_INCLUDE})
include_directories(${PROJECT_NAME} INTERFACE ${API_INCLUDE})
include_directories(${PROJECT_NAME} INTERFACE jni-lib)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} native_jni)