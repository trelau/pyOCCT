#include <pyOCCT_Common.hpp>

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

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepRepr");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWAllAroundShapeAspect.hxx
	py::class_<RWStepRepr_RWAllAroundShapeAspect, std::unique_ptr<RWStepRepr_RWAllAroundShapeAspect, Deleter<RWStepRepr_RWAllAroundShapeAspect>>> cls_RWStepRepr_RWAllAroundShapeAspect(mod, "RWStepRepr_RWAllAroundShapeAspect", "Read & Write tool for AllAroundShapeAspect");
	cls_RWStepRepr_RWAllAroundShapeAspect.def(py::init<>());
	cls_RWStepRepr_RWAllAroundShapeAspect.def("ReadStep", (void (RWStepRepr_RWAllAroundShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_AllAroundShapeAspect> &) const ) &RWStepRepr_RWAllAroundShapeAspect::ReadStep, "Reads AllAroundShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWAllAroundShapeAspect.def("WriteStep", (void (RWStepRepr_RWAllAroundShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_AllAroundShapeAspect> &) const ) &RWStepRepr_RWAllAroundShapeAspect::WriteStep, "Writes AllAroundShapeAspect", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWAllAroundShapeAspect.def("Share", (void (RWStepRepr_RWAllAroundShapeAspect::*)(const opencascade::handle<StepRepr_AllAroundShapeAspect> &, Interface_EntityIterator &) const ) &RWStepRepr_RWAllAroundShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWApex.hxx
	py::class_<RWStepRepr_RWApex, std::unique_ptr<RWStepRepr_RWApex, Deleter<RWStepRepr_RWApex>>> cls_RWStepRepr_RWApex(mod, "RWStepRepr_RWApex", "Read & Write tool for Apex");
	cls_RWStepRepr_RWApex.def(py::init<>());
	cls_RWStepRepr_RWApex.def("ReadStep", (void (RWStepRepr_RWApex::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Apex> &) const ) &RWStepRepr_RWApex::ReadStep, "Reads Apex", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWApex.def("WriteStep", (void (RWStepRepr_RWApex::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Apex> &) const ) &RWStepRepr_RWApex::WriteStep, "Writes Apex", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWApex.def("Share", (void (RWStepRepr_RWApex::*)(const opencascade::handle<StepRepr_Apex> &, Interface_EntityIterator &) const ) &RWStepRepr_RWApex::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWAssemblyComponentUsage.hxx
	py::class_<RWStepRepr_RWAssemblyComponentUsage, std::unique_ptr<RWStepRepr_RWAssemblyComponentUsage, Deleter<RWStepRepr_RWAssemblyComponentUsage>>> cls_RWStepRepr_RWAssemblyComponentUsage(mod, "RWStepRepr_RWAssemblyComponentUsage", "Read & Write tool for AssemblyComponentUsage");
	cls_RWStepRepr_RWAssemblyComponentUsage.def(py::init<>());
	cls_RWStepRepr_RWAssemblyComponentUsage.def("ReadStep", (void (RWStepRepr_RWAssemblyComponentUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &) const ) &RWStepRepr_RWAssemblyComponentUsage::ReadStep, "Reads AssemblyComponentUsage", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWAssemblyComponentUsage.def("WriteStep", (void (RWStepRepr_RWAssemblyComponentUsage::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &) const ) &RWStepRepr_RWAssemblyComponentUsage::WriteStep, "Writes AssemblyComponentUsage", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWAssemblyComponentUsage.def("Share", (void (RWStepRepr_RWAssemblyComponentUsage::*)(const opencascade::handle<StepRepr_AssemblyComponentUsage> &, Interface_EntityIterator &) const ) &RWStepRepr_RWAssemblyComponentUsage::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWAssemblyComponentUsageSubstitute.hxx
	py::class_<RWStepRepr_RWAssemblyComponentUsageSubstitute, std::unique_ptr<RWStepRepr_RWAssemblyComponentUsageSubstitute, Deleter<RWStepRepr_RWAssemblyComponentUsageSubstitute>>> cls_RWStepRepr_RWAssemblyComponentUsageSubstitute(mod, "RWStepRepr_RWAssemblyComponentUsageSubstitute", "Read & Write Module for AssemblyComponentUsageSubstitute");
	cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def(py::init<>());
	cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def("ReadStep", (void (RWStepRepr_RWAssemblyComponentUsageSubstitute::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute> &) const ) &RWStepRepr_RWAssemblyComponentUsageSubstitute::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def("WriteStep", (void (RWStepRepr_RWAssemblyComponentUsageSubstitute::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute> &) const ) &RWStepRepr_RWAssemblyComponentUsageSubstitute::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWAssemblyComponentUsageSubstitute.def("Share", (void (RWStepRepr_RWAssemblyComponentUsageSubstitute::*)(const opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute> &, Interface_EntityIterator &) const ) &RWStepRepr_RWAssemblyComponentUsageSubstitute::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWBetweenShapeAspect.hxx
	py::class_<RWStepRepr_RWBetweenShapeAspect, std::unique_ptr<RWStepRepr_RWBetweenShapeAspect, Deleter<RWStepRepr_RWBetweenShapeAspect>>> cls_RWStepRepr_RWBetweenShapeAspect(mod, "RWStepRepr_RWBetweenShapeAspect", "Read & Write tool for BetweenShapeAspect");
	cls_RWStepRepr_RWBetweenShapeAspect.def(py::init<>());
	cls_RWStepRepr_RWBetweenShapeAspect.def("ReadStep", (void (RWStepRepr_RWBetweenShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_BetweenShapeAspect> &) const ) &RWStepRepr_RWBetweenShapeAspect::ReadStep, "Reads BetweenShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWBetweenShapeAspect.def("WriteStep", (void (RWStepRepr_RWBetweenShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_BetweenShapeAspect> &) const ) &RWStepRepr_RWBetweenShapeAspect::WriteStep, "Writes BetweenShapeAspect", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWBetweenShapeAspect.def("Share", (void (RWStepRepr_RWBetweenShapeAspect::*)(const opencascade::handle<StepRepr_BetweenShapeAspect> &, Interface_EntityIterator &) const ) &RWStepRepr_RWBetweenShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWCentreOfSymmetry.hxx
	py::class_<RWStepRepr_RWCentreOfSymmetry, std::unique_ptr<RWStepRepr_RWCentreOfSymmetry, Deleter<RWStepRepr_RWCentreOfSymmetry>>> cls_RWStepRepr_RWCentreOfSymmetry(mod, "RWStepRepr_RWCentreOfSymmetry", "Read & Write tool for CentreOfSymmetry");
	cls_RWStepRepr_RWCentreOfSymmetry.def(py::init<>());
	cls_RWStepRepr_RWCentreOfSymmetry.def("ReadStep", (void (RWStepRepr_RWCentreOfSymmetry::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CentreOfSymmetry> &) const ) &RWStepRepr_RWCentreOfSymmetry::ReadStep, "Reads CentreOfSymmetry", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWCentreOfSymmetry.def("WriteStep", (void (RWStepRepr_RWCentreOfSymmetry::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CentreOfSymmetry> &) const ) &RWStepRepr_RWCentreOfSymmetry::WriteStep, "Writes CentreOfSymmetry", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWCentreOfSymmetry.def("Share", (void (RWStepRepr_RWCentreOfSymmetry::*)(const opencascade::handle<StepRepr_CentreOfSymmetry> &, Interface_EntityIterator &) const ) &RWStepRepr_RWCentreOfSymmetry::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWCharacterizedRepresentation.hxx
	py::class_<RWStepRepr_RWCharacterizedRepresentation, std::unique_ptr<RWStepRepr_RWCharacterizedRepresentation, Deleter<RWStepRepr_RWCharacterizedRepresentation>>> cls_RWStepRepr_RWCharacterizedRepresentation(mod, "RWStepRepr_RWCharacterizedRepresentation", "Read & Write Module for CharacterizedRepresentation");
	cls_RWStepRepr_RWCharacterizedRepresentation.def(py::init<>());
	cls_RWStepRepr_RWCharacterizedRepresentation.def("ReadStep", (void (RWStepRepr_RWCharacterizedRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CharacterizedRepresentation> &) const ) &RWStepRepr_RWCharacterizedRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWCharacterizedRepresentation.def("WriteStep", (void (RWStepRepr_RWCharacterizedRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CharacterizedRepresentation> &) const ) &RWStepRepr_RWCharacterizedRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWCharacterizedRepresentation.def("Share", (void (RWStepRepr_RWCharacterizedRepresentation::*)(const opencascade::handle<StepRepr_CharacterizedRepresentation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWCharacterizedRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.hxx
	py::class_<RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp, std::unique_ptr<RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp, Deleter<RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp>>> cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp(mod, "RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp", "Read & Write Module for CompGroupShAspAndCompShAspAndDatumFeatAndShAsp");
	cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def(py::init<>());
	cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def("ReadStep", (void (RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp> &) const ) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def("WriteStep", (void (RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp> &) const ) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def("Share", (void (RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::*)(const opencascade::handle<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp> &, Interface_EntityIterator &) const ) &RWStepRepr_RWCompGroupShAspAndCompShAspAndDatumFeatAndShAsp::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWCompositeGroupShapeAspect.hxx
	py::class_<RWStepRepr_RWCompositeGroupShapeAspect, std::unique_ptr<RWStepRepr_RWCompositeGroupShapeAspect, Deleter<RWStepRepr_RWCompositeGroupShapeAspect>>> cls_RWStepRepr_RWCompositeGroupShapeAspect(mod, "RWStepRepr_RWCompositeGroupShapeAspect", "Read & Write tool for CompositeGroupShapeAspect");
	cls_RWStepRepr_RWCompositeGroupShapeAspect.def(py::init<>());
	cls_RWStepRepr_RWCompositeGroupShapeAspect.def("ReadStep", (void (RWStepRepr_RWCompositeGroupShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompositeGroupShapeAspect> &) const ) &RWStepRepr_RWCompositeGroupShapeAspect::ReadStep, "Reads CompositeGroupShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWCompositeGroupShapeAspect.def("WriteStep", (void (RWStepRepr_RWCompositeGroupShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompositeGroupShapeAspect> &) const ) &RWStepRepr_RWCompositeGroupShapeAspect::WriteStep, "Writes CompositeGroupShapeAspect", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWCompositeGroupShapeAspect.def("Share", (void (RWStepRepr_RWCompositeGroupShapeAspect::*)(const opencascade::handle<StepRepr_CompositeGroupShapeAspect> &, Interface_EntityIterator &) const ) &RWStepRepr_RWCompositeGroupShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWCompositeShapeAspect.hxx
	py::class_<RWStepRepr_RWCompositeShapeAspect, std::unique_ptr<RWStepRepr_RWCompositeShapeAspect, Deleter<RWStepRepr_RWCompositeShapeAspect>>> cls_RWStepRepr_RWCompositeShapeAspect(mod, "RWStepRepr_RWCompositeShapeAspect", "Read & Write tool for CompositeShapeAspect");
	cls_RWStepRepr_RWCompositeShapeAspect.def(py::init<>());
	cls_RWStepRepr_RWCompositeShapeAspect.def("ReadStep", (void (RWStepRepr_RWCompositeShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompositeShapeAspect> &) const ) &RWStepRepr_RWCompositeShapeAspect::ReadStep, "Reads CompositeShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWCompositeShapeAspect.def("WriteStep", (void (RWStepRepr_RWCompositeShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompositeShapeAspect> &) const ) &RWStepRepr_RWCompositeShapeAspect::WriteStep, "Writes CompositeShapeAspect", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWCompositeShapeAspect.def("Share", (void (RWStepRepr_RWCompositeShapeAspect::*)(const opencascade::handle<StepRepr_CompositeShapeAspect> &, Interface_EntityIterator &) const ) &RWStepRepr_RWCompositeShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWCompoundRepresentationItem.hxx
	py::class_<RWStepRepr_RWCompoundRepresentationItem, std::unique_ptr<RWStepRepr_RWCompoundRepresentationItem, Deleter<RWStepRepr_RWCompoundRepresentationItem>>> cls_RWStepRepr_RWCompoundRepresentationItem(mod, "RWStepRepr_RWCompoundRepresentationItem", "Read & Write Module for CompoundRepresentationItem");
	cls_RWStepRepr_RWCompoundRepresentationItem.def(py::init<>());
	cls_RWStepRepr_RWCompoundRepresentationItem.def("ReadStep", (void (RWStepRepr_RWCompoundRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompoundRepresentationItem> &) const ) &RWStepRepr_RWCompoundRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWCompoundRepresentationItem.def("WriteStep", (void (RWStepRepr_RWCompoundRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompoundRepresentationItem> &) const ) &RWStepRepr_RWCompoundRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWCompoundRepresentationItem.def("Share", (void (RWStepRepr_RWCompoundRepresentationItem::*)(const opencascade::handle<StepRepr_CompoundRepresentationItem> &, Interface_EntityIterator &) const ) &RWStepRepr_RWCompoundRepresentationItem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.hxx
	py::class_<RWStepRepr_RWCompShAspAndDatumFeatAndShAsp, std::unique_ptr<RWStepRepr_RWCompShAspAndDatumFeatAndShAsp, Deleter<RWStepRepr_RWCompShAspAndDatumFeatAndShAsp>>> cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp(mod, "RWStepRepr_RWCompShAspAndDatumFeatAndShAsp", "Read & Write Module for CompShAspAndDatumFeatAndShAsp");
	cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def(py::init<>());
	cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def("ReadStep", (void (RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_CompShAspAndDatumFeatAndShAsp> &) const ) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def("WriteStep", (void (RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_CompShAspAndDatumFeatAndShAsp> &) const ) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWCompShAspAndDatumFeatAndShAsp.def("Share", (void (RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::*)(const opencascade::handle<StepRepr_CompShAspAndDatumFeatAndShAsp> &, Interface_EntityIterator &) const ) &RWStepRepr_RWCompShAspAndDatumFeatAndShAsp::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWConfigurationDesign.hxx
	py::class_<RWStepRepr_RWConfigurationDesign, std::unique_ptr<RWStepRepr_RWConfigurationDesign, Deleter<RWStepRepr_RWConfigurationDesign>>> cls_RWStepRepr_RWConfigurationDesign(mod, "RWStepRepr_RWConfigurationDesign", "Read & Write tool for ConfigurationDesign");
	cls_RWStepRepr_RWConfigurationDesign.def(py::init<>());
	cls_RWStepRepr_RWConfigurationDesign.def("ReadStep", (void (RWStepRepr_RWConfigurationDesign::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConfigurationDesign> &) const ) &RWStepRepr_RWConfigurationDesign::ReadStep, "Reads ConfigurationDesign", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWConfigurationDesign.def("WriteStep", (void (RWStepRepr_RWConfigurationDesign::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConfigurationDesign> &) const ) &RWStepRepr_RWConfigurationDesign::WriteStep, "Writes ConfigurationDesign", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWConfigurationDesign.def("Share", (void (RWStepRepr_RWConfigurationDesign::*)(const opencascade::handle<StepRepr_ConfigurationDesign> &, Interface_EntityIterator &) const ) &RWStepRepr_RWConfigurationDesign::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWConfigurationEffectivity.hxx
	py::class_<RWStepRepr_RWConfigurationEffectivity, std::unique_ptr<RWStepRepr_RWConfigurationEffectivity, Deleter<RWStepRepr_RWConfigurationEffectivity>>> cls_RWStepRepr_RWConfigurationEffectivity(mod, "RWStepRepr_RWConfigurationEffectivity", "Read & Write tool for ConfigurationEffectivity");
	cls_RWStepRepr_RWConfigurationEffectivity.def(py::init<>());
	cls_RWStepRepr_RWConfigurationEffectivity.def("ReadStep", (void (RWStepRepr_RWConfigurationEffectivity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConfigurationEffectivity> &) const ) &RWStepRepr_RWConfigurationEffectivity::ReadStep, "Reads ConfigurationEffectivity", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWConfigurationEffectivity.def("WriteStep", (void (RWStepRepr_RWConfigurationEffectivity::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConfigurationEffectivity> &) const ) &RWStepRepr_RWConfigurationEffectivity::WriteStep, "Writes ConfigurationEffectivity", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWConfigurationEffectivity.def("Share", (void (RWStepRepr_RWConfigurationEffectivity::*)(const opencascade::handle<StepRepr_ConfigurationEffectivity> &, Interface_EntityIterator &) const ) &RWStepRepr_RWConfigurationEffectivity::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWConfigurationItem.hxx
	py::class_<RWStepRepr_RWConfigurationItem, std::unique_ptr<RWStepRepr_RWConfigurationItem, Deleter<RWStepRepr_RWConfigurationItem>>> cls_RWStepRepr_RWConfigurationItem(mod, "RWStepRepr_RWConfigurationItem", "Read & Write tool for ConfigurationItem");
	cls_RWStepRepr_RWConfigurationItem.def(py::init<>());
	cls_RWStepRepr_RWConfigurationItem.def("ReadStep", (void (RWStepRepr_RWConfigurationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConfigurationItem> &) const ) &RWStepRepr_RWConfigurationItem::ReadStep, "Reads ConfigurationItem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWConfigurationItem.def("WriteStep", (void (RWStepRepr_RWConfigurationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConfigurationItem> &) const ) &RWStepRepr_RWConfigurationItem::WriteStep, "Writes ConfigurationItem", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWConfigurationItem.def("Share", (void (RWStepRepr_RWConfigurationItem::*)(const opencascade::handle<StepRepr_ConfigurationItem> &, Interface_EntityIterator &) const ) &RWStepRepr_RWConfigurationItem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWConstructiveGeometryRepresentation.hxx
	py::class_<RWStepRepr_RWConstructiveGeometryRepresentation, std::unique_ptr<RWStepRepr_RWConstructiveGeometryRepresentation, Deleter<RWStepRepr_RWConstructiveGeometryRepresentation>>> cls_RWStepRepr_RWConstructiveGeometryRepresentation(mod, "RWStepRepr_RWConstructiveGeometryRepresentation", "Read & Write Module for ConstructiveGeometryRepresentation");
	cls_RWStepRepr_RWConstructiveGeometryRepresentation.def(py::init<>());
	cls_RWStepRepr_RWConstructiveGeometryRepresentation.def("ReadStep", (void (RWStepRepr_RWConstructiveGeometryRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConstructiveGeometryRepresentation> &) const ) &RWStepRepr_RWConstructiveGeometryRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWConstructiveGeometryRepresentation.def("WriteStep", (void (RWStepRepr_RWConstructiveGeometryRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConstructiveGeometryRepresentation> &) const ) &RWStepRepr_RWConstructiveGeometryRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWConstructiveGeometryRepresentation.def("Share", (void (RWStepRepr_RWConstructiveGeometryRepresentation::*)(const opencascade::handle<StepRepr_ConstructiveGeometryRepresentation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWConstructiveGeometryRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWConstructiveGeometryRepresentationRelationship.hxx
	py::class_<RWStepRepr_RWConstructiveGeometryRepresentationRelationship, std::unique_ptr<RWStepRepr_RWConstructiveGeometryRepresentationRelationship, Deleter<RWStepRepr_RWConstructiveGeometryRepresentationRelationship>>> cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship(mod, "RWStepRepr_RWConstructiveGeometryRepresentationRelationship", "Read & Write Module for ConstructiveGeometryRepresentationRelationship");
	cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def(py::init<>());
	cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def("ReadStep", (void (RWStepRepr_RWConstructiveGeometryRepresentationRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConstructiveGeometryRepresentationRelationship> &) const ) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def("WriteStep", (void (RWStepRepr_RWConstructiveGeometryRepresentationRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConstructiveGeometryRepresentationRelationship> &) const ) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWConstructiveGeometryRepresentationRelationship.def("Share", (void (RWStepRepr_RWConstructiveGeometryRepresentationRelationship::*)(const opencascade::handle<StepRepr_ConstructiveGeometryRepresentationRelationship> &, Interface_EntityIterator &) const ) &RWStepRepr_RWConstructiveGeometryRepresentationRelationship::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWContinuosShapeAspect.hxx
	py::class_<RWStepRepr_RWContinuosShapeAspect, std::unique_ptr<RWStepRepr_RWContinuosShapeAspect, Deleter<RWStepRepr_RWContinuosShapeAspect>>> cls_RWStepRepr_RWContinuosShapeAspect(mod, "RWStepRepr_RWContinuosShapeAspect", "Read & Write tool for ContinuosShapeAspect");
	cls_RWStepRepr_RWContinuosShapeAspect.def(py::init<>());
	cls_RWStepRepr_RWContinuosShapeAspect.def("ReadStep", (void (RWStepRepr_RWContinuosShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ContinuosShapeAspect> &) const ) &RWStepRepr_RWContinuosShapeAspect::ReadStep, "Reads ContinuosShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWContinuosShapeAspect.def("WriteStep", (void (RWStepRepr_RWContinuosShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ContinuosShapeAspect> &) const ) &RWStepRepr_RWContinuosShapeAspect::WriteStep, "Writes ContinuosShapeAspect", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWContinuosShapeAspect.def("Share", (void (RWStepRepr_RWContinuosShapeAspect::*)(const opencascade::handle<StepRepr_ContinuosShapeAspect> &, Interface_EntityIterator &) const ) &RWStepRepr_RWContinuosShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWDataEnvironment.hxx
	py::class_<RWStepRepr_RWDataEnvironment, std::unique_ptr<RWStepRepr_RWDataEnvironment, Deleter<RWStepRepr_RWDataEnvironment>>> cls_RWStepRepr_RWDataEnvironment(mod, "RWStepRepr_RWDataEnvironment", "Read & Write tool for DataEnvironment");
	cls_RWStepRepr_RWDataEnvironment.def(py::init<>());
	cls_RWStepRepr_RWDataEnvironment.def("ReadStep", (void (RWStepRepr_RWDataEnvironment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_DataEnvironment> &) const ) &RWStepRepr_RWDataEnvironment::ReadStep, "Reads DataEnvironment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWDataEnvironment.def("WriteStep", (void (RWStepRepr_RWDataEnvironment::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_DataEnvironment> &) const ) &RWStepRepr_RWDataEnvironment::WriteStep, "Writes DataEnvironment", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWDataEnvironment.def("Share", (void (RWStepRepr_RWDataEnvironment::*)(const opencascade::handle<StepRepr_DataEnvironment> &, Interface_EntityIterator &) const ) &RWStepRepr_RWDataEnvironment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWDefinitionalRepresentation.hxx
	py::class_<RWStepRepr_RWDefinitionalRepresentation, std::unique_ptr<RWStepRepr_RWDefinitionalRepresentation, Deleter<RWStepRepr_RWDefinitionalRepresentation>>> cls_RWStepRepr_RWDefinitionalRepresentation(mod, "RWStepRepr_RWDefinitionalRepresentation", "Read & Write Module for DefinitionalRepresentation");
	cls_RWStepRepr_RWDefinitionalRepresentation.def(py::init<>());
	cls_RWStepRepr_RWDefinitionalRepresentation.def("ReadStep", (void (RWStepRepr_RWDefinitionalRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &) const ) &RWStepRepr_RWDefinitionalRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWDefinitionalRepresentation.def("WriteStep", (void (RWStepRepr_RWDefinitionalRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &) const ) &RWStepRepr_RWDefinitionalRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWDefinitionalRepresentation.def("Share", (void (RWStepRepr_RWDefinitionalRepresentation::*)(const opencascade::handle<StepRepr_DefinitionalRepresentation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWDefinitionalRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWDerivedShapeAspect.hxx
	py::class_<RWStepRepr_RWDerivedShapeAspect, std::unique_ptr<RWStepRepr_RWDerivedShapeAspect, Deleter<RWStepRepr_RWDerivedShapeAspect>>> cls_RWStepRepr_RWDerivedShapeAspect(mod, "RWStepRepr_RWDerivedShapeAspect", "Read & Write tool for DerivedShapeAspect");
	cls_RWStepRepr_RWDerivedShapeAspect.def(py::init<>());
	cls_RWStepRepr_RWDerivedShapeAspect.def("ReadStep", (void (RWStepRepr_RWDerivedShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_DerivedShapeAspect> &) const ) &RWStepRepr_RWDerivedShapeAspect::ReadStep, "Reads DerivedShapeAspect", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWDerivedShapeAspect.def("WriteStep", (void (RWStepRepr_RWDerivedShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_DerivedShapeAspect> &) const ) &RWStepRepr_RWDerivedShapeAspect::WriteStep, "Writes DerivedShapeAspect", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWDerivedShapeAspect.def("Share", (void (RWStepRepr_RWDerivedShapeAspect::*)(const opencascade::handle<StepRepr_DerivedShapeAspect> &, Interface_EntityIterator &) const ) &RWStepRepr_RWDerivedShapeAspect::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWDescriptiveRepresentationItem.hxx
	py::class_<RWStepRepr_RWDescriptiveRepresentationItem, std::unique_ptr<RWStepRepr_RWDescriptiveRepresentationItem, Deleter<RWStepRepr_RWDescriptiveRepresentationItem>>> cls_RWStepRepr_RWDescriptiveRepresentationItem(mod, "RWStepRepr_RWDescriptiveRepresentationItem", "Read & Write Module for DescriptiveRepresentationItem");
	cls_RWStepRepr_RWDescriptiveRepresentationItem.def(py::init<>());
	cls_RWStepRepr_RWDescriptiveRepresentationItem.def("ReadStep", (void (RWStepRepr_RWDescriptiveRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_DescriptiveRepresentationItem> &) const ) &RWStepRepr_RWDescriptiveRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWDescriptiveRepresentationItem.def("WriteStep", (void (RWStepRepr_RWDescriptiveRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_DescriptiveRepresentationItem> &) const ) &RWStepRepr_RWDescriptiveRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWExtension.hxx
	py::class_<RWStepRepr_RWExtension, std::unique_ptr<RWStepRepr_RWExtension, Deleter<RWStepRepr_RWExtension>>> cls_RWStepRepr_RWExtension(mod, "RWStepRepr_RWExtension", "Read & Write tool for Extension");
	cls_RWStepRepr_RWExtension.def(py::init<>());
	cls_RWStepRepr_RWExtension.def("ReadStep", (void (RWStepRepr_RWExtension::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Extension> &) const ) &RWStepRepr_RWExtension::ReadStep, "Reads Extension", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWExtension.def("WriteStep", (void (RWStepRepr_RWExtension::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Extension> &) const ) &RWStepRepr_RWExtension::WriteStep, "Writes Extension", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWExtension.def("Share", (void (RWStepRepr_RWExtension::*)(const opencascade::handle<StepRepr_Extension> &, Interface_EntityIterator &) const ) &RWStepRepr_RWExtension::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWFeatureForDatumTargetRelationship.hxx
	py::class_<RWStepRepr_RWFeatureForDatumTargetRelationship, std::unique_ptr<RWStepRepr_RWFeatureForDatumTargetRelationship, Deleter<RWStepRepr_RWFeatureForDatumTargetRelationship>>> cls_RWStepRepr_RWFeatureForDatumTargetRelationship(mod, "RWStepRepr_RWFeatureForDatumTargetRelationship", "Read & Write tool for FeatureForDatumTargetRelationship");
	cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def(py::init<>());
	cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("ReadStep", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &) const ) &RWStepRepr_RWFeatureForDatumTargetRelationship::ReadStep, "Reads ShapeAspectRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("WriteStep", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &) const ) &RWStepRepr_RWFeatureForDatumTargetRelationship::WriteStep, "Writes ShapeAspectRelationship", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("Share", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &, Interface_EntityIterator &) const ) &RWStepRepr_RWFeatureForDatumTargetRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWFunctionallyDefinedTransformation.hxx
	py::class_<RWStepRepr_RWFunctionallyDefinedTransformation, std::unique_ptr<RWStepRepr_RWFunctionallyDefinedTransformation, Deleter<RWStepRepr_RWFunctionallyDefinedTransformation>>> cls_RWStepRepr_RWFunctionallyDefinedTransformation(mod, "RWStepRepr_RWFunctionallyDefinedTransformation", "Read & Write Module for FunctionallyDefinedTransformation");
	cls_RWStepRepr_RWFunctionallyDefinedTransformation.def(py::init<>());
	cls_RWStepRepr_RWFunctionallyDefinedTransformation.def("ReadStep", (void (RWStepRepr_RWFunctionallyDefinedTransformation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_FunctionallyDefinedTransformation> &) const ) &RWStepRepr_RWFunctionallyDefinedTransformation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWFunctionallyDefinedTransformation.def("WriteStep", (void (RWStepRepr_RWFunctionallyDefinedTransformation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_FunctionallyDefinedTransformation> &) const ) &RWStepRepr_RWFunctionallyDefinedTransformation::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWGeometricAlignment.hxx
	py::class_<RWStepRepr_RWGeometricAlignment, std::unique_ptr<RWStepRepr_RWGeometricAlignment, Deleter<RWStepRepr_RWGeometricAlignment>>> cls_RWStepRepr_RWGeometricAlignment(mod, "RWStepRepr_RWGeometricAlignment", "Read & Write tool for GeometricAlignment");
	cls_RWStepRepr_RWGeometricAlignment.def(py::init<>());
	cls_RWStepRepr_RWGeometricAlignment.def("ReadStep", (void (RWStepRepr_RWGeometricAlignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_GeometricAlignment> &) const ) &RWStepRepr_RWGeometricAlignment::ReadStep, "Reads GeometricAlignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWGeometricAlignment.def("WriteStep", (void (RWStepRepr_RWGeometricAlignment::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_GeometricAlignment> &) const ) &RWStepRepr_RWGeometricAlignment::WriteStep, "Writes GeometricAlignment", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWGeometricAlignment.def("Share", (void (RWStepRepr_RWGeometricAlignment::*)(const opencascade::handle<StepRepr_GeometricAlignment> &, Interface_EntityIterator &) const ) &RWStepRepr_RWGeometricAlignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWGlobalUncertaintyAssignedContext.hxx
	py::class_<RWStepRepr_RWGlobalUncertaintyAssignedContext, std::unique_ptr<RWStepRepr_RWGlobalUncertaintyAssignedContext, Deleter<RWStepRepr_RWGlobalUncertaintyAssignedContext>>> cls_RWStepRepr_RWGlobalUncertaintyAssignedContext(mod, "RWStepRepr_RWGlobalUncertaintyAssignedContext", "Read & Write Module for GlobalUncertaintyAssignedContext");
	cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def(py::init<>());
	cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def("ReadStep", (void (RWStepRepr_RWGlobalUncertaintyAssignedContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &) const ) &RWStepRepr_RWGlobalUncertaintyAssignedContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def("WriteStep", (void (RWStepRepr_RWGlobalUncertaintyAssignedContext::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &) const ) &RWStepRepr_RWGlobalUncertaintyAssignedContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWGlobalUncertaintyAssignedContext.def("Share", (void (RWStepRepr_RWGlobalUncertaintyAssignedContext::*)(const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &, Interface_EntityIterator &) const ) &RWStepRepr_RWGlobalUncertaintyAssignedContext::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWGlobalUnitAssignedContext.hxx
	py::class_<RWStepRepr_RWGlobalUnitAssignedContext, std::unique_ptr<RWStepRepr_RWGlobalUnitAssignedContext, Deleter<RWStepRepr_RWGlobalUnitAssignedContext>>> cls_RWStepRepr_RWGlobalUnitAssignedContext(mod, "RWStepRepr_RWGlobalUnitAssignedContext", "Read & Write Module for GlobalUnitAssignedContext");
	cls_RWStepRepr_RWGlobalUnitAssignedContext.def(py::init<>());
	cls_RWStepRepr_RWGlobalUnitAssignedContext.def("ReadStep", (void (RWStepRepr_RWGlobalUnitAssignedContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &) const ) &RWStepRepr_RWGlobalUnitAssignedContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWGlobalUnitAssignedContext.def("WriteStep", (void (RWStepRepr_RWGlobalUnitAssignedContext::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &) const ) &RWStepRepr_RWGlobalUnitAssignedContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWGlobalUnitAssignedContext.def("Share", (void (RWStepRepr_RWGlobalUnitAssignedContext::*)(const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &, Interface_EntityIterator &) const ) &RWStepRepr_RWGlobalUnitAssignedContext::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWIntegerRepresentationItem.hxx
	py::class_<RWStepRepr_RWIntegerRepresentationItem, std::unique_ptr<RWStepRepr_RWIntegerRepresentationItem, Deleter<RWStepRepr_RWIntegerRepresentationItem>>> cls_RWStepRepr_RWIntegerRepresentationItem(mod, "RWStepRepr_RWIntegerRepresentationItem", "Read & Write Module for IntegerRepresentationItem");
	cls_RWStepRepr_RWIntegerRepresentationItem.def(py::init<>());
	cls_RWStepRepr_RWIntegerRepresentationItem.def("ReadStep", (void (RWStepRepr_RWIntegerRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_IntegerRepresentationItem> &) const ) &RWStepRepr_RWIntegerRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWIntegerRepresentationItem.def("WriteStep", (void (RWStepRepr_RWIntegerRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_IntegerRepresentationItem> &) const ) &RWStepRepr_RWIntegerRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWItemDefinedTransformation.hxx
	py::class_<RWStepRepr_RWItemDefinedTransformation, std::unique_ptr<RWStepRepr_RWItemDefinedTransformation, Deleter<RWStepRepr_RWItemDefinedTransformation>>> cls_RWStepRepr_RWItemDefinedTransformation(mod, "RWStepRepr_RWItemDefinedTransformation", "Read & Write Module for ItemDefinedTransformation");
	cls_RWStepRepr_RWItemDefinedTransformation.def(py::init<>());
	cls_RWStepRepr_RWItemDefinedTransformation.def("ReadStep", (void (RWStepRepr_RWItemDefinedTransformation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ItemDefinedTransformation> &) const ) &RWStepRepr_RWItemDefinedTransformation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWItemDefinedTransformation.def("WriteStep", (void (RWStepRepr_RWItemDefinedTransformation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ItemDefinedTransformation> &) const ) &RWStepRepr_RWItemDefinedTransformation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWItemDefinedTransformation.def("Share", (void (RWStepRepr_RWItemDefinedTransformation::*)(const opencascade::handle<StepRepr_ItemDefinedTransformation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWItemDefinedTransformation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWMakeFromUsageOption.hxx
	py::class_<RWStepRepr_RWMakeFromUsageOption, std::unique_ptr<RWStepRepr_RWMakeFromUsageOption, Deleter<RWStepRepr_RWMakeFromUsageOption>>> cls_RWStepRepr_RWMakeFromUsageOption(mod, "RWStepRepr_RWMakeFromUsageOption", "Read & Write tool for MakeFromUsageOption");
	cls_RWStepRepr_RWMakeFromUsageOption.def(py::init<>());
	cls_RWStepRepr_RWMakeFromUsageOption.def("ReadStep", (void (RWStepRepr_RWMakeFromUsageOption::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MakeFromUsageOption> &) const ) &RWStepRepr_RWMakeFromUsageOption::ReadStep, "Reads MakeFromUsageOption", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWMakeFromUsageOption.def("WriteStep", (void (RWStepRepr_RWMakeFromUsageOption::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MakeFromUsageOption> &) const ) &RWStepRepr_RWMakeFromUsageOption::WriteStep, "Writes MakeFromUsageOption", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWMakeFromUsageOption.def("Share", (void (RWStepRepr_RWMakeFromUsageOption::*)(const opencascade::handle<StepRepr_MakeFromUsageOption> &, Interface_EntityIterator &) const ) &RWStepRepr_RWMakeFromUsageOption::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWMappedItem.hxx
	py::class_<RWStepRepr_RWMappedItem, std::unique_ptr<RWStepRepr_RWMappedItem, Deleter<RWStepRepr_RWMappedItem>>> cls_RWStepRepr_RWMappedItem(mod, "RWStepRepr_RWMappedItem", "Read & Write Module for MappedItem");
	cls_RWStepRepr_RWMappedItem.def(py::init<>());
	cls_RWStepRepr_RWMappedItem.def("ReadStep", (void (RWStepRepr_RWMappedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MappedItem> &) const ) &RWStepRepr_RWMappedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWMappedItem.def("WriteStep", (void (RWStepRepr_RWMappedItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MappedItem> &) const ) &RWStepRepr_RWMappedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWMappedItem.def("Share", (void (RWStepRepr_RWMappedItem::*)(const opencascade::handle<StepRepr_MappedItem> &, Interface_EntityIterator &) const ) &RWStepRepr_RWMappedItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWMaterialDesignation.hxx
	py::class_<RWStepRepr_RWMaterialDesignation, std::unique_ptr<RWStepRepr_RWMaterialDesignation, Deleter<RWStepRepr_RWMaterialDesignation>>> cls_RWStepRepr_RWMaterialDesignation(mod, "RWStepRepr_RWMaterialDesignation", "Read & Write Module for MaterialDesignation");
	cls_RWStepRepr_RWMaterialDesignation.def(py::init<>());
	cls_RWStepRepr_RWMaterialDesignation.def("ReadStep", (void (RWStepRepr_RWMaterialDesignation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MaterialDesignation> &) const ) &RWStepRepr_RWMaterialDesignation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWMaterialDesignation.def("WriteStep", (void (RWStepRepr_RWMaterialDesignation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MaterialDesignation> &) const ) &RWStepRepr_RWMaterialDesignation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWMaterialDesignation.def("Share", (void (RWStepRepr_RWMaterialDesignation::*)(const opencascade::handle<StepRepr_MaterialDesignation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWMaterialDesignation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWMaterialProperty.hxx
	py::class_<RWStepRepr_RWMaterialProperty, std::unique_ptr<RWStepRepr_RWMaterialProperty, Deleter<RWStepRepr_RWMaterialProperty>>> cls_RWStepRepr_RWMaterialProperty(mod, "RWStepRepr_RWMaterialProperty", "Read & Write tool for MaterialProperty");
	cls_RWStepRepr_RWMaterialProperty.def(py::init<>());
	cls_RWStepRepr_RWMaterialProperty.def("ReadStep", (void (RWStepRepr_RWMaterialProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MaterialProperty> &) const ) &RWStepRepr_RWMaterialProperty::ReadStep, "Reads MaterialProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWMaterialProperty.def("WriteStep", (void (RWStepRepr_RWMaterialProperty::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MaterialProperty> &) const ) &RWStepRepr_RWMaterialProperty::WriteStep, "Writes MaterialProperty", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWMaterialProperty.def("Share", (void (RWStepRepr_RWMaterialProperty::*)(const opencascade::handle<StepRepr_MaterialProperty> &, Interface_EntityIterator &) const ) &RWStepRepr_RWMaterialProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWMaterialPropertyRepresentation.hxx
	py::class_<RWStepRepr_RWMaterialPropertyRepresentation, std::unique_ptr<RWStepRepr_RWMaterialPropertyRepresentation, Deleter<RWStepRepr_RWMaterialPropertyRepresentation>>> cls_RWStepRepr_RWMaterialPropertyRepresentation(mod, "RWStepRepr_RWMaterialPropertyRepresentation", "Read & Write tool for MaterialPropertyRepresentation");
	cls_RWStepRepr_RWMaterialPropertyRepresentation.def(py::init<>());
	cls_RWStepRepr_RWMaterialPropertyRepresentation.def("ReadStep", (void (RWStepRepr_RWMaterialPropertyRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MaterialPropertyRepresentation> &) const ) &RWStepRepr_RWMaterialPropertyRepresentation::ReadStep, "Reads MaterialPropertyRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWMaterialPropertyRepresentation.def("WriteStep", (void (RWStepRepr_RWMaterialPropertyRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MaterialPropertyRepresentation> &) const ) &RWStepRepr_RWMaterialPropertyRepresentation::WriteStep, "Writes MaterialPropertyRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWMaterialPropertyRepresentation.def("Share", (void (RWStepRepr_RWMaterialPropertyRepresentation::*)(const opencascade::handle<StepRepr_MaterialPropertyRepresentation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWMaterialPropertyRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWMeasureRepresentationItem.hxx
	py::class_<RWStepRepr_RWMeasureRepresentationItem, std::unique_ptr<RWStepRepr_RWMeasureRepresentationItem, Deleter<RWStepRepr_RWMeasureRepresentationItem>>> cls_RWStepRepr_RWMeasureRepresentationItem(mod, "RWStepRepr_RWMeasureRepresentationItem", "Read & Write Module for MeasureRepresentationItem");
	cls_RWStepRepr_RWMeasureRepresentationItem.def(py::init<>());
	cls_RWStepRepr_RWMeasureRepresentationItem.def("ReadStep", (void (RWStepRepr_RWMeasureRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MeasureRepresentationItem> &) const ) &RWStepRepr_RWMeasureRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWMeasureRepresentationItem.def("WriteStep", (void (RWStepRepr_RWMeasureRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MeasureRepresentationItem> &) const ) &RWStepRepr_RWMeasureRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWMeasureRepresentationItem.def("Share", (void (RWStepRepr_RWMeasureRepresentationItem::*)(const opencascade::handle<StepRepr_MeasureRepresentationItem> &, Interface_EntityIterator &) const ) &RWStepRepr_RWMeasureRepresentationItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWParallelOffset.hxx
	py::class_<RWStepRepr_RWParallelOffset, std::unique_ptr<RWStepRepr_RWParallelOffset, Deleter<RWStepRepr_RWParallelOffset>>> cls_RWStepRepr_RWParallelOffset(mod, "RWStepRepr_RWParallelOffset", "Read & Write tool for ParallelOffset");
	cls_RWStepRepr_RWParallelOffset.def(py::init<>());
	cls_RWStepRepr_RWParallelOffset.def("ReadStep", (void (RWStepRepr_RWParallelOffset::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ParallelOffset> &) const ) &RWStepRepr_RWParallelOffset::ReadStep, "Reads ParallelOffset", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWParallelOffset.def("WriteStep", (void (RWStepRepr_RWParallelOffset::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ParallelOffset> &) const ) &RWStepRepr_RWParallelOffset::WriteStep, "Writes ParallelOffset", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWParallelOffset.def("Share", (void (RWStepRepr_RWParallelOffset::*)(const opencascade::handle<StepRepr_ParallelOffset> &, Interface_EntityIterator &) const ) &RWStepRepr_RWParallelOffset::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWParametricRepresentationContext.hxx
	py::class_<RWStepRepr_RWParametricRepresentationContext, std::unique_ptr<RWStepRepr_RWParametricRepresentationContext, Deleter<RWStepRepr_RWParametricRepresentationContext>>> cls_RWStepRepr_RWParametricRepresentationContext(mod, "RWStepRepr_RWParametricRepresentationContext", "Read & Write Module for ParametricRepresentationContext");
	cls_RWStepRepr_RWParametricRepresentationContext.def(py::init<>());
	cls_RWStepRepr_RWParametricRepresentationContext.def("ReadStep", (void (RWStepRepr_RWParametricRepresentationContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ParametricRepresentationContext> &) const ) &RWStepRepr_RWParametricRepresentationContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWParametricRepresentationContext.def("WriteStep", (void (RWStepRepr_RWParametricRepresentationContext::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ParametricRepresentationContext> &) const ) &RWStepRepr_RWParametricRepresentationContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWPerpendicularTo.hxx
	py::class_<RWStepRepr_RWPerpendicularTo, std::unique_ptr<RWStepRepr_RWPerpendicularTo, Deleter<RWStepRepr_RWPerpendicularTo>>> cls_RWStepRepr_RWPerpendicularTo(mod, "RWStepRepr_RWPerpendicularTo", "Read & Write tool for PerpendicularTo");
	cls_RWStepRepr_RWPerpendicularTo.def(py::init<>());
	cls_RWStepRepr_RWPerpendicularTo.def("ReadStep", (void (RWStepRepr_RWPerpendicularTo::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PerpendicularTo> &) const ) &RWStepRepr_RWPerpendicularTo::ReadStep, "Reads PerpendicularTo", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWPerpendicularTo.def("WriteStep", (void (RWStepRepr_RWPerpendicularTo::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PerpendicularTo> &) const ) &RWStepRepr_RWPerpendicularTo::WriteStep, "Writes PerpendicularTo", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWPerpendicularTo.def("Share", (void (RWStepRepr_RWPerpendicularTo::*)(const opencascade::handle<StepRepr_PerpendicularTo> &, Interface_EntityIterator &) const ) &RWStepRepr_RWPerpendicularTo::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWProductConcept.hxx
	py::class_<RWStepRepr_RWProductConcept, std::unique_ptr<RWStepRepr_RWProductConcept, Deleter<RWStepRepr_RWProductConcept>>> cls_RWStepRepr_RWProductConcept(mod, "RWStepRepr_RWProductConcept", "Read & Write tool for ProductConcept");
	cls_RWStepRepr_RWProductConcept.def(py::init<>());
	cls_RWStepRepr_RWProductConcept.def("ReadStep", (void (RWStepRepr_RWProductConcept::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ProductConcept> &) const ) &RWStepRepr_RWProductConcept::ReadStep, "Reads ProductConcept", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWProductConcept.def("WriteStep", (void (RWStepRepr_RWProductConcept::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ProductConcept> &) const ) &RWStepRepr_RWProductConcept::WriteStep, "Writes ProductConcept", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWProductConcept.def("Share", (void (RWStepRepr_RWProductConcept::*)(const opencascade::handle<StepRepr_ProductConcept> &, Interface_EntityIterator &) const ) &RWStepRepr_RWProductConcept::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWProductDefinitionShape.hxx
	py::class_<RWStepRepr_RWProductDefinitionShape, std::unique_ptr<RWStepRepr_RWProductDefinitionShape, Deleter<RWStepRepr_RWProductDefinitionShape>>> cls_RWStepRepr_RWProductDefinitionShape(mod, "RWStepRepr_RWProductDefinitionShape", "Read & Write tool for ProductDefinitionShape");
	cls_RWStepRepr_RWProductDefinitionShape.def(py::init<>());
	cls_RWStepRepr_RWProductDefinitionShape.def("ReadStep", (void (RWStepRepr_RWProductDefinitionShape::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &) const ) &RWStepRepr_RWProductDefinitionShape::ReadStep, "Reads ProductDefinitionShape", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWProductDefinitionShape.def("WriteStep", (void (RWStepRepr_RWProductDefinitionShape::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ProductDefinitionShape> &) const ) &RWStepRepr_RWProductDefinitionShape::WriteStep, "Writes ProductDefinitionShape", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWProductDefinitionShape.def("Share", (void (RWStepRepr_RWProductDefinitionShape::*)(const opencascade::handle<StepRepr_ProductDefinitionShape> &, Interface_EntityIterator &) const ) &RWStepRepr_RWProductDefinitionShape::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWPropertyDefinition.hxx
	py::class_<RWStepRepr_RWPropertyDefinition, std::unique_ptr<RWStepRepr_RWPropertyDefinition, Deleter<RWStepRepr_RWPropertyDefinition>>> cls_RWStepRepr_RWPropertyDefinition(mod, "RWStepRepr_RWPropertyDefinition", "Read & Write tool for PropertyDefinition");
	cls_RWStepRepr_RWPropertyDefinition.def(py::init<>());
	cls_RWStepRepr_RWPropertyDefinition.def("ReadStep", (void (RWStepRepr_RWPropertyDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PropertyDefinition> &) const ) &RWStepRepr_RWPropertyDefinition::ReadStep, "Reads PropertyDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWPropertyDefinition.def("WriteStep", (void (RWStepRepr_RWPropertyDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PropertyDefinition> &) const ) &RWStepRepr_RWPropertyDefinition::WriteStep, "Writes PropertyDefinition", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWPropertyDefinition.def("Share", (void (RWStepRepr_RWPropertyDefinition::*)(const opencascade::handle<StepRepr_PropertyDefinition> &, Interface_EntityIterator &) const ) &RWStepRepr_RWPropertyDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWPropertyDefinitionRelationship.hxx
	py::class_<RWStepRepr_RWPropertyDefinitionRelationship, std::unique_ptr<RWStepRepr_RWPropertyDefinitionRelationship, Deleter<RWStepRepr_RWPropertyDefinitionRelationship>>> cls_RWStepRepr_RWPropertyDefinitionRelationship(mod, "RWStepRepr_RWPropertyDefinitionRelationship", "Read & Write tool for PropertyDefinitionRelationship");
	cls_RWStepRepr_RWPropertyDefinitionRelationship.def(py::init<>());
	cls_RWStepRepr_RWPropertyDefinitionRelationship.def("ReadStep", (void (RWStepRepr_RWPropertyDefinitionRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PropertyDefinitionRelationship> &) const ) &RWStepRepr_RWPropertyDefinitionRelationship::ReadStep, "Reads PropertyDefinitionRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWPropertyDefinitionRelationship.def("WriteStep", (void (RWStepRepr_RWPropertyDefinitionRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PropertyDefinitionRelationship> &) const ) &RWStepRepr_RWPropertyDefinitionRelationship::WriteStep, "Writes PropertyDefinitionRelationship", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWPropertyDefinitionRelationship.def("Share", (void (RWStepRepr_RWPropertyDefinitionRelationship::*)(const opencascade::handle<StepRepr_PropertyDefinitionRelationship> &, Interface_EntityIterator &) const ) &RWStepRepr_RWPropertyDefinitionRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWPropertyDefinitionRepresentation.hxx
	py::class_<RWStepRepr_RWPropertyDefinitionRepresentation, std::unique_ptr<RWStepRepr_RWPropertyDefinitionRepresentation, Deleter<RWStepRepr_RWPropertyDefinitionRepresentation>>> cls_RWStepRepr_RWPropertyDefinitionRepresentation(mod, "RWStepRepr_RWPropertyDefinitionRepresentation", "Read & Write tool for PropertyDefinitionRepresentation");
	cls_RWStepRepr_RWPropertyDefinitionRepresentation.def(py::init<>());
	cls_RWStepRepr_RWPropertyDefinitionRepresentation.def("ReadStep", (void (RWStepRepr_RWPropertyDefinitionRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PropertyDefinitionRepresentation> &) const ) &RWStepRepr_RWPropertyDefinitionRepresentation::ReadStep, "Reads PropertyDefinitionRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWPropertyDefinitionRepresentation.def("WriteStep", (void (RWStepRepr_RWPropertyDefinitionRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PropertyDefinitionRepresentation> &) const ) &RWStepRepr_RWPropertyDefinitionRepresentation::WriteStep, "Writes PropertyDefinitionRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWPropertyDefinitionRepresentation.def("Share", (void (RWStepRepr_RWPropertyDefinitionRepresentation::*)(const opencascade::handle<StepRepr_PropertyDefinitionRepresentation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWPropertyDefinitionRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWQuantifiedAssemblyComponentUsage.hxx
	py::class_<RWStepRepr_RWQuantifiedAssemblyComponentUsage, std::unique_ptr<RWStepRepr_RWQuantifiedAssemblyComponentUsage, Deleter<RWStepRepr_RWQuantifiedAssemblyComponentUsage>>> cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage(mod, "RWStepRepr_RWQuantifiedAssemblyComponentUsage", "Read & Write tool for QuantifiedAssemblyComponentUsage");
	cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def(py::init<>());
	cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def("ReadStep", (void (RWStepRepr_RWQuantifiedAssemblyComponentUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_QuantifiedAssemblyComponentUsage> &) const ) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::ReadStep, "Reads QuantifiedAssemblyComponentUsage", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def("WriteStep", (void (RWStepRepr_RWQuantifiedAssemblyComponentUsage::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_QuantifiedAssemblyComponentUsage> &) const ) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::WriteStep, "Writes QuantifiedAssemblyComponentUsage", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWQuantifiedAssemblyComponentUsage.def("Share", (void (RWStepRepr_RWQuantifiedAssemblyComponentUsage::*)(const opencascade::handle<StepRepr_QuantifiedAssemblyComponentUsage> &, Interface_EntityIterator &) const ) &RWStepRepr_RWQuantifiedAssemblyComponentUsage::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWRepresentation.hxx
	py::class_<RWStepRepr_RWRepresentation, std::unique_ptr<RWStepRepr_RWRepresentation, Deleter<RWStepRepr_RWRepresentation>>> cls_RWStepRepr_RWRepresentation(mod, "RWStepRepr_RWRepresentation", "Read & Write Module for Representation");
	cls_RWStepRepr_RWRepresentation.def(py::init<>());
	cls_RWStepRepr_RWRepresentation.def("ReadStep", (void (RWStepRepr_RWRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Representation> &) const ) &RWStepRepr_RWRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentation.def("WriteStep", (void (RWStepRepr_RWRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Representation> &) const ) &RWStepRepr_RWRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentation.def("Share", (void (RWStepRepr_RWRepresentation::*)(const opencascade::handle<StepRepr_Representation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWRepresentationContext.hxx
	py::class_<RWStepRepr_RWRepresentationContext, std::unique_ptr<RWStepRepr_RWRepresentationContext, Deleter<RWStepRepr_RWRepresentationContext>>> cls_RWStepRepr_RWRepresentationContext(mod, "RWStepRepr_RWRepresentationContext", "Read & Write Module for RepresentationContext");
	cls_RWStepRepr_RWRepresentationContext.def(py::init<>());
	cls_RWStepRepr_RWRepresentationContext.def("ReadStep", (void (RWStepRepr_RWRepresentationContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationContext> &) const ) &RWStepRepr_RWRepresentationContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentationContext.def("WriteStep", (void (RWStepRepr_RWRepresentationContext::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationContext> &) const ) &RWStepRepr_RWRepresentationContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWRepresentationItem.hxx
	py::class_<RWStepRepr_RWRepresentationItem, std::unique_ptr<RWStepRepr_RWRepresentationItem, Deleter<RWStepRepr_RWRepresentationItem>>> cls_RWStepRepr_RWRepresentationItem(mod, "RWStepRepr_RWRepresentationItem", "Read & Write Module for RepresentationItem");
	cls_RWStepRepr_RWRepresentationItem.def(py::init<>());
	cls_RWStepRepr_RWRepresentationItem.def("ReadStep", (void (RWStepRepr_RWRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationItem> &) const ) &RWStepRepr_RWRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentationItem.def("WriteStep", (void (RWStepRepr_RWRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationItem> &) const ) &RWStepRepr_RWRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWRepresentationMap.hxx
	py::class_<RWStepRepr_RWRepresentationMap, std::unique_ptr<RWStepRepr_RWRepresentationMap, Deleter<RWStepRepr_RWRepresentationMap>>> cls_RWStepRepr_RWRepresentationMap(mod, "RWStepRepr_RWRepresentationMap", "Read & Write Module for RepresentationMap");
	cls_RWStepRepr_RWRepresentationMap.def(py::init<>());
	cls_RWStepRepr_RWRepresentationMap.def("ReadStep", (void (RWStepRepr_RWRepresentationMap::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationMap> &) const ) &RWStepRepr_RWRepresentationMap::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentationMap.def("WriteStep", (void (RWStepRepr_RWRepresentationMap::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationMap> &) const ) &RWStepRepr_RWRepresentationMap::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentationMap.def("Share", (void (RWStepRepr_RWRepresentationMap::*)(const opencascade::handle<StepRepr_RepresentationMap> &, Interface_EntityIterator &) const ) &RWStepRepr_RWRepresentationMap::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWRepresentationRelationship.hxx
	py::class_<RWStepRepr_RWRepresentationRelationship, std::unique_ptr<RWStepRepr_RWRepresentationRelationship, Deleter<RWStepRepr_RWRepresentationRelationship>>> cls_RWStepRepr_RWRepresentationRelationship(mod, "RWStepRepr_RWRepresentationRelationship", "Read & Write Module for RepresentationRelationship");
	cls_RWStepRepr_RWRepresentationRelationship.def(py::init<>());
	cls_RWStepRepr_RWRepresentationRelationship.def("ReadStep", (void (RWStepRepr_RWRepresentationRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationRelationship> &) const ) &RWStepRepr_RWRepresentationRelationship::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentationRelationship.def("WriteStep", (void (RWStepRepr_RWRepresentationRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationRelationship> &) const ) &RWStepRepr_RWRepresentationRelationship::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentationRelationship.def("Share", (void (RWStepRepr_RWRepresentationRelationship::*)(const opencascade::handle<StepRepr_RepresentationRelationship> &, Interface_EntityIterator &) const ) &RWStepRepr_RWRepresentationRelationship::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWRepresentationRelationshipWithTransformation.hxx
	py::class_<RWStepRepr_RWRepresentationRelationshipWithTransformation, std::unique_ptr<RWStepRepr_RWRepresentationRelationshipWithTransformation, Deleter<RWStepRepr_RWRepresentationRelationshipWithTransformation>>> cls_RWStepRepr_RWRepresentationRelationshipWithTransformation(mod, "RWStepRepr_RWRepresentationRelationshipWithTransformation", "Read & Write Module for RepresentationRelationshipWithTransformation");
	cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def(py::init<>());
	cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def("ReadStep", (void (RWStepRepr_RWRepresentationRelationshipWithTransformation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation> &) const ) &RWStepRepr_RWRepresentationRelationshipWithTransformation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def("WriteStep", (void (RWStepRepr_RWRepresentationRelationshipWithTransformation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation> &) const ) &RWStepRepr_RWRepresentationRelationshipWithTransformation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWRepresentationRelationshipWithTransformation.def("Share", (void (RWStepRepr_RWRepresentationRelationshipWithTransformation::*)(const opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWRepresentationRelationshipWithTransformation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWReprItemAndLengthMeasureWithUnit.hxx
	py::class_<RWStepRepr_RWReprItemAndLengthMeasureWithUnit, std::unique_ptr<RWStepRepr_RWReprItemAndLengthMeasureWithUnit, Deleter<RWStepRepr_RWReprItemAndLengthMeasureWithUnit>>> cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit(mod, "RWStepRepr_RWReprItemAndLengthMeasureWithUnit", "Read & Write Module for ReprItemAndLengthMeasureWithUni");
	cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def(py::init<>());
	cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def("ReadStep", (void (RWStepRepr_RWReprItemAndLengthMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnit> &) const ) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnit.def("WriteStep", (void (RWStepRepr_RWReprItemAndLengthMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnit> &) const ) &RWStepRepr_RWReprItemAndLengthMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.hxx
	py::class_<RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI, std::unique_ptr<RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI, Deleter<RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI>>> cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI(mod, "RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI", "Read & Write Module for ReprItemAndLengthMeasureWithUnitAndQRI");
	cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def(py::init<>());
	cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def("ReadStep", (void (RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI> &) const ) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI.def("WriteStep", (void (RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI> &) const ) &RWStepRepr_RWReprItemAndLengthMeasureWithUnitAndQRI::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.hxx
	py::class_<RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit, std::unique_ptr<RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit, Deleter<RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit>>> cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit(mod, "RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit", "Read & Write Module for ReprItemAndPlaneAngleMeasureWithUni");
	cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def(py::init<>());
	cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def("ReadStep", (void (RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnit> &) const ) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit.def("WriteStep", (void (RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnit> &) const ) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.hxx
	py::class_<RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI, std::unique_ptr<RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI, Deleter<RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI>>> cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI(mod, "RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI", "Read & Write Module for ReprItemAndPlaneAngleMeasureWithUnitAndQRI");
	cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def(py::init<>());
	cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def("ReadStep", (void (RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI> &) const ) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI.def("WriteStep", (void (RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI> &) const ) &RWStepRepr_RWReprItemAndPlaneAngleMeasureWithUnitAndQRI::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWShapeAspect.hxx
	py::class_<RWStepRepr_RWShapeAspect, std::unique_ptr<RWStepRepr_RWShapeAspect, Deleter<RWStepRepr_RWShapeAspect>>> cls_RWStepRepr_RWShapeAspect(mod, "RWStepRepr_RWShapeAspect", "Read & Write Module for ShapeAspect");
	cls_RWStepRepr_RWShapeAspect.def(py::init<>());
	cls_RWStepRepr_RWShapeAspect.def("ReadStep", (void (RWStepRepr_RWShapeAspect::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeAspect> &) const ) &RWStepRepr_RWShapeAspect::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWShapeAspect.def("WriteStep", (void (RWStepRepr_RWShapeAspect::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeAspect> &) const ) &RWStepRepr_RWShapeAspect::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWShapeAspect.def("Share", (void (RWStepRepr_RWShapeAspect::*)(const opencascade::handle<StepRepr_ShapeAspect> &, Interface_EntityIterator &) const ) &RWStepRepr_RWShapeAspect::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWShapeAspectDerivingRelationship.hxx
	py::class_<RWStepRepr_RWShapeAspectDerivingRelationship, std::unique_ptr<RWStepRepr_RWShapeAspectDerivingRelationship, Deleter<RWStepRepr_RWShapeAspectDerivingRelationship>>> cls_RWStepRepr_RWShapeAspectDerivingRelationship(mod, "RWStepRepr_RWShapeAspectDerivingRelationship", "Read & Write tool for ShapeAspectDerivingRelationship");
	cls_RWStepRepr_RWShapeAspectDerivingRelationship.def(py::init<>());
	cls_RWStepRepr_RWShapeAspectDerivingRelationship.def("ReadStep", (void (RWStepRepr_RWShapeAspectDerivingRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeAspectDerivingRelationship> &) const ) &RWStepRepr_RWShapeAspectDerivingRelationship::ReadStep, "Reads ShapeAspectDerivingRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWShapeAspectDerivingRelationship.def("WriteStep", (void (RWStepRepr_RWShapeAspectDerivingRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeAspectDerivingRelationship> &) const ) &RWStepRepr_RWShapeAspectDerivingRelationship::WriteStep, "Writes ShapeAspectDerivingRelationship", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWShapeAspectDerivingRelationship.def("Share", (void (RWStepRepr_RWShapeAspectDerivingRelationship::*)(const opencascade::handle<StepRepr_ShapeAspectDerivingRelationship> &, Interface_EntityIterator &) const ) &RWStepRepr_RWShapeAspectDerivingRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWShapeAspectRelationship.hxx
	py::class_<RWStepRepr_RWShapeAspectRelationship, std::unique_ptr<RWStepRepr_RWShapeAspectRelationship, Deleter<RWStepRepr_RWShapeAspectRelationship>>> cls_RWStepRepr_RWShapeAspectRelationship(mod, "RWStepRepr_RWShapeAspectRelationship", "Read & Write tool for ShapeAspectRelationship");
	cls_RWStepRepr_RWShapeAspectRelationship.def(py::init<>());
	cls_RWStepRepr_RWShapeAspectRelationship.def("ReadStep", (void (RWStepRepr_RWShapeAspectRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeAspectRelationship> &) const ) &RWStepRepr_RWShapeAspectRelationship::ReadStep, "Reads ShapeAspectRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWShapeAspectRelationship.def("WriteStep", (void (RWStepRepr_RWShapeAspectRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeAspectRelationship> &) const ) &RWStepRepr_RWShapeAspectRelationship::WriteStep, "Writes ShapeAspectRelationship", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWShapeAspectRelationship.def("Share", (void (RWStepRepr_RWShapeAspectRelationship::*)(const opencascade::handle<StepRepr_ShapeAspectRelationship> &, Interface_EntityIterator &) const ) &RWStepRepr_RWShapeAspectRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWShapeAspectTransition.hxx
	py::class_<RWStepRepr_RWShapeAspectTransition, std::unique_ptr<RWStepRepr_RWShapeAspectTransition, Deleter<RWStepRepr_RWShapeAspectTransition>>> cls_RWStepRepr_RWShapeAspectTransition(mod, "RWStepRepr_RWShapeAspectTransition", "Read & Write tool for ShapeAspectTransition");
	cls_RWStepRepr_RWShapeAspectTransition.def(py::init<>());
	cls_RWStepRepr_RWShapeAspectTransition.def("ReadStep", (void (RWStepRepr_RWShapeAspectTransition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeAspectTransition> &) const ) &RWStepRepr_RWShapeAspectTransition::ReadStep, "Reads ShapeAspectTransition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWShapeAspectTransition.def("WriteStep", (void (RWStepRepr_RWShapeAspectTransition::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeAspectTransition> &) const ) &RWStepRepr_RWShapeAspectTransition::WriteStep, "Writes ShapeAspectTransition", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWShapeAspectTransition.def("Share", (void (RWStepRepr_RWShapeAspectTransition::*)(const opencascade::handle<StepRepr_ShapeAspectTransition> &, Interface_EntityIterator &) const ) &RWStepRepr_RWShapeAspectTransition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.hxx
	py::class_<RWStepRepr_RWShapeRepresentationRelationshipWithTransformation, std::unique_ptr<RWStepRepr_RWShapeRepresentationRelationshipWithTransformation, Deleter<RWStepRepr_RWShapeRepresentationRelationshipWithTransformation>>> cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation(mod, "RWStepRepr_RWShapeRepresentationRelationshipWithTransformation", "Read & Write Module for ShapeRepresentationRelationshipWithTransformation");
	cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def(py::init<>());
	cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def("ReadStep", (void (RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ShapeRepresentationRelationshipWithTransformation> &) const ) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def("WriteStep", (void (RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ShapeRepresentationRelationshipWithTransformation> &) const ) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWShapeRepresentationRelationshipWithTransformation.def("Share", (void (RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::*)(const opencascade::handle<StepRepr_ShapeRepresentationRelationshipWithTransformation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWShapeRepresentationRelationshipWithTransformation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWSpecifiedHigherUsageOccurrence.hxx
	py::class_<RWStepRepr_RWSpecifiedHigherUsageOccurrence, std::unique_ptr<RWStepRepr_RWSpecifiedHigherUsageOccurrence, Deleter<RWStepRepr_RWSpecifiedHigherUsageOccurrence>>> cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence(mod, "RWStepRepr_RWSpecifiedHigherUsageOccurrence", "Read & Write tool for SpecifiedHigherUsageOccurrence");
	cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def(py::init<>());
	cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def("ReadStep", (void (RWStepRepr_RWSpecifiedHigherUsageOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_SpecifiedHigherUsageOccurrence> &) const ) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::ReadStep, "Reads SpecifiedHigherUsageOccurrence", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def("WriteStep", (void (RWStepRepr_RWSpecifiedHigherUsageOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_SpecifiedHigherUsageOccurrence> &) const ) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::WriteStep, "Writes SpecifiedHigherUsageOccurrence", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWSpecifiedHigherUsageOccurrence.def("Share", (void (RWStepRepr_RWSpecifiedHigherUsageOccurrence::*)(const opencascade::handle<StepRepr_SpecifiedHigherUsageOccurrence> &, Interface_EntityIterator &) const ) &RWStepRepr_RWSpecifiedHigherUsageOccurrence::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWStructuralResponseProperty.hxx
	py::class_<RWStepRepr_RWStructuralResponseProperty, std::unique_ptr<RWStepRepr_RWStructuralResponseProperty, Deleter<RWStepRepr_RWStructuralResponseProperty>>> cls_RWStepRepr_RWStructuralResponseProperty(mod, "RWStepRepr_RWStructuralResponseProperty", "Read & Write tool for StructuralResponseProperty");
	cls_RWStepRepr_RWStructuralResponseProperty.def(py::init<>());
	cls_RWStepRepr_RWStructuralResponseProperty.def("ReadStep", (void (RWStepRepr_RWStructuralResponseProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_StructuralResponseProperty> &) const ) &RWStepRepr_RWStructuralResponseProperty::ReadStep, "Reads StructuralResponseProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWStructuralResponseProperty.def("WriteStep", (void (RWStepRepr_RWStructuralResponseProperty::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_StructuralResponseProperty> &) const ) &RWStepRepr_RWStructuralResponseProperty::WriteStep, "Writes StructuralResponseProperty", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWStructuralResponseProperty.def("Share", (void (RWStepRepr_RWStructuralResponseProperty::*)(const opencascade::handle<StepRepr_StructuralResponseProperty> &, Interface_EntityIterator &) const ) &RWStepRepr_RWStructuralResponseProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.hxx
	py::class_<RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation, std::unique_ptr<RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation, Deleter<RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation>>> cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation(mod, "RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation", "Read & Write tool for StructuralResponsePropertyDefinitionRepresentation");
	cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def(py::init<>());
	cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def("ReadStep", (void (RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_StructuralResponsePropertyDefinitionRepresentation> &) const ) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::ReadStep, "Reads StructuralResponsePropertyDefinitionRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def("WriteStep", (void (RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_StructuralResponsePropertyDefinitionRepresentation> &) const ) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::WriteStep, "Writes StructuralResponsePropertyDefinitionRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation.def("Share", (void (RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::*)(const opencascade::handle<StepRepr_StructuralResponsePropertyDefinitionRepresentation> &, Interface_EntityIterator &) const ) &RWStepRepr_RWStructuralResponsePropertyDefinitionRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWTangent.hxx
	py::class_<RWStepRepr_RWTangent, std::unique_ptr<RWStepRepr_RWTangent, Deleter<RWStepRepr_RWTangent>>> cls_RWStepRepr_RWTangent(mod, "RWStepRepr_RWTangent", "Read & Write tool for Tangent");
	cls_RWStepRepr_RWTangent.def(py::init<>());
	cls_RWStepRepr_RWTangent.def("ReadStep", (void (RWStepRepr_RWTangent::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Tangent> &) const ) &RWStepRepr_RWTangent::ReadStep, "Reads Tangent", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWTangent.def("WriteStep", (void (RWStepRepr_RWTangent::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Tangent> &) const ) &RWStepRepr_RWTangent::WriteStep, "Writes Tangent", py::arg("SW"), py::arg("ent"));
	cls_RWStepRepr_RWTangent.def("Share", (void (RWStepRepr_RWTangent::*)(const opencascade::handle<StepRepr_Tangent> &, Interface_EntityIterator &) const ) &RWStepRepr_RWTangent::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepRepr_RWValueRepresentationItem.hxx
	py::class_<RWStepRepr_RWValueRepresentationItem, std::unique_ptr<RWStepRepr_RWValueRepresentationItem, Deleter<RWStepRepr_RWValueRepresentationItem>>> cls_RWStepRepr_RWValueRepresentationItem(mod, "RWStepRepr_RWValueRepresentationItem", "Read & Write Module for ValueRepresentationItem");
	cls_RWStepRepr_RWValueRepresentationItem.def(py::init<>());
	cls_RWStepRepr_RWValueRepresentationItem.def("ReadStep", (void (RWStepRepr_RWValueRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ValueRepresentationItem> &) const ) &RWStepRepr_RWValueRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepRepr_RWValueRepresentationItem.def("WriteStep", (void (RWStepRepr_RWValueRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ValueRepresentationItem> &) const ) &RWStepRepr_RWValueRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));


}
