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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_CurveStyleFontPattern.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CurveStyleFontPattern(py::module &mod){

py::class_<StepVisual_CurveStyleFontPattern, opencascade::handle<StepVisual_CurveStyleFontPattern>, Standard_Transient> cls_StepVisual_CurveStyleFontPattern(mod, "StepVisual_CurveStyleFontPattern", "None");

// Constructors
cls_StepVisual_CurveStyleFontPattern.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CurveStyleFontPattern.def("Init", (void (StepVisual_CurveStyleFontPattern::*)(const Standard_Real, const Standard_Real)) &StepVisual_CurveStyleFontPattern::Init, "None", py::arg("aVisibleSegmentLength"), py::arg("aInvisibleSegmentLength"));
cls_StepVisual_CurveStyleFontPattern.def("SetVisibleSegmentLength", (void (StepVisual_CurveStyleFontPattern::*)(const Standard_Real)) &StepVisual_CurveStyleFontPattern::SetVisibleSegmentLength, "None", py::arg("aVisibleSegmentLength"));
cls_StepVisual_CurveStyleFontPattern.def("VisibleSegmentLength", (Standard_Real (StepVisual_CurveStyleFontPattern::*)() const) &StepVisual_CurveStyleFontPattern::VisibleSegmentLength, "None");
cls_StepVisual_CurveStyleFontPattern.def("SetInvisibleSegmentLength", (void (StepVisual_CurveStyleFontPattern::*)(const Standard_Real)) &StepVisual_CurveStyleFontPattern::SetInvisibleSegmentLength, "None", py::arg("aInvisibleSegmentLength"));
cls_StepVisual_CurveStyleFontPattern.def("InvisibleSegmentLength", (Standard_Real (StepVisual_CurveStyleFontPattern::*)() const) &StepVisual_CurveStyleFontPattern::InvisibleSegmentLength, "None");
cls_StepVisual_CurveStyleFontPattern.def_static("get_type_name_", (const char * (*)()) &StepVisual_CurveStyleFontPattern::get_type_name, "None");
cls_StepVisual_CurveStyleFontPattern.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CurveStyleFontPattern::get_type_descriptor, "None");
cls_StepVisual_CurveStyleFontPattern.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CurveStyleFontPattern::*)() const) &StepVisual_CurveStyleFontPattern::DynamicType, "None");

// Enums

}