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
#include <StepVisual_MarkerSelect.hxx>
#include <StepBasic_SizeSelect.hxx>
#include <StepVisual_Colour.hxx>
#include <StepVisual_PointStyle.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_PointStyle(py::module &mod){

py::class_<StepVisual_PointStyle, opencascade::handle<StepVisual_PointStyle>, Standard_Transient> cls_StepVisual_PointStyle(mod, "StepVisual_PointStyle", "None");

// Constructors
cls_StepVisual_PointStyle.def(py::init<>());

// Fields

// Methods
cls_StepVisual_PointStyle.def("Init", (void (StepVisual_PointStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepVisual_MarkerSelect &, const StepBasic_SizeSelect &, const opencascade::handle<StepVisual_Colour> &)) &StepVisual_PointStyle::Init, "None", py::arg("aName"), py::arg("aMarker"), py::arg("aMarkerSize"), py::arg("aMarkerColour"));
cls_StepVisual_PointStyle.def("SetName", (void (StepVisual_PointStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_PointStyle::SetName, "None", py::arg("aName"));
cls_StepVisual_PointStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_PointStyle::*)() const) &StepVisual_PointStyle::Name, "None");
cls_StepVisual_PointStyle.def("SetMarker", (void (StepVisual_PointStyle::*)(const StepVisual_MarkerSelect &)) &StepVisual_PointStyle::SetMarker, "None", py::arg("aMarker"));
cls_StepVisual_PointStyle.def("Marker", (StepVisual_MarkerSelect (StepVisual_PointStyle::*)() const) &StepVisual_PointStyle::Marker, "None");
cls_StepVisual_PointStyle.def("SetMarkerSize", (void (StepVisual_PointStyle::*)(const StepBasic_SizeSelect &)) &StepVisual_PointStyle::SetMarkerSize, "None", py::arg("aMarkerSize"));
cls_StepVisual_PointStyle.def("MarkerSize", (StepBasic_SizeSelect (StepVisual_PointStyle::*)() const) &StepVisual_PointStyle::MarkerSize, "None");
cls_StepVisual_PointStyle.def("SetMarkerColour", (void (StepVisual_PointStyle::*)(const opencascade::handle<StepVisual_Colour> &)) &StepVisual_PointStyle::SetMarkerColour, "None", py::arg("aMarkerColour"));
cls_StepVisual_PointStyle.def("MarkerColour", (opencascade::handle<StepVisual_Colour> (StepVisual_PointStyle::*)() const) &StepVisual_PointStyle::MarkerColour, "None");
cls_StepVisual_PointStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_PointStyle::get_type_name, "None");
cls_StepVisual_PointStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PointStyle::get_type_descriptor, "None");
cls_StepVisual_PointStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PointStyle::*)() const) &StepVisual_PointStyle::DynamicType, "None");

// Enums

}