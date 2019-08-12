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
#include <Standard_TypeDef.hxx>
#include <StepBasic_Group.hxx>
#include <StepBasic_GroupRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_GroupRelationship(py::module &mod){

py::class_<StepBasic_GroupRelationship, opencascade::handle<StepBasic_GroupRelationship>, Standard_Transient> cls_StepBasic_GroupRelationship(mod, "StepBasic_GroupRelationship", "Representation of STEP entity GroupRelationship");

// Constructors
cls_StepBasic_GroupRelationship.def(py::init<>());

// Fields

// Methods
cls_StepBasic_GroupRelationship.def("Init", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Group> &, const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingGroup"), py::arg("aRelatedGroup"));
cls_StepBasic_GroupRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_GroupRelationship::*)() const) &StepBasic_GroupRelationship::Name, "Returns field Name");
cls_StepBasic_GroupRelationship.def("SetName", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_GroupRelationship::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_GroupRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_GroupRelationship::*)() const) &StepBasic_GroupRelationship::Description, "Returns field Description");
cls_StepBasic_GroupRelationship.def("SetDescription", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_GroupRelationship::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_GroupRelationship.def("HasDescription", (Standard_Boolean (StepBasic_GroupRelationship::*)() const) &StepBasic_GroupRelationship::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_GroupRelationship.def("RelatingGroup", (opencascade::handle<StepBasic_Group> (StepBasic_GroupRelationship::*)() const) &StepBasic_GroupRelationship::RelatingGroup, "Returns field RelatingGroup");
cls_StepBasic_GroupRelationship.def("SetRelatingGroup", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupRelationship::SetRelatingGroup, "Set field RelatingGroup", py::arg("RelatingGroup"));
cls_StepBasic_GroupRelationship.def("RelatedGroup", (opencascade::handle<StepBasic_Group> (StepBasic_GroupRelationship::*)() const) &StepBasic_GroupRelationship::RelatedGroup, "Returns field RelatedGroup");
cls_StepBasic_GroupRelationship.def("SetRelatedGroup", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupRelationship::SetRelatedGroup, "Set field RelatedGroup", py::arg("RelatedGroup"));
cls_StepBasic_GroupRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_GroupRelationship::get_type_name, "None");
cls_StepBasic_GroupRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_GroupRelationship::get_type_descriptor, "None");
cls_StepBasic_GroupRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_GroupRelationship::*)() const) &StepBasic_GroupRelationship::DynamicType, "None");

// Enums

}