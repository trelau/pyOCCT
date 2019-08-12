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
#include <TopoDS_Solid.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <BRepCheck_Solid.hxx>
#include <Standard_Type.hxx>

void bind_BRepCheck_Solid(py::module &mod){

py::class_<BRepCheck_Solid, opencascade::handle<BRepCheck_Solid>, BRepCheck_Result> cls_BRepCheck_Solid(mod, "BRepCheck_Solid", "The class is to check a solid.");

// Constructors
cls_BRepCheck_Solid.def(py::init<const TopoDS_Solid &>(), py::arg("theS"));

// Fields

// Methods
cls_BRepCheck_Solid.def("InContext", (void (BRepCheck_Solid::*)(const TopoDS_Shape &)) &BRepCheck_Solid::InContext, "Checks the solid in context of the shape <theContextShape>", py::arg("theContextShape"));
cls_BRepCheck_Solid.def("Minimum", (void (BRepCheck_Solid::*)()) &BRepCheck_Solid::Minimum, "Checks the solid per se.");
cls_BRepCheck_Solid.def("Blind", (void (BRepCheck_Solid::*)()) &BRepCheck_Solid::Blind, "see the parent class for more details");
cls_BRepCheck_Solid.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Solid::get_type_name, "None");
cls_BRepCheck_Solid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Solid::get_type_descriptor, "None");
cls_BRepCheck_Solid.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Solid::*)() const) &BRepCheck_Solid::DynamicType, "None");

// Enums

}