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
#include <StepBasic_HArray1OfDerivedUnitElement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_DerivedUnitElement.hxx>
#include <StepBasic_DerivedUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DerivedUnit(py::module &mod){

py::class_<StepBasic_DerivedUnit, opencascade::handle<StepBasic_DerivedUnit>, Standard_Transient> cls_StepBasic_DerivedUnit(mod, "StepBasic_DerivedUnit", "Added from StepBasic Rev2 to Rev4");

// Constructors
cls_StepBasic_DerivedUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DerivedUnit.def("Init", (void (StepBasic_DerivedUnit::*)(const opencascade::handle<StepBasic_HArray1OfDerivedUnitElement> &)) &StepBasic_DerivedUnit::Init, "None", py::arg("elements"));
cls_StepBasic_DerivedUnit.def("SetElements", (void (StepBasic_DerivedUnit::*)(const opencascade::handle<StepBasic_HArray1OfDerivedUnitElement> &)) &StepBasic_DerivedUnit::SetElements, "None", py::arg("elements"));
cls_StepBasic_DerivedUnit.def("Elements", (opencascade::handle<StepBasic_HArray1OfDerivedUnitElement> (StepBasic_DerivedUnit::*)() const) &StepBasic_DerivedUnit::Elements, "None");
cls_StepBasic_DerivedUnit.def("NbElements", (Standard_Integer (StepBasic_DerivedUnit::*)() const) &StepBasic_DerivedUnit::NbElements, "None");
cls_StepBasic_DerivedUnit.def("ElementsValue", (opencascade::handle<StepBasic_DerivedUnitElement> (StepBasic_DerivedUnit::*)(const Standard_Integer) const) &StepBasic_DerivedUnit::ElementsValue, "None", py::arg("num"));
cls_StepBasic_DerivedUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_DerivedUnit::get_type_name, "None");
cls_StepBasic_DerivedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DerivedUnit::get_type_descriptor, "None");
cls_StepBasic_DerivedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DerivedUnit::*)() const) &StepBasic_DerivedUnit::DynamicType, "None");

// Enums

}