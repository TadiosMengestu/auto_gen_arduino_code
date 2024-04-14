cmake_minimum_required(VERSION "3.17")

project(Imgui)

file(GLOB Imgui_SOURCE_FILES "${Imgui_SOURCE_DIR}/i*.cpp" "${Imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h" "${Imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h")
file(GLOB Imgui_HEADER_FILES "${Imgui_SOURCE_DIR}/i*.h" "${Imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp" "${Imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp")

file(GLOB SRC_FILES "${Imgui_SOURCE_DIR}/examples/example_glfw_opengl3/*.cpp")

set(BUILD_SHARED_LIBS NO)

add_library(${PROJECT_NAME} ${SRC_FILES} ${Imgui_SOURCE_FILES} ${Imgui_HEADER_FILES})