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
#include <ShapeUpgrade_EdgeDivide.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_ClosedEdgeDivide.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_ClosedEdgeDivide(py::module &mod){

py::class_<ShapeUpgrade_ClosedEdgeDivide, opencascade::handle<ShapeUpgrade_ClosedEdgeDivide>, ShapeUpgrade_EdgeDivide> cls_ShapeUpgrade_ClosedEdgeDivide(mod, "ShapeUpgrade_ClosedEdgeDivide", "None");

// Constructors
cls_ShapeUpgrade_ClosedEdgeDivide.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_ClosedEdgeDivide.def("Compute", (Standard_Boolean (ShapeUpgrade_ClosedEdgeDivide::*)(const TopoDS_Edge &)) &ShapeUpgrade_ClosedEdgeDivide::Compute, "None", py::arg("anEdge"));
cls_ShapeUpgrade_ClosedEdgeDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ClosedEdgeDivide::get_type_name, "None");
cls_ShapeUpgrade_ClosedEdgeDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ClosedEdgeDivide::get_type_descriptor, "None");
cls_ShapeUpgrade_ClosedEdgeDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ClosedEdgeDivide::*)() const) &ShapeUpgrade_ClosedEdgeDivide::DynamicType, "None");

// Enums

}