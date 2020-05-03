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

from OCCT.TColgp import TColgp_HArray1OfPnt, TColgp_Array1OfPnt, \
    TColgp_HSequenceOfPnt, TColgp_SequenceOfPnt
from OCCT.gp import gp_Pnt


class Test_TColgp_HArray1OfPnt(unittest.TestCase):
    """
    Test for TColgp_HArray1OfPnt class mostly to test binding of the
    DEFINE_HARRAY1 macro.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up for TColgp_HArray1OfPnt.
        """
        p1 = gp_Pnt()
        p2 = gp_Pnt(1, 0, 0)
        p3 = gp_Pnt(2, 0, 0)
        arr = TColgp_Array1OfPnt(1, 3)
        arr.SetValue(1, p1)
        arr.SetValue(2, p2)
        arr.SetValue(3, p3)
        cls._harr = TColgp_HArray1OfPnt(arr)

    def test_Array1(self):
        """
        Test TColgp_HArray1OfPnt::Array1
        """
        arr = self._harr.Array1()
        self.assertIsInstance(arr, TColgp_Array1OfPnt)
        self.assertEqual(arr.Length(), 3)
        p = arr.Value(1)
        self.assertAlmostEqual(p.X(), 0.)
        p = arr.Value(2)
        self.assertAlmostEqual(p.X(), 1.)
        p = arr.Value(3)
        self.assertAlmostEqual(p.X(), 2.)

    def test_Size(self):
        """
        Test TColgp_HArray1OfPnt::Size
        """
        self.assertEqual(self._harr.Size(), 3)

    def test_Length(self):
        """
        Test TColgp_HArray1OfPnt::Length
        """
        self.assertEqual(self._harr.Length(), 3)

    def test_Value(self):
        """
        Test TColgp_HArray1OfPnt::Value
        """
        p = self._harr.Value(1)
        self.assertAlmostEqual(p.X(), 0.)
        p = self._harr.Value(2)
        self.assertAlmostEqual(p.X(), 1.)
        p = self._harr.Value(3)
        self.assertAlmostEqual(p.X(), 2.)


class Test_TColgp_HSequenceOfPnt(unittest.TestCase):
    """
    Test for TColgp_HSequenceOfPnt class mostly to test binding of the
    DEFINE_HSEQUENCE macro.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up for TColgp_HSequenceOfPnt.
        """
        p1 = gp_Pnt()
        p2 = gp_Pnt(1, 0, 0)
        p3 = gp_Pnt(2, 0, 0)
        seq = TColgp_SequenceOfPnt()
        seq.Append(p1)
        seq.Append(p2)
        seq.Append(p3)
        cls._hseq = TColgp_HSequenceOfPnt(seq)

    def test_Sequence(self):
        """
        Test TColgp_HSequenceOfPnt::Sequence
        """
        seq = self._hseq.Sequence()
        self.assertIsInstance(seq, TColgp_SequenceOfPnt)
        self.assertEqual(seq.Length(), 3)
        p = seq.Value(1)
        self.assertAlmostEqual(p.X(), 0.)
        p = seq.Value(2)
        self.assertAlmostEqual(p.X(), 1.)
        p = seq.Value(3)
        self.assertAlmostEqual(p.X(), 2.)

    def test_Size(self):
        """
        Test TColgp_HSequenceOfPnt::Size
        """
        self.assertEqual(self._hseq.Size(), 3)

    def test_Length(self):
        """
        Test TColgp_HSequenceOfPnt::Length
        """
        self.assertEqual(self._hseq.Length(), 3)

    def test_Value(self):
        """
        Test TColgp_HSequenceOfPnt::Value
        """
        p = self._hseq.Value(1)
        self.assertAlmostEqual(p.X(), 0.)
        p = self._hseq.Value(2)
        self.assertAlmostEqual(p.X(), 1.)
        p = self._hseq.Value(3)
        self.assertAlmostEqual(p.X(), 2.)


if __name__ == '__main__':
    unittest.main()
