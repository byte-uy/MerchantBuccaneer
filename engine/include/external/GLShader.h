#pragma once

#include "IShader.h"

#include <vector>

namespace MBEngine::rendering
{
    class GLShader : public IShader
    {
        public:
            virtual void render() override;

            ~GLShader() override;

            //TODO(Mati): Make this private (and friend) so its only used by GLShaderBuilder
            GLShader(unsigned int shaderProgramHandler, std::vector<unsigned int> shaderHandlers);

            void setVertexBuffer(std::shared_ptr<VertexBuffer>& buffer);
        protected:
            void use() override;
        private:
            unsigned int shaderProgramHandler_;
            std::vector<unsigned int> shaderHandlers_;
            std::shared_ptr<VertexBuffer> vertexBuffer_;
    };

    class GLShaderBuilder : public IShaderBuilder
    {
        public:
            IShaderBuilder& addVertexShader(const core::File& shaderFile) override;
            IShaderBuilder& addFragmentShader(const core::File& shaderFile) override;
            IShaderBuilder& addVertexBuffer(std::shared_ptr<VertexBuffer>& buffer) override;
            std::unique_ptr<IShader> build() override;
            void reset();
        private:
            unsigned int vertexShaderHandler_ = 0;
            unsigned int fragmentShaderHandler_ = 0;
            std::shared_ptr<VertexBuffer> vertexBuffer_;

            static void compileShader(unsigned int shaderHandler, const core::File& shader);
    };
} // namespace MBEngine::rendering
