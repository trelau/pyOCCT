Overview
========
For now, toolkits are relatively small, lightweight modules intended to
streamline basic OpenCASCADE functionality and make it more *pythonic*. They
should be small in scope and provide relatively generic capability to enable
users to more quickly develop their own applications. Development of
large-scale, special purpose toolkits or applications is outside the scope
of native pyOCCT functionality.

Boolean
=======
The ``Boolean`` toolkit provides helper classes for OpenCASCADE Boolean
operations which can be safely imported by:

.. code-block:: python

    from OCCT.Boolean import *

Exchange
========
The ``Exchange`` toolkit provides helper classes for basic data exchange
include reading and writing BREP, STEP, and/or IGES files. The utilities can be
imported as:

.. code-block:: python

    from OCCT.Exchange import ExchangeBasic

    shape = ExchangeBasic.read_step('model.step')

The ``ExchangeBasic`` class uses only simple static methods to
read and write data.

Topology
========
The ``topology`` toolkit provides a number of helper classes to streamline
topology operations including Boolean operations. All of the helper classes
can be safely imported using:

.. code-block:: python

    from OCCT.Topology import *

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
