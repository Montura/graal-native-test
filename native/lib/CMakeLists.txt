cmake_minimum_required(VERSION 3.22)
project(NativeTest)

set(CMAKE_CXX_STANDARD 14)

set(JNI_COMMON_INCLUDE ${PROJECT_SOURCE_DIR}/../graal/jni/include)

message("JNI_PATH: ${JNI_COMMON_INCLUDE}")

if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/win32)
    set(LIB_EXT dll)
    set(LIB_NAME ${PROJECT_NAME}.dll)
    message("Target lib name: ${LIB_NAME}")
elseif (APPLE)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/darwin)
    set(LIB_EXT dylib)
    set(LIB_NAME ${PROJECT_NAME}.dylib)
    message("Target lib name: ${LIB_NAME}")
elseif (UNIX)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/linux)
    set(LIB_EXT so)
    set(LIB_NAME lib${PROJECT_NAME}.dll)
    message("Target lib name: ${LIB_NAME}")
endif ()


include_directories(${target} INTERFACE ${JNI_INCLUDE})
set(SOURCE_FILES lib.cc)

message("-- Linking native_lib")
add_library(NativeTest SHARED lib.cc)

add_custom_command(
    TARGET ${PROJECT_NAME}  POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}
    ${CMAKE_CURRENT_BINARY_DIR}/../${LIB_NAME})
