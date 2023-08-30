#pragma once

#include "RendererAPI.h"

namespace MBEngine
{
    class Renderer
    {
        public:
            Renderer(RendererAPI* rendererAPI);
            ~Renderer();

            void render();
        private:
            RendererAPI* rendererAPI_;
    };
} 
