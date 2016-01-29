cmake_minimum_required(VERSION 3.4.1)
project(llvmyaml-example VERSION 0.1 LANGUAGES CXX)
find_package(LLVM REQUIRED)
llvm_map_components_to_libnames(llvm_libs support)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(llvmyaml main.cpp)
target_compile_features(llvmyaml PRIVATE cxx_generalized_initializers)
target_link_libraries(llvmyaml ${llvm_libs})

