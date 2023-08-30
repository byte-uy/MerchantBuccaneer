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
    void GLRenderer::init(std::shared_ptr<IWindow> window) 
    {
        if (glewInit() != GLEW_OK)
        {
            throw std::runtime_error("Failed to init GLEW");
        }

        window_ = std::dynamic_pointer_cast<GLWindow>(window);
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

    std::shared_ptr<GLRenderer> GLRenderer::create(const std::shared_ptr<GLWindow>& window)
    {
        auto renderer = std::make_shared<GLRenderer>();
        renderer->init(window);
        return renderer;
    }

}  // namespace MBEngine
