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
#include <StepBasic_ExternalIdentificationAssignment.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_IdentificationRole.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <StepAP214_HArray1OfExternalIdentificationItem.hxx>
#include <StepAP214_AppliedExternalIdentificationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AppliedExternalIdentificationAssignment(py::module &mod){

py::class_<StepAP214_AppliedExternalIdentificationAssignment, opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment>, StepBasic_ExternalIdentificationAssignment> cls_StepAP214_AppliedExternalIdentificationAssignment(mod, "StepAP214_AppliedExternalIdentificationAssignment", "Representation of STEP entity AppliedExternalIdentificationAssignment");

// Constructors
cls_StepAP214_AppliedExternalIdentificationAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AppliedExternalIdentificationAssignment.def("Init", (void (StepAP214_AppliedExternalIdentificationAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_IdentificationRole> &, const opencascade::handle<StepBasic_ExternalSource> &, const opencascade::handle<StepAP214_HArray1OfExternalIdentificationItem> &)) &StepAP214_AppliedExternalIdentificationAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aIdentificationAssignment_AssignedId"), py::arg("aIdentificationAssignment_Role"), py::arg("aExternalIdentificationAssignment_Source"), py::arg("aItems"));
cls_StepAP214_AppliedExternalIdentificationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfExternalIdentificationItem> (StepAP214_AppliedExternalIdentificationAssignment::*)() const) &StepAP214_AppliedExternalIdentificationAssignment::Items, "Returns field Items");
cls_StepAP214_AppliedExternalIdentificationAssignment.def("SetItems", (void (StepAP214_AppliedExternalIdentificationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfExternalIdentificationItem> &)) &StepAP214_AppliedExternalIdentificationAssignment::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP214_AppliedExternalIdentificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedExternalIdentificationAssignment::get_type_name, "None");
cls_StepAP214_AppliedExternalIdentificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedExternalIdentificationAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedExternalIdentificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedExternalIdentificationAssignment::*)() const) &StepAP214_AppliedExternalIdentificationAssignment::DynamicType, "None");

// Enums

}