cmake_minimum_required(VERSION 3.14)
project(Game)

# Set policy to avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP
cmake_policy(SET CMP0135 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/executables)

# Include GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(src/BaseGame)
add_subdirectory(src/PigDices)
add_subdirectory(src/PigDices_interface)
add_subdirectory(src/Poker)
add_subdirectory(src/Poker_interface)
add_subdirectory(src/War)
add_subdirectory(src/War_interface)
add_subdirectory(tests/basetests)
add_subdirectory(tests/dicestests)
add_subdirectory(tests/wartests)
add_subdirectory(tests/pokertests)