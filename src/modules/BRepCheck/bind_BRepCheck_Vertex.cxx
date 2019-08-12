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
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepCheck_Vertex.hxx>
#include <Standard_Type.hxx>

void bind_BRepCheck_Vertex(py::module &mod){

py::class_<BRepCheck_Vertex, opencascade::handle<BRepCheck_Vertex>, BRepCheck_Result> cls_BRepCheck_Vertex(mod, "BRepCheck_Vertex", "None");

// Constructors
cls_BRepCheck_Vertex.def(py::init<const TopoDS_Vertex &>(), py::arg("V"));

// Fields

// Methods
cls_BRepCheck_Vertex.def("InContext", (void (BRepCheck_Vertex::*)(const TopoDS_Shape &)) &BRepCheck_Vertex::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Vertex.def("Minimum", (void (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Minimum, "None");
cls_BRepCheck_Vertex.def("Blind", (void (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Blind, "None");
cls_BRepCheck_Vertex.def("Tolerance", (Standard_Real (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Tolerance, "None");
cls_BRepCheck_Vertex.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Vertex::get_type_name, "None");
cls_BRepCheck_Vertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Vertex::get_type_descriptor, "None");
cls_BRepCheck_Vertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Vertex::*)() const) &BRepCheck_Vertex::DynamicType, "None");

// Enums

}