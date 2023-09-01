#pragma once

namespace MBEngine::core
{
    class IWindow
    {
        public:
            virtual bool shouldClose() = 0;
            virtual void swapBuffers() = 0;
            virtual void processInput() = 0;
            
            virtual void init() = 0;
            virtual void destroy() = 0;
    };
} // namespace MBEngine::core
