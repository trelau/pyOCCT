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

from OCCT.BRepPrimAPI import BRepPrimAPI_MakeBox
from OCCT.TopoDS import TopoDS_Shape, TopoDS_ListOfShape


class Test_TopoDS_Shape(unittest.TestCase):
    """
    Test for TopoDS_Shape class.
    """

    def test_hash(self):
        """
        Test __hash__ method.
        """
        s1 = BRepPrimAPI_MakeBox(1, 1, 1).Shape()
        s2 = BRepPrimAPI_MakeBox(1, 1, 1).Shape()
        s3 = BRepPrimAPI_MakeBox(1, 1, 1).Shape()

        self.assertEqual(len({s1, s2, s3}), 3)
        self.assertEqual(len({s1, s1, s2}), 2)


class Test_TopoDS_ListOfShape(unittest.TestCase):
    """
    Test for TopoDS_ListOfShape class.
    """

    def test_iter(self):
        """
        Test __iter__ method.
        """
        s1 = TopoDS_Shape()
        s2 = TopoDS_Shape()
        s3 = TopoDS_Shape()
        shape_list = TopoDS_ListOfShape()
        shape_list.Append(s1)
        shape_list.Append(s2)
        shape_list.Append(s3)
        self.assertEqual(shape_list.Size(), 3)
        for s in shape_list:
            self.assertIsInstance(s, TopoDS_Shape)


if __name__ == '__main__':
    unittest.main()
