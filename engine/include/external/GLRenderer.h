#pragma once

#include "IRenderer.h"
#include "GLWindow.h"

#include <memory>

#include "gsl.h"

namespace MBEngine::rendering
{
    class GLRenderer : public IRenderer
    {
        public:
            void init() override;
            void render() override;

            static std::shared_ptr<GLRenderer> create();
            void createShaderProgram(const core::File& vertexShader, const core::File& fragmentShader) override;

            ~GLRenderer();
        private:
            unsigned int vertexShaderHandler_;
            unsigned int fragmentShaderHandler_;
            unsigned int shaderProgramHandler_;

            static void compileShader(unsigned int shaderHandler, const core::File& shader);
    };
} // namespace MBEngine::rendering
