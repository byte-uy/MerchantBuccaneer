#include "glew.h"
#include <GL/GLU.h>
#include <iostream>

#include "benchmark.h"
#include "glfw3.h"

int main()
{
    SCOPED_BENCHMARK(main);
    if (!static_cast<bool>(glfwInit()))
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Merchant Buccaneer", nullptr, nullptr);

    if (window == nullptr)
    {
        glfwTerminate();
        std::cout << "Faild to create window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Faild to init glew" << std::endl;
        return -1;
    }

    glViewport(0, 0, mode->width, mode->height);
    while (!static_cast<bool>(glfwWindowShouldClose(window)))
    {
        std::cout << "While" << std::endl;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}