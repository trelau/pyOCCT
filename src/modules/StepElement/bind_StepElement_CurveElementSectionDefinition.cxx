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
#include <Standard_TypeDef.hxx>
#include <StepElement_CurveElementSectionDefinition.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_CurveElementSectionDefinition(py::module &mod){

py::class_<StepElement_CurveElementSectionDefinition, opencascade::handle<StepElement_CurveElementSectionDefinition>, Standard_Transient> cls_StepElement_CurveElementSectionDefinition(mod, "StepElement_CurveElementSectionDefinition", "Representation of STEP entity CurveElementSectionDefinition");

// Constructors
cls_StepElement_CurveElementSectionDefinition.def(py::init<>());

// Fields

// Methods
cls_StepElement_CurveElementSectionDefinition.def("Init", (void (StepElement_CurveElementSectionDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real)) &StepElement_CurveElementSectionDefinition::Init, "Initialize all fields (own and inherited)", py::arg("aDescription"), py::arg("aSectionAngle"));
cls_StepElement_CurveElementSectionDefinition.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepElement_CurveElementSectionDefinition::*)() const) &StepElement_CurveElementSectionDefinition::Description, "Returns field Description");
cls_StepElement_CurveElementSectionDefinition.def("SetDescription", (void (StepElement_CurveElementSectionDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_CurveElementSectionDefinition::SetDescription, "Set field Description", py::arg("Description"));
cls_StepElement_CurveElementSectionDefinition.def("SectionAngle", (Standard_Real (StepElement_CurveElementSectionDefinition::*)() const) &StepElement_CurveElementSectionDefinition::SectionAngle, "Returns field SectionAngle");
cls_StepElement_CurveElementSectionDefinition.def("SetSectionAngle", (void (StepElement_CurveElementSectionDefinition::*)(const Standard_Real)) &StepElement_CurveElementSectionDefinition::SetSectionAngle, "Set field SectionAngle", py::arg("SectionAngle"));
cls_StepElement_CurveElementSectionDefinition.def_static("get_type_name_", (const char * (*)()) &StepElement_CurveElementSectionDefinition::get_type_name, "None");
cls_StepElement_CurveElementSectionDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_CurveElementSectionDefinition::get_type_descriptor, "None");
cls_StepElement_CurveElementSectionDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_CurveElementSectionDefinition::*)() const) &StepElement_CurveElementSectionDefinition::DynamicType, "None");

// Enums

}