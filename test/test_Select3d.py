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

from OCCT.Select3D import Select3D_SensitiveTriangle
from OCCT.SelectMgr import SelectMgr_EntityOwner
from OCCT.gp import gp_Pnt


class Test_Select3D_SensitiveTriangle(unittest.TestCase):
    """
    Test for Select3D_SensitiveTriangle class.
    """

    @classmethod
    def setUpClass(cls):
        p0 = gp_Pnt(1., 0., 0.)
        p1 = gp_Pnt(2., 0., 0.)
        p2 = gp_Pnt(2., 1., 0.)
        owner = SelectMgr_EntityOwner()
        cls.tri = Select3D_SensitiveTriangle(owner, p0, p1, p2)

    def test_Points3D(self):
        """
        Test if the points are updated by reference.
        """
        p0 = gp_Pnt()
        p1 = gp_Pnt()
        p2 = gp_Pnt()
        self.tri.Points3D(p0, p1, p2)
        self.assertAlmostEqual(p0.X(), 1.)
        self.assertAlmostEqual(p1.X(), 2.)
        self.assertAlmostEqual(p2.X(), 2.)
        self.assertAlmostEqual(p2.Y(), 1.)


if __name__ == '__main__':
    unittest.main()
