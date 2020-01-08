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


class TestModuleImport(unittest.TestCase):
    """
    Test import of each module.
    """

    def test_BaseTraceCollector(self):
        try:
            import OCCT.BaseTraceCollector
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BasicsGenericDestructor(self):
        try:
            import OCCT.BasicsGenericDestructor
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Driver(self):
        try:
            import OCCT.Driver
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DriverDAT(self):
        try:
            import OCCT.DriverDAT
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DriverGMF(self):
        try:
            import OCCT.DriverGMF
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DriverSTL(self):
        try:
            import OCCT.DriverSTL
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DriverUNV(self):
        try:
            import OCCT.DriverUNV
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LocalTraceBufferPool(self):
        try:
            import OCCT.LocalTraceBufferPool
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_NETGENPlugin(self):
        try:
            import OCCT.NETGENPlugin
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SMDS(self):
        try:
            import OCCT.SMDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SMDSAbs(self):
        try:
            import OCCT.SMDSAbs
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SMESH(self):
        try:
            import OCCT.SMESH
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SMESHDS(self):
        try:
            import OCCT.SMESHDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdMeshers(self):
        try:
            import OCCT.StdMeshers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Utils(self):
        try:
            import OCCT.Utils
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)


if __name__ == '__main__':
    unittest.main()
