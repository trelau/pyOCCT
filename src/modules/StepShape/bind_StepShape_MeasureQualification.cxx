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
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepShape_HArray1OfValueQualifier.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_ValueQualifier.hxx>
#include <StepShape_MeasureQualification.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_MeasureQualification(py::module &mod){

py::class_<StepShape_MeasureQualification, opencascade::handle<StepShape_MeasureQualification>, Standard_Transient> cls_StepShape_MeasureQualification(mod, "StepShape_MeasureQualification", "Added for Dimensional Tolerances");

// Constructors
cls_StepShape_MeasureQualification.def(py::init<>());

// Fields

// Methods
cls_StepShape_MeasureQualification.def("Init", (void (StepShape_MeasureQualification::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_MeasureQualification::Init, "None", py::arg("name"), py::arg("description"), py::arg("qualified_measure"), py::arg("qualifiers"));
cls_StepShape_MeasureQualification.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepShape_MeasureQualification::*)() const) &StepShape_MeasureQualification::Name, "None");
cls_StepShape_MeasureQualification.def("SetName", (void (StepShape_MeasureQualification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_MeasureQualification::SetName, "None", py::arg("name"));
cls_StepShape_MeasureQualification.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepShape_MeasureQualification::*)() const) &StepShape_MeasureQualification::Description, "None");
cls_StepShape_MeasureQualification.def("SetDescription", (void (StepShape_MeasureQualification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_MeasureQualification::SetDescription, "None", py::arg("description"));
cls_StepShape_MeasureQualification.def("QualifiedMeasure", (opencascade::handle<StepBasic_MeasureWithUnit> (StepShape_MeasureQualification::*)() const) &StepShape_MeasureQualification::QualifiedMeasure, "None");
cls_StepShape_MeasureQualification.def("SetQualifiedMeasure", (void (StepShape_MeasureQualification::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_MeasureQualification::SetQualifiedMeasure, "None", py::arg("qualified_measure"));
cls_StepShape_MeasureQualification.def("Qualifiers", (opencascade::handle<StepShape_HArray1OfValueQualifier> (StepShape_MeasureQualification::*)() const) &StepShape_MeasureQualification::Qualifiers, "None");
cls_StepShape_MeasureQualification.def("NbQualifiers", (Standard_Integer (StepShape_MeasureQualification::*)() const) &StepShape_MeasureQualification::NbQualifiers, "None");
cls_StepShape_MeasureQualification.def("SetQualifiers", (void (StepShape_MeasureQualification::*)(const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_MeasureQualification::SetQualifiers, "None", py::arg("qualifiers"));
cls_StepShape_MeasureQualification.def("QualifiersValue", (StepShape_ValueQualifier (StepShape_MeasureQualification::*)(const Standard_Integer) const) &StepShape_MeasureQualification::QualifiersValue, "None", py::arg("num"));
cls_StepShape_MeasureQualification.def("SetQualifiersValue", (void (StepShape_MeasureQualification::*)(const Standard_Integer, const StepShape_ValueQualifier &)) &StepShape_MeasureQualification::SetQualifiersValue, "None", py::arg("num"), py::arg("aqualifier"));
cls_StepShape_MeasureQualification.def_static("get_type_name_", (const char * (*)()) &StepShape_MeasureQualification::get_type_name, "None");
cls_StepShape_MeasureQualification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_MeasureQualification::get_type_descriptor, "None");
cls_StepShape_MeasureQualification.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_MeasureQualification::*)() const) &StepShape_MeasureQualification::DynamicType, "None");

// Enums

}