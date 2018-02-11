# pyOCCT — Python bindings for OpenCASCADE

[![Documentation Status](https://readthedocs.org/projects/pyocct/badge/?version=latest)](http://pyocct.readthedocs.io/en/latest/?badge=latest)
[![Join the chat at https://gitter.im/pyOCCT/Lobby](https://badges.gitter.im/pyOCCT/Lobby.svg)](https://gitter.im/pyOCCT/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

The **pyOCCT** project provides Python bindings to the OpenCASCADE 7.2.0
geometry kernel and SMESH 8.3.0 meshing library via pybind11. Together, this
technology stack enables rapid CAD/CAE application development in the popular
Python programming language.

Are you a pybind11 expert? If so, check out the
[Design Considerations](http://pyocct.readthedocs.io/en/latest/dev.html#design-considerations)
documentation and share your thoughts and ideas!

## Technology Stack
The pyOCCT core technology stack includes:

* [pybind11](https://github.com/pybind/pybind11): This is a lightweight
  header-only library that exposes C++ types to Python and proved to be a
  natural fit for the large and complex OpenCASCADE codebase.

* [OpenCASCADE](https://www.opencascade.com): This mature library provides
  advanced geometric modeling and CAD functionality and is under active
  development. Newer versions (i.e., beyond 7.0.0) provide robust and
  high-performance Boolean operations.

* [NETGEN](https://sourceforge.net/projects/netgen-mesher): This library
  enables advanced meshing capabilities including 3-D tetrahedral and 2-D
  unstructured quad-dominated surface meshing. The designated branch for the
  pyOCCT branch can be found [here](https://github.com/LaughlinResearch/NETGEN).

* [Salome Platform](http://www.salome-platform.org): The core meshing library
  from this open source application serves as the central component for
  pyOCCT's mesh generation capabilities. A standalone version of the meshing
  library can be found [here](https://github.com/LaughlinResearch/SMESH).

## Resources
More resources for using, developing, and navigating the pyOCCT project will be
made available, but for now the OpenCASCADE C++ documentation provides the most
complete set of information. The pyOCCT interface should be very similar to its
C++ counterpart. More resources will be available soon.

* [OpenCASCADE Technology Overview](https://www.opencascade.com/doc/occt-7.2.0/overview/html/index.html)
* [OpenCASCADE Reference Manual](https://www.opencascade.com/doc/occt-7.2.0/refman/html/index.html)
* [Chat on Gitter](https://gitter.im/pyOCCT/Lobby)
* [Submit issues](https://github.com/LaughlinResearch/pyOCCT/issues)

# Getting Started
Detailed build instructions and CI services will be available soon so check
back for more information. Until then, users with access to a Windows 64-bit
machine and Python 3.5 can use the prebuilt binaries already in the *OCCT*
folder.

## Requirements
The following tools and libraries should be available to build, install, or
use pyOCCT. The links are meant to provide useful references or recommendations
but are not necessarily the only place to find them.

### Core
Core components for pyOCCT:

* **C++11 compiler (Required)**: Visual Studio 14 has been used so far.

* **Python 2.X or 3.X (Required)**: So far 3.5 has been tested but support for
  2.7 and 3.X is anticipated.

* **pybind11 (Required)**: Version 2.3dev0 has been used but latest needs
  verified. Get it [here](https://github.com/pybind/pybind11).

* **OpenCASCADE 7.2.0 (Required)**: Available from [OPEN CASCADE SAS](https://www.opencascade.com/content/latest-release)
  or [conda-forge](https://anaconda.org/conda-forge/occt).

* **SMESH 8.3.0 (Optional)**: Standalone version [here](https://github.com/LaughlinResearch/SMESH).

* **Netgen 6.2 (Optional)**: Special SMESH version [here](https://github.com/LaughlinResearch/NETGEN).

* **PySide 1.2.4 (Optional)**: To support minimal visualization in Python.

### Supporting
Supporting components are listed below along with what core component they
support:

* **Tk 8.5 (OpenCASCADE)**

* **Freetype 2.7 (OpenCASCADE)**

* **tbb 2018_20170919 (OpenCASCADE)**

* **VTK 7.1.1 (SMESH)**

* **pthreads (SMESH)**

## Using Prebuilt Binaries
Prebuilt binaries for pyOCCT are provided for Windows 64-bit Python 3.5 in the
*OCCT* folder. Anaconda Python is recommended for package management and since
many packages are available for some of the prerequisites.

It is recommended that a designated environment be created and used for pyOCCT.
An example of creating this environment for Anaconda Python within an Anaconda
command prompt is:

    conda create -n occt python=3.5

This will create an environment named "occt" with Python 3.5. Make sure this
environment is active when using pyOCCT. For Anaconda Python, activating this
environment may look like:

    activate occt

within an Anaconda command prompt. At this point the prerequisites can be
installed using specified channels on the Anaconda cloud:

    conda install -c conda-forge occt=7.2.0

This should automatically resolve all dependencies and install all the
required packages for the OpenCASCADE binaries. Please note that 7.2.0 vc14
is required and a later patch (7.2.0.1) that shows up on the conda-forge
channel will result in package conflicts with the required version of VTK. For
some users it has been a challenge to force install that exact version (a fix
would be welcomed).

The SMESH binaries depend on The Visualization Toolkit (VTK) and "pthreads" and
can be installed with:

    conda install -c conda-forge vtk=7.1.1 pthreads-win32=2.9.1

pyOCCT can be installed using the command:

    python setup.py install

within the pyOCCT root folder. This will provide the "OCCT" package:

    from OCCT.TopoDS import TopoDS_Shape

Binaries for SMESH and NETGEN are already included in the prebuilt OCCT
distribution.

Navigate to the *examples* folder and run:

    python import_step.py
    
and you should see the following image in the viewing tool if all the
requirements are correctly installed.

![compressor](./docs/source/resources/compressor.jpg)

Installation files can be cleaned up by:

    conda clean -a
    
Please note that the prebuilt binaries will eventually be removed as CI
services become available and the build process is better documented. They are
only there now to provide a quick-start for users.

# Help Wanted
For now, contributions to the source code will be incorporated manually. There
is a (mostly) automated tool for generating the source but it needs some
attention before being made publicly available. As new versions of OpenCASCADE
are released, it may be better to just patch up the existing bindings rather
than rerun the binding generation tool anyway. The automated process still
requires a handful of manual patches to capture edge cases. Although, if the
header files of new OpenCASCADE releases are significantly different or there
is an architectural change in pyOCCT, it makes sense to use the automated tool.
The automated tool will eventually be released, and improvements can be made
that hopefully automated the process entirely.

In addition to the items in the
[Design Considerations](http://pyocct.readthedocs.io/en/latest/dev.html#design-considerations)
section in the documentation, some areas that could use contributor support:

* Improve robustness of CMake build process and add support for targeting other
  platforms and architectures
* Leverage CI platforms like AppVeyor and Travis-CI
* Support for building and deploying Conda packages
* Tests, examples, and benchmarks
* Fix conda-forge OCCT version issue described in installation instructions
* There are a number of *unresolved externals* that show up during the build
  process but are ignored. In some cases, this is due to the OCCT header files
  providing an interface but there is no implementation in the source. A better
  way to handle this could be useful.
* The source code generation tool will comment out known issues and usually add
  a `// FIXME` line to something that is causing compilation problems. Figuring
  out what the root issue is would be helpful.
* Better exception handling
* The example visualization tool in *examples/display.py* could use review.
  When the program terminates an error message is reported from OpenCASCADE
  but the root issue has not been resolved.
