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
#include <StepData_SelectNamed.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepFEA_DegreeOfFreedomMember.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_DegreeOfFreedomMember(py::module &mod){

py::class_<StepFEA_DegreeOfFreedomMember, opencascade::handle<StepFEA_DegreeOfFreedomMember>, StepData_SelectNamed> cls_StepFEA_DegreeOfFreedomMember(mod, "StepFEA_DegreeOfFreedomMember", "Representation of member for STEP SELECT type CurveElementFreedom");

// Constructors
cls_StepFEA_DegreeOfFreedomMember.def(py::init<>());

// Fields

// Methods
cls_StepFEA_DegreeOfFreedomMember.def("HasName", (Standard_Boolean (StepFEA_DegreeOfFreedomMember::*)() const) &StepFEA_DegreeOfFreedomMember::HasName, "Returns True if has name");
cls_StepFEA_DegreeOfFreedomMember.def("Name", (Standard_CString (StepFEA_DegreeOfFreedomMember::*)() const) &StepFEA_DegreeOfFreedomMember::Name, "Returns set name");
cls_StepFEA_DegreeOfFreedomMember.def("SetName", (Standard_Boolean (StepFEA_DegreeOfFreedomMember::*)(const Standard_CString)) &StepFEA_DegreeOfFreedomMember::SetName, "Set name", py::arg("name"));
cls_StepFEA_DegreeOfFreedomMember.def("Matches", (Standard_Boolean (StepFEA_DegreeOfFreedomMember::*)(const Standard_CString) const) &StepFEA_DegreeOfFreedomMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepFEA_DegreeOfFreedomMember.def_static("get_type_name_", (const char * (*)()) &StepFEA_DegreeOfFreedomMember::get_type_name, "None");
cls_StepFEA_DegreeOfFreedomMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_DegreeOfFreedomMember::get_type_descriptor, "None");
cls_StepFEA_DegreeOfFreedomMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_DegreeOfFreedomMember::*)() const) &StepFEA_DegreeOfFreedomMember::DynamicType, "None");

// Enums

}