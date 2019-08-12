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
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <STEPSelections_AssemblyComponent.hxx>
#include <STEPSelections_AssemblyLink.hxx>
#include <Standard_Type.hxx>

void bind_STEPSelections_AssemblyLink(py::module &mod){

py::class_<STEPSelections_AssemblyLink, opencascade::handle<STEPSelections_AssemblyLink>, Standard_Transient> cls_STEPSelections_AssemblyLink(mod, "STEPSelections_AssemblyLink", "None");

// Constructors
cls_STEPSelections_AssemblyLink.def(py::init<>());
cls_STEPSelections_AssemblyLink.def(py::init<const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<STEPSelections_AssemblyComponent> &>(), py::arg("nauo"), py::arg("item"), py::arg("part"));

// Fields

// Methods
cls_STEPSelections_AssemblyLink.def("GetNAUO", (opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> (STEPSelections_AssemblyLink::*)() const) &STEPSelections_AssemblyLink::GetNAUO, "None");
cls_STEPSelections_AssemblyLink.def("GetItem", (opencascade::handle<Standard_Transient> (STEPSelections_AssemblyLink::*)() const) &STEPSelections_AssemblyLink::GetItem, "None");
cls_STEPSelections_AssemblyLink.def("GetComponent", (opencascade::handle<STEPSelections_AssemblyComponent> (STEPSelections_AssemblyLink::*)() const) &STEPSelections_AssemblyLink::GetComponent, "None");
cls_STEPSelections_AssemblyLink.def("SetNAUO", (void (STEPSelections_AssemblyLink::*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &STEPSelections_AssemblyLink::SetNAUO, "None", py::arg("nauo"));
cls_STEPSelections_AssemblyLink.def("SetItem", (void (STEPSelections_AssemblyLink::*)(const opencascade::handle<Standard_Transient> &)) &STEPSelections_AssemblyLink::SetItem, "None", py::arg("item"));
cls_STEPSelections_AssemblyLink.def("SetComponent", (void (STEPSelections_AssemblyLink::*)(const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_AssemblyLink::SetComponent, "None", py::arg("part"));
cls_STEPSelections_AssemblyLink.def_static("get_type_name_", (const char * (*)()) &STEPSelections_AssemblyLink::get_type_name, "None");
cls_STEPSelections_AssemblyLink.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_AssemblyLink::get_type_descriptor, "None");
cls_STEPSelections_AssemblyLink.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_AssemblyLink::*)() const) &STEPSelections_AssemblyLink::DynamicType, "None");

// Enums

}