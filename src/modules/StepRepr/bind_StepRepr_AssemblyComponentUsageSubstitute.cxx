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
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_AssemblyComponentUsage.hxx>
#include <StepRepr_AssemblyComponentUsageSubstitute.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_AssemblyComponentUsageSubstitute(py::module &mod){

py::class_<StepRepr_AssemblyComponentUsageSubstitute, opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute>, Standard_Transient> cls_StepRepr_AssemblyComponentUsageSubstitute(mod, "StepRepr_AssemblyComponentUsageSubstitute", "None");

// Constructors
cls_StepRepr_AssemblyComponentUsageSubstitute.def(py::init<>());

// Fields

// Methods
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Init", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &)) &StepRepr_AssemblyComponentUsageSubstitute::Init, "None", py::arg("aName"), py::arg("aDef"), py::arg("aBase"), py::arg("aSubs"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::Name, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("SetName", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_AssemblyComponentUsageSubstitute::SetName, "None", py::arg("aName"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Definition", (opencascade::handle<TCollection_HAsciiString> (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::Definition, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("SetDefinition", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_AssemblyComponentUsageSubstitute::SetDefinition, "None", py::arg("aDef"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Base", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::Base, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("SetBase", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<StepRepr_AssemblyComponentUsage> &)) &StepRepr_AssemblyComponentUsageSubstitute::SetBase, "None", py::arg("aBase"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Substitute", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::Substitute, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("SetSubstitute", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<StepRepr_AssemblyComponentUsage> &)) &StepRepr_AssemblyComponentUsageSubstitute::SetSubstitute, "None", py::arg("aSubstitute"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def_static("get_type_name_", (const char * (*)()) &StepRepr_AssemblyComponentUsageSubstitute::get_type_name, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_AssemblyComponentUsageSubstitute::get_type_descriptor, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::DynamicType, "None");

// Enums

}