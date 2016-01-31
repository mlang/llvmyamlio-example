cmake_minimum_required(VERSION 3.4.1)
project(llvmyaml-example VERSION 0.1 LANGUAGES CXX)
find_package(LLVM REQUIRED)
set_property(TARGET LLVMSupport PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${LLVM_INCLUDE_DIRS}")
set_property(TARGET LLVMSupport PROPERTY IMPORTED_LINK_INTERFACE_LANGUAGES CXX)

add_executable(llvmyaml main.cpp)
target_compile_features(llvmyaml PRIVATE cxx_generalized_initializers)
target_link_libraries(llvmyaml LLVMSupport)

