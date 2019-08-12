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
#include <StepVisual_NullStyle.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_NullStyleMember.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_NullStyleMember(py::module &mod){

py::class_<StepVisual_NullStyleMember, opencascade::handle<StepVisual_NullStyleMember>, StepData_SelectInt> cls_StepVisual_NullStyleMember(mod, "StepVisual_NullStyleMember", "Defines NullStyle as unique member of PresentationStyleSelect Works with an EnumTool");

// Constructors
cls_StepVisual_NullStyleMember.def(py::init<>());

// Fields

// Methods
cls_StepVisual_NullStyleMember.def("HasName", (Standard_Boolean (StepVisual_NullStyleMember::*)() const) &StepVisual_NullStyleMember::HasName, "None");
cls_StepVisual_NullStyleMember.def("Name", (Standard_CString (StepVisual_NullStyleMember::*)() const) &StepVisual_NullStyleMember::Name, "None");
cls_StepVisual_NullStyleMember.def("SetName", (Standard_Boolean (StepVisual_NullStyleMember::*)(const Standard_CString)) &StepVisual_NullStyleMember::SetName, "None", py::arg(""));
cls_StepVisual_NullStyleMember.def("Kind", (Standard_Integer (StepVisual_NullStyleMember::*)() const) &StepVisual_NullStyleMember::Kind, "None");
cls_StepVisual_NullStyleMember.def("EnumText", (Standard_CString (StepVisual_NullStyleMember::*)() const) &StepVisual_NullStyleMember::EnumText, "None");
cls_StepVisual_NullStyleMember.def("SetEnumText", (void (StepVisual_NullStyleMember::*)(const Standard_Integer, const Standard_CString)) &StepVisual_NullStyleMember::SetEnumText, "None", py::arg("theValue"), py::arg("theText"));
cls_StepVisual_NullStyleMember.def("SetValue", (void (StepVisual_NullStyleMember::*)(const StepVisual_NullStyle)) &StepVisual_NullStyleMember::SetValue, "None", py::arg("theValue"));
cls_StepVisual_NullStyleMember.def("Value", (StepVisual_NullStyle (StepVisual_NullStyleMember::*)() const) &StepVisual_NullStyleMember::Value, "None");
cls_StepVisual_NullStyleMember.def_static("get_type_name_", (const char * (*)()) &StepVisual_NullStyleMember::get_type_name, "None");
cls_StepVisual_NullStyleMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_NullStyleMember::get_type_descriptor, "None");
cls_StepVisual_NullStyleMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_NullStyleMember::*)() const) &StepVisual_NullStyleMember::DynamicType, "None");

// Enums

}