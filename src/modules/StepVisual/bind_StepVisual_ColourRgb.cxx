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
#include <StepVisual_ColourSpecification.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_ColourRgb.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_ColourRgb(py::module &mod){

py::class_<StepVisual_ColourRgb, opencascade::handle<StepVisual_ColourRgb>, StepVisual_ColourSpecification> cls_StepVisual_ColourRgb(mod, "StepVisual_ColourRgb", "None");

// Constructors
cls_StepVisual_ColourRgb.def(py::init<>());

// Fields

// Methods
cls_StepVisual_ColourRgb.def("Init", (void (StepVisual_ColourRgb::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepVisual_ColourRgb::Init, "None", py::arg("aName"), py::arg("aRed"), py::arg("aGreen"), py::arg("aBlue"));
cls_StepVisual_ColourRgb.def("SetRed", (void (StepVisual_ColourRgb::*)(const Standard_Real)) &StepVisual_ColourRgb::SetRed, "None", py::arg("aRed"));
cls_StepVisual_ColourRgb.def("Red", (Standard_Real (StepVisual_ColourRgb::*)() const) &StepVisual_ColourRgb::Red, "None");
cls_StepVisual_ColourRgb.def("SetGreen", (void (StepVisual_ColourRgb::*)(const Standard_Real)) &StepVisual_ColourRgb::SetGreen, "None", py::arg("aGreen"));
cls_StepVisual_ColourRgb.def("Green", (Standard_Real (StepVisual_ColourRgb::*)() const) &StepVisual_ColourRgb::Green, "None");
cls_StepVisual_ColourRgb.def("SetBlue", (void (StepVisual_ColourRgb::*)(const Standard_Real)) &StepVisual_ColourRgb::SetBlue, "None", py::arg("aBlue"));
cls_StepVisual_ColourRgb.def("Blue", (Standard_Real (StepVisual_ColourRgb::*)() const) &StepVisual_ColourRgb::Blue, "None");
cls_StepVisual_ColourRgb.def_static("get_type_name_", (const char * (*)()) &StepVisual_ColourRgb::get_type_name, "None");
cls_StepVisual_ColourRgb.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ColourRgb::get_type_descriptor, "None");
cls_StepVisual_ColourRgb.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ColourRgb::*)() const) &StepVisual_ColourRgb::DynamicType, "None");

// Enums

}