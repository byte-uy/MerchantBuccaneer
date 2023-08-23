#include "benchmark.h"
#include <iostream>

void stressTestName()
{
    SCOPED_BENCHMARK(stressTest);
    
    const int large_number = 100000;

    for (size_t i = 0; i < large_number; i++)
    {
    }

}
 
auto main() -> int {
    stressTestName();
    return 0;
}