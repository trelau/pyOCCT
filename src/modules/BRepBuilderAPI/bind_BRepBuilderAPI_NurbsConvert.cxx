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
#include <BRepBuilderAPI_ModifyShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepTools_ReShape.hxx>
#include <BRepBuilderAPI_NurbsConvert.hxx>

void bind_BRepBuilderAPI_NurbsConvert(py::module &mod){

py::class_<BRepBuilderAPI_NurbsConvert, BRepBuilderAPI_ModifyShape> cls_BRepBuilderAPI_NurbsConvert(mod, "BRepBuilderAPI_NurbsConvert", "Conversion of the complete geometry of a shape (all 3D analytical representation of surfaces and curves) into NURBS geometry (execpt for Planes). For example, all curves supporting edges of the basis shape are converted into BSpline curves, and all surfaces supporting its faces are converted into BSpline surfaces.");

// Constructors
cls_BRepBuilderAPI_NurbsConvert.def(py::init<>());
cls_BRepBuilderAPI_NurbsConvert.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepBuilderAPI_NurbsConvert.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("Copy"));

// Fields

// Methods
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_NurbsConvert::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_NurbsConvert::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_NurbsConvert::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_NurbsConvert::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_NurbsConvert::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_NurbsConvert::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_NurbsConvert.def("Perform", [](BRepBuilderAPI_NurbsConvert &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepBuilderAPI_NurbsConvert.def("Perform", (void (BRepBuilderAPI_NurbsConvert::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepBuilderAPI_NurbsConvert::Perform, "Builds a new shape by converting the geometry of the shape S into NURBS geometry. Specifically, all curves supporting edges of S are converted into BSpline curves, and all surfaces supporting its faces are converted into BSpline surfaces. Use the function Shape to access the new shape. Note: this framework can be reused to convert other shapes: you specify them by calling the function Perform again.", py::arg("S"), py::arg("Copy"));
cls_BRepBuilderAPI_NurbsConvert.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_NurbsConvert::*)(const TopoDS_Shape &)) &BRepBuilderAPI_NurbsConvert::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_NurbsConvert.def("ModifiedShape", (TopoDS_Shape (BRepBuilderAPI_NurbsConvert::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_NurbsConvert::ModifiedShape, "Returns the modified shape corresponding to <S>. S can correspond to the entire initial shape or to its subshape. Exceptions Standard_NoSuchObject if S is not the initial shape or a subshape of the initial shape to which the transformation has been applied.", py::arg("S"));

// Enums

}