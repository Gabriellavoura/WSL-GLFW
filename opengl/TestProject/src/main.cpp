#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

int main(int, char**) {

    GLFWwindow* window;

    if(!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(640, 480, "First window!", NULL, NULL);
    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
