cmake_minimum_required(VERSION 3.4.1)
project(llvmyaml VERSION 0.1 LANGUAGES CXX)
find_package(LLVM REQUIRED)
llvm_map_components_to_libnames(llvm_libs support)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(llvmyaml main.cpp)
# LLVM is using C++11, but apparently does not set LLVM_DEFINITIONS correctly.
target_compile_features(llvmyaml PRIVATE cxx_auto_type cxx_range_for)

target_link_libraries(llvmyaml ${llvm_libs})


