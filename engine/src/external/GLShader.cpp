#include "GLShader.h"

#include "glew.h"
#include <GL/GLU.h>

#include <stdexcept>

namespace MBEngine::rendering
{
    IShaderBuilder& GLShaderBuilder::addVertexShader(const core::File& shaderFile) 
    {
        vertexShaderHandler_ = glCreateShader(GL_VERTEX_SHADER);
        compileShader(vertexShaderHandler_, shaderFile);
        return *this;
    }

    IShaderBuilder& GLShaderBuilder::addFragmentShader(const core::File& shaderFile) {
        fragmentShaderHandler_ = glCreateShader(GL_FRAGMENT_SHADER);
        compileShader(fragmentShaderHandler_, shaderFile);
        return *this;
    }

    IShaderBuilder& GLShaderBuilder::addVertexBuffer(std::shared_ptr<VertexBuffer>& buffer)
    {
        vertexBuffer_ = buffer;
        return *this;
    }

    std::unique_ptr<IShader> GLShaderBuilder::build() {
        unsigned int shaderProgramHandler = glCreateProgram();

        glAttachShader(shaderProgramHandler, vertexShaderHandler_);
        glAttachShader(shaderProgramHandler, fragmentShaderHandler_);
        glLinkProgram(shaderProgramHandler);

        GLint success = 0;
        glGetProgramiv(shaderProgramHandler, GL_LINK_STATUS, &success);
        if (success == GL_FALSE)
        {
            // Dealing with C-style strings so the linter will complain
            // NOLINTBEGIN
            char infoLog[512];
            glGetProgramInfoLog(shaderProgramHandler, 512, nullptr, infoLog);
            glDeleteShader(vertexShaderHandler_);
            glDeleteShader(fragmentShaderHandler_);
            glDeleteProgram(shaderProgramHandler);
            reset();
            throw std::runtime_error("Failed to link shader program: " + std::string(infoLog));
            // NOLINTEND
        }
        std::vector<unsigned int> shaderHandlers = {vertexShaderHandler_, fragmentShaderHandler_};

        std::unique_ptr<GLShader> shader = std::make_unique<GLShader>(shaderProgramHandler, shaderHandlers);
        if (vertexBuffer_)
        {
            shader->setVertexBuffer(vertexBuffer_);     
        }
        reset();
        return shader;
    }

    void GLShaderBuilder::reset() 
    {
        vertexShaderHandler_ = 0;
        fragmentShaderHandler_ = 0;
        vertexBuffer_.reset();
    }

    void GLShaderBuilder::compileShader(unsigned int shaderHandler, const core::File& shader) 
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

    void GLShader::use()
    {
        glUseProgram(shaderProgramHandler_);
        vertexBuffer_->bind();
    }

    void GLShader::render() 
    {
        use();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    GLShader::~GLShader() {
        for (auto shaderHandler : shaderHandlers_)
        {
            glDeleteShader(shaderHandler);
        }
        glDeleteProgram(shaderProgramHandler_);
    }

    GLShader::GLShader(unsigned int shaderProgramHandler, std::vector<unsigned int> shaderHandlers) 
        : shaderProgramHandler_(shaderProgramHandler), shaderHandlers_(std::move(shaderHandlers))
    {}

    void GLShader::setVertexBuffer(std::shared_ptr<VertexBuffer>& buffer) 
    {
        vertexBuffer_ = buffer;
    }

}  // namespace MBEngine::rendering
