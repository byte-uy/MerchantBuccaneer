#pragma once

#include "IWindow.h"
#include "File.h"

#include <string>
#include <memory>
namespace MBEngine::rendering
{
    class IRenderer
    {
        public:
            virtual void init() = 0;
            virtual void render() = 0;
            virtual void createShaderProgram(const core::File& vertexShader, const core::File& fragmentShader) = 0;
    };
} // namespace MBEngine::rendering