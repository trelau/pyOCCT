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
#include <StepFEA_SymmetricTensor23d.hxx>
#include <StepFEA_FeaMoistureAbsorption.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaMoistureAbsorption(py::module &mod){

py::class_<StepFEA_FeaMoistureAbsorption, opencascade::handle<StepFEA_FeaMoistureAbsorption>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaMoistureAbsorption(mod, "StepFEA_FeaMoistureAbsorption", "Representation of STEP entity FeaMoistureAbsorption");

// Constructors
cls_StepFEA_FeaMoistureAbsorption.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaMoistureAbsorption.def("Init", (void (StepFEA_FeaMoistureAbsorption::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor23d &)) &StepFEA_FeaMoistureAbsorption::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
cls_StepFEA_FeaMoistureAbsorption.def("FeaConstants", (StepFEA_SymmetricTensor23d (StepFEA_FeaMoistureAbsorption::*)() const) &StepFEA_FeaMoistureAbsorption::FeaConstants, "Returns field FeaConstants");
cls_StepFEA_FeaMoistureAbsorption.def("SetFeaConstants", (void (StepFEA_FeaMoistureAbsorption::*)(const StepFEA_SymmetricTensor23d &)) &StepFEA_FeaMoistureAbsorption::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
cls_StepFEA_FeaMoistureAbsorption.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaMoistureAbsorption::get_type_name, "None");
cls_StepFEA_FeaMoistureAbsorption.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaMoistureAbsorption::get_type_descriptor, "None");
cls_StepFEA_FeaMoistureAbsorption.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaMoistureAbsorption::*)() const) &StepFEA_FeaMoistureAbsorption::DynamicType, "None");

// Enums

}