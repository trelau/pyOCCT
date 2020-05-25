Overview
========
For now, extensions are relatively small, lightweight modules intended to
streamline basic OpenCASCADE functionality and make it more *pythonic*. They
should be small in scope and provide relatively generic capability to enable
users to more quickly develop their own applications. Development of
large-scale, special purpose toolkits or applications is outside the scope
of native pyOCCT functionality.

Exchange
========
The ``Exchange`` extension provides tools for data exchange including reading
and writing BREP, STEP, and/or IGES files. The tools can be imported as:

.. code-block:: python

    from OCCT.Exchange import *

    shape = ExchangeBasic.read_step('model.step')

The following tools are available:

.. table:: OCCT.Exchange tools.
   :widths: auto

   ================= ==========================================================
   Name              Description
   ================= ==========================================================
   ``ExchangeBasic`` Basic read/write static methods.
   ================= ==========================================================

Visualization
=============
A minimal viewing tool is provided in the ``Visualization`` extension. It can
be imported as:

.. code-block:: python

    from OCCT.Visualization import WxViewer

    v = ViewerWx()
    v.add(*args)
    v.start()

This is intended to provide only a minimum capability to display shapes to the
screen. Examine the source further for other methods and properties.

The following tools are available:

.. table:: OCCT.Visualization tools.
   :widths: auto

   ============ ==================================================================
   Name         Description
   ============ ==================================================================
   ``ViewerWx`` Basic viewing tool for shapes, geometry, and meshes using wxpython
   ============ ==================================================================
   ``ViewerQt`` Basic viewing tool for shapes, geometry, and meshes using Qt
   ============ ==================================================================
