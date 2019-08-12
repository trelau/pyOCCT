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
#include <StepFEA_ElementRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepFEA_HArray1OfNodeRepresentation.hxx>
#include <StepFEA_FeaModel3d.hxx>
#include <StepElement_Volume3dElementDescriptor.hxx>
#include <StepElement_ElementMaterial.hxx>
#include <StepFEA_Volume3dElementRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_Volume3dElementRepresentation(py::module &mod){

py::class_<StepFEA_Volume3dElementRepresentation, opencascade::handle<StepFEA_Volume3dElementRepresentation>, StepFEA_ElementRepresentation> cls_StepFEA_Volume3dElementRepresentation(mod, "StepFEA_Volume3dElementRepresentation", "Representation of STEP entity Volume3dElementRepresentation");

// Constructors
cls_StepFEA_Volume3dElementRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepFEA_Volume3dElementRepresentation.def("Init", (void (StepFEA_Volume3dElementRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &, const opencascade::handle<StepFEA_FeaModel3d> &, const opencascade::handle<StepElement_Volume3dElementDescriptor> &, const opencascade::handle<StepElement_ElementMaterial> &)) &StepFEA_Volume3dElementRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aElementRepresentation_NodeList"), py::arg("aModelRef"), py::arg("aElementDescriptor"), py::arg("aMaterial"));
cls_StepFEA_Volume3dElementRepresentation.def("ModelRef", (opencascade::handle<StepFEA_FeaModel3d> (StepFEA_Volume3dElementRepresentation::*)() const) &StepFEA_Volume3dElementRepresentation::ModelRef, "Returns field ModelRef");
cls_StepFEA_Volume3dElementRepresentation.def("SetModelRef", (void (StepFEA_Volume3dElementRepresentation::*)(const opencascade::handle<StepFEA_FeaModel3d> &)) &StepFEA_Volume3dElementRepresentation::SetModelRef, "Set field ModelRef", py::arg("ModelRef"));
cls_StepFEA_Volume3dElementRepresentation.def("ElementDescriptor", (opencascade::handle<StepElement_Volume3dElementDescriptor> (StepFEA_Volume3dElementRepresentation::*)() const) &StepFEA_Volume3dElementRepresentation::ElementDescriptor, "Returns field ElementDescriptor");
cls_StepFEA_Volume3dElementRepresentation.def("SetElementDescriptor", (void (StepFEA_Volume3dElementRepresentation::*)(const opencascade::handle<StepElement_Volume3dElementDescriptor> &)) &StepFEA_Volume3dElementRepresentation::SetElementDescriptor, "Set field ElementDescriptor", py::arg("ElementDescriptor"));
cls_StepFEA_Volume3dElementRepresentation.def("Material", (opencascade::handle<StepElement_ElementMaterial> (StepFEA_Volume3dElementRepresentation::*)() const) &StepFEA_Volume3dElementRepresentation::Material, "Returns field Material");
cls_StepFEA_Volume3dElementRepresentation.def("SetMaterial", (void (StepFEA_Volume3dElementRepresentation::*)(const opencascade::handle<StepElement_ElementMaterial> &)) &StepFEA_Volume3dElementRepresentation::SetMaterial, "Set field Material", py::arg("Material"));
cls_StepFEA_Volume3dElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_Volume3dElementRepresentation::get_type_name, "None");
cls_StepFEA_Volume3dElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_Volume3dElementRepresentation::get_type_descriptor, "None");
cls_StepFEA_Volume3dElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_Volume3dElementRepresentation::*)() const) &StepFEA_Volume3dElementRepresentation::DynamicType, "None");

// Enums

}