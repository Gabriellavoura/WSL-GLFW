cmake_minimum_required(VERSION 3.5.0)
project(TestProject VERSION 0.1.0 LANGUAGES C CXX)

# Ensure modern OpenGL policy
cmake_policy(SET CMP0072 NEW)

# Find and include OpenGL
find_package(OpenGL REQUIRED)

# Create an executable with the source files
add_executable(TestProject 
    src/main.cpp
    include/glad/glad.h
    src/glad.c 
)

# Specify where to find glad headers for this target
target_include_directories(TestProject PRIVATE 
    ${CMAKE_SOURCE_DIR}/opengl/TestProject/include
)

# Link GLFW and OpenGL libraries
target_link_libraries(TestProject glfw OpenGL::GL)

# Specify C++ compiler flags (CXXFLAGS) here
set_target_properties(TestProject PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

# Specify C++ and C compiler flags if needed
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Enable testing functionality
enable_testing()