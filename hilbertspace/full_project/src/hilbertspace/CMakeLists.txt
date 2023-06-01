add_library(hilbertspace_obj OBJECT QuantumChannel.cpp)
target_include_directories(hilbertspace_obj INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
set_target_properties(hilbertspace_obj PROPERTIES
    PUBLIC_HEADER src/hilbertspace/include/hilbertspace/QuantumChannel.hpp
    POSITION_INDEPENDENT_CODE 1
)

add_library(hilbertspace_shared SHARED)
target_link_libraries(hilbertspace_shared hilbertspace_obj)
add_library(hilbertspace_static STATIC)
target_link_libraries(hilbertspace_static hilbertspace_obj)

#Add this to create executable target in full_project
#add_executable(quantummessage QuantumMessage.cpp)
#target_link_libraries(quantummessage hilbertspace_static)
#EndAdd

include(Coverage)
CleanCoverage(hilbertspace_static)
include(Format)
Format(hilbertspace_static .)
include(CppCheck)
AddCppCheck(hilbertspace_obj)
include(Doxygen)
Doxygen(hilbertspace src/hilbertspace)
