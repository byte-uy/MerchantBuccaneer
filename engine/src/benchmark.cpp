#include "benchmark.h"

#if !defined(RELEASE_MODE) && !defined(INSTRUMENTED_BENCHMARK)

#include <iostream>
namespace MBEngine
{
    Benchmark::Benchmark(const char* scope_name) : scope_name_{scope_name}
    {
        start_time_ = readTimeStampCounter();
    }

    Benchmark::~Benchmark()
    {
        const unsigned long long delta = readTimeStampCounter() - this->start_time_;
        std::cout << "[Benchmark] " << this->scope_name_ << " took " << delta << " cycles." << std::endl;
    }
}

#endif