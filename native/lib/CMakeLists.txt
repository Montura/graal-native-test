cmake_minimum_required(VERSION 3.15)
project(NativeTest)

set(CMAKE_CXX_STANDARD 14)

set(RELATIVE_GRAAL_PATH "..")
include("../graal/FindJNI.cmake")

message("-- Linking native_lib")
add_library(NativeTest SHARED lib.cc)
set_target_properties(NativeTest PROPERTIES PREFIX "")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(NativeTest PRIVATE -Wall -Wextra)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    target_compile_options(NativeTest PRIVATE /EHsc /MTd /W2 /c)
endif()
