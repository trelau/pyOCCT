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
from OCCT.TopTools import TopTools_ListOfShape

__all__ = ['TopologyUtils']


class TopologyUtils(object):
    """
    Utilities for topology.
    """

    @staticmethod
    def to_TopTools_ListOfShape(shapes):
        """
        Create TopTools_ListOfShape from a list of shapes.

        :param list(OCCT.TopoDS.TopoDS_Shape) shapes: List of shapes.

        :return: TopTools_ListOfShape
        :rtype: OCCT.TopTools.TopTools_ListOfShape
        """
        lst = TopTools_ListOfShape()
        for s in shapes:
            lst.Append(s)
        return lst

    @staticmethod
    def to_list_from_TopTools_ListofShape(toptools_list):
        """
        Create a list of shapes from a TopTools_ListOfShape.

        :param OCCT.TopTools.TopTools_ListOfShape toptools_list: The
            TopTools_ListOfShape.

        :return: A list of shapes.
        :rtype: list(OCCT.TopoDS.TopoDS_Shape)
        """
        return [s for s in toptools_list]
