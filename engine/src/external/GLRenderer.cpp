#include "GLRenderer.h"

#include "Constants.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
#include "glew.h"
#pragma clang diagnostic pop
#include <GL/GLU.h>
#include "glfw3.h"

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

    void GLRenderer::createShaderProgram(const core::File& vertexShader, const core::File& fragmentShader)
    {
        vertexShaderHandler_ = glCreateShader(GL_VERTEX_SHADER);
        compileShader(vertexShaderHandler_, vertexShader);

        fragmentShaderHandler_ = glCreateShader(GL_FRAGMENT_SHADER);
        compileShader(fragmentShaderHandler_, fragmentShader);

        shaderProgramHandler_ = glCreateProgram();
        glAttachShader(shaderProgramHandler_, vertexShaderHandler_);
        glAttachShader(shaderProgramHandler_, fragmentShaderHandler_);
        glLinkProgram(shaderProgramHandler_);

        GLint success = 0;
        glGetProgramiv(shaderProgramHandler_, GL_LINK_STATUS, &success);
        if (success == GL_FALSE)
        {
            // Dealing with C-style strings so the linter will complain
            // NOLINTBEGIN
            char infoLog[512];
            glGetProgramInfoLog(shaderProgramHandler_, 512, nullptr, infoLog);
            glDeleteShader(vertexShaderHandler_);
            glDeleteShader(fragmentShaderHandler_);
            glDeleteProgram(shaderProgramHandler_);
            throw std::runtime_error("Failed to link shader program: " + std::string(infoLog));
            // NOLINTEND
        }
    }

    GLRenderer::~GLRenderer() 
    {
        glDeleteShader(vertexShaderHandler_);
        glDeleteShader(fragmentShaderHandler_);
        glDeleteProgram(shaderProgramHandler_);
    }

    void GLRenderer::compileShader(unsigned int shaderHandler, const core::File& shader) 
    {
        std::string shaderContent = shader.getContent();
        const char* shaderSource = shaderContent.c_str();
        glShaderSource(shaderHandler, 1, &shaderSource, nullptr);
        glCompileShader(shaderHandler);

        GLint success = 0;
        glGetShaderiv(shaderHandler, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
        {
            // Dealing with C-style strings so the linter will complain
            // NOLINTBEGIN
            char infoLog[512];
            glGetShaderInfoLog(shaderHandler, 512, nullptr, infoLog);
            glDeleteShader(shaderHandler);
            throw std::runtime_error("Failed to compile vertex shader: " + std::string(infoLog));
            // NOLINTEND
        }
    }


}  // namespace MBEngine::rendering
