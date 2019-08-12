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
#include <StepRepr_Representation.hxx>
#include <StepRepr_RepresentationRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_RepresentationRelationship(py::module &mod){

py::class_<StepRepr_RepresentationRelationship, opencascade::handle<StepRepr_RepresentationRelationship>, Standard_Transient> cls_StepRepr_RepresentationRelationship(mod, "StepRepr_RepresentationRelationship", "None");

// Constructors
cls_StepRepr_RepresentationRelationship.def(py::init<>());

// Fields

// Methods
cls_StepRepr_RepresentationRelationship.def("Init", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationRelationship::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aRep1"), py::arg("aRep2"));
cls_StepRepr_RepresentationRelationship.def("SetName", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationRelationship::SetName, "None", py::arg("aName"));
cls_StepRepr_RepresentationRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::Name, "None");
cls_StepRepr_RepresentationRelationship.def("SetDescription", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationRelationship::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_RepresentationRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::Description, "None");
cls_StepRepr_RepresentationRelationship.def("SetRep1", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationRelationship::SetRep1, "None", py::arg("aRep1"));
cls_StepRepr_RepresentationRelationship.def("Rep1", (opencascade::handle<StepRepr_Representation> (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::Rep1, "None");
cls_StepRepr_RepresentationRelationship.def("SetRep2", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationRelationship::SetRep2, "None", py::arg("aRep2"));
cls_StepRepr_RepresentationRelationship.def("Rep2", (opencascade::handle<StepRepr_Representation> (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::Rep2, "None");
cls_StepRepr_RepresentationRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_RepresentationRelationship::get_type_name, "None");
cls_StepRepr_RepresentationRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_RepresentationRelationship::get_type_descriptor, "None");
cls_StepRepr_RepresentationRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::DynamicType, "None");

// Enums

}