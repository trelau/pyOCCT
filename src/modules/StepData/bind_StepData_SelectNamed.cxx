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
#include <StepData_SelectMember.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_Field.hxx>
#include <Standard_Handle.hxx>
#include <StepData_SelectNamed.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>

void bind_StepData_SelectNamed(py::module &mod){

py::class_<StepData_SelectNamed, opencascade::handle<StepData_SelectNamed>, StepData_SelectMember> cls_StepData_SelectNamed(mod, "StepData_SelectNamed", "This select member can be of any kind, and be named But its takes more memory than some specialised ones This class allows one name for the instance");

// Constructors
cls_StepData_SelectNamed.def(py::init<>());

// Fields

// Methods
cls_StepData_SelectNamed.def("HasName", (Standard_Boolean (StepData_SelectNamed::*)() const) &StepData_SelectNamed::HasName, "None");
cls_StepData_SelectNamed.def("Name", (Standard_CString (StepData_SelectNamed::*)() const) &StepData_SelectNamed::Name, "None");
cls_StepData_SelectNamed.def("SetName", (Standard_Boolean (StepData_SelectNamed::*)(const Standard_CString)) &StepData_SelectNamed::SetName, "None", py::arg("name"));
cls_StepData_SelectNamed.def("Field", (const StepData_Field & (StepData_SelectNamed::*)() const) &StepData_SelectNamed::Field, "None");
cls_StepData_SelectNamed.def("CField", (StepData_Field & (StepData_SelectNamed::*)()) &StepData_SelectNamed::CField, "None");
cls_StepData_SelectNamed.def("Kind", (Standard_Integer (StepData_SelectNamed::*)() const) &StepData_SelectNamed::Kind, "None");
cls_StepData_SelectNamed.def("SetKind", (void (StepData_SelectNamed::*)(const Standard_Integer)) &StepData_SelectNamed::SetKind, "None", py::arg("kind"));
cls_StepData_SelectNamed.def("Int", (Standard_Integer (StepData_SelectNamed::*)() const) &StepData_SelectNamed::Int, "This internal method gives access to a value implemented by an Integer (to read it)");
cls_StepData_SelectNamed.def("SetInt", (void (StepData_SelectNamed::*)(const Standard_Integer)) &StepData_SelectNamed::SetInt, "This internal method gives access to a value implemented by an Integer (to set it)", py::arg("val"));
cls_StepData_SelectNamed.def("Real", (Standard_Real (StepData_SelectNamed::*)() const) &StepData_SelectNamed::Real, "None");
cls_StepData_SelectNamed.def("SetReal", (void (StepData_SelectNamed::*)(const Standard_Real)) &StepData_SelectNamed::SetReal, "None", py::arg("val"));
cls_StepData_SelectNamed.def("String", (Standard_CString (StepData_SelectNamed::*)() const) &StepData_SelectNamed::String, "None");
cls_StepData_SelectNamed.def("SetString", (void (StepData_SelectNamed::*)(const Standard_CString)) &StepData_SelectNamed::SetString, "None", py::arg("val"));
cls_StepData_SelectNamed.def_static("get_type_name_", (const char * (*)()) &StepData_SelectNamed::get_type_name, "None");
cls_StepData_SelectNamed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_SelectNamed::get_type_descriptor, "None");
cls_StepData_SelectNamed.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_SelectNamed::*)() const) &StepData_SelectNamed::DynamicType, "None");

// Enums

}