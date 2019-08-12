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
#include <StepBasic_NamedUnit.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_DerivedUnitElement.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DerivedUnitElement(py::module &mod){

py::class_<StepBasic_DerivedUnitElement, opencascade::handle<StepBasic_DerivedUnitElement>, Standard_Transient> cls_StepBasic_DerivedUnitElement(mod, "StepBasic_DerivedUnitElement", "Added from StepBasic Rev2 to Rev4");

// Constructors
cls_StepBasic_DerivedUnitElement.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DerivedUnitElement.def("Init", (void (StepBasic_DerivedUnitElement::*)(const opencascade::handle<StepBasic_NamedUnit> &, const Standard_Real)) &StepBasic_DerivedUnitElement::Init, "None", py::arg("aUnit"), py::arg("aExponent"));
cls_StepBasic_DerivedUnitElement.def("SetUnit", (void (StepBasic_DerivedUnitElement::*)(const opencascade::handle<StepBasic_NamedUnit> &)) &StepBasic_DerivedUnitElement::SetUnit, "None", py::arg("aUnit"));
cls_StepBasic_DerivedUnitElement.def("Unit", (opencascade::handle<StepBasic_NamedUnit> (StepBasic_DerivedUnitElement::*)() const) &StepBasic_DerivedUnitElement::Unit, "None");
cls_StepBasic_DerivedUnitElement.def("SetExponent", (void (StepBasic_DerivedUnitElement::*)(const Standard_Real)) &StepBasic_DerivedUnitElement::SetExponent, "None", py::arg("aExponent"));
cls_StepBasic_DerivedUnitElement.def("Exponent", (Standard_Real (StepBasic_DerivedUnitElement::*)() const) &StepBasic_DerivedUnitElement::Exponent, "None");
cls_StepBasic_DerivedUnitElement.def_static("get_type_name_", (const char * (*)()) &StepBasic_DerivedUnitElement::get_type_name, "None");
cls_StepBasic_DerivedUnitElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DerivedUnitElement::get_type_descriptor, "None");
cls_StepBasic_DerivedUnitElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DerivedUnitElement::*)() const) &StepBasic_DerivedUnitElement::DynamicType, "None");

// Enums

}