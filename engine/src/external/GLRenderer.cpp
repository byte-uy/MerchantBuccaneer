#include "GLRenderer.h"

#include "Constants.h"

#include "glew.h"
#include <GL/GLU.h>

#include <stdexcept>

namespace MBEngine::rendering
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
        glClearColor(core::BACKGROUND_RED, core::BACKGROUND_GREEN, core::BACKGROUND_BLUE, core::BACKGROUND_ALPHA);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    std::shared_ptr<GLRenderer> GLRenderer::create()
    {
        auto renderer = std::make_shared<GLRenderer>();
        renderer->init();
        return renderer;
    }

}  // namespace MBEngine::rendering
