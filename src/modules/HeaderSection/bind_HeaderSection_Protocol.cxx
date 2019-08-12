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
#include <HeaderSection_Protocol.hxx>

void bind_HeaderSection_Protocol(py::module &mod){

py::class_<HeaderSection_Protocol, opencascade::handle<HeaderSection_Protocol>, StepData_Protocol> cls_HeaderSection_Protocol(mod, "HeaderSection_Protocol", "Protocol for HeaderSection Entities It requires HeaderSection as a Resource");

// Constructors
cls_HeaderSection_Protocol.def(py::init<>());

// Fields

// Methods
cls_HeaderSection_Protocol.def("TypeNumber", (Standard_Integer (HeaderSection_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &HeaderSection_Protocol::TypeNumber, "Returns a Case Number for each of the HeaderSection Entities", py::arg("atype"));
cls_HeaderSection_Protocol.def("SchemaName", (Standard_CString (HeaderSection_Protocol::*)() const) &HeaderSection_Protocol::SchemaName, "None");
cls_HeaderSection_Protocol.def_static("get_type_name_", (const char * (*)()) &HeaderSection_Protocol::get_type_name, "None");
cls_HeaderSection_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_Protocol::get_type_descriptor, "None");
cls_HeaderSection_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_Protocol::*)() const) &HeaderSection_Protocol::DynamicType, "None");

// Enums

}