About
=====
The **pyOCCT** project provides Python bindings to the OpenCASCADE geometry
kernel and SMESH meshing library via pybind11. Together, this technology stack
enables rapid CAD/CAE application development in the popular Python programming
language.

Technology Stack
----------------
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
  3-D tetrahedral and 2-D unstructured quad-dominated surface meshing. The
  designated branch for the pyOCCT branch can be found
  `here <https://github.com/LaughlinResearch/NETGEN>`_.

* `Salome Platform <http://www.salome-platform.org>`_: The core meshing library
  from this open source application serves as the central component for
  pyOCCT's mesh generation capabilities. A standalone version of the meshing
  library can be found `here <https://github.com/LaughlinResearch/SMESH>`_.

Resources
---------
More resources for using, developing, and navigating the pyOCCT project will be
made available, but for now the OpenCASCADE C++ documentation provides the most
complete set of information. The pyOCCT interface should be very similar to its
C++ counterpart. More resources will be available soon.

* `OpenCASCADE Technology Overview <https://www.opencascade.com/doc/occt-7.2.0/overview/html/index.html>`_
* `OpenCASCADE Reference Manual <https://www.opencascade.com/doc/occt-7.2.0/refman/html/index.html>`_
* `Chat on Gitter <https://gitter.im/pyOCCT/Lobby>`_
* `Submit issues <https://github.com/LaughlinResearch/pyOCCT/issues>`_

Design Considerations
=====================
This section describes some fundamental assumptions and implementation details
for the pyOCCT project, most of which relate to pybdind11 usage. Feedback is
welcomed on these topics based on usage experience and expertise.

Static Methods
--------------
To avoid naming conflicts with regular instance methods, the names of static
methods are modified by appending a trailing underscore. For example, the code

.. code:: python

    edge = TopoDS.Edge_(shape)

uses the static method ``TopoDS::Edge`` to downcast a shape to an edge if
possible. The trailing underscore was selected as a global rule to avoid naming
conflicts and inform the user they are calling a static method.

Templates
---------
The OpenCASCADE library is a large and complex codebase that makes use of
modern C++ features including templates. Compared to earlier versions, the
latest releases of OpenCASCADE define a number of different types by
instantiating a set of core class templates. To more closely follow the
OpenCASCADE architecture and avoid repetitive code, function templates are used
whenever possible to bind types derived from an OpenCASCADE class template.
These templates are provided in the *inc/* folder and in theory there should be
one function template for each OpenCASCADE class template. In the appropriate
module, the function template can be called with essentially the same
parameters as its OpenCASCADE counterpart, with the addition of the current
pybind11 module and its desired name.

As an example, binding the type ``TopoDS_ListOfShape`` in the ``TopoDS`` module
looks like

.. code:: cpp

    bind_NCollection_List<TopoDS_Shape>(mod, "TopoDS_ListOfShape");

where ``mod`` is the pybind11 module. This seems to be a fairly efficient and
easily maintained implementation, but feedback and suggestions are welcomed.

Holder Types
------------
TODO: A few items to be explained further:

* Use of ``std::unique_ptr<>`` for the holder type of all types unless derived
  from  ``Standard_Transient``

* For ``Standard_Transient`` types, use the ``opencascade::handle<>`` as the
  holder type which has been registered using ``PYBIND11_DECLARE_HOLDER_TYPE``
  macro

Protected Destructors
---------------------
Describe use of ``py::nodelete`` capability for types with protected or private
destructors.

Known Issues
============
TODO: This is a summary of some known issues:

* Methods like `ShapeAnalysis_FreeBounds::ConnectEdgesToWires` take in a
  `TopTools_HSequenceOfShape` which is modified on the C++ side to contain the
  resulting wires. In the source, they use
  `owires = new TopTools_HSequenceOfShape` to I think clear the list. At this
  point I think this breaks the associativity to the Python variable as the
  provided variable is not changed. For now, this is avoided by using a lambda
  function in the bindings and the resulting wires are returned rather than
  modified as an input.

Build
=====
TODO: Complete when CI is available...

Install
=======
TODO: Complete when CI is available...

PythonOCC Comparison
====================
The overall organization between **pyOCCT** and PythonOCC_ is very similar. The
most noticeable difference is that the installed package is called ``OCCT``
instead of ``OCC`` and the concept of handles as described below.

Static Methods
--------------
In OCC, static methods are converted to module level methods with their
name following the format ``modulename_MethodName()``. In pyOCCT, static
methods are within the class but have a trailing underscore. The trailing
underscore was needed to avoid naming conflicts with regular class methods.
For example, the method to convert a generic ``TopoDS_Shape`` to a
``TopoDS_Edge`` in PythonOCC is::

  from OCC.TopoDS import topods_Edge

In pyOCCT, this is now::

  from OCCT.TopoDS import TopoDS

and the method is called as::

  edge = TopoDS.Edge_(shape)

GetHandle() and GetObject()
---------------------------
In PythonOCC, a Python object wrapping an OpenCASCADE type usually had a
method called ``GetHandle()`` which would return a ``Handle_*`` instance (e.g.,
``Handle_Geom_Curve``), or a ``GetObject()`` method to return the underlying
object if you have a ``Handle_*`` instance on the Python side. The OpenCASCADE
``opencascade::handle<Type>`` is their own implementation of a smart pointer
for memory management. In pyOCCT, the binding technology actually uses
the OpenCASCADE handle as a custom smart pointer (everything is wrapped by a
smart pointer in pybind11) so on the Python side the wrapped type actually
serves as **both** the object and the handle. Methods that returned a
``Handle_*`` instance in PythonOCC will now return the specific type (i.e.,
``Handle_Geom_Curve`` now just comes back as a ``Geom_Curve``). There is no
more ``GetHandle()`` or ``GetObject()`` methods. Methods and/or classes that
require a handle as an input can now just be supplied the pyOCCT instance.

Return Types
------------
In pybind11, return types are resolved to their most specific type before
being returned to Python. This is not the case in C++ where a type may be
returned and then require additional downcasting to get a more specific type.
This may provide a more *pythonic* interface, but the user should be aware
that the return types may not exactly much the C++ documentation, although
since they will be a sub-class they should have the same functionality. For
example, copying a line in PythonOCC may have looked like::

  handle_geom = line.Copy()
  new_line = Handle_Geom_Line.Downcast(handle_geom).GetObject()

where in pyOCCT it will now look like::

  new_line = line.Copy()

with ``new_line`` being of type ``Geom_Line``. There are no more ``Handle_*``
types available to import or use.

Iterators
---------
Some types support iteration like ``NCollection_List<TheItemType>`` which is
used as the template for the ``TopoDS_ListOfShape`` type. So now the user can
do something like::

        slist = TopoDS_ListOfShape()
        slist.Append(item1)
        slist.Append(item2)

        for item in slist:
            do something...

.. _PythonOCC: https://github.com/tpaviot/pythonocc-core