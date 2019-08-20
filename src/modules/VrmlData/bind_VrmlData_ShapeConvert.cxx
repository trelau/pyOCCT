/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Node.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_Geometry.hxx>
#include <Poly_Triangulation.hxx>
#include <TopoDS_Face.hxx>
#include <VrmlData_Coordinate.hxx>
#include <Poly_Polygon3D.hxx>
#include <VrmlData_Appearance.hxx>
#include <NCollection_List.hxx>
#include <VrmlData_ShapeConvert.hxx>

void bind_VrmlData_ShapeConvert(py::module &mod){

py::class_<VrmlData_ShapeConvert, std::unique_ptr<VrmlData_ShapeConvert>> cls_VrmlData_ShapeConvert(mod, "VrmlData_ShapeConvert", "Algorithm converting one shape or a set of shapes to VrmlData_Scene.");

// Constructors
cls_VrmlData_ShapeConvert.def(py::init<VrmlData_Scene &>(), py::arg("theScene"));
cls_VrmlData_ShapeConvert.def(py::init<VrmlData_Scene &, const Standard_Real>(), py::arg("theScene"), py::arg("theScale"));

// Fields

// Methods
cls_VrmlData_ShapeConvert.def("AddShape", [](VrmlData_ShapeConvert &self, const TopoDS_Shape & a0) -> void { return self.AddShape(a0); });
cls_VrmlData_ShapeConvert.def("AddShape", (void (VrmlData_ShapeConvert::*)(const TopoDS_Shape &, const char *)) &VrmlData_ShapeConvert::AddShape, "Add one shape to the internal list, may be called several times with different shapes.", py::arg("theShape"), py::arg("theName"));
cls_VrmlData_ShapeConvert.def("Convert", [](VrmlData_ShapeConvert &self, const Standard_Boolean a0, const Standard_Boolean a1) -> void { return self.Convert(a0, a1); });
cls_VrmlData_ShapeConvert.def("Convert", [](VrmlData_ShapeConvert &self, const Standard_Boolean a0, const Standard_Boolean a1, const Standard_Real a2) -> void { return self.Convert(a0, a1, a2); });
cls_VrmlData_ShapeConvert.def("Convert", (void (VrmlData_ShapeConvert::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real)) &VrmlData_ShapeConvert::Convert, "Convert all accumulated shapes and store them in myScene. The internal data structures are cleared in the end of convertion.", py::arg("theExtractFaces"), py::arg("theExtractEdges"), py::arg("theDeflection"), py::arg("theDeflAngle"));

// Enums

}