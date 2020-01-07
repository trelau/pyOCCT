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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepRepr_AllAroundShapeAspect.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepRepr_RWAllAroundShapeAspect.hxx>
#include <StepRepr_Apex.hxx>
#include <RWStepRepr_RWApex.hxx>
#include <StepRepr_AssemblyComponentUsage.hxx>
#include <RWStepRepr_RWAssemblyComponentUsage.hxx>
#include <StepRepr_AssemblyComponentUsageSubstitute.hxx>
#include <RWStepRepr_RWAssemblyComponentUsageSubstitute.hxx>
#include <StepRepr_BetweenShapeAspect.hxx>
#include <RWStepRepr_RWBetweenShapeAspect.hxx>
#include <StepRepr_CentreOfSymmetry.hxx>
#include <RWStepRepr_RWCentreOfSymmetry.hxx>
#include <StepRepr_CharacterizedRepresentation.hxx>
#include <RWStepRepr_RWCharacterizedRepresentation.hxx>
#include <StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.hxx>
#include <RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.hxx>
#include <StepRepr_CompositeGroupShapeAspect.hxx>
#include <RWStepRepr_RWCompositeGroupShapeAspect.hxx>
#include <StepRepr_CompositeShapeAspect.hxx>
#include <RWStepRepr_RWCompositeShapeAspect.hxx>
#include <StepRepr_CompoundRepresentationItem.hxx>
#include <RWStepRepr_RWCompoundRepresentationItem.hxx>
#include <StepRepr_CompShAspAndDatumFeatAndShAsp.hxx>
#include <RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.hxx>
#include <StepRepr_ConfigurationDesign.hxx>
#include <RWStepRepr_RWConfigurationDesign.hxx>
#include <StepRepr_ConfigurationEffectivity.hxx>
#include <RWStepRepr_RWConfigurationEffectivity.hxx>
#include <StepRepr_ConfigurationItem.hxx>
#include <RWStepRepr_RWConfigurationItem.hxx>
#include <StepRepr_ConstructiveGeometryRepresentation.hxx>
#include <RWStepRepr_RWConstructiveGeometryRepresentation.hxx>
#include <StepRepr_ConstructiveGeometryRepresentationRelationship.hxx>
#include <RWStepRepr_RWConstructiveGeometryRepresentationRelationship.hxx>
#include <StepRepr_ContinuosShapeAspect.hxx>
#include <RWStepRepr_RWContinuosShapeAspect.hxx>
#include <StepRepr_DataEnvironment.hxx>
#include <RWStepRepr_RWDataEnvironment.hxx>
#include <StepRepr_DefinitionalRepresentation.hxx>
#include <RWStepRepr_RWDefinitionalRepresentation.hxx>
#include <StepRepr_DerivedShapeAspect.hxx>
#include <RWStepRepr_RWDerivedShapeAspect.hxx>
#include <StepRepr_DescriptiveRepresentationItem.hxx>
#include <RWStepRepr_RWDescriptiveRepresentationItem.hxx>
#include <StepRepr_Extension.hxx>
#include <RWStepRepr_RWExtension.hxx>
#include <StepRepr_FeatureForDatumTargetRelationship.hxx>
#include <RWStepRepr_RWFeatureForDatumTargetRelationship.hxx>
#include <StepRepr_FunctionallyDefinedTransformation.hxx>
#include <RWStepRepr_RWFunctionallyDefinedTransformation.hxx>
#include <StepRepr_GeometricAlignment.hxx>
#include <RWStepRepr_RWGeometricAlignment.hxx>
#include <StepRepr_GlobalUncertaintyAssignedContext.hxx>
#include <RWStepRepr_RWGlobalUncertaintyAssignedContext.hxx>
#include <StepRepr_GlobalUnitAssignedContext.hxx>
#include <RWStepRepr_RWGlobalUnitAssignedContext.hxx>
#include <StepRepr_IntegerRepresentationItem.hxx>
#include <RWStepRepr_RWIntegerRepresentationItem.hxx>
#include <StepRepr_ItemDefinedTransformation.hxx>
#include <RWStepRepr_RWItemDefinedTransformation.hxx>
#include <StepRepr_MakeFromUsageOption.hxx>
#include <RWStepRepr_RWMakeFromUsageOption.hxx>
#include <StepRepr_MappedItem.hxx>
#include <RWStepRepr_RWMappedItem.hxx>
#include <StepRepr_MaterialDesignation.hxx>
#include <RWStepRepr_RWMaterialDesignation.hxx>
#include <StepRepr_MaterialProperty.hxx>
#include <RWStepRepr_RWMaterialProperty.hxx>
#include <StepRepr_MaterialPropertyRepresentation.hxx>
#include <RWStepRepr_RWMaterialPropertyRepresentation.hxx>
#include <StepRepr_MeasureRepresentationItem.hxx>
#include <RWStepRepr_RWMeasureRepresentationItem.hxx>
#include <StepRepr_ParallelOffset.hxx>
#include <RWStepRepr_RWParallelOffset.hxx>
#include <StepRepr_ParametricRepresentationContext.hxx>
#include <RWStepRepr_RWParametricRepresentationContext.hxx>
#include <StepRepr_PerpendicularTo.hxx>
#include <RWStepRepr_RWPerpendicularTo.hxx>
#include <StepRepr_ProductConcept.hxx>
#include <RWStepRepr_RWProductConcept.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <RWStepRepr_RWProductDefinitionShape.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <RWStepRepr_RWPropertyDefinition.hxx>
#include <StepRepr_PropertyDefinitionRelationship.hxx>
#include <RWStepRepr_RWPropertyDefinitionRelationship.hxx>
#include <StepRepr_PropertyDefinitionRepresentation.hxx>
#include <RWStepRepr_RWPropertyDefinitionRepresentation.hxx>
#include <StepRepr_QuantifiedAssemblyComponentUsage.hxx>
#include <RWStepRepr_RWQuantifiedAssemblyComponentUsage.hxx>
#include <StepRepr_Representation.hxx>
#include <RWStepRepr_RWRepresentation.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <RWStepRepr_RWRepresentationContext.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <RWStepRepr_RWRepresentationItem.hxx>
#include <StepRepr_RepresentationMap.hxx>
#include <RWStepRepr_RWRepresentationMap.hxx>
#include <StepRepr_RepresentationRelationship.hxx>
#include <RWStepRepr_RWRepresentationRelationship.hxx>
#include <StepRepr_RepresentationRelationshipWithTransformation.hxx>
#include <RWStepRepr_RWRepresentationRelationshipWithTransformation.hxx>
#include <StepRepr_ReprItemAndLengthMeasureWithUnit.hxx>
#include <RWStepRepr_RWReprItemAndLengthMeasureWithUnit.hxx>
#include <StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.hxx>
#include <RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.hxx>
#include <StepRepr_ReprItemAndPlaneAngleMeasureWithUnit.hxx>
#include <RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.hxx>
#include <StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI.hxx>
#include <RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <RWStepRepr_RWShapeAspect.hxx>
#include <StepRepr_ShapeAspectDerivingRelationship.hxx>
#include <RWStepRepr_RWShapeAspectDerivingRelationship.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <RWStepRepr_RWShapeAspectRelationship.hxx>
#include <StepRepr_ShapeAspectTransition.hxx>
#include <RWStepRepr_RWShapeAspectTransition.hxx>
#include <StepRepr_ShapeRepresentationRelationshipWithTransformation.hxx>
#include <RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.hxx>
#include <StepRepr_SpecifiedHigherUsageOccurrence.hxx>
#include <RWStepRepr_RWSpecifiedHigherUsageOccurrence.hxx>
#include <StepRepr_StructuralResponseProperty.hxx>
#include <RWStepRepr_RWStructuralResponseProperty.hxx>
#include <StepRepr_StructuralResponsePropertyDefinitionRepresentation.hxx>
#include <RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.hxx>
#include <StepRepr_Tangent.hxx>
#include <RWStepRepr_RWTangent.hxx>
#include <StepRepr_ValueRepresentationItem.hxx>
#include <RWStepRepr_RWValueRepresentationItem.hxx>

PYBIND11_MODULE(RWStepRepr, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepRepr");

// CLASS: RWSTEPREPR_RWALLAROUNDSHAPEASPECT
py::class_<RWStepRepr_RWAllAroundShapeAspect> cls_RWStepRepr_RWAllAroundShapeAspect(mod, "RWStepRepr_RWAllAroundShapeAspect", "Read & Write tool for AllAroundShapeAspect");

// Constructors
cls_RWStepRepr_RWAllAroundShapeAspect.def(py::init<>());

// Methods
// cls_RWStepRepr_RWAllAroundShapeAspect.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWAllAroundShapeAspect::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWAllAroundShapeAspect.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWAllAroundShapeAspect::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWAllAroundShapeAspect.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWAllAroundShapeAspect::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWAllAroundShapeAspect.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWAllAroundShapeAspect::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWAllAroundShapeAspect.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWAllAroundShapeAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWAllAroundShapeAspect.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWAllAroundShapeAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWAllAroundShapeAspect.def("ReadStep", (void (RWStepRepr_RWAllAroundShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_AllAroundShapeAspect> &) const) &RWStepRepr_RWAllAroundShapeAspect::ReadStep, "Reads AllAroundShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWAllAroundShapeAspect.def("WriteStep", (void (RWStepRepr_RWAllAroundShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_AllAroundShapeAspect> &) const) &RWStepRepr_RWAllAroundShapeAspect::WriteStep, "Writes AllAroundShapeAspect", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWAllAroundShapeAspect.def("Share", (void (RWStepRepr_RWAllAroundShapeAspect::*)(const opencascade::handle<StepRepr_AllAroundShapeAspect> &, Interface_EntityIterator &) const) &RWStepRepr_RWAllAroundShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWAPEX
py::class_<RWStepRepr_RWApex> cls_RWStepRepr_RWApex(mod, "RWStepRepr_RWApex", "Read & Write tool for Apex");

// Constructors
cls_RWStepRepr_RWApex.def(py::init<>());

// Methods
// cls_RWStepRepr_RWApex.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWApex::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWApex.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWApex::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWApex.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWApex::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWApex.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWApex::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWApex.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWApex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWApex.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWApex::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWApex.def("ReadStep", (void (RWStepRepr_RWApex::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Apex> &) const) &RWStepRepr_RWApex::ReadStep, "Reads Apex", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWApex.def("WriteStep", (void (RWStepRepr_RWApex::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Apex> &) const) &RWStepRepr_RWApex::WriteStep, "Writes Apex", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWApex.def("Share", (void (RWStepRepr_RWApex::*)(const opencascade::handle<StepRepr_Apex> &, Interface_EntityIterator &) const) &RWStepRepr_RWApex::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWASSEMBLYCOMPONENTUSAGE
py::class_<RWStepRepr_RWAssemblyComponentUsage> cls_RWStepRepr_RWAssemblyComponentUsage(mod, "RWStepRepr_RWAssemblyComponentUsage", "Read & Write tool for AssemblyComponentUsage");

// Constructors
cls_RWStepRepr_RWAssemblyComponentUsage.def(py::init<>());

// Methods
// cls_RWStepRepr_RWAssemblyComponentUsage.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWAssemblyComponentUsage::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWAssemblyComponentUsage.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWAssemblyComponentUsage::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWAssemblyComponentUsage.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWAssemblyComponentUsage::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWAssemblyComponentUsage.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWAssemblyComponentUsage::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWAssemblyComponentUsage.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWAssemblyComponentUsage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWAssemblyComponentUsage.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWAssemblyComponentUsage::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWAssemblyComponentUsage.def("ReadStep", (void (RWStepRepr_RWAssemblyComponentUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &) const) &RWStepRepr_RWAssemblyComponentUsage::ReadStep, "Reads AssemblyComponentUsage", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWAssemblyComponentUsage.def("WriteStep", (void (RWStepRepr_RWAssemblyComponentUsage::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &) const) &RWStepRepr_RWAssemblyComponentUsage::WriteStep, "Writes AssemblyComponentUsage", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWAssemblyComponentUsage.def("Share", (void (RWStepRepr_RWAssemblyComponentUsage::*)(const opencascade::handle<StepRepr_AssemblyComponentUsage> &, Interface_EntityIterator &) const) &RWStepRepr_RWAssemblyComponentUsage::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWASSEMBLYCOMPONENTUSAGESUBSTITUTE
py::class_<RWStepRepr_RWAssemblyComponentUsageSubstitute> cls_RWStepRepr_RWAssemblyComponentUsageSubstitute(mod, "RWStepRepr_RWAssemblyComponentUsageSubstitute", "Read & Write Module for AssemblyComponentUsageSubstitute");

// Constructors
cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def(py::init<>());

// Methods
// cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWAssemblyComponentUsageSubstitute::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWAssemblyComponentUsageSubstitute::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWAssemblyComponentUsageSubstitute::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWAssemblyComponentUsageSubstitute::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWAssemblyComponentUsageSubstitute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWAssemblyComponentUsageSubstitute::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def("ReadStep", (void (RWStepRepr_RWAssemblyComponentUsageSubstitute::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute> &) const) &RWStepRepr_RWAssemblyComponentUsageSubstitute::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def("WriteStep", (void (RWStepRepr_RWAssemblyComponentUsageSubstitute::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute> &) const) &RWStepRepr_RWAssemblyComponentUsageSubstitute::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def("Share", (void (RWStepRepr_RWAssemblyComponentUsageSubstitute::*)(const opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute> &, Interface_EntityIterator &) const) &RWStepRepr_RWAssemblyComponentUsageSubstitute::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWBETWEENSHAPEASPECT
py::class_<RWStepRepr_RWBetweenShapeAspect> cls_RWStepRepr_RWBetweenShapeAspect(mod, "RWStepRepr_RWBetweenShapeAspect", "Read & Write tool for BetweenShapeAspect");

// Constructors
cls_RWStepRepr_RWBetweenShapeAspect.def(py::init<>());

// Methods
// cls_RWStepRepr_RWBetweenShapeAspect.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWBetweenShapeAspect::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWBetweenShapeAspect.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWBetweenShapeAspect::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWBetweenShapeAspect.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWBetweenShapeAspect::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWBetweenShapeAspect.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWBetweenShapeAspect::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWBetweenShapeAspect.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWBetweenShapeAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWBetweenShapeAspect.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWBetweenShapeAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWBetweenShapeAspect.def("ReadStep", (void (RWStepRepr_RWBetweenShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_BetweenShapeAspect> &) const) &RWStepRepr_RWBetweenShapeAspect::ReadStep, "Reads BetweenShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWBetweenShapeAspect.def("WriteStep", (void (RWStepRepr_RWBetweenShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_BetweenShapeAspect> &) const) &RWStepRepr_RWBetweenShapeAspect::WriteStep, "Writes BetweenShapeAspect", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWBetweenShapeAspect.def("Share", (void (RWStepRepr_RWBetweenShapeAspect::*)(const opencascade::handle<StepRepr_BetweenShapeAspect> &, Interface_EntityIterator &) const) &RWStepRepr_RWBetweenShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCENTREOFSYMMETRY
py::class_<RWStepRepr_RWCentreOfSymmetry> cls_RWStepRepr_RWCentreOfSymmetry(mod, "RWStepRepr_RWCentreOfSymmetry", "Read & Write tool for CentreOfSymmetry");

// Constructors
cls_RWStepRepr_RWCentreOfSymmetry.def(py::init<>());

// Methods
// cls_RWStepRepr_RWCentreOfSymmetry.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWCentreOfSymmetry::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWCentreOfSymmetry.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWCentreOfSymmetry::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCentreOfSymmetry.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWCentreOfSymmetry::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWCentreOfSymmetry.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWCentreOfSymmetry::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCentreOfSymmetry.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWCentreOfSymmetry::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWCentreOfSymmetry.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWCentreOfSymmetry::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWCentreOfSymmetry.def("ReadStep", (void (RWStepRepr_RWCentreOfSymmetry::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CentreOfSymmetry> &) const) &RWStepRepr_RWCentreOfSymmetry::ReadStep, "Reads CentreOfSymmetry", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWCentreOfSymmetry.def("WriteStep", (void (RWStepRepr_RWCentreOfSymmetry::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CentreOfSymmetry> &) const) &RWStepRepr_RWCentreOfSymmetry::WriteStep, "Writes CentreOfSymmetry", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWCentreOfSymmetry.def("Share", (void (RWStepRepr_RWCentreOfSymmetry::*)(const opencascade::handle<StepRepr_CentreOfSymmetry> &, Interface_EntityIterator &) const) &RWStepRepr_RWCentreOfSymmetry::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCHARACTERIZEDREPRESENTATION
py::class_<RWStepRepr_RWCharacterizedRepresentation> cls_RWStepRepr_RWCharacterizedRepresentation(mod, "RWStepRepr_RWCharacterizedRepresentation", "Read & Write Module for CharacterizedRepresentation");

// Constructors
cls_RWStepRepr_RWCharacterizedRepresentation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWCharacterizedRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWCharacterizedRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWCharacterizedRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWCharacterizedRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCharacterizedRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWCharacterizedRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWCharacterizedRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWCharacterizedRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCharacterizedRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWCharacterizedRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWCharacterizedRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWCharacterizedRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWCharacterizedRepresentation.def("ReadStep", (void (RWStepRepr_RWCharacterizedRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CharacterizedRepresentation> &) const) &RWStepRepr_RWCharacterizedRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWCharacterizedRepresentation.def("WriteStep", (void (RWStepRepr_RWCharacterizedRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CharacterizedRepresentation> &) const) &RWStepRepr_RWCharacterizedRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWCharacterizedRepresentation.def("Share", (void (RWStepRepr_RWCharacterizedRepresentation::*)(const opencascade::handle<StepRepr_CharacterizedRepresentation> &, Interface_EntityIterator &) const) &RWStepRepr_RWCharacterizedRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCOMPGROUPSHASPANDCOMPSHASPANDDATUMFEATANDSHASP
py::class_<RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp> cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp(mod, "RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp", "Read & Write Module for CompGroupShAspAndCompShAspAndDatumFeatAndShAsp");

// Constructors
cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def(py::init<>());

// Methods
// cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def("ReadStep", (void (RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp> &) const) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def("WriteStep", (void (RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp> &) const) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def("Share", (void (RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::*)(const opencascade::handle<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp> &, Interface_EntityIterator &) const) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCOMPOSITEGROUPSHAPEASPECT
py::class_<RWStepRepr_RWCompositeGroupShapeAspect> cls_RWStepRepr_RWCompositeGroupShapeAspect(mod, "RWStepRepr_RWCompositeGroupShapeAspect", "Read & Write tool for CompositeGroupShapeAspect");

// Constructors
cls_RWStepRepr_RWCompositeGroupShapeAspect.def(py::init<>());

// Methods
// cls_RWStepRepr_RWCompositeGroupShapeAspect.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWCompositeGroupShapeAspect::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompositeGroupShapeAspect.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWCompositeGroupShapeAspect::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompositeGroupShapeAspect.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWCompositeGroupShapeAspect::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompositeGroupShapeAspect.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWCompositeGroupShapeAspect::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompositeGroupShapeAspect.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWCompositeGroupShapeAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWCompositeGroupShapeAspect.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWCompositeGroupShapeAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWCompositeGroupShapeAspect.def("ReadStep", (void (RWStepRepr_RWCompositeGroupShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompositeGroupShapeAspect> &) const) &RWStepRepr_RWCompositeGroupShapeAspect::ReadStep, "Reads CompositeGroupShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWCompositeGroupShapeAspect.def("WriteStep", (void (RWStepRepr_RWCompositeGroupShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompositeGroupShapeAspect> &) const) &RWStepRepr_RWCompositeGroupShapeAspect::WriteStep, "Writes CompositeGroupShapeAspect", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWCompositeGroupShapeAspect.def("Share", (void (RWStepRepr_RWCompositeGroupShapeAspect::*)(const opencascade::handle<StepRepr_CompositeGroupShapeAspect> &, Interface_EntityIterator &) const) &RWStepRepr_RWCompositeGroupShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCOMPOSITESHAPEASPECT
py::class_<RWStepRepr_RWCompositeShapeAspect> cls_RWStepRepr_RWCompositeShapeAspect(mod, "RWStepRepr_RWCompositeShapeAspect", "Read & Write tool for CompositeShapeAspect");

// Constructors
cls_RWStepRepr_RWCompositeShapeAspect.def(py::init<>());

// Methods
// cls_RWStepRepr_RWCompositeShapeAspect.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWCompositeShapeAspect::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompositeShapeAspect.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWCompositeShapeAspect::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompositeShapeAspect.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWCompositeShapeAspect::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompositeShapeAspect.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWCompositeShapeAspect::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompositeShapeAspect.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWCompositeShapeAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWCompositeShapeAspect.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWCompositeShapeAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWCompositeShapeAspect.def("ReadStep", (void (RWStepRepr_RWCompositeShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompositeShapeAspect> &) const) &RWStepRepr_RWCompositeShapeAspect::ReadStep, "Reads CompositeShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWCompositeShapeAspect.def("WriteStep", (void (RWStepRepr_RWCompositeShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompositeShapeAspect> &) const) &RWStepRepr_RWCompositeShapeAspect::WriteStep, "Writes CompositeShapeAspect", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWCompositeShapeAspect.def("Share", (void (RWStepRepr_RWCompositeShapeAspect::*)(const opencascade::handle<StepRepr_CompositeShapeAspect> &, Interface_EntityIterator &) const) &RWStepRepr_RWCompositeShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCOMPOUNDREPRESENTATIONITEM
py::class_<RWStepRepr_RWCompoundRepresentationItem> cls_RWStepRepr_RWCompoundRepresentationItem(mod, "RWStepRepr_RWCompoundRepresentationItem", "Read & Write Module for CompoundRepresentationItem");

// Constructors
cls_RWStepRepr_RWCompoundRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepRepr_RWCompoundRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWCompoundRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompoundRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWCompoundRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompoundRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWCompoundRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompoundRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWCompoundRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompoundRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWCompoundRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWCompoundRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWCompoundRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWCompoundRepresentationItem.def("ReadStep", (void (RWStepRepr_RWCompoundRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompoundRepresentationItem> &) const) &RWStepRepr_RWCompoundRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWCompoundRepresentationItem.def("WriteStep", (void (RWStepRepr_RWCompoundRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompoundRepresentationItem> &) const) &RWStepRepr_RWCompoundRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWCompoundRepresentationItem.def("Share", (void (RWStepRepr_RWCompoundRepresentationItem::*)(const opencascade::handle<StepRepr_CompoundRepresentationItem> &, Interface_EntityIterator &) const) &RWStepRepr_RWCompoundRepresentationItem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCOMPSHASPANDDATUMFEATANDSHASP
py::class_<RWStepRepr_RWCompShAspAndDatumFeatAndShAsp> cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp(mod, "RWStepRepr_RWCompShAspAndDatumFeatAndShAsp", "Read & Write Module for CompShAspAndDatumFeatAndShAsp");

// Constructors
cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def(py::init<>());

// Methods
// cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def("ReadStep", (void (RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompShAspAndDatumFeatAndShAsp> &) const) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def("WriteStep", (void (RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompShAspAndDatumFeatAndShAsp> &) const) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def("Share", (void (RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::*)(const opencascade::handle<StepRepr_CompShAspAndDatumFeatAndShAsp> &, Interface_EntityIterator &) const) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCONFIGURATIONDESIGN
py::class_<RWStepRepr_RWConfigurationDesign> cls_RWStepRepr_RWConfigurationDesign(mod, "RWStepRepr_RWConfigurationDesign", "Read & Write tool for ConfigurationDesign");

// Constructors
cls_RWStepRepr_RWConfigurationDesign.def(py::init<>());

// Methods
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationDesign::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWConfigurationDesign::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationDesign::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWConfigurationDesign::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWConfigurationDesign::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWConfigurationDesign::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWConfigurationDesign.def("ReadStep", (void (RWStepRepr_RWConfigurationDesign::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConfigurationDesign> &) const) &RWStepRepr_RWConfigurationDesign::ReadStep, "Reads ConfigurationDesign", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationDesign.def("WriteStep", (void (RWStepRepr_RWConfigurationDesign::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConfigurationDesign> &) const) &RWStepRepr_RWConfigurationDesign::WriteStep, "Writes ConfigurationDesign", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationDesign.def("Share", (void (RWStepRepr_RWConfigurationDesign::*)(const opencascade::handle<StepRepr_ConfigurationDesign> &, Interface_EntityIterator &) const) &RWStepRepr_RWConfigurationDesign::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCONFIGURATIONEFFECTIVITY
py::class_<RWStepRepr_RWConfigurationEffectivity> cls_RWStepRepr_RWConfigurationEffectivity(mod, "RWStepRepr_RWConfigurationEffectivity", "Read & Write tool for ConfigurationEffectivity");

// Constructors
cls_RWStepRepr_RWConfigurationEffectivity.def(py::init<>());

// Methods
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationEffectivity::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWConfigurationEffectivity::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationEffectivity::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWConfigurationEffectivity::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWConfigurationEffectivity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWConfigurationEffectivity::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWConfigurationEffectivity.def("ReadStep", (void (RWStepRepr_RWConfigurationEffectivity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConfigurationEffectivity> &) const) &RWStepRepr_RWConfigurationEffectivity::ReadStep, "Reads ConfigurationEffectivity", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationEffectivity.def("WriteStep", (void (RWStepRepr_RWConfigurationEffectivity::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConfigurationEffectivity> &) const) &RWStepRepr_RWConfigurationEffectivity::WriteStep, "Writes ConfigurationEffectivity", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationEffectivity.def("Share", (void (RWStepRepr_RWConfigurationEffectivity::*)(const opencascade::handle<StepRepr_ConfigurationEffectivity> &, Interface_EntityIterator &) const) &RWStepRepr_RWConfigurationEffectivity::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCONFIGURATIONITEM
py::class_<RWStepRepr_RWConfigurationItem> cls_RWStepRepr_RWConfigurationItem(mod, "RWStepRepr_RWConfigurationItem", "Read & Write tool for ConfigurationItem");

// Constructors
cls_RWStepRepr_RWConfigurationItem.def(py::init<>());

// Methods
// cls_RWStepRepr_RWConfigurationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationItem.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWConfigurationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWConfigurationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWConfigurationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWConfigurationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWConfigurationItem.def("ReadStep", (void (RWStepRepr_RWConfigurationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConfigurationItem> &) const) &RWStepRepr_RWConfigurationItem::ReadStep, "Reads ConfigurationItem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationItem.def("WriteStep", (void (RWStepRepr_RWConfigurationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConfigurationItem> &) const) &RWStepRepr_RWConfigurationItem::WriteStep, "Writes ConfigurationItem", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationItem.def("Share", (void (RWStepRepr_RWConfigurationItem::*)(const opencascade::handle<StepRepr_ConfigurationItem> &, Interface_EntityIterator &) const) &RWStepRepr_RWConfigurationItem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCONSTRUCTIVEGEOMETRYREPRESENTATION
py::class_<RWStepRepr_RWConstructiveGeometryRepresentation> cls_RWStepRepr_RWConstructiveGeometryRepresentation(mod, "RWStepRepr_RWConstructiveGeometryRepresentation", "Read & Write Module for ConstructiveGeometryRepresentation");

// Constructors
cls_RWStepRepr_RWConstructiveGeometryRepresentation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWConstructiveGeometryRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWConstructiveGeometryRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWConstructiveGeometryRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWConstructiveGeometryRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWConstructiveGeometryRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWConstructiveGeometryRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWConstructiveGeometryRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWConstructiveGeometryRepresentation.def("ReadStep", (void (RWStepRepr_RWConstructiveGeometryRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConstructiveGeometryRepresentation> &) const) &RWStepRepr_RWConstructiveGeometryRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWConstructiveGeometryRepresentation.def("WriteStep", (void (RWStepRepr_RWConstructiveGeometryRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConstructiveGeometryRepresentation> &) const) &RWStepRepr_RWConstructiveGeometryRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWConstructiveGeometryRepresentation.def("Share", (void (RWStepRepr_RWConstructiveGeometryRepresentation::*)(const opencascade::handle<StepRepr_ConstructiveGeometryRepresentation> &, Interface_EntityIterator &) const) &RWStepRepr_RWConstructiveGeometryRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCONSTRUCTIVEGEOMETRYREPRESENTATIONRELATIONSHIP
py::class_<RWStepRepr_RWConstructiveGeometryRepresentationRelationship> cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship(mod, "RWStepRepr_RWConstructiveGeometryRepresentationRelationship", "Read & Write Module for ConstructiveGeometryRepresentationRelationship");

// Constructors
cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def(py::init<>());

// Methods
// cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def("ReadStep", (void (RWStepRepr_RWConstructiveGeometryRepresentationRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConstructiveGeometryRepresentationRelationship> &) const) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def("WriteStep", (void (RWStepRepr_RWConstructiveGeometryRepresentationRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConstructiveGeometryRepresentationRelationship> &) const) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def("Share", (void (RWStepRepr_RWConstructiveGeometryRepresentationRelationship::*)(const opencascade::handle<StepRepr_ConstructiveGeometryRepresentationRelationship> &, Interface_EntityIterator &) const) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWCONTINUOSSHAPEASPECT
py::class_<RWStepRepr_RWContinuosShapeAspect> cls_RWStepRepr_RWContinuosShapeAspect(mod, "RWStepRepr_RWContinuosShapeAspect", "Read & Write tool for ContinuosShapeAspect");

// Constructors
cls_RWStepRepr_RWContinuosShapeAspect.def(py::init<>());

// Methods
// cls_RWStepRepr_RWContinuosShapeAspect.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWContinuosShapeAspect::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWContinuosShapeAspect.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWContinuosShapeAspect::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWContinuosShapeAspect.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWContinuosShapeAspect::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWContinuosShapeAspect.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWContinuosShapeAspect::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWContinuosShapeAspect.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWContinuosShapeAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWContinuosShapeAspect.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWContinuosShapeAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWContinuosShapeAspect.def("ReadStep", (void (RWStepRepr_RWContinuosShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ContinuosShapeAspect> &) const) &RWStepRepr_RWContinuosShapeAspect::ReadStep, "Reads ContinuosShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWContinuosShapeAspect.def("WriteStep", (void (RWStepRepr_RWContinuosShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ContinuosShapeAspect> &) const) &RWStepRepr_RWContinuosShapeAspect::WriteStep, "Writes ContinuosShapeAspect", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWContinuosShapeAspect.def("Share", (void (RWStepRepr_RWContinuosShapeAspect::*)(const opencascade::handle<StepRepr_ContinuosShapeAspect> &, Interface_EntityIterator &) const) &RWStepRepr_RWContinuosShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWDATAENVIRONMENT
py::class_<RWStepRepr_RWDataEnvironment> cls_RWStepRepr_RWDataEnvironment(mod, "RWStepRepr_RWDataEnvironment", "Read & Write tool for DataEnvironment");

// Constructors
cls_RWStepRepr_RWDataEnvironment.def(py::init<>());

// Methods
// cls_RWStepRepr_RWDataEnvironment.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWDataEnvironment::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWDataEnvironment.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWDataEnvironment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWDataEnvironment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWDataEnvironment::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWDataEnvironment.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWDataEnvironment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWDataEnvironment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWDataEnvironment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWDataEnvironment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWDataEnvironment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWDataEnvironment.def("ReadStep", (void (RWStepRepr_RWDataEnvironment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_DataEnvironment> &) const) &RWStepRepr_RWDataEnvironment::ReadStep, "Reads DataEnvironment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWDataEnvironment.def("WriteStep", (void (RWStepRepr_RWDataEnvironment::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_DataEnvironment> &) const) &RWStepRepr_RWDataEnvironment::WriteStep, "Writes DataEnvironment", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWDataEnvironment.def("Share", (void (RWStepRepr_RWDataEnvironment::*)(const opencascade::handle<StepRepr_DataEnvironment> &, Interface_EntityIterator &) const) &RWStepRepr_RWDataEnvironment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWDEFINITIONALREPRESENTATION
py::class_<RWStepRepr_RWDefinitionalRepresentation> cls_RWStepRepr_RWDefinitionalRepresentation(mod, "RWStepRepr_RWDefinitionalRepresentation", "Read & Write Module for DefinitionalRepresentation");

// Constructors
cls_RWStepRepr_RWDefinitionalRepresentation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWDefinitionalRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWDefinitionalRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWDefinitionalRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWDefinitionalRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWDefinitionalRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWDefinitionalRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWDefinitionalRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWDefinitionalRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWDefinitionalRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWDefinitionalRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWDefinitionalRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWDefinitionalRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWDefinitionalRepresentation.def("ReadStep", (void (RWStepRepr_RWDefinitionalRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &) const) &RWStepRepr_RWDefinitionalRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWDefinitionalRepresentation.def("WriteStep", (void (RWStepRepr_RWDefinitionalRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &) const) &RWStepRepr_RWDefinitionalRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWDefinitionalRepresentation.def("Share", (void (RWStepRepr_RWDefinitionalRepresentation::*)(const opencascade::handle<StepRepr_DefinitionalRepresentation> &, Interface_EntityIterator &) const) &RWStepRepr_RWDefinitionalRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWDERIVEDSHAPEASPECT
py::class_<RWStepRepr_RWDerivedShapeAspect> cls_RWStepRepr_RWDerivedShapeAspect(mod, "RWStepRepr_RWDerivedShapeAspect", "Read & Write tool for DerivedShapeAspect");

// Constructors
cls_RWStepRepr_RWDerivedShapeAspect.def(py::init<>());

// Methods
// cls_RWStepRepr_RWDerivedShapeAspect.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWDerivedShapeAspect::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWDerivedShapeAspect.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWDerivedShapeAspect::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWDerivedShapeAspect.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWDerivedShapeAspect::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWDerivedShapeAspect.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWDerivedShapeAspect::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWDerivedShapeAspect.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWDerivedShapeAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWDerivedShapeAspect.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWDerivedShapeAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWDerivedShapeAspect.def("ReadStep", (void (RWStepRepr_RWDerivedShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_DerivedShapeAspect> &) const) &RWStepRepr_RWDerivedShapeAspect::ReadStep, "Reads DerivedShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWDerivedShapeAspect.def("WriteStep", (void (RWStepRepr_RWDerivedShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_DerivedShapeAspect> &) const) &RWStepRepr_RWDerivedShapeAspect::WriteStep, "Writes DerivedShapeAspect", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWDerivedShapeAspect.def("Share", (void (RWStepRepr_RWDerivedShapeAspect::*)(const opencascade::handle<StepRepr_DerivedShapeAspect> &, Interface_EntityIterator &) const) &RWStepRepr_RWDerivedShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWDESCRIPTIVEREPRESENTATIONITEM
py::class_<RWStepRepr_RWDescriptiveRepresentationItem> cls_RWStepRepr_RWDescriptiveRepresentationItem(mod, "RWStepRepr_RWDescriptiveRepresentationItem", "Read & Write Module for DescriptiveRepresentationItem");

// Constructors
cls_RWStepRepr_RWDescriptiveRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepRepr_RWDescriptiveRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWDescriptiveRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWDescriptiveRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWDescriptiveRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWDescriptiveRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWDescriptiveRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWDescriptiveRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWDescriptiveRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWDescriptiveRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWDescriptiveRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWDescriptiveRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWDescriptiveRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWDescriptiveRepresentationItem.def("ReadStep", (void (RWStepRepr_RWDescriptiveRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_DescriptiveRepresentationItem> &) const) &RWStepRepr_RWDescriptiveRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWDescriptiveRepresentationItem.def("WriteStep", (void (RWStepRepr_RWDescriptiveRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_DescriptiveRepresentationItem> &) const) &RWStepRepr_RWDescriptiveRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWEXTENSION
py::class_<RWStepRepr_RWExtension> cls_RWStepRepr_RWExtension(mod, "RWStepRepr_RWExtension", "Read & Write tool for Extension");

// Constructors
cls_RWStepRepr_RWExtension.def(py::init<>());

// Methods
// cls_RWStepRepr_RWExtension.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWExtension::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWExtension.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWExtension::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWExtension.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWExtension::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWExtension.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWExtension::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWExtension.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWExtension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWExtension.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWExtension::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWExtension.def("ReadStep", (void (RWStepRepr_RWExtension::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Extension> &) const) &RWStepRepr_RWExtension::ReadStep, "Reads Extension", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWExtension.def("WriteStep", (void (RWStepRepr_RWExtension::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Extension> &) const) &RWStepRepr_RWExtension::WriteStep, "Writes Extension", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWExtension.def("Share", (void (RWStepRepr_RWExtension::*)(const opencascade::handle<StepRepr_Extension> &, Interface_EntityIterator &) const) &RWStepRepr_RWExtension::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWFEATUREFORDATUMTARGETRELATIONSHIP
py::class_<RWStepRepr_RWFeatureForDatumTargetRelationship> cls_RWStepRepr_RWFeatureForDatumTargetRelationship(mod, "RWStepRepr_RWFeatureForDatumTargetRelationship", "Read & Write tool for FeatureForDatumTargetRelationship");

// Constructors
cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def(py::init<>());

// Methods
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("ReadStep", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &) const) &RWStepRepr_RWFeatureForDatumTargetRelationship::ReadStep, "Reads ShapeAspectRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("WriteStep", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &) const) &RWStepRepr_RWFeatureForDatumTargetRelationship::WriteStep, "Writes ShapeAspectRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("Share", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &, Interface_EntityIterator &) const) &RWStepRepr_RWFeatureForDatumTargetRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWFUNCTIONALLYDEFINEDTRANSFORMATION
py::class_<RWStepRepr_RWFunctionallyDefinedTransformation> cls_RWStepRepr_RWFunctionallyDefinedTransformation(mod, "RWStepRepr_RWFunctionallyDefinedTransformation", "Read & Write Module for FunctionallyDefinedTransformation");

// Constructors
cls_RWStepRepr_RWFunctionallyDefinedTransformation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWFunctionallyDefinedTransformation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWFunctionallyDefinedTransformation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWFunctionallyDefinedTransformation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWFunctionallyDefinedTransformation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWFunctionallyDefinedTransformation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWFunctionallyDefinedTransformation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWFunctionallyDefinedTransformation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWFunctionallyDefinedTransformation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWFunctionallyDefinedTransformation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWFunctionallyDefinedTransformation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWFunctionallyDefinedTransformation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWFunctionallyDefinedTransformation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWFunctionallyDefinedTransformation.def("ReadStep", (void (RWStepRepr_RWFunctionallyDefinedTransformation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_FunctionallyDefinedTransformation> &) const) &RWStepRepr_RWFunctionallyDefinedTransformation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWFunctionallyDefinedTransformation.def("WriteStep", (void (RWStepRepr_RWFunctionallyDefinedTransformation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_FunctionallyDefinedTransformation> &) const) &RWStepRepr_RWFunctionallyDefinedTransformation::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWGEOMETRICALIGNMENT
py::class_<RWStepRepr_RWGeometricAlignment> cls_RWStepRepr_RWGeometricAlignment(mod, "RWStepRepr_RWGeometricAlignment", "Read & Write tool for GeometricAlignment");

// Constructors
cls_RWStepRepr_RWGeometricAlignment.def(py::init<>());

// Methods
// cls_RWStepRepr_RWGeometricAlignment.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWGeometricAlignment::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWGeometricAlignment.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWGeometricAlignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWGeometricAlignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWGeometricAlignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWGeometricAlignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWGeometricAlignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWGeometricAlignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWGeometricAlignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWGeometricAlignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWGeometricAlignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWGeometricAlignment.def("ReadStep", (void (RWStepRepr_RWGeometricAlignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_GeometricAlignment> &) const) &RWStepRepr_RWGeometricAlignment::ReadStep, "Reads GeometricAlignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWGeometricAlignment.def("WriteStep", (void (RWStepRepr_RWGeometricAlignment::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_GeometricAlignment> &) const) &RWStepRepr_RWGeometricAlignment::WriteStep, "Writes GeometricAlignment", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWGeometricAlignment.def("Share", (void (RWStepRepr_RWGeometricAlignment::*)(const opencascade::handle<StepRepr_GeometricAlignment> &, Interface_EntityIterator &) const) &RWStepRepr_RWGeometricAlignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWGLOBALUNCERTAINTYASSIGNEDCONTEXT
py::class_<RWStepRepr_RWGlobalUncertaintyAssignedContext> cls_RWStepRepr_RWGlobalUncertaintyAssignedContext(mod, "RWStepRepr_RWGlobalUncertaintyAssignedContext", "Read & Write Module for GlobalUncertaintyAssignedContext");

// Constructors
cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def(py::init<>());

// Methods
// cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWGlobalUncertaintyAssignedContext::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWGlobalUncertaintyAssignedContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWGlobalUncertaintyAssignedContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWGlobalUncertaintyAssignedContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWGlobalUncertaintyAssignedContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWGlobalUncertaintyAssignedContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def("ReadStep", (void (RWStepRepr_RWGlobalUncertaintyAssignedContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &) const) &RWStepRepr_RWGlobalUncertaintyAssignedContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def("WriteStep", (void (RWStepRepr_RWGlobalUncertaintyAssignedContext::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &) const) &RWStepRepr_RWGlobalUncertaintyAssignedContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def("Share", (void (RWStepRepr_RWGlobalUncertaintyAssignedContext::*)(const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &, Interface_EntityIterator &) const) &RWStepRepr_RWGlobalUncertaintyAssignedContext::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWGLOBALUNITASSIGNEDCONTEXT
py::class_<RWStepRepr_RWGlobalUnitAssignedContext> cls_RWStepRepr_RWGlobalUnitAssignedContext(mod, "RWStepRepr_RWGlobalUnitAssignedContext", "Read & Write Module for GlobalUnitAssignedContext");

// Constructors
cls_RWStepRepr_RWGlobalUnitAssignedContext.def(py::init<>());

// Methods
// cls_RWStepRepr_RWGlobalUnitAssignedContext.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWGlobalUnitAssignedContext::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWGlobalUnitAssignedContext.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWGlobalUnitAssignedContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWGlobalUnitAssignedContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWGlobalUnitAssignedContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWGlobalUnitAssignedContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWGlobalUnitAssignedContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWGlobalUnitAssignedContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWGlobalUnitAssignedContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWGlobalUnitAssignedContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWGlobalUnitAssignedContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWGlobalUnitAssignedContext.def("ReadStep", (void (RWStepRepr_RWGlobalUnitAssignedContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &) const) &RWStepRepr_RWGlobalUnitAssignedContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWGlobalUnitAssignedContext.def("WriteStep", (void (RWStepRepr_RWGlobalUnitAssignedContext::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &) const) &RWStepRepr_RWGlobalUnitAssignedContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWGlobalUnitAssignedContext.def("Share", (void (RWStepRepr_RWGlobalUnitAssignedContext::*)(const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &, Interface_EntityIterator &) const) &RWStepRepr_RWGlobalUnitAssignedContext::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWINTEGERREPRESENTATIONITEM
py::class_<RWStepRepr_RWIntegerRepresentationItem> cls_RWStepRepr_RWIntegerRepresentationItem(mod, "RWStepRepr_RWIntegerRepresentationItem", "Read & Write Module for IntegerRepresentationItem");

// Constructors
cls_RWStepRepr_RWIntegerRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepRepr_RWIntegerRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWIntegerRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWIntegerRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWIntegerRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWIntegerRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWIntegerRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWIntegerRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWIntegerRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWIntegerRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWIntegerRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWIntegerRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWIntegerRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWIntegerRepresentationItem.def("ReadStep", (void (RWStepRepr_RWIntegerRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_IntegerRepresentationItem> &) const) &RWStepRepr_RWIntegerRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWIntegerRepresentationItem.def("WriteStep", (void (RWStepRepr_RWIntegerRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_IntegerRepresentationItem> &) const) &RWStepRepr_RWIntegerRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWITEMDEFINEDTRANSFORMATION
py::class_<RWStepRepr_RWItemDefinedTransformation> cls_RWStepRepr_RWItemDefinedTransformation(mod, "RWStepRepr_RWItemDefinedTransformation", "Read & Write Module for ItemDefinedTransformation");

// Constructors
cls_RWStepRepr_RWItemDefinedTransformation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWItemDefinedTransformation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWItemDefinedTransformation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWItemDefinedTransformation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWItemDefinedTransformation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWItemDefinedTransformation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWItemDefinedTransformation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWItemDefinedTransformation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWItemDefinedTransformation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWItemDefinedTransformation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWItemDefinedTransformation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWItemDefinedTransformation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWItemDefinedTransformation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWItemDefinedTransformation.def("ReadStep", (void (RWStepRepr_RWItemDefinedTransformation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ItemDefinedTransformation> &) const) &RWStepRepr_RWItemDefinedTransformation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWItemDefinedTransformation.def("WriteStep", (void (RWStepRepr_RWItemDefinedTransformation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ItemDefinedTransformation> &) const) &RWStepRepr_RWItemDefinedTransformation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWItemDefinedTransformation.def("Share", (void (RWStepRepr_RWItemDefinedTransformation::*)(const opencascade::handle<StepRepr_ItemDefinedTransformation> &, Interface_EntityIterator &) const) &RWStepRepr_RWItemDefinedTransformation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWMAKEFROMUSAGEOPTION
py::class_<RWStepRepr_RWMakeFromUsageOption> cls_RWStepRepr_RWMakeFromUsageOption(mod, "RWStepRepr_RWMakeFromUsageOption", "Read & Write tool for MakeFromUsageOption");

// Constructors
cls_RWStepRepr_RWMakeFromUsageOption.def(py::init<>());

// Methods
// cls_RWStepRepr_RWMakeFromUsageOption.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWMakeFromUsageOption::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWMakeFromUsageOption.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWMakeFromUsageOption::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMakeFromUsageOption.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWMakeFromUsageOption::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWMakeFromUsageOption.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWMakeFromUsageOption::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMakeFromUsageOption.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWMakeFromUsageOption::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWMakeFromUsageOption.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWMakeFromUsageOption::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWMakeFromUsageOption.def("ReadStep", (void (RWStepRepr_RWMakeFromUsageOption::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MakeFromUsageOption> &) const) &RWStepRepr_RWMakeFromUsageOption::ReadStep, "Reads MakeFromUsageOption", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWMakeFromUsageOption.def("WriteStep", (void (RWStepRepr_RWMakeFromUsageOption::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MakeFromUsageOption> &) const) &RWStepRepr_RWMakeFromUsageOption::WriteStep, "Writes MakeFromUsageOption", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWMakeFromUsageOption.def("Share", (void (RWStepRepr_RWMakeFromUsageOption::*)(const opencascade::handle<StepRepr_MakeFromUsageOption> &, Interface_EntityIterator &) const) &RWStepRepr_RWMakeFromUsageOption::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWMAPPEDITEM
py::class_<RWStepRepr_RWMappedItem> cls_RWStepRepr_RWMappedItem(mod, "RWStepRepr_RWMappedItem", "Read & Write Module for MappedItem");

// Constructors
cls_RWStepRepr_RWMappedItem.def(py::init<>());

// Methods
// cls_RWStepRepr_RWMappedItem.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWMappedItem::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWMappedItem.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWMappedItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMappedItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWMappedItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWMappedItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWMappedItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMappedItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWMappedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWMappedItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWMappedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWMappedItem.def("ReadStep", (void (RWStepRepr_RWMappedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MappedItem> &) const) &RWStepRepr_RWMappedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWMappedItem.def("WriteStep", (void (RWStepRepr_RWMappedItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MappedItem> &) const) &RWStepRepr_RWMappedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWMappedItem.def("Share", (void (RWStepRepr_RWMappedItem::*)(const opencascade::handle<StepRepr_MappedItem> &, Interface_EntityIterator &) const) &RWStepRepr_RWMappedItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWMATERIALDESIGNATION
py::class_<RWStepRepr_RWMaterialDesignation> cls_RWStepRepr_RWMaterialDesignation(mod, "RWStepRepr_RWMaterialDesignation", "Read & Write Module for MaterialDesignation");

// Constructors
cls_RWStepRepr_RWMaterialDesignation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWMaterialDesignation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWMaterialDesignation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWMaterialDesignation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWMaterialDesignation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWMaterialDesignation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWMaterialDesignation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWMaterialDesignation.def("ReadStep", (void (RWStepRepr_RWMaterialDesignation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MaterialDesignation> &) const) &RWStepRepr_RWMaterialDesignation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWMaterialDesignation.def("WriteStep", (void (RWStepRepr_RWMaterialDesignation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MaterialDesignation> &) const) &RWStepRepr_RWMaterialDesignation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWMaterialDesignation.def("Share", (void (RWStepRepr_RWMaterialDesignation::*)(const opencascade::handle<StepRepr_MaterialDesignation> &, Interface_EntityIterator &) const) &RWStepRepr_RWMaterialDesignation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWMATERIALPROPERTY
py::class_<RWStepRepr_RWMaterialProperty> cls_RWStepRepr_RWMaterialProperty(mod, "RWStepRepr_RWMaterialProperty", "Read & Write tool for MaterialProperty");

// Constructors
cls_RWStepRepr_RWMaterialProperty.def(py::init<>());

// Methods
// cls_RWStepRepr_RWMaterialProperty.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWMaterialProperty::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWMaterialProperty.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWMaterialProperty::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialProperty.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWMaterialProperty::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWMaterialProperty.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWMaterialProperty::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialProperty.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWMaterialProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialProperty.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWMaterialProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWMaterialProperty.def("ReadStep", (void (RWStepRepr_RWMaterialProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MaterialProperty> &) const) &RWStepRepr_RWMaterialProperty::ReadStep, "Reads MaterialProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWMaterialProperty.def("WriteStep", (void (RWStepRepr_RWMaterialProperty::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MaterialProperty> &) const) &RWStepRepr_RWMaterialProperty::WriteStep, "Writes MaterialProperty", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWMaterialProperty.def("Share", (void (RWStepRepr_RWMaterialProperty::*)(const opencascade::handle<StepRepr_MaterialProperty> &, Interface_EntityIterator &) const) &RWStepRepr_RWMaterialProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWMATERIALPROPERTYREPRESENTATION
py::class_<RWStepRepr_RWMaterialPropertyRepresentation> cls_RWStepRepr_RWMaterialPropertyRepresentation(mod, "RWStepRepr_RWMaterialPropertyRepresentation", "Read & Write tool for MaterialPropertyRepresentation");

// Constructors
cls_RWStepRepr_RWMaterialPropertyRepresentation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWMaterialPropertyRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWMaterialPropertyRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWMaterialPropertyRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWMaterialPropertyRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialPropertyRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWMaterialPropertyRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWMaterialPropertyRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWMaterialPropertyRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialPropertyRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWMaterialPropertyRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialPropertyRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWMaterialPropertyRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWMaterialPropertyRepresentation.def("ReadStep", (void (RWStepRepr_RWMaterialPropertyRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MaterialPropertyRepresentation> &) const) &RWStepRepr_RWMaterialPropertyRepresentation::ReadStep, "Reads MaterialPropertyRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWMaterialPropertyRepresentation.def("WriteStep", (void (RWStepRepr_RWMaterialPropertyRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MaterialPropertyRepresentation> &) const) &RWStepRepr_RWMaterialPropertyRepresentation::WriteStep, "Writes MaterialPropertyRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWMaterialPropertyRepresentation.def("Share", (void (RWStepRepr_RWMaterialPropertyRepresentation::*)(const opencascade::handle<StepRepr_MaterialPropertyRepresentation> &, Interface_EntityIterator &) const) &RWStepRepr_RWMaterialPropertyRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWMEASUREREPRESENTATIONITEM
py::class_<RWStepRepr_RWMeasureRepresentationItem> cls_RWStepRepr_RWMeasureRepresentationItem(mod, "RWStepRepr_RWMeasureRepresentationItem", "Read & Write Module for MeasureRepresentationItem");

// Constructors
cls_RWStepRepr_RWMeasureRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepRepr_RWMeasureRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWMeasureRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWMeasureRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWMeasureRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMeasureRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWMeasureRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWMeasureRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWMeasureRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMeasureRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWMeasureRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWMeasureRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWMeasureRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWMeasureRepresentationItem.def("ReadStep", (void (RWStepRepr_RWMeasureRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MeasureRepresentationItem> &) const) &RWStepRepr_RWMeasureRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWMeasureRepresentationItem.def("WriteStep", (void (RWStepRepr_RWMeasureRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MeasureRepresentationItem> &) const) &RWStepRepr_RWMeasureRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWMeasureRepresentationItem.def("Share", (void (RWStepRepr_RWMeasureRepresentationItem::*)(const opencascade::handle<StepRepr_MeasureRepresentationItem> &, Interface_EntityIterator &) const) &RWStepRepr_RWMeasureRepresentationItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWPARALLELOFFSET
py::class_<RWStepRepr_RWParallelOffset> cls_RWStepRepr_RWParallelOffset(mod, "RWStepRepr_RWParallelOffset", "Read & Write tool for ParallelOffset");

// Constructors
cls_RWStepRepr_RWParallelOffset.def(py::init<>());

// Methods
// cls_RWStepRepr_RWParallelOffset.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWParallelOffset::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWParallelOffset.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWParallelOffset::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWParallelOffset.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWParallelOffset::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWParallelOffset.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWParallelOffset::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWParallelOffset.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWParallelOffset::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWParallelOffset.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWParallelOffset::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWParallelOffset.def("ReadStep", (void (RWStepRepr_RWParallelOffset::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ParallelOffset> &) const) &RWStepRepr_RWParallelOffset::ReadStep, "Reads ParallelOffset", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWParallelOffset.def("WriteStep", (void (RWStepRepr_RWParallelOffset::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ParallelOffset> &) const) &RWStepRepr_RWParallelOffset::WriteStep, "Writes ParallelOffset", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWParallelOffset.def("Share", (void (RWStepRepr_RWParallelOffset::*)(const opencascade::handle<StepRepr_ParallelOffset> &, Interface_EntityIterator &) const) &RWStepRepr_RWParallelOffset::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWPARAMETRICREPRESENTATIONCONTEXT
py::class_<RWStepRepr_RWParametricRepresentationContext> cls_RWStepRepr_RWParametricRepresentationContext(mod, "RWStepRepr_RWParametricRepresentationContext", "Read & Write Module for ParametricRepresentationContext");

// Constructors
cls_RWStepRepr_RWParametricRepresentationContext.def(py::init<>());

// Methods
// cls_RWStepRepr_RWParametricRepresentationContext.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWParametricRepresentationContext::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWParametricRepresentationContext.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWParametricRepresentationContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWParametricRepresentationContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWParametricRepresentationContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWParametricRepresentationContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWParametricRepresentationContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWParametricRepresentationContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWParametricRepresentationContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWParametricRepresentationContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWParametricRepresentationContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWParametricRepresentationContext.def("ReadStep", (void (RWStepRepr_RWParametricRepresentationContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ParametricRepresentationContext> &) const) &RWStepRepr_RWParametricRepresentationContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWParametricRepresentationContext.def("WriteStep", (void (RWStepRepr_RWParametricRepresentationContext::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ParametricRepresentationContext> &) const) &RWStepRepr_RWParametricRepresentationContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWPERPENDICULARTO
py::class_<RWStepRepr_RWPerpendicularTo> cls_RWStepRepr_RWPerpendicularTo(mod, "RWStepRepr_RWPerpendicularTo", "Read & Write tool for PerpendicularTo");

// Constructors
cls_RWStepRepr_RWPerpendicularTo.def(py::init<>());

// Methods
// cls_RWStepRepr_RWPerpendicularTo.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWPerpendicularTo::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWPerpendicularTo.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWPerpendicularTo::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPerpendicularTo.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWPerpendicularTo::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWPerpendicularTo.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWPerpendicularTo::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPerpendicularTo.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWPerpendicularTo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWPerpendicularTo.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWPerpendicularTo::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWPerpendicularTo.def("ReadStep", (void (RWStepRepr_RWPerpendicularTo::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PerpendicularTo> &) const) &RWStepRepr_RWPerpendicularTo::ReadStep, "Reads PerpendicularTo", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWPerpendicularTo.def("WriteStep", (void (RWStepRepr_RWPerpendicularTo::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PerpendicularTo> &) const) &RWStepRepr_RWPerpendicularTo::WriteStep, "Writes PerpendicularTo", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWPerpendicularTo.def("Share", (void (RWStepRepr_RWPerpendicularTo::*)(const opencascade::handle<StepRepr_PerpendicularTo> &, Interface_EntityIterator &) const) &RWStepRepr_RWPerpendicularTo::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWPRODUCTCONCEPT
py::class_<RWStepRepr_RWProductConcept> cls_RWStepRepr_RWProductConcept(mod, "RWStepRepr_RWProductConcept", "Read & Write tool for ProductConcept");

// Constructors
cls_RWStepRepr_RWProductConcept.def(py::init<>());

// Methods
// cls_RWStepRepr_RWProductConcept.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWProductConcept::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWProductConcept.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWProductConcept::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWProductConcept.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWProductConcept::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWProductConcept.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWProductConcept::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWProductConcept.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWProductConcept::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWProductConcept.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWProductConcept::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWProductConcept.def("ReadStep", (void (RWStepRepr_RWProductConcept::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ProductConcept> &) const) &RWStepRepr_RWProductConcept::ReadStep, "Reads ProductConcept", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWProductConcept.def("WriteStep", (void (RWStepRepr_RWProductConcept::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ProductConcept> &) const) &RWStepRepr_RWProductConcept::WriteStep, "Writes ProductConcept", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWProductConcept.def("Share", (void (RWStepRepr_RWProductConcept::*)(const opencascade::handle<StepRepr_ProductConcept> &, Interface_EntityIterator &) const) &RWStepRepr_RWProductConcept::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWPRODUCTDEFINITIONSHAPE
py::class_<RWStepRepr_RWProductDefinitionShape> cls_RWStepRepr_RWProductDefinitionShape(mod, "RWStepRepr_RWProductDefinitionShape", "Read & Write tool for ProductDefinitionShape");

// Constructors
cls_RWStepRepr_RWProductDefinitionShape.def(py::init<>());

// Methods
// cls_RWStepRepr_RWProductDefinitionShape.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWProductDefinitionShape::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWProductDefinitionShape.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWProductDefinitionShape::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWProductDefinitionShape.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWProductDefinitionShape::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWProductDefinitionShape.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWProductDefinitionShape::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWProductDefinitionShape.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWProductDefinitionShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWProductDefinitionShape.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWProductDefinitionShape::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWProductDefinitionShape.def("ReadStep", (void (RWStepRepr_RWProductDefinitionShape::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &) const) &RWStepRepr_RWProductDefinitionShape::ReadStep, "Reads ProductDefinitionShape", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWProductDefinitionShape.def("WriteStep", (void (RWStepRepr_RWProductDefinitionShape::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ProductDefinitionShape> &) const) &RWStepRepr_RWProductDefinitionShape::WriteStep, "Writes ProductDefinitionShape", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWProductDefinitionShape.def("Share", (void (RWStepRepr_RWProductDefinitionShape::*)(const opencascade::handle<StepRepr_ProductDefinitionShape> &, Interface_EntityIterator &) const) &RWStepRepr_RWProductDefinitionShape::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWPROPERTYDEFINITION
py::class_<RWStepRepr_RWPropertyDefinition> cls_RWStepRepr_RWPropertyDefinition(mod, "RWStepRepr_RWPropertyDefinition", "Read & Write tool for PropertyDefinition");

// Constructors
cls_RWStepRepr_RWPropertyDefinition.def(py::init<>());

// Methods
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWPropertyDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWPropertyDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWPropertyDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWPropertyDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWPropertyDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWPropertyDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWPropertyDefinition.def("ReadStep", (void (RWStepRepr_RWPropertyDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PropertyDefinition> &) const) &RWStepRepr_RWPropertyDefinition::ReadStep, "Reads PropertyDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWPropertyDefinition.def("WriteStep", (void (RWStepRepr_RWPropertyDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PropertyDefinition> &) const) &RWStepRepr_RWPropertyDefinition::WriteStep, "Writes PropertyDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWPropertyDefinition.def("Share", (void (RWStepRepr_RWPropertyDefinition::*)(const opencascade::handle<StepRepr_PropertyDefinition> &, Interface_EntityIterator &) const) &RWStepRepr_RWPropertyDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWPROPERTYDEFINITIONRELATIONSHIP
py::class_<RWStepRepr_RWPropertyDefinitionRelationship> cls_RWStepRepr_RWPropertyDefinitionRelationship(mod, "RWStepRepr_RWPropertyDefinitionRelationship", "Read & Write tool for PropertyDefinitionRelationship");

// Constructors
cls_RWStepRepr_RWPropertyDefinitionRelationship.def(py::init<>());

// Methods
// cls_RWStepRepr_RWPropertyDefinitionRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWPropertyDefinitionRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWPropertyDefinitionRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWPropertyDefinitionRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinitionRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWPropertyDefinitionRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWPropertyDefinitionRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWPropertyDefinitionRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinitionRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWPropertyDefinitionRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinitionRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWPropertyDefinitionRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWPropertyDefinitionRelationship.def("ReadStep", (void (RWStepRepr_RWPropertyDefinitionRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PropertyDefinitionRelationship> &) const) &RWStepRepr_RWPropertyDefinitionRelationship::ReadStep, "Reads PropertyDefinitionRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWPropertyDefinitionRelationship.def("WriteStep", (void (RWStepRepr_RWPropertyDefinitionRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PropertyDefinitionRelationship> &) const) &RWStepRepr_RWPropertyDefinitionRelationship::WriteStep, "Writes PropertyDefinitionRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWPropertyDefinitionRelationship.def("Share", (void (RWStepRepr_RWPropertyDefinitionRelationship::*)(const opencascade::handle<StepRepr_PropertyDefinitionRelationship> &, Interface_EntityIterator &) const) &RWStepRepr_RWPropertyDefinitionRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWPROPERTYDEFINITIONREPRESENTATION
py::class_<RWStepRepr_RWPropertyDefinitionRepresentation> cls_RWStepRepr_RWPropertyDefinitionRepresentation(mod, "RWStepRepr_RWPropertyDefinitionRepresentation", "Read & Write tool for PropertyDefinitionRepresentation");

// Constructors
cls_RWStepRepr_RWPropertyDefinitionRepresentation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWPropertyDefinitionRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWPropertyDefinitionRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWPropertyDefinitionRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWPropertyDefinitionRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinitionRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWPropertyDefinitionRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWPropertyDefinitionRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWPropertyDefinitionRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinitionRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWPropertyDefinitionRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinitionRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWPropertyDefinitionRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWPropertyDefinitionRepresentation.def("ReadStep", (void (RWStepRepr_RWPropertyDefinitionRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PropertyDefinitionRepresentation> &) const) &RWStepRepr_RWPropertyDefinitionRepresentation::ReadStep, "Reads PropertyDefinitionRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWPropertyDefinitionRepresentation.def("WriteStep", (void (RWStepRepr_RWPropertyDefinitionRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PropertyDefinitionRepresentation> &) const) &RWStepRepr_RWPropertyDefinitionRepresentation::WriteStep, "Writes PropertyDefinitionRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWPropertyDefinitionRepresentation.def("Share", (void (RWStepRepr_RWPropertyDefinitionRepresentation::*)(const opencascade::handle<StepRepr_PropertyDefinitionRepresentation> &, Interface_EntityIterator &) const) &RWStepRepr_RWPropertyDefinitionRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWQUANTIFIEDASSEMBLYCOMPONENTUSAGE
py::class_<RWStepRepr_RWQuantifiedAssemblyComponentUsage> cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage(mod, "RWStepRepr_RWQuantifiedAssemblyComponentUsage", "Read & Write tool for QuantifiedAssemblyComponentUsage");

// Constructors
cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def(py::init<>());

// Methods
// cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def("ReadStep", (void (RWStepRepr_RWQuantifiedAssemblyComponentUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_QuantifiedAssemblyComponentUsage> &) const) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::ReadStep, "Reads QuantifiedAssemblyComponentUsage", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def("WriteStep", (void (RWStepRepr_RWQuantifiedAssemblyComponentUsage::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_QuantifiedAssemblyComponentUsage> &) const) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::WriteStep, "Writes QuantifiedAssemblyComponentUsage", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def("Share", (void (RWStepRepr_RWQuantifiedAssemblyComponentUsage::*)(const opencascade::handle<StepRepr_QuantifiedAssemblyComponentUsage> &, Interface_EntityIterator &) const) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWREPRESENTATION
py::class_<RWStepRepr_RWRepresentation> cls_RWStepRepr_RWRepresentation(mod, "RWStepRepr_RWRepresentation", "Read & Write Module for Representation");

// Constructors
cls_RWStepRepr_RWRepresentation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWRepresentation.def("ReadStep", (void (RWStepRepr_RWRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Representation> &) const) &RWStepRepr_RWRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWRepresentation.def("WriteStep", (void (RWStepRepr_RWRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Representation> &) const) &RWStepRepr_RWRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWRepresentation.def("Share", (void (RWStepRepr_RWRepresentation::*)(const opencascade::handle<StepRepr_Representation> &, Interface_EntityIterator &) const) &RWStepRepr_RWRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWREPRESENTATIONCONTEXT
py::class_<RWStepRepr_RWRepresentationContext> cls_RWStepRepr_RWRepresentationContext(mod, "RWStepRepr_RWRepresentationContext", "Read & Write Module for RepresentationContext");

// Constructors
cls_RWStepRepr_RWRepresentationContext.def(py::init<>());

// Methods
// cls_RWStepRepr_RWRepresentationContext.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationContext::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationContext.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWRepresentationContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWRepresentationContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWRepresentationContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWRepresentationContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWRepresentationContext.def("ReadStep", (void (RWStepRepr_RWRepresentationContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationContext> &) const) &RWStepRepr_RWRepresentationContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWRepresentationContext.def("WriteStep", (void (RWStepRepr_RWRepresentationContext::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationContext> &) const) &RWStepRepr_RWRepresentationContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWREPRESENTATIONITEM
py::class_<RWStepRepr_RWRepresentationItem> cls_RWStepRepr_RWRepresentationItem(mod, "RWStepRepr_RWRepresentationItem", "Read & Write Module for RepresentationItem");

// Constructors
cls_RWStepRepr_RWRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepRepr_RWRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWRepresentationItem.def("ReadStep", (void (RWStepRepr_RWRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationItem> &) const) &RWStepRepr_RWRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWRepresentationItem.def("WriteStep", (void (RWStepRepr_RWRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationItem> &) const) &RWStepRepr_RWRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWREPRESENTATIONMAP
py::class_<RWStepRepr_RWRepresentationMap> cls_RWStepRepr_RWRepresentationMap(mod, "RWStepRepr_RWRepresentationMap", "Read & Write Module for RepresentationMap");

// Constructors
cls_RWStepRepr_RWRepresentationMap.def(py::init<>());

// Methods
// cls_RWStepRepr_RWRepresentationMap.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationMap::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationMap.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWRepresentationMap::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationMap.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationMap::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationMap.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWRepresentationMap::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationMap.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWRepresentationMap::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationMap.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWRepresentationMap::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWRepresentationMap.def("ReadStep", (void (RWStepRepr_RWRepresentationMap::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationMap> &) const) &RWStepRepr_RWRepresentationMap::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWRepresentationMap.def("WriteStep", (void (RWStepRepr_RWRepresentationMap::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationMap> &) const) &RWStepRepr_RWRepresentationMap::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWRepresentationMap.def("Share", (void (RWStepRepr_RWRepresentationMap::*)(const opencascade::handle<StepRepr_RepresentationMap> &, Interface_EntityIterator &) const) &RWStepRepr_RWRepresentationMap::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWREPRESENTATIONRELATIONSHIP
py::class_<RWStepRepr_RWRepresentationRelationship> cls_RWStepRepr_RWRepresentationRelationship(mod, "RWStepRepr_RWRepresentationRelationship", "Read & Write Module for RepresentationRelationship");

// Constructors
cls_RWStepRepr_RWRepresentationRelationship.def(py::init<>());

// Methods
// cls_RWStepRepr_RWRepresentationRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWRepresentationRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWRepresentationRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWRepresentationRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWRepresentationRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWRepresentationRelationship.def("ReadStep", (void (RWStepRepr_RWRepresentationRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationRelationship> &) const) &RWStepRepr_RWRepresentationRelationship::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWRepresentationRelationship.def("WriteStep", (void (RWStepRepr_RWRepresentationRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationRelationship> &) const) &RWStepRepr_RWRepresentationRelationship::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWRepresentationRelationship.def("Share", (void (RWStepRepr_RWRepresentationRelationship::*)(const opencascade::handle<StepRepr_RepresentationRelationship> &, Interface_EntityIterator &) const) &RWStepRepr_RWRepresentationRelationship::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWREPRESENTATIONRELATIONSHIPWITHTRANSFORMATION
py::class_<RWStepRepr_RWRepresentationRelationshipWithTransformation> cls_RWStepRepr_RWRepresentationRelationshipWithTransformation(mod, "RWStepRepr_RWRepresentationRelationshipWithTransformation", "Read & Write Module for RepresentationRelationshipWithTransformation");

// Constructors
cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationRelationshipWithTransformation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWRepresentationRelationshipWithTransformation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWRepresentationRelationshipWithTransformation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWRepresentationRelationshipWithTransformation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWRepresentationRelationshipWithTransformation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWRepresentationRelationshipWithTransformation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def("ReadStep", (void (RWStepRepr_RWRepresentationRelationshipWithTransformation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation> &) const) &RWStepRepr_RWRepresentationRelationshipWithTransformation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def("WriteStep", (void (RWStepRepr_RWRepresentationRelationshipWithTransformation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation> &) const) &RWStepRepr_RWRepresentationRelationshipWithTransformation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def("Share", (void (RWStepRepr_RWRepresentationRelationshipWithTransformation::*)(const opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation> &, Interface_EntityIterator &) const) &RWStepRepr_RWRepresentationRelationshipWithTransformation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWREPRITEMANDLENGTHMEASUREWITHUNIT
py::class_<RWStepRepr_RWReprItemAndLengthMeasureWithUnit> cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit(mod, "RWStepRepr_RWReprItemAndLengthMeasureWithUnit", "Read & Write Module for ReprItemAndLengthMeasureWithUni");

// Constructors
cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def("ReadStep", (void (RWStepRepr_RWReprItemAndLengthMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnit> &) const) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def("WriteStep", (void (RWStepRepr_RWReprItemAndLengthMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnit> &) const) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWREPRITEMANDLENGTHMEASUREWITHUNITANDQRI
py::class_<RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI> cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI(mod, "RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI", "Read & Write Module for ReprItemAndLengthMeasureWithUnitAndQRI");

// Constructors
cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def(py::init<>());

// Methods
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def("ReadStep", (void (RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI> &) const) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def("WriteStep", (void (RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI> &) const) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWREPRITEMANDPLANEANGLEMEASUREWITHUNIT
py::class_<RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit> cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit(mod, "RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit", "Read & Write Module for ReprItemAndPlaneAngleMeasureWithUni");

// Constructors
cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def("ReadStep", (void (RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnit> &) const) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def("WriteStep", (void (RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnit> &) const) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWREPRITEMANDPLANEANGLEMEASUREWITHUNITANDQRI
py::class_<RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI> cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI(mod, "RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI", "Read & Write Module for ReprItemAndPlaneAngleMeasureWithUnitAndQRI");

// Constructors
cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def(py::init<>());

// Methods
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def("ReadStep", (void (RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI> &) const) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def("WriteStep", (void (RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI> &) const) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPREPR_RWSHAPEASPECT
py::class_<RWStepRepr_RWShapeAspect> cls_RWStepRepr_RWShapeAspect(mod, "RWStepRepr_RWShapeAspect", "Read & Write Module for ShapeAspect");

// Constructors
cls_RWStepRepr_RWShapeAspect.def(py::init<>());

// Methods
// cls_RWStepRepr_RWShapeAspect.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWShapeAspect::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeAspect.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWShapeAspect::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspect.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWShapeAspect::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeAspect.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWShapeAspect::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspect.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWShapeAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspect.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWShapeAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWShapeAspect.def("ReadStep", (void (RWStepRepr_RWShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeAspect> &) const) &RWStepRepr_RWShapeAspect::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWShapeAspect.def("WriteStep", (void (RWStepRepr_RWShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeAspect> &) const) &RWStepRepr_RWShapeAspect::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWShapeAspect.def("Share", (void (RWStepRepr_RWShapeAspect::*)(const opencascade::handle<StepRepr_ShapeAspect> &, Interface_EntityIterator &) const) &RWStepRepr_RWShapeAspect::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWSHAPEASPECTDERIVINGRELATIONSHIP
py::class_<RWStepRepr_RWShapeAspectDerivingRelationship> cls_RWStepRepr_RWShapeAspectDerivingRelationship(mod, "RWStepRepr_RWShapeAspectDerivingRelationship", "Read & Write tool for ShapeAspectDerivingRelationship");

// Constructors
cls_RWStepRepr_RWShapeAspectDerivingRelationship.def(py::init<>());

// Methods
// cls_RWStepRepr_RWShapeAspectDerivingRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWShapeAspectDerivingRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeAspectDerivingRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWShapeAspectDerivingRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectDerivingRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWShapeAspectDerivingRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeAspectDerivingRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWShapeAspectDerivingRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectDerivingRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWShapeAspectDerivingRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectDerivingRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWShapeAspectDerivingRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWShapeAspectDerivingRelationship.def("ReadStep", (void (RWStepRepr_RWShapeAspectDerivingRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeAspectDerivingRelationship> &) const) &RWStepRepr_RWShapeAspectDerivingRelationship::ReadStep, "Reads ShapeAspectDerivingRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWShapeAspectDerivingRelationship.def("WriteStep", (void (RWStepRepr_RWShapeAspectDerivingRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeAspectDerivingRelationship> &) const) &RWStepRepr_RWShapeAspectDerivingRelationship::WriteStep, "Writes ShapeAspectDerivingRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWShapeAspectDerivingRelationship.def("Share", (void (RWStepRepr_RWShapeAspectDerivingRelationship::*)(const opencascade::handle<StepRepr_ShapeAspectDerivingRelationship> &, Interface_EntityIterator &) const) &RWStepRepr_RWShapeAspectDerivingRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWSHAPEASPECTRELATIONSHIP
py::class_<RWStepRepr_RWShapeAspectRelationship> cls_RWStepRepr_RWShapeAspectRelationship(mod, "RWStepRepr_RWShapeAspectRelationship", "Read & Write tool for ShapeAspectRelationship");

// Constructors
cls_RWStepRepr_RWShapeAspectRelationship.def(py::init<>());

// Methods
// cls_RWStepRepr_RWShapeAspectRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWShapeAspectRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeAspectRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWShapeAspectRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWShapeAspectRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeAspectRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWShapeAspectRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWShapeAspectRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWShapeAspectRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWShapeAspectRelationship.def("ReadStep", (void (RWStepRepr_RWShapeAspectRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeAspectRelationship> &) const) &RWStepRepr_RWShapeAspectRelationship::ReadStep, "Reads ShapeAspectRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWShapeAspectRelationship.def("WriteStep", (void (RWStepRepr_RWShapeAspectRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeAspectRelationship> &) const) &RWStepRepr_RWShapeAspectRelationship::WriteStep, "Writes ShapeAspectRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWShapeAspectRelationship.def("Share", (void (RWStepRepr_RWShapeAspectRelationship::*)(const opencascade::handle<StepRepr_ShapeAspectRelationship> &, Interface_EntityIterator &) const) &RWStepRepr_RWShapeAspectRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWSHAPEASPECTTRANSITION
py::class_<RWStepRepr_RWShapeAspectTransition> cls_RWStepRepr_RWShapeAspectTransition(mod, "RWStepRepr_RWShapeAspectTransition", "Read & Write tool for ShapeAspectTransition");

// Constructors
cls_RWStepRepr_RWShapeAspectTransition.def(py::init<>());

// Methods
// cls_RWStepRepr_RWShapeAspectTransition.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWShapeAspectTransition::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeAspectTransition.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWShapeAspectTransition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectTransition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWShapeAspectTransition::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeAspectTransition.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWShapeAspectTransition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectTransition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWShapeAspectTransition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWShapeAspectTransition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWShapeAspectTransition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWShapeAspectTransition.def("ReadStep", (void (RWStepRepr_RWShapeAspectTransition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeAspectTransition> &) const) &RWStepRepr_RWShapeAspectTransition::ReadStep, "Reads ShapeAspectTransition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWShapeAspectTransition.def("WriteStep", (void (RWStepRepr_RWShapeAspectTransition::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeAspectTransition> &) const) &RWStepRepr_RWShapeAspectTransition::WriteStep, "Writes ShapeAspectTransition", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWShapeAspectTransition.def("Share", (void (RWStepRepr_RWShapeAspectTransition::*)(const opencascade::handle<StepRepr_ShapeAspectTransition> &, Interface_EntityIterator &) const) &RWStepRepr_RWShapeAspectTransition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWSHAPEREPRESENTATIONRELATIONSHIPWITHTRANSFORMATION
py::class_<RWStepRepr_RWShapeRepresentationRelationshipWithTransformation> cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation(mod, "RWStepRepr_RWShapeRepresentationRelationshipWithTransformation", "Read & Write Module for ShapeRepresentationRelationshipWithTransformation");

// Constructors
cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def("ReadStep", (void (RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeRepresentationRelationshipWithTransformation> &) const) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def("WriteStep", (void (RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeRepresentationRelationshipWithTransformation> &) const) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def("Share", (void (RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::*)(const opencascade::handle<StepRepr_ShapeRepresentationRelationshipWithTransformation> &, Interface_EntityIterator &) const) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWSPECIFIEDHIGHERUSAGEOCCURRENCE
py::class_<RWStepRepr_RWSpecifiedHigherUsageOccurrence> cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence(mod, "RWStepRepr_RWSpecifiedHigherUsageOccurrence", "Read & Write tool for SpecifiedHigherUsageOccurrence");

// Constructors
cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def(py::init<>());

// Methods
// cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def("ReadStep", (void (RWStepRepr_RWSpecifiedHigherUsageOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_SpecifiedHigherUsageOccurrence> &) const) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::ReadStep, "Reads SpecifiedHigherUsageOccurrence", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def("WriteStep", (void (RWStepRepr_RWSpecifiedHigherUsageOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_SpecifiedHigherUsageOccurrence> &) const) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::WriteStep, "Writes SpecifiedHigherUsageOccurrence", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def("Share", (void (RWStepRepr_RWSpecifiedHigherUsageOccurrence::*)(const opencascade::handle<StepRepr_SpecifiedHigherUsageOccurrence> &, Interface_EntityIterator &) const) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWSTRUCTURALRESPONSEPROPERTY
py::class_<RWStepRepr_RWStructuralResponseProperty> cls_RWStepRepr_RWStructuralResponseProperty(mod, "RWStepRepr_RWStructuralResponseProperty", "Read & Write tool for StructuralResponseProperty");

// Constructors
cls_RWStepRepr_RWStructuralResponseProperty.def(py::init<>());

// Methods
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWStructuralResponseProperty::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWStructuralResponseProperty::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWStructuralResponseProperty::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWStructuralResponseProperty::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWStructuralResponseProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWStructuralResponseProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWStructuralResponseProperty.def("ReadStep", (void (RWStepRepr_RWStructuralResponseProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_StructuralResponseProperty> &) const) &RWStepRepr_RWStructuralResponseProperty::ReadStep, "Reads StructuralResponseProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWStructuralResponseProperty.def("WriteStep", (void (RWStepRepr_RWStructuralResponseProperty::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_StructuralResponseProperty> &) const) &RWStepRepr_RWStructuralResponseProperty::WriteStep, "Writes StructuralResponseProperty", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWStructuralResponseProperty.def("Share", (void (RWStepRepr_RWStructuralResponseProperty::*)(const opencascade::handle<StepRepr_StructuralResponseProperty> &, Interface_EntityIterator &) const) &RWStepRepr_RWStructuralResponseProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWSTRUCTURALRESPONSEPROPERTYDEFINITIONREPRESENTATION
py::class_<RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation> cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation(mod, "RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation", "Read & Write tool for StructuralResponsePropertyDefinitionRepresentation");

// Constructors
cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def(py::init<>());

// Methods
// cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def("ReadStep", (void (RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_StructuralResponsePropertyDefinitionRepresentation> &) const) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::ReadStep, "Reads StructuralResponsePropertyDefinitionRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def("WriteStep", (void (RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_StructuralResponsePropertyDefinitionRepresentation> &) const) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::WriteStep, "Writes StructuralResponsePropertyDefinitionRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def("Share", (void (RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::*)(const opencascade::handle<StepRepr_StructuralResponsePropertyDefinitionRepresentation> &, Interface_EntityIterator &) const) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWTANGENT
py::class_<RWStepRepr_RWTangent> cls_RWStepRepr_RWTangent(mod, "RWStepRepr_RWTangent", "Read & Write tool for Tangent");

// Constructors
cls_RWStepRepr_RWTangent.def(py::init<>());

// Methods
// cls_RWStepRepr_RWTangent.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWTangent::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWTangent.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWTangent::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWTangent.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWTangent::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWTangent.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWTangent::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWTangent.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWTangent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWTangent.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWTangent::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWTangent.def("ReadStep", (void (RWStepRepr_RWTangent::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Tangent> &) const) &RWStepRepr_RWTangent::ReadStep, "Reads Tangent", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWTangent.def("WriteStep", (void (RWStepRepr_RWTangent::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Tangent> &) const) &RWStepRepr_RWTangent::WriteStep, "Writes Tangent", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWTangent.def("Share", (void (RWStepRepr_RWTangent::*)(const opencascade::handle<StepRepr_Tangent> &, Interface_EntityIterator &) const) &RWStepRepr_RWTangent::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPREPR_RWVALUEREPRESENTATIONITEM
py::class_<RWStepRepr_RWValueRepresentationItem> cls_RWStepRepr_RWValueRepresentationItem(mod, "RWStepRepr_RWValueRepresentationItem", "Read & Write Module for ValueRepresentationItem");

// Constructors
cls_RWStepRepr_RWValueRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepRepr_RWValueRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWValueRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWValueRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWValueRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWValueRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWValueRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWValueRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWValueRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWValueRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWValueRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWValueRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWValueRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWValueRepresentationItem.def("ReadStep", (void (RWStepRepr_RWValueRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ValueRepresentationItem> &) const) &RWStepRepr_RWValueRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWValueRepresentationItem.def("WriteStep", (void (RWStepRepr_RWValueRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ValueRepresentationItem> &) const) &RWStepRepr_RWValueRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));


}
