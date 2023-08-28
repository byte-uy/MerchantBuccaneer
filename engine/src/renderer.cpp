#include "renderer.h"
#include "window.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
#include "glew.h"
#pragma clang diagnostic pop
#include <GL/GLU.h>
#include <iostream>

#include "glfw3.h"

int MBEngine::Renderer::render()
{
    
    Window &window = Window::getInstance();
    
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Faild to init glew" << std::endl;
        return -1;
    }

    glViewport(0, 0, window.getWidth(), window.getHeight());
    while (!window.shouldClose())
    {
        window.swapBuffers();
        glfwPollEvents();
    }

    return 0;
}
