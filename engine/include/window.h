#ifndef MBENGINE_WINDOW
#define MBENGINE_WINDOW

#include <memory>

namespace MBEngine
{
    class WindowImpl;

    class Window
    {
        public:
            static Window& getInstance() {
                static Window instance;
                return instance; 
            };
            
            Window(const Window&) = delete;
            void operator=(const Window&) = delete; 

            int getWidth();
            int getHeight();

            bool shouldClose();

            void swapBuffers();
        private:
            WindowImpl window_;

            int width_ = 0;
            int height_ = 0;

            Window();
            ~Window();
    };
}
#endif