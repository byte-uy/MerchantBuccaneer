#pragma once

#include "IRenderer.h"
#include "IWindow.h"

namespace MBEngine
{
    class Renderer
    {
        public:
            Renderer(IRenderer* renderer, IWindow* window);
            ~Renderer();

            void render();
        private:
            IRenderer* renderer_;
    };
} 
