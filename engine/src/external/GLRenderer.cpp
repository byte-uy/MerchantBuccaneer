#include "GLRenderer.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
#include "glew.h"
#pragma clang diagnostic pop
#include <GL/GLU.h>
#include "glfw3.h"

#include <stdexcept>

namespace MBEngine
{
    void GLRenderer::init(IWindow* window) 
    {
        if (glewInit() != GLEW_OK)
        {
            throw std::runtime_error("Failed to init GLEW");
        }

        window_ = std::shared_ptr<GLWindow>(dynamic_cast<GLWindow*>(window));
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
