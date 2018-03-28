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
import unittest

from OCCT.TopoDS import TopoDS_Shape, TopoDS_ListOfShape


class TestNCollectionList(unittest.TestCase):
    """
    Test for NCollection_List template
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
