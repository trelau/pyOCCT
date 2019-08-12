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
#include <StepFEA_FeaMaterialPropertyRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepFEA_SymmetricTensor42d.hxx>
#include <StepFEA_FeaShellMembraneBendingCouplingStiffness.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaShellMembraneBendingCouplingStiffness(py::module &mod){

py::class_<StepFEA_FeaShellMembraneBendingCouplingStiffness, opencascade::handle<StepFEA_FeaShellMembraneBendingCouplingStiffness>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaShellMembraneBendingCouplingStiffness(mod, "StepFEA_FeaShellMembraneBendingCouplingStiffness", "Representation of STEP entity FeaShellMembraneBendingCouplingStiffness");

// Constructors
cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def("Init", (void (StepFEA_FeaShellMembraneBendingCouplingStiffness::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellMembraneBendingCouplingStiffness::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def("FeaConstants", (StepFEA_SymmetricTensor42d (StepFEA_FeaShellMembraneBendingCouplingStiffness::*)() const) &StepFEA_FeaShellMembraneBendingCouplingStiffness::FeaConstants, "Returns field FeaConstants");
cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def("SetFeaConstants", (void (StepFEA_FeaShellMembraneBendingCouplingStiffness::*)(const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellMembraneBendingCouplingStiffness::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaShellMembraneBendingCouplingStiffness::get_type_name, "None");
cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaShellMembraneBendingCouplingStiffness::get_type_descriptor, "None");
cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaShellMembraneBendingCouplingStiffness::*)() const) &StepFEA_FeaShellMembraneBendingCouplingStiffness::DynamicType, "None");

// Enums

}