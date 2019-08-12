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
#include <StepDimTol_SimpleDatumReferenceModifier.hxx>
#include <Standard_Handle.hxx>
#include <StepDimTol_SimpleDatumReferenceModifierMember.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_SimpleDatumReferenceModifierMember(py::module &mod){

py::class_<StepDimTol_SimpleDatumReferenceModifierMember, opencascade::handle<StepDimTol_SimpleDatumReferenceModifierMember>, StepData_SelectInt> cls_StepDimTol_SimpleDatumReferenceModifierMember(mod, "StepDimTol_SimpleDatumReferenceModifierMember", "Defines SimpleDatumReferenceModifier as unique member of DatumReferenceModifier Works with an EnumTool");

// Constructors
cls_StepDimTol_SimpleDatumReferenceModifierMember.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("HasName", (Standard_Boolean (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::HasName, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Name", (Standard_CString (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::Name, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetName", (Standard_Boolean (StepDimTol_SimpleDatumReferenceModifierMember::*)(const Standard_CString)) &StepDimTol_SimpleDatumReferenceModifierMember::SetName, "None", py::arg(""));
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Kind", (Standard_Integer (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::Kind, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("EnumText", (Standard_CString (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::EnumText, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetEnumText", (void (StepDimTol_SimpleDatumReferenceModifierMember::*)(const Standard_Integer, const Standard_CString)) &StepDimTol_SimpleDatumReferenceModifierMember::SetEnumText, "None", py::arg("theValue"), py::arg("theText"));
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetValue", (void (StepDimTol_SimpleDatumReferenceModifierMember::*)(const StepDimTol_SimpleDatumReferenceModifier)) &StepDimTol_SimpleDatumReferenceModifierMember::SetValue, "None", py::arg("theValue"));
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Value", (StepDimTol_SimpleDatumReferenceModifier (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::Value, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def_static("get_type_name_", (const char * (*)()) &StepDimTol_SimpleDatumReferenceModifierMember::get_type_name, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_SimpleDatumReferenceModifierMember::get_type_descriptor, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::DynamicType, "None");

// Enums

}