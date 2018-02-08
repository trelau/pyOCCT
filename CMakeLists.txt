cmake_minimum_required(VERSION 2.8)
project(pyOCCT)

# DEFINITIONS
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /FORCE")

# OCCT
find_package(OpenCASCADE REQUIRED)
include_directories(${OpenCASCADE_INCLUDE_DIR})
link_directories(${OpenCASCADE_LIBRARY_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenCASCADE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenCASCADE_CXX_FLAGS}")

# NETGEN
find_package(NETGEN REQUIRED)
include_directories(${NETGEN_INCLUDE_DIR})

# SMESH
find_package(SMESH REQUIRED)
include_directories(${SMESH_INCLUDE_PATH})
link_directories(${SMESH_LIB_PATH})
# Build full library paths since they have the same name as the Python libraries
set(SMESH_ABS_LIBS)
foreach(LIB ${SMESH_LIBRARIES})
    set(FOUND_LIB "FOUND_LIB-NOTFOUND")
    find_library(FOUND_LIB ${LIB} PATHS ${SMESH_LIB_PATH})
    list(APPEND SMESH_ABS_LIBS ${FOUND_LIB})
endforeach(LIB)
unset(FOUND_LIB CACHE)

# VTK
find_package(VTK REQUIRED)
include_directories(${VTK_INCLUDE_DIRS})

# Boost 
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# pthread
set(pthread_INCLUDE_DIRS "" CACHE PATH "Path to pthread.h")
include_directories(${pthread_INCLUDE_DIRS})

#BLSURF
set(MESHGEMS_INCLUDE "" CACHE PATH "MeshGems include directory.")
include_directories(${MESHGEMS_INCLUDE})

# PYTHON
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

# PYBIND11
add_subdirectory(pybind11)

# pyOCCT
include_directories(inc)
set(OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/ CACHE PATH "Targets output path.")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_PATH}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_PATH}")

if(WIN32)
	set(EXTENSION ".pyd")
else(WIN32)
	set(EXTENSION ".so")
endif(WIN32)

# BUILD AND INSTALL
file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
foreach(SRC ${SRCS})
    get_filename_component(MOD ${SRC} NAME_WE)
    pybind11_add_module(${MOD} ${SRC})
    target_link_libraries(${MOD} PUBLIC ${OpenCASCADE_LIBRARIES} ${SMESH_ABS_LIBS})
    set_target_properties(${MOD} PROPERTIES SUFFIX ${EXTENSION})
    install(FILES ${OUTPUT_PATH}/${MOD}${EXTENSION} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/OCCT)
endforeach(SRC)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/cmake/__init__.py DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/OCCT)
