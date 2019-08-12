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
#include <StepVisual_SurfaceStyleControlGrid.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_SurfaceStyleControlGrid(py::module &mod){

py::class_<StepVisual_SurfaceStyleControlGrid, opencascade::handle<StepVisual_SurfaceStyleControlGrid>, Standard_Transient> cls_StepVisual_SurfaceStyleControlGrid(mod, "StepVisual_SurfaceStyleControlGrid", "None");

// Constructors
cls_StepVisual_SurfaceStyleControlGrid.def(py::init<>());

// Fields

// Methods
cls_StepVisual_SurfaceStyleControlGrid.def("Init", (void (StepVisual_SurfaceStyleControlGrid::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleControlGrid::Init, "None", py::arg("aStyleOfControlGrid"));
cls_StepVisual_SurfaceStyleControlGrid.def("SetStyleOfControlGrid", (void (StepVisual_SurfaceStyleControlGrid::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleControlGrid::SetStyleOfControlGrid, "None", py::arg("aStyleOfControlGrid"));
cls_StepVisual_SurfaceStyleControlGrid.def("StyleOfControlGrid", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_SurfaceStyleControlGrid::*)() const) &StepVisual_SurfaceStyleControlGrid::StyleOfControlGrid, "None");
cls_StepVisual_SurfaceStyleControlGrid.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleControlGrid::get_type_name, "None");
cls_StepVisual_SurfaceStyleControlGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleControlGrid::get_type_descriptor, "None");
cls_StepVisual_SurfaceStyleControlGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleControlGrid::*)() const) &StepVisual_SurfaceStyleControlGrid::DynamicType, "None");

// Enums

}