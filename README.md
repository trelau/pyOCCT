# pyOCCT — Python bindings for OpenCASCADE

[![Documentation Status](https://readthedocs.org/projects/pyocct/badge/?version=latest)](http://pyocct.readthedocs.io/en/latest/?badge=latest)
[![Join the chat at https://gitter.im/pyOCCT/Lobby](https://badges.gitter.im/pyOCCT/Lobby.svg)](https://gitter.im/pyOCCT/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

[![Anaconda-Server Badge](https://anaconda.org/trelau/pyocct/badges/installer/conda.svg)](https://conda.anaconda.org/trelau/pyocct)
[![Anaconda-Server Badge](https://anaconda.org/trelau/pyocct/badges/platforms.svg)](https://anaconda.org/trelau/pyocct)
[![Anaconda-Server Badge](https://anaconda.org/trelau/pyocct/badges/downloads.svg)](https://anaconda.org/trelau/pyocct)
[![Anaconda-Server Badge](https://anaconda.org/trelau/pyocct/badges/latest_release_date.svg)](https://anaconda.org/trelau/pyocct)

The **pyOCCT** project provides Python bindings to the OpenCASCADE 7.4.0
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

* [Netgen](https://sourceforge.net/projects/netgen-mesher): This library
  enables advanced meshing capabilities including 3-D tetrahedral and 2-D
  unstructured quad-dominated surface meshing.

* [Salome Platform](http://www.salome-platform.org): The core meshing library
  from this open source application serves as the central component for
  pyOCCT's mesh generation capabilities.

## Resources
More resources for using, developing, and navigating the pyOCCT project will be
made available, but for now the OpenCASCADE C++ documentation provides the most
complete set of information. The pyOCCT interface should be very similar to its
C++ counterpart. More resources will be available soon.

* [OpenCASCADE Technology Overview](https://www.opencascade.com/doc/occt-7.4.0/overview/html/index.html)
* [OpenCASCADE Reference Manual](https://www.opencascade.com/doc/occt-7.4.0/refman/html/index.html)
* [OpenCASCADE forums](https://www.opencascade.com/forums)
* [OpenCASCADE issue tracker](https://tracker.dev.opencascade.org/)
* [Chat on Gitter](https://gitter.im/pyOCCT/Lobby)
* [Submit issues](https://github.com/LaughlinResearch/pyOCCT/issues)

# Getting Started
[Anaconda Python](https://www.anaconda.com/) (or [Miniconda](https://conda.io/miniconda.html))
is recommended for package management and installation. It is recommended that
a designated environment be created and used for pyOCCT. An example of
creating this environment for Anaconda Python within an Anaconda command prompt
is:

    conda create -n pyocct python=3.7

This will create an environment named "pyocct" with Python 3.7. Make sure this
environment is active when using pyOCCT. For Anaconda Python, activating this
environment may look like:

    activate pyocct

The easiest and fastest way to get started is using the conda build from the
Anaconda cloud:

    conda install -c conda-forge -c laughlinresearch pyocct

To support minimal visualization the wxPython package is required and can be
installed via conda by:

    conda install -c conda-forge wxpython

At this point the ``OCCT`` package should be available:

    from OCCT.TopoDS import TopoDS_Shape

Navigate to the *examples/* folder and run:

    python import_step.py

and you should see the following image in the viewing tool if all the
requirements are correctly installed.

![compressor](./docs/source/resources/compressor.jpg)

Installation files can be cleaned up by:

    conda clean -a
