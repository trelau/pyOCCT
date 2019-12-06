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

from OCCT.BRepAlgoAPI import BRepAlgoAPI_Fuse
from OCCT.Message import Message_Report, Message_Gravity, Message_ListOfAlert


class Test_BRepAlgoAPI_Algo(unittest.TestCase):
    """
    Test for inherited methods from BRepAlgoAPI_Algo.
    """

    @classmethod
    def setUpClass(cls):
        """
        Use BRepAlgoAPI_Fuse to test methods.
        """
        cls._bop = BRepAlgoAPI_Fuse()

    def test_Clear(self):
        """
        Test BRepAlgoAPI_Algo::Clear.
        """
        self.assertIsNone(self._bop.Clear())

    def test_SetRunParallel(self):
        """
        Test BRepAlgoAPI_Algo::SetRunParallel.
        """
        self.assertIsNone(self._bop.SetRunParallel(True))
        self.assertTrue(self._bop.RunParallel())

    def test_RunParallel(self):
        """
        Test BRepAlgoAPI_Algo::RunParallel.
        """
        self.assertFalse(self._bop.RunParallel())

    def test_SetFuzzyValue(self):
        """
        Test BRepAlgoAPI_Algo::SetFuzzyValue.
        """
        self._bop.SetFuzzyValue(1.0)
        self.assertAlmostEqual(self._bop.FuzzyValue(), 1.0)

    def test_FuzzyValue(self):
        """
        Test BRepAlgoAPI_Algo::FuzzyValue.
        """
        self.assertAlmostEqual(self._bop.FuzzyValue(), 1.0e-7)

    def test_HasErrors(self):
        """
        Test BRepAlgoAPI_Algo::HasErrors.
        """
        self.assertFalse(self._bop.HasErrors())

    def test_HasWarnings(self):
        """
        Test BRepAlgoAPI_Algo::HasWarnings.
        """
        self.assertFalse(self._bop.HasWarnings())

    def test_GetReport(self):
        """
        Test BRepAlgoAPI_Algo::GetReport.
        """
        report = self._bop.GetReport()
        self.assertIs(type(report), Message_Report)

        alerts = report.GetAlerts(Message_Gravity.Message_Info)
        self.assertIs(type(alerts), Message_ListOfAlert)
        self.assertEqual(alerts.Size(), 0)


if __name__ == '__main__':
    unittest.main()
