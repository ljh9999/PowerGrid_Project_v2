# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build

# Include any dependencies generated for this target.
include CMakeFiles/yolov5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/yolov5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yolov5.dir/flags.make

CMakeFiles/yolov5.dir/Yolov5.cpp.o: CMakeFiles/yolov5.dir/flags.make
CMakeFiles/yolov5.dir/Yolov5.cpp.o: ../Yolov5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/yolov5.dir/Yolov5.cpp.o"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yolov5.dir/Yolov5.cpp.o -c /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/Yolov5.cpp

CMakeFiles/yolov5.dir/Yolov5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yolov5.dir/Yolov5.cpp.i"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/Yolov5.cpp > CMakeFiles/yolov5.dir/Yolov5.cpp.i

CMakeFiles/yolov5.dir/Yolov5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yolov5.dir/Yolov5.cpp.s"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/Yolov5.cpp -o CMakeFiles/yolov5.dir/Yolov5.cpp.s

CMakeFiles/yolov5.dir/Yolov5.cpp.o.requires:

.PHONY : CMakeFiles/yolov5.dir/Yolov5.cpp.o.requires

CMakeFiles/yolov5.dir/Yolov5.cpp.o.provides: CMakeFiles/yolov5.dir/Yolov5.cpp.o.requires
	$(MAKE) -f CMakeFiles/yolov5.dir/build.make CMakeFiles/yolov5.dir/Yolov5.cpp.o.provides.build
.PHONY : CMakeFiles/yolov5.dir/Yolov5.cpp.o.provides

CMakeFiles/yolov5.dir/Yolov5.cpp.o.provides.build: CMakeFiles/yolov5.dir/Yolov5.cpp.o


CMakeFiles/yolov5.dir/ImageResize.cpp.o: CMakeFiles/yolov5.dir/flags.make
CMakeFiles/yolov5.dir/ImageResize.cpp.o: ../ImageResize.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/yolov5.dir/ImageResize.cpp.o"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yolov5.dir/ImageResize.cpp.o -c /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/ImageResize.cpp

CMakeFiles/yolov5.dir/ImageResize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yolov5.dir/ImageResize.cpp.i"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/ImageResize.cpp > CMakeFiles/yolov5.dir/ImageResize.cpp.i

CMakeFiles/yolov5.dir/ImageResize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yolov5.dir/ImageResize.cpp.s"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/ImageResize.cpp -o CMakeFiles/yolov5.dir/ImageResize.cpp.s

CMakeFiles/yolov5.dir/ImageResize.cpp.o.requires:

.PHONY : CMakeFiles/yolov5.dir/ImageResize.cpp.o.requires

CMakeFiles/yolov5.dir/ImageResize.cpp.o.provides: CMakeFiles/yolov5.dir/ImageResize.cpp.o.requires
	$(MAKE) -f CMakeFiles/yolov5.dir/build.make CMakeFiles/yolov5.dir/ImageResize.cpp.o.provides.build
.PHONY : CMakeFiles/yolov5.dir/ImageResize.cpp.o.provides

CMakeFiles/yolov5.dir/ImageResize.cpp.o.provides.build: CMakeFiles/yolov5.dir/ImageResize.cpp.o


CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o: CMakeFiles/yolov5.dir/flags.make
CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o: ../svp/src/common/sample_comm_ive.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o   -c /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_ive.c

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.i"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_ive.c > CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.i

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.s"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_ive.c -o CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.s

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o.requires:

.PHONY : CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o.requires

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o.provides: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o.requires
	$(MAKE) -f CMakeFiles/yolov5.dir/build.make CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o.provides.build
.PHONY : CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o.provides

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o.provides.build: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o


CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o: CMakeFiles/yolov5.dir/flags.make
CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o: ../svp/src/common/sample_comm_nnie.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o   -c /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_nnie.c

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.i"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_nnie.c > CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.i

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.s"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_nnie.c -o CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.s

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o.requires:

.PHONY : CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o.requires

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o.provides: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o.requires
	$(MAKE) -f CMakeFiles/yolov5.dir/build.make CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o.provides.build
.PHONY : CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o.provides

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o.provides.build: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o


CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o: CMakeFiles/yolov5.dir/flags.make
CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o: ../svp/src/common/sample_comm_svp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o   -c /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_svp.c

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.i"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_svp.c > CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.i

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.s"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/common/sample_comm_svp.c -o CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.s

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o.requires:

.PHONY : CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o.requires

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o.provides: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o.requires
	$(MAKE) -f CMakeFiles/yolov5.dir/build.make CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o.provides.build
.PHONY : CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o.provides

CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o.provides.build: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o


CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o: CMakeFiles/yolov5.dir/flags.make
CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o: ../svp/src/nnie/sample_nnie.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o   -c /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/nnie/sample_nnie.c

CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.i"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/nnie/sample_nnie.c > CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.i

CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.s"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/nnie/sample_nnie.c -o CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.s

CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o.requires:

.PHONY : CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o.requires

CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o.provides: CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o.requires
	$(MAKE) -f CMakeFiles/yolov5.dir/build.make CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o.provides.build
.PHONY : CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o.provides

CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o.provides.build: CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o


CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o: CMakeFiles/yolov5.dir/flags.make
CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o: ../svp/src/nnie/sample_svp_nnie_software.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o   -c /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/nnie/sample_svp_nnie_software.c

CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.i"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/nnie/sample_svp_nnie_software.c > CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.i

CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.s"
	/opt/hisi-linux/x86-arm/arm-himix200-linux//bin/arm-himix200-linux-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/svp/src/nnie/sample_svp_nnie_software.c -o CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.s

CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o.requires:

.PHONY : CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o.requires

CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o.provides: CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o.requires
	$(MAKE) -f CMakeFiles/yolov5.dir/build.make CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o.provides.build
.PHONY : CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o.provides

CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o.provides.build: CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o


# Object files for target yolov5
yolov5_OBJECTS = \
"CMakeFiles/yolov5.dir/Yolov5.cpp.o" \
"CMakeFiles/yolov5.dir/ImageResize.cpp.o" \
"CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o" \
"CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o" \
"CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o" \
"CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o" \
"CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o"

# External object files for target yolov5
yolov5_EXTERNAL_OBJECTS =

libyolov5.so: CMakeFiles/yolov5.dir/Yolov5.cpp.o
libyolov5.so: CMakeFiles/yolov5.dir/ImageResize.cpp.o
libyolov5.so: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o
libyolov5.so: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o
libyolov5.so: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o
libyolov5.so: CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o
libyolov5.so: CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o
libyolov5.so: CMakeFiles/yolov5.dir/build.make
libyolov5.so: CMakeFiles/yolov5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library libyolov5.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yolov5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yolov5.dir/build: libyolov5.so

.PHONY : CMakeFiles/yolov5.dir/build

CMakeFiles/yolov5.dir/requires: CMakeFiles/yolov5.dir/Yolov5.cpp.o.requires
CMakeFiles/yolov5.dir/requires: CMakeFiles/yolov5.dir/ImageResize.cpp.o.requires
CMakeFiles/yolov5.dir/requires: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_ive.c.o.requires
CMakeFiles/yolov5.dir/requires: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_nnie.c.o.requires
CMakeFiles/yolov5.dir/requires: CMakeFiles/yolov5.dir/svp/src/common/sample_comm_svp.c.o.requires
CMakeFiles/yolov5.dir/requires: CMakeFiles/yolov5.dir/svp/src/nnie/sample_nnie.c.o.requires
CMakeFiles/yolov5.dir/requires: CMakeFiles/yolov5.dir/svp/src/nnie/sample_svp_nnie_software.c.o.requires

.PHONY : CMakeFiles/yolov5.dir/requires

CMakeFiles/yolov5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/yolov5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/yolov5.dir/clean

CMakeFiles/yolov5.dir/depend:
	cd /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build /home/ljh/Documents/毕业相关/yolov5_4HIVIEW-main/build/CMakeFiles/yolov5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yolov5.dir/depend

