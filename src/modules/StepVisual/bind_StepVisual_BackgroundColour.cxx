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
#include <StepVisual_Colour.hxx>
#include <StepVisual_AreaOrView.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_BackgroundColour.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_BackgroundColour(py::module &mod){

py::class_<StepVisual_BackgroundColour, opencascade::handle<StepVisual_BackgroundColour>, StepVisual_Colour> cls_StepVisual_BackgroundColour(mod, "StepVisual_BackgroundColour", "None");

// Constructors
cls_StepVisual_BackgroundColour.def(py::init<>());

// Fields

// Methods
cls_StepVisual_BackgroundColour.def("Init", (void (StepVisual_BackgroundColour::*)(const StepVisual_AreaOrView &)) &StepVisual_BackgroundColour::Init, "None", py::arg("aPresentation"));
cls_StepVisual_BackgroundColour.def("SetPresentation", (void (StepVisual_BackgroundColour::*)(const StepVisual_AreaOrView &)) &StepVisual_BackgroundColour::SetPresentation, "None", py::arg("aPresentation"));
cls_StepVisual_BackgroundColour.def("Presentation", (StepVisual_AreaOrView (StepVisual_BackgroundColour::*)() const) &StepVisual_BackgroundColour::Presentation, "None");
cls_StepVisual_BackgroundColour.def_static("get_type_name_", (const char * (*)()) &StepVisual_BackgroundColour::get_type_name, "None");
cls_StepVisual_BackgroundColour.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_BackgroundColour::get_type_descriptor, "None");
cls_StepVisual_BackgroundColour.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_BackgroundColour::*)() const) &StepVisual_BackgroundColour::DynamicType, "None");

// Enums

}