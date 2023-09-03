#pragma once

#include "File.h"
#include "VertexBuffer.h"
#include <memory>

namespace MBEngine::rendering
{
    class IShader
    {
        public:
            virtual void render() = 0;
            virtual ~IShader() = default;
        protected:
            virtual void use() = 0;
    };

    class IShaderBuilder
    {
        public:
            virtual IShaderBuilder& addVertexShader(const core::File& shaderFile) = 0;
            virtual IShaderBuilder& addFragmentShader(const core::File& shaderFile) = 0;
            virtual IShaderBuilder& addVertexBuffer(std::shared_ptr<VertexBuffer>& buffer) = 0;
            virtual std::unique_ptr<IShader> build() = 0;
    };


} // namespace MBEngine::rendering
