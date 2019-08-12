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
#include <BRepCheck_Result.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepCheck_Status.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepCheck_Face.hxx>
#include <Standard_Type.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>

void bind_BRepCheck_Face(py::module &mod){

py::class_<BRepCheck_Face, opencascade::handle<BRepCheck_Face>, BRepCheck_Result> cls_BRepCheck_Face(mod, "BRepCheck_Face", "None");

// Constructors
cls_BRepCheck_Face.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Fields

// Methods
cls_BRepCheck_Face.def("InContext", (void (BRepCheck_Face::*)(const TopoDS_Shape &)) &BRepCheck_Face::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Face.def("Minimum", (void (BRepCheck_Face::*)()) &BRepCheck_Face::Minimum, "None");
cls_BRepCheck_Face.def("Blind", (void (BRepCheck_Face::*)()) &BRepCheck_Face::Blind, "None");
cls_BRepCheck_Face.def("IntersectWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.IntersectWires(); });
cls_BRepCheck_Face.def("IntersectWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::IntersectWires, "None", py::arg("Update"));
cls_BRepCheck_Face.def("ClassifyWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.ClassifyWires(); });
cls_BRepCheck_Face.def("ClassifyWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::ClassifyWires, "None", py::arg("Update"));
cls_BRepCheck_Face.def("OrientationOfWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.OrientationOfWires(); });
cls_BRepCheck_Face.def("OrientationOfWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::OrientationOfWires, "None", py::arg("Update"));
cls_BRepCheck_Face.def("SetUnorientable", (void (BRepCheck_Face::*)()) &BRepCheck_Face::SetUnorientable, "None");
cls_BRepCheck_Face.def("SetStatus", (void (BRepCheck_Face::*)(const BRepCheck_Status)) &BRepCheck_Face::SetStatus, "Sets status of Face;", py::arg("theStatus"));
cls_BRepCheck_Face.def("IsUnorientable", (Standard_Boolean (BRepCheck_Face::*)() const) &BRepCheck_Face::IsUnorientable, "None");
cls_BRepCheck_Face.def("GeometricControls", (Standard_Boolean (BRepCheck_Face::*)() const) &BRepCheck_Face::GeometricControls, "None");
cls_BRepCheck_Face.def("GeometricControls", (void (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::GeometricControls, "None", py::arg("B"));
cls_BRepCheck_Face.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Face::get_type_name, "None");
cls_BRepCheck_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Face::get_type_descriptor, "None");
cls_BRepCheck_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Face::*)() const) &BRepCheck_Face::DynamicType, "None");

// Enums

}