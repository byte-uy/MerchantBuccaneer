#pragma once

#include "IWindow.h"

#include "gsl.h"
#include <memory>

namespace MBEngine
{
    class GLWindowImpl;

    class GLWindow : public IWindow
    {
        public: 
            bool shouldClose() override;
            void swapBuffers() override;
            void processInput() override;

            void init() override;
            void destroy() override;

            static std::shared_ptr<GLWindow> create();

        private:
            gsl::owner<GLWindowImpl*> window_;
    };
} // namespace MBEngine
