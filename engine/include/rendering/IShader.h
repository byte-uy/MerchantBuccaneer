#pragma once

#include "File.h"
#include <memory>

namespace MBEngine::rendering
{
    class IShader
    {
        public:
            virtual void render() = 0;
            virtual ~IShader() = default;
    };

    class IShaderBuilder
    {
        public:
            virtual IShaderBuilder& addVertexShader(const core::File& shaderFile) = 0;
            virtual IShaderBuilder& addFragmentShader(const core::File& shaderFile) = 0;
            virtual std::unique_ptr<IShader> build() = 0;
    };


} // namespace MBEngine::rendering
