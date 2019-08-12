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
#include <StepRepr_PropertyDefinitionRepresentation.hxx>
#include <StepRepr_RepresentedDefinition.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_DataEnvironment.hxx>
#include <StepRepr_MaterialPropertyRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_MaterialPropertyRepresentation(py::module &mod){

py::class_<StepRepr_MaterialPropertyRepresentation, opencascade::handle<StepRepr_MaterialPropertyRepresentation>, StepRepr_PropertyDefinitionRepresentation> cls_StepRepr_MaterialPropertyRepresentation(mod, "StepRepr_MaterialPropertyRepresentation", "Representation of STEP entity MaterialPropertyRepresentation");

// Constructors
cls_StepRepr_MaterialPropertyRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepRepr_MaterialPropertyRepresentation.def("Init", (void (StepRepr_MaterialPropertyRepresentation::*)(const StepRepr_RepresentedDefinition &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_DataEnvironment> &)) &StepRepr_MaterialPropertyRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aPropertyDefinitionRepresentation_Definition"), py::arg("aPropertyDefinitionRepresentation_UsedRepresentation"), py::arg("aDependentEnvironment"));
cls_StepRepr_MaterialPropertyRepresentation.def("DependentEnvironment", (opencascade::handle<StepRepr_DataEnvironment> (StepRepr_MaterialPropertyRepresentation::*)() const) &StepRepr_MaterialPropertyRepresentation::DependentEnvironment, "Returns field DependentEnvironment");
cls_StepRepr_MaterialPropertyRepresentation.def("SetDependentEnvironment", (void (StepRepr_MaterialPropertyRepresentation::*)(const opencascade::handle<StepRepr_DataEnvironment> &)) &StepRepr_MaterialPropertyRepresentation::SetDependentEnvironment, "Set field DependentEnvironment", py::arg("DependentEnvironment"));
cls_StepRepr_MaterialPropertyRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_MaterialPropertyRepresentation::get_type_name, "None");
cls_StepRepr_MaterialPropertyRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MaterialPropertyRepresentation::get_type_descriptor, "None");
cls_StepRepr_MaterialPropertyRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MaterialPropertyRepresentation::*)() const) &StepRepr_MaterialPropertyRepresentation::DynamicType, "None");

// Enums

}