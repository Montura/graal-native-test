 cmake_minimum_required(VERSION 3.22)
project(native)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/lib")
add_subdirectory(lib)

set(GRAAL_LIB_PATH "${PROJECT_SOURCE_DIR}/../target/native-image")
message("GRAAL_LIB_PATH: ${GRAAL_LIB_PATH}")

link_directories(
	"${PROJECT_SOURCE_DIR}/graal"
	${GRAAL_LIB_PATH}
)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} GraalSample NativeTest)

if (WIN32)
    message("GRAAL_LIB: ${GRAAL_LIB_PATH}/GraalSample.dll")
    add_custom_command(
        TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${GRAAL_LIB_PATH}/GraalSample.dll
        ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME})
endif()