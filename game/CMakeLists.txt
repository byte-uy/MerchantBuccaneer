cmake_minimum_required(VERSION 3.20)

project(MerchantBuccaneer)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(TIDY "Run clang-tidy" ON)

# clang-tidy configuration
if(TIDY)
    set(CMAKE_CXX_CLANG_TIDY clang-tidy;)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../engine)

# Include directories
include_directories(
    "include" 
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

add_executable(MerchantBuccaneer ${SOURCES})
target_link_libraries(MerchantBuccaneer MBEngine)

add_custom_command(TARGET GameExecutable POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/GL/dll/glew32.dll
        ${CMAKE_CURRENT_BINARY_DIR}/glew32.dll)

add_custom_command(TARGET GameExecutable POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/../engine/external/assimp/dll/assimp-vc143-mt.dll
        ${CMAKE_CURRENT_BINARY_DIR}/assimp-vc143-mt.dll)
