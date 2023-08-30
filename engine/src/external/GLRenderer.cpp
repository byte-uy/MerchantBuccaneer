#include "GLRenderer.h"

#include "Constants.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
#include "glew.h"
#pragma clang diagnostic pop
#include <GL/GLU.h>
#include "glfw3.h"

#include <stdexcept>

namespace MBEngine
{
    class GLWindow
    {
    public:
        GLWindow(int width, int height)
            : width_(width), height_(height),
              window_(glfwCreateWindow(width, height, GAME_TITLE, 
              nullptr, nullptr))
        {
            if (window_ == nullptr)
            {
                throw std::runtime_error("Failed to create GLFW window");
            }

            glfwMakeContextCurrent(window_);
        }

        ~GLWindow()
        {
            glfwDestroyWindow(window_);
        }

        GLWindow(const GLWindow&) = delete;
        GLWindow(GLWindow&&) = default;

        GLWindow& operator=(const GLWindow&) = delete;
        GLWindow& operator=(GLWindow&&) = default;

        [[nodiscard]] inline bool shouldClose()
        {
            return glfwWindowShouldClose(window_) != 0;
        }

        inline void swapBuffers()
        {
            glfwSwapBuffers(window_);
        }

        [[nodiscard]] inline int getWidth() const
        {
            return width_;
        }

        [[nodiscard]] inline int getHeight() const
        {
            return height_;
        }

    private:
        GLFWwindow* window_;
    
        int width_;
        int height_;
    };

    void GLRenderer::init() 
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

        window_ = new GLWindow(mode->width, mode->height);

        if (glewInit() != GLEW_OK)
        {
            throw std::runtime_error("Failed to init GLEW");
        }
    }

    void GLRenderer::render() 
    {
        glViewport(0, 0, window_->getWidth(), window_->getHeight());
        while (!window_->shouldClose())
        {
            window_->swapBuffers();
            glfwPollEvents();
        }
    }

    void GLRenderer::destroy() 
    {
        glfwTerminate();
    }
}  // namespace MBEngine
