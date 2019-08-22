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
#include <STEPConstruct_Tool.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepFEA_FeaModel.hxx>
#include <StepBasic_Product.hxx>
#include <StepFEA_FeaAxis2Placement3d.hxx>
#include <StepShape_ShapeRepresentation.hxx>
#include <StepElement_HSequenceOfElementMaterial.hxx>
#include <StepFEA_HSequenceOfElementGeometricRelationship.hxx>
#include <StepFEA_HSequenceOfElementRepresentation.hxx>
#include <StepElement_HSequenceOfCurveElementSectionDefinition.hxx>
#include <StepFEA_Curve3dElementRepresentation.hxx>
#include <StepFEA_ElementRepresentation.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepData_StepModel.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <Standard_Type.hxx>
#include <StepAP209_Construct.hxx>

void bind_StepAP209_Construct(py::module &mod){

py::class_<StepAP209_Construct, STEPConstruct_Tool> cls_StepAP209_Construct(mod, "StepAP209_Construct", "Basic tool for working with AP209 model");

// Constructors
cls_StepAP209_Construct.def(py::init<>());
cls_StepAP209_Construct.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Fields

// Methods
// cls_StepAP209_Construct.def_static("operator new_", (void * (*)(size_t)) &StepAP209_Construct::operator new, "None", py::arg("theSize"));
// cls_StepAP209_Construct.def_static("operator delete_", (void (*)(void *)) &StepAP209_Construct::operator delete, "None", py::arg("theAddress"));
// cls_StepAP209_Construct.def_static("operator new[]_", (void * (*)(size_t)) &StepAP209_Construct::operator new[], "None", py::arg("theSize"));
// cls_StepAP209_Construct.def_static("operator delete[]_", (void (*)(void *)) &StepAP209_Construct::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP209_Construct.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP209_Construct::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP209_Construct.def_static("operator delete_", (void (*)(void *, void *)) &StepAP209_Construct::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP209_Construct.def("Init", (Standard_Boolean (StepAP209_Construct::*)(const opencascade::handle<XSControl_WorkSession> &)) &StepAP209_Construct::Init, "Initializes tool; returns True if succeeded", py::arg("WS"));
cls_StepAP209_Construct.def("IsDesing", (Standard_Boolean (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &) const) &StepAP209_Construct::IsDesing, "None", py::arg("PD"));
cls_StepAP209_Construct.def("IsAnalys", (Standard_Boolean (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &) const) &StepAP209_Construct::IsAnalys, "None", py::arg("PD"));
cls_StepAP209_Construct.def("FeaModel", (opencascade::handle<StepFEA_FeaModel> (StepAP209_Construct::*)(const opencascade::handle<StepBasic_Product> &) const) &StepAP209_Construct::FeaModel, "None", py::arg("Prod"));
cls_StepAP209_Construct.def("FeaModel", (opencascade::handle<StepFEA_FeaModel> (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &) const) &StepAP209_Construct::FeaModel, "None", py::arg("PDF"));
cls_StepAP209_Construct.def("GetFeaAxis2Placement3d", (opencascade::handle<StepFEA_FeaAxis2Placement3d> (StepAP209_Construct::*)(const opencascade::handle<StepFEA_FeaModel> &) const) &StepAP209_Construct::GetFeaAxis2Placement3d, "None", py::arg("theFeaModel"));
cls_StepAP209_Construct.def("IdealShape", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepBasic_Product> &) const) &StepAP209_Construct::IdealShape, "None", py::arg("Prod"));
cls_StepAP209_Construct.def("IdealShape", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &) const) &StepAP209_Construct::IdealShape, "None", py::arg("PDF"));
cls_StepAP209_Construct.def("NominShape", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepBasic_Product> &) const) &StepAP209_Construct::NominShape, "None", py::arg("Prod"));
cls_StepAP209_Construct.def("NominShape", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &) const) &StepAP209_Construct::NominShape, "None", py::arg("PDF"));
cls_StepAP209_Construct.def("GetElementMaterial", (opencascade::handle<StepElement_HSequenceOfElementMaterial> (StepAP209_Construct::*)() const) &StepAP209_Construct::GetElementMaterial, "None");
cls_StepAP209_Construct.def("GetElemGeomRelat", (opencascade::handle<StepFEA_HSequenceOfElementGeometricRelationship> (StepAP209_Construct::*)() const) &StepAP209_Construct::GetElemGeomRelat, "None");
cls_StepAP209_Construct.def("GetElements1D", (opencascade::handle<StepFEA_HSequenceOfElementRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepFEA_FeaModel> &) const) &StepAP209_Construct::GetElements1D, "None", py::arg("theFeaModel"));
cls_StepAP209_Construct.def("GetElements2D", (opencascade::handle<StepFEA_HSequenceOfElementRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepFEA_FeaModel> &) const) &StepAP209_Construct::GetElements2D, "None", py::arg("theFEAModel"));
cls_StepAP209_Construct.def("GetElements3D", (opencascade::handle<StepFEA_HSequenceOfElementRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepFEA_FeaModel> &) const) &StepAP209_Construct::GetElements3D, "None", py::arg("theFEAModel"));
cls_StepAP209_Construct.def("GetCurElemSection", (opencascade::handle<StepElement_HSequenceOfCurveElementSectionDefinition> (StepAP209_Construct::*)(const opencascade::handle<StepFEA_Curve3dElementRepresentation> &) const) &StepAP209_Construct::GetCurElemSection, "Getting list of curve_element_section_definitions for given element_representation", py::arg("ElemRepr"));
cls_StepAP209_Construct.def("GetShReprForElem", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepFEA_ElementRepresentation> &) const) &StepAP209_Construct::GetShReprForElem, "None", py::arg("ElemRepr"));
cls_StepAP209_Construct.def("CreateAnalysStructure", (Standard_Boolean (StepAP209_Construct::*)(const opencascade::handle<StepBasic_Product> &) const) &StepAP209_Construct::CreateAnalysStructure, "Create empty structure for idealized_analysis_shape", py::arg("Prod"));
cls_StepAP209_Construct.def("CreateFeaStructure", (Standard_Boolean (StepAP209_Construct::*)(const opencascade::handle<StepBasic_Product> &) const) &StepAP209_Construct::CreateFeaStructure, "Create fea structure", py::arg("Prod"));
cls_StepAP209_Construct.def("ReplaceCcDesingToApplied", (Standard_Boolean (StepAP209_Construct::*)() const) &StepAP209_Construct::ReplaceCcDesingToApplied, "Put into model entities Applied... for AP209 instead of entities CcDesing... from AP203.");
cls_StepAP209_Construct.def("CreateAddingEntities", (Standard_Boolean (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinition> &) const) &StepAP209_Construct::CreateAddingEntities, "Create approval.. , date.. , time.. , person.. and organization.. entities for analysis structure", py::arg("AnaPD"));
cls_StepAP209_Construct.def("CreateAP203Structure", (opencascade::handle<StepData_StepModel> (StepAP209_Construct::*)() const) &StepAP209_Construct::CreateAP203Structure, "Create AP203 structure from existing AP209 structure");
cls_StepAP209_Construct.def("CreateAdding203Entities", (Standard_Boolean (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinition> &, opencascade::handle<StepData_StepModel> &) const) &StepAP209_Construct::CreateAdding203Entities, "Create approval.. , date.. , time.. , person.. and organization.. entities for 203 structure", py::arg("PD"), py::arg("aModel"));
cls_StepAP209_Construct.def("FeaModel", (opencascade::handle<StepFEA_FeaModel> (StepAP209_Construct::*)(const opencascade::handle<StepRepr_ProductDefinitionShape> &) const) &StepAP209_Construct::FeaModel, "None", py::arg("PDS"));
cls_StepAP209_Construct.def("FeaModel", (opencascade::handle<StepFEA_FeaModel> (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinition> &) const) &StepAP209_Construct::FeaModel, "None", py::arg("PD"));
cls_StepAP209_Construct.def("IdealShape", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepBasic_ProductDefinition> &) const) &StepAP209_Construct::IdealShape, "None", py::arg("PD"));
cls_StepAP209_Construct.def("IdealShape", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP209_Construct::*)(const opencascade::handle<StepRepr_ProductDefinitionShape> &) const) &StepAP209_Construct::IdealShape, "None", py::arg("PDS"));

// Enums

}