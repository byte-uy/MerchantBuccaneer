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
    void GLRenderer::init() 
    {
        if (glewInit() != GLEW_OK)
        {
            throw std::runtime_error("Failed to init GLEW");
        }

    }

    void GLRenderer::render() 
    {
        static const float GL_BACKGROUND_RED = 0.2F;
        static const float GL_BACKGROUND_GREEN = 0.3F;
        static const float GL_BACKGROUND_BLUE = 0.3F;
        static const float GL_BACKGROUND_ALPHA = 1.0F;
        glClearColor(GL_BACKGROUND_RED, GL_BACKGROUND_GREEN, GL_BACKGROUND_BLUE, GL_BACKGROUND_ALPHA);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    std::shared_ptr<GLRenderer> GLRenderer::create()
    {
        auto renderer = std::make_shared<GLRenderer>();
        renderer->init();
        return renderer;
    }

}  // namespace MBEngine
