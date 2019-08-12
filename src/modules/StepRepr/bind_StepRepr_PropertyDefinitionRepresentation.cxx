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
#include <StepRepr_RepresentedDefinition.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_PropertyDefinitionRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_PropertyDefinitionRepresentation(py::module &mod){

py::class_<StepRepr_PropertyDefinitionRepresentation, opencascade::handle<StepRepr_PropertyDefinitionRepresentation>, Standard_Transient> cls_StepRepr_PropertyDefinitionRepresentation(mod, "StepRepr_PropertyDefinitionRepresentation", "Representation of STEP entity PropertyDefinitionRepresentation");

// Constructors
cls_StepRepr_PropertyDefinitionRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepRepr_PropertyDefinitionRepresentation.def("Init", (void (StepRepr_PropertyDefinitionRepresentation::*)(const StepRepr_RepresentedDefinition &, const opencascade::handle<StepRepr_Representation> &)) &StepRepr_PropertyDefinitionRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aDefinition"), py::arg("aUsedRepresentation"));
cls_StepRepr_PropertyDefinitionRepresentation.def("Definition", (StepRepr_RepresentedDefinition (StepRepr_PropertyDefinitionRepresentation::*)() const) &StepRepr_PropertyDefinitionRepresentation::Definition, "Returns field Definition");
cls_StepRepr_PropertyDefinitionRepresentation.def("SetDefinition", (void (StepRepr_PropertyDefinitionRepresentation::*)(const StepRepr_RepresentedDefinition &)) &StepRepr_PropertyDefinitionRepresentation::SetDefinition, "Set field Definition", py::arg("Definition"));
cls_StepRepr_PropertyDefinitionRepresentation.def("UsedRepresentation", (opencascade::handle<StepRepr_Representation> (StepRepr_PropertyDefinitionRepresentation::*)() const) &StepRepr_PropertyDefinitionRepresentation::UsedRepresentation, "Returns field UsedRepresentation");
cls_StepRepr_PropertyDefinitionRepresentation.def("SetUsedRepresentation", (void (StepRepr_PropertyDefinitionRepresentation::*)(const opencascade::handle<StepRepr_Representation> &)) &StepRepr_PropertyDefinitionRepresentation::SetUsedRepresentation, "Set field UsedRepresentation", py::arg("UsedRepresentation"));
cls_StepRepr_PropertyDefinitionRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_PropertyDefinitionRepresentation::get_type_name, "None");
cls_StepRepr_PropertyDefinitionRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_PropertyDefinitionRepresentation::get_type_descriptor, "None");
cls_StepRepr_PropertyDefinitionRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_PropertyDefinitionRepresentation::*)() const) &StepRepr_PropertyDefinitionRepresentation::DynamicType, "None");

// Enums

}