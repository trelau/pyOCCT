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
#include <StepData_ESDescr.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_Simple.hxx>
#include <StepData_Field.hxx>
#include <StepData_FieldListN.hxx>
#include <Interface_Check.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_Type.hxx>

void bind_StepData_Simple(py::module &mod){

py::class_<StepData_Simple, opencascade::handle<StepData_Simple>, StepData_Described> cls_StepData_Simple(mod, "StepData_Simple", "A Simple Entity is defined by a type (which can heve super types) and a list of parameters");

// Constructors
cls_StepData_Simple.def(py::init<const opencascade::handle<StepData_ESDescr> &>(), py::arg("descr"));

// Fields

// Methods
cls_StepData_Simple.def("ESDescr", (opencascade::handle<StepData_ESDescr> (StepData_Simple::*)() const) &StepData_Simple::ESDescr, "Returns description, as for simple");
cls_StepData_Simple.def("StepType", (Standard_CString (StepData_Simple::*)() const) &StepData_Simple::StepType, "Returns the recorded StepType (TypeName of its ESDescr)");
cls_StepData_Simple.def("IsComplex", (Standard_Boolean (StepData_Simple::*)() const) &StepData_Simple::IsComplex, "Returns False");
cls_StepData_Simple.def("Matches", (Standard_Boolean (StepData_Simple::*)(const Standard_CString) const) &StepData_Simple::Matches, "Tells if a step type is matched by <me> For a Simple Entity : own type or super type For a Complex Entity : one of the members", py::arg("steptype"));
cls_StepData_Simple.def("As", (opencascade::handle<StepData_Simple> (StepData_Simple::*)(const Standard_CString) const) &StepData_Simple::As, "Returns a Simple Entity which matches with a Type in <me> : For a Simple Entity : me if it matches, else a null handle For a Complex Entity : the member which matches, else null", py::arg("steptype"));
cls_StepData_Simple.def("HasField", (Standard_Boolean (StepData_Simple::*)(const Standard_CString) const) &StepData_Simple::HasField, "Tells if a Field brings a given name", py::arg("name"));
cls_StepData_Simple.def("Field", (const StepData_Field & (StepData_Simple::*)(const Standard_CString) const) &StepData_Simple::Field, "Returns a Field from its name; read-only", py::arg("name"));
cls_StepData_Simple.def("CField", (StepData_Field & (StepData_Simple::*)(const Standard_CString)) &StepData_Simple::CField, "Returns a Field from its name; read or write", py::arg("name"));
cls_StepData_Simple.def("NbFields", (Standard_Integer (StepData_Simple::*)() const) &StepData_Simple::NbFields, "Returns the count of fields");
cls_StepData_Simple.def("FieldNum", (const StepData_Field & (StepData_Simple::*)(const Standard_Integer) const) &StepData_Simple::FieldNum, "Returns a field from its rank, for read-only use", py::arg("num"));
cls_StepData_Simple.def("CFieldNum", (StepData_Field & (StepData_Simple::*)(const Standard_Integer)) &StepData_Simple::CFieldNum, "Returns a field from its rank, in order to modify it", py::arg("num"));
cls_StepData_Simple.def("Fields", (const StepData_FieldListN & (StepData_Simple::*)() const) &StepData_Simple::Fields, "Returns the entire field list, read-only");
cls_StepData_Simple.def("CFields", (StepData_FieldListN & (StepData_Simple::*)()) &StepData_Simple::CFields, "Returns the entire field list, read or write");
cls_StepData_Simple.def("Check", (void (StepData_Simple::*)(opencascade::handle<Interface_Check> &) const) &StepData_Simple::Check, "Fills a Check by using its Description", py::arg("ach"));
cls_StepData_Simple.def("Shared", (void (StepData_Simple::*)(Interface_EntityIterator &) const) &StepData_Simple::Shared, "Fills an EntityIterator with entities shared by <me>", py::arg("list"));
cls_StepData_Simple.def_static("get_type_name_", (const char * (*)()) &StepData_Simple::get_type_name, "None");
cls_StepData_Simple.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_Simple::get_type_descriptor, "None");
cls_StepData_Simple.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_Simple::*)() const) &StepData_Simple::DynamicType, "None");

// Enums

}