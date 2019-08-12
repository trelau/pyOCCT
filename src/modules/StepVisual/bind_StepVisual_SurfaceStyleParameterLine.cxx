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
#include <StepVisual_CurveStyle.hxx>
#include <StepVisual_HArray1OfDirectionCountSelect.hxx>
#include <StepVisual_DirectionCountSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_SurfaceStyleParameterLine.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_SurfaceStyleParameterLine(py::module &mod){

py::class_<StepVisual_SurfaceStyleParameterLine, opencascade::handle<StepVisual_SurfaceStyleParameterLine>, Standard_Transient> cls_StepVisual_SurfaceStyleParameterLine(mod, "StepVisual_SurfaceStyleParameterLine", "None");

// Constructors
cls_StepVisual_SurfaceStyleParameterLine.def(py::init<>());

// Fields

// Methods
cls_StepVisual_SurfaceStyleParameterLine.def("Init", (void (StepVisual_SurfaceStyleParameterLine::*)(const opencascade::handle<StepVisual_CurveStyle> &, const opencascade::handle<StepVisual_HArray1OfDirectionCountSelect> &)) &StepVisual_SurfaceStyleParameterLine::Init, "None", py::arg("aStyleOfParameterLines"), py::arg("aDirectionCounts"));
cls_StepVisual_SurfaceStyleParameterLine.def("SetStyleOfParameterLines", (void (StepVisual_SurfaceStyleParameterLine::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleParameterLine::SetStyleOfParameterLines, "None", py::arg("aStyleOfParameterLines"));
cls_StepVisual_SurfaceStyleParameterLine.def("StyleOfParameterLines", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_SurfaceStyleParameterLine::*)() const) &StepVisual_SurfaceStyleParameterLine::StyleOfParameterLines, "None");
cls_StepVisual_SurfaceStyleParameterLine.def("SetDirectionCounts", (void (StepVisual_SurfaceStyleParameterLine::*)(const opencascade::handle<StepVisual_HArray1OfDirectionCountSelect> &)) &StepVisual_SurfaceStyleParameterLine::SetDirectionCounts, "None", py::arg("aDirectionCounts"));
cls_StepVisual_SurfaceStyleParameterLine.def("DirectionCounts", (opencascade::handle<StepVisual_HArray1OfDirectionCountSelect> (StepVisual_SurfaceStyleParameterLine::*)() const) &StepVisual_SurfaceStyleParameterLine::DirectionCounts, "None");
cls_StepVisual_SurfaceStyleParameterLine.def("DirectionCountsValue", (StepVisual_DirectionCountSelect (StepVisual_SurfaceStyleParameterLine::*)(const Standard_Integer) const) &StepVisual_SurfaceStyleParameterLine::DirectionCountsValue, "None", py::arg("num"));
cls_StepVisual_SurfaceStyleParameterLine.def("NbDirectionCounts", (Standard_Integer (StepVisual_SurfaceStyleParameterLine::*)() const) &StepVisual_SurfaceStyleParameterLine::NbDirectionCounts, "None");
cls_StepVisual_SurfaceStyleParameterLine.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleParameterLine::get_type_name, "None");
cls_StepVisual_SurfaceStyleParameterLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleParameterLine::get_type_descriptor, "None");
cls_StepVisual_SurfaceStyleParameterLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleParameterLine::*)() const) &StepVisual_SurfaceStyleParameterLine::DynamicType, "None");

// Enums

}