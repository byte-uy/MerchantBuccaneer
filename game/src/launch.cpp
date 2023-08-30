#include "Benchmark.h"
#include "Renderer.h"
#include "external/GLRenderer.h"

int main()
{
    SCOPED_BENCHMARK(main);
    MBEngine::Renderer renderer(new MBEngine::GLRenderer());
    renderer.render();
    return 0;
}
