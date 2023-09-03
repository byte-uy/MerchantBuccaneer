#pragma once

#include "MBMath.h"

#include <vector>

namespace MBEngine::rendering
{
    class Vertex 
    {
    public:
        void createVertexBuffer(const std::vector<core::Vector3>& vertexBuffer);
    private:
        std::vector<float> vertexBufferData_;

        unsigned int vertexBufferHandler_;

    };
} // namespace MBEngine::rendering
