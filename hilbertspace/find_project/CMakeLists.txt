cmake_minimum_required(VERSION 3.20.0)
project(FindHilbertSpacePackage CXX)

find_package(HilbertSpace REQUIRED)

include(CMakePrintHelpers)
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message("HILBERTSPACE_FOUND: ${HilbertSpace_FOUND}")
#[[cmake_print_properties(TARGETS "HilbertSpace::hilbertspace_shared" PROPERTIES
  IMPORTED_CONFIGURATIONS
  INCLUDE_DIRECTORIES
  INTERFACE_INCLUDE_DIRECTORIES
)]]
cmake_print_properties(TARGETS "hilbertspace_shared" PROPERTIES
  IMPORTED_CONFIGURATIONS
  INCLUDE_DIRECTORIES
  INTERFACE_INCLUDE_DIRECTORIES
)

add_executable(test main_QuantumMessage.cpp)
#target_link_libraries(test NewtonianSpace::newtonianspace_shared)
target_link_libraries(test hilbertspace_shared)
