#pragma once

#include "IWindow.h"
#include "IRenderer.h"

#include <memory>

namespace MBEngine
{
    class Launch
    {
    public:
        void init(std::shared_ptr<IWindow> window, std::shared_ptr<IRenderer> renderer);
        void tick();

        static std::shared_ptr<Launch> create(std::shared_ptr<IWindow> window, std::shared_ptr<IRenderer> renderer);
    private:
        // TODO: Probably Launch should be the owner of window and renderer, change to unique ptr
        std::shared_ptr<IWindow> window_;
        std::shared_ptr<IRenderer> renderer_;
    };
} // namespace MBEngine
