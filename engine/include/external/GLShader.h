#pragma once

#include "IShader.h"

#include <vector>

namespace MBEngine::rendering
{
    class GLShader : public IShader
    {
        public:
            void render() override;
            ~GLShader() override;
            //TODO(Mati): Make this private (and friend) so its only used by GLShaderBuilder
            GLShader(unsigned int shaderProgramHandler, std::vector<unsigned int> shaderHandlers);
        private:

            unsigned int shaderProgramHandler_;
            std::vector<unsigned int> shaderHandlers_;
    };

    class GLShaderBuilder : public IShaderBuilder
    {
        public:
            IShaderBuilder& addVertexShader(const core::File& shaderFile) override;
            IShaderBuilder& addFragmentShader(const core::File& shaderFile) override;
            std::unique_ptr<IShader> build() override;
            void reset();
        private:
            unsigned int vertexShaderHandler_ = 0;
            unsigned int fragmentShaderHandler_ = 0;

            static void compileShader(unsigned int shaderHandler, const core::File& shader);
    };
} // namespace MBEngine::rendering
