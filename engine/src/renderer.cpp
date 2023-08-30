#include "Renderer.h"
#include "IRenderer.h"

namespace MBEngine 
{
    Renderer::Renderer(IRenderer* renderer, IWindow* window) 
        : renderer_(renderer)
    {
        renderer_->init(window);
    }

    Renderer::~Renderer()
    {
        renderer_->destroy();
    }

    void Renderer::render()
    {
        renderer_->render();
    }

} // namespace MBEngine