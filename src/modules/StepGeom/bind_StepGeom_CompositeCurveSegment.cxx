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
#include <StepGeom_TransitionCode.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepGeom_Curve.hxx>
#include <StepGeom_CompositeCurveSegment.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_CompositeCurveSegment(py::module &mod){

py::class_<StepGeom_CompositeCurveSegment, opencascade::handle<StepGeom_CompositeCurveSegment>, Standard_Transient> cls_StepGeom_CompositeCurveSegment(mod, "StepGeom_CompositeCurveSegment", "None");

// Constructors
cls_StepGeom_CompositeCurveSegment.def(py::init<>());

// Fields

// Methods
cls_StepGeom_CompositeCurveSegment.def("Init", (void (StepGeom_CompositeCurveSegment::*)(const StepGeom_TransitionCode, const Standard_Boolean, const opencascade::handle<StepGeom_Curve> &)) &StepGeom_CompositeCurveSegment::Init, "None", py::arg("aTransition"), py::arg("aSameSense"), py::arg("aParentCurve"));
cls_StepGeom_CompositeCurveSegment.def("SetTransition", (void (StepGeom_CompositeCurveSegment::*)(const StepGeom_TransitionCode)) &StepGeom_CompositeCurveSegment::SetTransition, "None", py::arg("aTransition"));
cls_StepGeom_CompositeCurveSegment.def("Transition", (StepGeom_TransitionCode (StepGeom_CompositeCurveSegment::*)() const) &StepGeom_CompositeCurveSegment::Transition, "None");
cls_StepGeom_CompositeCurveSegment.def("SetSameSense", (void (StepGeom_CompositeCurveSegment::*)(const Standard_Boolean)) &StepGeom_CompositeCurveSegment::SetSameSense, "None", py::arg("aSameSense"));
cls_StepGeom_CompositeCurveSegment.def("SameSense", (Standard_Boolean (StepGeom_CompositeCurveSegment::*)() const) &StepGeom_CompositeCurveSegment::SameSense, "None");
cls_StepGeom_CompositeCurveSegment.def("SetParentCurve", (void (StepGeom_CompositeCurveSegment::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_CompositeCurveSegment::SetParentCurve, "None", py::arg("aParentCurve"));
cls_StepGeom_CompositeCurveSegment.def("ParentCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_CompositeCurveSegment::*)() const) &StepGeom_CompositeCurveSegment::ParentCurve, "None");
cls_StepGeom_CompositeCurveSegment.def_static("get_type_name_", (const char * (*)()) &StepGeom_CompositeCurveSegment::get_type_name, "None");
cls_StepGeom_CompositeCurveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CompositeCurveSegment::get_type_descriptor, "None");
cls_StepGeom_CompositeCurveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CompositeCurveSegment::*)() const) &StepGeom_CompositeCurveSegment::DynamicType, "None");

// Enums

}