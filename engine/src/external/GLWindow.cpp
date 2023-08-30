#include "GLWindow.h"
#include "Constants.h"

#include "glfw3.h"

#include <stdexcept>

namespace MBEngine
{
    class GLWindowImpl
    {
        public:
            GLFWwindow* window_;
    };

    void GLWindow::init()
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

        window_ = new GLWindowImpl();
        window_->window_ = glfwCreateWindow(width_, height_, GAME_TITLE, nullptr, nullptr);

        if (window_->window_ == nullptr)
        {
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window_->window_);
    }

    void GLWindow::destroy()
    {
        glfwDestroyWindow(window_->window_);
        delete window_;
    }

    void GLWindow::swapBuffers()
    {
        glfwSwapBuffers(window_->window_);
    }

    bool GLWindow::shouldClose()
    {
        return glfwWindowShouldClose(window_->window_) != 0;
    }

} // namespace MBEngine
