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
#include <StepVisual_HArray1OfFillStyleSelect.hxx>
#include <StepVisual_FillStyleSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_FillAreaStyle.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_FillAreaStyle(py::module &mod){

py::class_<StepVisual_FillAreaStyle, opencascade::handle<StepVisual_FillAreaStyle>, Standard_Transient> cls_StepVisual_FillAreaStyle(mod, "StepVisual_FillAreaStyle", "None");

// Constructors
cls_StepVisual_FillAreaStyle.def(py::init<>());

// Fields

// Methods
cls_StepVisual_FillAreaStyle.def("Init", (void (StepVisual_FillAreaStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfFillStyleSelect> &)) &StepVisual_FillAreaStyle::Init, "None", py::arg("aName"), py::arg("aFillStyles"));
cls_StepVisual_FillAreaStyle.def("SetName", (void (StepVisual_FillAreaStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_FillAreaStyle::SetName, "None", py::arg("aName"));
cls_StepVisual_FillAreaStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_FillAreaStyle::*)() const) &StepVisual_FillAreaStyle::Name, "None");
cls_StepVisual_FillAreaStyle.def("SetFillStyles", (void (StepVisual_FillAreaStyle::*)(const opencascade::handle<StepVisual_HArray1OfFillStyleSelect> &)) &StepVisual_FillAreaStyle::SetFillStyles, "None", py::arg("aFillStyles"));
cls_StepVisual_FillAreaStyle.def("FillStyles", (opencascade::handle<StepVisual_HArray1OfFillStyleSelect> (StepVisual_FillAreaStyle::*)() const) &StepVisual_FillAreaStyle::FillStyles, "None");
cls_StepVisual_FillAreaStyle.def("FillStylesValue", (StepVisual_FillStyleSelect (StepVisual_FillAreaStyle::*)(const Standard_Integer) const) &StepVisual_FillAreaStyle::FillStylesValue, "None", py::arg("num"));
cls_StepVisual_FillAreaStyle.def("NbFillStyles", (Standard_Integer (StepVisual_FillAreaStyle::*)() const) &StepVisual_FillAreaStyle::NbFillStyles, "None");
cls_StepVisual_FillAreaStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_FillAreaStyle::get_type_name, "None");
cls_StepVisual_FillAreaStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_FillAreaStyle::get_type_descriptor, "None");
cls_StepVisual_FillAreaStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_FillAreaStyle::*)() const) &StepVisual_FillAreaStyle::DynamicType, "None");

// Enums

}