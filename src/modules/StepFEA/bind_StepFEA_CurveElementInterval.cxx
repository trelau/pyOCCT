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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StepFEA_CurveElementLocation.hxx>
#include <StepBasic_EulerAngles.hxx>
#include <StepFEA_CurveElementInterval.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_CurveElementInterval(py::module &mod){

py::class_<StepFEA_CurveElementInterval, opencascade::handle<StepFEA_CurveElementInterval>, Standard_Transient> cls_StepFEA_CurveElementInterval(mod, "StepFEA_CurveElementInterval", "Representation of STEP entity CurveElementInterval");

// Constructors
cls_StepFEA_CurveElementInterval.def(py::init<>());

// Fields

// Methods
cls_StepFEA_CurveElementInterval.def("Init", (void (StepFEA_CurveElementInterval::*)(const opencascade::handle<StepFEA_CurveElementLocation> &, const opencascade::handle<StepBasic_EulerAngles> &)) &StepFEA_CurveElementInterval::Init, "Initialize all fields (own and inherited)", py::arg("aFinishPosition"), py::arg("aEuAngles"));
cls_StepFEA_CurveElementInterval.def("FinishPosition", (opencascade::handle<StepFEA_CurveElementLocation> (StepFEA_CurveElementInterval::*)() const) &StepFEA_CurveElementInterval::FinishPosition, "Returns field FinishPosition");
cls_StepFEA_CurveElementInterval.def("SetFinishPosition", (void (StepFEA_CurveElementInterval::*)(const opencascade::handle<StepFEA_CurveElementLocation> &)) &StepFEA_CurveElementInterval::SetFinishPosition, "Set field FinishPosition", py::arg("FinishPosition"));
cls_StepFEA_CurveElementInterval.def("EuAngles", (opencascade::handle<StepBasic_EulerAngles> (StepFEA_CurveElementInterval::*)() const) &StepFEA_CurveElementInterval::EuAngles, "Returns field EuAngles");
cls_StepFEA_CurveElementInterval.def("SetEuAngles", (void (StepFEA_CurveElementInterval::*)(const opencascade::handle<StepBasic_EulerAngles> &)) &StepFEA_CurveElementInterval::SetEuAngles, "Set field EuAngles", py::arg("EuAngles"));
cls_StepFEA_CurveElementInterval.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementInterval::get_type_name, "None");
cls_StepFEA_CurveElementInterval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementInterval::get_type_descriptor, "None");
cls_StepFEA_CurveElementInterval.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementInterval::*)() const) &StepFEA_CurveElementInterval::DynamicType, "None");

// Enums

}