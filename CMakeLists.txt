cmake_minimum_required(VERSION 3.12)
project(WaveletToolkit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ------------------------------------------------------------------------------
# Include directories
# ------------------------------------------------------------------------------

include_directories(include)

# ------------------------------------------------------------------------------
# Source files
# ------------------------------------------------------------------------------

file(GLOB_RECURSE LIB_SOURCES src/*.cpp)
file(GLOB_RECURSE LIB_HEADERS include/wavelet/*.hpp)

# ------------------------------------------------------------------------------
# Wavelet Library
# ------------------------------------------------------------------------------

add_library(wavelet_toolkit STATIC ${LIB_SOURCES} ${LIB_HEADERS})

# ------------------------------------------------------------------------------
# Examples (executables using the library)
# ------------------------------------------------------------------------------

file(GLOB EXAMPLE_SOURCES examples/*.cpp)

foreach(example_file ${EXAMPLE_SOURCES})
    get_filename_component(example_name ${example_file} NAME_WE)
    add_executable(${example_name} ${example_file})
    target_link_libraries(${example_name} wavelet_toolkit)
endforeach()

# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------

file(GLOB TEST_SOURCES tests/*.cpp)

add_executable(test_runner ${TEST_SOURCES})
target_link_libraries(test_runner wavelet_toolkit)
