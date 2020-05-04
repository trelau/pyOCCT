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
import math
import unittest

from OCCT.Geom import Geom_SphericalSurface
from OCCT.gp import gp_Pnt, gp_Ax3, gp_Dir, gp_Sphere


class Test_Geom_Surface(unittest.TestCase):
    """
    Test for Geom_Surface class.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up with a Geom_SphericalSurface.
        """
        p = gp_Pnt()
        v = gp_Dir()
        a = gp_Ax3(p, v)
        s = gp_Sphere(a, 1.0)
        cls._surf = Geom_SphericalSurface(s)

    def test_Bounds(self):
        """
        Test Geom_Surface::Bounds.
        """
        u1, u2, v1, v2 = self._surf.Bounds(0, 0, 0, 0)

        self.assertAlmostEqual(u1, 0.0)
        self.assertAlmostEqual(u2, 2.0 * math.pi)
        self.assertAlmostEqual(v1, -0.5 * math.pi)
        self.assertAlmostEqual(v2, 0.5 * math.pi)

    def test_U1(self):
        """
        Test Geom_Surface::U1.
        """
        self.assertAlmostEqual(self._surf.U1(), 0.0)

    def test_U2(self):
        """
        Test Geom_Surface::U2.
        """
        self.assertAlmostEqual(self._surf.U2(), 2.0 * math.pi)

    def test_V1(self):
        """
        Test Geom_Surface::V1.
        """
        self.assertAlmostEqual(self._surf.V1(), -0.5 * math.pi)

    def test_V2(self):
        """
        Test Geom_Surface::V2.
        """
        self.assertAlmostEqual(self._surf.V2(), 0.5 * math.pi)


if __name__ == '__main__':
    unittest.main()
