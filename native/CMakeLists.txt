cmake_minimum_required(VERSION 3.15)
project(native)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/lib")
add_subdirectory(lib)

set(GRAAL_LIB_PATH "${PROJECT_SOURCE_DIR}/../target/native-image")
message("GRAAL_LIB_PATH: ${GRAAL_LIB_PATH}")

link_directories(${GRAAL_LIB_PATH})

find_library(GRAAL_LIB NAMES GraalSample libGraalSample GraalSample.dylib PATHS ${GRAAL_LIB_PATH})
message("Graal lib: ${GRAAL_LIB}")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} "${GRAAL_LIB}" NativeTest)

if (WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${GRAAL_LIB_PATH}/GraalSample.dll
        ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME})
endif()