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

from OCCT.TCollection import TCollection_ExtendedString
from OCCT.TDF import TDF_LabelSequence
from OCCT.TDataStd import TDataStd_Name
from OCCT.TDocStd import TDocStd_Document
from OCCT.TNaming import TNaming_NamedShape
from OCCT.TopAbs import TopAbs_ShapeEnum
from OCCT.TopExp import TopExp
from OCCT.TopTools import TopTools_IndexedMapOfShape
from OCCT.XCAFApp import XCAFApp_Application
from OCCT.XCAFDoc import XCAFDoc_DocumentTool
from OCCT.XmlXCAFDrivers import XmlXCAFDrivers


class Test_XCAFDoc_ShapeTool(unittest.TestCase):
    """
    Test for XCAFDoc_ShapeTool class.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up for XCAFDoc_ShapeTool class.
        """
        cls._app = XCAFApp_Application.GetApplication_()
        XmlXCAFDrivers.DefineFormat_(cls._app)

        fmt = TCollection_ExtendedString('XmlXCAF')
        doc = TDocStd_Document(fmt)

        cls._app.InitDocument(doc)

        filename = join(dirname(__file__), 'test_io', 'named_box.xml')
        fn = TCollection_ExtendedString(filename)
        status, cls._doc = cls._app.Open(fn, doc)

        cls._tool = XCAFDoc_DocumentTool.ShapeTool_(cls._doc.Main())

    @classmethod
    def tearDownClass(cls):
        """
        Close down the application and document.
        """
        cls._app.Close(cls._doc)

    def test_FindSubShape(self):
        """
        Test XCAFDoc_ShapeTool:FindSubShape.
        """
        names = ['back face',
                 'front face',
                 'left face',
                 'right face',
                 'bottom face',
                 'top face']

        labels = TDF_LabelSequence()
        self._tool.GetShapes(labels)
        self.assertFalse(labels.IsEmpty())
        self.assertEqual(labels.Length(), 1)

        label = labels.Value(1)
        named_shape = TNaming_NamedShape()
        status, named_shape = label.FindAttribute(TNaming_NamedShape.GetID_(),
                                                  named_shape)
        self.assertTrue(status)

        shape = named_shape.Get()
        self.assertEqual(shape.ShapeType(), TopAbs_ShapeEnum.TopAbs_SOLID)

        map_ = TopTools_IndexedMapOfShape()
        TopExp.MapShapes_(shape, TopAbs_ShapeEnum.TopAbs_FACE, map_)
        for i in range(1, map_.Size() + 1):
            face = map_.FindKey(i)
            status, sub_label = self._tool.FindSubShape(label, face)
            self.assertTrue(status)

            name = TDataStd_Name()
            status, name = sub_label.FindAttribute(TDataStd_Name.GetID_(),
                                                   name)
            self.assertTrue(status)

            name = name.Get().ToExtString()
            self.assertEqual(name, names[i - 1])


if __name__ == '__main__':
    unittest.main()
