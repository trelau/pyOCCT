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
#include <StepData_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Interface_Protocol.hxx>
#include <StepAP214_Protocol.hxx>

void bind_StepAP214_Protocol(py::module &mod){

py::class_<StepAP214_Protocol, opencascade::handle<StepAP214_Protocol>, StepData_Protocol> cls_StepAP214_Protocol(mod, "StepAP214_Protocol", "Protocol for StepAP214 Entities It requires StepAP214 as a Resource");

// Constructors
cls_StepAP214_Protocol.def(py::init<>());

// Fields

// Methods
cls_StepAP214_Protocol.def("TypeNumber", (Standard_Integer (StepAP214_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &StepAP214_Protocol::TypeNumber, "Returns a Case Number for each of the StepAP214 Entities", py::arg("atype"));
cls_StepAP214_Protocol.def("SchemaName", (Standard_CString (StepAP214_Protocol::*)() const) &StepAP214_Protocol::SchemaName, "None");
cls_StepAP214_Protocol.def("NbResources", (Standard_Integer (StepAP214_Protocol::*)() const) &StepAP214_Protocol::NbResources, "Returns count of Protocol used as Resources (level one)");
cls_StepAP214_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (StepAP214_Protocol::*)(const Standard_Integer) const) &StepAP214_Protocol::Resource, "Returns a Resource, given its rank (between 1 and NbResources)", py::arg("num"));
cls_StepAP214_Protocol.def_static("get_type_name_", (const char * (*)()) &StepAP214_Protocol::get_type_name, "None");
cls_StepAP214_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_Protocol::get_type_descriptor, "None");
cls_StepAP214_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_Protocol::*)() const) &StepAP214_Protocol::DynamicType, "None");

// Enums

}