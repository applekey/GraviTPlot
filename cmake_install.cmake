# Install script for directory: /home/users/applekey/visit2.10.0/src/plots/GraviT

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libIGraviTPlot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libIGraviTPlot.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libIGraviTPlot.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots" TYPE SHARED_LIBRARY FILES "/home/users/applekey/visit2.10.0/src/plugins/plots/libIGraviTPlot.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libIGraviTPlot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libIGraviTPlot.so")
    file(RPATH_REMOVE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libIGraviTPlot.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libIGraviTPlot.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libGGraviTPlot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libGGraviTPlot.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libGGraviTPlot.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots" TYPE SHARED_LIBRARY FILES "/home/users/applekey/visit2.10.0/src/plugins/plots/libGGraviTPlot.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libGGraviTPlot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libGGraviTPlot.so")
    file(RPATH_REMOVE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libGGraviTPlot.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libGGraviTPlot.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libVGraviTPlot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libVGraviTPlot.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libVGraviTPlot.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots" TYPE SHARED_LIBRARY FILES "/home/users/applekey/visit2.10.0/src/plugins/plots/libVGraviTPlot.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libVGraviTPlot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libVGraviTPlot.so")
    file(RPATH_REMOVE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libVGraviTPlot.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libVGraviTPlot.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libSGraviTPlot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libSGraviTPlot.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libSGraviTPlot.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots" TYPE SHARED_LIBRARY FILES "/home/users/applekey/visit2.10.0/src/plugins/plots/libSGraviTPlot.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libSGraviTPlot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libSGraviTPlot.so")
    file(RPATH_REMOVE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libSGraviTPlot.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libSGraviTPlot.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libEGraviTPlot_ser.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libEGraviTPlot_ser.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libEGraviTPlot_ser.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots" TYPE SHARED_LIBRARY FILES "/home/users/applekey/visit2.10.0/src/plugins/plots/libEGraviTPlot_ser.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libEGraviTPlot_ser.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libEGraviTPlot_ser.so")
    file(RPATH_REMOVE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libEGraviTPlot_ser.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/2.10.0/linux-x86_64/plugins/plots/libEGraviTPlot_ser.so")
    endif()
  endif()
endif()

