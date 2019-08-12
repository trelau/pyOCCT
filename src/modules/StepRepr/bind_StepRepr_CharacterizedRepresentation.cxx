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
#include <StepRepr_Representation.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepRepr_CharacterizedRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_CharacterizedRepresentation(py::module &mod){

py::class_<StepRepr_CharacterizedRepresentation, opencascade::handle<StepRepr_CharacterizedRepresentation>, StepRepr_Representation> cls_StepRepr_CharacterizedRepresentation(mod, "StepRepr_CharacterizedRepresentation", "None");

// Constructors
cls_StepRepr_CharacterizedRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepRepr_CharacterizedRepresentation.def("Init", (void (StepRepr_CharacterizedRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &)) &StepRepr_CharacterizedRepresentation::Init, "Returns a CharacterizedRepresentation", py::arg("theName"), py::arg("theDescription"), py::arg("theItems"), py::arg("theContextOfItems"));
cls_StepRepr_CharacterizedRepresentation.def("SetDescription", (void (StepRepr_CharacterizedRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_CharacterizedRepresentation::SetDescription, "None", py::arg("theDescription"));
cls_StepRepr_CharacterizedRepresentation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_CharacterizedRepresentation::*)() const) &StepRepr_CharacterizedRepresentation::Description, "None");
cls_StepRepr_CharacterizedRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_CharacterizedRepresentation::get_type_name, "None");
cls_StepRepr_CharacterizedRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CharacterizedRepresentation::get_type_descriptor, "None");
cls_StepRepr_CharacterizedRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CharacterizedRepresentation::*)() const) &StepRepr_CharacterizedRepresentation::DynamicType, "None");

// Enums

}