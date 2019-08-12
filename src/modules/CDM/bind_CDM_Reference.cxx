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
#include <CDM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <CDM_Reference.hxx>
#include <Standard_Type.hxx>
#include <CDM_MetaData.hxx>
#include <CDM_Application.hxx>
#include <CDM_DocumentPointer.hxx>

void bind_CDM_Reference(py::module &mod){

py::class_<CDM_Reference, opencascade::handle<CDM_Reference>, Standard_Transient> cls_CDM_Reference(mod, "CDM_Reference", "None");

// Constructors

// Fields

// Methods
cls_CDM_Reference.def("FromDocument", (opencascade::handle<CDM_Document> (CDM_Reference::*)()) &CDM_Reference::FromDocument, "None");
cls_CDM_Reference.def("ToDocument", (opencascade::handle<CDM_Document> (CDM_Reference::*)()) &CDM_Reference::ToDocument, "None");
cls_CDM_Reference.def("ReferenceIdentifier", (Standard_Integer (CDM_Reference::*)()) &CDM_Reference::ReferenceIdentifier, "None");
cls_CDM_Reference.def("DocumentVersion", (Standard_Integer (CDM_Reference::*)() const) &CDM_Reference::DocumentVersion, "None");
cls_CDM_Reference.def("IsReadOnly", (Standard_Boolean (CDM_Reference::*)() const) &CDM_Reference::IsReadOnly, "None");
cls_CDM_Reference.def_static("get_type_name_", (const char * (*)()) &CDM_Reference::get_type_name, "None");
cls_CDM_Reference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_Reference::get_type_descriptor, "None");
cls_CDM_Reference.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_Reference::*)() const) &CDM_Reference::DynamicType, "None");

// Enums

}