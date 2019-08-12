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
#include <StepVisual_HArray1OfCurveStyleFontPattern.hxx>
#include <StepVisual_CurveStyleFontPattern.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_CurveStyleFont.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CurveStyleFont(py::module &mod){

py::class_<StepVisual_CurveStyleFont, opencascade::handle<StepVisual_CurveStyleFont>, Standard_Transient> cls_StepVisual_CurveStyleFont(mod, "StepVisual_CurveStyleFont", "None");

// Constructors
cls_StepVisual_CurveStyleFont.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CurveStyleFont.def("Init", (void (StepVisual_CurveStyleFont::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfCurveStyleFontPattern> &)) &StepVisual_CurveStyleFont::Init, "None", py::arg("aName"), py::arg("aPatternList"));
cls_StepVisual_CurveStyleFont.def("SetName", (void (StepVisual_CurveStyleFont::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_CurveStyleFont::SetName, "None", py::arg("aName"));
cls_StepVisual_CurveStyleFont.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_CurveStyleFont::*)() const) &StepVisual_CurveStyleFont::Name, "None");
cls_StepVisual_CurveStyleFont.def("SetPatternList", (void (StepVisual_CurveStyleFont::*)(const opencascade::handle<StepVisual_HArray1OfCurveStyleFontPattern> &)) &StepVisual_CurveStyleFont::SetPatternList, "None", py::arg("aPatternList"));
cls_StepVisual_CurveStyleFont.def("PatternList", (opencascade::handle<StepVisual_HArray1OfCurveStyleFontPattern> (StepVisual_CurveStyleFont::*)() const) &StepVisual_CurveStyleFont::PatternList, "None");
cls_StepVisual_CurveStyleFont.def("PatternListValue", (opencascade::handle<StepVisual_CurveStyleFontPattern> (StepVisual_CurveStyleFont::*)(const Standard_Integer) const) &StepVisual_CurveStyleFont::PatternListValue, "None", py::arg("num"));
cls_StepVisual_CurveStyleFont.def("NbPatternList", (Standard_Integer (StepVisual_CurveStyleFont::*)() const) &StepVisual_CurveStyleFont::NbPatternList, "None");
cls_StepVisual_CurveStyleFont.def_static("get_type_name_", (const char * (*)()) &StepVisual_CurveStyleFont::get_type_name, "None");
cls_StepVisual_CurveStyleFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CurveStyleFont::get_type_descriptor, "None");
cls_StepVisual_CurveStyleFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CurveStyleFont::*)() const) &StepVisual_CurveStyleFont::DynamicType, "None");

// Enums

}