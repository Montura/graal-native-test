cmake_minimum_required(VERSION 3.15)
project(native_app)

set(JAVA_HOME /Users/Andrey.Mikhalev/Documents/Tools/labsjdk-ce-11.0.15-jvmci-22.1-b06/Contents/Home)
set(JNI_COMMON_INCLUDE ${JAVA_HOME}/include)

add_subdirectory(jni-lib)
message(JNI_INCLUDE: " ${JNI_INCLUDE}")
message(API_INCLUDE: " ${API_INCLUDE}")

include_directories(${PROJECT_NAME} INTERFACE ${JNI_INCLUDE})
include_directories(${PROJECT_NAME} INTERFACE ${API_INCLUDE})
include_directories(${PROJECT_NAME} INTERFACE jni-lib)

set(JAVA_LIB_PATH "${JAVA_HOME}/lib/server")
message("JAVA_LIB_PATH: ${JAVA_LIB_PATH}")

link_directories(${JAVA_LIB_PATH})

add_library(JVM_LIB SHARED IMPORTED)
if (WIN32)
    set_property(TARGET JVM_LIB PROPERTY IMPORTED_LOCATION ${JAVA_LIB_PATH}/jvm.dll)
    set_property(TARGET JVM_LIB PROPERTY IMPORTED_IMPLIB ${JAVA_LIB_PATH}/jvm.lib)
elseif (APPLE)
    set_property(TARGET JVM_LIB PROPERTY IMPORTED_LOCATION ${JAVA_LIB_PATH}/libjvm.dylib)
elseif (UNIX)
    set_property(TARGET JVM_LIB PROPERTY IMPORTED_LOCATION ${JAVA_LIB_PATH}/jvm.so)
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} JVM_LIB)
target_link_libraries(${PROJECT_NAME} JVM_LIB native_jni)