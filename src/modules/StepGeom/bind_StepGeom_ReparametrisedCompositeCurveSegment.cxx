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
#include <StepGeom_CompositeCurveSegment.hxx>
#include <StepGeom_TransitionCode.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepGeom_Curve.hxx>
#include <StepGeom_ReparametrisedCompositeCurveSegment.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_ReparametrisedCompositeCurveSegment(py::module &mod){

py::class_<StepGeom_ReparametrisedCompositeCurveSegment, opencascade::handle<StepGeom_ReparametrisedCompositeCurveSegment>, StepGeom_CompositeCurveSegment> cls_StepGeom_ReparametrisedCompositeCurveSegment(mod, "StepGeom_ReparametrisedCompositeCurveSegment", "None");

// Constructors
cls_StepGeom_ReparametrisedCompositeCurveSegment.def(py::init<>());

// Fields

// Methods
cls_StepGeom_ReparametrisedCompositeCurveSegment.def("Init", (void (StepGeom_ReparametrisedCompositeCurveSegment::*)(const StepGeom_TransitionCode, const Standard_Boolean, const opencascade::handle<StepGeom_Curve> &, const Standard_Real)) &StepGeom_ReparametrisedCompositeCurveSegment::Init, "None", py::arg("aTransition"), py::arg("aSameSense"), py::arg("aParentCurve"), py::arg("aParamLength"));
cls_StepGeom_ReparametrisedCompositeCurveSegment.def("SetParamLength", (void (StepGeom_ReparametrisedCompositeCurveSegment::*)(const Standard_Real)) &StepGeom_ReparametrisedCompositeCurveSegment::SetParamLength, "None", py::arg("aParamLength"));
cls_StepGeom_ReparametrisedCompositeCurveSegment.def("ParamLength", (Standard_Real (StepGeom_ReparametrisedCompositeCurveSegment::*)() const) &StepGeom_ReparametrisedCompositeCurveSegment::ParamLength, "None");
cls_StepGeom_ReparametrisedCompositeCurveSegment.def_static("get_type_name_", (const char * (*)()) &StepGeom_ReparametrisedCompositeCurveSegment::get_type_name, "None");
cls_StepGeom_ReparametrisedCompositeCurveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_ReparametrisedCompositeCurveSegment::get_type_descriptor, "None");
cls_StepGeom_ReparametrisedCompositeCurveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_ReparametrisedCompositeCurveSegment::*)() const) &StepGeom_ReparametrisedCompositeCurveSegment::DynamicType, "None");

// Enums

}