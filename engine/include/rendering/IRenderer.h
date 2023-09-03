#pragma once

#include "IWindow.h"
#include "File.h"
#include "IShader.h"

#include <string>
#include <memory>
namespace MBEngine::rendering
{
    class IRenderer
    {
        public:
            virtual void init() = 0;
            virtual void render() = 0;
            virtual void addShader(std::unique_ptr<IShader> shader) = 0;
    };
} // namespace MBEngine::rendering