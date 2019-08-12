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
#include <StepFEA_FeaModel.hxx>
#include <StepFEA_NodeRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_NodeRepresentation(py::module &mod){

py::class_<StepFEA_NodeRepresentation, opencascade::handle<StepFEA_NodeRepresentation>, StepRepr_Representation> cls_StepFEA_NodeRepresentation(mod, "StepFEA_NodeRepresentation", "Representation of STEP entity NodeRepresentation");

// Constructors
cls_StepFEA_NodeRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepFEA_NodeRepresentation.def("Init", (void (StepFEA_NodeRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepFEA_FeaModel> &)) &StepFEA_NodeRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aModelRef"));
cls_StepFEA_NodeRepresentation.def("ModelRef", (opencascade::handle<StepFEA_FeaModel> (StepFEA_NodeRepresentation::*)() const) &StepFEA_NodeRepresentation::ModelRef, "Returns field ModelRef");
cls_StepFEA_NodeRepresentation.def("SetModelRef", (void (StepFEA_NodeRepresentation::*)(const opencascade::handle<StepFEA_FeaModel> &)) &StepFEA_NodeRepresentation::SetModelRef, "Set field ModelRef", py::arg("ModelRef"));
cls_StepFEA_NodeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_NodeRepresentation::get_type_name, "None");
cls_StepFEA_NodeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_NodeRepresentation::get_type_descriptor, "None");
cls_StepFEA_NodeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_NodeRepresentation::*)() const) &StepFEA_NodeRepresentation::DynamicType, "None");

// Enums

}