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
            void init(IWindow* window) override;
            void render() override;
            void destroy() override;
        private:
            std::shared_ptr<GLWindow> window_;
    };
}