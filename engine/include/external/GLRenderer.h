#pragma once

#include "IRenderer.h"
#include "GLWindow.h"

#include <memory>

#include "gsl.h"

namespace MBEngine::rendering
{
    class GLRenderer : public IRenderer
    {
        public:
            void init() override;
            void render() override;

            static std::shared_ptr<GLRenderer> create();
    };
} // namespace MBEngine::rendering
