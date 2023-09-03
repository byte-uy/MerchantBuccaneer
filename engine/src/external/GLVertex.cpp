#include "VertexBuffer.h"

#include "glew.h"
#include <GL/GLU.h>

namespace MBEngine::rendering
{
    VertexBuffer::VertexBuffer(const std::vector<core::Vector3>& vertexBuffer)
    {
        for (core::Vector3 vec : vertexBuffer)
        {
            // NOLINTBEGIN(cppcoreguidelines-pro-type-union-access)
            vertexBufferData_.push_back(vec.coordinates.coord.x);
            vertexBufferData_.push_back(vec.coordinates.coord.y);
            vertexBufferData_.push_back(vec.coordinates.coord.z);
            // NOLINTEND(cppcoreguidelines-pro-type-union-access)
        }
        glGenVertexArrays(1, &vertexArrayHandler_);
        glGenBuffers(1, &vertexBufferHandler_);

        glBindVertexArray(vertexArrayHandler_);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandler_);
        glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertexBufferData_.size() * sizeof(float)), vertexBufferData_.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);
    }

    void VertexBuffer::bind() const
    {
        glBindVertexArray(vertexArrayHandler_);
    }

}  // namespace MBEngine::rendering
