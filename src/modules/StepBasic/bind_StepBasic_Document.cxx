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
#include <Standard_TypeDef.hxx>
#include <StepBasic_DocumentType.hxx>
#include <StepBasic_Document.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Document(py::module &mod){

py::class_<StepBasic_Document, opencascade::handle<StepBasic_Document>, Standard_Transient> cls_StepBasic_Document(mod, "StepBasic_Document", "Representation of STEP entity Document");

// Constructors
cls_StepBasic_Document.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Document.def("Init", (void (StepBasic_Document::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_DocumentType> &)) &StepBasic_Document::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aKind"));
cls_StepBasic_Document.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Document::*)() const) &StepBasic_Document::Id, "Returns field Id");
cls_StepBasic_Document.def("SetId", (void (StepBasic_Document::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Document::SetId, "Set field Id", py::arg("Id"));
cls_StepBasic_Document.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Document::*)() const) &StepBasic_Document::Name, "Returns field Name");
cls_StepBasic_Document.def("SetName", (void (StepBasic_Document::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Document::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_Document.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Document::*)() const) &StepBasic_Document::Description, "Returns field Description");
cls_StepBasic_Document.def("SetDescription", (void (StepBasic_Document::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Document::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_Document.def("HasDescription", (Standard_Boolean (StepBasic_Document::*)() const) &StepBasic_Document::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_Document.def("Kind", (opencascade::handle<StepBasic_DocumentType> (StepBasic_Document::*)() const) &StepBasic_Document::Kind, "Returns field Kind");
cls_StepBasic_Document.def("SetKind", (void (StepBasic_Document::*)(const opencascade::handle<StepBasic_DocumentType> &)) &StepBasic_Document::SetKind, "Set field Kind", py::arg("Kind"));
cls_StepBasic_Document.def_static("get_type_name_", (const char * (*)()) &StepBasic_Document::get_type_name, "None");
cls_StepBasic_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Document::get_type_descriptor, "None");
cls_StepBasic_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Document::*)() const) &StepBasic_Document::DynamicType, "None");

// Enums

}