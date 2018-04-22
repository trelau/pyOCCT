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
cmake_minimum_required(VERSION 3.0)
project(pyOCCT VERSION 7.2.0.1 LANGUAGES CXX)


# --------------------------------------------------------------------------- #
# OPTIONS
# --------------------------------------------------------------------------- #
option(ENABLE_SMESH "Enable SMESH" OFF)
option(ENABLE_NETGEN "Enable Netgen" OFF)
option(ENABLE_BLSURF "Enable BLSURF" OFF)
option(ENABLE_FORCE "Force build even if unresolved externals are found" OFF)
option(ENABLE_WARNINGS "Disable warning output." OFF)
option(TEST_BUILD "Build a subset of modules for testing." OFF)

# --------------------------------------------------------------------------- #
# SETTINGS
# --------------------------------------------------------------------------- #
set(pyOCCT_MAJOR_VERSION 7)
set(pyOCCT_MINOR_VERSION 2)
set(pyOCCT_PATCH_VERSION 0)
set(pyOCCT_TWEAK_VERSION 1)

if(WIN32)
	set(EXTENSION ".pyd")
else(WIN32)
	set(EXTENSION ".so")
endif(WIN32)

# Use /FORCE to ignore unresolved externals (known issue)
if(ENABLE_FORCE)
    message(STATUS "Using /FORCE linker option.")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /FORCE")
endif(ENABLE_FORCE)

# Use Link Time Optimization per pybind11 documentation
if(MSVC)
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /LTCG")
endif(MSVC)

# Known warnings
if(NOT ENABLE_WARNINGS)
    if(WIN32)
        set(WARNINGS "/wd4996 /wd4800 /wd4267 /wd4275 /wd4251 /wd4805 /wd4290 /wd4005 /wd4180 /wd4244 /wd4146 /wd4172")
    else(WIN32)
        set(WARNINGS "-Wall -Wno-deprecated-declarations -Wno-strict-aliasing")
    endif(WIN32)
else(NOT ENABLE_WARNINGS)
    set(WARNINGS)
endif(NOT ENABLE_WARNINGS)

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
if(ENABLE_NETGEN AND ENABLE_SMESH)
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
# Manually provide the SMESH modules since the library names may not match up
# exactly with the module names based on the header file names. The
# SMESH_LIBRARIES should be found by find_package(SMESH).
set(SMESH_MODULES Driver;
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
                  StdMeshers;
                  SMDSAbs;
                  BasicsGenericDestructor;
                  BaseTraceCollector;
                  LocalTraceBufferPool;
                  Utils)

set(SMESH_ABS_LIBS)
if(ENABLE_SMESH)
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

    if(NOT DEFINED SMESH_LIBRARIES)
        message(FATAL_ERROR "SMESH libraries were not found.")
    else()
        message(STATUS "SMESH libraries: ${SMESH_LIBRARIES}")
    endif()

    message(STATUS "SMESH include directory: ${SMESH_INCLUDE_PATH}")
    message(STATUS "SMESH library directory: ${SMESH_LIB_PATH}")
    include_directories(${SMESH_INCLUDE_PATH})
    link_directories(${SMESH_LIB_PATH})

    # Build full library paths since they have the same name as the Python
    # libraries
    foreach(LIB ${SMESH_LIBRARIES})
        set(FOUND_LIB "FOUND_LIB-NOTFOUND")
        find_library(FOUND_LIB ${LIB} PATHS ${SMESH_LIB_PATH})
        list(APPEND SMESH_ABS_LIBS ${FOUND_LIB})
    endforeach(LIB)
    unset(FOUND_LIB CACHE)
endif()


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
if(ENABLE_SMESH)
    set(PTHREAD_INCLUDE_DIRS "" CACHE PATH "pthread include directory.")

    if(NOT EXISTS ${PTHREAD_INCLUDE_DIRS})
        message(FATAL_ERROR "pthread include directory is required.")
    endif()

    message(STATUS "pthread include directory: ${PTHREAD_INCLUDE_DIRS}")
    include_directories(${PTHREAD_INCLUDE_DIRS})
endif()


# --------------------------------------------------------------------------- #
# BLSURF
# --------------------------------------------------------------------------- #
if(ENABLE_BLSURF AND ENABLE_SMESH)
    set(MESHGEMS_INCLUDE "" CACHE PATH "MeshGems include directory.")

    if(NOT EXISTS ${MESHGEMS_INCLUDE})
        message(FATAL_ERROR "MeshGems include directory is required.")
    endif()

    message(STATUS "MeshGems include directory: ${MESHGEMS_INCLUDE}")
    include_directories(${MESHGEMS_INCLUDE})
endif()


# --------------------------------------------------------------------------- #
# PYBIND11
# --------------------------------------------------------------------------- #
IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/pybind11")
    message(STATUS "Adding pybind11 subdirectory.")
    add_subdirectory(pybind11)
ELSE()
    message(STATUS "Searching for pybind11...")
    find_package(pybind11 REQUIRED)
ENDIF()


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

# Subset of modules to build when TEST_BUILD is ON
set(TEST_MODULES AIS;
                 Aspect;
                 BRep;
                 BRepBuilderAPI;
                 BRepTools;
                 Geom;
                 gp;
                 Graphic3d;
                 IGESControl;
                 MeshVS;
                 OpenGl;
                 Quantity;
                 SMESH;
                 STEPControl;
                 TopoDS;
                 V3d;
                 XwWindow)

# Issue warning if TEST_BUILD is ON
if(TEST_BUILD)
    message(WARNING "WARNING: TEST_BUILD mode. Not all modules will be generated.")
endif()

# Be aware any *.cpp is assumed to be a module!
file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(MAKE_LIB BOOL ON)
foreach(SRC ${SRCS})
    get_filename_component(MOD ${SRC} NAME_WE)

    # Check for test modules
    list(FIND TEST_MODULES ${MOD} _INDEX)
    if(TEST_BUILD AND NOT ${_INDEX} GREATER -1)
        set(MAKE_LIB OFF)
    endif()

    # Check for SMESH modules
    list(FIND SMESH_MODULES ${MOD} _INDEX)
    if(NOT ENABLE_SMESH AND ${_INDEX} GREATER -1)
        message(STATUS "Skipping ${MOD}")
        set(MAKE_LIB OFF)
    endif()

    # Check Netgen
    if(NOT ENABLE_NETGEN AND ${MOD} STREQUAL "NETGENPlugin" AND MAKE_LIB)
        message(STATUS "Skipping ${MOD}")
        set(MAKE_LIB OFF)
    endif()

    # Check BLSURF
    if(NOT ENABLE_BLSURF AND ${MOD} STREQUAL "BLSURFPlugin" AND MAKE_LIB)
        message(STATUS "Skipping ${MOD}")
        set(MAKE_LIB OFF)
    endif()

    # Check for platform-specific modules
    if((WIN32 AND (${MOD} STREQUAL "XwWindow"))
        OR ((NOT WIN32) AND (${MOD} STREQUAL "WNT")))
            message(STATUS "Skipping platform-specific module ${MOD}")
            set(MAKE_LIB OFF)
    endif()

    if(MAKE_LIB)
        pybind11_add_module(${MOD} ${SRC})
        target_link_libraries(${MOD} PUBLIC ${OpenCASCADE_LIBRARIES}
                                            ${SMESH_ABS_LIBS})
        set_target_properties(${MOD} PROPERTIES SUFFIX ${EXTENSION} COMPILE_FLAGS ${WARNINGS})
        install(FILES ${OUTPUT_PATH}/${MOD}${EXTENSION}
                DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/OCCT)
    endif()
    set(MAKE_LIB ON)
endforeach()
