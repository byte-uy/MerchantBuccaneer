cmake -Bengine/build -Sengine -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DINSTRUMENTED=ON -DTESTS=ON -GNinja
cmake --build engine/build -j 12 --config Debug
ctest --test-dir engine/build