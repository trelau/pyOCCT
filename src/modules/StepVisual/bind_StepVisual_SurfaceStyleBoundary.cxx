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
#include <StepVisual_SurfaceStyleBoundary.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_SurfaceStyleBoundary(py::module &mod){

py::class_<StepVisual_SurfaceStyleBoundary, opencascade::handle<StepVisual_SurfaceStyleBoundary>, Standard_Transient> cls_StepVisual_SurfaceStyleBoundary(mod, "StepVisual_SurfaceStyleBoundary", "None");

// Constructors
cls_StepVisual_SurfaceStyleBoundary.def(py::init<>());

// Fields

// Methods
cls_StepVisual_SurfaceStyleBoundary.def("Init", (void (StepVisual_SurfaceStyleBoundary::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleBoundary::Init, "None", py::arg("aStyleOfBoundary"));
cls_StepVisual_SurfaceStyleBoundary.def("SetStyleOfBoundary", (void (StepVisual_SurfaceStyleBoundary::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleBoundary::SetStyleOfBoundary, "None", py::arg("aStyleOfBoundary"));
cls_StepVisual_SurfaceStyleBoundary.def("StyleOfBoundary", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_SurfaceStyleBoundary::*)() const) &StepVisual_SurfaceStyleBoundary::StyleOfBoundary, "None");
cls_StepVisual_SurfaceStyleBoundary.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleBoundary::get_type_name, "None");
cls_StepVisual_SurfaceStyleBoundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleBoundary::get_type_descriptor, "None");
cls_StepVisual_SurfaceStyleBoundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleBoundary::*)() const) &StepVisual_SurfaceStyleBoundary::DynamicType, "None");

// Enums

}