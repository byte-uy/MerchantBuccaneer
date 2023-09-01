#pragma once

#if defined(__x86_64__) || defined(_M_X64)
#   ifdef _MSC_VER
#       include <intrin.h>
#   else
#       include <x86intrin.h>
#   endif
#endif

namespace MBEngine::core {
    inline unsigned long long readTimeStampCounter()
    {
    #if defined(__x86_64__) || defined(_M_X64)
        return __rdtsc();
    #else
        // Not yet implemented
        return -1;
    #endif
    }

} // namespace MBEngine::core

