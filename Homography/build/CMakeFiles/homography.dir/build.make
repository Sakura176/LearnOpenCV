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
CMAKE_SOURCE_DIR = /home/yuchao/OpenCV练习/Homography

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuchao/OpenCV练习/Homography/build

# Include any dependencies generated for this target.
include CMakeFiles/homography.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/homography.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homography.dir/flags.make

CMakeFiles/homography.dir/virtual-billboard.cpp.o: CMakeFiles/homography.dir/flags.make
CMakeFiles/homography.dir/virtual-billboard.cpp.o: ../virtual-billboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuchao/OpenCV练习/Homography/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homography.dir/virtual-billboard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/homography.dir/virtual-billboard.cpp.o -c /home/yuchao/OpenCV练习/Homography/virtual-billboard.cpp

CMakeFiles/homography.dir/virtual-billboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homography.dir/virtual-billboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuchao/OpenCV练习/Homography/virtual-billboard.cpp > CMakeFiles/homography.dir/virtual-billboard.cpp.i

CMakeFiles/homography.dir/virtual-billboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homography.dir/virtual-billboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuchao/OpenCV练习/Homography/virtual-billboard.cpp -o CMakeFiles/homography.dir/virtual-billboard.cpp.s

# Object files for target homography
homography_OBJECTS = \
"CMakeFiles/homography.dir/virtual-billboard.cpp.o"

# External object files for target homography
homography_EXTERNAL_OBJECTS =

homography: CMakeFiles/homography.dir/virtual-billboard.cpp.o
homography: CMakeFiles/homography.dir/build.make
homography: /usr/local/lib/libopencv_gapi.so.4.5.0
homography: /usr/local/lib/libopencv_stitching.so.4.5.0
homography: /usr/local/lib/libopencv_alphamat.so.4.5.0
homography: /usr/local/lib/libopencv_aruco.so.4.5.0
homography: /usr/local/lib/libopencv_bgsegm.so.4.5.0
homography: /usr/local/lib/libopencv_bioinspired.so.4.5.0
homography: /usr/local/lib/libopencv_ccalib.so.4.5.0
homography: /usr/local/lib/libopencv_dnn_objdetect.so.4.5.0
homography: /usr/local/lib/libopencv_dnn_superres.so.4.5.0
homography: /usr/local/lib/libopencv_dpm.so.4.5.0
homography: /usr/local/lib/libopencv_face.so.4.5.0
homography: /usr/local/lib/libopencv_freetype.so.4.5.0
homography: /usr/local/lib/libopencv_fuzzy.so.4.5.0
homography: /usr/local/lib/libopencv_hfs.so.4.5.0
homography: /usr/local/lib/libopencv_img_hash.so.4.5.0
homography: /usr/local/lib/libopencv_intensity_transform.so.4.5.0
homography: /usr/local/lib/libopencv_line_descriptor.so.4.5.0
homography: /usr/local/lib/libopencv_mcc.so.4.5.0
homography: /usr/local/lib/libopencv_quality.so.4.5.0
homography: /usr/local/lib/libopencv_rapid.so.4.5.0
homography: /usr/local/lib/libopencv_reg.so.4.5.0
homography: /usr/local/lib/libopencv_rgbd.so.4.5.0
homography: /usr/local/lib/libopencv_saliency.so.4.5.0
homography: /usr/local/lib/libopencv_stereo.so.4.5.0
homography: /usr/local/lib/libopencv_structured_light.so.4.5.0
homography: /usr/local/lib/libopencv_superres.so.4.5.0
homography: /usr/local/lib/libopencv_surface_matching.so.4.5.0
homography: /usr/local/lib/libopencv_tracking.so.4.5.0
homography: /usr/local/lib/libopencv_videostab.so.4.5.0
homography: /usr/local/lib/libopencv_xfeatures2d.so.4.5.0
homography: /usr/local/lib/libopencv_xobjdetect.so.4.5.0
homography: /usr/local/lib/libopencv_xphoto.so.4.5.0
homography: /usr/local/lib/libopencv_shape.so.4.5.0
homography: /usr/local/lib/libopencv_highgui.so.4.5.0
homography: /usr/local/lib/libopencv_datasets.so.4.5.0
homography: /usr/local/lib/libopencv_plot.so.4.5.0
homography: /usr/local/lib/libopencv_text.so.4.5.0
homography: /usr/local/lib/libopencv_dnn.so.4.5.0
homography: /usr/local/lib/libopencv_ml.so.4.5.0
homography: /usr/local/lib/libopencv_phase_unwrapping.so.4.5.0
homography: /usr/local/lib/libopencv_optflow.so.4.5.0
homography: /usr/local/lib/libopencv_ximgproc.so.4.5.0
homography: /usr/local/lib/libopencv_video.so.4.5.0
homography: /usr/local/lib/libopencv_videoio.so.4.5.0
homography: /usr/local/lib/libopencv_imgcodecs.so.4.5.0
homography: /usr/local/lib/libopencv_objdetect.so.4.5.0
homography: /usr/local/lib/libopencv_calib3d.so.4.5.0
homography: /usr/local/lib/libopencv_features2d.so.4.5.0
homography: /usr/local/lib/libopencv_flann.so.4.5.0
homography: /usr/local/lib/libopencv_photo.so.4.5.0
homography: /usr/local/lib/libopencv_imgproc.so.4.5.0
homography: /usr/local/lib/libopencv_core.so.4.5.0
homography: CMakeFiles/homography.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yuchao/OpenCV练习/Homography/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable homography"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/homography.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homography.dir/build: homography

.PHONY : CMakeFiles/homography.dir/build

CMakeFiles/homography.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homography.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homography.dir/clean

CMakeFiles/homography.dir/depend:
	cd /home/yuchao/OpenCV练习/Homography/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuchao/OpenCV练习/Homography /home/yuchao/OpenCV练习/Homography /home/yuchao/OpenCV练习/Homography/build /home/yuchao/OpenCV练习/Homography/build /home/yuchao/OpenCV练习/Homography/build/CMakeFiles/homography.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homography.dir/depend
