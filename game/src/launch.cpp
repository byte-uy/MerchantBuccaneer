#include "benchmark.h"
#include "renderer.h"

int main()
{
    SCOPED_BENCHMARK(main);
  
    return MBEngine::Renderer::render();
}