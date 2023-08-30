#pragma once

#include "IWindow.h"

#include "gsl.h"

namespace MBEngine
{
    class GLWindowImpl;

    class GLWindow : public IWindow
    {
        public: 
            bool shouldClose() override;
            void swapBuffers() override;
            
            void init() override;
            void destroy() override;
        private:

            gsl::owner<GLWindowImpl*> window_;
    };
} // namespace MBEngine
