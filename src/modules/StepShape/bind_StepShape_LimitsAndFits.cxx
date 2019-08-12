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
#include <StepShape_LimitsAndFits.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_LimitsAndFits(py::module &mod){

py::class_<StepShape_LimitsAndFits, opencascade::handle<StepShape_LimitsAndFits>, Standard_Transient> cls_StepShape_LimitsAndFits(mod, "StepShape_LimitsAndFits", "Added for Dimensional Tolerances");

// Constructors
cls_StepShape_LimitsAndFits.def(py::init<>());

// Fields

// Methods
cls_StepShape_LimitsAndFits.def("Init", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::Init, "None", py::arg("form_variance"), py::arg("zone_variance"), py::arg("grade"), py::arg("source"));
cls_StepShape_LimitsAndFits.def("FormVariance", (opencascade::handle<TCollection_HAsciiString> (StepShape_LimitsAndFits::*)() const) &StepShape_LimitsAndFits::FormVariance, "None");
cls_StepShape_LimitsAndFits.def("SetFormVariance", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::SetFormVariance, "None", py::arg("form_variance"));
cls_StepShape_LimitsAndFits.def("ZoneVariance", (opencascade::handle<TCollection_HAsciiString> (StepShape_LimitsAndFits::*)() const) &StepShape_LimitsAndFits::ZoneVariance, "None");
cls_StepShape_LimitsAndFits.def("SetZoneVariance", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::SetZoneVariance, "None", py::arg("zone_variance"));
cls_StepShape_LimitsAndFits.def("Grade", (opencascade::handle<TCollection_HAsciiString> (StepShape_LimitsAndFits::*)() const) &StepShape_LimitsAndFits::Grade, "None");
cls_StepShape_LimitsAndFits.def("SetGrade", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::SetGrade, "None", py::arg("grade"));
cls_StepShape_LimitsAndFits.def("Source", (opencascade::handle<TCollection_HAsciiString> (StepShape_LimitsAndFits::*)() const) &StepShape_LimitsAndFits::Source, "None");
cls_StepShape_LimitsAndFits.def("SetSource", (void (StepShape_LimitsAndFits::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_LimitsAndFits::SetSource, "None", py::arg("source"));
cls_StepShape_LimitsAndFits.def_static("get_type_name_", (const char * (*)()) &StepShape_LimitsAndFits::get_type_name, "None");
cls_StepShape_LimitsAndFits.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_LimitsAndFits::get_type_descriptor, "None");
cls_StepShape_LimitsAndFits.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_LimitsAndFits::*)() const) &StepShape_LimitsAndFits::DynamicType, "None");

// Enums

}