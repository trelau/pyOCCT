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
#include <StepElement_SurfaceSection.hxx>
#include <StepElement_AnalysisItemWithinRepresentation.hxx>
#include <StepFEA_FeaSurfaceSectionGeometricRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaSurfaceSectionGeometricRelationship(py::module &mod){

py::class_<StepFEA_FeaSurfaceSectionGeometricRelationship, opencascade::handle<StepFEA_FeaSurfaceSectionGeometricRelationship>, Standard_Transient> cls_StepFEA_FeaSurfaceSectionGeometricRelationship(mod, "StepFEA_FeaSurfaceSectionGeometricRelationship", "Representation of STEP entity FeaSurfaceSectionGeometricRelationship");

// Constructors
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("Init", (void (StepFEA_FeaSurfaceSectionGeometricRelationship::*)(const opencascade::handle<StepElement_SurfaceSection> &, const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_FeaSurfaceSectionGeometricRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aSectionRef"), py::arg("aItem"));
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("SectionRef", (opencascade::handle<StepElement_SurfaceSection> (StepFEA_FeaSurfaceSectionGeometricRelationship::*)() const) &StepFEA_FeaSurfaceSectionGeometricRelationship::SectionRef, "Returns field SectionRef");
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("SetSectionRef", (void (StepFEA_FeaSurfaceSectionGeometricRelationship::*)(const opencascade::handle<StepElement_SurfaceSection> &)) &StepFEA_FeaSurfaceSectionGeometricRelationship::SetSectionRef, "Set field SectionRef", py::arg("SectionRef"));
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("Item", (opencascade::handle<StepElement_AnalysisItemWithinRepresentation> (StepFEA_FeaSurfaceSectionGeometricRelationship::*)() const) &StepFEA_FeaSurfaceSectionGeometricRelationship::Item, "Returns field Item");
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("SetItem", (void (StepFEA_FeaSurfaceSectionGeometricRelationship::*)(const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_FeaSurfaceSectionGeometricRelationship::SetItem, "Set field Item", py::arg("Item"));
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaSurfaceSectionGeometricRelationship::get_type_name, "None");
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaSurfaceSectionGeometricRelationship::get_type_descriptor, "None");
cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaSurfaceSectionGeometricRelationship::*)() const) &StepFEA_FeaSurfaceSectionGeometricRelationship::DynamicType, "None");

// Enums

}