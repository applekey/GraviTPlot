# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/users/applekey/visit2.10.0/visit/cmake/3.0.2/linux-x86_64_icc/bin/cmake

# The command to remove a file.
RM = /home/users/applekey/visit2.10.0/visit/cmake/3.0.2/linux-x86_64_icc/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/users/applekey/visit2.10.0/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/users/applekey/visit2.10.0/src

# Include any dependencies generated for this target.
include plots/GraviT/CMakeFiles/IGraviTPlot.dir/depend.make

# Include the progress variables for this target.
include plots/GraviT/CMakeFiles/IGraviTPlot.dir/progress.make

# Include the compile flags for this target's objects.
include plots/GraviT/CMakeFiles/IGraviTPlot.dir/flags.make

plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o: plots/GraviT/GraviTPluginInfo.C
	$(CMAKE_COMMAND) -E cmake_progress_report /home/users/applekey/visit2.10.0/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o"
	cd /home/users/applekey/visit2.10.0/src/plots/GraviT && /home/users/applekey/intel/compilers_and_libraries/linux/bin/intel64/icpc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o -c /home/users/applekey/visit2.10.0/src/plots/GraviT/GraviTPluginInfo.C

plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.i"
	cd /home/users/applekey/visit2.10.0/src/plots/GraviT && /home/users/applekey/intel/compilers_and_libraries/linux/bin/intel64/icpc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/users/applekey/visit2.10.0/src/plots/GraviT/GraviTPluginInfo.C > CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.i

plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.s"
	cd /home/users/applekey/visit2.10.0/src/plots/GraviT && /home/users/applekey/intel/compilers_and_libraries/linux/bin/intel64/icpc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/users/applekey/visit2.10.0/src/plots/GraviT/GraviTPluginInfo.C -o CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.s

plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o.requires:
.PHONY : plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o.requires

plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o.provides: plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o.requires
	$(MAKE) -f plots/GraviT/CMakeFiles/IGraviTPlot.dir/build.make plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o.provides.build
.PHONY : plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o.provides

plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o.provides.build: plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o

# Object files for target IGraviTPlot
IGraviTPlot_OBJECTS = \
"CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o"

# External object files for target IGraviTPlot
IGraviTPlot_EXTERNAL_OBJECTS =

plugins/plots/libIGraviTPlot.so: plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o
plugins/plots/libIGraviTPlot.so: lib/libvisitcommon.so
plugins/plots/libIGraviTPlot.so: plots/GraviT/CMakeFiles/IGraviTPlot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../plugins/plots/libIGraviTPlot.so"
	cd /home/users/applekey/visit2.10.0/src/plots/GraviT && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IGraviTPlot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plots/GraviT/CMakeFiles/IGraviTPlot.dir/build: plugins/plots/libIGraviTPlot.so
.PHONY : plots/GraviT/CMakeFiles/IGraviTPlot.dir/build

plots/GraviT/CMakeFiles/IGraviTPlot.dir/requires: plots/GraviT/CMakeFiles/IGraviTPlot.dir/GraviTPluginInfo.C.o.requires
.PHONY : plots/GraviT/CMakeFiles/IGraviTPlot.dir/requires

plots/GraviT/CMakeFiles/IGraviTPlot.dir/clean:
	cd /home/users/applekey/visit2.10.0/src/plots/GraviT && $(CMAKE_COMMAND) -P CMakeFiles/IGraviTPlot.dir/cmake_clean.cmake
.PHONY : plots/GraviT/CMakeFiles/IGraviTPlot.dir/clean

plots/GraviT/CMakeFiles/IGraviTPlot.dir/depend:
	cd /home/users/applekey/visit2.10.0/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/users/applekey/visit2.10.0/src /home/users/applekey/visit2.10.0/src/plots/GraviT /home/users/applekey/visit2.10.0/src /home/users/applekey/visit2.10.0/src/plots/GraviT /home/users/applekey/visit2.10.0/src/plots/GraviT/CMakeFiles/IGraviTPlot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plots/GraviT/CMakeFiles/IGraviTPlot.dir/depend

