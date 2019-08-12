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
#include <StepBasic_VersionedActionRequest.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_VersionedActionRequest(py::module &mod){

py::class_<StepBasic_VersionedActionRequest, opencascade::handle<StepBasic_VersionedActionRequest>, Standard_Transient> cls_StepBasic_VersionedActionRequest(mod, "StepBasic_VersionedActionRequest", "Representation of STEP entity VersionedActionRequest");

// Constructors
cls_StepBasic_VersionedActionRequest.def(py::init<>());

// Fields

// Methods
cls_StepBasic_VersionedActionRequest.def("Init", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aVersion"), py::arg("aPurpose"), py::arg("hasDescription"), py::arg("aDescription"));
cls_StepBasic_VersionedActionRequest.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_VersionedActionRequest::*)() const) &StepBasic_VersionedActionRequest::Id, "Returns field Id");
cls_StepBasic_VersionedActionRequest.def("SetId", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::SetId, "Set field Id", py::arg("Id"));
cls_StepBasic_VersionedActionRequest.def("Version", (opencascade::handle<TCollection_HAsciiString> (StepBasic_VersionedActionRequest::*)() const) &StepBasic_VersionedActionRequest::Version, "Returns field Version");
cls_StepBasic_VersionedActionRequest.def("SetVersion", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::SetVersion, "Set field Version", py::arg("Version"));
cls_StepBasic_VersionedActionRequest.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_VersionedActionRequest::*)() const) &StepBasic_VersionedActionRequest::Purpose, "Returns field Purpose");
cls_StepBasic_VersionedActionRequest.def("SetPurpose", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepBasic_VersionedActionRequest.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_VersionedActionRequest::*)() const) &StepBasic_VersionedActionRequest::Description, "Returns field Description");
cls_StepBasic_VersionedActionRequest.def("SetDescription", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_VersionedActionRequest.def("HasDescription", (Standard_Boolean (StepBasic_VersionedActionRequest::*)() const) &StepBasic_VersionedActionRequest::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_VersionedActionRequest.def_static("get_type_name_", (const char * (*)()) &StepBasic_VersionedActionRequest::get_type_name, "None");
cls_StepBasic_VersionedActionRequest.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_VersionedActionRequest::get_type_descriptor, "None");
cls_StepBasic_VersionedActionRequest.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_VersionedActionRequest::*)() const) &StepBasic_VersionedActionRequest::DynamicType, "None");

// Enums

}