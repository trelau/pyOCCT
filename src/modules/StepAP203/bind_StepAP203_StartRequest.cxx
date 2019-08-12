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
#include <StepBasic_ActionRequestAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_VersionedActionRequest.hxx>
#include <StepAP203_HArray1OfStartRequestItem.hxx>
#include <StepAP203_StartRequest.hxx>
#include <Standard_Type.hxx>

void bind_StepAP203_StartRequest(py::module &mod){

py::class_<StepAP203_StartRequest, opencascade::handle<StepAP203_StartRequest>, StepBasic_ActionRequestAssignment> cls_StepAP203_StartRequest(mod, "StepAP203_StartRequest", "Representation of STEP entity StartRequest");

// Constructors
cls_StepAP203_StartRequest.def(py::init<>());

// Fields

// Methods
cls_StepAP203_StartRequest.def("Init", (void (StepAP203_StartRequest::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &, const opencascade::handle<StepAP203_HArray1OfStartRequestItem> &)) &StepAP203_StartRequest::Init, "Initialize all fields (own and inherited)", py::arg("aActionRequestAssignment_AssignedActionRequest"), py::arg("aItems"));
cls_StepAP203_StartRequest.def("Items", (opencascade::handle<StepAP203_HArray1OfStartRequestItem> (StepAP203_StartRequest::*)() const) &StepAP203_StartRequest::Items, "Returns field Items");
cls_StepAP203_StartRequest.def("SetItems", (void (StepAP203_StartRequest::*)(const opencascade::handle<StepAP203_HArray1OfStartRequestItem> &)) &StepAP203_StartRequest::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP203_StartRequest.def_static("get_type_name_", (const char * (*)()) &StepAP203_StartRequest::get_type_name, "None");
cls_StepAP203_StartRequest.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_StartRequest::get_type_descriptor, "None");
cls_StepAP203_StartRequest.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_StartRequest::*)() const) &StepAP203_StartRequest::DynamicType, "None");

// Enums

}