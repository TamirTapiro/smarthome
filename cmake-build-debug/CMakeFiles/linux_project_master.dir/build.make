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
CMAKE_COMMAND = /snap/clion/22/bin/cmake/bin/cmake

# The command to remove a file.
RM = /snap/clion/22/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ran/Downloads/linux-project-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ran/Downloads/linux-project-master/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linux_project_master.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linux_project_master.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linux_project_master.dir/flags.make

CMakeFiles/linux_project_master.dir/DB/dbInit.c.o: CMakeFiles/linux_project_master.dir/flags.make
CMakeFiles/linux_project_master.dir/DB/dbInit.c.o: ../DB/dbInit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/linux_project_master.dir/DB/dbInit.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_project_master.dir/DB/dbInit.c.o   -c /home/ran/Downloads/linux-project-master/DB/dbInit.c

CMakeFiles/linux_project_master.dir/DB/dbInit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_project_master.dir/DB/dbInit.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ran/Downloads/linux-project-master/DB/dbInit.c > CMakeFiles/linux_project_master.dir/DB/dbInit.c.i

CMakeFiles/linux_project_master.dir/DB/dbInit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_project_master.dir/DB/dbInit.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ran/Downloads/linux-project-master/DB/dbInit.c -o CMakeFiles/linux_project_master.dir/DB/dbInit.c.s

CMakeFiles/linux_project_master.dir/DB/dbInit.c.o.requires:

.PHONY : CMakeFiles/linux_project_master.dir/DB/dbInit.c.o.requires

CMakeFiles/linux_project_master.dir/DB/dbInit.c.o.provides: CMakeFiles/linux_project_master.dir/DB/dbInit.c.o.requires
	$(MAKE) -f CMakeFiles/linux_project_master.dir/build.make CMakeFiles/linux_project_master.dir/DB/dbInit.c.o.provides.build
.PHONY : CMakeFiles/linux_project_master.dir/DB/dbInit.c.o.provides

CMakeFiles/linux_project_master.dir/DB/dbInit.c.o.provides.build: CMakeFiles/linux_project_master.dir/DB/dbInit.c.o


CMakeFiles/linux_project_master.dir/DB/main.c.o: CMakeFiles/linux_project_master.dir/flags.make
CMakeFiles/linux_project_master.dir/DB/main.c.o: ../DB/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/linux_project_master.dir/DB/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_project_master.dir/DB/main.c.o   -c /home/ran/Downloads/linux-project-master/DB/main.c

CMakeFiles/linux_project_master.dir/DB/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_project_master.dir/DB/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ran/Downloads/linux-project-master/DB/main.c > CMakeFiles/linux_project_master.dir/DB/main.c.i

CMakeFiles/linux_project_master.dir/DB/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_project_master.dir/DB/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ran/Downloads/linux-project-master/DB/main.c -o CMakeFiles/linux_project_master.dir/DB/main.c.s

CMakeFiles/linux_project_master.dir/DB/main.c.o.requires:

.PHONY : CMakeFiles/linux_project_master.dir/DB/main.c.o.requires

CMakeFiles/linux_project_master.dir/DB/main.c.o.provides: CMakeFiles/linux_project_master.dir/DB/main.c.o.requires
	$(MAKE) -f CMakeFiles/linux_project_master.dir/build.make CMakeFiles/linux_project_master.dir/DB/main.c.o.provides.build
.PHONY : CMakeFiles/linux_project_master.dir/DB/main.c.o.provides

CMakeFiles/linux_project_master.dir/DB/main.c.o.provides.build: CMakeFiles/linux_project_master.dir/DB/main.c.o


CMakeFiles/linux_project_master.dir/Home.cpp.o: CMakeFiles/linux_project_master.dir/flags.make
CMakeFiles/linux_project_master.dir/Home.cpp.o: ../Home.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/linux_project_master.dir/Home.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linux_project_master.dir/Home.cpp.o -c /home/ran/Downloads/linux-project-master/Home.cpp

CMakeFiles/linux_project_master.dir/Home.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linux_project_master.dir/Home.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ran/Downloads/linux-project-master/Home.cpp > CMakeFiles/linux_project_master.dir/Home.cpp.i

CMakeFiles/linux_project_master.dir/Home.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linux_project_master.dir/Home.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ran/Downloads/linux-project-master/Home.cpp -o CMakeFiles/linux_project_master.dir/Home.cpp.s

CMakeFiles/linux_project_master.dir/Home.cpp.o.requires:

.PHONY : CMakeFiles/linux_project_master.dir/Home.cpp.o.requires

CMakeFiles/linux_project_master.dir/Home.cpp.o.provides: CMakeFiles/linux_project_master.dir/Home.cpp.o.requires
	$(MAKE) -f CMakeFiles/linux_project_master.dir/build.make CMakeFiles/linux_project_master.dir/Home.cpp.o.provides.build
.PHONY : CMakeFiles/linux_project_master.dir/Home.cpp.o.provides

CMakeFiles/linux_project_master.dir/Home.cpp.o.provides.build: CMakeFiles/linux_project_master.dir/Home.cpp.o


CMakeFiles/linux_project_master.dir/RequestManager.cpp.o: CMakeFiles/linux_project_master.dir/flags.make
CMakeFiles/linux_project_master.dir/RequestManager.cpp.o: ../RequestManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/linux_project_master.dir/RequestManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linux_project_master.dir/RequestManager.cpp.o -c /home/ran/Downloads/linux-project-master/RequestManager.cpp

CMakeFiles/linux_project_master.dir/RequestManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linux_project_master.dir/RequestManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ran/Downloads/linux-project-master/RequestManager.cpp > CMakeFiles/linux_project_master.dir/RequestManager.cpp.i

CMakeFiles/linux_project_master.dir/RequestManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linux_project_master.dir/RequestManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ran/Downloads/linux-project-master/RequestManager.cpp -o CMakeFiles/linux_project_master.dir/RequestManager.cpp.s

CMakeFiles/linux_project_master.dir/RequestManager.cpp.o.requires:

.PHONY : CMakeFiles/linux_project_master.dir/RequestManager.cpp.o.requires

CMakeFiles/linux_project_master.dir/RequestManager.cpp.o.provides: CMakeFiles/linux_project_master.dir/RequestManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/linux_project_master.dir/build.make CMakeFiles/linux_project_master.dir/RequestManager.cpp.o.provides.build
.PHONY : CMakeFiles/linux_project_master.dir/RequestManager.cpp.o.provides

CMakeFiles/linux_project_master.dir/RequestManager.cpp.o.provides.build: CMakeFiles/linux_project_master.dir/RequestManager.cpp.o


CMakeFiles/linux_project_master.dir/Socket.cpp.o: CMakeFiles/linux_project_master.dir/flags.make
CMakeFiles/linux_project_master.dir/Socket.cpp.o: ../Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/linux_project_master.dir/Socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linux_project_master.dir/Socket.cpp.o -c /home/ran/Downloads/linux-project-master/Socket.cpp

CMakeFiles/linux_project_master.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linux_project_master.dir/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ran/Downloads/linux-project-master/Socket.cpp > CMakeFiles/linux_project_master.dir/Socket.cpp.i

CMakeFiles/linux_project_master.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linux_project_master.dir/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ran/Downloads/linux-project-master/Socket.cpp -o CMakeFiles/linux_project_master.dir/Socket.cpp.s

CMakeFiles/linux_project_master.dir/Socket.cpp.o.requires:

.PHONY : CMakeFiles/linux_project_master.dir/Socket.cpp.o.requires

CMakeFiles/linux_project_master.dir/Socket.cpp.o.provides: CMakeFiles/linux_project_master.dir/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/linux_project_master.dir/build.make CMakeFiles/linux_project_master.dir/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/linux_project_master.dir/Socket.cpp.o.provides

CMakeFiles/linux_project_master.dir/Socket.cpp.o.provides.build: CMakeFiles/linux_project_master.dir/Socket.cpp.o


CMakeFiles/linux_project_master.dir/User.cpp.o: CMakeFiles/linux_project_master.dir/flags.make
CMakeFiles/linux_project_master.dir/User.cpp.o: ../User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/linux_project_master.dir/User.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linux_project_master.dir/User.cpp.o -c /home/ran/Downloads/linux-project-master/User.cpp

CMakeFiles/linux_project_master.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linux_project_master.dir/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ran/Downloads/linux-project-master/User.cpp > CMakeFiles/linux_project_master.dir/User.cpp.i

CMakeFiles/linux_project_master.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linux_project_master.dir/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ran/Downloads/linux-project-master/User.cpp -o CMakeFiles/linux_project_master.dir/User.cpp.s

CMakeFiles/linux_project_master.dir/User.cpp.o.requires:

.PHONY : CMakeFiles/linux_project_master.dir/User.cpp.o.requires

CMakeFiles/linux_project_master.dir/User.cpp.o.provides: CMakeFiles/linux_project_master.dir/User.cpp.o.requires
	$(MAKE) -f CMakeFiles/linux_project_master.dir/build.make CMakeFiles/linux_project_master.dir/User.cpp.o.provides.build
.PHONY : CMakeFiles/linux_project_master.dir/User.cpp.o.provides

CMakeFiles/linux_project_master.dir/User.cpp.o.provides.build: CMakeFiles/linux_project_master.dir/User.cpp.o


CMakeFiles/linux_project_master.dir/Database.cpp.o: CMakeFiles/linux_project_master.dir/flags.make
CMakeFiles/linux_project_master.dir/Database.cpp.o: ../Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/linux_project_master.dir/Database.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linux_project_master.dir/Database.cpp.o -c /home/ran/Downloads/linux-project-master/Database.cpp

CMakeFiles/linux_project_master.dir/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linux_project_master.dir/Database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ran/Downloads/linux-project-master/Database.cpp > CMakeFiles/linux_project_master.dir/Database.cpp.i

CMakeFiles/linux_project_master.dir/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linux_project_master.dir/Database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ran/Downloads/linux-project-master/Database.cpp -o CMakeFiles/linux_project_master.dir/Database.cpp.s

CMakeFiles/linux_project_master.dir/Database.cpp.o.requires:

.PHONY : CMakeFiles/linux_project_master.dir/Database.cpp.o.requires

CMakeFiles/linux_project_master.dir/Database.cpp.o.provides: CMakeFiles/linux_project_master.dir/Database.cpp.o.requires
	$(MAKE) -f CMakeFiles/linux_project_master.dir/build.make CMakeFiles/linux_project_master.dir/Database.cpp.o.provides.build
.PHONY : CMakeFiles/linux_project_master.dir/Database.cpp.o.provides

CMakeFiles/linux_project_master.dir/Database.cpp.o.provides.build: CMakeFiles/linux_project_master.dir/Database.cpp.o


CMakeFiles/linux_project_master.dir/main.cpp.o: CMakeFiles/linux_project_master.dir/flags.make
CMakeFiles/linux_project_master.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/linux_project_master.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linux_project_master.dir/main.cpp.o -c /home/ran/Downloads/linux-project-master/main.cpp

CMakeFiles/linux_project_master.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linux_project_master.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ran/Downloads/linux-project-master/main.cpp > CMakeFiles/linux_project_master.dir/main.cpp.i

CMakeFiles/linux_project_master.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linux_project_master.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ran/Downloads/linux-project-master/main.cpp -o CMakeFiles/linux_project_master.dir/main.cpp.s

CMakeFiles/linux_project_master.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/linux_project_master.dir/main.cpp.o.requires

CMakeFiles/linux_project_master.dir/main.cpp.o.provides: CMakeFiles/linux_project_master.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/linux_project_master.dir/build.make CMakeFiles/linux_project_master.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/linux_project_master.dir/main.cpp.o.provides

CMakeFiles/linux_project_master.dir/main.cpp.o.provides.build: CMakeFiles/linux_project_master.dir/main.cpp.o


# Object files for target linux_project_master
linux_project_master_OBJECTS = \
"CMakeFiles/linux_project_master.dir/DB/dbInit.c.o" \
"CMakeFiles/linux_project_master.dir/DB/main.c.o" \
"CMakeFiles/linux_project_master.dir/Home.cpp.o" \
"CMakeFiles/linux_project_master.dir/RequestManager.cpp.o" \
"CMakeFiles/linux_project_master.dir/Socket.cpp.o" \
"CMakeFiles/linux_project_master.dir/User.cpp.o" \
"CMakeFiles/linux_project_master.dir/Database.cpp.o" \
"CMakeFiles/linux_project_master.dir/main.cpp.o"

# External object files for target linux_project_master
linux_project_master_EXTERNAL_OBJECTS =

linux_project_master: CMakeFiles/linux_project_master.dir/DB/dbInit.c.o
linux_project_master: CMakeFiles/linux_project_master.dir/DB/main.c.o
linux_project_master: CMakeFiles/linux_project_master.dir/Home.cpp.o
linux_project_master: CMakeFiles/linux_project_master.dir/RequestManager.cpp.o
linux_project_master: CMakeFiles/linux_project_master.dir/Socket.cpp.o
linux_project_master: CMakeFiles/linux_project_master.dir/User.cpp.o
linux_project_master: CMakeFiles/linux_project_master.dir/Database.cpp.o
linux_project_master: CMakeFiles/linux_project_master.dir/main.cpp.o
linux_project_master: CMakeFiles/linux_project_master.dir/build.make
linux_project_master: CMakeFiles/linux_project_master.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable linux_project_master"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linux_project_master.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linux_project_master.dir/build: linux_project_master

.PHONY : CMakeFiles/linux_project_master.dir/build

CMakeFiles/linux_project_master.dir/requires: CMakeFiles/linux_project_master.dir/DB/dbInit.c.o.requires
CMakeFiles/linux_project_master.dir/requires: CMakeFiles/linux_project_master.dir/DB/main.c.o.requires
CMakeFiles/linux_project_master.dir/requires: CMakeFiles/linux_project_master.dir/Home.cpp.o.requires
CMakeFiles/linux_project_master.dir/requires: CMakeFiles/linux_project_master.dir/RequestManager.cpp.o.requires
CMakeFiles/linux_project_master.dir/requires: CMakeFiles/linux_project_master.dir/Socket.cpp.o.requires
CMakeFiles/linux_project_master.dir/requires: CMakeFiles/linux_project_master.dir/User.cpp.o.requires
CMakeFiles/linux_project_master.dir/requires: CMakeFiles/linux_project_master.dir/Database.cpp.o.requires
CMakeFiles/linux_project_master.dir/requires: CMakeFiles/linux_project_master.dir/main.cpp.o.requires

.PHONY : CMakeFiles/linux_project_master.dir/requires

CMakeFiles/linux_project_master.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linux_project_master.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linux_project_master.dir/clean

CMakeFiles/linux_project_master.dir/depend:
	cd /home/ran/Downloads/linux-project-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ran/Downloads/linux-project-master /home/ran/Downloads/linux-project-master /home/ran/Downloads/linux-project-master/cmake-build-debug /home/ran/Downloads/linux-project-master/cmake-build-debug /home/ran/Downloads/linux-project-master/cmake-build-debug/CMakeFiles/linux_project_master.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linux_project_master.dir/depend
