cmake_minimum_required(VERSION 3.0)
# https://cmake.org/cmake/help/latest/command/project.html
project( DisplayImage )

# https://cmake.org/cmake/help/latest/command/find_package.html
find_package( OpenCV REQUIRED )

# https://cmake.org/cmake/help/latest/command/include_directories.html
# https://stackoverflow.com/questions/33981618/check-where-include-library-path-variables-like-opencv-libs-point-to-in-unix
# Where do OpenCV_INCLUDES_DIRS come from?
include_directories(${OpenCV_INCLUDE_DIRS})
# https://cmake.org/cmake/help/latest/command/link_directories.html
link_directories(${OpenCV_LIB_DIR})

# https://cmake.org/cmake/help/latest/command/add_executable.html
add_executable( DisplayImage DisplayImage.cpp )
# https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries( DisplayImage ${OpenCV_LIBS} )