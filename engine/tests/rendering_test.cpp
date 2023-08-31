#include "GLRenderer.h"
#include "GLWindow.h"
#include "Launch.h"

#include <iostream>

int main()
{
    auto window = MBEngine::GLWindow::create();
    auto renderer = MBEngine::GLRenderer::create();
    auto launch = MBEngine::Launch::create(window, renderer);

    launch->tick();

    window->destroy();
    return 0;
}