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
#include <StepVisual_PresentationSizeAssignmentSelect.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_PlanarBox.hxx>
#include <StepVisual_PresentationSize.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_PresentationSize(py::module &mod){

py::class_<StepVisual_PresentationSize, opencascade::handle<StepVisual_PresentationSize>, Standard_Transient> cls_StepVisual_PresentationSize(mod, "StepVisual_PresentationSize", "None");

// Constructors
cls_StepVisual_PresentationSize.def(py::init<>());

// Fields

// Methods
cls_StepVisual_PresentationSize.def("Init", (void (StepVisual_PresentationSize::*)(const StepVisual_PresentationSizeAssignmentSelect &, const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_PresentationSize::Init, "None", py::arg("aUnit"), py::arg("aSize"));
cls_StepVisual_PresentationSize.def("SetUnit", (void (StepVisual_PresentationSize::*)(const StepVisual_PresentationSizeAssignmentSelect &)) &StepVisual_PresentationSize::SetUnit, "None", py::arg("aUnit"));
cls_StepVisual_PresentationSize.def("Unit", (StepVisual_PresentationSizeAssignmentSelect (StepVisual_PresentationSize::*)() const) &StepVisual_PresentationSize::Unit, "None");
cls_StepVisual_PresentationSize.def("SetSize", (void (StepVisual_PresentationSize::*)(const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_PresentationSize::SetSize, "None", py::arg("aSize"));
cls_StepVisual_PresentationSize.def("Size", (opencascade::handle<StepVisual_PlanarBox> (StepVisual_PresentationSize::*)() const) &StepVisual_PresentationSize::Size, "None");
cls_StepVisual_PresentationSize.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationSize::get_type_name, "None");
cls_StepVisual_PresentationSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationSize::get_type_descriptor, "None");
cls_StepVisual_PresentationSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationSize::*)() const) &StepVisual_PresentationSize::DynamicType, "None");

// Enums

}