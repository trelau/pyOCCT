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
#include <StepElement_CurveElementSectionDefinition.hxx>
#include <StepElement_AnalysisItemWithinRepresentation.hxx>
#include <StepFEA_FeaCurveSectionGeometricRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaCurveSectionGeometricRelationship(py::module &mod){

py::class_<StepFEA_FeaCurveSectionGeometricRelationship, opencascade::handle<StepFEA_FeaCurveSectionGeometricRelationship>, Standard_Transient> cls_StepFEA_FeaCurveSectionGeometricRelationship(mod, "StepFEA_FeaCurveSectionGeometricRelationship", "Representation of STEP entity FeaCurveSectionGeometricRelationship");

// Constructors
cls_StepFEA_FeaCurveSectionGeometricRelationship.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaCurveSectionGeometricRelationship.def("Init", (void (StepFEA_FeaCurveSectionGeometricRelationship::*)(const opencascade::handle<StepElement_CurveElementSectionDefinition> &, const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_FeaCurveSectionGeometricRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aSectionRef"), py::arg("aItem"));
cls_StepFEA_FeaCurveSectionGeometricRelationship.def("SectionRef", (opencascade::handle<StepElement_CurveElementSectionDefinition> (StepFEA_FeaCurveSectionGeometricRelationship::*)() const) &StepFEA_FeaCurveSectionGeometricRelationship::SectionRef, "Returns field SectionRef");
cls_StepFEA_FeaCurveSectionGeometricRelationship.def("SetSectionRef", (void (StepFEA_FeaCurveSectionGeometricRelationship::*)(const opencascade::handle<StepElement_CurveElementSectionDefinition> &)) &StepFEA_FeaCurveSectionGeometricRelationship::SetSectionRef, "Set field SectionRef", py::arg("SectionRef"));
cls_StepFEA_FeaCurveSectionGeometricRelationship.def("Item", (opencascade::handle<StepElement_AnalysisItemWithinRepresentation> (StepFEA_FeaCurveSectionGeometricRelationship::*)() const) &StepFEA_FeaCurveSectionGeometricRelationship::Item, "Returns field Item");
cls_StepFEA_FeaCurveSectionGeometricRelationship.def("SetItem", (void (StepFEA_FeaCurveSectionGeometricRelationship::*)(const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_FeaCurveSectionGeometricRelationship::SetItem, "Set field Item", py::arg("Item"));
cls_StepFEA_FeaCurveSectionGeometricRelationship.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaCurveSectionGeometricRelationship::get_type_name, "None");
cls_StepFEA_FeaCurveSectionGeometricRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaCurveSectionGeometricRelationship::get_type_descriptor, "None");
cls_StepFEA_FeaCurveSectionGeometricRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaCurveSectionGeometricRelationship::*)() const) &StepFEA_FeaCurveSectionGeometricRelationship::DynamicType, "None");

// Enums

}