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
#include <StepVisual_CurveStyleFontSelect.hxx>
#include <StepBasic_SizeSelect.hxx>
#include <StepVisual_Colour.hxx>
#include <StepVisual_CurveStyle.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CurveStyle(py::module &mod){

py::class_<StepVisual_CurveStyle, opencascade::handle<StepVisual_CurveStyle>, Standard_Transient> cls_StepVisual_CurveStyle(mod, "StepVisual_CurveStyle", "None");

// Constructors
cls_StepVisual_CurveStyle.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CurveStyle.def("Init", (void (StepVisual_CurveStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepVisual_CurveStyleFontSelect &, const StepBasic_SizeSelect &, const opencascade::handle<StepVisual_Colour> &)) &StepVisual_CurveStyle::Init, "None", py::arg("aName"), py::arg("aCurveFont"), py::arg("aCurveWidth"), py::arg("aCurveColour"));
cls_StepVisual_CurveStyle.def("SetName", (void (StepVisual_CurveStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_CurveStyle::SetName, "None", py::arg("aName"));
cls_StepVisual_CurveStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_CurveStyle::*)() const) &StepVisual_CurveStyle::Name, "None");
cls_StepVisual_CurveStyle.def("SetCurveFont", (void (StepVisual_CurveStyle::*)(const StepVisual_CurveStyleFontSelect &)) &StepVisual_CurveStyle::SetCurveFont, "None", py::arg("aCurveFont"));
cls_StepVisual_CurveStyle.def("CurveFont", (StepVisual_CurveStyleFontSelect (StepVisual_CurveStyle::*)() const) &StepVisual_CurveStyle::CurveFont, "None");
cls_StepVisual_CurveStyle.def("SetCurveWidth", (void (StepVisual_CurveStyle::*)(const StepBasic_SizeSelect &)) &StepVisual_CurveStyle::SetCurveWidth, "None", py::arg("aCurveWidth"));
cls_StepVisual_CurveStyle.def("CurveWidth", (StepBasic_SizeSelect (StepVisual_CurveStyle::*)() const) &StepVisual_CurveStyle::CurveWidth, "None");
cls_StepVisual_CurveStyle.def("SetCurveColour", (void (StepVisual_CurveStyle::*)(const opencascade::handle<StepVisual_Colour> &)) &StepVisual_CurveStyle::SetCurveColour, "None", py::arg("aCurveColour"));
cls_StepVisual_CurveStyle.def("CurveColour", (opencascade::handle<StepVisual_Colour> (StepVisual_CurveStyle::*)() const) &StepVisual_CurveStyle::CurveColour, "None");
cls_StepVisual_CurveStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_CurveStyle::get_type_name, "None");
cls_StepVisual_CurveStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CurveStyle::get_type_descriptor, "None");
cls_StepVisual_CurveStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CurveStyle::*)() const) &StepVisual_CurveStyle::DynamicType, "None");

// Enums

}