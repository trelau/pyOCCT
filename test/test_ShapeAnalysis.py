# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC
# Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors
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
import unittest

from OCCT.BRepBuilderAPI import (BRepBuilderAPI_MakeEdge,
                                 BRepBuilderAPI_MakeWire)
from OCCT.ShapeAnalysis import ShapeAnalysis_FreeBounds
from OCCT.TopTools import TopTools_HSequenceOfShape
from OCCT.gp import gp_Pnt


class Test_ShapeAnalysis_FreeBounds(unittest.TestCase):
    """
    Test for ShapeAnalysis_FreeBounds class.
    """

    def test_ConnectEdgesToWires(self):
        """
        Test ShapeAnalysis_FreeBounds::ConnectEdgesToWires
        """
        p1 = gp_Pnt()
        p2 = gp_Pnt(1, 0, 0)
        e1 = BRepBuilderAPI_MakeEdge(p1, p2).Edge()

        p3 = gp_Pnt(1, 1, 0)
        e2 = BRepBuilderAPI_MakeEdge(p2, p3).Edge()

        seq = TopTools_HSequenceOfShape()
        seq.Append(e1)
        seq.Append(e2)

        wires = ShapeAnalysis_FreeBounds.ConnectEdgesToWires_(seq,
                                                              1.0e-7,
                                                              False)
        self.assertFalse(wires.IsEmpty())
        self.assertEqual(wires.Length(), 1)

    def test_ConnectWiresToWires(self):
        """
        Test ShapeAnalysis_FreeBounds::ConnectWiresToWires
        """
        p1 = gp_Pnt()
        p2 = gp_Pnt(1, 0, 0)
        e1 = BRepBuilderAPI_MakeEdge(p1, p2).Edge()
        w1 = BRepBuilderAPI_MakeWire(e1).Wire()

        p3 = gp_Pnt(1, 1, 0)
        e2 = BRepBuilderAPI_MakeEdge(p2, p3).Edge()
        w2 = BRepBuilderAPI_MakeWire(e2).Wire()

        seq = TopTools_HSequenceOfShape()
        seq.Append(w1)
        seq.Append(w2)

        wires = ShapeAnalysis_FreeBounds.ConnectWiresToWires_(seq,
                                                              1.0e-7,
                                                              False)
        self.assertFalse(wires.IsEmpty())
        self.assertEqual(wires.Length(), 1)


if __name__ == '__main__':
    unittest.main()
