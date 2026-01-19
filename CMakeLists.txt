cmake_minimum_required(VERSION 3.15)

project(ProjektNetsim VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    src/factory.cpp
    src/helpers.cpp
    src/nodes.cpp
    src/package.cpp
    src/storage_types.cpp
)

add_executable(MyExecutable
    main.cpp
    ${SOURCE_FILES}
)

target_include_directories(MyExecutable PRIVATE include)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(MyExecutable-test
    test/tests.cpp
    test/main_gtest.cpp
    ${SOURCE_FILES}
)

target_include_directories(MyExecutable-test PRIVATE include)

target_link_libraries(MyExecutable-test PRIVATE gtest gtest_main)