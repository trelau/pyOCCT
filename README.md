[![Join the chat at https://gitter.im/pyOCCT/Lobby](https://badges.gitter.im/pyOCCT/Lobby.svg)](https://gitter.im/pyOCCT/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

# pyOCCT
The pyOCCT project provides Python bindings to the OpenCASCADE 7.2.0 geometry
kernel and SMESH 8.3.0 meshing library from the Salome Platform. This project
began as a way to test the suitability of using the pybind11 technology for a
large and complex C++ codebase like the OpenCASCADE modeling kernel.For that
reason, change should be expected and feedback and contributions are welcome.
The project was made open source to solicit any improvements while the overall
architecture and approach are still (relatively) easy to adapt. Please see
the *TODO* section below for a quick introduction to some existing issues and
needs. The documentation includes more specific design considerations that are
open for discussion.

# Installation
Prebuilt binaries for pyOCCT are provided for Windows 64-bit Python 3.5.
Anaconda Python is recommended for package management and since packages are
available for some of the prerequisites.

The core libraries exposed and enabling technologies are available from the
following organizations:
* [OpenCASCADE](https://www.opencascade.com)
* [Salome](http://www.salome-platform.org)
* [NETGEN](https://sourceforge.net/projects/netgen-mesher)
* [pybind11](https://github.com/pybind/pybind11)

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
    
Installation files can be cleaned by:

    conda clean -a

# Installing pyOCCT
Be sure to activate the designated pyOCCT environment before installation.

pyOCCT can be installed using the command:

    python setup.py install

within the pyOCCT root folder. This will provide the "OCCT" package:

    from OCCT.TopoDS import TopoDS_Shape

Binaries for SMESH and NETGEN are already included in the prebuilt OCCT
distribution.

# TODO
This project is in early development and change should be expected. Eventually,
the prebuilt binaries in the `OCCT` folder will be removed as CI services like
AppVeyor, Travis-CI, and Conda are supported. The prebuilt binaries are only to
give users a quick start.

Some areas that could use contributor support:

* Improve robustness of CMake build process and add support for targeting other
  platforms and architectures
* Leverage CI platforms like AppVeyor and Travis-CI
* Support for building and deploying Conda packages
* Tests, examples, and benchmarks
* Fix conda-forge OCCT version issue described in installation instructions
* Improvement of minimal visualization tool in the *examples/display*
* There are a number of *unresolved externals* that show up during the build
  process but are ignored. In some cases, this is due to the OCCT header files
  providing an interface but there is no implementation in the source. A better
  way to handle this could be useful.
* The source code generation tool will comment out known issues and usually add
  a `// FIXME` line to something that is causing compilation problems. Figuring
  out what the root issue is would be helpful.
* Better exception handling

## Contributing
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

## Building
To build pyOCCT from source the following resources are needed:

* [pybind11](https://github.com/pybind/pybind11): You should make a pybind11
  subdirectory in the pyOCCT source folder for the CMake process to work. Some
  further testing and work needs to be done to verify the exact version that
  will work. That is, the local version used to build the binaries is somewhere
  between the last release and master. The subdirectory used locally is a
  symbolic link that points to the local pybind11 repo.
* [NETGEN](https://github.com/LaughlinResearch/NETGEN): This version of NETGEN
  is for integration into SMESH and pyOCCT.
* [SMESH](https://github.com/LaughlinResearch/SMESH): This standalone version
  of the meshing library from the Salome Platform is required.
* [MeshGems](http://meshgems.com): Distene SAS provides a commercial mesh
  generation library that has been integrated into the Salome Platform. The
  binaries are available in the Salome Platform distribution and support for
  the BLSURFPlugin was experimented with at one point and time. The MeshGems
  binaries are not included in this project and require a license from Distene.
  Continued support for the BLSURFPlugin module is not intended and for now is
  just left over from previous work.
  
As CI services for these prerequisites come online the build process for pyOCCT
will be updated as needed.
