#include "GLRenderer.h"
#include "GLWindow.h"
#include "Launch.h"

#include <iostream>

int main()
{
    auto window = MBEngine::core::GLWindow::create();
    auto renderer = MBEngine::rendering::GLRenderer::create();
    auto launch = MBEngine::core::Launch::create(window, renderer);

    launch->tick();

    window->destroy();
    return 0;
}