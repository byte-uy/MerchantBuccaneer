#ifndef CCRAFT_BENCHMARK
#define CCRAFT_BENCHMARK

#if defined(RELEASE_MODE)
#   define SCOPED_BENCHMARK(name) 
#   define FRAME_END
#elif defined(INSTRUMENTED_BENCHMARK)
#   include "Tracy.hpp"
#   define SCOPED_BENCHMARK(name) ZoneScopedN(#name)
#   define FRAME_END FrameMark
#else
#   include "intrinsics.h"
#   include <string>

#   define SCOPED_BENCHMARK(name) CCraft::Benchmark(#name);
#   define FRAME_END 

namespace CCraft {
class Benchmark 
{
public:
    Benchmark(const char* scope_name);
    ~Benchmark();
private:
    std::string scope_name_;
    unsigned long long start_time_;
};
}

#endif

#endif //CCRAFT_BENCHMARK
