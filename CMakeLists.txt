cmake_minimum_required(VERSION 3.15)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

project(ProjektNetsim VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

set(SOURCE_FILES
    src/factory.cpp
    src/helpers.cpp
    src/nodes.cpp
    src/package.cpp
    src/storage_types.cpp
    src/reports.cpp
    src/simulation.cpp
)

add_executable(MyExecutable
    main.cpp
    ${SOURCE_FILES}
)

set_target_properties(MyExecutable PROPERTIES WIN32_EXECUTABLE OFF)

target_include_directories(MyExecutable PRIVATE include)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(Dummy-test
    test/test_for_tests.cpp
    test/main_gtest.cpp
    ${SOURCE_FILES}
)

set_target_properties(Dummy-test PROPERTIES WIN32_EXECUTABLE OFF)
target_include_directories(Dummy-test PRIVATE include)
target_link_libraries(Dummy-test PRIVATE gtest gtest_main)
add_test(NAME DummyTest COMMAND Dummy-test)

add_executable(Package-test
    test/main_gtest.cpp
    test/test_package.cpp
    ${SOURCE_FILES}
)

set_target_properties(Package-test PROPERTIES WIN32_EXECUTABLE OFF)
target_include_directories(Package-test PRIVATE include)
target_link_libraries(Package-test PRIVATE gtest gtest_main)
add_test(NAME PackageTest COMMAND Package-test)

add_executable(Storage_types-test
    test/main_gtest.cpp
    test/test_storage_types.cpp
    ${SOURCE_FILES}
)

set_target_properties(Storage_types-test PROPERTIES WIN32_EXECUTABLE OFF)
target_include_directories(Storage_types-test PRIVATE include)
target_link_libraries(Storage_types-test PRIVATE gtest gtest_main)
add_test(NAME StorageTypesTest COMMAND Storage_types-test)

add_executable(Nodes-test
    test/main_gtest.cpp
    test/test_nodes.cpp
    ${SOURCE_FILES}
)

set_target_properties(Nodes-test PROPERTIES WIN32_EXECUTABLE OFF)
target_include_directories(Nodes-test PRIVATE include)
target_link_libraries(Nodes-test PRIVATE gtest gtest_main)
add_test(NAME NodesTest COMMAND Nodes-test)

add_executable(Factory-test
    test/main_gtest.cpp
    test/test_factory.cpp
    ${SOURCE_FILES}
)

set_target_properties(Factory-test PROPERTIES WIN32_EXECUTABLE OFF)
target_include_directories(Factory-test PRIVATE include)
target_link_libraries(Factory-test PRIVATE gtest gtest_main)
add_test(NAME FactoryTest COMMAND Factory-test)