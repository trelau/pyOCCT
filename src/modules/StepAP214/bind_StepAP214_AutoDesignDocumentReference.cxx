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
#include <StepAP214_HArray1OfAutoDesignReferencingItem.hxx>
#include <StepAP214_AutoDesignReferencingItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AutoDesignDocumentReference.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AutoDesignDocumentReference(py::module &mod){

py::class_<StepAP214_AutoDesignDocumentReference, opencascade::handle<StepAP214_AutoDesignDocumentReference>, StepBasic_DocumentReference> cls_StepAP214_AutoDesignDocumentReference(mod, "StepAP214_AutoDesignDocumentReference", "None");

// Constructors
cls_StepAP214_AutoDesignDocumentReference.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AutoDesignDocumentReference.def("Init", (void (StepAP214_AutoDesignDocumentReference::*)(const opencascade::handle<StepBasic_Document> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignReferencingItem> &)) &StepAP214_AutoDesignDocumentReference::Init, "None", py::arg("aAssignedDocument"), py::arg("aSource"), py::arg("aItems"));
cls_StepAP214_AutoDesignDocumentReference.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignReferencingItem> (StepAP214_AutoDesignDocumentReference::*)() const) &StepAP214_AutoDesignDocumentReference::Items, "None");
cls_StepAP214_AutoDesignDocumentReference.def("SetItems", (void (StepAP214_AutoDesignDocumentReference::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignReferencingItem> &)) &StepAP214_AutoDesignDocumentReference::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignDocumentReference.def("ItemsValue", (StepAP214_AutoDesignReferencingItem (StepAP214_AutoDesignDocumentReference::*)(const Standard_Integer) const) &StepAP214_AutoDesignDocumentReference::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignDocumentReference.def("NbItems", (Standard_Integer (StepAP214_AutoDesignDocumentReference::*)() const) &StepAP214_AutoDesignDocumentReference::NbItems, "None");
cls_StepAP214_AutoDesignDocumentReference.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignDocumentReference::get_type_name, "None");
cls_StepAP214_AutoDesignDocumentReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignDocumentReference::get_type_descriptor, "None");
cls_StepAP214_AutoDesignDocumentReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignDocumentReference::*)() const) &StepAP214_AutoDesignDocumentReference::DynamicType, "None");

// Enums

}