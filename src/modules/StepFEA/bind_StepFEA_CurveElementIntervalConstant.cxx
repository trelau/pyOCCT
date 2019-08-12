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
#include <StepFEA_CurveElementInterval.hxx>
#include <Standard_Handle.hxx>
#include <StepFEA_CurveElementLocation.hxx>
#include <StepBasic_EulerAngles.hxx>
#include <StepElement_CurveElementSectionDefinition.hxx>
#include <StepFEA_CurveElementIntervalConstant.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_CurveElementIntervalConstant(py::module &mod){

py::class_<StepFEA_CurveElementIntervalConstant, opencascade::handle<StepFEA_CurveElementIntervalConstant>, StepFEA_CurveElementInterval> cls_StepFEA_CurveElementIntervalConstant(mod, "StepFEA_CurveElementIntervalConstant", "Representation of STEP entity CurveElementIntervalConstant");

// Constructors
cls_StepFEA_CurveElementIntervalConstant.def(py::init<>());

// Fields

// Methods
cls_StepFEA_CurveElementIntervalConstant.def("Init", (void (StepFEA_CurveElementIntervalConstant::*)(const opencascade::handle<StepFEA_CurveElementLocation> &, const opencascade::handle<StepBasic_EulerAngles> &, const opencascade::handle<StepElement_CurveElementSectionDefinition> &)) &StepFEA_CurveElementIntervalConstant::Init, "Initialize all fields (own and inherited)", py::arg("aCurveElementInterval_FinishPosition"), py::arg("aCurveElementInterval_EuAngles"), py::arg("aSection"));
cls_StepFEA_CurveElementIntervalConstant.def("Section", (opencascade::handle<StepElement_CurveElementSectionDefinition> (StepFEA_CurveElementIntervalConstant::*)() const) &StepFEA_CurveElementIntervalConstant::Section, "Returns field Section");
cls_StepFEA_CurveElementIntervalConstant.def("SetSection", (void (StepFEA_CurveElementIntervalConstant::*)(const opencascade::handle<StepElement_CurveElementSectionDefinition> &)) &StepFEA_CurveElementIntervalConstant::SetSection, "Set field Section", py::arg("Section"));
cls_StepFEA_CurveElementIntervalConstant.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementIntervalConstant::get_type_name, "None");
cls_StepFEA_CurveElementIntervalConstant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementIntervalConstant::get_type_descriptor, "None");
cls_StepFEA_CurveElementIntervalConstant.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementIntervalConstant::*)() const) &StepFEA_CurveElementIntervalConstant::DynamicType, "None");

// Enums

}