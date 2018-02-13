# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
from datetime import datetime
from warnings import warn

from OCCT.BOPAlgo import BOPAlgo_MakerVolume, BOPAlgo_Options
from OCCT.BRepAlgoAPI import (BRepAlgoAPI_Common, BRepAlgoAPI_Cut,
                              BRepAlgoAPI_Fuse, BRepAlgoAPI_Section,
                              BRepAlgoAPI_Splitter)
from OCCT.BRepFeat import BRepFeat_MakeCylindricalHole, BRepFeat_SplitShape
from OCCT.Geom import Geom_Surface
from OCCT.Message import Message_Gravity
from OCCT.TopTools import TopTools_SequenceOfShape
from OCCT.TopoDS import TopoDS_Face, TopoDS, TopoDS_Shape

from OCCT.Exchange import ExchangeBasic
from OCCT.Topology.Check import CheckTopology
from OCCT.Topology.Create import CreateTopology
from OCCT.Topology.Explore import ExploreTopology
from OCCT.Topology.Utils import TopologyUtils

__all__ = ['FuseShapes', 'CutShapes', 'CommonShapes', 'IntersectShapes',
           'SplitShapes', 'VolumeMaker', 'CutCylindricalHole', 'SplitLocal',
           'SplitShapeByEdges']

# Turn on parallel Boolean execution by default
BOPAlgo_Options.SetParallelMode_(True)

# Message gravities
_gravities = [Message_Gravity.Message_Trace, Message_Gravity.Message_Info,
              Message_Gravity.Message_Warning, Message_Gravity.Message_Alarm,
              Message_Gravity.Message_Fail]


class BopCore(object):
    """
    Core class for Boolean operations and enabling attributes and methods for
    rebuilding shapes.
    """

    def __init__(self):
        self._bop = None

    def build(self):
        """
        Build the results.

        :return: None.
        """
        if isinstance(self._bop, BOPAlgo_MakerVolume):
            self._bop.Perform()
        else:
            self._bop.Build()

    @property
    def is_done(self):
        """
        :return: *True* if operation is done, *False* if not.
        :rtype: bool
        """
        if isinstance(self._bop, (BOPAlgo_MakerVolume,
                                  BRepFeat_MakeCylindricalHole)):
            return not self._bop.HasErrors()
        return self._bop.IsDone()

    @property
    def shape(self):
        """
        :return: The resulting shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        return self._bop.Shape()

    def modified(self, shape):
        """
        Return a list of shapes modified from the given shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: List of modified shapes.
        :rtype: list(OCCT.TopoDS.TopoDS_Shape)
        """
        toptools_list = self._bop.Modified(shape)
        return TopologyUtils.to_list_from_TopTools_ListofShape(toptools_list)

    def generated(self, shape):
        """
        Return a list of shapes generated from the given shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: List of generated shapes.
        :rtype: list(OCCT.TopoDS.TopoDS_Shape)
        """
        toptools_list = self._bop.Generated(shape)
        return TopologyUtils.to_list_from_TopTools_ListofShape(toptools_list)

    def is_deleted(self, shape):
        """
        Check to see if shape is deleted.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: *True* if deleted, *False* if not.
        :rtype: bool
        """
        return self._bop.IsDeleted(shape)


class BopAlgo(BopCore):
    """
    Base class for Boolean operations.

    :param shape1: The first shape.
    :type shape1: OCCT.TopoDS.TopoDS_Shape or None
    :param shape2: The second shape.
    :type shape2: OCCT.TopoDS.TopoDS_Shape or None
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.
    :param bop: The OpenCASCADE class for the Boolean operation.

    .. note::

        If *shape1* or *shape2* is *None* then the user is expected to manually
        set the arguments and tools and build the result.
    """

    def __init__(self, shape1, shape2, fuzzy_val, nondestructive, bop):
        super(BopAlgo, self).__init__()

        self._bop = bop()

        if fuzzy_val is not None:
            self._bop.SetFuzzyValue(fuzzy_val)

        if nondestructive:
            self._bop.SetNonDestructive(True)
        else:
            self._bop.SetNonDestructive(False)

        if CheckTopology.is_shape(shape1) and CheckTopology.is_shape(shape2):
            self.set_args([shape1])
            self.set_tools([shape2])
            self.build()

    @staticmethod
    def set_parallel_mode(flag):
        """
        Global option to set the Boolean operations for parallel execution.

        :param bool flag: Option for parallel execution. *True* turns parallel
            execution on, *False* turns it off.

        :return: None.
        """
        BOPAlgo_Options.SetParallelMode_(flag)

    def debug(self, path='.'):
        """
        Export files for debugging Boolean operations.

        :param path:

        :return:
        """
        # Generate a suffix using timestamp
        now = datetime.now()
        timestamp = str(now.timestamp())

        # Operation name for prefix
        op = str(self.__class__.__name__)

        # Info file
        fn = ''.join([path, '/', op, '.info.', timestamp, '.txt'])
        info = open(fn, 'w')
        info.write('Date (M-D-Y): {}-{}-{}\n'.format(now.month, now.day,
                                                     now.year))
        info.write('Operation: {}\n'.format(op))
        info.write('Parallel: {}\n'.format(self._bop.RunParallel()))
        info.write('Fuzzy value: {}\n'.format(self._bop.FuzzyValue()))
        info.write('Nondestructive: {}\n'.format(self._bop.NonDestructive()))

        # Errors and warnings report
        msg_report = self._bop.GetReport()
        for gravity in _gravities:
            msg_list = msg_report.GetAlerts(gravity)
            if msg_list.Size() == 0:
                continue
            info.write('Messages:\n')
            for msg in msg_list:
                info.write('\t{}\n'.format(msg.GetMessageKey()))

        # Arguments
        args = self.arguments
        if args:
            shape1 = CreateTopology.compound(args)
            fn = ''.join([path, '/', op, '.shape1.', timestamp, '.brep'])
            ExchangeBasic.write_brep(shape1, fn)

        # Tools
        tools = self.tools
        if tools:
            shape2 = CreateTopology.compound(tools)
            fn = ''.join([path, '/', op, '.shape2.', timestamp, '.brep'])
            ExchangeBasic.write_brep(shape2, fn)

    @property
    def arguments(self):
        """
        :return: The arguments.
        :rtype: list(OCCT.TopoDS.TopoDS_Shape)
        """
        args = self._bop.Arguments()
        return TopologyUtils.to_list_from_TopTools_ListofShape(args)

    @property
    def tools(self):
        """
        :return: The tools.
        :rtype: list(OCCT.TopoDS.TopoDS_Shape)
        """
        tools = self._bop.Tools()
        return TopologyUtils.to_list_from_TopTools_ListofShape(tools)

    def set_args(self, shapes):
        """
        Set the arguments.

        :param list(OCCT.TopoDS.TopoDS_Shape) shapes: The arguments.

        :return: None.
        """
        if isinstance(self._bop, BOPAlgo_MakerVolume):
            for shape in shapes:
                self._bop.AddArgument(shape)
            return None
        args = TopologyUtils.to_TopTools_ListOfShape(shapes)
        self._bop.SetArguments(args)

    def set_tools(self, shapes):
        """
        Set the tools.

        :param list(OCCT.TopoDS.TopoDS_Shape) shapes: The tools.

        :return: None.
        """
        if isinstance(self._bop, BOPAlgo_MakerVolume):
            warn('Setting tools not available. Doing nothing.', RuntimeWarning)
            return None

        tools = TopologyUtils.to_TopTools_ListOfShape(shapes)
        self._bop.SetTools(tools)

    @property
    def vertices(self):
        """
        :return: The vertices of the resulting shape.
        :rtype: list(OCCT.TopoDS.TopoDS_Vertex)
        """
        return ExploreTopology.get_vertices(self.shape)

    @property
    def edges(self):
        """
        :return: The edges of the resulting shape.
        :rtype: list(OCCT.TopoDS.TopoDS_Edge)
        """
        return ExploreTopology.get_edges(self.shape)

    def refine_edges(self):
        """
        Fuse C1 edges.

        :return: None.
        """
        if isinstance(self._bop, (BRepAlgoAPI_Splitter, BOPAlgo_MakerVolume,
                                  BRepFeat_MakeCylindricalHole)):
            warn('Refining edges not available. Doing nothing.',
                 RuntimeWarning)
        else:
            self._bop.RefineEdges()

    @property
    def fuse_edges(self):
        """
        :return: The result flag of edge refining.
        :rtype: bool
        """
        if isinstance(self._bop, (BRepAlgoAPI_Splitter, BOPAlgo_MakerVolume,
                                  BRepFeat_MakeCylindricalHole)):
            return False
        else:
            return self._bop.FuseEdges()

    @property
    def section_edges(self):
        """
        :return: A list of section edges as a result of intersection between
            the shapes.
        :rtype: list(OCCT.TopoDS.TopoDS_Edge)
        """
        if isinstance(self._bop, (BRepAlgoAPI_Splitter, BOPAlgo_MakerVolume,
                                  BRepFeat_MakeCylindricalHole)):
            warn('Getting section edges not available. Returning an empty '
                 'list.', RuntimeWarning)
            return []
        else:
            edges = self._bop.SectionEdges()
            return TopologyUtils.to_list_from_TopTools_ListofShape(edges)

    @property
    def has_modified(self):
        """
        :return: *True* if there is at least one modified shape.
        :rtype: bool
        """
        return self._bop.HasModified()

    @property
    def has_generated(self):
        """
        :return: *True* if there is at least one generated shape.
        :rtype: bool
        """
        return self._bop.HasGenerated()

    @property
    def has_deleted(self):
        """
        :return: *True* if there is at least one deleted shape.
        :rtype: bool
        """
        return self._bop.HasDeleted()


class FuseShapes(BopAlgo):
    """
    Boolean fuse operation.

    :param shape1: The first shape.
    :type shape1: OCCT.TopoDS.TopoDS_Shape or None
    :param shape2: The second shape.
    :type shape2: OCCT.TopoDS.TopoDS_Shape or None
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.

    .. note::

        If *shape1* or *shape2* is *None* then the user is expected to manually
        set the arguments and tools and build the result.

    For more information see BRepAlgoAPI_Fuse_.

    .. _BRepAlgoAPI_Fuse: https://www.opencascade.com/doc/occt-7.2.0/refman/html/class_b_rep_algo_a_p_i___fuse.html

    """

    def __init__(self, shape1=None, shape2=None, fuzzy_val=None,
                 nondestructive=False):
        super(FuseShapes, self).__init__(shape1, shape2, fuzzy_val,
                                         nondestructive, BRepAlgoAPI_Fuse)


class CutShapes(BopAlgo):
    """
    Boolean cut operation.

    :param shape1: The first shape.
    :type shape1: OCCT.TopoDS.TopoDS_Shape or None
    :param shape2: The second shape.
    :type shape2: OCCT.TopoDS.TopoDS_Shape or None
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.

    .. note::

        If *shape1* or *shape2* is *None* then the user is expected to manually
        set the arguments and tools and build the result.

    For more information see BRepAlgoAPI_Cut_.

    .. _BRepAlgoAPI_Cut: https://www.opencascade.com/doc/occt-7.2.0/refman/html/class_b_rep_algo_a_p_i___cut.html

    """

    def __init__(self, shape1=None, shape2=None, fuzzy_val=None,
                 nondestructive=False):
        super(CutShapes, self).__init__(shape1, shape2, fuzzy_val,
                                        nondestructive, BRepAlgoAPI_Cut)


class CommonShapes(BopAlgo):
    """
    Boolean common operation.

    :param shape1: The first shape.
    :type shape1: OCCT.TopoDS.TopoDS_Shape or None
    :param shape2: The second shape.
    :type shape2: OCCT.TopoDS.TopoDS_Shape or None
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.

    .. note::

        If *shape1* or *shape2* is *None* then the user is expected to manually
        set the arguments and tools and build the result.

    For more information see BRepAlgoAPI_Common_.

    .. _BRepAlgoAPI_Common: https://www.opencascade.com/doc/occt-7.2.0/refman/html/class_b_rep_algo_a_p_i___common.html

    """

    def __init__(self, shape1=None, shape2=None, fuzzy_val=None,
                 nondestructive=False):
        super(CommonShapes, self).__init__(shape1, shape2, fuzzy_val,
                                           nondestructive, BRepAlgoAPI_Common)


class IntersectShapes(BopAlgo):
    """
    Boolean intersect operation.

    :param shape1: The first shape.
    :type shape1: OCCT.TopoDS.TopoDS_Shape or OCCT.Geom.Geom_Surface
    :param shape2: The second shape.
    :type shape2: OCCT.TopoDS.TopoDS_Shape or OCCT.Geom.Geom_Surface
    :param bool compute_pcurve1: Option to compute p-curves on shape 1.
    :param bool compute_pcurve2: Option to compute p-curves on shape 2.
    :param bool approximate: Option to approximate intersection curves.
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.

    .. note::

        If *shape1* or *shape2* is *None* then the user is expected to manually
        set the arguments and tools and build the result.

    For more information see BRepAlgoAPI_Section_.

    .. _BRepAlgoAPI_Section: https://www.opencascade.com/doc/occt-7.2.0/refman/html/class_b_rep_algo_a_p_i___section.html

    """

    def __init__(self, shape1=None, shape2=None, compute_pcurve1=False,
                 compute_pcurve2=False, approximate=False, fuzzy_val=None,
                 nondestructive=False):
        super(IntersectShapes, self).__init__(None, None, fuzzy_val,
                                              nondestructive,
                                              BRepAlgoAPI_Section)

        self._bop.ComputePCurveOn1(compute_pcurve1)
        self._bop.ComputePCurveOn2(compute_pcurve2)
        self._bop.Approximation(approximate)

        build1, build2 = False, False
        if isinstance(shape1, (TopoDS_Shape, Geom_Surface)):
            self._bop.Init1(shape1)
            build1 = True

            if isinstance(shape2, (TopoDS_Shape, Geom_Surface)):
                self._bop.Init2(shape2)
            build2 = True

        if build1 and build2:
            self._bop.Build()

    def has_ancestor_face1(self, edge):
        """
        Get the ancestor face on the intersection edge on the first shape
        if available.

        :param OCCT.TopoDS.TopoDS_Edge edge: The edge.

        :return: *True* and the face if available, *False* and *None* if not.
        :rtype: tuple(bool, OCCT.TopoDS.TopoDS_Face or None)
        """
        f = TopoDS_Face()
        if self._bop.HasAncestorFaceOn1(edge, f):
            return True, f
        return False, None

    def has_ancestor_face2(self, edge):
        """
        Get the ancestor face on the intersection edge on the second shape
        if available.

        :param OCCT.TopoDS.TopoDS_Edge edge: The edge.

        :return: *True* and the face if available, *False* and *None* if not.
        :rtype: tuple(bool, OCCT.TopoDS.TopoDS_Face or None)
        """
        f = TopoDS_Face()
        if self._bop.HasAncestorFaceOn2(edge, f):
            return True, f
        return False, None


class SplitShapes(BopAlgo):
    """
    Split arbitrary shapes. This is a wrapper for the SALOME
    GEOMAlgo_Splitter tool.

    :param shape1: The first shape.
    :type shape1: OCCT.TopoDS.TopoDS_Shape or None
    :param shape2: The second shape.
    :type shape2: OCCT.TopoDS.TopoDS_Shape or None
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.

    .. note::

        If *shape1* or *shape2* is *None* then the user is expected to manually
        set the arguments and tools and build the result.

    """

    def __init__(self, shape1=None, shape2=None, fuzzy_val=None,
                 nondestructive=False):
        super(SplitShapes, self).__init__(shape1, shape2, fuzzy_val,
                                          nondestructive,
                                          BRepAlgoAPI_Splitter)


class VolumeMaker(BopAlgo):
    """
    Build solids from a list of shapes.

    :param list(OCCT.TopoDS.TopoDS_Shape) shapes: The shapes.
    :param bool intersect: Option to intersect the shapes before building
        solids.
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.
    """

    def __init__(self, shapes, intersect=False, fuzzy_val=None,
                 nondestructive=False):
        super(VolumeMaker, self).__init__(None, None, fuzzy_val,
                                          nondestructive,
                                          BOPAlgo_MakerVolume)

        self.set_args(shapes)

        if intersect:
            self._bop.SetIntersect(True)
        else:
            self._bop.SetIntersect(False)

        self.build()

        self._solids = []
        for solid in ExploreTopology.get_solids(self.shape):
            self._solids.append(TopoDS.Solid_(solid))

    @property
    def box(self):
        """
        :return: The bounding box of all provided shapes.
        :rtype: OCCT.TopoDS.TopoDS_Solid
        """
        return self._bop.Box()

    @property
    def nsolids(self):
        """
        :return: The number of solids in the shape.
        :rtype: int
        """
        return len(self.solids)

    @property
    def solids(self):
        """
        :return: The list of solids.
        :rtype: list(OCCT.TopoDS.TopoDS_Solid)
        """
        return self._solids


class CutCylindricalHole(BopAlgo):
    """
    Cut a cylindrical hole on a shape.

    :param shape: The shape.
    :type shape: OCCT.TopoDS.TopoDS_Shape
    :param float radius: The radius of the hole.
    :param OCCT.gp.gp_Ax1: The axis for the hole.
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.
    """

    def __init__(self, shape, radius, ax1, fuzzy_val=None,
                 nondestructive=False):
        super(CutCylindricalHole, self).__init__(None, None, fuzzy_val,
                                                 nondestructive,
                                                 BRepFeat_MakeCylindricalHole)

        self._bop.Init(shape, ax1)
        self._bop.Perform(radius)


class SplitLocal(BopCore):
    """
    Perform a local split of a shape in the context of a basis shape. This tool
    only splits faces.

    :param OCCT.TopoDS.TopoDS_Shape shape: The local shape.
    :param tool: The tool to split with.
    :type tool: OCCT.TopoDS.TopoDS_Shape or OCCT.Geom.Geom_Surface
    :param OCCT.TopoDS.TopoDS_Shape basis_shape: The basis shape that the local
        shape is part of.
    :param bool approximate: Option to approximate intersection curves.
    :param float fuzzy_val: Fuzzy tolerance value.
    :param bool nondestructive: Option to not modify the input shapes.
    """

    def __init__(self, shape, tool, basis_shape, approximate=False,
                 fuzzy_val=None, nondestructive=False):
        super(SplitLocal, self).__init__()

        # Intersect
        section = IntersectShapes(shape, tool, True, False, approximate,
                                  fuzzy_val, nondestructive)
        sec_edges = section.edges

        # Split
        self._bop = BRepFeat_SplitShape(basis_shape)
        for e in sec_edges:
            status, f = section.has_ancestor_face1(e)
            if status:
                self._bop.Add(e, f)
        self.build()


class SplitShapeByEdges(BopCore):
    """
    Split a shape using edges.

    :param OCCT.TopoDS.TopoDS_Shape shape: The basis shape.
    :param edges: The edges to split the shape with. If provided, then the
        results will be built during initialization. If none are provided then
        the user is expected to add edges and build manually.
    :type edges: collections.Sequence(OCCT.TopoDS.TopoDS_Edge) or None
    :param bool check_interior: Option to check internal intersections.

    """

    def __init__(self, shape, edges=None, check_interior=True):
        super(SplitShapeByEdges, self).__init__()

        self._bop = BRepFeat_SplitShape(shape)

        if not check_interior:
            self._bop.SetCheckInterior(False)

        if edges is not None:
            edge_seq = TopTools_SequenceOfShape()
            for e in edges:
                edge_seq.Append(e)
            self._bop.Add(edge_seq)
            self.build()

    def add_edges(self, shapes):
        """
        Add splittings edges or wires for the initial shape.

        :param collections.Sequence(OCCT.TopoDS.TopoDS_Shape) shapes: The
            splitting edges or wires.

        :return: *True* if added, *False* if not.
        :rtype: bool
        """
        seq = TopTools_SequenceOfShape()
        for s in shapes:
            seq.Append(s)
        return self._bop.Add(seq)

    def add_wire_on_face(self, w, f):
        """
        Add the wire on the face.

        :param OCCT.TopoDS.TopoDS_Wire w: The wire.
        :param OCCT.TopoDS.TopoDS_Face f: The face.

        :return: None.
        """
        self._bop.Add(w, f)

    def add_edge_on_face(self, e, f):
        """
        Add the edge on the face.

        :param OCCT.TopoDS.TopoDS_Edge e: The edge.
        :param OCCT.TopoDS.TopoDS_Face f: The face.

        :return: None
        """
        self._bop.Add(e, f)

    def add_edges_on_face(self, e, f):
        """

        :param collections.Sequence(OCCT.TopoDS.TopoDS_Edge) e: The edges.
        :param OCCT.TopoDS.TopoDS_Face f: The face.

        :return: None
        """
        cmp = CreateTopology.compound(e)
        self._bop.Add(cmp, f)

    def add_edge_on_edge(self, e1, e2):
        """
        Add the edge on an existing edge.

        :param OCCT.TopoDS.TopoDS_Edge e1: The edge.
        :param OCCT.TopoDS.TopoDS_Edge e2: The existing edge.

        :return: None.
        """
        self._bop.Add(e1, e2)
