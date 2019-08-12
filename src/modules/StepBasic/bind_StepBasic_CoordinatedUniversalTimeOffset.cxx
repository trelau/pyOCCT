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
#include <Standard_TypeDef.hxx>
#include <StepBasic_AheadOrBehind.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_CoordinatedUniversalTimeOffset.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_CoordinatedUniversalTimeOffset(py::module &mod){

py::class_<StepBasic_CoordinatedUniversalTimeOffset, opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset>, Standard_Transient> cls_StepBasic_CoordinatedUniversalTimeOffset(mod, "StepBasic_CoordinatedUniversalTimeOffset", "None");

// Constructors
cls_StepBasic_CoordinatedUniversalTimeOffset.def(py::init<>());

// Fields

// Methods
cls_StepBasic_CoordinatedUniversalTimeOffset.def("Init", (void (StepBasic_CoordinatedUniversalTimeOffset::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer, const StepBasic_AheadOrBehind)) &StepBasic_CoordinatedUniversalTimeOffset::Init, "None", py::arg("aHourOffset"), py::arg("hasAminuteOffset"), py::arg("aMinuteOffset"), py::arg("aSense"));
cls_StepBasic_CoordinatedUniversalTimeOffset.def("SetHourOffset", (void (StepBasic_CoordinatedUniversalTimeOffset::*)(const Standard_Integer)) &StepBasic_CoordinatedUniversalTimeOffset::SetHourOffset, "None", py::arg("aHourOffset"));
cls_StepBasic_CoordinatedUniversalTimeOffset.def("HourOffset", (Standard_Integer (StepBasic_CoordinatedUniversalTimeOffset::*)() const) &StepBasic_CoordinatedUniversalTimeOffset::HourOffset, "None");
cls_StepBasic_CoordinatedUniversalTimeOffset.def("SetMinuteOffset", (void (StepBasic_CoordinatedUniversalTimeOffset::*)(const Standard_Integer)) &StepBasic_CoordinatedUniversalTimeOffset::SetMinuteOffset, "None", py::arg("aMinuteOffset"));
cls_StepBasic_CoordinatedUniversalTimeOffset.def("UnSetMinuteOffset", (void (StepBasic_CoordinatedUniversalTimeOffset::*)()) &StepBasic_CoordinatedUniversalTimeOffset::UnSetMinuteOffset, "None");
cls_StepBasic_CoordinatedUniversalTimeOffset.def("MinuteOffset", (Standard_Integer (StepBasic_CoordinatedUniversalTimeOffset::*)() const) &StepBasic_CoordinatedUniversalTimeOffset::MinuteOffset, "None");
cls_StepBasic_CoordinatedUniversalTimeOffset.def("HasMinuteOffset", (Standard_Boolean (StepBasic_CoordinatedUniversalTimeOffset::*)() const) &StepBasic_CoordinatedUniversalTimeOffset::HasMinuteOffset, "None");
cls_StepBasic_CoordinatedUniversalTimeOffset.def("SetSense", (void (StepBasic_CoordinatedUniversalTimeOffset::*)(const StepBasic_AheadOrBehind)) &StepBasic_CoordinatedUniversalTimeOffset::SetSense, "None", py::arg("aSense"));
cls_StepBasic_CoordinatedUniversalTimeOffset.def("Sense", (StepBasic_AheadOrBehind (StepBasic_CoordinatedUniversalTimeOffset::*)() const) &StepBasic_CoordinatedUniversalTimeOffset::Sense, "None");
cls_StepBasic_CoordinatedUniversalTimeOffset.def_static("get_type_name_", (const char * (*)()) &StepBasic_CoordinatedUniversalTimeOffset::get_type_name, "None");
cls_StepBasic_CoordinatedUniversalTimeOffset.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_CoordinatedUniversalTimeOffset::get_type_descriptor, "None");
cls_StepBasic_CoordinatedUniversalTimeOffset.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_CoordinatedUniversalTimeOffset::*)() const) &StepBasic_CoordinatedUniversalTimeOffset::DynamicType, "None");

// Enums

}