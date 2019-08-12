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
#include <StepVisual_Invisibility.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_HArray1OfInvisibleItem.hxx>
#include <StepVisual_InvisibilityContext.hxx>
#include <StepVisual_ContextDependentInvisibility.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_ContextDependentInvisibility(py::module &mod){

py::class_<StepVisual_ContextDependentInvisibility, opencascade::handle<StepVisual_ContextDependentInvisibility>, StepVisual_Invisibility> cls_StepVisual_ContextDependentInvisibility(mod, "StepVisual_ContextDependentInvisibility", "None");

// Constructors
cls_StepVisual_ContextDependentInvisibility.def(py::init<>());

// Fields

// Methods
cls_StepVisual_ContextDependentInvisibility.def("Init", (void (StepVisual_ContextDependentInvisibility::*)(const opencascade::handle<StepVisual_HArray1OfInvisibleItem> &, const StepVisual_InvisibilityContext &)) &StepVisual_ContextDependentInvisibility::Init, "None", py::arg("aInvisibleItems"), py::arg("aPresentationContext"));
cls_StepVisual_ContextDependentInvisibility.def("SetPresentationContext", (void (StepVisual_ContextDependentInvisibility::*)(const StepVisual_InvisibilityContext &)) &StepVisual_ContextDependentInvisibility::SetPresentationContext, "None", py::arg("aPresentationContext"));
cls_StepVisual_ContextDependentInvisibility.def("PresentationContext", (StepVisual_InvisibilityContext (StepVisual_ContextDependentInvisibility::*)() const) &StepVisual_ContextDependentInvisibility::PresentationContext, "None");
cls_StepVisual_ContextDependentInvisibility.def_static("get_type_name_", (const char * (*)()) &StepVisual_ContextDependentInvisibility::get_type_name, "None");
cls_StepVisual_ContextDependentInvisibility.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ContextDependentInvisibility::get_type_descriptor, "None");
cls_StepVisual_ContextDependentInvisibility.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ContextDependentInvisibility::*)() const) &StepVisual_ContextDependentInvisibility::DynamicType, "None");

// Enums

}