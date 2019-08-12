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

void bind_StepRepr_RepresentationItem(py::module &);
void bind_StepRepr_RepresentedDefinition(py::module &);
void bind_StepRepr_PropertyDefinitionRepresentation(py::module &);
void bind_StepRepr_MaterialPropertyRepresentation(py::module &);
void bind_StepRepr_Array1OfMaterialPropertyRepresentation(py::module &);
void bind_StepRepr_HArray1OfMaterialPropertyRepresentation(py::module &);
void bind_StepRepr_Array1OfRepresentationItem(py::module &);
void bind_StepRepr_HArray1OfRepresentationItem(py::module &);
void bind_StepRepr_Representation(py::module &);
void bind_StepRepr_CompoundRepresentationItem(py::module &);
void bind_StepRepr_ShapeAspect(py::module &);
void bind_StepRepr_CharacterizedDefinition(py::module &);
void bind_StepRepr_PropertyDefinition(py::module &);
void bind_StepRepr_ProductDefinitionShape(py::module &);
void bind_StepRepr_CompositeShapeAspect(py::module &);
void bind_StepRepr_Array1OfShapeAspect(py::module &);
void bind_StepRepr_HArray1OfShapeAspect(py::module &);
void bind_StepRepr_RepresentationContext(py::module &);
void bind_StepRepr_ContinuosShapeAspect(py::module &);
void bind_StepRepr_AllAroundShapeAspect(py::module &);
void bind_StepRepr_DerivedShapeAspect(py::module &);
void bind_StepRepr_Apex(py::module &);
void bind_StepRepr_Array1OfPropertyDefinitionRepresentation(py::module &);
void bind_StepRepr_ProductDefinitionUsage(py::module &);
void bind_StepRepr_AssemblyComponentUsage(py::module &);
void bind_StepRepr_AssemblyComponentUsageSubstitute(py::module &);
void bind_StepRepr_BetweenShapeAspect(py::module &);
void bind_StepRepr_CentreOfSymmetry(py::module &);
void bind_StepRepr_CharacterizedRepresentation(py::module &);
void bind_StepRepr_CompShAspAndDatumFeatAndShAsp(py::module &);
void bind_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp(py::module &);
void bind_StepRepr_CompositeGroupShapeAspect(py::module &);
void bind_StepRepr_ConfigurationDesignItem(py::module &);
void bind_StepRepr_ConfigurationDesign(py::module &);
void bind_StepRepr_ConfigurationEffectivity(py::module &);
void bind_StepRepr_ConfigurationItem(py::module &);
void bind_StepRepr_ConstructiveGeometryRepresentation(py::module &);
void bind_StepRepr_RepresentationRelationship(py::module &);
void bind_StepRepr_ConstructiveGeometryRepresentationRelationship(py::module &);
void bind_StepRepr_HArray1OfPropertyDefinitionRepresentation(py::module &);
void bind_StepRepr_DataEnvironment(py::module &);
void bind_StepRepr_DefinitionalRepresentation(py::module &);
void bind_StepRepr_DescriptiveRepresentationItem(py::module &);
void bind_StepRepr_Extension(py::module &);
void bind_StepRepr_ExternallyDefinedRepresentation(py::module &);
void bind_StepRepr_ShapeAspectRelationship(py::module &);
void bind_StepRepr_FeatureForDatumTargetRelationship(py::module &);
void bind_StepRepr_FunctionallyDefinedTransformation(py::module &);
void bind_StepRepr_GeometricAlignment(py::module &);
void bind_StepRepr_GlobalUncertaintyAssignedContext(py::module &);
void bind_StepRepr_GlobalUnitAssignedContext(py::module &);
void bind_StepRepr_SequenceOfMaterialPropertyRepresentation(py::module &);
void bind_StepRepr_HSequenceOfMaterialPropertyRepresentation(py::module &);
void bind_StepRepr_SequenceOfRepresentationItem(py::module &);
void bind_StepRepr_HSequenceOfRepresentationItem(py::module &);
void bind_StepRepr_IntegerRepresentationItem(py::module &);
void bind_StepRepr_ItemDefinedTransformation(py::module &);
void bind_StepRepr_MakeFromUsageOption(py::module &);
void bind_StepRepr_MappedItem(py::module &);
void bind_StepRepr_MaterialDesignation(py::module &);
void bind_StepRepr_MaterialProperty(py::module &);
void bind_StepRepr_MeasureRepresentationItem(py::module &);
void bind_StepRepr_NextAssemblyUsageOccurrence(py::module &);
void bind_StepRepr_ParallelOffset(py::module &);
void bind_StepRepr_ParametricRepresentationContext(py::module &);
void bind_StepRepr_PerpendicularTo(py::module &);
void bind_StepRepr_ProductConcept(py::module &);
void bind_StepRepr_PromissoryUsageOccurrence(py::module &);
void bind_StepRepr_PropertyDefinitionRelationship(py::module &);
void bind_StepRepr_QuantifiedAssemblyComponentUsage(py::module &);
void bind_StepRepr_RepresentationMap(py::module &);
void bind_StepRepr_Transformation(py::module &);
void bind_StepRepr_ShapeRepresentationRelationship(py::module &);
void bind_StepRepr_RepresentationRelationshipWithTransformation(py::module &);
void bind_StepRepr_ReprItemAndMeasureWithUnit(py::module &);
void bind_StepRepr_ReprItemAndLengthMeasureWithUnit(py::module &);
void bind_StepRepr_ReprItemAndMeasureWithUnitAndQRI(py::module &);
void bind_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI(py::module &);
void bind_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit(py::module &);
void bind_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI(py::module &);
void bind_StepRepr_ShapeAspectDerivingRelationship(py::module &);
void bind_StepRepr_ShapeAspectTransition(py::module &);
void bind_StepRepr_ShapeDefinition(py::module &);
void bind_StepRepr_ShapeRepresentationRelationshipWithTransformation(py::module &);
void bind_StepRepr_SpecifiedHigherUsageOccurrence(py::module &);
void bind_StepRepr_StructuralResponseProperty(py::module &);
void bind_StepRepr_StructuralResponsePropertyDefinitionRepresentation(py::module &);
void bind_StepRepr_SuppliedPartRelationship(py::module &);
void bind_StepRepr_Tangent(py::module &);
void bind_StepRepr_ValueRange(py::module &);
void bind_StepRepr_ValueRepresentationItem(py::module &);

PYBIND11_MODULE(StepRepr, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepData");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.NCollection");

bind_StepRepr_RepresentationItem(mod);
bind_StepRepr_RepresentedDefinition(mod);
bind_StepRepr_PropertyDefinitionRepresentation(mod);
bind_StepRepr_MaterialPropertyRepresentation(mod);
bind_StepRepr_Array1OfMaterialPropertyRepresentation(mod);
bind_StepRepr_HArray1OfMaterialPropertyRepresentation(mod);
bind_StepRepr_Array1OfRepresentationItem(mod);
bind_StepRepr_HArray1OfRepresentationItem(mod);
bind_StepRepr_Representation(mod);
bind_StepRepr_CompoundRepresentationItem(mod);
bind_StepRepr_ShapeAspect(mod);
bind_StepRepr_CharacterizedDefinition(mod);
bind_StepRepr_PropertyDefinition(mod);
bind_StepRepr_ProductDefinitionShape(mod);
bind_StepRepr_CompositeShapeAspect(mod);
bind_StepRepr_Array1OfShapeAspect(mod);
bind_StepRepr_HArray1OfShapeAspect(mod);
bind_StepRepr_RepresentationContext(mod);
bind_StepRepr_ContinuosShapeAspect(mod);
bind_StepRepr_AllAroundShapeAspect(mod);
bind_StepRepr_DerivedShapeAspect(mod);
bind_StepRepr_Apex(mod);
bind_StepRepr_Array1OfPropertyDefinitionRepresentation(mod);
bind_StepRepr_ProductDefinitionUsage(mod);
bind_StepRepr_AssemblyComponentUsage(mod);
bind_StepRepr_AssemblyComponentUsageSubstitute(mod);
bind_StepRepr_BetweenShapeAspect(mod);
bind_StepRepr_CentreOfSymmetry(mod);
bind_StepRepr_CharacterizedRepresentation(mod);
bind_StepRepr_CompShAspAndDatumFeatAndShAsp(mod);
bind_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp(mod);
bind_StepRepr_CompositeGroupShapeAspect(mod);
bind_StepRepr_ConfigurationDesignItem(mod);
bind_StepRepr_ConfigurationDesign(mod);
bind_StepRepr_ConfigurationEffectivity(mod);
bind_StepRepr_ConfigurationItem(mod);
bind_StepRepr_ConstructiveGeometryRepresentation(mod);
bind_StepRepr_RepresentationRelationship(mod);
bind_StepRepr_ConstructiveGeometryRepresentationRelationship(mod);
bind_StepRepr_HArray1OfPropertyDefinitionRepresentation(mod);
bind_StepRepr_DataEnvironment(mod);
bind_StepRepr_DefinitionalRepresentation(mod);
bind_StepRepr_DescriptiveRepresentationItem(mod);
bind_StepRepr_Extension(mod);
bind_StepRepr_ExternallyDefinedRepresentation(mod);
bind_StepRepr_ShapeAspectRelationship(mod);
bind_StepRepr_FeatureForDatumTargetRelationship(mod);
bind_StepRepr_FunctionallyDefinedTransformation(mod);
bind_StepRepr_GeometricAlignment(mod);
bind_StepRepr_GlobalUncertaintyAssignedContext(mod);
bind_StepRepr_GlobalUnitAssignedContext(mod);
bind_StepRepr_SequenceOfMaterialPropertyRepresentation(mod);
bind_StepRepr_HSequenceOfMaterialPropertyRepresentation(mod);
bind_StepRepr_SequenceOfRepresentationItem(mod);
bind_StepRepr_HSequenceOfRepresentationItem(mod);
bind_StepRepr_IntegerRepresentationItem(mod);
bind_StepRepr_ItemDefinedTransformation(mod);
bind_StepRepr_MakeFromUsageOption(mod);
bind_StepRepr_MappedItem(mod);
bind_StepRepr_MaterialDesignation(mod);
bind_StepRepr_MaterialProperty(mod);
bind_StepRepr_MeasureRepresentationItem(mod);
bind_StepRepr_NextAssemblyUsageOccurrence(mod);
bind_StepRepr_ParallelOffset(mod);
bind_StepRepr_ParametricRepresentationContext(mod);
bind_StepRepr_PerpendicularTo(mod);
bind_StepRepr_ProductConcept(mod);
bind_StepRepr_PromissoryUsageOccurrence(mod);
bind_StepRepr_PropertyDefinitionRelationship(mod);
bind_StepRepr_QuantifiedAssemblyComponentUsage(mod);
bind_StepRepr_RepresentationMap(mod);
bind_StepRepr_Transformation(mod);
bind_StepRepr_ShapeRepresentationRelationship(mod);
bind_StepRepr_RepresentationRelationshipWithTransformation(mod);
bind_StepRepr_ReprItemAndMeasureWithUnit(mod);
bind_StepRepr_ReprItemAndLengthMeasureWithUnit(mod);
bind_StepRepr_ReprItemAndMeasureWithUnitAndQRI(mod);
bind_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI(mod);
bind_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit(mod);
bind_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI(mod);
bind_StepRepr_ShapeAspectDerivingRelationship(mod);
bind_StepRepr_ShapeAspectTransition(mod);
bind_StepRepr_ShapeDefinition(mod);
bind_StepRepr_ShapeRepresentationRelationshipWithTransformation(mod);
bind_StepRepr_SpecifiedHigherUsageOccurrence(mod);
bind_StepRepr_StructuralResponseProperty(mod);
bind_StepRepr_StructuralResponsePropertyDefinitionRepresentation(mod);
bind_StepRepr_SuppliedPartRelationship(mod);
bind_StepRepr_Tangent(mod);
bind_StepRepr_ValueRange(mod);
bind_StepRepr_ValueRepresentationItem(mod);

}
