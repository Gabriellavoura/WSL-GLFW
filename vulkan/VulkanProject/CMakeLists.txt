cmake_minimum_required(VERSION 3.10)
project(VulkanTest VERSION 0.1.0 LANGUAGES CXX)

# set C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(glfw3 3.4 REQUIRED)  # Requires GLFW version 3.4 or higher
find_package(Vulkan REQUIRED) # Added vulkan package


# Create an executable with the Vulkan settings.
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)


# Link libraries and specify include directories for TestProject
target_link_libraries(${PROJECT_NAME} PUBLIC
    glfw
    Vulkan::Vulkan
)

# Specify common include directories in a single target_include_directories call
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/libs
    ${CMAKE_CURRENT_SOURCE_DIR}/deps
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/include
    ${Vulkan_INCLUDE_DIRS}
)

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra)

# Print Vulkan paths for debuggin
message(STATUS "Vulkan_INCLUDE_DIRS: ${Vulkan_INCLUDE_DIRS}")
