#pragma once
#include <array>
namespace MBEngine::core
{
    template<typename T>
    struct Coord {
        T x, y, z;
    };

    template<typename T>
    struct Color {
        T r, g, b;
    };

    template<typename T>
    struct Triplet {
        union {
            Coord<T> coord;
            Color<T> color;
            std::array<T, 3> data;
        };

        Triplet() : coord({T(), T(), T()}) {}
        Triplet(T x, T y, T z) : coord({x, y, z}) {}

        T& operator[](std::size_t index) {
            return data[index];
        }

        const T& operator[](std::size_t index) const {
            return data[index];
        }
    };
    class Vector3
    {
    public:
        Triplet<float> coordinates;

        Vector3(float CoordX = 0, float CoordY = 0, float CoordZ = 0);
    };      
} // namespace MBEngine::core
