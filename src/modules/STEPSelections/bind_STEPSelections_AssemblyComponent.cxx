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
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <STEPSelections_HSequenceOfAssemblyLink.hxx>
#include <STEPSelections_AssemblyComponent.hxx>
#include <Standard_Type.hxx>

void bind_STEPSelections_AssemblyComponent(py::module &mod){

py::class_<STEPSelections_AssemblyComponent, opencascade::handle<STEPSelections_AssemblyComponent>, Standard_Transient> cls_STEPSelections_AssemblyComponent(mod, "STEPSelections_AssemblyComponent", "None");

// Constructors
cls_STEPSelections_AssemblyComponent.def(py::init<>());
cls_STEPSelections_AssemblyComponent.def(py::init<const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<STEPSelections_HSequenceOfAssemblyLink> &>(), py::arg("sdr"), py::arg("list"));

// Fields

// Methods
cls_STEPSelections_AssemblyComponent.def("GetSDR", (opencascade::handle<StepShape_ShapeDefinitionRepresentation> (STEPSelections_AssemblyComponent::*)() const) &STEPSelections_AssemblyComponent::GetSDR, "None");
cls_STEPSelections_AssemblyComponent.def("GetList", (opencascade::handle<STEPSelections_HSequenceOfAssemblyLink> (STEPSelections_AssemblyComponent::*)() const) &STEPSelections_AssemblyComponent::GetList, "None");
cls_STEPSelections_AssemblyComponent.def("SetSDR", (void (STEPSelections_AssemblyComponent::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &)) &STEPSelections_AssemblyComponent::SetSDR, "None", py::arg("sdr"));
cls_STEPSelections_AssemblyComponent.def("SetList", (void (STEPSelections_AssemblyComponent::*)(const opencascade::handle<STEPSelections_HSequenceOfAssemblyLink> &)) &STEPSelections_AssemblyComponent::SetList, "None", py::arg("list"));
cls_STEPSelections_AssemblyComponent.def_static("get_type_name_", (const char * (*)()) &STEPSelections_AssemblyComponent::get_type_name, "None");
cls_STEPSelections_AssemblyComponent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_AssemblyComponent::get_type_descriptor, "None");
cls_STEPSelections_AssemblyComponent.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_AssemblyComponent::*)() const) &STEPSelections_AssemblyComponent::DynamicType, "None");

// Enums

}