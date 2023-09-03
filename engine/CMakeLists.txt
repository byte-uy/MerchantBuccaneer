cmake_minimum_required(VERSION 3.20)

project(MBEngine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(TESTS "Build the unit tests" OFF)
option(INSTRUMENTED "Build with code coverage instrumentation" OFF)
option(TIDY "Run clang-tidy" ON)

# clang-tidy configuration
if(TIDY)
    set(CMAKE_CXX_CLANG_TIDY clang-tidy;)
endif()

# Include directories
include_directories(
    "include" 
    "include/core"
    "include/rendering"
    "include/external"
    "external/assimp/include" 
    "external/catch/include"
    "external/GL/include"
    "external/glfw/include"
    "external/stb_image/include"
    "external/tracy/tracy"
)

# Debug flags
add_compile_definitions("$<$<CONFIG:DEBUG>:DEBUG_MODE>")

# Add MT flags
add_compile_definitions("$<$<CONFIG:DEBUG>:MT_DEBUG>")

# Release flags
add_compile_definitions("$<$<CONFIG:RELEASE>:RELEASE_MODE>")

add_compile_definitions("GLEW_STATIC")
# Source files
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp" "src/external/glew.c")


# External sources
file(GLOB EXTERNAL_SOURCES "external/*.cpp")

# Add instrumented flags and source files
if(INSTRUMENTED)
    add_compile_definitions("INSTRUMENTED_BENCHMARK")
    include_directories("external/tracy/tracy")
    list(APPEND EXTERNAL_SOURCES "external/tracy/TracyClient.cpp")
endif()

if(TESTS AND INSTRUMENTED)
    add_compile_definitions("TRACY_NO_EXIT")
endif()

# Now set the target-specific compile options for your internal sources only
set_property(SOURCE ${SOURCES} PROPERTY COMPILE_OPTIONS -Wall -Werror)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set_property(SOURCE ${SOURCES} PROPERTY COMPILE_OPTIONS -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(MBEngine PRIVATE /W4 /WX)
endif()

# Add external libs
link_directories(
    "external/assimp/lib" 
    "external/glfw/lib" 
)

add_library(MBEngine ${SOURCES} ${EXTERNAL_SOURCES})
find_library(ASSIMP_LIBRARY NAMES assimp-vc143-mt PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/assimp/lib")
find_library(GLFW3_LIBRARY NAMES glfw3 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/glfw/lib")

target_link_libraries(MBEngine     
    ${ASSIMP_LIBRARY}
    ${GLFW3_LIBRARY}
    opengl32)

add_custom_command(TARGET MBEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/external/GL/dll/glew32.dll
        ${CMAKE_CURRENT_BINARY_DIR}/glew32.dll)

add_custom_command(TARGET MBEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/external/assimp/dll/assimp-vc143-mt.dll
        ${CMAKE_CURRENT_BINARY_DIR}/assimp-vc143-mt.dll)

if(TESTS)
    add_executable(MBEngineTests "tests/test_test.cpp")
    target_link_libraries(MBEngineTests PRIVATE MBEngine)
    add_executable(MBEngineBenchmark "tests/benchmark_test.cpp")
    target_link_libraries(MBEngineBenchmark PRIVATE MBEngine)
    add_executable(MBRenderingTest "tests/rendering_test.cpp")
    target_link_libraries(MBRenderingTest PRIVATE MBEngine)

    enable_testing(true)
    
    add_test(NAME TestingTest COMMAND MBEngineTests)
    add_test(NAME BenchmarkTest COMMAND MBEngineBenchmark)
endif()
