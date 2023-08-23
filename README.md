# MerchantBuccaneer

## Windows Preconditions
```
winget install Kitware.CMake
winget install Ninja-build.Ninja
```

## Configure build
`cmake -Bbuild -S. [-DCMAKE_EXPORT_COMPILE_COMMANDS=ON] [-DINSTRUMENTED=ON] [-DTESTS=ON] [-DTIDY=OFF] -GNinja`

- Instrumented option compiles the library with instrumentation (currently tracy).
- Tests option compiles the tests.

## Build
`cmake --build build -j 12 [--config Debug/Release/RelWithDebInfo]`

- Debug don't optimize, has build symbols and defines `DEBUG_MODE`
- Release is optimized and defines `RELEASE_MODE`


## Run tests
`ctest --test-dir build`