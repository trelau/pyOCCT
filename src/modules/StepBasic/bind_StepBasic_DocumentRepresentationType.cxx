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
#include <StepBasic_DocumentRepresentationType.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DocumentRepresentationType(py::module &mod){

py::class_<StepBasic_DocumentRepresentationType, opencascade::handle<StepBasic_DocumentRepresentationType>, Standard_Transient> cls_StepBasic_DocumentRepresentationType(mod, "StepBasic_DocumentRepresentationType", "Representation of STEP entity DocumentRepresentationType");

// Constructors
cls_StepBasic_DocumentRepresentationType.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DocumentRepresentationType.def("Init", (void (StepBasic_DocumentRepresentationType::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRepresentationType::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aRepresentedDocument"));
cls_StepBasic_DocumentRepresentationType.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentRepresentationType::*)() const) &StepBasic_DocumentRepresentationType::Name, "Returns field Name");
cls_StepBasic_DocumentRepresentationType.def("SetName", (void (StepBasic_DocumentRepresentationType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentRepresentationType::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_DocumentRepresentationType.def("RepresentedDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentRepresentationType::*)() const) &StepBasic_DocumentRepresentationType::RepresentedDocument, "Returns field RepresentedDocument");
cls_StepBasic_DocumentRepresentationType.def("SetRepresentedDocument", (void (StepBasic_DocumentRepresentationType::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRepresentationType::SetRepresentedDocument, "Set field RepresentedDocument", py::arg("RepresentedDocument"));
cls_StepBasic_DocumentRepresentationType.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentRepresentationType::get_type_name, "None");
cls_StepBasic_DocumentRepresentationType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentRepresentationType::get_type_descriptor, "None");
cls_StepBasic_DocumentRepresentationType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentRepresentationType::*)() const) &StepBasic_DocumentRepresentationType::DynamicType, "None");

// Enums

}