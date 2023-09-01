#pragma once

#include "IWindow.h"

#include <memory>
namespace MBEngine::rendering
{
    class IRenderer
    {
        public:
            virtual void init() = 0;
            virtual void render() = 0;
    };
} // namespace MBEngine::rendering