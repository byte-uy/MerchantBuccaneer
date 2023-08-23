cmake_minimum_required(VERSION 3.20)

project(MerchantBuccaneer)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(TIDY "Run clang-tidy" ON)
option(INSTRUMENTED "Build with code coverage instrumentation" OFF)


# clang-tidy configuration
if(TIDY)
    set(CMAKE_CXX_CLANG_TIDY clang-tidy;)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../engine ${CMAKE_CURRENT_BINARY_DIR}/../../engine/build)

# Include directories
include_directories(
    "include" 
    "../engine/include"
    "../engine/external/tracy/tracy"
)

# Debug flags
add_compile_definitions("$<$<CONFIG:DEBUG>:DEBUG_MODE>")

# Add MT flags
add_compile_definitions("$<$<CONFIG:DEBUG>:MT_DEBUG>")

# Release flags
add_compile_definitions("$<$<CONFIG:RELEASE>:RELEASE_MODE>")

# Source files
file(GLOB SOURCES "src/*.cpp")

# Now set the target-specific compile options for your internal sources only
set_property(SOURCE ${SOURCES} PROPERTY COMPILE_OPTIONS -Wall -Werror)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set_property(SOURCE ${SOURCES} PROPERTY COMPILE_OPTIONS -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(MerchantBuccaneer PRIVATE /W4 /WX)
endif()

add_compile_definitions("GLEW_BUILD")

if(INSTRUMENTED)
    add_compile_definitions("INSTRUMENTED_BENCHMARK")
endif()

add_executable(MerchantBuccaneer ${SOURCES})

find_library(ASSIMP_LIBRARY NAMES assimp-vc143-mt PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/assimp/lib")
find_library(GLFW3_LIBRARY NAMES glfw3 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/glfw/lib")
find_library(GLEW32_LIBRARY NAMES glew32 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/GL/lib")

target_link_libraries(MerchantBuccaneer 
    PRIVATE MBEngine    
    ${ASSIMP_LIBRARY}
    ${GLFW3_LIBRARY}
    ${GLEW32_LIBRARY}
    opengl32)

add_custom_command(TARGET MerchantBuccaneer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/GL/dll/glew32.dll
        ${CMAKE_CURRENT_BINARY_DIR}/glew32.dll)

add_custom_command(TARGET MerchantBuccaneer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/assimp/dll/assimp-vc143-mt.dll
        ${CMAKE_CURRENT_BINARY_DIR}/assimp-vc143-mt.dll)
