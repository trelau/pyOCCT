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
#include <StepFEA_FeaGroup.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepFEA_FeaModel.hxx>
#include <StepFEA_HArray1OfNodeRepresentation.hxx>
#include <StepFEA_NodeGroup.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_NodeGroup(py::module &mod){

py::class_<StepFEA_NodeGroup, opencascade::handle<StepFEA_NodeGroup>, StepFEA_FeaGroup> cls_StepFEA_NodeGroup(mod, "StepFEA_NodeGroup", "Representation of STEP entity NodeGroup");

// Constructors
cls_StepFEA_NodeGroup.def(py::init<>());

// Fields

// Methods
cls_StepFEA_NodeGroup.def("Init", (void (StepFEA_NodeGroup::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaModel> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_NodeGroup::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("aGroup_Description"), py::arg("aFeaGroup_ModelRef"), py::arg("aNodes"));
cls_StepFEA_NodeGroup.def("Nodes", (opencascade::handle<StepFEA_HArray1OfNodeRepresentation> (StepFEA_NodeGroup::*)() const) &StepFEA_NodeGroup::Nodes, "Returns field Nodes");
cls_StepFEA_NodeGroup.def("SetNodes", (void (StepFEA_NodeGroup::*)(const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_NodeGroup::SetNodes, "Set field Nodes", py::arg("Nodes"));
cls_StepFEA_NodeGroup.def_static("get_type_name_", (const char * (*)()) &StepFEA_NodeGroup::get_type_name, "None");
cls_StepFEA_NodeGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_NodeGroup::get_type_descriptor, "None");
cls_StepFEA_NodeGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_NodeGroup::*)() const) &StepFEA_NodeGroup::DynamicType, "None");

// Enums

}