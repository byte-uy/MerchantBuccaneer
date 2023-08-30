#include "Renderer.h"
#include "RendererAPI.h"

namespace MBEngine 
{
    Renderer::Renderer(RendererAPI* rendererAPI) 
        : rendererAPI_(rendererAPI)
    {
        rendererAPI_->init();
    }

    Renderer::~Renderer()
    {
        rendererAPI_->destroy();
    }

    void Renderer::render()
    {
        rendererAPI_->render();
    }

} // namespace MBEngine