Overview
========
For now, extensions are relatively small, lightweight modules intended to
streamline basic OpenCASCADE functionality and make it more *pythonic*. They
should be small in scope and provide relatively generic capability to enable
users to more quickly develop their own applications. Development of
large-scale, special purpose toolkits or applications is outside the scope
of native pyOCCT functionality.

Boolean
=======
The ``Boolean`` extension provides tools for OpenCASCADE Boolean operations
which can be safely imported by:

.. code-block:: python

    from OCCT.Boolean import *

The following tools are available:

.. table:: OCCT.Boolean tools.
   :widths: auto

   ====================== =====================================================
   Name                   Description
   ====================== =====================================================
   ``FuseShapes``         Fuse operation with BRepAlgoAPI_Fuse.
   ``CutShapes``          Cut operation with BRepAlgoAPI_Cut.
   ``CommonShapes``       Common operation with BRepAlgoAPI_Common.
   ``IntersectShapes``    Section operation with BRepAlgoAPI_Section.
   ``SplitShapes``        Split operation with BRepAlgoAPI_Splitter.
   ``VolumeMaker``        Make volumes with BOPAlgo_MakerVolume.
   ``CutCylindricalHole`` Cut cylindrical hole in a shape using
                          BRepFeat_MakeCylindricalHole
   ``SplitLocal``         Split a shape in the context of a basis shape.
   ``SplitShapeByEdges``  Split a shape using edges.
   ====================== =====================================================

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
   ``ImportVSP``     Special tool for translating OpenVSP models in solids.
   ================= ==========================================================

The NASA OpenVSP tool is available `here <www.openvsp.org/>`_.

Topology
========
The ``Topology`` extension provides a number of tools to streamline working
with topology (i.e., shapes). The tools can be safely imported using:

.. code-block:: python

    from OCCT.Topology import *

The following tools are available:

.. table:: OCCT.Topology tools.
   :widths: auto

   ======================== ===================================================
   Name                     Description
   ======================== ===================================================
   ``CheckShape``           Methods to check shape basic validity and type.
   ``ClassifyPointInSolid`` Classify a point in/on/out of a solid.
   ``CreateShape``          Methods to create shapes.
   ``ExploreShape``         Basic methods to explore shapes and get sub-shapes.
   ``ExploreWire``          Explore the edges of a wire.
   ``ExploreFreeEdges``     Analyze the free edges of a shape.
   ``FixShape``             Attempt to fix a shape or limit tolerance.
   ``LinearProps``          Linear shape properties.
   ``SurfaceProps``         Surface shape properties.
   ``VolumeProps``          Volume shape properties.
   ``LengthOfShapes``       Length of all shape edges.
   ``AreaOfShapes``         Area of all shape faces.
   ``TopologyUtils``        Utility methods like converting between Python list
                            and ``TopTools_ListOfShape``.
   ======================== ===================================================

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
