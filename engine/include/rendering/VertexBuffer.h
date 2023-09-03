#pragma once

#include "MBMath.h"

#include <vector>

namespace MBEngine::rendering
{
    class VertexBuffer
    {
    public:
        VertexBuffer() = default;
        explicit VertexBuffer(const std::vector<core::Vector3>& vertexBuffer);
        void bind() const;
    private:
        std::vector<float> vertexBufferData_;

        unsigned int vertexBufferHandler_{};
        unsigned int vertexArrayHandler_{};
    };
} // namespace MBEngine::rendering
