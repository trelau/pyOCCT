# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC
# Copyright (C) 2020 Trevor Laughlin and the pyOCCT contributors
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

from OCCT.Font import Font_FontMgr, Font_BRepTextBuilder, Font_FontAspect, Font_BRepFont
from OCCT.Graphic3d import Graphic3d_HTA_LEFT, Graphic3d_VTA_BOTTOM
from OCCT.NCollection import NCollection_String
from OCCT.TColStd import TColStd_SequenceOfHAsciiString
from OCCT.TCollection import TCollection_AsciiString
from OCCT.gp import gp_Ax3


class Test_Font_BRepFont(unittest.TestCase):
    """
    Test for Font_BRepFont class.
    """

    def test_Perform(self):
        """
        Test Font_BRepTextBuilder::Perform.
        """

        # Get a font (os dependent)
        font_names = TColStd_SequenceOfHAsciiString()
        font_mgr = Font_FontMgr.GetInstance_()
        font_mgr.GetAvailableFontsNames(font_names)
        self.assertGreater(font_names.Size(), 0)

        font_family = TCollection_AsciiString(font_names.First().ToCString())
        font_style = Font_FontAspect.Font_FA_Regular

        # Create the font
        font = Font_BRepFont()
        self.assertTrue(font.FindAndInit(font_family, font_style, 12.0))

        # Create builder
        builder = Font_BRepTextBuilder()

        # Parameters
        text = NCollection_String("pyOCCT".encode("utf-8"))
        pos = gp_Ax3()
        halign = Graphic3d_HTA_LEFT
        valign = Graphic3d_VTA_BOTTOM
        topods_shape = builder.Perform(font, text, pos, halign, valign)
        self.assertFalse(topods_shape.IsNull())


if __name__ == '__main__':
    unittest.main()
