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

from OCCT.AIS import AIS_Line, AIS_PointCloud
from OCCT.Geom import Geom_CartesianPoint


class Test_AIS_Line(unittest.TestCase):
    """
    Test for AIS_Line class.
    """

    def test_Points(self):
        """
        Test AIS_Line::Points method.
        """
        p1 = Geom_CartesianPoint(1., 2., 3.)
        p2 = Geom_CartesianPoint(10., 20., 30.)
        line = AIS_Line(p1, p2)

        p3 = Geom_CartesianPoint(0., 0., 0.)
        p4 = Geom_CartesianPoint(0., 0., 0.)
        p3, p4 = line.Points(p3, p4)

        self.assertAlmostEqual(p3.X(), 1.)
        self.assertAlmostEqual(p3.Y(), 2.)
        self.assertAlmostEqual(p3.Z(), 3.)

        self.assertAlmostEqual(p4.X(), 10.)
        self.assertAlmostEqual(p4.Y(), 20.)
        self.assertAlmostEqual(p4.Z(), 30.)


class Test_AIS_Point_Cloud(unittest.TestCase):
    """
    Test for AIS_PointCloud class.
    """

    def test_SelectionMode(self):
        """
        Test for AIS_PointCloud::SelectionMode enum.
        """
        self.assertEqual(int(AIS_PointCloud.SM_Points), 0)
        self.assertEqual(int(AIS_PointCloud.SM_SubsetOfPoints), 1)
        self.assertEqual(int(AIS_PointCloud.SM_BndBox), 2)


if __name__ == '__main__':
    unittest.main()
