#pragma once

namespace MBEngine
{
    class IWindow
    {
        public:
            virtual bool shouldClose() = 0;
            virtual void swapBuffers() = 0;

            virtual void init() = 0;
            virtual void destroy() = 0;

            int getWidth() const;
            int getHeight() const;
        protected:
            int width_;
            int height_;
    };
} // namespace MBEngine
