#include "Vertex.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
#include "glew.h"
#pragma clang diagnostic pop
#include <GL/GLU.h>

namespace MBEngine::rendering
{
    void Vertex::createVertexBuffer(const std::vector<core::Vector3>& vertexBuffer)
    {
        vertexBufferData_.resize(vertexBuffer.size() * 3);
        for (core::Vector3 vec : vertexBuffer)
        {
            // NOLINTBEGIN(cppcoreguidelines-pro-type-union-access)
            vertexBufferData_.push_back(vec.coordinates.coord.x);
            vertexBufferData_.push_back(vec.coordinates.coord.y);
            vertexBufferData_.push_back(vec.coordinates.coord.z);
            // NOLINTEND(cppcoreguidelines-pro-type-union-access)
        }
        glGenBuffers(1, &vertexBufferHandler_);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandler_);
        glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertexBufferData_.size() * sizeof(float)), vertexBufferData_.data(), GL_STATIC_DRAW);
    }
} // namespace MBEngine::rendering
