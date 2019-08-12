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
#include <StepBasic_NamedUnit.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnitName.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_DimensionalExponents.hxx>
#include <StepBasic_SiUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_SiUnit(py::module &mod){

py::class_<StepBasic_SiUnit, opencascade::handle<StepBasic_SiUnit>, StepBasic_NamedUnit> cls_StepBasic_SiUnit(mod, "StepBasic_SiUnit", "None");

// Constructors
cls_StepBasic_SiUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_SiUnit.def("Init", (void (StepBasic_SiUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
cls_StepBasic_SiUnit.def("SetPrefix", (void (StepBasic_SiUnit::*)(const StepBasic_SiPrefix)) &StepBasic_SiUnit::SetPrefix, "None", py::arg("aPrefix"));
cls_StepBasic_SiUnit.def("UnSetPrefix", (void (StepBasic_SiUnit::*)()) &StepBasic_SiUnit::UnSetPrefix, "None");
cls_StepBasic_SiUnit.def("Prefix", (StepBasic_SiPrefix (StepBasic_SiUnit::*)() const) &StepBasic_SiUnit::Prefix, "None");
cls_StepBasic_SiUnit.def("HasPrefix", (Standard_Boolean (StepBasic_SiUnit::*)() const) &StepBasic_SiUnit::HasPrefix, "None");
cls_StepBasic_SiUnit.def("SetName", (void (StepBasic_SiUnit::*)(const StepBasic_SiUnitName)) &StepBasic_SiUnit::SetName, "None", py::arg("aName"));
cls_StepBasic_SiUnit.def("Name", (StepBasic_SiUnitName (StepBasic_SiUnit::*)() const) &StepBasic_SiUnit::Name, "None");
cls_StepBasic_SiUnit.def("SetDimensions", (void (StepBasic_SiUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &)) &StepBasic_SiUnit::SetDimensions, "None", py::arg("aDimensions"));
cls_StepBasic_SiUnit.def("Dimensions", (opencascade::handle<StepBasic_DimensionalExponents> (StepBasic_SiUnit::*)() const) &StepBasic_SiUnit::Dimensions, "None");
cls_StepBasic_SiUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnit::get_type_name, "None");
cls_StepBasic_SiUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnit::get_type_descriptor, "None");
cls_StepBasic_SiUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnit::*)() const) &StepBasic_SiUnit::DynamicType, "None");

// Enums

}