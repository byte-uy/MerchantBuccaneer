#pragma once

#include "IWindow.h"

namespace MBEngine
{
    class IRenderer
    {
        public:
            virtual ~IRenderer() = default;
            virtual void init(IWindow* Window) = 0;
            virtual void render() = 0;
            virtual void destroy() = 0;
    };
}