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
#include <Interface_HArray1OfHAsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <HeaderSection_FileSchema.hxx>
#include <Standard_Type.hxx>

void bind_HeaderSection_FileSchema(py::module &mod){

py::class_<HeaderSection_FileSchema, opencascade::handle<HeaderSection_FileSchema>, Standard_Transient> cls_HeaderSection_FileSchema(mod, "HeaderSection_FileSchema", "None");

// Constructors
cls_HeaderSection_FileSchema.def(py::init<>());

// Fields

// Methods
cls_HeaderSection_FileSchema.def("Init", (void (HeaderSection_FileSchema::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileSchema::Init, "None", py::arg("aSchemaIdentifiers"));
cls_HeaderSection_FileSchema.def("SetSchemaIdentifiers", (void (HeaderSection_FileSchema::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileSchema::SetSchemaIdentifiers, "None", py::arg("aSchemaIdentifiers"));
cls_HeaderSection_FileSchema.def("SchemaIdentifiers", (opencascade::handle<Interface_HArray1OfHAsciiString> (HeaderSection_FileSchema::*)() const) &HeaderSection_FileSchema::SchemaIdentifiers, "None");
cls_HeaderSection_FileSchema.def("SchemaIdentifiersValue", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileSchema::*)(const Standard_Integer) const) &HeaderSection_FileSchema::SchemaIdentifiersValue, "None", py::arg("num"));
cls_HeaderSection_FileSchema.def("NbSchemaIdentifiers", (Standard_Integer (HeaderSection_FileSchema::*)() const) &HeaderSection_FileSchema::NbSchemaIdentifiers, "None");
cls_HeaderSection_FileSchema.def_static("get_type_name_", (const char * (*)()) &HeaderSection_FileSchema::get_type_name, "None");
cls_HeaderSection_FileSchema.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_FileSchema::get_type_descriptor, "None");
cls_HeaderSection_FileSchema.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_FileSchema::*)() const) &HeaderSection_FileSchema::DynamicType, "None");

// Enums

}