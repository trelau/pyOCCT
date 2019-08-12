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
#include <StepFEA_FeaShellMembraneStiffness.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaShellMembraneStiffness(py::module &mod){

py::class_<StepFEA_FeaShellMembraneStiffness, opencascade::handle<StepFEA_FeaShellMembraneStiffness>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaShellMembraneStiffness(mod, "StepFEA_FeaShellMembraneStiffness", "Representation of STEP entity FeaShellMembraneStiffness");

// Constructors
cls_StepFEA_FeaShellMembraneStiffness.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaShellMembraneStiffness.def("Init", (void (StepFEA_FeaShellMembraneStiffness::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellMembraneStiffness::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
cls_StepFEA_FeaShellMembraneStiffness.def("FeaConstants", (StepFEA_SymmetricTensor42d (StepFEA_FeaShellMembraneStiffness::*)() const) &StepFEA_FeaShellMembraneStiffness::FeaConstants, "Returns field FeaConstants");
cls_StepFEA_FeaShellMembraneStiffness.def("SetFeaConstants", (void (StepFEA_FeaShellMembraneStiffness::*)(const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellMembraneStiffness::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
cls_StepFEA_FeaShellMembraneStiffness.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaShellMembraneStiffness::get_type_name, "None");
cls_StepFEA_FeaShellMembraneStiffness.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaShellMembraneStiffness::get_type_descriptor, "None");
cls_StepFEA_FeaShellMembraneStiffness.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaShellMembraneStiffness::*)() const) &StepFEA_FeaShellMembraneStiffness::DynamicType, "None");

// Enums

}