# cmake -S . -B build -G Ninja 
# cmake --build build  
# ctest --test-dir build

cmake_minimum_required(VERSION 3.20)
project(OOP_Lab_1 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For VS Code error highlighting
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

function(flags target)
    if(MSVC) # MSVC - Microsoft compiler
        target_compile_options(${target} PRIVATE /Wall /Zi) #Zi - Debug info
        target_link_options(${target} PRIVATE /DEBUG)
    endif()
endfunction()

# Add library with array
add_library(array_lib src/main/array/array.cpp)
target_include_directories(array_lib PUBLIC src/main/array)
flags(array_lib)

add_executable(lab1 src/main/main.cpp)
target_link_libraries(lab1 PRIVATE array_lib)
flags(lab1)

# Download external library
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)

FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

add_executable(lab1_tests src/tests/array/test_array.cpp)
target_link_libraries(lab1_tests PRIVATE array_lib GTest::gtest_main)
flags(lab1_tests)
gtest_discover_tests(lab1_tests) # Register tests
