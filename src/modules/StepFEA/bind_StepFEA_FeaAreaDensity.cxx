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
#include <Standard_TypeDef.hxx>
#include <StepFEA_FeaAreaDensity.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaAreaDensity(py::module &mod){

py::class_<StepFEA_FeaAreaDensity, opencascade::handle<StepFEA_FeaAreaDensity>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaAreaDensity(mod, "StepFEA_FeaAreaDensity", "Representation of STEP entity FeaAreaDensity");

// Constructors
cls_StepFEA_FeaAreaDensity.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaAreaDensity.def("Init", (void (StepFEA_FeaAreaDensity::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real)) &StepFEA_FeaAreaDensity::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstant"));
cls_StepFEA_FeaAreaDensity.def("FeaConstant", (Standard_Real (StepFEA_FeaAreaDensity::*)() const) &StepFEA_FeaAreaDensity::FeaConstant, "Returns field FeaConstant");
cls_StepFEA_FeaAreaDensity.def("SetFeaConstant", (void (StepFEA_FeaAreaDensity::*)(const Standard_Real)) &StepFEA_FeaAreaDensity::SetFeaConstant, "Set field FeaConstant", py::arg("FeaConstant"));
cls_StepFEA_FeaAreaDensity.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaAreaDensity::get_type_name, "None");
cls_StepFEA_FeaAreaDensity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaAreaDensity::get_type_descriptor, "None");
cls_StepFEA_FeaAreaDensity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaAreaDensity::*)() const) &StepFEA_FeaAreaDensity::DynamicType, "None");

// Enums

}