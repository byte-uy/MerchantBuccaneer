#pragma once

#include "IRenderer.h"
#include "GLWindow.h"
#include "GLShader.h"

#include <vector>
#include <memory>

#include "gsl.h"

namespace MBEngine::rendering
{
    class GLRenderer : public IRenderer
    {
        public:
            void init() override;
            void render() override;

            void addShader(std::unique_ptr<IShader> shader) override;

            static std::shared_ptr<GLRenderer> create();
        private:
            std::vector<std::unique_ptr<GLShader>> shaders_;
    };
} // namespace MBEngine::rendering
