#pragma once
#include <array>

namespace MBEngine::core
{
    class Vector3
    {
    public:
        union {
            struct { float x, y, z; };
            struct { float r, g, b; };
            std::array<float, 3> data;
        };
        Vector3(float x, float y, float z);
    };      
} // namespace MBEngine::core
