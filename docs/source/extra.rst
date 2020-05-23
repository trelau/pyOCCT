How to Cite pyOCCT
==================
The following Bibtex template can be used to cite the pyOCCT project in
scientific publications:

.. code-block:: bash

    @misc{pyOCCT,
       author = {Trevor Laughlin},
       year = {2020},
       note = {https://github.com/LaughlinResearch/pyOCCT},
       title = {pyOCCT -- Python bindings for OpenCASCADE via pybind11}
    }

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

.. _PythonOCC: https://github.com/tpaviot/pythonocc-core
