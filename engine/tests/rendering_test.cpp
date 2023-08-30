#include "GLRenderer.h"
#include "GLWindow.h"

#include <iostream>

int main()
{
    auto window = MBEngine::GLWindow::create();
    auto renderer = MBEngine::GLRenderer::create(window);

    renderer->render();

    window->destroy();
    return 0;
}