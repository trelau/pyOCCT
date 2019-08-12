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
#include <StepData_EDescr.hxx>
#include <Standard_Handle.hxx>
#include <StepData_ESDescr.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <StepData_Described.hxx>
#include <StepData_ECDescr.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfTransient.hxx>

void bind_StepData_ECDescr(py::module &mod){

py::class_<StepData_ECDescr, opencascade::handle<StepData_ECDescr>, StepData_EDescr> cls_StepData_ECDescr(mod, "StepData_ECDescr", "Describes a Complex Entity (Plex) as a list of Simple ones");

// Constructors
cls_StepData_ECDescr.def(py::init<>());

// Fields

// Methods
cls_StepData_ECDescr.def("Add", (void (StepData_ECDescr::*)(const opencascade::handle<StepData_ESDescr> &)) &StepData_ECDescr::Add, "Adds a member Warning : members are added in alphabetic order", py::arg("member"));
cls_StepData_ECDescr.def("NbMembers", (Standard_Integer (StepData_ECDescr::*)() const) &StepData_ECDescr::NbMembers, "Returns the count of members");
cls_StepData_ECDescr.def("Member", (opencascade::handle<StepData_ESDescr> (StepData_ECDescr::*)(const Standard_Integer) const) &StepData_ECDescr::Member, "Returns a Member from its rank", py::arg("num"));
cls_StepData_ECDescr.def("TypeList", (opencascade::handle<TColStd_HSequenceOfAsciiString> (StepData_ECDescr::*)() const) &StepData_ECDescr::TypeList, "Returns the ordered list of types");
cls_StepData_ECDescr.def("Matches", (Standard_Boolean (StepData_ECDescr::*)(const Standard_CString) const) &StepData_ECDescr::Matches, "Tells if a ESDescr matches a step type : exact or super type", py::arg("steptype"));
cls_StepData_ECDescr.def("IsComplex", (Standard_Boolean (StepData_ECDescr::*)() const) &StepData_ECDescr::IsComplex, "Returns True");
cls_StepData_ECDescr.def("NewEntity", (opencascade::handle<StepData_Described> (StepData_ECDescr::*)() const) &StepData_ECDescr::NewEntity, "Creates a described entity (i.e. a complex one, made of one simple entity per member)");
cls_StepData_ECDescr.def_static("get_type_name_", (const char * (*)()) &StepData_ECDescr::get_type_name, "None");
cls_StepData_ECDescr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_ECDescr::get_type_descriptor, "None");
cls_StepData_ECDescr.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_ECDescr::*)() const) &StepData_ECDescr::DynamicType, "None");

// Enums

}