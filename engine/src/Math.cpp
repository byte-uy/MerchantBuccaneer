#include "Math.h"

namespace MBEngine::core
{
    // Disabling some linting rules for this constructor because it's a union so we shouldn't initialize all the members
    // Also, disabling linting rules about naming because its a well known name used in math (coordinates)
    //NOLINTNEXTLINE: (cppcoreguidelines-pro-type-member-init, hicpp-member-init, bugprone-easily-swappable-parameters, readability-identifier-length)
    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
    }    
} // namespace MBEngine::core


