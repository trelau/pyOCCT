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
#include <StepBasic_ActionAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Action.hxx>
#include <StepAP203_HArray1OfWorkItem.hxx>
#include <StepAP203_StartWork.hxx>
#include <Standard_Type.hxx>

void bind_StepAP203_StartWork(py::module &mod){

py::class_<StepAP203_StartWork, opencascade::handle<StepAP203_StartWork>, StepBasic_ActionAssignment> cls_StepAP203_StartWork(mod, "StepAP203_StartWork", "Representation of STEP entity StartWork");

// Constructors
cls_StepAP203_StartWork.def(py::init<>());

// Fields

// Methods
cls_StepAP203_StartWork.def("Init", (void (StepAP203_StartWork::*)(const opencascade::handle<StepBasic_Action> &, const opencascade::handle<StepAP203_HArray1OfWorkItem> &)) &StepAP203_StartWork::Init, "Initialize all fields (own and inherited)", py::arg("aActionAssignment_AssignedAction"), py::arg("aItems"));
cls_StepAP203_StartWork.def("Items", (opencascade::handle<StepAP203_HArray1OfWorkItem> (StepAP203_StartWork::*)() const) &StepAP203_StartWork::Items, "Returns field Items");
cls_StepAP203_StartWork.def("SetItems", (void (StepAP203_StartWork::*)(const opencascade::handle<StepAP203_HArray1OfWorkItem> &)) &StepAP203_StartWork::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP203_StartWork.def_static("get_type_name_", (const char * (*)()) &StepAP203_StartWork::get_type_name, "None");
cls_StepAP203_StartWork.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_StartWork::get_type_descriptor, "None");
cls_StepAP203_StartWork.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_StartWork::*)() const) &StepAP203_StartWork::DynamicType, "None");

// Enums

}