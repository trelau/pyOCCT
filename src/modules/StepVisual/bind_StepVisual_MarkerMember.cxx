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
#include <StepData_SelectInt.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_MarkerType.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_MarkerMember.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_MarkerMember(py::module &mod){

py::class_<StepVisual_MarkerMember, opencascade::handle<StepVisual_MarkerMember>, StepData_SelectInt> cls_StepVisual_MarkerMember(mod, "StepVisual_MarkerMember", "Defines MarkerType as unique member of MarkerSelect Works with an EnumTool");

// Constructors
cls_StepVisual_MarkerMember.def(py::init<>());

// Fields

// Methods
cls_StepVisual_MarkerMember.def("HasName", (Standard_Boolean (StepVisual_MarkerMember::*)() const) &StepVisual_MarkerMember::HasName, "None");
cls_StepVisual_MarkerMember.def("Name", (Standard_CString (StepVisual_MarkerMember::*)() const) &StepVisual_MarkerMember::Name, "None");
cls_StepVisual_MarkerMember.def("SetName", (Standard_Boolean (StepVisual_MarkerMember::*)(const Standard_CString)) &StepVisual_MarkerMember::SetName, "None", py::arg("name"));
cls_StepVisual_MarkerMember.def("EnumText", (Standard_CString (StepVisual_MarkerMember::*)() const) &StepVisual_MarkerMember::EnumText, "None");
cls_StepVisual_MarkerMember.def("SetEnumText", (void (StepVisual_MarkerMember::*)(const Standard_Integer, const Standard_CString)) &StepVisual_MarkerMember::SetEnumText, "None", py::arg("val"), py::arg("text"));
cls_StepVisual_MarkerMember.def("SetValue", (void (StepVisual_MarkerMember::*)(const StepVisual_MarkerType)) &StepVisual_MarkerMember::SetValue, "None", py::arg("val"));
cls_StepVisual_MarkerMember.def("Value", (StepVisual_MarkerType (StepVisual_MarkerMember::*)() const) &StepVisual_MarkerMember::Value, "None");
cls_StepVisual_MarkerMember.def_static("get_type_name_", (const char * (*)()) &StepVisual_MarkerMember::get_type_name, "None");
cls_StepVisual_MarkerMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_MarkerMember::get_type_descriptor, "None");
cls_StepVisual_MarkerMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_MarkerMember::*)() const) &StepVisual_MarkerMember::DynamicType, "None");

// Enums

}