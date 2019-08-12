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
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_HArray1OfSurfaceStyleElementSelect.hxx>
#include <StepVisual_SurfaceStyleElementSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_SurfaceSideStyle.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_SurfaceSideStyle(py::module &mod){

py::class_<StepVisual_SurfaceSideStyle, opencascade::handle<StepVisual_SurfaceSideStyle>, Standard_Transient> cls_StepVisual_SurfaceSideStyle(mod, "StepVisual_SurfaceSideStyle", "None");

// Constructors
cls_StepVisual_SurfaceSideStyle.def(py::init<>());

// Fields

// Methods
cls_StepVisual_SurfaceSideStyle.def("Init", (void (StepVisual_SurfaceSideStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfSurfaceStyleElementSelect> &)) &StepVisual_SurfaceSideStyle::Init, "None", py::arg("aName"), py::arg("aStyles"));
cls_StepVisual_SurfaceSideStyle.def("SetName", (void (StepVisual_SurfaceSideStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_SurfaceSideStyle::SetName, "None", py::arg("aName"));
cls_StepVisual_SurfaceSideStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_SurfaceSideStyle::*)() const) &StepVisual_SurfaceSideStyle::Name, "None");
cls_StepVisual_SurfaceSideStyle.def("SetStyles", (void (StepVisual_SurfaceSideStyle::*)(const opencascade::handle<StepVisual_HArray1OfSurfaceStyleElementSelect> &)) &StepVisual_SurfaceSideStyle::SetStyles, "None", py::arg("aStyles"));
cls_StepVisual_SurfaceSideStyle.def("Styles", (opencascade::handle<StepVisual_HArray1OfSurfaceStyleElementSelect> (StepVisual_SurfaceSideStyle::*)() const) &StepVisual_SurfaceSideStyle::Styles, "None");
cls_StepVisual_SurfaceSideStyle.def("StylesValue", (StepVisual_SurfaceStyleElementSelect (StepVisual_SurfaceSideStyle::*)(const Standard_Integer) const) &StepVisual_SurfaceSideStyle::StylesValue, "None", py::arg("num"));
cls_StepVisual_SurfaceSideStyle.def("NbStyles", (Standard_Integer (StepVisual_SurfaceSideStyle::*)() const) &StepVisual_SurfaceSideStyle::NbStyles, "None");
cls_StepVisual_SurfaceSideStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceSideStyle::get_type_name, "None");
cls_StepVisual_SurfaceSideStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceSideStyle::get_type_descriptor, "None");
cls_StepVisual_SurfaceSideStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceSideStyle::*)() const) &StepVisual_SurfaceSideStyle::DynamicType, "None");

// Enums

}