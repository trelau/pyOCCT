About
=====
The **pyOCCT** project provides Python bindings to the OpenCASCADE geometry
kernel and SMESH meshing library via pybind11. Together, this technology stack
enables rapid CAD/CAE application development in the popular Python programming
language.

Technology Stack
================
The pyOCCT core technology stack includes:

* `pybind11 <https://github.com/pybind/pybind11>`_: This is a lightweight
  header-only library that exposes C++ types to Python and proved to be a
  natural fit for the large and complex OpenCASCADE codebase.

* `OpenCASCADE <https://www.opencascade.com>`_: This mature library provides
  advanced geometric modeling and CAD functionality and is under active
  development. Newer versions (i.e., beyond 7.0.0) provide robust and
  high-performance Boolean operations.

* `NETGEN <https://sourceforge.net/projects/netgen-mesher>`_: This library
  enables advanced meshing capabilities to support CAE applications including
  3-D tetrahedral and 2-D unstructured quad-dominated surface meshing.

* `Salome Platform <http://www.salome-platform.org>`_: The core meshing library
  from this open source application serves as the central component for
  pyOCCT's mesh generation capabilities.

Resources
=========
More resources for using, developing, and navigating the pyOCCT project will be
made available, but for now the OpenCASCADE C++ documentation provides the most
complete set of information. The pyOCCT interface should be very similar to its
C++ counterpart. More resources will be available soon.

* `OpenCASCADE Technology Overview <https://www.opencascade.com/doc/occt-7.2.0/overview/html/index.html>`_
* `OpenCASCADE Reference Manual <https://www.opencascade.com/doc/occt-7.2.0/refman/html/index.html>`_
* `Chat on Gitter <https://gitter.im/pyOCCT/Lobby>`_
* `Submit issues <https://github.com/LaughlinResearch/pyOCCT/issues>`_
