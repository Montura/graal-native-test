cmake_minimum_required(VERSION 3.22)
project(native_lib)

set(CMAKE_CXX_STANDARD 14)

set(JNI_COMMON_INCLUDE ${PROJECT_SOURCE_DIR}/../graal/jni/include)

message("JNI_PATH: ${JNI_COMMON_INCLUDE}")

if (WIN32)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/win32)
    set(lib_extension dll)
elseif (APPLE)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/darwin)
    set(lib_extension dylib)
elseif (UNIX)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/linux)
    set(lib_extension so)
endif ()


include_directories(${target} INTERFACE ${JNI_INCLUDE})
set(SOURCE_FILES lib.cc)

message("-- Linking native_lib")
add_library(native_lib STATIC lib.cc)
