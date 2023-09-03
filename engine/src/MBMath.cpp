#include "MBMath.h"

namespace MBEngine::core
{
    Vector3::Vector3(float CoordX /*= 0*/, float CoordY /*= 0*/, float CoordZ /*= 0*/) 
    {
        // In this case we actually want to use the union to access in different ways the same memory
        // NOLINTBEGIN(cppcoreguidelines-pro-type-union-access)
        coordinates.coord.x = CoordX;
        coordinates.coord.y = CoordY;
        coordinates.coord.z = CoordZ;
        // NOLINTEND(cppcoreguidelines-pro-type-union-access)
    }    
} // namespace MBEngine::core


