cmake_minimum_required(VERSION 3.15)
project(native_jni)

set(CMAKE_CXX_STANDARD 17)

set(OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake-build-debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_PATH})

message("JNI_COMMON_INCLUDE: ${JNI_COMMON_INCLUDE}")

if (WIN32)
    # Set the DLLEXPORT variable to export symbols
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/win32)
    set(JNI_INCLUDE ${JNI_INCLUDE} PARENT_SCOPE)
elseif (APPLE)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/darwin)
    set(JNI_INCLUDE ${JNI_INCLUDE} PARENT_SCOPE)
elseif (UNIX)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/linux)
    set(JNI_INCLUDE ${JNI_INCLUDE} PARENT_SCOPE)
endif ()

message("JNI_COMMON_INCLUDE: ${JNI_INCLUDE}")
include_directories(${PROJECT_NAME} INTERFACE ${JNI_INCLUDE})
set(API_INCLUDE include)
set(API_INCLUDE ${API_INCLUDE} PARENT_SCOPE)
include_directories(${PROJECT_NAME} INTERFACE ${API_INCLUDE})

message("-- Linking native_lib")
set(SOURCE_FILES
        lib.cc
        src/Api.cpp
        src/DxFeed.cpp
        src/Connection.cpp
        src/Subscription.cpp
        src/utils/StringUtils.cpp
        src/utils/TimeAndSaleFormatter.cpp
        src/utils/Diagnostic.cpp
        src/utils/timer.cpp
        src/LoadLibrary.cpp
        src/LoadJavaVm.cpp
        src/utils/StopWatch.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

set(JAVA_LIB_PATH "${JAVA_HOME}/lib/server")
message("JAVA_LIB_PATH: ${JAVA_LIB_PATH}")

link_directories(${JAVA_LIB_PATH})

# Include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(FetchContent)

FetchContent_Declare(date
        GIT_REPOSITORY https://github.com/HowardHinnant/date.git
        GIT_TAG v3.0.1
        )
FetchContent_MakeAvailable(date)

target_link_libraries(${PROJECT_NAME} date)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c)
endif()
