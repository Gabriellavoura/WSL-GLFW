cmake_minimum_required(VERSION 3.5.0)
project(TestProject VERSION 0.1.0 LANGUAGES C CXX)

add_executable(TestProject src/main.cpp)

target_link_libraries(TestProject glfw)

# enable testing functionality
enable_testing()