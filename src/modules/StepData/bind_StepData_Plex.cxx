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
#include <StepData_Described.hxx>
#include <Standard_Handle.hxx>
#include <StepData_ECDescr.hxx>
#include <StepData_Simple.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_Field.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <Interface_Check.hxx>
#include <Interface_EntityIterator.hxx>
#include <StepData_Plex.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfTransient.hxx>

void bind_StepData_Plex(py::module &mod){

py::class_<StepData_Plex, opencascade::handle<StepData_Plex>, StepData_Described> cls_StepData_Plex(mod, "StepData_Plex", "A Plex (for Complex) Entity is defined as a list of Simple Members ('external mapping') The types of these members must be in alphabetic order");

// Constructors
cls_StepData_Plex.def(py::init<const opencascade::handle<StepData_ECDescr> &>(), py::arg("descr"));

// Fields

// Methods
cls_StepData_Plex.def("Add", (void (StepData_Plex::*)(const opencascade::handle<StepData_Simple> &)) &StepData_Plex::Add, "Adds a member to <me>", py::arg("member"));
cls_StepData_Plex.def("ECDescr", (opencascade::handle<StepData_ECDescr> (StepData_Plex::*)() const) &StepData_Plex::ECDescr, "Returns the Description as for a Plex");
cls_StepData_Plex.def("IsComplex", (Standard_Boolean (StepData_Plex::*)() const) &StepData_Plex::IsComplex, "Returns False");
cls_StepData_Plex.def("Matches", (Standard_Boolean (StepData_Plex::*)(const Standard_CString) const) &StepData_Plex::Matches, "Tells if a step type is matched by <me> For a Simple Entity : own type or super type For a Complex Entity : one of the members", py::arg("steptype"));
cls_StepData_Plex.def("As", (opencascade::handle<StepData_Simple> (StepData_Plex::*)(const Standard_CString) const) &StepData_Plex::As, "Returns a Simple Entity which matches with a Type in <me> : For a Simple Entity : me if it matches, else a null handle For a Complex Entity : the member which matches, else null", py::arg("steptype"));
cls_StepData_Plex.def("HasField", (Standard_Boolean (StepData_Plex::*)(const Standard_CString) const) &StepData_Plex::HasField, "Tells if a Field brings a given name", py::arg("name"));
cls_StepData_Plex.def("Field", (const StepData_Field & (StepData_Plex::*)(const Standard_CString) const) &StepData_Plex::Field, "Returns a Field from its name; read-only", py::arg("name"));
cls_StepData_Plex.def("CField", (StepData_Field & (StepData_Plex::*)(const Standard_CString)) &StepData_Plex::CField, "Returns a Field from its name; read or write", py::arg("name"));
cls_StepData_Plex.def("NbMembers", (Standard_Integer (StepData_Plex::*)() const) &StepData_Plex::NbMembers, "Returns the count of simple members");
cls_StepData_Plex.def("Member", (opencascade::handle<StepData_Simple> (StepData_Plex::*)(const Standard_Integer) const) &StepData_Plex::Member, "Returns a simple member from its rank", py::arg("num"));
cls_StepData_Plex.def("TypeList", (opencascade::handle<TColStd_HSequenceOfAsciiString> (StepData_Plex::*)() const) &StepData_Plex::TypeList, "Returns the actual list of members types");
cls_StepData_Plex.def("Check", (void (StepData_Plex::*)(opencascade::handle<Interface_Check> &) const) &StepData_Plex::Check, "Fills a Check by using its Description", py::arg("ach"));
cls_StepData_Plex.def("Shared", (void (StepData_Plex::*)(Interface_EntityIterator &) const) &StepData_Plex::Shared, "Fills an EntityIterator with entities shared by <me>", py::arg("list"));
cls_StepData_Plex.def_static("get_type_name_", (const char * (*)()) &StepData_Plex::get_type_name, "None");
cls_StepData_Plex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_Plex::get_type_descriptor, "None");
cls_StepData_Plex.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_Plex::*)() const) &StepData_Plex::DynamicType, "None");

// Enums

}