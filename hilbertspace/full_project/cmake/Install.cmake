include(GNUInstallDirs)
# HilbertSpace library
install(TARGETS hilbertspace_obj hilbertspace_shared hilbertspace_static
  EXPORT HilbertSpaceLibrary
  ARCHIVE COMPONENT development
  LIBRARY COMPONENT runtime
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/hilbertspace
    COMPONENT runtime
)

if (UNIX)
  install(CODE "execute_process(COMMAND ldconfig)"
          COMPONENT runtime
  )
endif()

install(EXPORT HilbertSpaceLibrary
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/hilbertspace/cmake
  #NAMESPACE HilbertSpace::
  COMPONENT runtime
)

install(FILES "HilbertSpaceConfig.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/hilbertspace/cmake
)

# CalcConsole runtime
#[[install(TARGETS calc_console
  RUNTIME COMPONENT runtime
)]]

# CPack configuration
set(CPACK_PACKAGE_VENDOR "Rabometrics")
set(CPACK_PACKAGE_CONTACT "rabometrics@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION "Hilbert Space")
include(CPack)
