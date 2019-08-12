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
#include <StepVisual_Colour.hxx>
#include <StepVisual_FillAreaStyleColour.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_FillAreaStyleColour(py::module &mod){

py::class_<StepVisual_FillAreaStyleColour, opencascade::handle<StepVisual_FillAreaStyleColour>, Standard_Transient> cls_StepVisual_FillAreaStyleColour(mod, "StepVisual_FillAreaStyleColour", "None");

// Constructors
cls_StepVisual_FillAreaStyleColour.def(py::init<>());

// Fields

// Methods
cls_StepVisual_FillAreaStyleColour.def("Init", (void (StepVisual_FillAreaStyleColour::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_Colour> &)) &StepVisual_FillAreaStyleColour::Init, "None", py::arg("aName"), py::arg("aFillColour"));
cls_StepVisual_FillAreaStyleColour.def("SetName", (void (StepVisual_FillAreaStyleColour::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_FillAreaStyleColour::SetName, "None", py::arg("aName"));
cls_StepVisual_FillAreaStyleColour.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_FillAreaStyleColour::*)() const) &StepVisual_FillAreaStyleColour::Name, "None");
cls_StepVisual_FillAreaStyleColour.def("SetFillColour", (void (StepVisual_FillAreaStyleColour::*)(const opencascade::handle<StepVisual_Colour> &)) &StepVisual_FillAreaStyleColour::SetFillColour, "None", py::arg("aFillColour"));
cls_StepVisual_FillAreaStyleColour.def("FillColour", (opencascade::handle<StepVisual_Colour> (StepVisual_FillAreaStyleColour::*)() const) &StepVisual_FillAreaStyleColour::FillColour, "None");
cls_StepVisual_FillAreaStyleColour.def_static("get_type_name_", (const char * (*)()) &StepVisual_FillAreaStyleColour::get_type_name, "None");
cls_StepVisual_FillAreaStyleColour.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_FillAreaStyleColour::get_type_descriptor, "None");
cls_StepVisual_FillAreaStyleColour.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_FillAreaStyleColour::*)() const) &StepVisual_FillAreaStyleColour::DynamicType, "None");

// Enums

}