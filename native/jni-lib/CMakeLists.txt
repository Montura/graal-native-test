cmake_minimum_required(VERSION 3.15)
project(native_jni)

set(CMAKE_CXX_STANDARD 14)

set(OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
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
    set(LIB_EXT dll)
    set(LIB_NAME ${PROJECT_NAME}.dll)
    message("Target lib name: ${LIB_NAME}")
elseif (APPLE)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/darwin)
    set(JNI_INCLUDE ${JNI_INCLUDE} PARENT_SCOPE)
    set(LIB_EXT dylib)
    set(LIB_NAME ${PROJECT_NAME}.dylib)
    message("Target lib name: ${LIB_NAME}")
elseif (UNIX)
    set(JNI_INCLUDE ${JNI_COMMON_INCLUDE} ${JNI_COMMON_INCLUDE}/linux)
    set(JNI_INCLUDE ${JNI_INCLUDE} PARENT_SCOPE)
    set(LIB_EXT so)
    set(LIB_NAME ${PROJECT_NAME}.so)
    message("Target lib name: ${LIB_NAME}")
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
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

set(JAVA_LIB_PATH "${JAVA_HOME}/lib/server")
message("JAVA_LIB_PATH: ${JAVA_LIB_PATH}")

link_directories(${JAVA_LIB_PATH})

add_library(JVM_LIB SHARED IMPORTED)
if (WIN32)
    set_property(TARGET JVM_LIB PROPERTY IMPORTED_LOCATION ${JAVA_HOME}/bin/server/jvm.dll)
    set_property(TARGET JVM_LIB PROPERTY IMPORTED_IMPLIB ${JAVA_HOME}/lib/jvm.lib)
elseif (APPLE)
    set_property(TARGET JVM_LIB PROPERTY IMPORTED_LOCATION ${JAVA_LIB_PATH}/libjvm.dylib)
elseif (UNIX)
    set_property(TARGET JVM_LIB PROPERTY IMPORTED_LOCATION ${JAVA_LIB_PATH}/jvm.so)
endif()

# Include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(FetchContent)

FetchContent_Declare(date
        GIT_REPOSITORY https://github.com/HowardHinnant/date.git
        GIT_TAG v3.0.1
        )
FetchContent_MakeAvailable(date)

target_link_libraries(${PROJECT_NAME} JVM_LIB date)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c)
endif()
