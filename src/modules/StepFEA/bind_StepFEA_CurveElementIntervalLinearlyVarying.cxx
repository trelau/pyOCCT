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
#include <StepElement_HArray1OfCurveElementSectionDefinition.hxx>
#include <StepFEA_CurveElementIntervalLinearlyVarying.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_CurveElementIntervalLinearlyVarying(py::module &mod){

py::class_<StepFEA_CurveElementIntervalLinearlyVarying, opencascade::handle<StepFEA_CurveElementIntervalLinearlyVarying>, StepFEA_CurveElementInterval> cls_StepFEA_CurveElementIntervalLinearlyVarying(mod, "StepFEA_CurveElementIntervalLinearlyVarying", "Representation of STEP entity CurveElementIntervalLinearlyVarying");

// Constructors
cls_StepFEA_CurveElementIntervalLinearlyVarying.def(py::init<>());

// Fields

// Methods
cls_StepFEA_CurveElementIntervalLinearlyVarying.def("Init", (void (StepFEA_CurveElementIntervalLinearlyVarying::*)(const opencascade::handle<StepFEA_CurveElementLocation> &, const opencascade::handle<StepBasic_EulerAngles> &, const opencascade::handle<StepElement_HArray1OfCurveElementSectionDefinition> &)) &StepFEA_CurveElementIntervalLinearlyVarying::Init, "Initialize all fields (own and inherited)", py::arg("aCurveElementInterval_FinishPosition"), py::arg("aCurveElementInterval_EuAngles"), py::arg("aSections"));
cls_StepFEA_CurveElementIntervalLinearlyVarying.def("Sections", (opencascade::handle<StepElement_HArray1OfCurveElementSectionDefinition> (StepFEA_CurveElementIntervalLinearlyVarying::*)() const) &StepFEA_CurveElementIntervalLinearlyVarying::Sections, "Returns field Sections");
cls_StepFEA_CurveElementIntervalLinearlyVarying.def("SetSections", (void (StepFEA_CurveElementIntervalLinearlyVarying::*)(const opencascade::handle<StepElement_HArray1OfCurveElementSectionDefinition> &)) &StepFEA_CurveElementIntervalLinearlyVarying::SetSections, "Set field Sections", py::arg("Sections"));
cls_StepFEA_CurveElementIntervalLinearlyVarying.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementIntervalLinearlyVarying::get_type_name, "None");
cls_StepFEA_CurveElementIntervalLinearlyVarying.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementIntervalLinearlyVarying::get_type_descriptor, "None");
cls_StepFEA_CurveElementIntervalLinearlyVarying.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementIntervalLinearlyVarying::*)() const) &StepFEA_CurveElementIntervalLinearlyVarying::DynamicType, "None");

// Enums

}