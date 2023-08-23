cmake -Bbuild -S. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DINSTRUMENTED=ON -DTESTS=ON -GNinja
cmake --build build -j 12 --config Debug
ctest --test-dir build