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
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_Document.hxx>
#include <StepBasic_DocumentRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DocumentRelationship(py::module &mod){

py::class_<StepBasic_DocumentRelationship, opencascade::handle<StepBasic_DocumentRelationship>, Standard_Transient> cls_StepBasic_DocumentRelationship(mod, "StepBasic_DocumentRelationship", "None");

// Constructors
cls_StepBasic_DocumentRelationship.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DocumentRelationship.def("Init", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Document> &, const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRelationship::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aRelating"), py::arg("aRelated"));
cls_StepBasic_DocumentRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentRelationship::*)() const) &StepBasic_DocumentRelationship::Name, "None");
cls_StepBasic_DocumentRelationship.def("SetName", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentRelationship::SetName, "None", py::arg("aName"));
cls_StepBasic_DocumentRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentRelationship::*)() const) &StepBasic_DocumentRelationship::Description, "None");
cls_StepBasic_DocumentRelationship.def("SetDescription", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentRelationship::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_DocumentRelationship.def("RelatingDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentRelationship::*)() const) &StepBasic_DocumentRelationship::RelatingDocument, "None");
cls_StepBasic_DocumentRelationship.def("SetRelatingDocument", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRelationship::SetRelatingDocument, "None", py::arg("aRelating"));
cls_StepBasic_DocumentRelationship.def("RelatedDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentRelationship::*)() const) &StepBasic_DocumentRelationship::RelatedDocument, "None");
cls_StepBasic_DocumentRelationship.def("SetRelatedDocument", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRelationship::SetRelatedDocument, "None", py::arg("aRelated"));
cls_StepBasic_DocumentRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentRelationship::get_type_name, "None");
cls_StepBasic_DocumentRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentRelationship::get_type_descriptor, "None");
cls_StepBasic_DocumentRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentRelationship::*)() const) &StepBasic_DocumentRelationship::DynamicType, "None");

// Enums

}