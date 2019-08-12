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
#include <StepVisual_SurfaceSide.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_SurfaceSideStyle.hxx>
#include <StepVisual_SurfaceStyleUsage.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_SurfaceStyleUsage(py::module &mod){

py::class_<StepVisual_SurfaceStyleUsage, opencascade::handle<StepVisual_SurfaceStyleUsage>, Standard_Transient> cls_StepVisual_SurfaceStyleUsage(mod, "StepVisual_SurfaceStyleUsage", "None");

// Constructors
cls_StepVisual_SurfaceStyleUsage.def(py::init<>());

// Fields

// Methods
cls_StepVisual_SurfaceStyleUsage.def("Init", (void (StepVisual_SurfaceStyleUsage::*)(const StepVisual_SurfaceSide, const opencascade::handle<StepVisual_SurfaceSideStyle> &)) &StepVisual_SurfaceStyleUsage::Init, "None", py::arg("aSide"), py::arg("aStyle"));
cls_StepVisual_SurfaceStyleUsage.def("SetSide", (void (StepVisual_SurfaceStyleUsage::*)(const StepVisual_SurfaceSide)) &StepVisual_SurfaceStyleUsage::SetSide, "None", py::arg("aSide"));
cls_StepVisual_SurfaceStyleUsage.def("Side", (StepVisual_SurfaceSide (StepVisual_SurfaceStyleUsage::*)() const) &StepVisual_SurfaceStyleUsage::Side, "None");
cls_StepVisual_SurfaceStyleUsage.def("SetStyle", (void (StepVisual_SurfaceStyleUsage::*)(const opencascade::handle<StepVisual_SurfaceSideStyle> &)) &StepVisual_SurfaceStyleUsage::SetStyle, "None", py::arg("aStyle"));
cls_StepVisual_SurfaceStyleUsage.def("Style", (opencascade::handle<StepVisual_SurfaceSideStyle> (StepVisual_SurfaceStyleUsage::*)() const) &StepVisual_SurfaceStyleUsage::Style, "None");
cls_StepVisual_SurfaceStyleUsage.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleUsage::get_type_name, "None");
cls_StepVisual_SurfaceStyleUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleUsage::get_type_descriptor, "None");
cls_StepVisual_SurfaceStyleUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleUsage::*)() const) &StepVisual_SurfaceStyleUsage::DynamicType, "None");

// Enums

}