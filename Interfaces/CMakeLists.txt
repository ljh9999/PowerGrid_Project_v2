cmake_minimum_required(VERSION 3.10)
project(Interface)

SET(CROSS_COMPILE 1)

IF(CROSS_COMPILE)
    SET(CMAKE_SYSTEM_NAME linux)
    SET(TOOLCHAIN_DIR /opt/hisi-linux/x86-arm/arm-himix200-linux/)

    # specify the cross compiler
    SET(CMAKE_C_COMPILER   ${TOOLCHAIN_DIR}/bin/arm-himix200-linux-gcc)
    SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/arm-himix200-linux-g++)
    SET(GNU_FLAGS "-mfpu=vfp -fPIC")
    SET(CMAKE_CXX_FLAGS "${GNU_FLAGS} ")
    SET(CMAKE_C_FLAGS "${GNU_FLAGS} ")

    # where is the target environment
    SET(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
            ${TOOLCHAIN_DIR}/include
            ${TOOLCHAIN_DIR}/lib)

    # search for programs in the build host directories (notnecessary)
    SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

    # for libraries and headers in the target directories
    SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

ENDIF(CROSS_COMPILE)

SET(CMAKE_CXX_FLAGS "-O3 -mfpu=neon-vfpv4 -mfloat-abi=softfp")
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")

#3516 OpenCV
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/opencv/inc)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(OpenCV_Lib opencv_core opencv_imgcodecs opencv_imgproc)

#hisdk
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hiSDK/inc)
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/hiSDK/lib)

add_library(Interfaces SHARED include/Interface.cpp include/Interface.h include/base64.h)
target_link_libraries(Interfaces ${OpenCV_LIBS})