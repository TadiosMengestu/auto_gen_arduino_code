cmake_minimum_required(VERSION "3.17")

set(CMAKE_CXX_STANDARD 17)

project(NDD)

include_directories("${CMAKE_SOURCE_DIR}/vendor/imgui/")
include_directories("${CMAKE_SOURCE_DIR}/vendor/imgui/backends")
include_directories("${CMAKE_SOURCE_DIR}/src/")

add_subdirectory("${CMAKE_SOURCE_DIR}/vendor/imgui/")

file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp" )
file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/src/*.h")

file(COPY ${CMAKE_SOURCE_DIR}/res/hw/ DESTINATION vendor)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} Imgui glfw GL)