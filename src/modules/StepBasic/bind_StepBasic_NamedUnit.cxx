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
#include <StepBasic_DimensionalExponents.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_NamedUnit(py::module &mod){

py::class_<StepBasic_NamedUnit, opencascade::handle<StepBasic_NamedUnit>, Standard_Transient> cls_StepBasic_NamedUnit(mod, "StepBasic_NamedUnit", "None");

// Constructors
cls_StepBasic_NamedUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_NamedUnit.def("Init", (void (StepBasic_NamedUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &)) &StepBasic_NamedUnit::Init, "None", py::arg("aDimensions"));
cls_StepBasic_NamedUnit.def("SetDimensions", (void (StepBasic_NamedUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &)) &StepBasic_NamedUnit::SetDimensions, "None", py::arg("aDimensions"));
cls_StepBasic_NamedUnit.def("Dimensions", (opencascade::handle<StepBasic_DimensionalExponents> (StepBasic_NamedUnit::*)() const) &StepBasic_NamedUnit::Dimensions, "None");
cls_StepBasic_NamedUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_NamedUnit::get_type_name, "None");
cls_StepBasic_NamedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_NamedUnit::get_type_descriptor, "None");
cls_StepBasic_NamedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_NamedUnit::*)() const) &StepBasic_NamedUnit::DynamicType, "None");

// Enums

}