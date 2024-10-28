cmake_minimum_required(VERSION 3.5.0)
project(TestProject VERSION 0.1.0 LANGUAGES C CXX)

# Ensure modern OpenGL policy
cmake_policy(SET CMP0072 NEW)

# Find and include OpenGL
find_package(OpenGL REQUIRED)
find_package(glfw3 3.4 REQUIRED)  # Requires GLFW version 3.4 or higher

# Add glad library and specify include directories
add_library(glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/src/gl.c libs/glad/src/egl.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include)

# Create an executable with the source files
add_executable(TestProject ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Link libraries and specify include directories for TestProject
target_link_libraries(TestProject PUBLIC OpenGL::GL glad glfw)


# Specify common include directories in a single target_include_directories call
target_include_directories(TestProject PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/libs
    ${CMAKE_CURRENT_SOURCE_DIR}/deps
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/include
)

# Specify C++ standards and compiler flags for TestProject only
set_target_properties(TestProject PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(TestProject PUBLIC -Wall -Wextra)