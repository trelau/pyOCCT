# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
# 
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
# 
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
cmake_minimum_required(VERSION 2.6)
project(pyOCCT)


# --------------------------------------------------------------------------- #
# OPTIONS
# --------------------------------------------------------------------------- #
option(ENABLE_NETGEN "Enable Netgen" ON)
option(ENABLE_BLSURF "Enable BLSURF" OFF)


# --------------------------------------------------------------------------- #
# SETTINGS
# Use /FORCE to ignore unresolved externals (known issue)
# --------------------------------------------------------------------------- #
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /FORCE")

set(pyOCCT_MAJOR_VERSION       "0")
set(pyOCCT_MINOR_VERSION       "0")
set(pyOCCT_MAINTENANCE_VERSION "1")
set(PACKAGE_VERSION "${pyOCCT_MAJOR_VERSION}.${pyOCCT_MINOR_VERSION}-${pyOCCT_MAINTENANCE_VERSION}")

if(WIN32)
	set(EXTENSION ".pyd")
else(WIN32)
	set(EXTENSION ".so")
endif(WIN32)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Default build type will be Release.")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING INTERNAL)
endif(NOT CMAKE_BUILD_TYPE)


# --------------------------------------------------------------------------- #
# OpenCASCADE
# --------------------------------------------------------------------------- #
if(NOT DEFINED OpenCASCADE_INCLUDE_DIR OR NOT DEFINED OpenCASCADE_LIBRARY_DIR)
    message(STATUS "Searching for OpenCASCADE...")
    find_package(OpenCASCADE 7.2.0 REQUIRED)
endif()

if(NOT EXISTS ${OpenCASCADE_INCLUDE_DIR})
    message(FATAL_ERROR "Failed to find OpenCASCADE include directory.")
endif()

if(NOT EXISTS ${OpenCASCADE_LIBRARY_DIR})
    message(FATAL_ERROR "Failed to find OpenCASCADE library directory.")
endif()
                             
message(STATUS "OpenCASCADE include directory: ${OpenCASCADE_INCLUDE_DIR}")
message(STATUS "OpenCASCADE library directory: ${OpenCASCADE_LIBRARY_DIR}")                                                                                
include_directories(${OpenCASCADE_INCLUDE_DIR})
link_directories(${OpenCASCADE_LIBRARY_DIR})


# --------------------------------------------------------------------------- #
# NETGEN
# --------------------------------------------------------------------------- #
if(ENABLE_NETGEN)
    if(NOT DEFINED NETGEN_INCLUDE_DIR)
        message(STATUS "Searching for Netgen...")
        find_package(NETGEN REQUIRED)
    endif()

    if(NOT EXISTS ${NETGEN_INCLUDE_DIR})
        message(FATAL_ERROR "Failed to find Netgen include directory.")
    endif()
    
    message(STATUS "Netgen include directory: ${NETGEN_INCLUDE_DIR}")
    include_directories(${NETGEN_INCLUDE_DIR})
    
endif()


# --------------------------------------------------------------------------- #
# SMESH
# --------------------------------------------------------------------------- #
if(NOT DEFINED SMESH_INCLUDE_PATH OR NOT DEFINED SMESH_LIB_PATH)
    message(STATUS "Searching for SMESH...")
    find_package(SMESH REQUIRED)
endif()

if(NOT EXISTS ${SMESH_INCLUDE_PATH})
    message(FATAL_ERROR "Failed to find SMESH include directory.")
endif()

if(NOT EXISTS ${SMESH_LIB_PATH})
    message(FATAL_ERROR "Failed to find SMESH library directory.")
endif()
                             
message(STATUS "SMESH include directory: ${SMESH_INCLUDE_PATH}")
message(STATUS "SMESH library directory: ${SMESH_LIB_PATH}")                                                                                
include_directories(${SMESH_INCLUDE_PATH})
link_directories(${SMESH_LIB_PATH})

set(SMESH_LIBRARIES Driver;
                    DriverDAT;
                    DriverGMF;
                    DriverSTL;
                    DriverUNV;
                    MEFISTO2;
                    SMDS;
                    SMESH;
                    SMESHBasics;
                    SMESHControls;
                    SMESHDS;
                    SMESHMisc;
                    SMESHTrace;
                    SMESHUtils;
                    StdMeshers)
                    
if(ENABLE_NETGEN)
    set(SMESH_LIBRARIES ${SMESH_LIBRARIES}; NETGENPlugin)
endif()

if(ENABLE_BLSURF)
    set(SMESH_LIBRARIES ${SMESH_LIBRARIES}; BLSURFlugin)
endif()

# Build full library paths since they have the same name as the Python
# libraries
set(SMESH_ABS_LIBS)
foreach(LIB ${SMESH_LIBRARIES})
    set(FOUND_LIB "FOUND_LIB-NOTFOUND")
    find_library(FOUND_LIB ${LIB} PATHS ${SMESH_LIB_PATH})
    list(APPEND SMESH_ABS_LIBS ${FOUND_LIB})
endforeach(LIB)
unset(FOUND_LIB CACHE)


# --------------------------------------------------------------------------- #
# VTK
# --------------------------------------------------------------------------- #
if(NOT DEFINED VTK_INCLUDE_DIRS)
    message(STATUS "Searching for VTK...")
    find_package(VTK REQUIRED)
endif()
    
message(STATUS "VTK include directory: ${VTK_INCLUDE_DIRS}")
include_directories(${VTK_INCLUDE_DIRS})


# --------------------------------------------------------------------------- #
# BOOST
# --------------------------------------------------------------------------- #
if(NOT DEFINED Boost_INCLUDE_DIR)
    message(STATUS "Searching for Boost...")
    find_package(Boost REQUIRED)
endif()

if(NOT EXISTS ${Boost_INCLUDE_DIR})
    message(FATAL_ERROR "Failed to find Boost include directory.")
endif()    

message(STATUS "Boost include directory: ${Boost_INCLUDE_DIR}")
include_directories(${Boost_INCLUDE_DIR})


# --------------------------------------------------------------------------- #
# PTHREAD
# --------------------------------------------------------------------------- #
set(PTHREAD_INCLUDE_DIRS "" CACHE PATH "Path to pthread.h")

if(NOT EXISTS ${PTHREAD_INCLUDE_DIRS})
    message(FATAL_ERROR "pthread include directory is required.")
endif()

message(STATUS "pthread include directory: ${PTHREAD_INCLUDE_DIRS}")
include_directories(${PTHREAD_INCLUDE_DIRS})


# --------------------------------------------------------------------------- #
# BLSURF
# --------------------------------------------------------------------------- #
if(ENABLE_BLSURF)
    set(MESHGEMS_INCLUDE "" CACHE PATH "MeshGems include directory.")
    
    if(NOT EXISTS ${MESHGEMS_INCLUDE})
        message(FATAL_ERROR "MeshGems include directory is required.")
    endif()
    
    message(STATUS "MeshGems include directory: ${MESHGEMS_INCLUDE}")
    include_directories(${MESHGEMS_INCLUDE})
endif(ENABLE_BLSURF)


# --------------------------------------------------------------------------- #
# PYTHON
# --------------------------------------------------------------------------- #
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})


# --------------------------------------------------------------------------- #
# PYBIND11
# --------------------------------------------------------------------------- #
add_subdirectory(pybind11)


# --------------------------------------------------------------------------- #
# pyOCCT
# --------------------------------------------------------------------------- #
include_directories(inc)
set(OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")

file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(MAKE_LIB BOOL ON)
foreach(SRC ${SRCS})
    get_filename_component(MOD ${SRC} NAME_WE)
    
    # Check Netgen
    if(${MOD} STREQUAL "NETGENPlugin" AND NOT ENABLE_NETGEN)
        set(MAKE_LIB OFF)
        message(STATUS "Skipping NETGENPlugin.")
    endif()
    
    # Check BLSURF
    if(${MOD} STREQUAL "BLSURFPlugin" AND NOT ENABLE_BLSURF)
        set(MAKE_LIB OFF)
        message(STATUS "Skipping BLSURFPLugin.")
    endif()
    
    if(MAKE_LIB)
        pybind11_add_module(${MOD} ${SRC})
        target_link_libraries(${MOD} PUBLIC ${OpenCASCADE_LIBRARIES}
                                            ${SMESH_ABS_LIBS})
        set_target_properties(${MOD} PROPERTIES SUFFIX ${EXTENSION})
        install(FILES ${OUTPUT_PATH}/${MOD}${EXTENSION}
                DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/OCCT)
    endif()
    set(MAKE_LIB ON)
endforeach()

INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/cmake/__init__.py
        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/OCCT)
