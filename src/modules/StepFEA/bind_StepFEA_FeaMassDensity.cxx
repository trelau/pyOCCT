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
#include <StepFEA_FeaMassDensity.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaMassDensity(py::module &mod){

py::class_<StepFEA_FeaMassDensity, opencascade::handle<StepFEA_FeaMassDensity>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaMassDensity(mod, "StepFEA_FeaMassDensity", "Representation of STEP entity FeaMassDensity");

// Constructors
cls_StepFEA_FeaMassDensity.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaMassDensity.def("Init", (void (StepFEA_FeaMassDensity::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real)) &StepFEA_FeaMassDensity::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstant"));
cls_StepFEA_FeaMassDensity.def("FeaConstant", (Standard_Real (StepFEA_FeaMassDensity::*)() const) &StepFEA_FeaMassDensity::FeaConstant, "Returns field FeaConstant");
cls_StepFEA_FeaMassDensity.def("SetFeaConstant", (void (StepFEA_FeaMassDensity::*)(const Standard_Real)) &StepFEA_FeaMassDensity::SetFeaConstant, "Set field FeaConstant", py::arg("FeaConstant"));
cls_StepFEA_FeaMassDensity.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaMassDensity::get_type_name, "None");
cls_StepFEA_FeaMassDensity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaMassDensity::get_type_descriptor, "None");
cls_StepFEA_FeaMassDensity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaMassDensity::*)() const) &StepFEA_FeaMassDensity::DynamicType, "None");

// Enums

}