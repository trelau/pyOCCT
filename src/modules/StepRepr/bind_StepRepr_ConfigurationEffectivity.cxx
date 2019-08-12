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
#include <StepBasic_ProductDefinitionEffectivity.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepRepr_ConfigurationDesign.hxx>
#include <StepRepr_ConfigurationEffectivity.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ConfigurationEffectivity(py::module &mod){

py::class_<StepRepr_ConfigurationEffectivity, opencascade::handle<StepRepr_ConfigurationEffectivity>, StepBasic_ProductDefinitionEffectivity> cls_StepRepr_ConfigurationEffectivity(mod, "StepRepr_ConfigurationEffectivity", "Representation of STEP entity ConfigurationEffectivity");

// Constructors
cls_StepRepr_ConfigurationEffectivity.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ConfigurationEffectivity.def("Init", (void (StepRepr_ConfigurationEffectivity::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionRelationship> &, const opencascade::handle<StepRepr_ConfigurationDesign> &)) &StepRepr_ConfigurationEffectivity::Init, "Initialize all fields (own and inherited)", py::arg("aEffectivity_Id"), py::arg("aProductDefinitionEffectivity_Usage"), py::arg("aConfiguration"));
cls_StepRepr_ConfigurationEffectivity.def("Configuration", (opencascade::handle<StepRepr_ConfigurationDesign> (StepRepr_ConfigurationEffectivity::*)() const) &StepRepr_ConfigurationEffectivity::Configuration, "Returns field Configuration");
cls_StepRepr_ConfigurationEffectivity.def("SetConfiguration", (void (StepRepr_ConfigurationEffectivity::*)(const opencascade::handle<StepRepr_ConfigurationDesign> &)) &StepRepr_ConfigurationEffectivity::SetConfiguration, "Set field Configuration", py::arg("Configuration"));
cls_StepRepr_ConfigurationEffectivity.def_static("get_type_name_", (const char * (*)()) &StepRepr_ConfigurationEffectivity::get_type_name, "None");
cls_StepRepr_ConfigurationEffectivity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ConfigurationEffectivity::get_type_descriptor, "None");
cls_StepRepr_ConfigurationEffectivity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ConfigurationEffectivity::*)() const) &StepRepr_ConfigurationEffectivity::DynamicType, "None");

// Enums

}