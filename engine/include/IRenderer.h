#pragma once

#include "IWindow.h"

#include <memory>
namespace MBEngine
{
    class IRenderer
    {
        public:
            virtual void init(std::shared_ptr<IWindow> Window) = 0;
            virtual void render() = 0;
    };
}