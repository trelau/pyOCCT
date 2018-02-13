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
from OCCT.BRepGProp import BRepGProp
from OCCT.GProp import GProp_GProps

from OCCT.Topology.Check import CheckTopology

__all__ = ['LinearProps', 'SurfaceProps', 'VolumeProps',
           'LengthOfShapes', 'AreaOfShapes']


class PropsBase(object):
    """
    Base class for shape properties.
    """

    def __init__(self):
        self._props = GProp_GProps()

    @property
    def mass(self):
        """
        :return: The mass of the shape. This corresponds to total length for
            linear properties, total area for surface properties, or total
            volume for volume properties.
        :rtype: float
        """
        return self._props.Mass()

    @property
    def cg(self):
        """
        :return: The center of gravity.
        :rtype: OCCT.gp.gp_Pnt
        """
        return self._props.CentreOfMass()

    @property
    def static_moments(self):
        """
        :return: The static moments of inertia Ix, Iy, and Iz.
        :rtype: tuple(float)
        """
        return self._props.StaticMoments(0., 0., 0.)

    def moment_of_inertia(self, axis):
        """
        Compute the moment of inertia about the axis.

        :param afem.geometry.entities.Axis1 axis: The axis.

        :return: The moment of inertia.
        :rtype: float
        """
        return self._props.MomentOfInertia(axis)


class LinearProps(PropsBase):
    """
    Calculate linear properties of a shape.

    :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
    :param bool skip_shared: If *True*, edges shared by two or more faces are
        taken into calculation only once.
    """

    def __init__(self, shape, skip_shared=False):
        super(LinearProps, self).__init__()
        BRepGProp.LinearProperties_(shape, self._props, skip_shared)

    @property
    def length(self):
        """
        :return: The total length of all edges of the shape.
        :rtype: float
        """
        return self.mass


class SurfaceProps(PropsBase):
    """
    Calculate surface properties of a shape.

    :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
    :param float tol: Maximum relative error of computed area for each face.
    :param bool skip_shared: If *True*, faces shared by two or more shells are
        taken into calculation only once.
    """

    def __init__(self, shape, tol=1.0e-7, skip_shared=False):
        super(SurfaceProps, self).__init__()
        BRepGProp.SurfaceProperties_(shape, self._props, tol, skip_shared)

    @property
    def area(self):
        """
        :return: The total area of all faces of the shape.
        :rtype: float
        """
        return self.mass


class VolumeProps(PropsBase):
    """
    Calculate volume properties of a shape.

    :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
    :param float tol: Maximum relative error of computed volume for each solid.
    :param bool only_closed: If *True*, then faces must belong to closed shells.
    :param bool skip_shared: If *True*, volumes formed by equal faces (i.e., the
        same TShape, location, and orientation) are taken into calculation only
        once.
    """

    def __init__(self, shape, tol=1.0e-7, only_closed=False,
                 skip_shared=False):
        super(VolumeProps, self).__init__()
        BRepGProp.VolumeProperties_(shape, self._props, tol, only_closed,
                                    skip_shared)

    @property
    def volume(self):
        """
        :return: The total volume of all solids of the shape.
        :rtype: float
        """
        return self.mass


class LengthOfShapes(object):
    """
    Calculate the total length of all edges of each shape and sort the results.

    :param list[OCCT.TopoDS.TopoDS_Shape] shapes: The shapes.
    """

    def __init__(self, shapes):
        results = []
        for shape in shapes:
            shape = CheckTopology.to_shape(shape)
            ls = LinearProps(shape).length
            results.append((ls, shape))

        results.sort(key=lambda tup: tup[0])
        self._lengths = [data[0] for data in results]
        self._shapes = [data[1] for data in results]

    @property
    def min_length(self):
        """
        :return: The minimum length.
        :rtype: float
        """
        return self._lengths[0]

    @property
    def max_length(self):
        """
        :return: The maximum length.
        :rtype: float
        """
        return self._lengths[-1]

    @property
    def sorted_lengths(self):
        """
        :return: List of sorted lengths.
        :rtype: list[float]
        """
        return self._lengths

    @property
    def shortest_shape(self):
        """
        :return: The shortest shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        return self._shapes[0]

    @property
    def longest_shape(self):
        """
        :return: The longest shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        return self._shapes[-1]

    @property
    def sorted_shapes(self):
        """
        :return: List of shapes sorted by length.
        :rtype: list[OCCT.TopoDS.TopoDS_Shape]
        """
        return self._shapes


class AreaOfShapes(object):
    """
    Calculate the total area of each face for each shape and sort the results.

    :param list[OCCT.TopoDS.TopoDS_Shape] shapes: The shapes.
    """

    def __init__(self, shapes):
        results = []
        for shape in shapes:
            shape = CheckTopology.to_shape(shape)
            a = SurfaceProps(shape).area
            results.append((a, shape))

        results.sort(key=lambda tup: tup[0])
        self._areas = [data[0] for data in results]
        self._shapes = [data[1] for data in results]

    @property
    def min_area(self):
        """
        :return: The minimum area.
        :rtype: float
        """
        return self._areas[0]

    @property
    def max_area(self):
        """
        :return: The maximum area.
        :rtype: float
        """
        return self._areas[-1]

    @property
    def sorted_areas(self):
        """
        :return: List of sorted areas.
        :rtype: list[float]
        """
        return self._areas

    @property
    def smallest_shape(self):
        """
        :return: The smallest shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        return self._shapes[0]

    @property
    def largest_shape(self):
        """
        :return: The largest shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        return self._shapes[-1]

    @property
    def sorted_shape(self):
        """
        :return: List of shapes sorted by area.
        :rtype: list[OCCT.TopoDS.TopoDS_Shape]
        """
        return self._shapes
