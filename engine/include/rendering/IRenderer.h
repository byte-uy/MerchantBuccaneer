#pragma once

#include "IWindow.h"

#include <memory>
namespace MBEngine
{
    class IRenderer
    {
        public:
            virtual void init() = 0;
            virtual void render() = 0;
    };
}