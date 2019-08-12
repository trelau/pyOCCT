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
#include <StepFEA_HArray1OfNodeRepresentation.hxx>
#include <StepFEA_ElementRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_ElementRepresentation(py::module &mod){

py::class_<StepFEA_ElementRepresentation, opencascade::handle<StepFEA_ElementRepresentation>, StepRepr_Representation> cls_StepFEA_ElementRepresentation(mod, "StepFEA_ElementRepresentation", "Representation of STEP entity ElementRepresentation");

// Constructors
cls_StepFEA_ElementRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepFEA_ElementRepresentation.def("Init", (void (StepFEA_ElementRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_ElementRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aNodeList"));
cls_StepFEA_ElementRepresentation.def("NodeList", (opencascade::handle<StepFEA_HArray1OfNodeRepresentation> (StepFEA_ElementRepresentation::*)() const) &StepFEA_ElementRepresentation::NodeList, "Returns field NodeList");
cls_StepFEA_ElementRepresentation.def("SetNodeList", (void (StepFEA_ElementRepresentation::*)(const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_ElementRepresentation::SetNodeList, "Set field NodeList", py::arg("NodeList"));
cls_StepFEA_ElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_ElementRepresentation::get_type_name, "None");
cls_StepFEA_ElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ElementRepresentation::get_type_descriptor, "None");
cls_StepFEA_ElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ElementRepresentation::*)() const) &StepFEA_ElementRepresentation::DynamicType, "None");

// Enums

}