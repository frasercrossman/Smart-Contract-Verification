# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/fraser/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/fraser/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LocalArrayConverted.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LocalArrayConverted.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LocalArrayConverted.dir/flags.make

CMakeFiles/LocalArrayConverted.dir/main.c.o: CMakeFiles/LocalArrayConverted.dir/flags.make
CMakeFiles/LocalArrayConverted.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LocalArrayConverted.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LocalArrayConverted.dir/main.c.o   -c /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/main.c

CMakeFiles/LocalArrayConverted.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LocalArrayConverted.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/main.c > CMakeFiles/LocalArrayConverted.dir/main.c.i

CMakeFiles/LocalArrayConverted.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LocalArrayConverted.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/main.c -o CMakeFiles/LocalArrayConverted.dir/main.c.s

CMakeFiles/LocalArrayConverted.dir/main.c.o.requires:

.PHONY : CMakeFiles/LocalArrayConverted.dir/main.c.o.requires

CMakeFiles/LocalArrayConverted.dir/main.c.o.provides: CMakeFiles/LocalArrayConverted.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/LocalArrayConverted.dir/build.make CMakeFiles/LocalArrayConverted.dir/main.c.o.provides.build
.PHONY : CMakeFiles/LocalArrayConverted.dir/main.c.o.provides

CMakeFiles/LocalArrayConverted.dir/main.c.o.provides.build: CMakeFiles/LocalArrayConverted.dir/main.c.o


CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o: CMakeFiles/LocalArrayConverted.dir/flags.make
CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o: ../contract_semantics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o   -c /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/contract_semantics.c

CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/contract_semantics.c > CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.i

CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/contract_semantics.c -o CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.s

CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o.requires:

.PHONY : CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o.requires

CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o.provides: CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o.requires
	$(MAKE) -f CMakeFiles/LocalArrayConverted.dir/build.make CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o.provides.build
.PHONY : CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o.provides

CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o.provides.build: CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o


# Object files for target LocalArrayConverted
LocalArrayConverted_OBJECTS = \
"CMakeFiles/LocalArrayConverted.dir/main.c.o" \
"CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o"

# External object files for target LocalArrayConverted
LocalArrayConverted_EXTERNAL_OBJECTS =

LocalArrayConverted: CMakeFiles/LocalArrayConverted.dir/main.c.o
LocalArrayConverted: CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o
LocalArrayConverted: CMakeFiles/LocalArrayConverted.dir/build.make
LocalArrayConverted: CMakeFiles/LocalArrayConverted.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable LocalArrayConverted"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LocalArrayConverted.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LocalArrayConverted.dir/build: LocalArrayConverted

.PHONY : CMakeFiles/LocalArrayConverted.dir/build

CMakeFiles/LocalArrayConverted.dir/requires: CMakeFiles/LocalArrayConverted.dir/main.c.o.requires
CMakeFiles/LocalArrayConverted.dir/requires: CMakeFiles/LocalArrayConverted.dir/contract_semantics.c.o.requires

.PHONY : CMakeFiles/LocalArrayConverted.dir/requires

CMakeFiles/LocalArrayConverted.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LocalArrayConverted.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LocalArrayConverted.dir/clean

CMakeFiles/LocalArrayConverted.dir/depend:
	cd /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/cmake-build-debug /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/cmake-build-debug /home/fraser/Programming/Smart-Contract-Verification/lab2/ArrayBounds/ConvertedArrayBounds_FixedRuntimeMemory/cmake-build-debug/CMakeFiles/LocalArrayConverted.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LocalArrayConverted.dir/depend

