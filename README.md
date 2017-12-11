# pyOCCT
The pyOCCT project provides Python bindings to the OpenCASCADE geometry kernel
and Salome SMESH meshing library.

# Installation
pyOCCT is currently only supported for Windows 64-bit Python 3.5. Anaconda
Python is recommended for package management and since pre-built binaries are
available for some of the prerequisites.

The core libraries exposed are available from the following organizations:
* [OpenCASCADE](https://www.opencascade.com)
* [SMESH](http://www.salome-platform.org)
* [NETGEN](https://sourceforge.net/projects/netgen-mesher)

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
required packages for the OpenCASCADE binaries.

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

Binaries for SMESH and NETGEN are already included in the OCCT distribution.

# Optional MeshGems License
Optional support for Distene's MeshGems MGCAD-Surf commercial surface meshing
technology is provided but requires a separate license.

# Notice
Copyright (c) 2017, Laughlin Research, LLC

Terms of Use:

The pyOCCT Code, including its source code and related software
documentation (collectively, the "pyOCCT Code"), as distributed herein 
and as may be subsequently revised, in whole and in part, is for 
government use only pursuant to development agreements between NASA, 
Georgia Institute of Technology, and Laughlin Research, LLC. At the 
time of distribution hereof, none of the pyOCCT Code is believed or 
intended to be open source. Disclosure of the pyOCCT Code is strictly 
subject to one or more restrictive covenants, including 
non-disclosure and non-circumvention covenants, and any use of the 
whole or a part of the pyOCCT Code constitutes acknowledgement and 
acceptance of said covenants. Any unauthorized use, disclosure, 
and/or sale of the pyOCCT Code or any portion thereof may be actionable
under current law.

Laughlin Research, LLC retains all commercial rights to the pyOCCT Code.
