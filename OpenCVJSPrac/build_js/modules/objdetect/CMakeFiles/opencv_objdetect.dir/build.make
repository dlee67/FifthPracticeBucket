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
CMAKE_SOURCE_DIR = /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js

# Include any dependencies generated for this target.
include modules/objdetect/CMakeFiles/opencv_objdetect.dir/depend.make

# Include the progress variables for this target.
include modules/objdetect/CMakeFiles/opencv_objdetect.dir/progress.make

# Include the compile flags for this target's objects.
include modules/objdetect/CMakeFiles/opencv_objdetect.dir/flags.make

modules/objdetect/opencl_kernels_objdetect.cpp: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/opencl/cascadedetect.cl
modules/objdetect/opencl_kernels_objdetect.cpp: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/opencl/objdetect_hog.cl
modules/objdetect/opencl_kernels_objdetect.cpp: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/cmake/cl2cpp.cmake
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Processing OpenCL kernels (objdetect)"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /usr/bin/cmake -DMODULE_NAME=objdetect -DCL_DIR=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/opencl -DOUTPUT=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect/opencl_kernels_objdetect.cpp -P /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/cmake/cl2cpp.cmake

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/flags.make
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/includes_CXX.rsp
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/cascadedetect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o -c /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/cascadedetect.cpp

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.i"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/cascadedetect.cpp > CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.i

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.s"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/cascadedetect.cpp -o CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.s

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o.requires:

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o.requires

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o.provides: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o.requires
	$(MAKE) -f modules/objdetect/CMakeFiles/opencv_objdetect.dir/build.make modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o.provides.build
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o.provides

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o.provides.build: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o


modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/flags.make
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/includes_CXX.rsp
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/cascadedetect_convert.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o -c /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/cascadedetect_convert.cpp

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.i"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/cascadedetect_convert.cpp > CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.i

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.s"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/cascadedetect_convert.cpp -o CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.s

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o.requires:

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o.requires

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o.provides: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o.requires
	$(MAKE) -f modules/objdetect/CMakeFiles/opencv_objdetect.dir/build.make modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o.provides.build
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o.provides

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o.provides.build: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o


modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/flags.make
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/includes_CXX.rsp
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/detection_based_tracker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o -c /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/detection_based_tracker.cpp

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.i"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/detection_based_tracker.cpp > CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.i

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.s"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/detection_based_tracker.cpp -o CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.s

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o.requires:

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o.requires

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o.provides: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o.requires
	$(MAKE) -f modules/objdetect/CMakeFiles/opencv_objdetect.dir/build.make modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o.provides.build
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o.provides

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o.provides.build: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o


modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/flags.make
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/includes_CXX.rsp
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/hog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o -c /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/hog.cpp

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_objdetect.dir/src/hog.cpp.i"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/hog.cpp > CMakeFiles/opencv_objdetect.dir/src/hog.cpp.i

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_objdetect.dir/src/hog.cpp.s"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/hog.cpp -o CMakeFiles/opencv_objdetect.dir/src/hog.cpp.s

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o.requires:

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o.requires

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o.provides: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o.requires
	$(MAKE) -f modules/objdetect/CMakeFiles/opencv_objdetect.dir/build.make modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o.provides.build
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o.provides

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o.provides.build: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o


modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/flags.make
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/includes_CXX.rsp
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_objdetect.dir/src/main.cpp.o -c /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/main.cpp

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_objdetect.dir/src/main.cpp.i"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/main.cpp > CMakeFiles/opencv_objdetect.dir/src/main.cpp.i

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_objdetect.dir/src/main.cpp.s"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/main.cpp -o CMakeFiles/opencv_objdetect.dir/src/main.cpp.s

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o.requires:

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o.requires

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o.provides: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o.requires
	$(MAKE) -f modules/objdetect/CMakeFiles/opencv_objdetect.dir/build.make modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o.provides.build
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o.provides

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o.provides.build: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o


modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/flags.make
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/includes_CXX.rsp
modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o: /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/qrcode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o -c /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/qrcode.cpp

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.i"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/qrcode.cpp > CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.i

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.s"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect/src/qrcode.cpp -o CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.s

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o.requires:

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o.requires

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o.provides: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o.requires
	$(MAKE) -f modules/objdetect/CMakeFiles/opencv_objdetect.dir/build.make modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o.provides.build
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o.provides

modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o.provides.build: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o


modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/flags.make
modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o: modules/objdetect/CMakeFiles/opencv_objdetect.dir/includes_CXX.rsp
modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o: modules/objdetect/opencl_kernels_objdetect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o -c /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect/opencl_kernels_objdetect.cpp

modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.i"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect/opencl_kernels_objdetect.cpp > CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.i

modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.s"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && /home/bob/emsdk/fastcomp/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect/opencl_kernels_objdetect.cpp -o CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.s

modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o.requires:

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o.requires

modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o.provides: modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o.requires
	$(MAKE) -f modules/objdetect/CMakeFiles/opencv_objdetect.dir/build.make modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o.provides.build
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o.provides

modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o.provides.build: modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o


# Object files for target opencv_objdetect
opencv_objdetect_OBJECTS = \
"CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o" \
"CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o" \
"CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o" \
"CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o" \
"CMakeFiles/opencv_objdetect.dir/src/main.cpp.o" \
"CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o" \
"CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o"

# External object files for target opencv_objdetect
opencv_objdetect_EXTERNAL_OBJECTS =

lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/build.make
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/objects1.rsp
lib/libopencv_objdetect.a: modules/objdetect/CMakeFiles/opencv_objdetect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library ../../lib/libopencv_objdetect.a"
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && $(CMAKE_COMMAND) -P CMakeFiles/opencv_objdetect.dir/cmake_clean_target.cmake
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_objdetect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/objdetect/CMakeFiles/opencv_objdetect.dir/build: lib/libopencv_objdetect.a

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/build

modules/objdetect/CMakeFiles/opencv_objdetect.dir/requires: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect.cpp.o.requires
modules/objdetect/CMakeFiles/opencv_objdetect.dir/requires: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/cascadedetect_convert.cpp.o.requires
modules/objdetect/CMakeFiles/opencv_objdetect.dir/requires: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/detection_based_tracker.cpp.o.requires
modules/objdetect/CMakeFiles/opencv_objdetect.dir/requires: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/hog.cpp.o.requires
modules/objdetect/CMakeFiles/opencv_objdetect.dir/requires: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/main.cpp.o.requires
modules/objdetect/CMakeFiles/opencv_objdetect.dir/requires: modules/objdetect/CMakeFiles/opencv_objdetect.dir/src/qrcode.cpp.o.requires
modules/objdetect/CMakeFiles/opencv_objdetect.dir/requires: modules/objdetect/CMakeFiles/opencv_objdetect.dir/opencl_kernels_objdetect.cpp.o.requires

.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/requires

modules/objdetect/CMakeFiles/opencv_objdetect.dir/clean:
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect && $(CMAKE_COMMAND) -P CMakeFiles/opencv_objdetect.dir/cmake_clean.cmake
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/clean

modules/objdetect/CMakeFiles/opencv_objdetect.dir/depend: modules/objdetect/opencl_kernels_objdetect.cpp
	cd /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/opencv/modules/objdetect /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect /home/bob/Desktop/FifthPracticeBucket/OpenCVJSPrac/build_js/modules/objdetect/CMakeFiles/opencv_objdetect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/objdetect/CMakeFiles/opencv_objdetect.dir/depend
