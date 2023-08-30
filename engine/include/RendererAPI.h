#pragma once

namespace MBEngine
{
    class RendererAPI
    {
        public:
            virtual ~RendererAPI() = default;
            virtual void init() = 0;
            virtual void render() = 0;
            virtual void destroy() = 0;
    };
}