#include "Launch.h"


namespace MBEngine::core
{
    void Launch::init(std::shared_ptr<IWindow> window, std::shared_ptr<rendering::IRenderer> renderer)
    {
        window_ = std::move(window);
        renderer_ = std::move(renderer);
    }

    std::shared_ptr<Launch> Launch::create(std::shared_ptr<IWindow> window, std::shared_ptr<rendering::IRenderer> renderer)
    {
        auto launch = std::make_shared<Launch>();
        launch->init(std::move(window), std::move(renderer));
        return launch;
    }

    void Launch::tick()
    {
        while (!window_->shouldClose())
        {
            window_->processInput();

            renderer_->render();

            window_->swapBuffers();
        }
    }

} // namespace MBEngine::core
