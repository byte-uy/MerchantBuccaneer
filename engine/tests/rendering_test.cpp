#include "Renderer.h"
#include "GLRenderer.h"
#include "GLWindow.h"

int main()
{
    std::shared_ptr<MBEngine::GLWindow> window = std::make_shared<MBEngine::GLWindow>();
    window->init();
    MBEngine::Renderer renderer(new MBEngine::GLRenderer(), window.get());
    renderer.render();
    return 0;
}