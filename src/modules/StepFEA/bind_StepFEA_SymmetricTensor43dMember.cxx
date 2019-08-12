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
#include <StepData_SelectArrReal.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepFEA_SymmetricTensor43dMember.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_SymmetricTensor43dMember(py::module &mod){

py::class_<StepFEA_SymmetricTensor43dMember, opencascade::handle<StepFEA_SymmetricTensor43dMember>, StepData_SelectArrReal> cls_StepFEA_SymmetricTensor43dMember(mod, "StepFEA_SymmetricTensor43dMember", "Representation of member for STEP SELECT type SymmetricTensor43d");

// Constructors
cls_StepFEA_SymmetricTensor43dMember.def(py::init<>());

// Fields

// Methods
cls_StepFEA_SymmetricTensor43dMember.def("HasName", (Standard_Boolean (StepFEA_SymmetricTensor43dMember::*)() const) &StepFEA_SymmetricTensor43dMember::HasName, "Returns True if has name");
cls_StepFEA_SymmetricTensor43dMember.def("Name", (Standard_CString (StepFEA_SymmetricTensor43dMember::*)() const) &StepFEA_SymmetricTensor43dMember::Name, "Returns set name");
cls_StepFEA_SymmetricTensor43dMember.def("SetName", (Standard_Boolean (StepFEA_SymmetricTensor43dMember::*)(const Standard_CString)) &StepFEA_SymmetricTensor43dMember::SetName, "Set name", py::arg("name"));
cls_StepFEA_SymmetricTensor43dMember.def("Matches", (Standard_Boolean (StepFEA_SymmetricTensor43dMember::*)(const Standard_CString) const) &StepFEA_SymmetricTensor43dMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepFEA_SymmetricTensor43dMember.def_static("get_type_name_", (const char * (*)()) &StepFEA_SymmetricTensor43dMember::get_type_name, "None");
cls_StepFEA_SymmetricTensor43dMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_SymmetricTensor43dMember::get_type_descriptor, "None");
cls_StepFEA_SymmetricTensor43dMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_SymmetricTensor43dMember::*)() const) &StepFEA_SymmetricTensor43dMember::DynamicType, "None");

// Enums

}