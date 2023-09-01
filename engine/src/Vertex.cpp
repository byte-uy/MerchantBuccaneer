#include "Vertex.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
#include "glew.h"
#pragma clang diagnostic pop
#include <GL/GLU.h>

namespace MBEngine::rendering
{
    void Vertex::createVertexBuffer(std::vector<core::Vector3> vertexBuffer)
    {
        vertexBufferData_.resize(vertexBuffer.size() * 3);
        for (Vector3 v : vertexBuffer)
        {
            vertexBuffer.emplace_back(v.point_.data);
        }
        glGenBuffers(1, &vertexBufferHandler_);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandler_);
        glBufferData(GL_ARRAY_BUFFER, vertexBufferData_.size() * sizeof(float), vertexBufferData_.data(), GL_STATIC_DRAW);
    }
} // namespace MBEngine::rendering
