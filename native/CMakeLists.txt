cmake_minimum_required(VERSION 3.15)
project(native)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/lib")
add_subdirectory(lib)

set(GRAAL_LIB_PATH "${PROJECT_SOURCE_DIR}/../target/native-image")
message("GRAAL_LIB_PATH: ${GRAAL_LIB_PATH}")

link_directories(${GRAAL_LIB_PATH})

add_library(GRAAL_LIB SHARED IMPORTED)
if (WIN32)
    set_property(TARGET GRAAL_LIB PROPERTY IMPORTED_LOCATION ${GRAAL_LIB_PATH}/GraalSample.dll)
    set_property(TARGET GRAAL_LIB PROPERTY IMPORTED_IMPLIB ${GRAAL_LIB_PATH}/GraalSample.lib)
elseif (APPLE)
    set_property(TARGET GRAAL_LIB PROPERTY IMPORTED_LOCATION ${GRAAL_LIB_PATH}/GraalSample.dylib)
elseif (UNIX)
    set_property(TARGET GRAAL_LIB PROPERTY IMPORTED_LOCATION ${GRAAL_LIB_PATH}/GraalSample.so)
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} GRAAL_LIB NativeTest)

if (WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${GRAAL_LIB_PATH}/GraalSample.dll
        ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME})
endif()