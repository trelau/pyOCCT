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
#include <StepBasic_DocumentReference.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Document.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepAP214_HArray1OfDocumentReferenceItem.hxx>
#include <StepAP214_DocumentReferenceItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AppliedDocumentReference.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AppliedDocumentReference(py::module &mod){

py::class_<StepAP214_AppliedDocumentReference, opencascade::handle<StepAP214_AppliedDocumentReference>, StepBasic_DocumentReference> cls_StepAP214_AppliedDocumentReference(mod, "StepAP214_AppliedDocumentReference", "None");

// Constructors
cls_StepAP214_AppliedDocumentReference.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AppliedDocumentReference.def("Init", (void (StepAP214_AppliedDocumentReference::*)(const opencascade::handle<StepBasic_Document> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepAP214_HArray1OfDocumentReferenceItem> &)) &StepAP214_AppliedDocumentReference::Init, "None", py::arg("aAssignedDocument"), py::arg("aSource"), py::arg("aItems"));
cls_StepAP214_AppliedDocumentReference.def("Items", (opencascade::handle<StepAP214_HArray1OfDocumentReferenceItem> (StepAP214_AppliedDocumentReference::*)() const) &StepAP214_AppliedDocumentReference::Items, "None");
cls_StepAP214_AppliedDocumentReference.def("SetItems", (void (StepAP214_AppliedDocumentReference::*)(const opencascade::handle<StepAP214_HArray1OfDocumentReferenceItem> &)) &StepAP214_AppliedDocumentReference::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedDocumentReference.def("ItemsValue", (StepAP214_DocumentReferenceItem (StepAP214_AppliedDocumentReference::*)(const Standard_Integer) const) &StepAP214_AppliedDocumentReference::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedDocumentReference.def("NbItems", (Standard_Integer (StepAP214_AppliedDocumentReference::*)() const) &StepAP214_AppliedDocumentReference::NbItems, "None");
cls_StepAP214_AppliedDocumentReference.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedDocumentReference::get_type_name, "None");
cls_StepAP214_AppliedDocumentReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedDocumentReference::get_type_descriptor, "None");
cls_StepAP214_AppliedDocumentReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedDocumentReference::*)() const) &StepAP214_AppliedDocumentReference::DynamicType, "None");

// Enums

}