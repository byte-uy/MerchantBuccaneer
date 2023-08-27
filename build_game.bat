cmake -Bgame/build -Sgame -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DINSTRUMENTED=ON -DTESTS=OFF -GNinja
cmake --build game/build -j 12 --config Debug
