# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zal/jack.lin.code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zal/jack.lin.code/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/app/test_main.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/app/test_main.c.o: ../app/test_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zal/jack.lin.code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/app/test_main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/app/test_main.c.o   -c /home/zal/jack.lin.code/app/test_main.c

CMakeFiles/main.dir/app/test_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/app/test_main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zal/jack.lin.code/app/test_main.c > CMakeFiles/main.dir/app/test_main.c.i

CMakeFiles/main.dir/app/test_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/app/test_main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zal/jack.lin.code/app/test_main.c -o CMakeFiles/main.dir/app/test_main.c.s

CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.o: ../domain/socket_wrapper/src/socket_wrapper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zal/jack.lin.code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.o   -c /home/zal/jack.lin.code/domain/socket_wrapper/src/socket_wrapper.c

CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zal/jack.lin.code/domain/socket_wrapper/src/socket_wrapper.c > CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.i

CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zal/jack.lin.code/domain/socket_wrapper/src/socket_wrapper.c -o CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.s

CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.o: ../common/data_struct/src/circ_queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zal/jack.lin.code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.o   -c /home/zal/jack.lin.code/common/data_struct/src/circ_queue.c

CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zal/jack.lin.code/common/data_struct/src/circ_queue.c > CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.i

CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zal/jack.lin.code/common/data_struct/src/circ_queue.c -o CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.s

CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.o: ../domain/data_struct_test/src/data_struct_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zal/jack.lin.code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.o   -c /home/zal/jack.lin.code/domain/data_struct_test/src/data_struct_test.c

CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zal/jack.lin.code/domain/data_struct_test/src/data_struct_test.c > CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.i

CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zal/jack.lin.code/domain/data_struct_test/src/data_struct_test.c -o CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/app/test_main.c.o" \
"CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.o" \
"CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.o" \
"CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

../bin/main: CMakeFiles/main.dir/app/test_main.c.o
../bin/main: CMakeFiles/main.dir/domain/socket_wrapper/src/socket_wrapper.c.o
../bin/main: CMakeFiles/main.dir/common/data_struct/src/circ_queue.c.o
../bin/main: CMakeFiles/main.dir/domain/data_struct_test/src/data_struct_test.c.o
../bin/main: CMakeFiles/main.dir/build.make
../bin/main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zal/jack.lin.code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ../bin/main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: ../bin/main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/zal/jack.lin.code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zal/jack.lin.code /home/zal/jack.lin.code /home/zal/jack.lin.code/build /home/zal/jack.lin.code/build /home/zal/jack.lin.code/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

