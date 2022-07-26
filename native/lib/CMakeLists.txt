cmake_minimum_required(VERSION 3.22)
project(NativeTest)

set(CMAKE_CXX_STANDARD 14)

set(JNI_COMMON_INCLUDE ${PROJECT_SOURCE_DIR}/../graal/jni/include)

message("JNI_PATH: ${JNI_COMMON_INCLUDE}")

if (WIN32)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/win32)
    set(LIB_EXT dll)
elseif (APPLE)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/darwin)
    set(LIB_EXT dylib)
elseif (UNIX)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/linux)
    set(LIB_EXT so)
endif ()


include_directories(${target} INTERFACE ${JNI_INCLUDE})
set(SOURCE_FILES lib.cc)

message("-- Linking native_lib")
add_library(NativeTest SHARED lib.cc)

add_custom_command(
    TARGET ${PROJECT_NAME}  POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_BINARY_DIR}/libNativeTest.${LIB_EXT}
    ${CMAKE_CURRENT_BINARY_DIR}/../libNativeTest.${LIB_EXT})
