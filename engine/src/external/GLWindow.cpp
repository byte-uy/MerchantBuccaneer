#include "GLWindow.h"
#include "Constants.h"

#include "glfw3.h"

#include <stdexcept>

namespace MBEngine::core
{
    class GLWindowImpl
    {
        public:
            GLFWwindow* window_;

            // void framebuffer_size_callback(GLFWwindow* window, int width, int height)
            // {
            //     glViewport(0, 0, width, height);
            // }
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

        window_ = new GLWindowImpl();
        window_->window_ = glfwCreateWindow(mode->width, mode->height, GAME_TITLE, nullptr, nullptr);

        if (window_->window_ == nullptr)
        {
            throw std::runtime_error("Failed to create GLFW window");
        }
        
        //glfwSetFramebufferSizeCallback(window_->window_, GLWindowImpl::framebuffer_size_callback);  

        glfwMakeContextCurrent(window_->window_);

        glViewport(0, 0, mode->height, mode->width);
    }

    void GLWindow::destroy()
    {
        glfwTerminate();
        delete window_;
    }

    std::shared_ptr<GLWindow> GLWindow::create() 
    {
        auto window = std::make_shared<GLWindow>();
        window->init();
        return window;
    }

    void GLWindow::swapBuffers()
    {
        glfwSwapBuffers(window_->window_);
    }

    bool GLWindow::shouldClose()
    {
        return glfwWindowShouldClose(window_->window_) != 0;
    }

    void GLWindow::processInput()
    {
        glfwPollEvents();
        if(glfwGetKey(window_->window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window_->window_, 1);
        }
    }
} // namespace MBEngine::core
