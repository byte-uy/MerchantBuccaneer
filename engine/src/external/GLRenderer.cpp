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
    void GLRenderer::init() 
    {
        if (glewInit() != GLEW_OK)
        {
            throw std::runtime_error("Failed to init GLEW");
        }

    }

    void GLRenderer::render() 
    {
        glClearColor(BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE, BACKGROUND_ALPHA);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    std::shared_ptr<GLRenderer> GLRenderer::create()
    {
        auto renderer = std::make_shared<GLRenderer>();
        renderer->init();
        return renderer;
    }

}  // namespace MBEngine
