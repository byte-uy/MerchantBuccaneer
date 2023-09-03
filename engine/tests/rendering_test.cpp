#include "File.h"
#include "GLShader.h"
#include "GLRenderer.h"
#include "GLWindow.h"
#include "VertexBuffer.h"
#include "Launch.h"

#include <iostream>


std::string parseDirectory(const std::string& path)
{
    auto lastSlash = path.find_last_of("/\\");
    return path.substr(0, lastSlash);
}

int main()
{
    try 
    {
        auto window = MBEngine::core::GLWindow::create();
        auto renderer = MBEngine::rendering::GLRenderer::create();
        auto launch = MBEngine::core::Launch::create(window, renderer);

        // magic number
        //NOLINTBEGIN
        std::vector<MBEngine::core::Vector3> vertices =
        {
            {0.5f,  0.5f, 0.0f},  
            {0.5f, -0.5f, 0.0f},  
            {-0.5f,  0.5f, 0.0f},
            {0.5f, -0.5f, 0.0f},
            {-0.5f, -0.5f, 0.0f},
            {-0.5f,  0.5f, 0.0f}   
        };
        //NOLINTEND

        auto vertexBuffer = std::make_shared<MBEngine::rendering::VertexBuffer>(vertices);

        auto shader = MBEngine::rendering::GLShaderBuilder()
            .addVertexShader(MBEngine::core::File(parseDirectory(__FILE__) + "/basic_shader.vs"))
            .addFragmentShader(MBEngine::core::File(parseDirectory(__FILE__) + "/basic_shader.fs"))
            .addVertexBuffer(vertexBuffer)
            .build();

        renderer->addShader(std::move(shader));

        launch->tick();

        window->destroy();
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}