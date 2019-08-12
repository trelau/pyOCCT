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
#include <Standard_Handle.hxx>
#include <StepData_EDescr.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_Simple.hxx>
#include <StepData_Field.hxx>
#include <Interface_Check.hxx>
#include <Interface_EntityIterator.hxx>
#include <StepData_Described.hxx>
#include <Standard_Type.hxx>

void bind_StepData_Described(py::module &mod){

py::class_<StepData_Described, opencascade::handle<StepData_Described>, Standard_Transient> cls_StepData_Described(mod, "StepData_Described", "General frame to describe entities with Description (Simple or Complex)");

// Fields

// Methods
cls_StepData_Described.def("Description", (opencascade::handle<StepData_EDescr> (StepData_Described::*)() const) &StepData_Described::Description, "Returns the Description used to define this entity");
cls_StepData_Described.def("IsComplex", (Standard_Boolean (StepData_Described::*)() const) &StepData_Described::IsComplex, "Tells if a described entity is complex");
cls_StepData_Described.def("Matches", (Standard_Boolean (StepData_Described::*)(const Standard_CString) const) &StepData_Described::Matches, "Tells if a step type is matched by <me> For a Simple Entity : own type or super type For a Complex Entity : one of the members", py::arg("steptype"));
cls_StepData_Described.def("As", (opencascade::handle<StepData_Simple> (StepData_Described::*)(const Standard_CString) const) &StepData_Described::As, "Returns a Simple Entity which matches with a Type in <me> : For a Simple Entity : me if it matches, else a null handle For a Complex Entity : the member which matches, else null", py::arg("steptype"));
cls_StepData_Described.def("HasField", (Standard_Boolean (StepData_Described::*)(const Standard_CString) const) &StepData_Described::HasField, "Tells if a Field brings a given name", py::arg("name"));
cls_StepData_Described.def("Field", (const StepData_Field & (StepData_Described::*)(const Standard_CString) const) &StepData_Described::Field, "Returns a Field from its name; read-only", py::arg("name"));
cls_StepData_Described.def("CField", (StepData_Field & (StepData_Described::*)(const Standard_CString)) &StepData_Described::CField, "Returns a Field from its name; read or write", py::arg("name"));
cls_StepData_Described.def("Check", (void (StepData_Described::*)(opencascade::handle<Interface_Check> &) const) &StepData_Described::Check, "Fills a Check by using its Description", py::arg("ach"));
cls_StepData_Described.def("Shared", (void (StepData_Described::*)(Interface_EntityIterator &) const) &StepData_Described::Shared, "Fills an EntityIterator with entities shared by <me>", py::arg("list"));
cls_StepData_Described.def_static("get_type_name_", (const char * (*)()) &StepData_Described::get_type_name, "None");
cls_StepData_Described.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_Described::get_type_descriptor, "None");
cls_StepData_Described.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_Described::*)() const) &StepData_Described::DynamicType, "None");

// Enums

}