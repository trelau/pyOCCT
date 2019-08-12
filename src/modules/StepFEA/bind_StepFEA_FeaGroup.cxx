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
#include <StepBasic_Group.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepFEA_FeaModel.hxx>
#include <StepFEA_FeaGroup.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaGroup(py::module &mod){

py::class_<StepFEA_FeaGroup, opencascade::handle<StepFEA_FeaGroup>, StepBasic_Group> cls_StepFEA_FeaGroup(mod, "StepFEA_FeaGroup", "Representation of STEP entity FeaGroup");

// Constructors
cls_StepFEA_FeaGroup.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaGroup.def("Init", (void (StepFEA_FeaGroup::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaModel> &)) &StepFEA_FeaGroup::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("aGroup_Description"), py::arg("aModelRef"));
cls_StepFEA_FeaGroup.def("ModelRef", (opencascade::handle<StepFEA_FeaModel> (StepFEA_FeaGroup::*)() const) &StepFEA_FeaGroup::ModelRef, "Returns field ModelRef");
cls_StepFEA_FeaGroup.def("SetModelRef", (void (StepFEA_FeaGroup::*)(const opencascade::handle<StepFEA_FeaModel> &)) &StepFEA_FeaGroup::SetModelRef, "Set field ModelRef", py::arg("ModelRef"));
cls_StepFEA_FeaGroup.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaGroup::get_type_name, "None");
cls_StepFEA_FeaGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaGroup::get_type_descriptor, "None");
cls_StepFEA_FeaGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaGroup::*)() const) &StepFEA_FeaGroup::DynamicType, "None");

// Enums

}