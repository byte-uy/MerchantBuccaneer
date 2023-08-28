#include "window.h"
#include "constants.h"

#include "glfw3.h"

#include <memory>
#include <stdexcept>

namespace MBEngine
{
    class WindowImpl {
        public:
            std::unique_ptr<GLFWwindow> window_;
    };

    Window::Window()
    {
        if (!static_cast<bool>(glfwInit()))
        {
            throw std::runtime_error("Failed to init GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        width_ = mode->width;
        height_ = mode->height;

        
        window_.window_ = std::make_unique<GLFWwindow>(glfwCreateWindow(width_, height_, GAME_TITLE, nullptr, nullptr));

        if (window_.window_ == nullptr)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to init window");
        }

        glfwMakeContextCurrent(window_.window_.get());
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    int Window::getWidth()
    {
        return width_;
    }

    int Window::getHeight()
    {
        return height_;
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(window_.window_.get()) != 0;
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(window_.window_.get());
    }

}
