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
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_Source.hxx>
#include <StepBasic_ProductDefinitionFormationWithSpecifiedSource.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionFormationWithSpecifiedSource(py::module &mod){

py::class_<StepBasic_ProductDefinitionFormationWithSpecifiedSource, opencascade::handle<StepBasic_ProductDefinitionFormationWithSpecifiedSource>, StepBasic_ProductDefinitionFormation> cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource(mod, "StepBasic_ProductDefinitionFormationWithSpecifiedSource", "None");

// Constructors
cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def("Init", (void (StepBasic_ProductDefinitionFormationWithSpecifiedSource::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Product> &, const StepBasic_Source)) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::Init, "None", py::arg("aId"), py::arg("aDescription"), py::arg("aOfProduct"), py::arg("aMakeOrBuy"));
cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def("SetMakeOrBuy", (void (StepBasic_ProductDefinitionFormationWithSpecifiedSource::*)(const StepBasic_Source)) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::SetMakeOrBuy, "None", py::arg("aMakeOrBuy"));
cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def("MakeOrBuy", (StepBasic_Source (StepBasic_ProductDefinitionFormationWithSpecifiedSource::*)() const) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::MakeOrBuy, "None");
cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::get_type_name, "None");
cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionFormationWithSpecifiedSource::*)() const) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::DynamicType, "None");

// Enums

}