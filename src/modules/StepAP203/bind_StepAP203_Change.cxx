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
#include <StepAP203_Change.hxx>
#include <Standard_Type.hxx>

void bind_StepAP203_Change(py::module &mod){

py::class_<StepAP203_Change, opencascade::handle<StepAP203_Change>, StepBasic_ActionAssignment> cls_StepAP203_Change(mod, "StepAP203_Change", "Representation of STEP entity Change");

// Constructors
cls_StepAP203_Change.def(py::init<>());

// Fields

// Methods
cls_StepAP203_Change.def("Init", (void (StepAP203_Change::*)(const opencascade::handle<StepBasic_Action> &, const opencascade::handle<StepAP203_HArray1OfWorkItem> &)) &StepAP203_Change::Init, "Initialize all fields (own and inherited)", py::arg("aActionAssignment_AssignedAction"), py::arg("aItems"));
cls_StepAP203_Change.def("Items", (opencascade::handle<StepAP203_HArray1OfWorkItem> (StepAP203_Change::*)() const) &StepAP203_Change::Items, "Returns field Items");
cls_StepAP203_Change.def("SetItems", (void (StepAP203_Change::*)(const opencascade::handle<StepAP203_HArray1OfWorkItem> &)) &StepAP203_Change::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP203_Change.def_static("get_type_name_", (const char * (*)()) &StepAP203_Change::get_type_name, "None");
cls_StepAP203_Change.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_Change::get_type_descriptor, "None");
cls_StepAP203_Change.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_Change::*)() const) &StepAP203_Change::DynamicType, "None");

// Enums

}