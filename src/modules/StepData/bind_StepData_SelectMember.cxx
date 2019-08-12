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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_ParamType.hxx>
#include <StepData_Logical.hxx>
#include <Standard_Handle.hxx>
#include <StepData_SelectMember.hxx>
#include <Standard_Type.hxx>

void bind_StepData_SelectMember(py::module &mod){

py::class_<StepData_SelectMember, opencascade::handle<StepData_SelectMember>, Standard_Transient> cls_StepData_SelectMember(mod, "StepData_SelectMember", "The general form for a Select Member. A Select Member can, either define a value of a basic type (such as an integer) with an additional information : a name or list of names which precise the meaning of this value or be an alternate value in a select, which also accepts an entity (in this case, the name is not mandatory)");

// Constructors
cls_StepData_SelectMember.def(py::init<>());

// Fields

// Methods
cls_StepData_SelectMember.def("HasName", (Standard_Boolean (StepData_SelectMember::*)() const) &StepData_SelectMember::HasName, "Tells if a SelectMember has a name. Default is False");
cls_StepData_SelectMember.def("Name", (Standard_CString (StepData_SelectMember::*)() const) &StepData_SelectMember::Name, "Returns the name of a SelectMember. Default is empty");
cls_StepData_SelectMember.def("SetName", (Standard_Boolean (StepData_SelectMember::*)(const Standard_CString)) &StepData_SelectMember::SetName, "Sets the name of a SelectMember, returns True if done, False if no name is allowed Default does nothing and returns False", py::arg("name"));
cls_StepData_SelectMember.def("Matches", (Standard_Boolean (StepData_SelectMember::*)(const Standard_CString) const) &StepData_SelectMember::Matches, "Tells if the name of a SelectMember matches a given one By default, compares the strings, can be redefined (optimised)", py::arg("name"));
cls_StepData_SelectMember.def("Kind", (Standard_Integer (StepData_SelectMember::*)() const) &StepData_SelectMember::Kind, "None");
cls_StepData_SelectMember.def("SetKind", (void (StepData_SelectMember::*)(const Standard_Integer)) &StepData_SelectMember::SetKind, "None", py::arg("kind"));
cls_StepData_SelectMember.def("ParamType", (Interface_ParamType (StepData_SelectMember::*)() const) &StepData_SelectMember::ParamType, "Returns the Kind of the SelectMember, under the form of an enum ParamType");
cls_StepData_SelectMember.def("Int", (Standard_Integer (StepData_SelectMember::*)() const) &StepData_SelectMember::Int, "This internal method gives access to a value implemented by an Integer (to read it)");
cls_StepData_SelectMember.def("SetInt", (void (StepData_SelectMember::*)(const Standard_Integer)) &StepData_SelectMember::SetInt, "This internal method gives access to a value implemented by an Integer (to set it)", py::arg("val"));
cls_StepData_SelectMember.def("Integer", (Standard_Integer (StepData_SelectMember::*)() const) &StepData_SelectMember::Integer, "Gets the value as an Integer");
cls_StepData_SelectMember.def("SetInteger", (void (StepData_SelectMember::*)(const Standard_Integer)) &StepData_SelectMember::SetInteger, "None", py::arg("val"));
cls_StepData_SelectMember.def("Boolean", (Standard_Boolean (StepData_SelectMember::*)() const) &StepData_SelectMember::Boolean, "None");
cls_StepData_SelectMember.def("SetBoolean", (void (StepData_SelectMember::*)(const Standard_Boolean)) &StepData_SelectMember::SetBoolean, "None", py::arg("val"));
cls_StepData_SelectMember.def("Logical", (StepData_Logical (StepData_SelectMember::*)() const) &StepData_SelectMember::Logical, "None");
cls_StepData_SelectMember.def("SetLogical", (void (StepData_SelectMember::*)(const StepData_Logical)) &StepData_SelectMember::SetLogical, "None", py::arg("val"));
cls_StepData_SelectMember.def("Real", (Standard_Real (StepData_SelectMember::*)() const) &StepData_SelectMember::Real, "None");
cls_StepData_SelectMember.def("SetReal", (void (StepData_SelectMember::*)(const Standard_Real)) &StepData_SelectMember::SetReal, "None", py::arg("val"));
cls_StepData_SelectMember.def("String", (Standard_CString (StepData_SelectMember::*)() const) &StepData_SelectMember::String, "None");
cls_StepData_SelectMember.def("SetString", (void (StepData_SelectMember::*)(const Standard_CString)) &StepData_SelectMember::SetString, "None", py::arg("val"));
cls_StepData_SelectMember.def("Enum", (Standard_Integer (StepData_SelectMember::*)() const) &StepData_SelectMember::Enum, "None");
cls_StepData_SelectMember.def("EnumText", (Standard_CString (StepData_SelectMember::*)() const) &StepData_SelectMember::EnumText, "None");
cls_StepData_SelectMember.def("SetEnum", [](StepData_SelectMember &self, const Standard_Integer a0) -> void { return self.SetEnum(a0); });
cls_StepData_SelectMember.def("SetEnum", (void (StepData_SelectMember::*)(const Standard_Integer, const Standard_CString)) &StepData_SelectMember::SetEnum, "None", py::arg("val"), py::arg("text"));
cls_StepData_SelectMember.def("SetEnumText", (void (StepData_SelectMember::*)(const Standard_Integer, const Standard_CString)) &StepData_SelectMember::SetEnumText, "None", py::arg("val"), py::arg("text"));
cls_StepData_SelectMember.def_static("get_type_name_", (const char * (*)()) &StepData_SelectMember::get_type_name, "None");
cls_StepData_SelectMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_SelectMember::get_type_descriptor, "None");
cls_StepData_SelectMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_SelectMember::*)() const) &StepData_SelectMember::DynamicType, "None");

// Enums

}