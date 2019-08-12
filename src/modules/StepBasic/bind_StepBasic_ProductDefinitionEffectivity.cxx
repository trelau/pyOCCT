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
#include <StepBasic_Effectivity.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepBasic_ProductDefinitionEffectivity.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionEffectivity(py::module &mod){

py::class_<StepBasic_ProductDefinitionEffectivity, opencascade::handle<StepBasic_ProductDefinitionEffectivity>, StepBasic_Effectivity> cls_StepBasic_ProductDefinitionEffectivity(mod, "StepBasic_ProductDefinitionEffectivity", "None");

// Constructors
cls_StepBasic_ProductDefinitionEffectivity.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionEffectivity.def("Init", (void (StepBasic_ProductDefinitionEffectivity::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionRelationship> &)) &StepBasic_ProductDefinitionEffectivity::Init, "None", py::arg("aId"), py::arg("aUsage"));
cls_StepBasic_ProductDefinitionEffectivity.def("Usage", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepBasic_ProductDefinitionEffectivity::*)() const) &StepBasic_ProductDefinitionEffectivity::Usage, "None");
cls_StepBasic_ProductDefinitionEffectivity.def("SetUsage", (void (StepBasic_ProductDefinitionEffectivity::*)(const opencascade::handle<StepBasic_ProductDefinitionRelationship> &)) &StepBasic_ProductDefinitionEffectivity::SetUsage, "None", py::arg("aUsage"));
cls_StepBasic_ProductDefinitionEffectivity.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionEffectivity::get_type_name, "None");
cls_StepBasic_ProductDefinitionEffectivity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionEffectivity::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionEffectivity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionEffectivity::*)() const) &StepBasic_ProductDefinitionEffectivity::DynamicType, "None");

// Enums

}