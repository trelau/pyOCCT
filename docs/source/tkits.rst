Exchange
========
The ``Exchange`` toolkit provides utilities for data exchange include reading
and writing BREP, STEP, and/or IGES files. The utilities can be imported as:

.. code-block:: python

    from OCCT.Exchange import (read_brep, read_iges, read_step,
                               write_brep, write_iges, write_step)

For now it is a minimal set of utilities for only the simplest forms of data
exchange. See the source code for further information.

Visualization
=============
A minimal viewing utility is provided in the ``Visualization`` toolkit. It can
be imported as:

.. code-block:: python

    from OCCT.Visualization import Viewer

    v = Viewer()
    v.add(*args)
    v.start()

where ``*args`` is a number of ``TopoDS_Shape`` entities to display. This is
intended to provide only a minimum capability to display shapes to the screen.
Examine the source further for other methods and properties.
