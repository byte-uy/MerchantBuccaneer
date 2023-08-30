#pragma once

#include "IRenderer.h"
#include "GLWindow.h"

#include <memory>

#include "gsl.h"

namespace MBEngine
{
    class GLRenderer : public IRenderer
    {
        public:
            void init(std::shared_ptr<IWindow> window) override;
            void render() override;

            static std::shared_ptr<GLRenderer> create(const std::shared_ptr<GLWindow>& window);
        private:
            std::shared_ptr<GLWindow> window_;
    };
}