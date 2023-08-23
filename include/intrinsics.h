#ifndef CCRAFT_INTRINSICS
#define CCRAFT_INTRINSICS

#if defined(__x86_64__) || defined(_M_X64)
#   ifdef _MSC_VER
#       include <intrin.h>
#   else
#       include <x86intrin.h>
#   endif
#endif

namespace CCraft{

inline unsigned long long readTimeStampCounter()
{
#if defined(__x86_64__) || defined(_M_X64)
    return __rdtsc();
#else
    // Not yet implemented
    return -1;
#endif
}

}

#endif //__CCRAFT_INTRINSICS