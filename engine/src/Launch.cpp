#include "Launch.h"
#include "GLRenderer.h"
#include "Renderer.h"

#include <memory>

void MBEngine::Launch::launch()
{
  std::unique_ptr<MBEngine::GLRenderer> glRenderer = std::make_unique<MBEngine::GLRenderer>();

  MBEngine::Renderer renderer(glRenderer.get());
  renderer.render();
}