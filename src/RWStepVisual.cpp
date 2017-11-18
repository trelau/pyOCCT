#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepVisual_AnnotationCurveOccurrence.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepVisual_RWAnnotationCurveOccurrence.hxx>
#include <StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.hxx>
#include <RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.hxx>
#include <StepVisual_AnnotationFillArea.hxx>
#include <RWStepVisual_RWAnnotationFillArea.hxx>
#include <StepVisual_AnnotationFillAreaOccurrence.hxx>
#include <RWStepVisual_RWAnnotationFillAreaOccurrence.hxx>
#include <StepVisual_AnnotationOccurrence.hxx>
#include <RWStepVisual_RWAnnotationOccurrence.hxx>
#include <StepVisual_AnnotationPlane.hxx>
#include <RWStepVisual_RWAnnotationPlane.hxx>
#include <StepVisual_AreaInSet.hxx>
#include <RWStepVisual_RWAreaInSet.hxx>
#include <StepVisual_BackgroundColour.hxx>
#include <RWStepVisual_RWBackgroundColour.hxx>
#include <StepVisual_CameraImage.hxx>
#include <RWStepVisual_RWCameraImage.hxx>
#include <StepVisual_CameraModel.hxx>
#include <RWStepVisual_RWCameraModel.hxx>
#include <StepVisual_CameraModelD2.hxx>
#include <RWStepVisual_RWCameraModelD2.hxx>
#include <StepVisual_CameraModelD3.hxx>
#include <RWStepVisual_RWCameraModelD3.hxx>
#include <StepVisual_CameraModelD3MultiClipping.hxx>
#include <RWStepVisual_RWCameraModelD3MultiClipping.hxx>
#include <StepVisual_CameraModelD3MultiClippingIntersection.hxx>
#include <RWStepVisual_RWCameraModelD3MultiClippingIntersection.hxx>
#include <StepVisual_CameraModelD3MultiClippingUnion.hxx>
#include <RWStepVisual_RWCameraModelD3MultiClippingUnion.hxx>
#include <StepVisual_CameraUsage.hxx>
#include <RWStepVisual_RWCameraUsage.hxx>
#include <StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.hxx>
#include <RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.hxx>
#include <StepVisual_Colour.hxx>
#include <RWStepVisual_RWColour.hxx>
#include <StepVisual_ColourRgb.hxx>
#include <RWStepVisual_RWColourRgb.hxx>
#include <StepVisual_ColourSpecification.hxx>
#include <RWStepVisual_RWColourSpecification.hxx>
#include <StepVisual_CompositeText.hxx>
#include <RWStepVisual_RWCompositeText.hxx>
#include <StepVisual_CompositeTextWithExtent.hxx>
#include <RWStepVisual_RWCompositeTextWithExtent.hxx>
#include <StepVisual_ContextDependentInvisibility.hxx>
#include <RWStepVisual_RWContextDependentInvisibility.hxx>
#include <StepVisual_ContextDependentOverRidingStyledItem.hxx>
#include <RWStepVisual_RWContextDependentOverRidingStyledItem.hxx>
#include <StepVisual_CoordinatesList.hxx>
#include <RWStepVisual_RWCoordinatesList.hxx>
#include <StepVisual_CurveStyle.hxx>
#include <RWStepVisual_RWCurveStyle.hxx>
#include <StepVisual_CurveStyleFont.hxx>
#include <RWStepVisual_RWCurveStyleFont.hxx>
#include <StepVisual_CurveStyleFontPattern.hxx>
#include <RWStepVisual_RWCurveStyleFontPattern.hxx>
#include <StepVisual_DraughtingCallout.hxx>
#include <RWStepVisual_RWDraughtingCallout.hxx>
#include <StepVisual_DraughtingModel.hxx>
#include <RWStepVisual_RWDraughtingModel.hxx>
#include <StepVisual_DraughtingPreDefinedColour.hxx>
#include <RWStepVisual_RWDraughtingPreDefinedColour.hxx>
#include <StepVisual_DraughtingPreDefinedCurveFont.hxx>
#include <RWStepVisual_RWDraughtingPreDefinedCurveFont.hxx>
#include <StepVisual_ExternallyDefinedCurveFont.hxx>
#include <RWStepVisual_RWExternallyDefinedCurveFont.hxx>
#include <StepVisual_FillAreaStyle.hxx>
#include <RWStepVisual_RWFillAreaStyle.hxx>
#include <StepVisual_FillAreaStyleColour.hxx>
#include <RWStepVisual_RWFillAreaStyleColour.hxx>
#include <StepVisual_Invisibility.hxx>
#include <RWStepVisual_RWInvisibility.hxx>
#include <StepVisual_MechanicalDesignGeometricPresentationArea.hxx>
#include <RWStepVisual_RWMechanicalDesignGeometricPresentationArea.hxx>
#include <StepVisual_MechanicalDesignGeometricPresentationRepresentation.hxx>
#include <RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.hxx>
#include <StepVisual_OverRidingStyledItem.hxx>
#include <RWStepVisual_RWOverRidingStyledItem.hxx>
#include <StepVisual_PlanarBox.hxx>
#include <RWStepVisual_RWPlanarBox.hxx>
#include <StepVisual_PlanarExtent.hxx>
#include <RWStepVisual_RWPlanarExtent.hxx>
#include <StepVisual_PointStyle.hxx>
#include <RWStepVisual_RWPointStyle.hxx>
#include <StepVisual_PreDefinedColour.hxx>
#include <RWStepVisual_RWPreDefinedColour.hxx>
#include <StepVisual_PreDefinedCurveFont.hxx>
#include <RWStepVisual_RWPreDefinedCurveFont.hxx>
#include <StepVisual_PreDefinedItem.hxx>
#include <RWStepVisual_RWPreDefinedItem.hxx>
#include <StepVisual_PresentationArea.hxx>
#include <RWStepVisual_RWPresentationArea.hxx>
#include <StepVisual_PresentationLayerAssignment.hxx>
#include <RWStepVisual_RWPresentationLayerAssignment.hxx>
#include <StepVisual_PresentationLayerUsage.hxx>
#include <RWStepVisual_RWPresentationLayerUsage.hxx>
#include <StepVisual_PresentationRepresentation.hxx>
#include <RWStepVisual_RWPresentationRepresentation.hxx>
#include <StepVisual_PresentationSet.hxx>
#include <RWStepVisual_RWPresentationSet.hxx>
#include <StepVisual_PresentationSize.hxx>
#include <RWStepVisual_RWPresentationSize.hxx>
#include <StepVisual_PresentationStyleAssignment.hxx>
#include <RWStepVisual_RWPresentationStyleAssignment.hxx>
#include <StepVisual_PresentationStyleByContext.hxx>
#include <RWStepVisual_RWPresentationStyleByContext.hxx>
#include <StepVisual_PresentationView.hxx>
#include <RWStepVisual_RWPresentationView.hxx>
#include <StepVisual_PresentedItemRepresentation.hxx>
#include <RWStepVisual_RWPresentedItemRepresentation.hxx>
#include <StepVisual_StyledItem.hxx>
#include <RWStepVisual_RWStyledItem.hxx>
#include <StepVisual_SurfaceSideStyle.hxx>
#include <RWStepVisual_RWSurfaceSideStyle.hxx>
#include <StepVisual_SurfaceStyleBoundary.hxx>
#include <RWStepVisual_RWSurfaceStyleBoundary.hxx>
#include <StepVisual_SurfaceStyleControlGrid.hxx>
#include <RWStepVisual_RWSurfaceStyleControlGrid.hxx>
#include <StepVisual_SurfaceStyleFillArea.hxx>
#include <RWStepVisual_RWSurfaceStyleFillArea.hxx>
#include <StepVisual_SurfaceStyleParameterLine.hxx>
#include <RWStepVisual_RWSurfaceStyleParameterLine.hxx>
#include <StepVisual_SurfaceStyleSegmentationCurve.hxx>
#include <RWStepVisual_RWSurfaceStyleSegmentationCurve.hxx>
#include <StepVisual_SurfaceStyleSilhouette.hxx>
#include <RWStepVisual_RWSurfaceStyleSilhouette.hxx>
#include <StepVisual_SurfaceStyleUsage.hxx>
#include <RWStepVisual_RWSurfaceStyleUsage.hxx>
#include <StepVisual_Template.hxx>
#include <RWStepVisual_RWTemplate.hxx>
#include <StepVisual_TemplateInstance.hxx>
#include <RWStepVisual_RWTemplateInstance.hxx>
#include <StepVisual_TessellatedAnnotationOccurrence.hxx>
#include <RWStepVisual_RWTessellatedAnnotationOccurrence.hxx>
#include <StepVisual_TessellatedCurveSet.hxx>
#include <RWStepVisual_RWTessellatedCurveSet.hxx>
#include <StepVisual_TessellatedGeometricSet.hxx>
#include <RWStepVisual_RWTessellatedGeometricSet.hxx>
#include <StepVisual_TessellatedItem.hxx>
#include <RWStepVisual_RWTessellatedItem.hxx>
#include <StepVisual_TextLiteral.hxx>
#include <RWStepVisual_RWTextLiteral.hxx>
#include <StepVisual_TextStyle.hxx>
#include <RWStepVisual_RWTextStyle.hxx>
#include <StepVisual_TextStyleForDefinedFont.hxx>
#include <RWStepVisual_RWTextStyleForDefinedFont.hxx>
#include <StepVisual_TextStyleWithBoxCharacteristics.hxx>
#include <RWStepVisual_RWTextStyleWithBoxCharacteristics.hxx>
#include <StepVisual_ViewVolume.hxx>
#include <RWStepVisual_RWViewVolume.hxx>

PYBIND11_MODULE(RWStepVisual, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepVisual");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWAnnotationCurveOccurrence.hxx
	py::class_<RWStepVisual_RWAnnotationCurveOccurrence, std::unique_ptr<RWStepVisual_RWAnnotationCurveOccurrence, Deleter<RWStepVisual_RWAnnotationCurveOccurrence>>> cls_RWStepVisual_RWAnnotationCurveOccurrence(mod, "RWStepVisual_RWAnnotationCurveOccurrence", "Read & Write Module for AnnotationCurveOccurrence");
	cls_RWStepVisual_RWAnnotationCurveOccurrence.def(py::init<>());
	cls_RWStepVisual_RWAnnotationCurveOccurrence.def("ReadStep", (void (RWStepVisual_RWAnnotationCurveOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationCurveOccurrence> &) const ) &RWStepVisual_RWAnnotationCurveOccurrence::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationCurveOccurrence.def("WriteStep", (void (RWStepVisual_RWAnnotationCurveOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationCurveOccurrence> &) const ) &RWStepVisual_RWAnnotationCurveOccurrence::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationCurveOccurrence.def("Share", (void (RWStepVisual_RWAnnotationCurveOccurrence::*)(const opencascade::handle<StepVisual_AnnotationCurveOccurrence> &, Interface_EntityIterator &) const ) &RWStepVisual_RWAnnotationCurveOccurrence::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.hxx
	py::class_<RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem, std::unique_ptr<RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem, Deleter<RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem>>> cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem(mod, "RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem", "Read & Write Module for AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem");
	cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def(py::init<>());
	cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def("ReadStep", (void (RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem> &) const ) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def("WriteStep", (void (RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem> &) const ) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def("Share", (void (RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::*)(const opencascade::handle<StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem> &, Interface_EntityIterator &) const ) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWAnnotationFillArea.hxx
	py::class_<RWStepVisual_RWAnnotationFillArea, std::unique_ptr<RWStepVisual_RWAnnotationFillArea, Deleter<RWStepVisual_RWAnnotationFillArea>>> cls_RWStepVisual_RWAnnotationFillArea(mod, "RWStepVisual_RWAnnotationFillArea", "Read & Write Module for AnnotationFillArea");
	cls_RWStepVisual_RWAnnotationFillArea.def(py::init<>());
	cls_RWStepVisual_RWAnnotationFillArea.def("ReadStep", (void (RWStepVisual_RWAnnotationFillArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationFillArea> &) const ) &RWStepVisual_RWAnnotationFillArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationFillArea.def("WriteStep", (void (RWStepVisual_RWAnnotationFillArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationFillArea> &) const ) &RWStepVisual_RWAnnotationFillArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationFillArea.def("Share", (void (RWStepVisual_RWAnnotationFillArea::*)(const opencascade::handle<StepVisual_AnnotationFillArea> &, Interface_EntityIterator &) const ) &RWStepVisual_RWAnnotationFillArea::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWAnnotationFillAreaOccurrence.hxx
	py::class_<RWStepVisual_RWAnnotationFillAreaOccurrence, std::unique_ptr<RWStepVisual_RWAnnotationFillAreaOccurrence, Deleter<RWStepVisual_RWAnnotationFillAreaOccurrence>>> cls_RWStepVisual_RWAnnotationFillAreaOccurrence(mod, "RWStepVisual_RWAnnotationFillAreaOccurrence", "Read & Write Module for AnnotationFillAreaOccurrence");
	cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def(py::init<>());
	cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def("ReadStep", (void (RWStepVisual_RWAnnotationFillAreaOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationFillAreaOccurrence> &) const ) &RWStepVisual_RWAnnotationFillAreaOccurrence::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def("WriteStep", (void (RWStepVisual_RWAnnotationFillAreaOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationFillAreaOccurrence> &) const ) &RWStepVisual_RWAnnotationFillAreaOccurrence::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def("Share", (void (RWStepVisual_RWAnnotationFillAreaOccurrence::*)(const opencascade::handle<StepVisual_AnnotationFillAreaOccurrence> &, Interface_EntityIterator &) const ) &RWStepVisual_RWAnnotationFillAreaOccurrence::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWAnnotationOccurrence.hxx
	py::class_<RWStepVisual_RWAnnotationOccurrence, std::unique_ptr<RWStepVisual_RWAnnotationOccurrence, Deleter<RWStepVisual_RWAnnotationOccurrence>>> cls_RWStepVisual_RWAnnotationOccurrence(mod, "RWStepVisual_RWAnnotationOccurrence", "Read & Write Module for AnnotationOccurrence");
	cls_RWStepVisual_RWAnnotationOccurrence.def(py::init<>());
	cls_RWStepVisual_RWAnnotationOccurrence.def("ReadStep", (void (RWStepVisual_RWAnnotationOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationOccurrence> &) const ) &RWStepVisual_RWAnnotationOccurrence::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationOccurrence.def("WriteStep", (void (RWStepVisual_RWAnnotationOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationOccurrence> &) const ) &RWStepVisual_RWAnnotationOccurrence::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationOccurrence.def("Share", (void (RWStepVisual_RWAnnotationOccurrence::*)(const opencascade::handle<StepVisual_AnnotationOccurrence> &, Interface_EntityIterator &) const ) &RWStepVisual_RWAnnotationOccurrence::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWAnnotationPlane.hxx
	py::class_<RWStepVisual_RWAnnotationPlane, std::unique_ptr<RWStepVisual_RWAnnotationPlane, Deleter<RWStepVisual_RWAnnotationPlane>>> cls_RWStepVisual_RWAnnotationPlane(mod, "RWStepVisual_RWAnnotationPlane", "Read & Write Module for AnnotationPlane");
	cls_RWStepVisual_RWAnnotationPlane.def(py::init<>());
	cls_RWStepVisual_RWAnnotationPlane.def("ReadStep", (void (RWStepVisual_RWAnnotationPlane::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationPlane> &) const ) &RWStepVisual_RWAnnotationPlane::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationPlane.def("WriteStep", (void (RWStepVisual_RWAnnotationPlane::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationPlane> &) const ) &RWStepVisual_RWAnnotationPlane::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWAnnotationPlane.def("Share", (void (RWStepVisual_RWAnnotationPlane::*)(const opencascade::handle<StepVisual_AnnotationPlane> &, Interface_EntityIterator &) const ) &RWStepVisual_RWAnnotationPlane::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWAreaInSet.hxx
	py::class_<RWStepVisual_RWAreaInSet, std::unique_ptr<RWStepVisual_RWAreaInSet, Deleter<RWStepVisual_RWAreaInSet>>> cls_RWStepVisual_RWAreaInSet(mod, "RWStepVisual_RWAreaInSet", "Read & Write Module for AreaInSet");
	cls_RWStepVisual_RWAreaInSet.def(py::init<>());
	cls_RWStepVisual_RWAreaInSet.def("ReadStep", (void (RWStepVisual_RWAreaInSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AreaInSet> &) const ) &RWStepVisual_RWAreaInSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWAreaInSet.def("WriteStep", (void (RWStepVisual_RWAreaInSet::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AreaInSet> &) const ) &RWStepVisual_RWAreaInSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWAreaInSet.def("Share", (void (RWStepVisual_RWAreaInSet::*)(const opencascade::handle<StepVisual_AreaInSet> &, Interface_EntityIterator &) const ) &RWStepVisual_RWAreaInSet::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWBackgroundColour.hxx
	py::class_<RWStepVisual_RWBackgroundColour, std::unique_ptr<RWStepVisual_RWBackgroundColour, Deleter<RWStepVisual_RWBackgroundColour>>> cls_RWStepVisual_RWBackgroundColour(mod, "RWStepVisual_RWBackgroundColour", "Read & Write Module for BackgroundColour");
	cls_RWStepVisual_RWBackgroundColour.def(py::init<>());
	cls_RWStepVisual_RWBackgroundColour.def("ReadStep", (void (RWStepVisual_RWBackgroundColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_BackgroundColour> &) const ) &RWStepVisual_RWBackgroundColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWBackgroundColour.def("WriteStep", (void (RWStepVisual_RWBackgroundColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_BackgroundColour> &) const ) &RWStepVisual_RWBackgroundColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWBackgroundColour.def("Share", (void (RWStepVisual_RWBackgroundColour::*)(const opencascade::handle<StepVisual_BackgroundColour> &, Interface_EntityIterator &) const ) &RWStepVisual_RWBackgroundColour::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCameraImage.hxx
	py::class_<RWStepVisual_RWCameraImage, std::unique_ptr<RWStepVisual_RWCameraImage, Deleter<RWStepVisual_RWCameraImage>>> cls_RWStepVisual_RWCameraImage(mod, "RWStepVisual_RWCameraImage", "Read & Write Module for CameraImage");
	cls_RWStepVisual_RWCameraImage.def(py::init<>());
	cls_RWStepVisual_RWCameraImage.def("ReadStep", (void (RWStepVisual_RWCameraImage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraImage> &) const ) &RWStepVisual_RWCameraImage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCameraImage.def("WriteStep", (void (RWStepVisual_RWCameraImage::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraImage> &) const ) &RWStepVisual_RWCameraImage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCameraImage.def("Share", (void (RWStepVisual_RWCameraImage::*)(const opencascade::handle<StepVisual_CameraImage> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCameraImage::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCameraModel.hxx
	py::class_<RWStepVisual_RWCameraModel, std::unique_ptr<RWStepVisual_RWCameraModel, Deleter<RWStepVisual_RWCameraModel>>> cls_RWStepVisual_RWCameraModel(mod, "RWStepVisual_RWCameraModel", "Read & Write Module for CameraModel");
	cls_RWStepVisual_RWCameraModel.def(py::init<>());
	cls_RWStepVisual_RWCameraModel.def("ReadStep", (void (RWStepVisual_RWCameraModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModel> &) const ) &RWStepVisual_RWCameraModel::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModel.def("WriteStep", (void (RWStepVisual_RWCameraModel::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModel> &) const ) &RWStepVisual_RWCameraModel::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCameraModelD2.hxx
	py::class_<RWStepVisual_RWCameraModelD2, std::unique_ptr<RWStepVisual_RWCameraModelD2, Deleter<RWStepVisual_RWCameraModelD2>>> cls_RWStepVisual_RWCameraModelD2(mod, "RWStepVisual_RWCameraModelD2", "Read & Write Module for CameraModelD2");
	cls_RWStepVisual_RWCameraModelD2.def(py::init<>());
	cls_RWStepVisual_RWCameraModelD2.def("ReadStep", (void (RWStepVisual_RWCameraModelD2::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD2> &) const ) &RWStepVisual_RWCameraModelD2::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD2.def("WriteStep", (void (RWStepVisual_RWCameraModelD2::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD2> &) const ) &RWStepVisual_RWCameraModelD2::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD2.def("Share", (void (RWStepVisual_RWCameraModelD2::*)(const opencascade::handle<StepVisual_CameraModelD2> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCameraModelD2::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCameraModelD3.hxx
	py::class_<RWStepVisual_RWCameraModelD3, std::unique_ptr<RWStepVisual_RWCameraModelD3, Deleter<RWStepVisual_RWCameraModelD3>>> cls_RWStepVisual_RWCameraModelD3(mod, "RWStepVisual_RWCameraModelD3", "Read & Write Module for CameraModelD3");
	cls_RWStepVisual_RWCameraModelD3.def(py::init<>());
	cls_RWStepVisual_RWCameraModelD3.def("ReadStep", (void (RWStepVisual_RWCameraModelD3::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD3> &) const ) &RWStepVisual_RWCameraModelD3::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD3.def("WriteStep", (void (RWStepVisual_RWCameraModelD3::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD3> &) const ) &RWStepVisual_RWCameraModelD3::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD3.def("Share", (void (RWStepVisual_RWCameraModelD3::*)(const opencascade::handle<StepVisual_CameraModelD3> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCameraModelD3::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCameraModelD3MultiClipping.hxx
	py::class_<RWStepVisual_RWCameraModelD3MultiClipping, std::unique_ptr<RWStepVisual_RWCameraModelD3MultiClipping, Deleter<RWStepVisual_RWCameraModelD3MultiClipping>>> cls_RWStepVisual_RWCameraModelD3MultiClipping(mod, "RWStepVisual_RWCameraModelD3MultiClipping", "Read & Write Module for CameraModelD3MultiClipping");
	cls_RWStepVisual_RWCameraModelD3MultiClipping.def(py::init<>());
	cls_RWStepVisual_RWCameraModelD3MultiClipping.def("ReadStep", (void (RWStepVisual_RWCameraModelD3MultiClipping::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD3MultiClipping> &) const ) &RWStepVisual_RWCameraModelD3MultiClipping::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD3MultiClipping.def("WriteStep", (void (RWStepVisual_RWCameraModelD3MultiClipping::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD3MultiClipping> &) const ) &RWStepVisual_RWCameraModelD3MultiClipping::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD3MultiClipping.def("Share", (void (RWStepVisual_RWCameraModelD3MultiClipping::*)(const opencascade::handle<StepVisual_CameraModelD3MultiClipping> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCameraModelD3MultiClipping::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCameraModelD3MultiClippingIntersection.hxx
	py::class_<RWStepVisual_RWCameraModelD3MultiClippingIntersection, std::unique_ptr<RWStepVisual_RWCameraModelD3MultiClippingIntersection, Deleter<RWStepVisual_RWCameraModelD3MultiClippingIntersection>>> cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection(mod, "RWStepVisual_RWCameraModelD3MultiClippingIntersection", "Read & Write Module for CameraModelD3MultiClippingIntersection");
	cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def(py::init<>());
	cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def("ReadStep", (void (RWStepVisual_RWCameraModelD3MultiClippingIntersection::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection> &) const ) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def("WriteStep", (void (RWStepVisual_RWCameraModelD3MultiClippingIntersection::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection> &) const ) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def("Share", (void (RWStepVisual_RWCameraModelD3MultiClippingIntersection::*)(const opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCameraModelD3MultiClippingUnion.hxx
	py::class_<RWStepVisual_RWCameraModelD3MultiClippingUnion, std::unique_ptr<RWStepVisual_RWCameraModelD3MultiClippingUnion, Deleter<RWStepVisual_RWCameraModelD3MultiClippingUnion>>> cls_RWStepVisual_RWCameraModelD3MultiClippingUnion(mod, "RWStepVisual_RWCameraModelD3MultiClippingUnion", "Read & Write Module for CameraModelD3MultiClippingUnion");
	cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def(py::init<>());
	cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def("ReadStep", (void (RWStepVisual_RWCameraModelD3MultiClippingUnion::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD3MultiClippingUnion> &) const ) &RWStepVisual_RWCameraModelD3MultiClippingUnion::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def("WriteStep", (void (RWStepVisual_RWCameraModelD3MultiClippingUnion::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD3MultiClippingUnion> &) const ) &RWStepVisual_RWCameraModelD3MultiClippingUnion::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def("Share", (void (RWStepVisual_RWCameraModelD3MultiClippingUnion::*)(const opencascade::handle<StepVisual_CameraModelD3MultiClippingUnion> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCameraModelD3MultiClippingUnion::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCameraUsage.hxx
	py::class_<RWStepVisual_RWCameraUsage, std::unique_ptr<RWStepVisual_RWCameraUsage, Deleter<RWStepVisual_RWCameraUsage>>> cls_RWStepVisual_RWCameraUsage(mod, "RWStepVisual_RWCameraUsage", "Read & Write Module for CameraUsage");
	cls_RWStepVisual_RWCameraUsage.def(py::init<>());
	cls_RWStepVisual_RWCameraUsage.def("ReadStep", (void (RWStepVisual_RWCameraUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraUsage> &) const ) &RWStepVisual_RWCameraUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCameraUsage.def("WriteStep", (void (RWStepVisual_RWCameraUsage::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraUsage> &) const ) &RWStepVisual_RWCameraUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCameraUsage.def("Share", (void (RWStepVisual_RWCameraUsage::*)(const opencascade::handle<StepVisual_CameraUsage> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCameraUsage::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.hxx
	py::class_<RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation, std::unique_ptr<RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation, Deleter<RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation>>> cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation(mod, "RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation", "Read & Write Module for complex STEP entity Characterized_Object & Characterized_Representation & Draughting_Model & Representation");
	cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def(py::init<>());
	cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def("ReadStep", (void (RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation> &) const ) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def("WriteStep", (void (RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation> &) const ) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def("Share", (void (RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::*)(const opencascade::handle<StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWColour.hxx
	py::class_<RWStepVisual_RWColour, std::unique_ptr<RWStepVisual_RWColour, Deleter<RWStepVisual_RWColour>>> cls_RWStepVisual_RWColour(mod, "RWStepVisual_RWColour", "Read & Write Module for Colour");
	cls_RWStepVisual_RWColour.def(py::init<>());
	cls_RWStepVisual_RWColour.def("ReadStep", (void (RWStepVisual_RWColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_Colour> &) const ) &RWStepVisual_RWColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWColour.def("WriteStep", (void (RWStepVisual_RWColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_Colour> &) const ) &RWStepVisual_RWColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWColourRgb.hxx
	py::class_<RWStepVisual_RWColourRgb, std::unique_ptr<RWStepVisual_RWColourRgb, Deleter<RWStepVisual_RWColourRgb>>> cls_RWStepVisual_RWColourRgb(mod, "RWStepVisual_RWColourRgb", "Read & Write Module for ColourRgb");
	cls_RWStepVisual_RWColourRgb.def(py::init<>());
	cls_RWStepVisual_RWColourRgb.def("ReadStep", (void (RWStepVisual_RWColourRgb::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ColourRgb> &) const ) &RWStepVisual_RWColourRgb::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWColourRgb.def("WriteStep", (void (RWStepVisual_RWColourRgb::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ColourRgb> &) const ) &RWStepVisual_RWColourRgb::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWColourSpecification.hxx
	py::class_<RWStepVisual_RWColourSpecification, std::unique_ptr<RWStepVisual_RWColourSpecification, Deleter<RWStepVisual_RWColourSpecification>>> cls_RWStepVisual_RWColourSpecification(mod, "RWStepVisual_RWColourSpecification", "Read & Write Module for ColourSpecification");
	cls_RWStepVisual_RWColourSpecification.def(py::init<>());
	cls_RWStepVisual_RWColourSpecification.def("ReadStep", (void (RWStepVisual_RWColourSpecification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ColourSpecification> &) const ) &RWStepVisual_RWColourSpecification::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWColourSpecification.def("WriteStep", (void (RWStepVisual_RWColourSpecification::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ColourSpecification> &) const ) &RWStepVisual_RWColourSpecification::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCompositeText.hxx
	py::class_<RWStepVisual_RWCompositeText, std::unique_ptr<RWStepVisual_RWCompositeText, Deleter<RWStepVisual_RWCompositeText>>> cls_RWStepVisual_RWCompositeText(mod, "RWStepVisual_RWCompositeText", "Read & Write Module for CompositeText");
	cls_RWStepVisual_RWCompositeText.def(py::init<>());
	cls_RWStepVisual_RWCompositeText.def("ReadStep", (void (RWStepVisual_RWCompositeText::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CompositeText> &) const ) &RWStepVisual_RWCompositeText::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCompositeText.def("WriteStep", (void (RWStepVisual_RWCompositeText::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CompositeText> &) const ) &RWStepVisual_RWCompositeText::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCompositeText.def("Share", (void (RWStepVisual_RWCompositeText::*)(const opencascade::handle<StepVisual_CompositeText> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCompositeText::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCompositeTextWithExtent.hxx
	py::class_<RWStepVisual_RWCompositeTextWithExtent, std::unique_ptr<RWStepVisual_RWCompositeTextWithExtent, Deleter<RWStepVisual_RWCompositeTextWithExtent>>> cls_RWStepVisual_RWCompositeTextWithExtent(mod, "RWStepVisual_RWCompositeTextWithExtent", "Read & Write Module for CompositeTextWithExtent");
	cls_RWStepVisual_RWCompositeTextWithExtent.def(py::init<>());
	cls_RWStepVisual_RWCompositeTextWithExtent.def("ReadStep", (void (RWStepVisual_RWCompositeTextWithExtent::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CompositeTextWithExtent> &) const ) &RWStepVisual_RWCompositeTextWithExtent::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCompositeTextWithExtent.def("WriteStep", (void (RWStepVisual_RWCompositeTextWithExtent::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CompositeTextWithExtent> &) const ) &RWStepVisual_RWCompositeTextWithExtent::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCompositeTextWithExtent.def("Share", (void (RWStepVisual_RWCompositeTextWithExtent::*)(const opencascade::handle<StepVisual_CompositeTextWithExtent> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCompositeTextWithExtent::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWContextDependentInvisibility.hxx
	py::class_<RWStepVisual_RWContextDependentInvisibility, std::unique_ptr<RWStepVisual_RWContextDependentInvisibility, Deleter<RWStepVisual_RWContextDependentInvisibility>>> cls_RWStepVisual_RWContextDependentInvisibility(mod, "RWStepVisual_RWContextDependentInvisibility", "Read & Write Module for ContextDependentInvisibility");
	cls_RWStepVisual_RWContextDependentInvisibility.def(py::init<>());
	cls_RWStepVisual_RWContextDependentInvisibility.def("ReadStep", (void (RWStepVisual_RWContextDependentInvisibility::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ContextDependentInvisibility> &) const ) &RWStepVisual_RWContextDependentInvisibility::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWContextDependentInvisibility.def("WriteStep", (void (RWStepVisual_RWContextDependentInvisibility::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ContextDependentInvisibility> &) const ) &RWStepVisual_RWContextDependentInvisibility::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWContextDependentInvisibility.def("Share", (void (RWStepVisual_RWContextDependentInvisibility::*)(const opencascade::handle<StepVisual_ContextDependentInvisibility> &, Interface_EntityIterator &) const ) &RWStepVisual_RWContextDependentInvisibility::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWContextDependentOverRidingStyledItem.hxx
	py::class_<RWStepVisual_RWContextDependentOverRidingStyledItem, std::unique_ptr<RWStepVisual_RWContextDependentOverRidingStyledItem, Deleter<RWStepVisual_RWContextDependentOverRidingStyledItem>>> cls_RWStepVisual_RWContextDependentOverRidingStyledItem(mod, "RWStepVisual_RWContextDependentOverRidingStyledItem", "Read & Write Module for ContextDependentOverRidingStyledItem");
	cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def(py::init<>());
	cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def("ReadStep", (void (RWStepVisual_RWContextDependentOverRidingStyledItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ContextDependentOverRidingStyledItem> &) const ) &RWStepVisual_RWContextDependentOverRidingStyledItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def("WriteStep", (void (RWStepVisual_RWContextDependentOverRidingStyledItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ContextDependentOverRidingStyledItem> &) const ) &RWStepVisual_RWContextDependentOverRidingStyledItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def("Share", (void (RWStepVisual_RWContextDependentOverRidingStyledItem::*)(const opencascade::handle<StepVisual_ContextDependentOverRidingStyledItem> &, Interface_EntityIterator &) const ) &RWStepVisual_RWContextDependentOverRidingStyledItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCoordinatesList.hxx
	py::class_<RWStepVisual_RWCoordinatesList, std::unique_ptr<RWStepVisual_RWCoordinatesList, Deleter<RWStepVisual_RWCoordinatesList>>> cls_RWStepVisual_RWCoordinatesList(mod, "RWStepVisual_RWCoordinatesList", "Read & Write Module for AnnotationOccurrence");
	cls_RWStepVisual_RWCoordinatesList.def(py::init<>());
	cls_RWStepVisual_RWCoordinatesList.def("ReadStep", (void (RWStepVisual_RWCoordinatesList::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CoordinatesList> &) const ) &RWStepVisual_RWCoordinatesList::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCoordinatesList.def("WriteStep", (void (RWStepVisual_RWCoordinatesList::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CoordinatesList> &) const ) &RWStepVisual_RWCoordinatesList::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCurveStyle.hxx
	py::class_<RWStepVisual_RWCurveStyle, std::unique_ptr<RWStepVisual_RWCurveStyle, Deleter<RWStepVisual_RWCurveStyle>>> cls_RWStepVisual_RWCurveStyle(mod, "RWStepVisual_RWCurveStyle", "Read & Write Module for CurveStyle");
	cls_RWStepVisual_RWCurveStyle.def(py::init<>());
	cls_RWStepVisual_RWCurveStyle.def("ReadStep", (void (RWStepVisual_RWCurveStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CurveStyle> &) const ) &RWStepVisual_RWCurveStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCurveStyle.def("WriteStep", (void (RWStepVisual_RWCurveStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CurveStyle> &) const ) &RWStepVisual_RWCurveStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCurveStyle.def("Share", (void (RWStepVisual_RWCurveStyle::*)(const opencascade::handle<StepVisual_CurveStyle> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCurveStyle::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCurveStyleFont.hxx
	py::class_<RWStepVisual_RWCurveStyleFont, std::unique_ptr<RWStepVisual_RWCurveStyleFont, Deleter<RWStepVisual_RWCurveStyleFont>>> cls_RWStepVisual_RWCurveStyleFont(mod, "RWStepVisual_RWCurveStyleFont", "Read & Write Module for CurveStyleFont");
	cls_RWStepVisual_RWCurveStyleFont.def(py::init<>());
	cls_RWStepVisual_RWCurveStyleFont.def("ReadStep", (void (RWStepVisual_RWCurveStyleFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CurveStyleFont> &) const ) &RWStepVisual_RWCurveStyleFont::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCurveStyleFont.def("WriteStep", (void (RWStepVisual_RWCurveStyleFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CurveStyleFont> &) const ) &RWStepVisual_RWCurveStyleFont::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWCurveStyleFont.def("Share", (void (RWStepVisual_RWCurveStyleFont::*)(const opencascade::handle<StepVisual_CurveStyleFont> &, Interface_EntityIterator &) const ) &RWStepVisual_RWCurveStyleFont::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWCurveStyleFontPattern.hxx
	py::class_<RWStepVisual_RWCurveStyleFontPattern, std::unique_ptr<RWStepVisual_RWCurveStyleFontPattern, Deleter<RWStepVisual_RWCurveStyleFontPattern>>> cls_RWStepVisual_RWCurveStyleFontPattern(mod, "RWStepVisual_RWCurveStyleFontPattern", "Read & Write Module for CurveStyleFontPattern");
	cls_RWStepVisual_RWCurveStyleFontPattern.def(py::init<>());
	cls_RWStepVisual_RWCurveStyleFontPattern.def("ReadStep", (void (RWStepVisual_RWCurveStyleFontPattern::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CurveStyleFontPattern> &) const ) &RWStepVisual_RWCurveStyleFontPattern::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWCurveStyleFontPattern.def("WriteStep", (void (RWStepVisual_RWCurveStyleFontPattern::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CurveStyleFontPattern> &) const ) &RWStepVisual_RWCurveStyleFontPattern::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWDraughtingCallout.hxx
	py::class_<RWStepVisual_RWDraughtingCallout, std::unique_ptr<RWStepVisual_RWDraughtingCallout, Deleter<RWStepVisual_RWDraughtingCallout>>> cls_RWStepVisual_RWDraughtingCallout(mod, "RWStepVisual_RWDraughtingCallout", "Read & Write Module for DraughtingCallout");
	cls_RWStepVisual_RWDraughtingCallout.def(py::init<>());
	cls_RWStepVisual_RWDraughtingCallout.def("ReadStep", (void (RWStepVisual_RWDraughtingCallout::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_DraughtingCallout> &) const ) &RWStepVisual_RWDraughtingCallout::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWDraughtingCallout.def("WriteStep", (void (RWStepVisual_RWDraughtingCallout::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_DraughtingCallout> &) const ) &RWStepVisual_RWDraughtingCallout::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWDraughtingCallout.def("Share", (void (RWStepVisual_RWDraughtingCallout::*)(const opencascade::handle<StepVisual_DraughtingCallout> &, Interface_EntityIterator &) const ) &RWStepVisual_RWDraughtingCallout::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWDraughtingModel.hxx
	py::class_<RWStepVisual_RWDraughtingModel, std::unique_ptr<RWStepVisual_RWDraughtingModel, Deleter<RWStepVisual_RWDraughtingModel>>> cls_RWStepVisual_RWDraughtingModel(mod, "RWStepVisual_RWDraughtingModel", "Read & Write tool for DraughtingModel");
	cls_RWStepVisual_RWDraughtingModel.def(py::init<>());
	cls_RWStepVisual_RWDraughtingModel.def("ReadStep", (void (RWStepVisual_RWDraughtingModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_DraughtingModel> &) const ) &RWStepVisual_RWDraughtingModel::ReadStep, "Reads DraughtingModel", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWDraughtingModel.def("WriteStep", (void (RWStepVisual_RWDraughtingModel::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_DraughtingModel> &) const ) &RWStepVisual_RWDraughtingModel::WriteStep, "Writes DraughtingModel", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWDraughtingModel.def("Share", (void (RWStepVisual_RWDraughtingModel::*)(const opencascade::handle<StepVisual_DraughtingModel> &, Interface_EntityIterator &) const ) &RWStepVisual_RWDraughtingModel::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWDraughtingPreDefinedColour.hxx
	py::class_<RWStepVisual_RWDraughtingPreDefinedColour, std::unique_ptr<RWStepVisual_RWDraughtingPreDefinedColour, Deleter<RWStepVisual_RWDraughtingPreDefinedColour>>> cls_RWStepVisual_RWDraughtingPreDefinedColour(mod, "RWStepVisual_RWDraughtingPreDefinedColour", "Read & Write Module for DraughtingPreDefinedColour");
	cls_RWStepVisual_RWDraughtingPreDefinedColour.def(py::init<>());
	cls_RWStepVisual_RWDraughtingPreDefinedColour.def("ReadStep", (void (RWStepVisual_RWDraughtingPreDefinedColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_DraughtingPreDefinedColour> &) const ) &RWStepVisual_RWDraughtingPreDefinedColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWDraughtingPreDefinedColour.def("WriteStep", (void (RWStepVisual_RWDraughtingPreDefinedColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_DraughtingPreDefinedColour> &) const ) &RWStepVisual_RWDraughtingPreDefinedColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWDraughtingPreDefinedCurveFont.hxx
	py::class_<RWStepVisual_RWDraughtingPreDefinedCurveFont, std::unique_ptr<RWStepVisual_RWDraughtingPreDefinedCurveFont, Deleter<RWStepVisual_RWDraughtingPreDefinedCurveFont>>> cls_RWStepVisual_RWDraughtingPreDefinedCurveFont(mod, "RWStepVisual_RWDraughtingPreDefinedCurveFont", "Read & Write Module for DraughtingPreDefinedCurveFont");
	cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def(py::init<>());
	cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def("ReadStep", (void (RWStepVisual_RWDraughtingPreDefinedCurveFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_DraughtingPreDefinedCurveFont> &) const ) &RWStepVisual_RWDraughtingPreDefinedCurveFont::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def("WriteStep", (void (RWStepVisual_RWDraughtingPreDefinedCurveFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_DraughtingPreDefinedCurveFont> &) const ) &RWStepVisual_RWDraughtingPreDefinedCurveFont::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWExternallyDefinedCurveFont.hxx
	py::class_<RWStepVisual_RWExternallyDefinedCurveFont, std::unique_ptr<RWStepVisual_RWExternallyDefinedCurveFont, Deleter<RWStepVisual_RWExternallyDefinedCurveFont>>> cls_RWStepVisual_RWExternallyDefinedCurveFont(mod, "RWStepVisual_RWExternallyDefinedCurveFont", "Read & Write tool for ExternallyDefinedCurveFont");
	cls_RWStepVisual_RWExternallyDefinedCurveFont.def(py::init<>());
	cls_RWStepVisual_RWExternallyDefinedCurveFont.def("ReadStep", (void (RWStepVisual_RWExternallyDefinedCurveFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ExternallyDefinedCurveFont> &) const ) &RWStepVisual_RWExternallyDefinedCurveFont::ReadStep, "Reads ExternallyDefinedCurveFont", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWExternallyDefinedCurveFont.def("WriteStep", (void (RWStepVisual_RWExternallyDefinedCurveFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ExternallyDefinedCurveFont> &) const ) &RWStepVisual_RWExternallyDefinedCurveFont::WriteStep, "Writes ExternallyDefinedCurveFont", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWExternallyDefinedCurveFont.def("Share", (void (RWStepVisual_RWExternallyDefinedCurveFont::*)(const opencascade::handle<StepVisual_ExternallyDefinedCurveFont> &, Interface_EntityIterator &) const ) &RWStepVisual_RWExternallyDefinedCurveFont::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWFillAreaStyle.hxx
	py::class_<RWStepVisual_RWFillAreaStyle, std::unique_ptr<RWStepVisual_RWFillAreaStyle, Deleter<RWStepVisual_RWFillAreaStyle>>> cls_RWStepVisual_RWFillAreaStyle(mod, "RWStepVisual_RWFillAreaStyle", "Read & Write Module for FillAreaStyle");
	cls_RWStepVisual_RWFillAreaStyle.def(py::init<>());
	cls_RWStepVisual_RWFillAreaStyle.def("ReadStep", (void (RWStepVisual_RWFillAreaStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_FillAreaStyle> &) const ) &RWStepVisual_RWFillAreaStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWFillAreaStyle.def("WriteStep", (void (RWStepVisual_RWFillAreaStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_FillAreaStyle> &) const ) &RWStepVisual_RWFillAreaStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWFillAreaStyle.def("Share", (void (RWStepVisual_RWFillAreaStyle::*)(const opencascade::handle<StepVisual_FillAreaStyle> &, Interface_EntityIterator &) const ) &RWStepVisual_RWFillAreaStyle::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWFillAreaStyleColour.hxx
	py::class_<RWStepVisual_RWFillAreaStyleColour, std::unique_ptr<RWStepVisual_RWFillAreaStyleColour, Deleter<RWStepVisual_RWFillAreaStyleColour>>> cls_RWStepVisual_RWFillAreaStyleColour(mod, "RWStepVisual_RWFillAreaStyleColour", "Read & Write Module for FillAreaStyleColour");
	cls_RWStepVisual_RWFillAreaStyleColour.def(py::init<>());
	cls_RWStepVisual_RWFillAreaStyleColour.def("ReadStep", (void (RWStepVisual_RWFillAreaStyleColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_FillAreaStyleColour> &) const ) &RWStepVisual_RWFillAreaStyleColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWFillAreaStyleColour.def("WriteStep", (void (RWStepVisual_RWFillAreaStyleColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_FillAreaStyleColour> &) const ) &RWStepVisual_RWFillAreaStyleColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWFillAreaStyleColour.def("Share", (void (RWStepVisual_RWFillAreaStyleColour::*)(const opencascade::handle<StepVisual_FillAreaStyleColour> &, Interface_EntityIterator &) const ) &RWStepVisual_RWFillAreaStyleColour::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWInvisibility.hxx
	py::class_<RWStepVisual_RWInvisibility, std::unique_ptr<RWStepVisual_RWInvisibility, Deleter<RWStepVisual_RWInvisibility>>> cls_RWStepVisual_RWInvisibility(mod, "RWStepVisual_RWInvisibility", "Read & Write Module for Invisibility");
	cls_RWStepVisual_RWInvisibility.def(py::init<>());
	cls_RWStepVisual_RWInvisibility.def("ReadStep", (void (RWStepVisual_RWInvisibility::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_Invisibility> &) const ) &RWStepVisual_RWInvisibility::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWInvisibility.def("WriteStep", (void (RWStepVisual_RWInvisibility::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_Invisibility> &) const ) &RWStepVisual_RWInvisibility::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWInvisibility.def("Share", (void (RWStepVisual_RWInvisibility::*)(const opencascade::handle<StepVisual_Invisibility> &, Interface_EntityIterator &) const ) &RWStepVisual_RWInvisibility::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWMechanicalDesignGeometricPresentationArea.hxx
	py::class_<RWStepVisual_RWMechanicalDesignGeometricPresentationArea, std::unique_ptr<RWStepVisual_RWMechanicalDesignGeometricPresentationArea, Deleter<RWStepVisual_RWMechanicalDesignGeometricPresentationArea>>> cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea(mod, "RWStepVisual_RWMechanicalDesignGeometricPresentationArea", "Read & Write Module for MechanicalDesignGeometricPresentationArea");
	cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def(py::init<>());
	cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def("ReadStep", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationArea> &) const ) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def("WriteStep", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationArea> &) const ) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def("Share", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationArea::*)(const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationArea> &, Interface_EntityIterator &) const ) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.hxx
	py::class_<RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation, std::unique_ptr<RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation, Deleter<RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation>>> cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation(mod, "RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation", "Read & Write Module for MechanicalDesignGeometricPresentationRepresentation");
	cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def(py::init<>());
	cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def("ReadStep", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> &) const ) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def("WriteStep", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> &) const ) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def("Share", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::*)(const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> &, Interface_EntityIterator &) const ) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWOverRidingStyledItem.hxx
	py::class_<RWStepVisual_RWOverRidingStyledItem, std::unique_ptr<RWStepVisual_RWOverRidingStyledItem, Deleter<RWStepVisual_RWOverRidingStyledItem>>> cls_RWStepVisual_RWOverRidingStyledItem(mod, "RWStepVisual_RWOverRidingStyledItem", "Read & Write Module for OverRidingStyledItem");
	cls_RWStepVisual_RWOverRidingStyledItem.def(py::init<>());
	cls_RWStepVisual_RWOverRidingStyledItem.def("ReadStep", (void (RWStepVisual_RWOverRidingStyledItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_OverRidingStyledItem> &) const ) &RWStepVisual_RWOverRidingStyledItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWOverRidingStyledItem.def("WriteStep", (void (RWStepVisual_RWOverRidingStyledItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_OverRidingStyledItem> &) const ) &RWStepVisual_RWOverRidingStyledItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWOverRidingStyledItem.def("Share", (void (RWStepVisual_RWOverRidingStyledItem::*)(const opencascade::handle<StepVisual_OverRidingStyledItem> &, Interface_EntityIterator &) const ) &RWStepVisual_RWOverRidingStyledItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPlanarBox.hxx
	py::class_<RWStepVisual_RWPlanarBox, std::unique_ptr<RWStepVisual_RWPlanarBox, Deleter<RWStepVisual_RWPlanarBox>>> cls_RWStepVisual_RWPlanarBox(mod, "RWStepVisual_RWPlanarBox", "Read & Write Module for PlanarBox");
	cls_RWStepVisual_RWPlanarBox.def(py::init<>());
	cls_RWStepVisual_RWPlanarBox.def("ReadStep", (void (RWStepVisual_RWPlanarBox::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PlanarBox> &) const ) &RWStepVisual_RWPlanarBox::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPlanarBox.def("WriteStep", (void (RWStepVisual_RWPlanarBox::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PlanarBox> &) const ) &RWStepVisual_RWPlanarBox::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPlanarBox.def("Share", (void (RWStepVisual_RWPlanarBox::*)(const opencascade::handle<StepVisual_PlanarBox> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPlanarBox::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPlanarExtent.hxx
	py::class_<RWStepVisual_RWPlanarExtent, std::unique_ptr<RWStepVisual_RWPlanarExtent, Deleter<RWStepVisual_RWPlanarExtent>>> cls_RWStepVisual_RWPlanarExtent(mod, "RWStepVisual_RWPlanarExtent", "Read & Write Module for PlanarExtent");
	cls_RWStepVisual_RWPlanarExtent.def(py::init<>());
	cls_RWStepVisual_RWPlanarExtent.def("ReadStep", (void (RWStepVisual_RWPlanarExtent::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PlanarExtent> &) const ) &RWStepVisual_RWPlanarExtent::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPlanarExtent.def("WriteStep", (void (RWStepVisual_RWPlanarExtent::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PlanarExtent> &) const ) &RWStepVisual_RWPlanarExtent::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPointStyle.hxx
	py::class_<RWStepVisual_RWPointStyle, std::unique_ptr<RWStepVisual_RWPointStyle, Deleter<RWStepVisual_RWPointStyle>>> cls_RWStepVisual_RWPointStyle(mod, "RWStepVisual_RWPointStyle", "Read & Write Module for PointStyle");
	cls_RWStepVisual_RWPointStyle.def(py::init<>());
	cls_RWStepVisual_RWPointStyle.def("ReadStep", (void (RWStepVisual_RWPointStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PointStyle> &) const ) &RWStepVisual_RWPointStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPointStyle.def("WriteStep", (void (RWStepVisual_RWPointStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PointStyle> &) const ) &RWStepVisual_RWPointStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPointStyle.def("Share", (void (RWStepVisual_RWPointStyle::*)(const opencascade::handle<StepVisual_PointStyle> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPointStyle::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPreDefinedColour.hxx
	py::class_<RWStepVisual_RWPreDefinedColour, std::unique_ptr<RWStepVisual_RWPreDefinedColour, Deleter<RWStepVisual_RWPreDefinedColour>>> cls_RWStepVisual_RWPreDefinedColour(mod, "RWStepVisual_RWPreDefinedColour", "Read & Write Module for PreDefinedColour");
	cls_RWStepVisual_RWPreDefinedColour.def(py::init<>());
	cls_RWStepVisual_RWPreDefinedColour.def("ReadStep", (void (RWStepVisual_RWPreDefinedColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PreDefinedColour> &) const ) &RWStepVisual_RWPreDefinedColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPreDefinedColour.def("WriteStep", (void (RWStepVisual_RWPreDefinedColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PreDefinedColour> &) const ) &RWStepVisual_RWPreDefinedColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPreDefinedCurveFont.hxx
	py::class_<RWStepVisual_RWPreDefinedCurveFont, std::unique_ptr<RWStepVisual_RWPreDefinedCurveFont, Deleter<RWStepVisual_RWPreDefinedCurveFont>>> cls_RWStepVisual_RWPreDefinedCurveFont(mod, "RWStepVisual_RWPreDefinedCurveFont", "Read & Write Module for PreDefinedCurveFont");
	cls_RWStepVisual_RWPreDefinedCurveFont.def(py::init<>());
	cls_RWStepVisual_RWPreDefinedCurveFont.def("ReadStep", (void (RWStepVisual_RWPreDefinedCurveFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PreDefinedCurveFont> &) const ) &RWStepVisual_RWPreDefinedCurveFont::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPreDefinedCurveFont.def("WriteStep", (void (RWStepVisual_RWPreDefinedCurveFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PreDefinedCurveFont> &) const ) &RWStepVisual_RWPreDefinedCurveFont::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPreDefinedItem.hxx
	py::class_<RWStepVisual_RWPreDefinedItem, std::unique_ptr<RWStepVisual_RWPreDefinedItem, Deleter<RWStepVisual_RWPreDefinedItem>>> cls_RWStepVisual_RWPreDefinedItem(mod, "RWStepVisual_RWPreDefinedItem", "Read & Write Module for PreDefinedItem");
	cls_RWStepVisual_RWPreDefinedItem.def(py::init<>());
	cls_RWStepVisual_RWPreDefinedItem.def("ReadStep", (void (RWStepVisual_RWPreDefinedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PreDefinedItem> &) const ) &RWStepVisual_RWPreDefinedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPreDefinedItem.def("WriteStep", (void (RWStepVisual_RWPreDefinedItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PreDefinedItem> &) const ) &RWStepVisual_RWPreDefinedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationArea.hxx
	py::class_<RWStepVisual_RWPresentationArea, std::unique_ptr<RWStepVisual_RWPresentationArea, Deleter<RWStepVisual_RWPresentationArea>>> cls_RWStepVisual_RWPresentationArea(mod, "RWStepVisual_RWPresentationArea", "Read & Write Module for PresentationArea");
	cls_RWStepVisual_RWPresentationArea.def(py::init<>());
	cls_RWStepVisual_RWPresentationArea.def("ReadStep", (void (RWStepVisual_RWPresentationArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationArea> &) const ) &RWStepVisual_RWPresentationArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationArea.def("WriteStep", (void (RWStepVisual_RWPresentationArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationArea> &) const ) &RWStepVisual_RWPresentationArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationArea.def("Share", (void (RWStepVisual_RWPresentationArea::*)(const opencascade::handle<StepVisual_PresentationArea> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentationArea::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationLayerAssignment.hxx
	py::class_<RWStepVisual_RWPresentationLayerAssignment, std::unique_ptr<RWStepVisual_RWPresentationLayerAssignment, Deleter<RWStepVisual_RWPresentationLayerAssignment>>> cls_RWStepVisual_RWPresentationLayerAssignment(mod, "RWStepVisual_RWPresentationLayerAssignment", "Read & Write Module for PresentationLayerAssignment");
	cls_RWStepVisual_RWPresentationLayerAssignment.def(py::init<>());
	cls_RWStepVisual_RWPresentationLayerAssignment.def("ReadStep", (void (RWStepVisual_RWPresentationLayerAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationLayerAssignment> &) const ) &RWStepVisual_RWPresentationLayerAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationLayerAssignment.def("WriteStep", (void (RWStepVisual_RWPresentationLayerAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationLayerAssignment> &) const ) &RWStepVisual_RWPresentationLayerAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationLayerAssignment.def("Share", (void (RWStepVisual_RWPresentationLayerAssignment::*)(const opencascade::handle<StepVisual_PresentationLayerAssignment> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentationLayerAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationLayerUsage.hxx
	py::class_<RWStepVisual_RWPresentationLayerUsage, std::unique_ptr<RWStepVisual_RWPresentationLayerUsage, Deleter<RWStepVisual_RWPresentationLayerUsage>>> cls_RWStepVisual_RWPresentationLayerUsage(mod, "RWStepVisual_RWPresentationLayerUsage", "Read & Write Module for PresentationLayerUsage");
	cls_RWStepVisual_RWPresentationLayerUsage.def(py::init<>());
	cls_RWStepVisual_RWPresentationLayerUsage.def("ReadStep", (void (RWStepVisual_RWPresentationLayerUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationLayerUsage> &) const ) &RWStepVisual_RWPresentationLayerUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationLayerUsage.def("WriteStep", (void (RWStepVisual_RWPresentationLayerUsage::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationLayerUsage> &) const ) &RWStepVisual_RWPresentationLayerUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationLayerUsage.def("Share", (void (RWStepVisual_RWPresentationLayerUsage::*)(const opencascade::handle<StepVisual_PresentationLayerUsage> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentationLayerUsage::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationRepresentation.hxx
	py::class_<RWStepVisual_RWPresentationRepresentation, std::unique_ptr<RWStepVisual_RWPresentationRepresentation, Deleter<RWStepVisual_RWPresentationRepresentation>>> cls_RWStepVisual_RWPresentationRepresentation(mod, "RWStepVisual_RWPresentationRepresentation", "Read & Write Module for PresentationRepresentation");
	cls_RWStepVisual_RWPresentationRepresentation.def(py::init<>());
	cls_RWStepVisual_RWPresentationRepresentation.def("ReadStep", (void (RWStepVisual_RWPresentationRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationRepresentation> &) const ) &RWStepVisual_RWPresentationRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationRepresentation.def("WriteStep", (void (RWStepVisual_RWPresentationRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationRepresentation> &) const ) &RWStepVisual_RWPresentationRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationRepresentation.def("Share", (void (RWStepVisual_RWPresentationRepresentation::*)(const opencascade::handle<StepVisual_PresentationRepresentation> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentationRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationSet.hxx
	py::class_<RWStepVisual_RWPresentationSet, std::unique_ptr<RWStepVisual_RWPresentationSet, Deleter<RWStepVisual_RWPresentationSet>>> cls_RWStepVisual_RWPresentationSet(mod, "RWStepVisual_RWPresentationSet", "Read & Write Module for PresentationSet");
	cls_RWStepVisual_RWPresentationSet.def(py::init<>());
	cls_RWStepVisual_RWPresentationSet.def("ReadStep", (void (RWStepVisual_RWPresentationSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationSet> &) const ) &RWStepVisual_RWPresentationSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationSet.def("WriteStep", (void (RWStepVisual_RWPresentationSet::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationSet> &) const ) &RWStepVisual_RWPresentationSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationSize.hxx
	py::class_<RWStepVisual_RWPresentationSize, std::unique_ptr<RWStepVisual_RWPresentationSize, Deleter<RWStepVisual_RWPresentationSize>>> cls_RWStepVisual_RWPresentationSize(mod, "RWStepVisual_RWPresentationSize", "Read & Write Module for PresentationSize");
	cls_RWStepVisual_RWPresentationSize.def(py::init<>());
	cls_RWStepVisual_RWPresentationSize.def("ReadStep", (void (RWStepVisual_RWPresentationSize::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationSize> &) const ) &RWStepVisual_RWPresentationSize::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationSize.def("WriteStep", (void (RWStepVisual_RWPresentationSize::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationSize> &) const ) &RWStepVisual_RWPresentationSize::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationSize.def("Share", (void (RWStepVisual_RWPresentationSize::*)(const opencascade::handle<StepVisual_PresentationSize> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentationSize::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationStyleAssignment.hxx
	py::class_<RWStepVisual_RWPresentationStyleAssignment, std::unique_ptr<RWStepVisual_RWPresentationStyleAssignment, Deleter<RWStepVisual_RWPresentationStyleAssignment>>> cls_RWStepVisual_RWPresentationStyleAssignment(mod, "RWStepVisual_RWPresentationStyleAssignment", "Read & Write Module for PresentationStyleAssignment");
	cls_RWStepVisual_RWPresentationStyleAssignment.def(py::init<>());
	cls_RWStepVisual_RWPresentationStyleAssignment.def("ReadStep", (void (RWStepVisual_RWPresentationStyleAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationStyleAssignment> &) const ) &RWStepVisual_RWPresentationStyleAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationStyleAssignment.def("WriteStep", (void (RWStepVisual_RWPresentationStyleAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationStyleAssignment> &) const ) &RWStepVisual_RWPresentationStyleAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationStyleAssignment.def("Share", (void (RWStepVisual_RWPresentationStyleAssignment::*)(const opencascade::handle<StepVisual_PresentationStyleAssignment> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentationStyleAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationStyleByContext.hxx
	py::class_<RWStepVisual_RWPresentationStyleByContext, std::unique_ptr<RWStepVisual_RWPresentationStyleByContext, Deleter<RWStepVisual_RWPresentationStyleByContext>>> cls_RWStepVisual_RWPresentationStyleByContext(mod, "RWStepVisual_RWPresentationStyleByContext", "Read & Write Module for PresentationStyleByContext");
	cls_RWStepVisual_RWPresentationStyleByContext.def(py::init<>());
	cls_RWStepVisual_RWPresentationStyleByContext.def("ReadStep", (void (RWStepVisual_RWPresentationStyleByContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationStyleByContext> &) const ) &RWStepVisual_RWPresentationStyleByContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationStyleByContext.def("WriteStep", (void (RWStepVisual_RWPresentationStyleByContext::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationStyleByContext> &) const ) &RWStepVisual_RWPresentationStyleByContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationStyleByContext.def("Share", (void (RWStepVisual_RWPresentationStyleByContext::*)(const opencascade::handle<StepVisual_PresentationStyleByContext> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentationStyleByContext::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentationView.hxx
	py::class_<RWStepVisual_RWPresentationView, std::unique_ptr<RWStepVisual_RWPresentationView, Deleter<RWStepVisual_RWPresentationView>>> cls_RWStepVisual_RWPresentationView(mod, "RWStepVisual_RWPresentationView", "Read & Write Module for PresentationView");
	cls_RWStepVisual_RWPresentationView.def(py::init<>());
	cls_RWStepVisual_RWPresentationView.def("ReadStep", (void (RWStepVisual_RWPresentationView::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationView> &) const ) &RWStepVisual_RWPresentationView::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationView.def("WriteStep", (void (RWStepVisual_RWPresentationView::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationView> &) const ) &RWStepVisual_RWPresentationView::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentationView.def("Share", (void (RWStepVisual_RWPresentationView::*)(const opencascade::handle<StepVisual_PresentationView> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentationView::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWPresentedItemRepresentation.hxx
	py::class_<RWStepVisual_RWPresentedItemRepresentation, std::unique_ptr<RWStepVisual_RWPresentedItemRepresentation, Deleter<RWStepVisual_RWPresentedItemRepresentation>>> cls_RWStepVisual_RWPresentedItemRepresentation(mod, "RWStepVisual_RWPresentedItemRepresentation", "Read & Write Module for PresentedItemRepresentation");
	cls_RWStepVisual_RWPresentedItemRepresentation.def(py::init<>());
	cls_RWStepVisual_RWPresentedItemRepresentation.def("ReadStep", (void (RWStepVisual_RWPresentedItemRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentedItemRepresentation> &) const ) &RWStepVisual_RWPresentedItemRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWPresentedItemRepresentation.def("WriteStep", (void (RWStepVisual_RWPresentedItemRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentedItemRepresentation> &) const ) &RWStepVisual_RWPresentedItemRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWPresentedItemRepresentation.def("Share", (void (RWStepVisual_RWPresentedItemRepresentation::*)(const opencascade::handle<StepVisual_PresentedItemRepresentation> &, Interface_EntityIterator &) const ) &RWStepVisual_RWPresentedItemRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWStyledItem.hxx
	py::class_<RWStepVisual_RWStyledItem, std::unique_ptr<RWStepVisual_RWStyledItem, Deleter<RWStepVisual_RWStyledItem>>> cls_RWStepVisual_RWStyledItem(mod, "RWStepVisual_RWStyledItem", "Read & Write Module for StyledItem");
	cls_RWStepVisual_RWStyledItem.def(py::init<>());
	cls_RWStepVisual_RWStyledItem.def("ReadStep", (void (RWStepVisual_RWStyledItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_StyledItem> &) const ) &RWStepVisual_RWStyledItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWStyledItem.def("WriteStep", (void (RWStepVisual_RWStyledItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_StyledItem> &) const ) &RWStepVisual_RWStyledItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWStyledItem.def("Share", (void (RWStepVisual_RWStyledItem::*)(const opencascade::handle<StepVisual_StyledItem> &, Interface_EntityIterator &) const ) &RWStepVisual_RWStyledItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWSurfaceSideStyle.hxx
	py::class_<RWStepVisual_RWSurfaceSideStyle, std::unique_ptr<RWStepVisual_RWSurfaceSideStyle, Deleter<RWStepVisual_RWSurfaceSideStyle>>> cls_RWStepVisual_RWSurfaceSideStyle(mod, "RWStepVisual_RWSurfaceSideStyle", "Read & Write Module for SurfaceSideStyle");
	cls_RWStepVisual_RWSurfaceSideStyle.def(py::init<>());
	cls_RWStepVisual_RWSurfaceSideStyle.def("ReadStep", (void (RWStepVisual_RWSurfaceSideStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceSideStyle> &) const ) &RWStepVisual_RWSurfaceSideStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceSideStyle.def("WriteStep", (void (RWStepVisual_RWSurfaceSideStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceSideStyle> &) const ) &RWStepVisual_RWSurfaceSideStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceSideStyle.def("Share", (void (RWStepVisual_RWSurfaceSideStyle::*)(const opencascade::handle<StepVisual_SurfaceSideStyle> &, Interface_EntityIterator &) const ) &RWStepVisual_RWSurfaceSideStyle::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWSurfaceStyleBoundary.hxx
	py::class_<RWStepVisual_RWSurfaceStyleBoundary, std::unique_ptr<RWStepVisual_RWSurfaceStyleBoundary, Deleter<RWStepVisual_RWSurfaceStyleBoundary>>> cls_RWStepVisual_RWSurfaceStyleBoundary(mod, "RWStepVisual_RWSurfaceStyleBoundary", "Read & Write Module for SurfaceStyleBoundary");
	cls_RWStepVisual_RWSurfaceStyleBoundary.def(py::init<>());
	cls_RWStepVisual_RWSurfaceStyleBoundary.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleBoundary::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleBoundary> &) const ) &RWStepVisual_RWSurfaceStyleBoundary::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleBoundary.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleBoundary::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleBoundary> &) const ) &RWStepVisual_RWSurfaceStyleBoundary::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleBoundary.def("Share", (void (RWStepVisual_RWSurfaceStyleBoundary::*)(const opencascade::handle<StepVisual_SurfaceStyleBoundary> &, Interface_EntityIterator &) const ) &RWStepVisual_RWSurfaceStyleBoundary::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWSurfaceStyleControlGrid.hxx
	py::class_<RWStepVisual_RWSurfaceStyleControlGrid, std::unique_ptr<RWStepVisual_RWSurfaceStyleControlGrid, Deleter<RWStepVisual_RWSurfaceStyleControlGrid>>> cls_RWStepVisual_RWSurfaceStyleControlGrid(mod, "RWStepVisual_RWSurfaceStyleControlGrid", "Read & Write Module for SurfaceStyleControlGrid");
	cls_RWStepVisual_RWSurfaceStyleControlGrid.def(py::init<>());
	cls_RWStepVisual_RWSurfaceStyleControlGrid.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleControlGrid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleControlGrid> &) const ) &RWStepVisual_RWSurfaceStyleControlGrid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleControlGrid.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleControlGrid::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleControlGrid> &) const ) &RWStepVisual_RWSurfaceStyleControlGrid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleControlGrid.def("Share", (void (RWStepVisual_RWSurfaceStyleControlGrid::*)(const opencascade::handle<StepVisual_SurfaceStyleControlGrid> &, Interface_EntityIterator &) const ) &RWStepVisual_RWSurfaceStyleControlGrid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWSurfaceStyleFillArea.hxx
	py::class_<RWStepVisual_RWSurfaceStyleFillArea, std::unique_ptr<RWStepVisual_RWSurfaceStyleFillArea, Deleter<RWStepVisual_RWSurfaceStyleFillArea>>> cls_RWStepVisual_RWSurfaceStyleFillArea(mod, "RWStepVisual_RWSurfaceStyleFillArea", "Read & Write Module for SurfaceStyleFillArea");
	cls_RWStepVisual_RWSurfaceStyleFillArea.def(py::init<>());
	cls_RWStepVisual_RWSurfaceStyleFillArea.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleFillArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleFillArea> &) const ) &RWStepVisual_RWSurfaceStyleFillArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleFillArea.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleFillArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleFillArea> &) const ) &RWStepVisual_RWSurfaceStyleFillArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleFillArea.def("Share", (void (RWStepVisual_RWSurfaceStyleFillArea::*)(const opencascade::handle<StepVisual_SurfaceStyleFillArea> &, Interface_EntityIterator &) const ) &RWStepVisual_RWSurfaceStyleFillArea::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWSurfaceStyleParameterLine.hxx
	py::class_<RWStepVisual_RWSurfaceStyleParameterLine, std::unique_ptr<RWStepVisual_RWSurfaceStyleParameterLine, Deleter<RWStepVisual_RWSurfaceStyleParameterLine>>> cls_RWStepVisual_RWSurfaceStyleParameterLine(mod, "RWStepVisual_RWSurfaceStyleParameterLine", "Read & Write Module for SurfaceStyleParameterLine");
	cls_RWStepVisual_RWSurfaceStyleParameterLine.def(py::init<>());
	cls_RWStepVisual_RWSurfaceStyleParameterLine.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleParameterLine::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleParameterLine> &) const ) &RWStepVisual_RWSurfaceStyleParameterLine::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleParameterLine.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleParameterLine::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleParameterLine> &) const ) &RWStepVisual_RWSurfaceStyleParameterLine::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleParameterLine.def("Share", (void (RWStepVisual_RWSurfaceStyleParameterLine::*)(const opencascade::handle<StepVisual_SurfaceStyleParameterLine> &, Interface_EntityIterator &) const ) &RWStepVisual_RWSurfaceStyleParameterLine::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWSurfaceStyleSegmentationCurve.hxx
	py::class_<RWStepVisual_RWSurfaceStyleSegmentationCurve, std::unique_ptr<RWStepVisual_RWSurfaceStyleSegmentationCurve, Deleter<RWStepVisual_RWSurfaceStyleSegmentationCurve>>> cls_RWStepVisual_RWSurfaceStyleSegmentationCurve(mod, "RWStepVisual_RWSurfaceStyleSegmentationCurve", "Read & Write Module for SurfaceStyleSegmentationCurve");
	cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def(py::init<>());
	cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleSegmentationCurve::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleSegmentationCurve> &) const ) &RWStepVisual_RWSurfaceStyleSegmentationCurve::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleSegmentationCurve::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleSegmentationCurve> &) const ) &RWStepVisual_RWSurfaceStyleSegmentationCurve::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def("Share", (void (RWStepVisual_RWSurfaceStyleSegmentationCurve::*)(const opencascade::handle<StepVisual_SurfaceStyleSegmentationCurve> &, Interface_EntityIterator &) const ) &RWStepVisual_RWSurfaceStyleSegmentationCurve::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWSurfaceStyleSilhouette.hxx
	py::class_<RWStepVisual_RWSurfaceStyleSilhouette, std::unique_ptr<RWStepVisual_RWSurfaceStyleSilhouette, Deleter<RWStepVisual_RWSurfaceStyleSilhouette>>> cls_RWStepVisual_RWSurfaceStyleSilhouette(mod, "RWStepVisual_RWSurfaceStyleSilhouette", "Read & Write Module for SurfaceStyleSilhouette");
	cls_RWStepVisual_RWSurfaceStyleSilhouette.def(py::init<>());
	cls_RWStepVisual_RWSurfaceStyleSilhouette.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleSilhouette::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleSilhouette> &) const ) &RWStepVisual_RWSurfaceStyleSilhouette::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleSilhouette.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleSilhouette::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleSilhouette> &) const ) &RWStepVisual_RWSurfaceStyleSilhouette::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleSilhouette.def("Share", (void (RWStepVisual_RWSurfaceStyleSilhouette::*)(const opencascade::handle<StepVisual_SurfaceStyleSilhouette> &, Interface_EntityIterator &) const ) &RWStepVisual_RWSurfaceStyleSilhouette::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWSurfaceStyleUsage.hxx
	py::class_<RWStepVisual_RWSurfaceStyleUsage, std::unique_ptr<RWStepVisual_RWSurfaceStyleUsage, Deleter<RWStepVisual_RWSurfaceStyleUsage>>> cls_RWStepVisual_RWSurfaceStyleUsage(mod, "RWStepVisual_RWSurfaceStyleUsage", "Read & Write Module for SurfaceStyleUsage");
	cls_RWStepVisual_RWSurfaceStyleUsage.def(py::init<>());
	cls_RWStepVisual_RWSurfaceStyleUsage.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleUsage> &) const ) &RWStepVisual_RWSurfaceStyleUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleUsage.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleUsage::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleUsage> &) const ) &RWStepVisual_RWSurfaceStyleUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWSurfaceStyleUsage.def("Share", (void (RWStepVisual_RWSurfaceStyleUsage::*)(const opencascade::handle<StepVisual_SurfaceStyleUsage> &, Interface_EntityIterator &) const ) &RWStepVisual_RWSurfaceStyleUsage::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTemplate.hxx
	py::class_<RWStepVisual_RWTemplate, std::unique_ptr<RWStepVisual_RWTemplate, Deleter<RWStepVisual_RWTemplate>>> cls_RWStepVisual_RWTemplate(mod, "RWStepVisual_RWTemplate", "Read & Write Module for Template");
	cls_RWStepVisual_RWTemplate.def(py::init<>());
	cls_RWStepVisual_RWTemplate.def("ReadStep", (void (RWStepVisual_RWTemplate::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_Template> &) const ) &RWStepVisual_RWTemplate::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTemplate.def("WriteStep", (void (RWStepVisual_RWTemplate::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_Template> &) const ) &RWStepVisual_RWTemplate::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTemplate.def("Share", (void (RWStepVisual_RWTemplate::*)(const opencascade::handle<StepVisual_Template> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTemplate::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTemplateInstance.hxx
	py::class_<RWStepVisual_RWTemplateInstance, std::unique_ptr<RWStepVisual_RWTemplateInstance, Deleter<RWStepVisual_RWTemplateInstance>>> cls_RWStepVisual_RWTemplateInstance(mod, "RWStepVisual_RWTemplateInstance", "Read & Write Module for TemplateInstance");
	cls_RWStepVisual_RWTemplateInstance.def(py::init<>());
	cls_RWStepVisual_RWTemplateInstance.def("ReadStep", (void (RWStepVisual_RWTemplateInstance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TemplateInstance> &) const ) &RWStepVisual_RWTemplateInstance::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTemplateInstance.def("WriteStep", (void (RWStepVisual_RWTemplateInstance::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TemplateInstance> &) const ) &RWStepVisual_RWTemplateInstance::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTemplateInstance.def("Share", (void (RWStepVisual_RWTemplateInstance::*)(const opencascade::handle<StepVisual_TemplateInstance> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTemplateInstance::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTessellatedAnnotationOccurrence.hxx
	py::class_<RWStepVisual_RWTessellatedAnnotationOccurrence, std::unique_ptr<RWStepVisual_RWTessellatedAnnotationOccurrence, Deleter<RWStepVisual_RWTessellatedAnnotationOccurrence>>> cls_RWStepVisual_RWTessellatedAnnotationOccurrence(mod, "RWStepVisual_RWTessellatedAnnotationOccurrence", "Read & Write Module for AnnotationOccurrence");
	cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def(py::init<>());
	cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def("ReadStep", (void (RWStepVisual_RWTessellatedAnnotationOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TessellatedAnnotationOccurrence> &) const ) &RWStepVisual_RWTessellatedAnnotationOccurrence::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def("WriteStep", (void (RWStepVisual_RWTessellatedAnnotationOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TessellatedAnnotationOccurrence> &) const ) &RWStepVisual_RWTessellatedAnnotationOccurrence::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def("Share", (void (RWStepVisual_RWTessellatedAnnotationOccurrence::*)(const opencascade::handle<StepVisual_TessellatedAnnotationOccurrence> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTessellatedAnnotationOccurrence::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTessellatedCurveSet.hxx
	py::class_<RWStepVisual_RWTessellatedCurveSet, std::unique_ptr<RWStepVisual_RWTessellatedCurveSet, Deleter<RWStepVisual_RWTessellatedCurveSet>>> cls_RWStepVisual_RWTessellatedCurveSet(mod, "RWStepVisual_RWTessellatedCurveSet", "Read & Write Module for AnnotationOccurrence");
	cls_RWStepVisual_RWTessellatedCurveSet.def(py::init<>());
	cls_RWStepVisual_RWTessellatedCurveSet.def("ReadStep", (void (RWStepVisual_RWTessellatedCurveSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TessellatedCurveSet> &) const ) &RWStepVisual_RWTessellatedCurveSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTessellatedCurveSet.def("WriteStep", (void (RWStepVisual_RWTessellatedCurveSet::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TessellatedCurveSet> &) const ) &RWStepVisual_RWTessellatedCurveSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTessellatedCurveSet.def("Share", (void (RWStepVisual_RWTessellatedCurveSet::*)(const opencascade::handle<StepVisual_TessellatedCurveSet> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTessellatedCurveSet::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTessellatedGeometricSet.hxx
	py::class_<RWStepVisual_RWTessellatedGeometricSet, std::unique_ptr<RWStepVisual_RWTessellatedGeometricSet, Deleter<RWStepVisual_RWTessellatedGeometricSet>>> cls_RWStepVisual_RWTessellatedGeometricSet(mod, "RWStepVisual_RWTessellatedGeometricSet", "Read & Write Module for AnnotationOccurrence");
	cls_RWStepVisual_RWTessellatedGeometricSet.def(py::init<>());
	cls_RWStepVisual_RWTessellatedGeometricSet.def("ReadStep", (void (RWStepVisual_RWTessellatedGeometricSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TessellatedGeometricSet> &) const ) &RWStepVisual_RWTessellatedGeometricSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTessellatedGeometricSet.def("WriteStep", (void (RWStepVisual_RWTessellatedGeometricSet::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TessellatedGeometricSet> &) const ) &RWStepVisual_RWTessellatedGeometricSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTessellatedGeometricSet.def("Share", (void (RWStepVisual_RWTessellatedGeometricSet::*)(const opencascade::handle<StepVisual_TessellatedGeometricSet> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTessellatedGeometricSet::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTessellatedItem.hxx
	py::class_<RWStepVisual_RWTessellatedItem, std::unique_ptr<RWStepVisual_RWTessellatedItem, Deleter<RWStepVisual_RWTessellatedItem>>> cls_RWStepVisual_RWTessellatedItem(mod, "RWStepVisual_RWTessellatedItem", "Read & Write Module for AnnotationOccurrence");
	cls_RWStepVisual_RWTessellatedItem.def(py::init<>());
	cls_RWStepVisual_RWTessellatedItem.def("ReadStep", (void (RWStepVisual_RWTessellatedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TessellatedItem> &) const ) &RWStepVisual_RWTessellatedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTessellatedItem.def("WriteStep", (void (RWStepVisual_RWTessellatedItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TessellatedItem> &) const ) &RWStepVisual_RWTessellatedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTextLiteral.hxx
	py::class_<RWStepVisual_RWTextLiteral, std::unique_ptr<RWStepVisual_RWTextLiteral, Deleter<RWStepVisual_RWTextLiteral>>> cls_RWStepVisual_RWTextLiteral(mod, "RWStepVisual_RWTextLiteral", "Read & Write Module for TextLiteral");
	cls_RWStepVisual_RWTextLiteral.def(py::init<>());
	cls_RWStepVisual_RWTextLiteral.def("ReadStep", (void (RWStepVisual_RWTextLiteral::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TextLiteral> &) const ) &RWStepVisual_RWTextLiteral::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTextLiteral.def("WriteStep", (void (RWStepVisual_RWTextLiteral::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TextLiteral> &) const ) &RWStepVisual_RWTextLiteral::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTextLiteral.def("Share", (void (RWStepVisual_RWTextLiteral::*)(const opencascade::handle<StepVisual_TextLiteral> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTextLiteral::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTextStyle.hxx
	py::class_<RWStepVisual_RWTextStyle, std::unique_ptr<RWStepVisual_RWTextStyle, Deleter<RWStepVisual_RWTextStyle>>> cls_RWStepVisual_RWTextStyle(mod, "RWStepVisual_RWTextStyle", "Read & Write Module for TextStyle");
	cls_RWStepVisual_RWTextStyle.def(py::init<>());
	cls_RWStepVisual_RWTextStyle.def("ReadStep", (void (RWStepVisual_RWTextStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TextStyle> &) const ) &RWStepVisual_RWTextStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTextStyle.def("WriteStep", (void (RWStepVisual_RWTextStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TextStyle> &) const ) &RWStepVisual_RWTextStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTextStyle.def("Share", (void (RWStepVisual_RWTextStyle::*)(const opencascade::handle<StepVisual_TextStyle> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTextStyle::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTextStyleForDefinedFont.hxx
	py::class_<RWStepVisual_RWTextStyleForDefinedFont, std::unique_ptr<RWStepVisual_RWTextStyleForDefinedFont, Deleter<RWStepVisual_RWTextStyleForDefinedFont>>> cls_RWStepVisual_RWTextStyleForDefinedFont(mod, "RWStepVisual_RWTextStyleForDefinedFont", "Read & Write Module for TextStyleForDefinedFont");
	cls_RWStepVisual_RWTextStyleForDefinedFont.def(py::init<>());
	cls_RWStepVisual_RWTextStyleForDefinedFont.def("ReadStep", (void (RWStepVisual_RWTextStyleForDefinedFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TextStyleForDefinedFont> &) const ) &RWStepVisual_RWTextStyleForDefinedFont::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTextStyleForDefinedFont.def("WriteStep", (void (RWStepVisual_RWTextStyleForDefinedFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TextStyleForDefinedFont> &) const ) &RWStepVisual_RWTextStyleForDefinedFont::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTextStyleForDefinedFont.def("Share", (void (RWStepVisual_RWTextStyleForDefinedFont::*)(const opencascade::handle<StepVisual_TextStyleForDefinedFont> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTextStyleForDefinedFont::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWTextStyleWithBoxCharacteristics.hxx
	py::class_<RWStepVisual_RWTextStyleWithBoxCharacteristics, std::unique_ptr<RWStepVisual_RWTextStyleWithBoxCharacteristics, Deleter<RWStepVisual_RWTextStyleWithBoxCharacteristics>>> cls_RWStepVisual_RWTextStyleWithBoxCharacteristics(mod, "RWStepVisual_RWTextStyleWithBoxCharacteristics", "Read & Write Module for TextStyleWithBoxCharacteristics");
	cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def(py::init<>());
	cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def("ReadStep", (void (RWStepVisual_RWTextStyleWithBoxCharacteristics::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TextStyleWithBoxCharacteristics> &) const ) &RWStepVisual_RWTextStyleWithBoxCharacteristics::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def("WriteStep", (void (RWStepVisual_RWTextStyleWithBoxCharacteristics::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TextStyleWithBoxCharacteristics> &) const ) &RWStepVisual_RWTextStyleWithBoxCharacteristics::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def("Share", (void (RWStepVisual_RWTextStyleWithBoxCharacteristics::*)(const opencascade::handle<StepVisual_TextStyleWithBoxCharacteristics> &, Interface_EntityIterator &) const ) &RWStepVisual_RWTextStyleWithBoxCharacteristics::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepVisual_RWViewVolume.hxx
	py::class_<RWStepVisual_RWViewVolume, std::unique_ptr<RWStepVisual_RWViewVolume, Deleter<RWStepVisual_RWViewVolume>>> cls_RWStepVisual_RWViewVolume(mod, "RWStepVisual_RWViewVolume", "Read & Write Module for ViewVolume");
	cls_RWStepVisual_RWViewVolume.def(py::init<>());
	cls_RWStepVisual_RWViewVolume.def("ReadStep", (void (RWStepVisual_RWViewVolume::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ViewVolume> &) const ) &RWStepVisual_RWViewVolume::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepVisual_RWViewVolume.def("WriteStep", (void (RWStepVisual_RWViewVolume::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ViewVolume> &) const ) &RWStepVisual_RWViewVolume::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepVisual_RWViewVolume.def("Share", (void (RWStepVisual_RWViewVolume::*)(const opencascade::handle<StepVisual_ViewVolume> &, Interface_EntityIterator &) const ) &RWStepVisual_RWViewVolume::Share, "None", py::arg("ent"), py::arg("iter"));


}
