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

void bind_RWStepRepr_RWAllAroundShapeAspect(py::module &);
void bind_RWStepRepr_RWApex(py::module &);
void bind_RWStepRepr_RWAssemblyComponentUsage(py::module &);
void bind_RWStepRepr_RWAssemblyComponentUsageSubstitute(py::module &);
void bind_RWStepRepr_RWBetweenShapeAspect(py::module &);
void bind_RWStepRepr_RWCentreOfSymmetry(py::module &);
void bind_RWStepRepr_RWCharacterizedRepresentation(py::module &);
void bind_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp(py::module &);
void bind_RWStepRepr_RWCompositeGroupShapeAspect(py::module &);
void bind_RWStepRepr_RWCompositeShapeAspect(py::module &);
void bind_RWStepRepr_RWCompoundRepresentationItem(py::module &);
void bind_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp(py::module &);
void bind_RWStepRepr_RWConfigurationDesign(py::module &);
void bind_RWStepRepr_RWConfigurationEffectivity(py::module &);
void bind_RWStepRepr_RWConfigurationItem(py::module &);
void bind_RWStepRepr_RWConstructiveGeometryRepresentation(py::module &);
void bind_RWStepRepr_RWConstructiveGeometryRepresentationRelationship(py::module &);
void bind_RWStepRepr_RWContinuosShapeAspect(py::module &);
void bind_RWStepRepr_RWDataEnvironment(py::module &);
void bind_RWStepRepr_RWDefinitionalRepresentation(py::module &);
void bind_RWStepRepr_RWDerivedShapeAspect(py::module &);
void bind_RWStepRepr_RWDescriptiveRepresentationItem(py::module &);
void bind_RWStepRepr_RWExtension(py::module &);
void bind_RWStepRepr_RWFeatureForDatumTargetRelationship(py::module &);
void bind_RWStepRepr_RWFunctionallyDefinedTransformation(py::module &);
void bind_RWStepRepr_RWGeometricAlignment(py::module &);
void bind_RWStepRepr_RWGlobalUncertaintyAssignedContext(py::module &);
void bind_RWStepRepr_RWGlobalUnitAssignedContext(py::module &);
void bind_RWStepRepr_RWIntegerRepresentationItem(py::module &);
void bind_RWStepRepr_RWItemDefinedTransformation(py::module &);
void bind_RWStepRepr_RWMakeFromUsageOption(py::module &);
void bind_RWStepRepr_RWMappedItem(py::module &);
void bind_RWStepRepr_RWMaterialDesignation(py::module &);
void bind_RWStepRepr_RWMaterialProperty(py::module &);
void bind_RWStepRepr_RWMaterialPropertyRepresentation(py::module &);
void bind_RWStepRepr_RWMeasureRepresentationItem(py::module &);
void bind_RWStepRepr_RWParallelOffset(py::module &);
void bind_RWStepRepr_RWParametricRepresentationContext(py::module &);
void bind_RWStepRepr_RWPerpendicularTo(py::module &);
void bind_RWStepRepr_RWProductConcept(py::module &);
void bind_RWStepRepr_RWProductDefinitionShape(py::module &);
void bind_RWStepRepr_RWPropertyDefinition(py::module &);
void bind_RWStepRepr_RWPropertyDefinitionRelationship(py::module &);
void bind_RWStepRepr_RWPropertyDefinitionRepresentation(py::module &);
void bind_RWStepRepr_RWQuantifiedAssemblyComponentUsage(py::module &);
void bind_RWStepRepr_RWRepresentation(py::module &);
void bind_RWStepRepr_RWRepresentationContext(py::module &);
void bind_RWStepRepr_RWRepresentationItem(py::module &);
void bind_RWStepRepr_RWRepresentationMap(py::module &);
void bind_RWStepRepr_RWRepresentationRelationship(py::module &);
void bind_RWStepRepr_RWRepresentationRelationshipWithTransformation(py::module &);
void bind_RWStepRepr_RWReprItemAndLengthMeasureWithUnit(py::module &);
void bind_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI(py::module &);
void bind_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit(py::module &);
void bind_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI(py::module &);
void bind_RWStepRepr_RWShapeAspect(py::module &);
void bind_RWStepRepr_RWShapeAspectDerivingRelationship(py::module &);
void bind_RWStepRepr_RWShapeAspectRelationship(py::module &);
void bind_RWStepRepr_RWShapeAspectTransition(py::module &);
void bind_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation(py::module &);
void bind_RWStepRepr_RWSpecifiedHigherUsageOccurrence(py::module &);
void bind_RWStepRepr_RWStructuralResponseProperty(py::module &);
void bind_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation(py::module &);
void bind_RWStepRepr_RWTangent(py::module &);
void bind_RWStepRepr_RWValueRepresentationItem(py::module &);

PYBIND11_MODULE(RWStepRepr, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepRepr");

bind_RWStepRepr_RWAllAroundShapeAspect(mod);
bind_RWStepRepr_RWApex(mod);
bind_RWStepRepr_RWAssemblyComponentUsage(mod);
bind_RWStepRepr_RWAssemblyComponentUsageSubstitute(mod);
bind_RWStepRepr_RWBetweenShapeAspect(mod);
bind_RWStepRepr_RWCentreOfSymmetry(mod);
bind_RWStepRepr_RWCharacterizedRepresentation(mod);
bind_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp(mod);
bind_RWStepRepr_RWCompositeGroupShapeAspect(mod);
bind_RWStepRepr_RWCompositeShapeAspect(mod);
bind_RWStepRepr_RWCompoundRepresentationItem(mod);
bind_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp(mod);
bind_RWStepRepr_RWConfigurationDesign(mod);
bind_RWStepRepr_RWConfigurationEffectivity(mod);
bind_RWStepRepr_RWConfigurationItem(mod);
bind_RWStepRepr_RWConstructiveGeometryRepresentation(mod);
bind_RWStepRepr_RWConstructiveGeometryRepresentationRelationship(mod);
bind_RWStepRepr_RWContinuosShapeAspect(mod);
bind_RWStepRepr_RWDataEnvironment(mod);
bind_RWStepRepr_RWDefinitionalRepresentation(mod);
bind_RWStepRepr_RWDerivedShapeAspect(mod);
bind_RWStepRepr_RWDescriptiveRepresentationItem(mod);
bind_RWStepRepr_RWExtension(mod);
bind_RWStepRepr_RWFeatureForDatumTargetRelationship(mod);
bind_RWStepRepr_RWFunctionallyDefinedTransformation(mod);
bind_RWStepRepr_RWGeometricAlignment(mod);
bind_RWStepRepr_RWGlobalUncertaintyAssignedContext(mod);
bind_RWStepRepr_RWGlobalUnitAssignedContext(mod);
bind_RWStepRepr_RWIntegerRepresentationItem(mod);
bind_RWStepRepr_RWItemDefinedTransformation(mod);
bind_RWStepRepr_RWMakeFromUsageOption(mod);
bind_RWStepRepr_RWMappedItem(mod);
bind_RWStepRepr_RWMaterialDesignation(mod);
bind_RWStepRepr_RWMaterialProperty(mod);
bind_RWStepRepr_RWMaterialPropertyRepresentation(mod);
bind_RWStepRepr_RWMeasureRepresentationItem(mod);
bind_RWStepRepr_RWParallelOffset(mod);
bind_RWStepRepr_RWParametricRepresentationContext(mod);
bind_RWStepRepr_RWPerpendicularTo(mod);
bind_RWStepRepr_RWProductConcept(mod);
bind_RWStepRepr_RWProductDefinitionShape(mod);
bind_RWStepRepr_RWPropertyDefinition(mod);
bind_RWStepRepr_RWPropertyDefinitionRelationship(mod);
bind_RWStepRepr_RWPropertyDefinitionRepresentation(mod);
bind_RWStepRepr_RWQuantifiedAssemblyComponentUsage(mod);
bind_RWStepRepr_RWRepresentation(mod);
bind_RWStepRepr_RWRepresentationContext(mod);
bind_RWStepRepr_RWRepresentationItem(mod);
bind_RWStepRepr_RWRepresentationMap(mod);
bind_RWStepRepr_RWRepresentationRelationship(mod);
bind_RWStepRepr_RWRepresentationRelationshipWithTransformation(mod);
bind_RWStepRepr_RWReprItemAndLengthMeasureWithUnit(mod);
bind_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI(mod);
bind_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit(mod);
bind_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI(mod);
bind_RWStepRepr_RWShapeAspect(mod);
bind_RWStepRepr_RWShapeAspectDerivingRelationship(mod);
bind_RWStepRepr_RWShapeAspectRelationship(mod);
bind_RWStepRepr_RWShapeAspectTransition(mod);
bind_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation(mod);
bind_RWStepRepr_RWSpecifiedHigherUsageOccurrence(mod);
bind_RWStepRepr_RWStructuralResponseProperty(mod);
bind_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation(mod);
bind_RWStepRepr_RWTangent(mod);
bind_RWStepRepr_RWValueRepresentationItem(mod);

}
