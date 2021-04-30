# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018 Laughlin Research, LLC
# Copyright (C) 2019-2020 Trevor Laughlin and pyOCCT contributors
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
cmake_minimum_required(VERSION 3.15...3.20)
project(pyOCCT VERSION 7.5.1.0 LANGUAGES C CXX)


# --------------------------------------------------------------------------- #
# OPTIONS
# --------------------------------------------------------------------------- #
option(ENABLE_WARNINGS "Disable warning output." OFF)


# --------------------------------------------------------------------------- #
# SETTINGS
# --------------------------------------------------------------------------- #
set(pyOCCT_MAJOR_VERSION 7)
set(pyOCCT_MINOR_VERSION 5)
set(pyOCCT_PATCH_VERSION 1)
set(pyOCCT_TWEAK_VERSION 0)

if(WIN32)
    set(EXTENSION ".pyd")
else(WIN32)
    set(EXTENSION ".so")
endif(WIN32)

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

if(NOT MSVC)
    # TODO: Figure out how to handle methods that return functions
    message(STATUS "Flags: ${CMAKE_CXX_FLAGS}")
    message(STATUS "Linker flags: ${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-z,defs")
endif()


# --------------------------------------------------------------------------- #
# PYTHON and PYBIND11
# --------------------------------------------------------------------------- #
message(STATUS "Searching for Python and pybind11...")
find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)


# --------------------------------------------------------------------------- #
# TBB (for BVH header)
# --------------------------------------------------------------------------- #
message(STATUS "Searching for TBB...")
find_package(TBB REQUIRED)


# --------------------------------------------------------------------------- #
# OpenGL
# --------------------------------------------------------------------------- #
message(STATUS "Searching for OpenGL...")
if(WIN32 OR APPLE)
    find_package(OpenGL REQUIRED)
else()
    find_package(OpenGL REQUIRED GLX EGL)
endif()

message(STATUS "OpenGL include directory: ${OPENGL_INCLUDE_DIR}")
message(STATUS "OpenGL libraries: ${OPENGL_LIBRARIES}")
include_directories(${OPENGL_INCLUDE_DIR})


# --------------------------------------------------------------------------- #
# Freetype
# --------------------------------------------------------------------------- #
message(STATUS "Searching for freetype...")
find_package(Freetype REQUIRED)


# --------------------------------------------------------------------------- #
# GLEW
# --------------------------------------------------------------------------- #
message(STATUS "Searching for GLEW...")
find_package(GLEW REQUIRED)

# --------------------------------------------------------------------------- #
# X11
# --------------------------------------------------------------------------- #
if(NOT WIN32 AND NOT APPLE)
    find_package(X11 REQUIRED)
endif()

# --------------------------------------------------------------------------- #
# OpenCASCADE
# --------------------------------------------------------------------------- #
# Must be included before opencascade so the InterfaceGraphic.hxx patch works
include_directories(inc)
if(NOT DEFINED OpenCASCADE_INCLUDE_DIR OR NOT DEFINED OpenCASCADE_LIBRARY_DIR)
    message(STATUS "Searching for OpenCASCADE...")
    find_package(OpenCASCADE 7.5.1 REQUIRED)
endif()

if(NOT EXISTS ${OpenCASCADE_INCLUDE_DIR})
    message(FATAL_ERROR "Failed to find OpenCASCADE include directory.")
endif()

if(NOT EXISTS ${OpenCASCADE_LIBRARY_DIR})
    message(FATAL_ERROR "Failed to find OpenCASCADE library directory.")
endif()

include_directories(${OpenCASCADE_INCLUDE_DIR})
link_directories(${OpenCASCADE_LIBRARY_DIR})


# ----------------------------------------------------------------------- #
# VTK
# ----------------------------------------------------------------------- #
message(STATUS "Searching for VTK...")
find_package(VTK REQUIRED CommonCore)


# --------------------------------------------------------------------------- #
# pyOCCT
# --------------------------------------------------------------------------- #
set(OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")

# Treat each .cxx file in src/modules as a module
file(GLOB OCCT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx)

# OCCT modules
foreach(SRC ${OCCT_SRCS})

    # Get module name
    get_filename_component(MOD ${SRC} NAME_WE)

    # Check for platform-specific modules
    if((WIN32 OR APPLE) AND ${MOD} STREQUAL "Xw")
        message(STATUS "Skipping platform-specific module ${MOD}")
        continue()
    endif()

    if(NOT WIN32 AND ${MOD} STREQUAL "WNT")
        message(STATUS "Skipping platform-specific module ${MOD}")
        continue()
    endif()

    if(NOT APPLE AND ${MOD} STREQUAL "Cocoa")
        message(STATUS "Skipping platform-specific module ${MOD}")
        continue()
    endif()

    # Add pybind11 module
    pybind11_add_module(${MOD} ${SRC})
    target_link_libraries(${MOD} PUBLIC ${OpenCASCADE_LIBRARIES}
                                        ${Python_LIBRARIES})

    if(${MOD} STREQUAL "OpenGl")
        target_link_libraries(${MOD} PRIVATE ${OPENGL_LIBRARIES})
    endif()

    set_target_properties(${MOD} PROPERTIES SUFFIX ${EXTENSION} COMPILE_FLAGS ${WARNINGS})
    target_include_directories(${MOD} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
    install(FILES ${OUTPUT_PATH}/${MOD}${EXTENSION}
            DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/OCCT)
endforeach()
