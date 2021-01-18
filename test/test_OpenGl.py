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

from OCCT.Aspect import Aspect_DisplayConnection
from OCCT.OpenGl import OpenGl_GraphicDriver


class Test_OpenGl_GraphicsDriver(unittest.TestCase):
    """
    Test for OpenGl_GraphicsDriver.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up graphic driver.
        """
        aspect_display_connection = Aspect_DisplayConnection()
        cls._graphic_driver = OpenGl_GraphicDriver(aspect_display_connection)

    def test_ChangeOptions(self):
        """
        Test for OpenGl_GraphicDriver::ChangeOptions.
        """
        change_opts = self._graphic_driver.ChangeOptions()
        self.assertFalse(change_opts.sRGBDisable)

        # Set true
        change_opts.sRGBDisable = not change_opts.sRGBDisable

        # Make sure it stuck
        opts = self._graphic_driver.Options()
        self.assertEqual(opts.sRGBDisable, change_opts.sRGBDisable)


if __name__ == '__main__':
    unittest.main()
