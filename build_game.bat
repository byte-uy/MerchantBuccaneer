cmake -Bgame/build -Sgame -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DINSTRUMENTED=ON -DTESTS=OFF -GNinja
cmake --build game/build --config Debug
