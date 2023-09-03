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

        for (auto& shader : shaders_)
        {
            shader->render();
        }
    }

    void GLRenderer::addShader(std::unique_ptr<IShader> shader) 
    {
        std::unique_ptr<GLShader> glShader(dynamic_cast<GLShader*>(shader.release()));
        shaders_.push_back(std::move(glShader));
    }

    std::shared_ptr<GLRenderer> GLRenderer::create()
    {
        auto renderer = std::make_shared<GLRenderer>();
        renderer->init();
        return renderer;
    }

}  // namespace MBEngine::rendering
