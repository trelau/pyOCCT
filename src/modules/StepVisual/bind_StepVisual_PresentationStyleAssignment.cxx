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
#include <StepVisual_HArray1OfPresentationStyleSelect.hxx>
#include <StepVisual_PresentationStyleSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_PresentationStyleAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_PresentationStyleAssignment(py::module &mod){

py::class_<StepVisual_PresentationStyleAssignment, opencascade::handle<StepVisual_PresentationStyleAssignment>, Standard_Transient> cls_StepVisual_PresentationStyleAssignment(mod, "StepVisual_PresentationStyleAssignment", "None");

// Constructors
cls_StepVisual_PresentationStyleAssignment.def(py::init<>());

// Fields

// Methods
cls_StepVisual_PresentationStyleAssignment.def("Init", (void (StepVisual_PresentationStyleAssignment::*)(const opencascade::handle<StepVisual_HArray1OfPresentationStyleSelect> &)) &StepVisual_PresentationStyleAssignment::Init, "None", py::arg("aStyles"));
cls_StepVisual_PresentationStyleAssignment.def("SetStyles", (void (StepVisual_PresentationStyleAssignment::*)(const opencascade::handle<StepVisual_HArray1OfPresentationStyleSelect> &)) &StepVisual_PresentationStyleAssignment::SetStyles, "None", py::arg("aStyles"));
cls_StepVisual_PresentationStyleAssignment.def("Styles", (opencascade::handle<StepVisual_HArray1OfPresentationStyleSelect> (StepVisual_PresentationStyleAssignment::*)() const) &StepVisual_PresentationStyleAssignment::Styles, "None");
cls_StepVisual_PresentationStyleAssignment.def("StylesValue", (StepVisual_PresentationStyleSelect (StepVisual_PresentationStyleAssignment::*)(const Standard_Integer) const) &StepVisual_PresentationStyleAssignment::StylesValue, "None", py::arg("num"));
cls_StepVisual_PresentationStyleAssignment.def("NbStyles", (Standard_Integer (StepVisual_PresentationStyleAssignment::*)() const) &StepVisual_PresentationStyleAssignment::NbStyles, "None");
cls_StepVisual_PresentationStyleAssignment.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationStyleAssignment::get_type_name, "None");
cls_StepVisual_PresentationStyleAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationStyleAssignment::get_type_descriptor, "None");
cls_StepVisual_PresentationStyleAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationStyleAssignment::*)() const) &StepVisual_PresentationStyleAssignment::DynamicType, "None");

// Enums

}