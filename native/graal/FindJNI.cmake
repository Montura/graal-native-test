set(JNI_COMMON_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/${RELATIVE_GRAAL_PATH}/graal/jni/include)

message("JNI_PATH: ${JNI_COMMON_INCLUDE}")

if (WIN32)
    # Set the DLLEXPORT variable to export symbols
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
    set(LIB_NAME ${PROJECT_NAME}.so)
    message("Target lib name: ${LIB_NAME}")
endif ()

include_directories(${target} INTERFACE ${JNI_INCLUDE})

