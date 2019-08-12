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
#include <StepBasic_ActionMethod.hxx>
#include <StepBasic_VersionedActionRequest.hxx>
#include <StepBasic_ActionRequestSolution.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ActionRequestSolution(py::module &mod){

py::class_<StepBasic_ActionRequestSolution, opencascade::handle<StepBasic_ActionRequestSolution>, Standard_Transient> cls_StepBasic_ActionRequestSolution(mod, "StepBasic_ActionRequestSolution", "Representation of STEP entity ActionRequestSolution");

// Constructors
cls_StepBasic_ActionRequestSolution.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ActionRequestSolution.def("Init", (void (StepBasic_ActionRequestSolution::*)(const opencascade::handle<StepBasic_ActionMethod> &, const opencascade::handle<StepBasic_VersionedActionRequest> &)) &StepBasic_ActionRequestSolution::Init, "Initialize all fields (own and inherited)", py::arg("aMethod"), py::arg("aRequest"));
cls_StepBasic_ActionRequestSolution.def("Method", (opencascade::handle<StepBasic_ActionMethod> (StepBasic_ActionRequestSolution::*)() const) &StepBasic_ActionRequestSolution::Method, "Returns field Method");
cls_StepBasic_ActionRequestSolution.def("SetMethod", (void (StepBasic_ActionRequestSolution::*)(const opencascade::handle<StepBasic_ActionMethod> &)) &StepBasic_ActionRequestSolution::SetMethod, "Set field Method", py::arg("Method"));
cls_StepBasic_ActionRequestSolution.def("Request", (opencascade::handle<StepBasic_VersionedActionRequest> (StepBasic_ActionRequestSolution::*)() const) &StepBasic_ActionRequestSolution::Request, "Returns field Request");
cls_StepBasic_ActionRequestSolution.def("SetRequest", (void (StepBasic_ActionRequestSolution::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &)) &StepBasic_ActionRequestSolution::SetRequest, "Set field Request", py::arg("Request"));
cls_StepBasic_ActionRequestSolution.def_static("get_type_name_", (const char * (*)()) &StepBasic_ActionRequestSolution::get_type_name, "None");
cls_StepBasic_ActionRequestSolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ActionRequestSolution::get_type_descriptor, "None");
cls_StepBasic_ActionRequestSolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ActionRequestSolution::*)() const) &StepBasic_ActionRequestSolution::DynamicType, "None");

// Enums

}