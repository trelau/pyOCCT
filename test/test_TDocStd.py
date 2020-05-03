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
from os.path import join, dirname

from OCCT.PCDM import PCDM_ReaderStatus
from OCCT.TCollection import TCollection_ExtendedString
from OCCT.TDocStd import TDocStd_Document
from OCCT.XCAFApp import XCAFApp_Application
from OCCT.XmlXCAFDrivers import XmlXCAFDrivers


class Test_TDocStd_Application(unittest.TestCase):
    """
    Test for TDocStd_Application class.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up for TDocStd_Application class.
        """
        cls._app = XCAFApp_Application.GetApplication_()
        XmlXCAFDrivers.DefineFormat_(cls._app)

    def test_Open(self):
        """
        Test TDocStd_Application::Open.
        """
        fmt = TCollection_ExtendedString('XmlXCAF')
        doc = TDocStd_Document(fmt)

        self._app.InitDocument(doc)

        filename = join(dirname(__file__), 'test_io', 'named_box.xml')

        fn = TCollection_ExtendedString(filename)
        status, doc = self._app.Open(fn, doc)

        self.assertEqual(PCDM_ReaderStatus.PCDM_RS_OK, status)
        self.assertFalse(doc.IsEmpty())
        self.assertEqual(doc.FileExtension().ToExtString(), 'xml')

        self._app.Close(doc)


if __name__ == '__main__':
    unittest.main()
