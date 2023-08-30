#include "Renderer.h"
#include "GLRenderer.h"

int main()
{
    MBEngine::Renderer renderer(new MBEngine::GLRenderer());
    renderer.render();
    return 0;
}