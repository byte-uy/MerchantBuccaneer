#pragma once

#include "RendererAPI.h"

#include <memory>

#include "gsl.h"

namespace MBEngine
{
    class GLWindow;

    class GLRenderer : public RendererAPI
    {
        public:
            void init() override;
            void render() override;
            void destroy() override;
        private:
            gsl::owner<GLWindow*> window_;
    };
}