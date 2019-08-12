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
#include <TopoDS_Shell.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepCheck_Status.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <BRepCheck_Shell.hxx>
#include <Standard_Type.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>

void bind_BRepCheck_Shell(py::module &mod){

py::class_<BRepCheck_Shell, opencascade::handle<BRepCheck_Shell>, BRepCheck_Result> cls_BRepCheck_Shell(mod, "BRepCheck_Shell", "None");

// Constructors
cls_BRepCheck_Shell.def(py::init<const TopoDS_Shell &>(), py::arg("S"));

// Fields

// Methods
cls_BRepCheck_Shell.def("InContext", (void (BRepCheck_Shell::*)(const TopoDS_Shape &)) &BRepCheck_Shell::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Shell.def("Minimum", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::Minimum, "None");
cls_BRepCheck_Shell.def("Blind", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::Blind, "None");
cls_BRepCheck_Shell.def("Closed", [](BRepCheck_Shell &self) -> BRepCheck_Status { return self.Closed(); });
cls_BRepCheck_Shell.def("Closed", (BRepCheck_Status (BRepCheck_Shell::*)(const Standard_Boolean)) &BRepCheck_Shell::Closed, "Checks if the oriented faces of the shell give a closed shell. If the wire is closed, returns BRepCheck_NoError.If <Update> is set to Standard_True, registers the status in the list.", py::arg("Update"));
cls_BRepCheck_Shell.def("Orientation", [](BRepCheck_Shell &self) -> BRepCheck_Status { return self.Orientation(); });
cls_BRepCheck_Shell.def("Orientation", (BRepCheck_Status (BRepCheck_Shell::*)(const Standard_Boolean)) &BRepCheck_Shell::Orientation, "Checks if the oriented faces of the shell are correctly oriented. An internal call is made to the method Closed. If <Update> is set to Standard_True, registers the status in the list.", py::arg("Update"));
cls_BRepCheck_Shell.def("SetUnorientable", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::SetUnorientable, "None");
cls_BRepCheck_Shell.def("IsUnorientable", (Standard_Boolean (BRepCheck_Shell::*)() const) &BRepCheck_Shell::IsUnorientable, "None");
cls_BRepCheck_Shell.def("NbConnectedSet", (Standard_Integer (BRepCheck_Shell::*)(TopTools_ListOfShape &)) &BRepCheck_Shell::NbConnectedSet, "None", py::arg("theSets"));
cls_BRepCheck_Shell.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Shell::get_type_name, "None");
cls_BRepCheck_Shell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Shell::get_type_descriptor, "None");
cls_BRepCheck_Shell.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Shell::*)() const) &BRepCheck_Shell::DynamicType, "None");

// Enums

}