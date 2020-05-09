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
import math
import unittest

from OCCT.Aspect import Aspect_DisplayConnection
from OCCT.OpenGl import OpenGl_GraphicDriver
from OCCT.V3d import V3d_Viewer

try:
    display_connection = Aspect_DisplayConnection()
except RuntimeError:
    display_connection = None


@unittest.skipIf(display_connection is None, "No display connection")
class Test_V3d_View(unittest.TestCase):
    """
    Test for V3d_View class.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up with a V3d_View.
        """
        driver = cls._driver = OpenGl_GraphicDriver(display_connection)
        viewer = cls._viewer = V3d_Viewer(driver)
        cls._view = viewer.CreateView()

    def test_V3d_View_ChangeRenderingParams(self):
        """
        Test V3d_View::ChangeRenderingParams.
        """
        view = self._view

        # Update the value
        change_params = view.ChangeRenderingParams()
        new_value = not change_params.IsShadowEnabled
        change_params.IsShadowEnabled = new_value

        # Make sure it stuck
        params = view.RenderingParams()
        self.assertEqual(params.IsShadowEnabled, new_value)


if __name__ == '__main__':
    unittest.main()
