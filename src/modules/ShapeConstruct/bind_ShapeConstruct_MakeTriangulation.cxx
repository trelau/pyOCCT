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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <ShapeConstruct_MakeTriangulation.hxx>

void bind_ShapeConstruct_MakeTriangulation(py::module &mod){

py::class_<ShapeConstruct_MakeTriangulation, BRepBuilderAPI_MakeShape> cls_ShapeConstruct_MakeTriangulation(mod, "ShapeConstruct_MakeTriangulation", "None");

// Constructors
cls_ShapeConstruct_MakeTriangulation.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("pnts"));
cls_ShapeConstruct_MakeTriangulation.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real>(), py::arg("pnts"), py::arg("prec"));
cls_ShapeConstruct_MakeTriangulation.def(py::init<const TopoDS_Wire &>(), py::arg("wire"));
cls_ShapeConstruct_MakeTriangulation.def(py::init<const TopoDS_Wire &, const Standard_Real>(), py::arg("wire"), py::arg("prec"));

// Fields

// Methods
// cls_ShapeConstruct_MakeTriangulation.def_static("operator new_", (void * (*)(size_t)) &ShapeConstruct_MakeTriangulation::operator new, "None", py::arg("theSize"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator delete_", (void (*)(void *)) &ShapeConstruct_MakeTriangulation::operator delete, "None", py::arg("theAddress"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator new[]_", (void * (*)(size_t)) &ShapeConstruct_MakeTriangulation::operator new[], "None", py::arg("theSize"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator delete[]_", (void (*)(void *)) &ShapeConstruct_MakeTriangulation::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeConstruct_MakeTriangulation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator delete_", (void (*)(void *, void *)) &ShapeConstruct_MakeTriangulation::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeConstruct_MakeTriangulation.def("Build", (void (ShapeConstruct_MakeTriangulation::*)()) &ShapeConstruct_MakeTriangulation::Build, "None");
cls_ShapeConstruct_MakeTriangulation.def("IsDone", (Standard_Boolean (ShapeConstruct_MakeTriangulation::*)() const) &ShapeConstruct_MakeTriangulation::IsDone, "None");

// Enums

}