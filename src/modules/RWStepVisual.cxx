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

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepVisual");

// CLASS: RWSTEPVISUAL_RWANNOTATIONCURVEOCCURRENCE
py::class_<RWStepVisual_RWAnnotationCurveOccurrence> cls_RWStepVisual_RWAnnotationCurveOccurrence(mod, "RWStepVisual_RWAnnotationCurveOccurrence", "Read & Write Module for AnnotationCurveOccurrence");

// Constructors
cls_RWStepVisual_RWAnnotationCurveOccurrence.def(py::init<>());

// Methods
// cls_RWStepVisual_RWAnnotationCurveOccurrence.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationCurveOccurrence::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationCurveOccurrence.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWAnnotationCurveOccurrence::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationCurveOccurrence.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationCurveOccurrence::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationCurveOccurrence.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWAnnotationCurveOccurrence::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationCurveOccurrence.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWAnnotationCurveOccurrence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationCurveOccurrence.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWAnnotationCurveOccurrence::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWAnnotationCurveOccurrence.def("ReadStep", (void (RWStepVisual_RWAnnotationCurveOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationCurveOccurrence> &) const) &RWStepVisual_RWAnnotationCurveOccurrence::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationCurveOccurrence.def("WriteStep", (void (RWStepVisual_RWAnnotationCurveOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationCurveOccurrence> &) const) &RWStepVisual_RWAnnotationCurveOccurrence::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationCurveOccurrence.def("Share", (void (RWStepVisual_RWAnnotationCurveOccurrence::*)(const opencascade::handle<StepVisual_AnnotationCurveOccurrence> &, Interface_EntityIterator &) const) &RWStepVisual_RWAnnotationCurveOccurrence::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWANNOTATIONCURVEOCCURRENCEANDANNOTATIONOCCURRENCEANDGEOMREPRITEMANDREPRITEMANDSTYLEDITEM
py::class_<RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem> cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem(mod, "RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem", "Read & Write Module for AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem");

// Constructors
cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def(py::init<>());

// Methods
// cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def("ReadStep", (void (RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem> &) const) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def("WriteStep", (void (RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem> &) const) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def("Share", (void (RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::*)(const opencascade::handle<StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem> &, Interface_EntityIterator &) const) &RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWANNOTATIONFILLAREA
py::class_<RWStepVisual_RWAnnotationFillArea> cls_RWStepVisual_RWAnnotationFillArea(mod, "RWStepVisual_RWAnnotationFillArea", "Read & Write Module for AnnotationFillArea");

// Constructors
cls_RWStepVisual_RWAnnotationFillArea.def(py::init<>());

// Methods
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationFillArea::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWAnnotationFillArea::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationFillArea::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWAnnotationFillArea::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWAnnotationFillArea::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWAnnotationFillArea::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWAnnotationFillArea.def("ReadStep", (void (RWStepVisual_RWAnnotationFillArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationFillArea> &) const) &RWStepVisual_RWAnnotationFillArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationFillArea.def("WriteStep", (void (RWStepVisual_RWAnnotationFillArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationFillArea> &) const) &RWStepVisual_RWAnnotationFillArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationFillArea.def("Share", (void (RWStepVisual_RWAnnotationFillArea::*)(const opencascade::handle<StepVisual_AnnotationFillArea> &, Interface_EntityIterator &) const) &RWStepVisual_RWAnnotationFillArea::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWANNOTATIONFILLAREAOCCURRENCE
py::class_<RWStepVisual_RWAnnotationFillAreaOccurrence> cls_RWStepVisual_RWAnnotationFillAreaOccurrence(mod, "RWStepVisual_RWAnnotationFillAreaOccurrence", "Read & Write Module for AnnotationFillAreaOccurrence");

// Constructors
cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def(py::init<>());

// Methods
// cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationFillAreaOccurrence::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWAnnotationFillAreaOccurrence::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationFillAreaOccurrence::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWAnnotationFillAreaOccurrence::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWAnnotationFillAreaOccurrence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWAnnotationFillAreaOccurrence::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def("ReadStep", (void (RWStepVisual_RWAnnotationFillAreaOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationFillAreaOccurrence> &) const) &RWStepVisual_RWAnnotationFillAreaOccurrence::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def("WriteStep", (void (RWStepVisual_RWAnnotationFillAreaOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationFillAreaOccurrence> &) const) &RWStepVisual_RWAnnotationFillAreaOccurrence::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationFillAreaOccurrence.def("Share", (void (RWStepVisual_RWAnnotationFillAreaOccurrence::*)(const opencascade::handle<StepVisual_AnnotationFillAreaOccurrence> &, Interface_EntityIterator &) const) &RWStepVisual_RWAnnotationFillAreaOccurrence::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWANNOTATIONOCCURRENCE
py::class_<RWStepVisual_RWAnnotationOccurrence> cls_RWStepVisual_RWAnnotationOccurrence(mod, "RWStepVisual_RWAnnotationOccurrence", "Read & Write Module for AnnotationOccurrence");

// Constructors
cls_RWStepVisual_RWAnnotationOccurrence.def(py::init<>());

// Methods
// cls_RWStepVisual_RWAnnotationOccurrence.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationOccurrence::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationOccurrence.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWAnnotationOccurrence::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationOccurrence.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationOccurrence::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationOccurrence.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWAnnotationOccurrence::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationOccurrence.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWAnnotationOccurrence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationOccurrence.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWAnnotationOccurrence::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWAnnotationOccurrence.def("ReadStep", (void (RWStepVisual_RWAnnotationOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationOccurrence> &) const) &RWStepVisual_RWAnnotationOccurrence::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationOccurrence.def("WriteStep", (void (RWStepVisual_RWAnnotationOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationOccurrence> &) const) &RWStepVisual_RWAnnotationOccurrence::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationOccurrence.def("Share", (void (RWStepVisual_RWAnnotationOccurrence::*)(const opencascade::handle<StepVisual_AnnotationOccurrence> &, Interface_EntityIterator &) const) &RWStepVisual_RWAnnotationOccurrence::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWANNOTATIONPLANE
py::class_<RWStepVisual_RWAnnotationPlane> cls_RWStepVisual_RWAnnotationPlane(mod, "RWStepVisual_RWAnnotationPlane", "Read & Write Module for AnnotationPlane");

// Constructors
cls_RWStepVisual_RWAnnotationPlane.def(py::init<>());

// Methods
// cls_RWStepVisual_RWAnnotationPlane.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationPlane::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationPlane.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWAnnotationPlane::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationPlane.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationPlane::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationPlane.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWAnnotationPlane::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationPlane.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWAnnotationPlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationPlane.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWAnnotationPlane::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWAnnotationPlane.def("ReadStep", (void (RWStepVisual_RWAnnotationPlane::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationPlane> &) const) &RWStepVisual_RWAnnotationPlane::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationPlane.def("WriteStep", (void (RWStepVisual_RWAnnotationPlane::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationPlane> &) const) &RWStepVisual_RWAnnotationPlane::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationPlane.def("Share", (void (RWStepVisual_RWAnnotationPlane::*)(const opencascade::handle<StepVisual_AnnotationPlane> &, Interface_EntityIterator &) const) &RWStepVisual_RWAnnotationPlane::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWAREAINSET
py::class_<RWStepVisual_RWAreaInSet> cls_RWStepVisual_RWAreaInSet(mod, "RWStepVisual_RWAreaInSet", "Read & Write Module for AreaInSet");

// Constructors
cls_RWStepVisual_RWAreaInSet.def(py::init<>());

// Methods
// cls_RWStepVisual_RWAreaInSet.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWAreaInSet::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWAreaInSet.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWAreaInSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAreaInSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWAreaInSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWAreaInSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWAreaInSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAreaInSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWAreaInSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWAreaInSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWAreaInSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWAreaInSet.def("ReadStep", (void (RWStepVisual_RWAreaInSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AreaInSet> &) const) &RWStepVisual_RWAreaInSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWAreaInSet.def("WriteStep", (void (RWStepVisual_RWAreaInSet::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AreaInSet> &) const) &RWStepVisual_RWAreaInSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWAreaInSet.def("Share", (void (RWStepVisual_RWAreaInSet::*)(const opencascade::handle<StepVisual_AreaInSet> &, Interface_EntityIterator &) const) &RWStepVisual_RWAreaInSet::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWBACKGROUNDCOLOUR
py::class_<RWStepVisual_RWBackgroundColour> cls_RWStepVisual_RWBackgroundColour(mod, "RWStepVisual_RWBackgroundColour", "Read & Write Module for BackgroundColour");

// Constructors
cls_RWStepVisual_RWBackgroundColour.def(py::init<>());

// Methods
// cls_RWStepVisual_RWBackgroundColour.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWBackgroundColour::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWBackgroundColour.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWBackgroundColour::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWBackgroundColour.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWBackgroundColour::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWBackgroundColour.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWBackgroundColour::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWBackgroundColour.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWBackgroundColour::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWBackgroundColour.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWBackgroundColour::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWBackgroundColour.def("ReadStep", (void (RWStepVisual_RWBackgroundColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_BackgroundColour> &) const) &RWStepVisual_RWBackgroundColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWBackgroundColour.def("WriteStep", (void (RWStepVisual_RWBackgroundColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_BackgroundColour> &) const) &RWStepVisual_RWBackgroundColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWBackgroundColour.def("Share", (void (RWStepVisual_RWBackgroundColour::*)(const opencascade::handle<StepVisual_BackgroundColour> &, Interface_EntityIterator &) const) &RWStepVisual_RWBackgroundColour::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCAMERAIMAGE
py::class_<RWStepVisual_RWCameraImage> cls_RWStepVisual_RWCameraImage(mod, "RWStepVisual_RWCameraImage", "Read & Write Module for CameraImage");

// Constructors
cls_RWStepVisual_RWCameraImage.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCameraImage.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCameraImage::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraImage.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCameraImage::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraImage.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCameraImage::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraImage.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCameraImage::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraImage.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCameraImage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCameraImage.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCameraImage::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCameraImage.def("ReadStep", (void (RWStepVisual_RWCameraImage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraImage> &) const) &RWStepVisual_RWCameraImage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCameraImage.def("WriteStep", (void (RWStepVisual_RWCameraImage::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraImage> &) const) &RWStepVisual_RWCameraImage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCameraImage.def("Share", (void (RWStepVisual_RWCameraImage::*)(const opencascade::handle<StepVisual_CameraImage> &, Interface_EntityIterator &) const) &RWStepVisual_RWCameraImage::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCAMERAMODEL
py::class_<RWStepVisual_RWCameraModel> cls_RWStepVisual_RWCameraModel(mod, "RWStepVisual_RWCameraModel", "Read & Write Module for CameraModel");

// Constructors
cls_RWStepVisual_RWCameraModel.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCameraModel.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCameraModel::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModel.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCameraModel::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModel.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCameraModel::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModel.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCameraModel::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModel.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCameraModel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModel.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCameraModel::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCameraModel.def("ReadStep", (void (RWStepVisual_RWCameraModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModel> &) const) &RWStepVisual_RWCameraModel::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCameraModel.def("WriteStep", (void (RWStepVisual_RWCameraModel::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModel> &) const) &RWStepVisual_RWCameraModel::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWCAMERAMODELD2
py::class_<RWStepVisual_RWCameraModelD2> cls_RWStepVisual_RWCameraModelD2(mod, "RWStepVisual_RWCameraModelD2", "Read & Write Module for CameraModelD2");

// Constructors
cls_RWStepVisual_RWCameraModelD2.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCameraModelD2.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD2::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD2.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCameraModelD2::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD2.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD2::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD2.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCameraModelD2::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD2.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCameraModelD2::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD2.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCameraModelD2::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCameraModelD2.def("ReadStep", (void (RWStepVisual_RWCameraModelD2::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD2> &) const) &RWStepVisual_RWCameraModelD2::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD2.def("WriteStep", (void (RWStepVisual_RWCameraModelD2::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD2> &) const) &RWStepVisual_RWCameraModelD2::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD2.def("Share", (void (RWStepVisual_RWCameraModelD2::*)(const opencascade::handle<StepVisual_CameraModelD2> &, Interface_EntityIterator &) const) &RWStepVisual_RWCameraModelD2::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCAMERAMODELD3
py::class_<RWStepVisual_RWCameraModelD3> cls_RWStepVisual_RWCameraModelD3(mod, "RWStepVisual_RWCameraModelD3", "Read & Write Module for CameraModelD3");

// Constructors
cls_RWStepVisual_RWCameraModelD3.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCameraModelD3.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD3::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD3.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCameraModelD3::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD3::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD3.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCameraModelD3::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCameraModelD3::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCameraModelD3::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCameraModelD3.def("ReadStep", (void (RWStepVisual_RWCameraModelD3::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD3> &) const) &RWStepVisual_RWCameraModelD3::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD3.def("WriteStep", (void (RWStepVisual_RWCameraModelD3::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD3> &) const) &RWStepVisual_RWCameraModelD3::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD3.def("Share", (void (RWStepVisual_RWCameraModelD3::*)(const opencascade::handle<StepVisual_CameraModelD3> &, Interface_EntityIterator &) const) &RWStepVisual_RWCameraModelD3::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCAMERAMODELD3MULTICLIPPING
py::class_<RWStepVisual_RWCameraModelD3MultiClipping> cls_RWStepVisual_RWCameraModelD3MultiClipping(mod, "RWStepVisual_RWCameraModelD3MultiClipping", "Read & Write Module for CameraModelD3MultiClipping");

// Constructors
cls_RWStepVisual_RWCameraModelD3MultiClipping.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCameraModelD3MultiClipping.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD3MultiClipping::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD3MultiClipping.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCameraModelD3MultiClipping::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClipping.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD3MultiClipping::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD3MultiClipping.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCameraModelD3MultiClipping::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClipping.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCameraModelD3MultiClipping::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClipping.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCameraModelD3MultiClipping::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCameraModelD3MultiClipping.def("ReadStep", (void (RWStepVisual_RWCameraModelD3MultiClipping::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD3MultiClipping> &) const) &RWStepVisual_RWCameraModelD3MultiClipping::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD3MultiClipping.def("WriteStep", (void (RWStepVisual_RWCameraModelD3MultiClipping::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD3MultiClipping> &) const) &RWStepVisual_RWCameraModelD3MultiClipping::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD3MultiClipping.def("Share", (void (RWStepVisual_RWCameraModelD3MultiClipping::*)(const opencascade::handle<StepVisual_CameraModelD3MultiClipping> &, Interface_EntityIterator &) const) &RWStepVisual_RWCameraModelD3MultiClipping::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCAMERAMODELD3MULTICLIPPINGINTERSECTION
py::class_<RWStepVisual_RWCameraModelD3MultiClippingIntersection> cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection(mod, "RWStepVisual_RWCameraModelD3MultiClippingIntersection", "Read & Write Module for CameraModelD3MultiClippingIntersection");

// Constructors
cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def("ReadStep", (void (RWStepVisual_RWCameraModelD3MultiClippingIntersection::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection> &) const) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def("WriteStep", (void (RWStepVisual_RWCameraModelD3MultiClippingIntersection::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection> &) const) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD3MultiClippingIntersection.def("Share", (void (RWStepVisual_RWCameraModelD3MultiClippingIntersection::*)(const opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection> &, Interface_EntityIterator &) const) &RWStepVisual_RWCameraModelD3MultiClippingIntersection::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCAMERAMODELD3MULTICLIPPINGUNION
py::class_<RWStepVisual_RWCameraModelD3MultiClippingUnion> cls_RWStepVisual_RWCameraModelD3MultiClippingUnion(mod, "RWStepVisual_RWCameraModelD3MultiClippingUnion", "Read & Write Module for CameraModelD3MultiClippingUnion");

// Constructors
cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD3MultiClippingUnion::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCameraModelD3MultiClippingUnion::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCameraModelD3MultiClippingUnion::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCameraModelD3MultiClippingUnion::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCameraModelD3MultiClippingUnion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCameraModelD3MultiClippingUnion::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def("ReadStep", (void (RWStepVisual_RWCameraModelD3MultiClippingUnion::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraModelD3MultiClippingUnion> &) const) &RWStepVisual_RWCameraModelD3MultiClippingUnion::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def("WriteStep", (void (RWStepVisual_RWCameraModelD3MultiClippingUnion::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraModelD3MultiClippingUnion> &) const) &RWStepVisual_RWCameraModelD3MultiClippingUnion::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCameraModelD3MultiClippingUnion.def("Share", (void (RWStepVisual_RWCameraModelD3MultiClippingUnion::*)(const opencascade::handle<StepVisual_CameraModelD3MultiClippingUnion> &, Interface_EntityIterator &) const) &RWStepVisual_RWCameraModelD3MultiClippingUnion::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCAMERAUSAGE
py::class_<RWStepVisual_RWCameraUsage> cls_RWStepVisual_RWCameraUsage(mod, "RWStepVisual_RWCameraUsage", "Read & Write Module for CameraUsage");

// Constructors
cls_RWStepVisual_RWCameraUsage.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCameraUsage.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCameraUsage::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraUsage.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCameraUsage::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraUsage.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCameraUsage::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCameraUsage.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCameraUsage::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCameraUsage.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCameraUsage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCameraUsage.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCameraUsage::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCameraUsage.def("ReadStep", (void (RWStepVisual_RWCameraUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CameraUsage> &) const) &RWStepVisual_RWCameraUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCameraUsage.def("WriteStep", (void (RWStepVisual_RWCameraUsage::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CameraUsage> &) const) &RWStepVisual_RWCameraUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCameraUsage.def("Share", (void (RWStepVisual_RWCameraUsage::*)(const opencascade::handle<StepVisual_CameraUsage> &, Interface_EntityIterator &) const) &RWStepVisual_RWCameraUsage::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCHARACTERIZEDOBJECTANDCHARACTERIZEDREPRESENTATIONANDDRAUGHTINGMODELANDREPRESENTATION
py::class_<RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation> cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation(mod, "RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation", "Read & Write Module for complex STEP entity Characterized_Object & Characterized_Representation & Draughting_Model & Representation");

// Constructors
cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def("ReadStep", (void (RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation> &) const) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def("WriteStep", (void (RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation> &) const) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def("Share", (void (RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::*)(const opencascade::handle<StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation> &, Interface_EntityIterator &) const) &RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCOLOUR
py::class_<RWStepVisual_RWColour> cls_RWStepVisual_RWColour(mod, "RWStepVisual_RWColour", "Read & Write Module for Colour");

// Constructors
cls_RWStepVisual_RWColour.def(py::init<>());

// Methods
// cls_RWStepVisual_RWColour.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWColour::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWColour.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWColour::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWColour.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWColour::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWColour.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWColour::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWColour.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWColour::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWColour.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWColour::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWColour.def("ReadStep", (void (RWStepVisual_RWColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_Colour> &) const) &RWStepVisual_RWColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWColour.def("WriteStep", (void (RWStepVisual_RWColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_Colour> &) const) &RWStepVisual_RWColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWCOLOURRGB
py::class_<RWStepVisual_RWColourRgb> cls_RWStepVisual_RWColourRgb(mod, "RWStepVisual_RWColourRgb", "Read & Write Module for ColourRgb");

// Constructors
cls_RWStepVisual_RWColourRgb.def(py::init<>());

// Methods
// cls_RWStepVisual_RWColourRgb.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWColourRgb::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWColourRgb.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWColourRgb::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWColourRgb.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWColourRgb::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWColourRgb.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWColourRgb::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWColourRgb.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWColourRgb::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWColourRgb.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWColourRgb::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWColourRgb.def("ReadStep", (void (RWStepVisual_RWColourRgb::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ColourRgb> &) const) &RWStepVisual_RWColourRgb::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWColourRgb.def("WriteStep", (void (RWStepVisual_RWColourRgb::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ColourRgb> &) const) &RWStepVisual_RWColourRgb::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWCOLOURSPECIFICATION
py::class_<RWStepVisual_RWColourSpecification> cls_RWStepVisual_RWColourSpecification(mod, "RWStepVisual_RWColourSpecification", "Read & Write Module for ColourSpecification");

// Constructors
cls_RWStepVisual_RWColourSpecification.def(py::init<>());

// Methods
// cls_RWStepVisual_RWColourSpecification.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWColourSpecification::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWColourSpecification.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWColourSpecification::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWColourSpecification.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWColourSpecification::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWColourSpecification.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWColourSpecification::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWColourSpecification.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWColourSpecification::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWColourSpecification.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWColourSpecification::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWColourSpecification.def("ReadStep", (void (RWStepVisual_RWColourSpecification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ColourSpecification> &) const) &RWStepVisual_RWColourSpecification::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWColourSpecification.def("WriteStep", (void (RWStepVisual_RWColourSpecification::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ColourSpecification> &) const) &RWStepVisual_RWColourSpecification::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWCOMPOSITETEXT
py::class_<RWStepVisual_RWCompositeText> cls_RWStepVisual_RWCompositeText(mod, "RWStepVisual_RWCompositeText", "Read & Write Module for CompositeText");

// Constructors
cls_RWStepVisual_RWCompositeText.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCompositeText.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCompositeText::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCompositeText.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCompositeText::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCompositeText.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCompositeText::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCompositeText.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCompositeText::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCompositeText.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCompositeText::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCompositeText.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCompositeText::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCompositeText.def("ReadStep", (void (RWStepVisual_RWCompositeText::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CompositeText> &) const) &RWStepVisual_RWCompositeText::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCompositeText.def("WriteStep", (void (RWStepVisual_RWCompositeText::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CompositeText> &) const) &RWStepVisual_RWCompositeText::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCompositeText.def("Share", (void (RWStepVisual_RWCompositeText::*)(const opencascade::handle<StepVisual_CompositeText> &, Interface_EntityIterator &) const) &RWStepVisual_RWCompositeText::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCOMPOSITETEXTWITHEXTENT
py::class_<RWStepVisual_RWCompositeTextWithExtent> cls_RWStepVisual_RWCompositeTextWithExtent(mod, "RWStepVisual_RWCompositeTextWithExtent", "Read & Write Module for CompositeTextWithExtent");

// Constructors
cls_RWStepVisual_RWCompositeTextWithExtent.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCompositeTextWithExtent.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCompositeTextWithExtent::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCompositeTextWithExtent.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCompositeTextWithExtent::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCompositeTextWithExtent.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCompositeTextWithExtent::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCompositeTextWithExtent.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCompositeTextWithExtent::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCompositeTextWithExtent.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCompositeTextWithExtent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCompositeTextWithExtent.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCompositeTextWithExtent::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCompositeTextWithExtent.def("ReadStep", (void (RWStepVisual_RWCompositeTextWithExtent::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CompositeTextWithExtent> &) const) &RWStepVisual_RWCompositeTextWithExtent::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCompositeTextWithExtent.def("WriteStep", (void (RWStepVisual_RWCompositeTextWithExtent::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CompositeTextWithExtent> &) const) &RWStepVisual_RWCompositeTextWithExtent::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCompositeTextWithExtent.def("Share", (void (RWStepVisual_RWCompositeTextWithExtent::*)(const opencascade::handle<StepVisual_CompositeTextWithExtent> &, Interface_EntityIterator &) const) &RWStepVisual_RWCompositeTextWithExtent::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCONTEXTDEPENDENTINVISIBILITY
py::class_<RWStepVisual_RWContextDependentInvisibility> cls_RWStepVisual_RWContextDependentInvisibility(mod, "RWStepVisual_RWContextDependentInvisibility", "Read & Write Module for ContextDependentInvisibility");

// Constructors
cls_RWStepVisual_RWContextDependentInvisibility.def(py::init<>());

// Methods
// cls_RWStepVisual_RWContextDependentInvisibility.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWContextDependentInvisibility::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWContextDependentInvisibility.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWContextDependentInvisibility::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWContextDependentInvisibility.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWContextDependentInvisibility::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWContextDependentInvisibility.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWContextDependentInvisibility::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWContextDependentInvisibility.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWContextDependentInvisibility::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWContextDependentInvisibility.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWContextDependentInvisibility::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWContextDependentInvisibility.def("ReadStep", (void (RWStepVisual_RWContextDependentInvisibility::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ContextDependentInvisibility> &) const) &RWStepVisual_RWContextDependentInvisibility::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWContextDependentInvisibility.def("WriteStep", (void (RWStepVisual_RWContextDependentInvisibility::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ContextDependentInvisibility> &) const) &RWStepVisual_RWContextDependentInvisibility::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWContextDependentInvisibility.def("Share", (void (RWStepVisual_RWContextDependentInvisibility::*)(const opencascade::handle<StepVisual_ContextDependentInvisibility> &, Interface_EntityIterator &) const) &RWStepVisual_RWContextDependentInvisibility::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCONTEXTDEPENDENTOVERRIDINGSTYLEDITEM
py::class_<RWStepVisual_RWContextDependentOverRidingStyledItem> cls_RWStepVisual_RWContextDependentOverRidingStyledItem(mod, "RWStepVisual_RWContextDependentOverRidingStyledItem", "Read & Write Module for ContextDependentOverRidingStyledItem");

// Constructors
cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def(py::init<>());

// Methods
// cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWContextDependentOverRidingStyledItem::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWContextDependentOverRidingStyledItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWContextDependentOverRidingStyledItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWContextDependentOverRidingStyledItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWContextDependentOverRidingStyledItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWContextDependentOverRidingStyledItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def("ReadStep", (void (RWStepVisual_RWContextDependentOverRidingStyledItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ContextDependentOverRidingStyledItem> &) const) &RWStepVisual_RWContextDependentOverRidingStyledItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def("WriteStep", (void (RWStepVisual_RWContextDependentOverRidingStyledItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ContextDependentOverRidingStyledItem> &) const) &RWStepVisual_RWContextDependentOverRidingStyledItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWContextDependentOverRidingStyledItem.def("Share", (void (RWStepVisual_RWContextDependentOverRidingStyledItem::*)(const opencascade::handle<StepVisual_ContextDependentOverRidingStyledItem> &, Interface_EntityIterator &) const) &RWStepVisual_RWContextDependentOverRidingStyledItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCOORDINATESLIST
py::class_<RWStepVisual_RWCoordinatesList> cls_RWStepVisual_RWCoordinatesList(mod, "RWStepVisual_RWCoordinatesList", "Read & Write Module for AnnotationOccurrence");

// Constructors
cls_RWStepVisual_RWCoordinatesList.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCoordinatesList.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCoordinatesList::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCoordinatesList.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCoordinatesList::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCoordinatesList.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCoordinatesList::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCoordinatesList.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCoordinatesList::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCoordinatesList.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCoordinatesList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCoordinatesList.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCoordinatesList::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCoordinatesList.def("ReadStep", (void (RWStepVisual_RWCoordinatesList::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CoordinatesList> &) const) &RWStepVisual_RWCoordinatesList::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCoordinatesList.def("WriteStep", (void (RWStepVisual_RWCoordinatesList::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CoordinatesList> &) const) &RWStepVisual_RWCoordinatesList::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWCURVESTYLE
py::class_<RWStepVisual_RWCurveStyle> cls_RWStepVisual_RWCurveStyle(mod, "RWStepVisual_RWCurveStyle", "Read & Write Module for CurveStyle");

// Constructors
cls_RWStepVisual_RWCurveStyle.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCurveStyle.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCurveStyle::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCurveStyle.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCurveStyle::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyle.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCurveStyle::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCurveStyle.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCurveStyle::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyle.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCurveStyle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyle.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCurveStyle::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCurveStyle.def("ReadStep", (void (RWStepVisual_RWCurveStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CurveStyle> &) const) &RWStepVisual_RWCurveStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCurveStyle.def("WriteStep", (void (RWStepVisual_RWCurveStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CurveStyle> &) const) &RWStepVisual_RWCurveStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCurveStyle.def("Share", (void (RWStepVisual_RWCurveStyle::*)(const opencascade::handle<StepVisual_CurveStyle> &, Interface_EntityIterator &) const) &RWStepVisual_RWCurveStyle::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCURVESTYLEFONT
py::class_<RWStepVisual_RWCurveStyleFont> cls_RWStepVisual_RWCurveStyleFont(mod, "RWStepVisual_RWCurveStyleFont", "Read & Write Module for CurveStyleFont");

// Constructors
cls_RWStepVisual_RWCurveStyleFont.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCurveStyleFont.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCurveStyleFont::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCurveStyleFont.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCurveStyleFont::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyleFont.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCurveStyleFont::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCurveStyleFont.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCurveStyleFont::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyleFont.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCurveStyleFont::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyleFont.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCurveStyleFont::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCurveStyleFont.def("ReadStep", (void (RWStepVisual_RWCurveStyleFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CurveStyleFont> &) const) &RWStepVisual_RWCurveStyleFont::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCurveStyleFont.def("WriteStep", (void (RWStepVisual_RWCurveStyleFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CurveStyleFont> &) const) &RWStepVisual_RWCurveStyleFont::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWCurveStyleFont.def("Share", (void (RWStepVisual_RWCurveStyleFont::*)(const opencascade::handle<StepVisual_CurveStyleFont> &, Interface_EntityIterator &) const) &RWStepVisual_RWCurveStyleFont::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWCURVESTYLEFONTPATTERN
py::class_<RWStepVisual_RWCurveStyleFontPattern> cls_RWStepVisual_RWCurveStyleFontPattern(mod, "RWStepVisual_RWCurveStyleFontPattern", "Read & Write Module for CurveStyleFontPattern");

// Constructors
cls_RWStepVisual_RWCurveStyleFontPattern.def(py::init<>());

// Methods
// cls_RWStepVisual_RWCurveStyleFontPattern.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWCurveStyleFontPattern::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWCurveStyleFontPattern.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWCurveStyleFontPattern::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyleFontPattern.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWCurveStyleFontPattern::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWCurveStyleFontPattern.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWCurveStyleFontPattern::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyleFontPattern.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWCurveStyleFontPattern::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWCurveStyleFontPattern.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWCurveStyleFontPattern::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWCurveStyleFontPattern.def("ReadStep", (void (RWStepVisual_RWCurveStyleFontPattern::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_CurveStyleFontPattern> &) const) &RWStepVisual_RWCurveStyleFontPattern::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWCurveStyleFontPattern.def("WriteStep", (void (RWStepVisual_RWCurveStyleFontPattern::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_CurveStyleFontPattern> &) const) &RWStepVisual_RWCurveStyleFontPattern::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWDRAUGHTINGCALLOUT
py::class_<RWStepVisual_RWDraughtingCallout> cls_RWStepVisual_RWDraughtingCallout(mod, "RWStepVisual_RWDraughtingCallout", "Read & Write Module for DraughtingCallout");

// Constructors
cls_RWStepVisual_RWDraughtingCallout.def(py::init<>());

// Methods
// cls_RWStepVisual_RWDraughtingCallout.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWDraughtingCallout::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWDraughtingCallout.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWDraughtingCallout::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingCallout.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWDraughtingCallout::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWDraughtingCallout.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWDraughtingCallout::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingCallout.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWDraughtingCallout::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingCallout.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWDraughtingCallout::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWDraughtingCallout.def("ReadStep", (void (RWStepVisual_RWDraughtingCallout::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_DraughtingCallout> &) const) &RWStepVisual_RWDraughtingCallout::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWDraughtingCallout.def("WriteStep", (void (RWStepVisual_RWDraughtingCallout::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_DraughtingCallout> &) const) &RWStepVisual_RWDraughtingCallout::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWDraughtingCallout.def("Share", (void (RWStepVisual_RWDraughtingCallout::*)(const opencascade::handle<StepVisual_DraughtingCallout> &, Interface_EntityIterator &) const) &RWStepVisual_RWDraughtingCallout::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWDRAUGHTINGMODEL
py::class_<RWStepVisual_RWDraughtingModel> cls_RWStepVisual_RWDraughtingModel(mod, "RWStepVisual_RWDraughtingModel", "Read & Write tool for DraughtingModel");

// Constructors
cls_RWStepVisual_RWDraughtingModel.def(py::init<>());

// Methods
// cls_RWStepVisual_RWDraughtingModel.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWDraughtingModel::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWDraughtingModel.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWDraughtingModel::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingModel.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWDraughtingModel::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWDraughtingModel.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWDraughtingModel::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingModel.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWDraughtingModel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingModel.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWDraughtingModel::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWDraughtingModel.def("ReadStep", (void (RWStepVisual_RWDraughtingModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_DraughtingModel> &) const) &RWStepVisual_RWDraughtingModel::ReadStep, "Reads DraughtingModel", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWDraughtingModel.def("WriteStep", (void (RWStepVisual_RWDraughtingModel::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_DraughtingModel> &) const) &RWStepVisual_RWDraughtingModel::WriteStep, "Writes DraughtingModel", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWDraughtingModel.def("Share", (void (RWStepVisual_RWDraughtingModel::*)(const opencascade::handle<StepVisual_DraughtingModel> &, Interface_EntityIterator &) const) &RWStepVisual_RWDraughtingModel::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWDRAUGHTINGPREDEFINEDCOLOUR
py::class_<RWStepVisual_RWDraughtingPreDefinedColour> cls_RWStepVisual_RWDraughtingPreDefinedColour(mod, "RWStepVisual_RWDraughtingPreDefinedColour", "Read & Write Module for DraughtingPreDefinedColour");

// Constructors
cls_RWStepVisual_RWDraughtingPreDefinedColour.def(py::init<>());

// Methods
// cls_RWStepVisual_RWDraughtingPreDefinedColour.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWDraughtingPreDefinedColour::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWDraughtingPreDefinedColour.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWDraughtingPreDefinedColour::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingPreDefinedColour.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWDraughtingPreDefinedColour::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWDraughtingPreDefinedColour.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWDraughtingPreDefinedColour::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingPreDefinedColour.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWDraughtingPreDefinedColour::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingPreDefinedColour.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWDraughtingPreDefinedColour::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWDraughtingPreDefinedColour.def("ReadStep", (void (RWStepVisual_RWDraughtingPreDefinedColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_DraughtingPreDefinedColour> &) const) &RWStepVisual_RWDraughtingPreDefinedColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWDraughtingPreDefinedColour.def("WriteStep", (void (RWStepVisual_RWDraughtingPreDefinedColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_DraughtingPreDefinedColour> &) const) &RWStepVisual_RWDraughtingPreDefinedColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWDRAUGHTINGPREDEFINEDCURVEFONT
py::class_<RWStepVisual_RWDraughtingPreDefinedCurveFont> cls_RWStepVisual_RWDraughtingPreDefinedCurveFont(mod, "RWStepVisual_RWDraughtingPreDefinedCurveFont", "Read & Write Module for DraughtingPreDefinedCurveFont");

// Constructors
cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def(py::init<>());

// Methods
// cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWDraughtingPreDefinedCurveFont::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWDraughtingPreDefinedCurveFont::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWDraughtingPreDefinedCurveFont::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWDraughtingPreDefinedCurveFont::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWDraughtingPreDefinedCurveFont::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWDraughtingPreDefinedCurveFont::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def("ReadStep", (void (RWStepVisual_RWDraughtingPreDefinedCurveFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_DraughtingPreDefinedCurveFont> &) const) &RWStepVisual_RWDraughtingPreDefinedCurveFont::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWDraughtingPreDefinedCurveFont.def("WriteStep", (void (RWStepVisual_RWDraughtingPreDefinedCurveFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_DraughtingPreDefinedCurveFont> &) const) &RWStepVisual_RWDraughtingPreDefinedCurveFont::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWEXTERNALLYDEFINEDCURVEFONT
py::class_<RWStepVisual_RWExternallyDefinedCurveFont> cls_RWStepVisual_RWExternallyDefinedCurveFont(mod, "RWStepVisual_RWExternallyDefinedCurveFont", "Read & Write tool for ExternallyDefinedCurveFont");

// Constructors
cls_RWStepVisual_RWExternallyDefinedCurveFont.def(py::init<>());

// Methods
// cls_RWStepVisual_RWExternallyDefinedCurveFont.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWExternallyDefinedCurveFont::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWExternallyDefinedCurveFont.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWExternallyDefinedCurveFont::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWExternallyDefinedCurveFont.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWExternallyDefinedCurveFont::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWExternallyDefinedCurveFont.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWExternallyDefinedCurveFont::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWExternallyDefinedCurveFont.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWExternallyDefinedCurveFont::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWExternallyDefinedCurveFont.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWExternallyDefinedCurveFont::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWExternallyDefinedCurveFont.def("ReadStep", (void (RWStepVisual_RWExternallyDefinedCurveFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ExternallyDefinedCurveFont> &) const) &RWStepVisual_RWExternallyDefinedCurveFont::ReadStep, "Reads ExternallyDefinedCurveFont", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWExternallyDefinedCurveFont.def("WriteStep", (void (RWStepVisual_RWExternallyDefinedCurveFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ExternallyDefinedCurveFont> &) const) &RWStepVisual_RWExternallyDefinedCurveFont::WriteStep, "Writes ExternallyDefinedCurveFont", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWExternallyDefinedCurveFont.def("Share", (void (RWStepVisual_RWExternallyDefinedCurveFont::*)(const opencascade::handle<StepVisual_ExternallyDefinedCurveFont> &, Interface_EntityIterator &) const) &RWStepVisual_RWExternallyDefinedCurveFont::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWFILLAREASTYLE
py::class_<RWStepVisual_RWFillAreaStyle> cls_RWStepVisual_RWFillAreaStyle(mod, "RWStepVisual_RWFillAreaStyle", "Read & Write Module for FillAreaStyle");

// Constructors
cls_RWStepVisual_RWFillAreaStyle.def(py::init<>());

// Methods
// cls_RWStepVisual_RWFillAreaStyle.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWFillAreaStyle::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWFillAreaStyle.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWFillAreaStyle::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWFillAreaStyle.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWFillAreaStyle::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWFillAreaStyle.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWFillAreaStyle::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWFillAreaStyle.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWFillAreaStyle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWFillAreaStyle.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWFillAreaStyle::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWFillAreaStyle.def("ReadStep", (void (RWStepVisual_RWFillAreaStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_FillAreaStyle> &) const) &RWStepVisual_RWFillAreaStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWFillAreaStyle.def("WriteStep", (void (RWStepVisual_RWFillAreaStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_FillAreaStyle> &) const) &RWStepVisual_RWFillAreaStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWFillAreaStyle.def("Share", (void (RWStepVisual_RWFillAreaStyle::*)(const opencascade::handle<StepVisual_FillAreaStyle> &, Interface_EntityIterator &) const) &RWStepVisual_RWFillAreaStyle::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWFILLAREASTYLECOLOUR
py::class_<RWStepVisual_RWFillAreaStyleColour> cls_RWStepVisual_RWFillAreaStyleColour(mod, "RWStepVisual_RWFillAreaStyleColour", "Read & Write Module for FillAreaStyleColour");

// Constructors
cls_RWStepVisual_RWFillAreaStyleColour.def(py::init<>());

// Methods
// cls_RWStepVisual_RWFillAreaStyleColour.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWFillAreaStyleColour::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWFillAreaStyleColour.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWFillAreaStyleColour::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWFillAreaStyleColour.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWFillAreaStyleColour::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWFillAreaStyleColour.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWFillAreaStyleColour::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWFillAreaStyleColour.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWFillAreaStyleColour::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWFillAreaStyleColour.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWFillAreaStyleColour::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWFillAreaStyleColour.def("ReadStep", (void (RWStepVisual_RWFillAreaStyleColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_FillAreaStyleColour> &) const) &RWStepVisual_RWFillAreaStyleColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWFillAreaStyleColour.def("WriteStep", (void (RWStepVisual_RWFillAreaStyleColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_FillAreaStyleColour> &) const) &RWStepVisual_RWFillAreaStyleColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWFillAreaStyleColour.def("Share", (void (RWStepVisual_RWFillAreaStyleColour::*)(const opencascade::handle<StepVisual_FillAreaStyleColour> &, Interface_EntityIterator &) const) &RWStepVisual_RWFillAreaStyleColour::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWINVISIBILITY
py::class_<RWStepVisual_RWInvisibility> cls_RWStepVisual_RWInvisibility(mod, "RWStepVisual_RWInvisibility", "Read & Write Module for Invisibility");

// Constructors
cls_RWStepVisual_RWInvisibility.def(py::init<>());

// Methods
// cls_RWStepVisual_RWInvisibility.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWInvisibility::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWInvisibility.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWInvisibility::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWInvisibility.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWInvisibility::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWInvisibility.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWInvisibility::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWInvisibility.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWInvisibility::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWInvisibility.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWInvisibility::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWInvisibility.def("ReadStep", (void (RWStepVisual_RWInvisibility::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_Invisibility> &) const) &RWStepVisual_RWInvisibility::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWInvisibility.def("WriteStep", (void (RWStepVisual_RWInvisibility::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_Invisibility> &) const) &RWStepVisual_RWInvisibility::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWInvisibility.def("Share", (void (RWStepVisual_RWInvisibility::*)(const opencascade::handle<StepVisual_Invisibility> &, Interface_EntityIterator &) const) &RWStepVisual_RWInvisibility::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWMECHANICALDESIGNGEOMETRICPRESENTATIONAREA
py::class_<RWStepVisual_RWMechanicalDesignGeometricPresentationArea> cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea(mod, "RWStepVisual_RWMechanicalDesignGeometricPresentationArea", "Read & Write Module for MechanicalDesignGeometricPresentationArea");

// Constructors
cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def(py::init<>());

// Methods
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def("ReadStep", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationArea> &) const) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def("WriteStep", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationArea> &) const) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWMechanicalDesignGeometricPresentationArea.def("Share", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationArea::*)(const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationArea> &, Interface_EntityIterator &) const) &RWStepVisual_RWMechanicalDesignGeometricPresentationArea::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWMECHANICALDESIGNGEOMETRICPRESENTATIONREPRESENTATION
py::class_<RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation> cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation(mod, "RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation", "Read & Write Module for MechanicalDesignGeometricPresentationRepresentation");

// Constructors
cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def(py::init<>());

// Methods
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def("ReadStep", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> &) const) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def("WriteStep", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> &) const) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation.def("Share", (void (RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::*)(const opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> &, Interface_EntityIterator &) const) &RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWOVERRIDINGSTYLEDITEM
py::class_<RWStepVisual_RWOverRidingStyledItem> cls_RWStepVisual_RWOverRidingStyledItem(mod, "RWStepVisual_RWOverRidingStyledItem", "Read & Write Module for OverRidingStyledItem");

// Constructors
cls_RWStepVisual_RWOverRidingStyledItem.def(py::init<>());

// Methods
// cls_RWStepVisual_RWOverRidingStyledItem.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWOverRidingStyledItem::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWOverRidingStyledItem.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWOverRidingStyledItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWOverRidingStyledItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWOverRidingStyledItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWOverRidingStyledItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWOverRidingStyledItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWOverRidingStyledItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWOverRidingStyledItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWOverRidingStyledItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWOverRidingStyledItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWOverRidingStyledItem.def("ReadStep", (void (RWStepVisual_RWOverRidingStyledItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_OverRidingStyledItem> &) const) &RWStepVisual_RWOverRidingStyledItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWOverRidingStyledItem.def("WriteStep", (void (RWStepVisual_RWOverRidingStyledItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_OverRidingStyledItem> &) const) &RWStepVisual_RWOverRidingStyledItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWOverRidingStyledItem.def("Share", (void (RWStepVisual_RWOverRidingStyledItem::*)(const opencascade::handle<StepVisual_OverRidingStyledItem> &, Interface_EntityIterator &) const) &RWStepVisual_RWOverRidingStyledItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPLANARBOX
py::class_<RWStepVisual_RWPlanarBox> cls_RWStepVisual_RWPlanarBox(mod, "RWStepVisual_RWPlanarBox", "Read & Write Module for PlanarBox");

// Constructors
cls_RWStepVisual_RWPlanarBox.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPlanarBox.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPlanarBox::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPlanarBox.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPlanarBox::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPlanarBox.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPlanarBox::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPlanarBox.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPlanarBox::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPlanarBox.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPlanarBox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPlanarBox.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPlanarBox::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPlanarBox.def("ReadStep", (void (RWStepVisual_RWPlanarBox::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PlanarBox> &) const) &RWStepVisual_RWPlanarBox::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPlanarBox.def("WriteStep", (void (RWStepVisual_RWPlanarBox::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PlanarBox> &) const) &RWStepVisual_RWPlanarBox::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPlanarBox.def("Share", (void (RWStepVisual_RWPlanarBox::*)(const opencascade::handle<StepVisual_PlanarBox> &, Interface_EntityIterator &) const) &RWStepVisual_RWPlanarBox::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPLANAREXTENT
py::class_<RWStepVisual_RWPlanarExtent> cls_RWStepVisual_RWPlanarExtent(mod, "RWStepVisual_RWPlanarExtent", "Read & Write Module for PlanarExtent");

// Constructors
cls_RWStepVisual_RWPlanarExtent.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPlanarExtent.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPlanarExtent::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPlanarExtent.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPlanarExtent::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPlanarExtent.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPlanarExtent::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPlanarExtent.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPlanarExtent::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPlanarExtent.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPlanarExtent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPlanarExtent.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPlanarExtent::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPlanarExtent.def("ReadStep", (void (RWStepVisual_RWPlanarExtent::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PlanarExtent> &) const) &RWStepVisual_RWPlanarExtent::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPlanarExtent.def("WriteStep", (void (RWStepVisual_RWPlanarExtent::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PlanarExtent> &) const) &RWStepVisual_RWPlanarExtent::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWPOINTSTYLE
py::class_<RWStepVisual_RWPointStyle> cls_RWStepVisual_RWPointStyle(mod, "RWStepVisual_RWPointStyle", "Read & Write Module for PointStyle");

// Constructors
cls_RWStepVisual_RWPointStyle.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPointStyle.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPointStyle::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPointStyle.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPointStyle::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPointStyle.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPointStyle::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPointStyle.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPointStyle::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPointStyle.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPointStyle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPointStyle.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPointStyle::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPointStyle.def("ReadStep", (void (RWStepVisual_RWPointStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PointStyle> &) const) &RWStepVisual_RWPointStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPointStyle.def("WriteStep", (void (RWStepVisual_RWPointStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PointStyle> &) const) &RWStepVisual_RWPointStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPointStyle.def("Share", (void (RWStepVisual_RWPointStyle::*)(const opencascade::handle<StepVisual_PointStyle> &, Interface_EntityIterator &) const) &RWStepVisual_RWPointStyle::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPREDEFINEDCOLOUR
py::class_<RWStepVisual_RWPreDefinedColour> cls_RWStepVisual_RWPreDefinedColour(mod, "RWStepVisual_RWPreDefinedColour", "Read & Write Module for PreDefinedColour");

// Constructors
cls_RWStepVisual_RWPreDefinedColour.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPreDefinedColour.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPreDefinedColour::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPreDefinedColour.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPreDefinedColour::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedColour.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPreDefinedColour::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPreDefinedColour.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPreDefinedColour::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedColour.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPreDefinedColour::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedColour.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPreDefinedColour::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPreDefinedColour.def("ReadStep", (void (RWStepVisual_RWPreDefinedColour::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PreDefinedColour> &) const) &RWStepVisual_RWPreDefinedColour::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPreDefinedColour.def("WriteStep", (void (RWStepVisual_RWPreDefinedColour::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PreDefinedColour> &) const) &RWStepVisual_RWPreDefinedColour::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWPREDEFINEDCURVEFONT
py::class_<RWStepVisual_RWPreDefinedCurveFont> cls_RWStepVisual_RWPreDefinedCurveFont(mod, "RWStepVisual_RWPreDefinedCurveFont", "Read & Write Module for PreDefinedCurveFont");

// Constructors
cls_RWStepVisual_RWPreDefinedCurveFont.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPreDefinedCurveFont.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPreDefinedCurveFont::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPreDefinedCurveFont.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPreDefinedCurveFont::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedCurveFont.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPreDefinedCurveFont::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPreDefinedCurveFont.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPreDefinedCurveFont::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedCurveFont.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPreDefinedCurveFont::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedCurveFont.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPreDefinedCurveFont::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPreDefinedCurveFont.def("ReadStep", (void (RWStepVisual_RWPreDefinedCurveFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PreDefinedCurveFont> &) const) &RWStepVisual_RWPreDefinedCurveFont::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPreDefinedCurveFont.def("WriteStep", (void (RWStepVisual_RWPreDefinedCurveFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PreDefinedCurveFont> &) const) &RWStepVisual_RWPreDefinedCurveFont::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWPREDEFINEDITEM
py::class_<RWStepVisual_RWPreDefinedItem> cls_RWStepVisual_RWPreDefinedItem(mod, "RWStepVisual_RWPreDefinedItem", "Read & Write Module for PreDefinedItem");

// Constructors
cls_RWStepVisual_RWPreDefinedItem.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPreDefinedItem.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPreDefinedItem::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPreDefinedItem.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPreDefinedItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPreDefinedItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPreDefinedItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPreDefinedItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPreDefinedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPreDefinedItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPreDefinedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPreDefinedItem.def("ReadStep", (void (RWStepVisual_RWPreDefinedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PreDefinedItem> &) const) &RWStepVisual_RWPreDefinedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPreDefinedItem.def("WriteStep", (void (RWStepVisual_RWPreDefinedItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PreDefinedItem> &) const) &RWStepVisual_RWPreDefinedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONAREA
py::class_<RWStepVisual_RWPresentationArea> cls_RWStepVisual_RWPresentationArea(mod, "RWStepVisual_RWPresentationArea", "Read & Write Module for PresentationArea");

// Constructors
cls_RWStepVisual_RWPresentationArea.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationArea.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationArea::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationArea.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationArea::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationArea.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationArea::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationArea.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationArea::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationArea.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationArea::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationArea.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationArea::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationArea.def("ReadStep", (void (RWStepVisual_RWPresentationArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationArea> &) const) &RWStepVisual_RWPresentationArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationArea.def("WriteStep", (void (RWStepVisual_RWPresentationArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationArea> &) const) &RWStepVisual_RWPresentationArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentationArea.def("Share", (void (RWStepVisual_RWPresentationArea::*)(const opencascade::handle<StepVisual_PresentationArea> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentationArea::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONLAYERASSIGNMENT
py::class_<RWStepVisual_RWPresentationLayerAssignment> cls_RWStepVisual_RWPresentationLayerAssignment(mod, "RWStepVisual_RWPresentationLayerAssignment", "Read & Write Module for PresentationLayerAssignment");

// Constructors
cls_RWStepVisual_RWPresentationLayerAssignment.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationLayerAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationLayerAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationLayerAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationLayerAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationLayerAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationLayerAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationLayerAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationLayerAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationLayerAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationLayerAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationLayerAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationLayerAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationLayerAssignment.def("ReadStep", (void (RWStepVisual_RWPresentationLayerAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationLayerAssignment> &) const) &RWStepVisual_RWPresentationLayerAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationLayerAssignment.def("WriteStep", (void (RWStepVisual_RWPresentationLayerAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationLayerAssignment> &) const) &RWStepVisual_RWPresentationLayerAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentationLayerAssignment.def("Share", (void (RWStepVisual_RWPresentationLayerAssignment::*)(const opencascade::handle<StepVisual_PresentationLayerAssignment> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentationLayerAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONLAYERUSAGE
py::class_<RWStepVisual_RWPresentationLayerUsage> cls_RWStepVisual_RWPresentationLayerUsage(mod, "RWStepVisual_RWPresentationLayerUsage", "Read & Write Module for PresentationLayerUsage");

// Constructors
cls_RWStepVisual_RWPresentationLayerUsage.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationLayerUsage.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationLayerUsage::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationLayerUsage.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationLayerUsage::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationLayerUsage.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationLayerUsage::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationLayerUsage.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationLayerUsage::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationLayerUsage.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationLayerUsage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationLayerUsage.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationLayerUsage::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationLayerUsage.def("ReadStep", (void (RWStepVisual_RWPresentationLayerUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationLayerUsage> &) const) &RWStepVisual_RWPresentationLayerUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationLayerUsage.def("WriteStep", (void (RWStepVisual_RWPresentationLayerUsage::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationLayerUsage> &) const) &RWStepVisual_RWPresentationLayerUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentationLayerUsage.def("Share", (void (RWStepVisual_RWPresentationLayerUsage::*)(const opencascade::handle<StepVisual_PresentationLayerUsage> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentationLayerUsage::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONREPRESENTATION
py::class_<RWStepVisual_RWPresentationRepresentation> cls_RWStepVisual_RWPresentationRepresentation(mod, "RWStepVisual_RWPresentationRepresentation", "Read & Write Module for PresentationRepresentation");

// Constructors
cls_RWStepVisual_RWPresentationRepresentation.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationRepresentation.def("ReadStep", (void (RWStepVisual_RWPresentationRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationRepresentation> &) const) &RWStepVisual_RWPresentationRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationRepresentation.def("WriteStep", (void (RWStepVisual_RWPresentationRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationRepresentation> &) const) &RWStepVisual_RWPresentationRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentationRepresentation.def("Share", (void (RWStepVisual_RWPresentationRepresentation::*)(const opencascade::handle<StepVisual_PresentationRepresentation> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentationRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONSET
py::class_<RWStepVisual_RWPresentationSet> cls_RWStepVisual_RWPresentationSet(mod, "RWStepVisual_RWPresentationSet", "Read & Write Module for PresentationSet");

// Constructors
cls_RWStepVisual_RWPresentationSet.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationSet.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationSet::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationSet.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationSet.def("ReadStep", (void (RWStepVisual_RWPresentationSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationSet> &) const) &RWStepVisual_RWPresentationSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationSet.def("WriteStep", (void (RWStepVisual_RWPresentationSet::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationSet> &) const) &RWStepVisual_RWPresentationSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONSIZE
py::class_<RWStepVisual_RWPresentationSize> cls_RWStepVisual_RWPresentationSize(mod, "RWStepVisual_RWPresentationSize", "Read & Write Module for PresentationSize");

// Constructors
cls_RWStepVisual_RWPresentationSize.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationSize.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationSize::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationSize.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationSize::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationSize.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationSize::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationSize.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationSize::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationSize.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationSize::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationSize.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationSize::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationSize.def("ReadStep", (void (RWStepVisual_RWPresentationSize::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationSize> &) const) &RWStepVisual_RWPresentationSize::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationSize.def("WriteStep", (void (RWStepVisual_RWPresentationSize::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationSize> &) const) &RWStepVisual_RWPresentationSize::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentationSize.def("Share", (void (RWStepVisual_RWPresentationSize::*)(const opencascade::handle<StepVisual_PresentationSize> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentationSize::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONSTYLEASSIGNMENT
py::class_<RWStepVisual_RWPresentationStyleAssignment> cls_RWStepVisual_RWPresentationStyleAssignment(mod, "RWStepVisual_RWPresentationStyleAssignment", "Read & Write Module for PresentationStyleAssignment");

// Constructors
cls_RWStepVisual_RWPresentationStyleAssignment.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationStyleAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationStyleAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationStyleAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationStyleAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationStyleAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationStyleAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationStyleAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationStyleAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationStyleAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationStyleAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationStyleAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationStyleAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationStyleAssignment.def("ReadStep", (void (RWStepVisual_RWPresentationStyleAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationStyleAssignment> &) const) &RWStepVisual_RWPresentationStyleAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationStyleAssignment.def("WriteStep", (void (RWStepVisual_RWPresentationStyleAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationStyleAssignment> &) const) &RWStepVisual_RWPresentationStyleAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentationStyleAssignment.def("Share", (void (RWStepVisual_RWPresentationStyleAssignment::*)(const opencascade::handle<StepVisual_PresentationStyleAssignment> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentationStyleAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONSTYLEBYCONTEXT
py::class_<RWStepVisual_RWPresentationStyleByContext> cls_RWStepVisual_RWPresentationStyleByContext(mod, "RWStepVisual_RWPresentationStyleByContext", "Read & Write Module for PresentationStyleByContext");

// Constructors
cls_RWStepVisual_RWPresentationStyleByContext.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationStyleByContext.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationStyleByContext::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationStyleByContext.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationStyleByContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationStyleByContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationStyleByContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationStyleByContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationStyleByContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationStyleByContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationStyleByContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationStyleByContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationStyleByContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationStyleByContext.def("ReadStep", (void (RWStepVisual_RWPresentationStyleByContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationStyleByContext> &) const) &RWStepVisual_RWPresentationStyleByContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationStyleByContext.def("WriteStep", (void (RWStepVisual_RWPresentationStyleByContext::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationStyleByContext> &) const) &RWStepVisual_RWPresentationStyleByContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentationStyleByContext.def("Share", (void (RWStepVisual_RWPresentationStyleByContext::*)(const opencascade::handle<StepVisual_PresentationStyleByContext> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentationStyleByContext::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPRESENTATIONVIEW
py::class_<RWStepVisual_RWPresentationView> cls_RWStepVisual_RWPresentationView(mod, "RWStepVisual_RWPresentationView", "Read & Write Module for PresentationView");

// Constructors
cls_RWStepVisual_RWPresentationView.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentationView.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentationView::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationView.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentationView::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationView.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentationView::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentationView.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentationView::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationView.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentationView::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentationView.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentationView::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentationView.def("ReadStep", (void (RWStepVisual_RWPresentationView::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentationView> &) const) &RWStepVisual_RWPresentationView::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentationView.def("WriteStep", (void (RWStepVisual_RWPresentationView::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentationView> &) const) &RWStepVisual_RWPresentationView::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentationView.def("Share", (void (RWStepVisual_RWPresentationView::*)(const opencascade::handle<StepVisual_PresentationView> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentationView::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWPRESENTEDITEMREPRESENTATION
py::class_<RWStepVisual_RWPresentedItemRepresentation> cls_RWStepVisual_RWPresentedItemRepresentation(mod, "RWStepVisual_RWPresentedItemRepresentation", "Read & Write Module for PresentedItemRepresentation");

// Constructors
cls_RWStepVisual_RWPresentedItemRepresentation.def(py::init<>());

// Methods
// cls_RWStepVisual_RWPresentedItemRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWPresentedItemRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentedItemRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWPresentedItemRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentedItemRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWPresentedItemRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWPresentedItemRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWPresentedItemRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWPresentedItemRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWPresentedItemRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWPresentedItemRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWPresentedItemRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWPresentedItemRepresentation.def("ReadStep", (void (RWStepVisual_RWPresentedItemRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_PresentedItemRepresentation> &) const) &RWStepVisual_RWPresentedItemRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWPresentedItemRepresentation.def("WriteStep", (void (RWStepVisual_RWPresentedItemRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_PresentedItemRepresentation> &) const) &RWStepVisual_RWPresentedItemRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWPresentedItemRepresentation.def("Share", (void (RWStepVisual_RWPresentedItemRepresentation::*)(const opencascade::handle<StepVisual_PresentedItemRepresentation> &, Interface_EntityIterator &) const) &RWStepVisual_RWPresentedItemRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSTYLEDITEM
py::class_<RWStepVisual_RWStyledItem> cls_RWStepVisual_RWStyledItem(mod, "RWStepVisual_RWStyledItem", "Read & Write Module for StyledItem");

// Constructors
cls_RWStepVisual_RWStyledItem.def(py::init<>());

// Methods
// cls_RWStepVisual_RWStyledItem.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWStyledItem::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWStyledItem.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWStyledItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWStyledItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWStyledItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWStyledItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWStyledItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWStyledItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWStyledItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWStyledItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWStyledItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWStyledItem.def("ReadStep", (void (RWStepVisual_RWStyledItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_StyledItem> &) const) &RWStepVisual_RWStyledItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWStyledItem.def("WriteStep", (void (RWStepVisual_RWStyledItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_StyledItem> &) const) &RWStepVisual_RWStyledItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWStyledItem.def("Share", (void (RWStepVisual_RWStyledItem::*)(const opencascade::handle<StepVisual_StyledItem> &, Interface_EntityIterator &) const) &RWStepVisual_RWStyledItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSURFACESIDESTYLE
py::class_<RWStepVisual_RWSurfaceSideStyle> cls_RWStepVisual_RWSurfaceSideStyle(mod, "RWStepVisual_RWSurfaceSideStyle", "Read & Write Module for SurfaceSideStyle");

// Constructors
cls_RWStepVisual_RWSurfaceSideStyle.def(py::init<>());

// Methods
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceSideStyle::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceSideStyle::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceSideStyle::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceSideStyle::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceSideStyle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceSideStyle::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceSideStyle.def("ReadStep", (void (RWStepVisual_RWSurfaceSideStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceSideStyle> &) const) &RWStepVisual_RWSurfaceSideStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceSideStyle.def("WriteStep", (void (RWStepVisual_RWSurfaceSideStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceSideStyle> &) const) &RWStepVisual_RWSurfaceSideStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceSideStyle.def("Share", (void (RWStepVisual_RWSurfaceSideStyle::*)(const opencascade::handle<StepVisual_SurfaceSideStyle> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceSideStyle::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSURFACESTYLEBOUNDARY
py::class_<RWStepVisual_RWSurfaceStyleBoundary> cls_RWStepVisual_RWSurfaceStyleBoundary(mod, "RWStepVisual_RWSurfaceStyleBoundary", "Read & Write Module for SurfaceStyleBoundary");

// Constructors
cls_RWStepVisual_RWSurfaceStyleBoundary.def(py::init<>());

// Methods
// cls_RWStepVisual_RWSurfaceStyleBoundary.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleBoundary::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleBoundary.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleBoundary::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleBoundary.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleBoundary::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleBoundary.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleBoundary::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleBoundary.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceStyleBoundary::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleBoundary.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceStyleBoundary::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceStyleBoundary.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleBoundary::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleBoundary> &) const) &RWStepVisual_RWSurfaceStyleBoundary::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleBoundary.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleBoundary::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleBoundary> &) const) &RWStepVisual_RWSurfaceStyleBoundary::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleBoundary.def("Share", (void (RWStepVisual_RWSurfaceStyleBoundary::*)(const opencascade::handle<StepVisual_SurfaceStyleBoundary> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceStyleBoundary::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSURFACESTYLECONTROLGRID
py::class_<RWStepVisual_RWSurfaceStyleControlGrid> cls_RWStepVisual_RWSurfaceStyleControlGrid(mod, "RWStepVisual_RWSurfaceStyleControlGrid", "Read & Write Module for SurfaceStyleControlGrid");

// Constructors
cls_RWStepVisual_RWSurfaceStyleControlGrid.def(py::init<>());

// Methods
// cls_RWStepVisual_RWSurfaceStyleControlGrid.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleControlGrid::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleControlGrid.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleControlGrid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleControlGrid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleControlGrid::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleControlGrid.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleControlGrid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleControlGrid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceStyleControlGrid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleControlGrid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceStyleControlGrid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceStyleControlGrid.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleControlGrid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleControlGrid> &) const) &RWStepVisual_RWSurfaceStyleControlGrid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleControlGrid.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleControlGrid::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleControlGrid> &) const) &RWStepVisual_RWSurfaceStyleControlGrid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleControlGrid.def("Share", (void (RWStepVisual_RWSurfaceStyleControlGrid::*)(const opencascade::handle<StepVisual_SurfaceStyleControlGrid> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceStyleControlGrid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSURFACESTYLEFILLAREA
py::class_<RWStepVisual_RWSurfaceStyleFillArea> cls_RWStepVisual_RWSurfaceStyleFillArea(mod, "RWStepVisual_RWSurfaceStyleFillArea", "Read & Write Module for SurfaceStyleFillArea");

// Constructors
cls_RWStepVisual_RWSurfaceStyleFillArea.def(py::init<>());

// Methods
// cls_RWStepVisual_RWSurfaceStyleFillArea.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleFillArea::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleFillArea.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleFillArea::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleFillArea.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleFillArea::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleFillArea.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleFillArea::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleFillArea.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceStyleFillArea::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleFillArea.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceStyleFillArea::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceStyleFillArea.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleFillArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleFillArea> &) const) &RWStepVisual_RWSurfaceStyleFillArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleFillArea.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleFillArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleFillArea> &) const) &RWStepVisual_RWSurfaceStyleFillArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleFillArea.def("Share", (void (RWStepVisual_RWSurfaceStyleFillArea::*)(const opencascade::handle<StepVisual_SurfaceStyleFillArea> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceStyleFillArea::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSURFACESTYLEPARAMETERLINE
py::class_<RWStepVisual_RWSurfaceStyleParameterLine> cls_RWStepVisual_RWSurfaceStyleParameterLine(mod, "RWStepVisual_RWSurfaceStyleParameterLine", "Read & Write Module for SurfaceStyleParameterLine");

// Constructors
cls_RWStepVisual_RWSurfaceStyleParameterLine.def(py::init<>());

// Methods
// cls_RWStepVisual_RWSurfaceStyleParameterLine.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleParameterLine::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleParameterLine.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleParameterLine::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleParameterLine.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleParameterLine::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleParameterLine.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleParameterLine::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleParameterLine.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceStyleParameterLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleParameterLine.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceStyleParameterLine::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceStyleParameterLine.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleParameterLine::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleParameterLine> &) const) &RWStepVisual_RWSurfaceStyleParameterLine::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleParameterLine.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleParameterLine::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleParameterLine> &) const) &RWStepVisual_RWSurfaceStyleParameterLine::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleParameterLine.def("Share", (void (RWStepVisual_RWSurfaceStyleParameterLine::*)(const opencascade::handle<StepVisual_SurfaceStyleParameterLine> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceStyleParameterLine::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSURFACESTYLESEGMENTATIONCURVE
py::class_<RWStepVisual_RWSurfaceStyleSegmentationCurve> cls_RWStepVisual_RWSurfaceStyleSegmentationCurve(mod, "RWStepVisual_RWSurfaceStyleSegmentationCurve", "Read & Write Module for SurfaceStyleSegmentationCurve");

// Constructors
cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def(py::init<>());

// Methods
// cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleSegmentationCurve::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleSegmentationCurve::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleSegmentationCurve::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleSegmentationCurve::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceStyleSegmentationCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceStyleSegmentationCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleSegmentationCurve::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleSegmentationCurve> &) const) &RWStepVisual_RWSurfaceStyleSegmentationCurve::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleSegmentationCurve::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleSegmentationCurve> &) const) &RWStepVisual_RWSurfaceStyleSegmentationCurve::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleSegmentationCurve.def("Share", (void (RWStepVisual_RWSurfaceStyleSegmentationCurve::*)(const opencascade::handle<StepVisual_SurfaceStyleSegmentationCurve> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceStyleSegmentationCurve::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSURFACESTYLESILHOUETTE
py::class_<RWStepVisual_RWSurfaceStyleSilhouette> cls_RWStepVisual_RWSurfaceStyleSilhouette(mod, "RWStepVisual_RWSurfaceStyleSilhouette", "Read & Write Module for SurfaceStyleSilhouette");

// Constructors
cls_RWStepVisual_RWSurfaceStyleSilhouette.def(py::init<>());

// Methods
// cls_RWStepVisual_RWSurfaceStyleSilhouette.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleSilhouette::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleSilhouette.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleSilhouette::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleSilhouette.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleSilhouette::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleSilhouette.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleSilhouette::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleSilhouette.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceStyleSilhouette::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleSilhouette.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceStyleSilhouette::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceStyleSilhouette.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleSilhouette::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleSilhouette> &) const) &RWStepVisual_RWSurfaceStyleSilhouette::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleSilhouette.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleSilhouette::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleSilhouette> &) const) &RWStepVisual_RWSurfaceStyleSilhouette::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleSilhouette.def("Share", (void (RWStepVisual_RWSurfaceStyleSilhouette::*)(const opencascade::handle<StepVisual_SurfaceStyleSilhouette> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceStyleSilhouette::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWSURFACESTYLEUSAGE
py::class_<RWStepVisual_RWSurfaceStyleUsage> cls_RWStepVisual_RWSurfaceStyleUsage(mod, "RWStepVisual_RWSurfaceStyleUsage", "Read & Write Module for SurfaceStyleUsage");

// Constructors
cls_RWStepVisual_RWSurfaceStyleUsage.def(py::init<>());

// Methods
// cls_RWStepVisual_RWSurfaceStyleUsage.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleUsage::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleUsage.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleUsage::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleUsage.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceStyleUsage::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceStyleUsage.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceStyleUsage::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleUsage.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceStyleUsage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceStyleUsage.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceStyleUsage::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceStyleUsage.def("ReadStep", (void (RWStepVisual_RWSurfaceStyleUsage::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceStyleUsage> &) const) &RWStepVisual_RWSurfaceStyleUsage::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleUsage.def("WriteStep", (void (RWStepVisual_RWSurfaceStyleUsage::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceStyleUsage> &) const) &RWStepVisual_RWSurfaceStyleUsage::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceStyleUsage.def("Share", (void (RWStepVisual_RWSurfaceStyleUsage::*)(const opencascade::handle<StepVisual_SurfaceStyleUsage> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceStyleUsage::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTEMPLATE
py::class_<RWStepVisual_RWTemplate> cls_RWStepVisual_RWTemplate(mod, "RWStepVisual_RWTemplate", "Read & Write Module for Template");

// Constructors
cls_RWStepVisual_RWTemplate.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTemplate.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTemplate::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTemplate.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTemplate::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTemplate.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTemplate::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTemplate.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTemplate::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTemplate.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTemplate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTemplate.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTemplate::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTemplate.def("ReadStep", (void (RWStepVisual_RWTemplate::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_Template> &) const) &RWStepVisual_RWTemplate::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTemplate.def("WriteStep", (void (RWStepVisual_RWTemplate::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_Template> &) const) &RWStepVisual_RWTemplate::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTemplate.def("Share", (void (RWStepVisual_RWTemplate::*)(const opencascade::handle<StepVisual_Template> &, Interface_EntityIterator &) const) &RWStepVisual_RWTemplate::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTEMPLATEINSTANCE
py::class_<RWStepVisual_RWTemplateInstance> cls_RWStepVisual_RWTemplateInstance(mod, "RWStepVisual_RWTemplateInstance", "Read & Write Module for TemplateInstance");

// Constructors
cls_RWStepVisual_RWTemplateInstance.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTemplateInstance.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTemplateInstance::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTemplateInstance.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTemplateInstance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTemplateInstance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTemplateInstance::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTemplateInstance.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTemplateInstance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTemplateInstance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTemplateInstance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTemplateInstance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTemplateInstance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTemplateInstance.def("ReadStep", (void (RWStepVisual_RWTemplateInstance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TemplateInstance> &) const) &RWStepVisual_RWTemplateInstance::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTemplateInstance.def("WriteStep", (void (RWStepVisual_RWTemplateInstance::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TemplateInstance> &) const) &RWStepVisual_RWTemplateInstance::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTemplateInstance.def("Share", (void (RWStepVisual_RWTemplateInstance::*)(const opencascade::handle<StepVisual_TemplateInstance> &, Interface_EntityIterator &) const) &RWStepVisual_RWTemplateInstance::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTESSELLATEDANNOTATIONOCCURRENCE
py::class_<RWStepVisual_RWTessellatedAnnotationOccurrence> cls_RWStepVisual_RWTessellatedAnnotationOccurrence(mod, "RWStepVisual_RWTessellatedAnnotationOccurrence", "Read & Write Module for AnnotationOccurrence");

// Constructors
cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTessellatedAnnotationOccurrence::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTessellatedAnnotationOccurrence::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTessellatedAnnotationOccurrence::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTessellatedAnnotationOccurrence::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTessellatedAnnotationOccurrence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTessellatedAnnotationOccurrence::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def("ReadStep", (void (RWStepVisual_RWTessellatedAnnotationOccurrence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TessellatedAnnotationOccurrence> &) const) &RWStepVisual_RWTessellatedAnnotationOccurrence::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def("WriteStep", (void (RWStepVisual_RWTessellatedAnnotationOccurrence::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TessellatedAnnotationOccurrence> &) const) &RWStepVisual_RWTessellatedAnnotationOccurrence::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTessellatedAnnotationOccurrence.def("Share", (void (RWStepVisual_RWTessellatedAnnotationOccurrence::*)(const opencascade::handle<StepVisual_TessellatedAnnotationOccurrence> &, Interface_EntityIterator &) const) &RWStepVisual_RWTessellatedAnnotationOccurrence::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTESSELLATEDCURVESET
py::class_<RWStepVisual_RWTessellatedCurveSet> cls_RWStepVisual_RWTessellatedCurveSet(mod, "RWStepVisual_RWTessellatedCurveSet", "Read & Write Module for AnnotationOccurrence");

// Constructors
cls_RWStepVisual_RWTessellatedCurveSet.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTessellatedCurveSet.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTessellatedCurveSet::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTessellatedCurveSet.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTessellatedCurveSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedCurveSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTessellatedCurveSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTessellatedCurveSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTessellatedCurveSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedCurveSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTessellatedCurveSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedCurveSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTessellatedCurveSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTessellatedCurveSet.def("ReadStep", (void (RWStepVisual_RWTessellatedCurveSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TessellatedCurveSet> &) const) &RWStepVisual_RWTessellatedCurveSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTessellatedCurveSet.def("WriteStep", (void (RWStepVisual_RWTessellatedCurveSet::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TessellatedCurveSet> &) const) &RWStepVisual_RWTessellatedCurveSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTessellatedCurveSet.def("Share", (void (RWStepVisual_RWTessellatedCurveSet::*)(const opencascade::handle<StepVisual_TessellatedCurveSet> &, Interface_EntityIterator &) const) &RWStepVisual_RWTessellatedCurveSet::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTESSELLATEDGEOMETRICSET
py::class_<RWStepVisual_RWTessellatedGeometricSet> cls_RWStepVisual_RWTessellatedGeometricSet(mod, "RWStepVisual_RWTessellatedGeometricSet", "Read & Write Module for AnnotationOccurrence");

// Constructors
cls_RWStepVisual_RWTessellatedGeometricSet.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTessellatedGeometricSet.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTessellatedGeometricSet::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTessellatedGeometricSet.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTessellatedGeometricSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedGeometricSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTessellatedGeometricSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTessellatedGeometricSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTessellatedGeometricSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedGeometricSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTessellatedGeometricSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedGeometricSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTessellatedGeometricSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTessellatedGeometricSet.def("ReadStep", (void (RWStepVisual_RWTessellatedGeometricSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TessellatedGeometricSet> &) const) &RWStepVisual_RWTessellatedGeometricSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTessellatedGeometricSet.def("WriteStep", (void (RWStepVisual_RWTessellatedGeometricSet::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TessellatedGeometricSet> &) const) &RWStepVisual_RWTessellatedGeometricSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTessellatedGeometricSet.def("Share", (void (RWStepVisual_RWTessellatedGeometricSet::*)(const opencascade::handle<StepVisual_TessellatedGeometricSet> &, Interface_EntityIterator &) const) &RWStepVisual_RWTessellatedGeometricSet::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTESSELLATEDITEM
py::class_<RWStepVisual_RWTessellatedItem> cls_RWStepVisual_RWTessellatedItem(mod, "RWStepVisual_RWTessellatedItem", "Read & Write Module for AnnotationOccurrence");

// Constructors
cls_RWStepVisual_RWTessellatedItem.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTessellatedItem.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTessellatedItem::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTessellatedItem.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTessellatedItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTessellatedItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTessellatedItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTessellatedItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTessellatedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTessellatedItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTessellatedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTessellatedItem.def("ReadStep", (void (RWStepVisual_RWTessellatedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TessellatedItem> &) const) &RWStepVisual_RWTessellatedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTessellatedItem.def("WriteStep", (void (RWStepVisual_RWTessellatedItem::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TessellatedItem> &) const) &RWStepVisual_RWTessellatedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPVISUAL_RWTEXTLITERAL
py::class_<RWStepVisual_RWTextLiteral> cls_RWStepVisual_RWTextLiteral(mod, "RWStepVisual_RWTextLiteral", "Read & Write Module for TextLiteral");

// Constructors
cls_RWStepVisual_RWTextLiteral.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTextLiteral.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTextLiteral::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTextLiteral.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTextLiteral::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTextLiteral.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTextLiteral::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTextLiteral.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTextLiteral::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTextLiteral.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTextLiteral::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTextLiteral.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTextLiteral::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTextLiteral.def("ReadStep", (void (RWStepVisual_RWTextLiteral::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TextLiteral> &) const) &RWStepVisual_RWTextLiteral::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTextLiteral.def("WriteStep", (void (RWStepVisual_RWTextLiteral::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TextLiteral> &) const) &RWStepVisual_RWTextLiteral::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTextLiteral.def("Share", (void (RWStepVisual_RWTextLiteral::*)(const opencascade::handle<StepVisual_TextLiteral> &, Interface_EntityIterator &) const) &RWStepVisual_RWTextLiteral::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTEXTSTYLE
py::class_<RWStepVisual_RWTextStyle> cls_RWStepVisual_RWTextStyle(mod, "RWStepVisual_RWTextStyle", "Read & Write Module for TextStyle");

// Constructors
cls_RWStepVisual_RWTextStyle.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTextStyle.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTextStyle::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTextStyle.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTextStyle::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyle.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTextStyle::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTextStyle.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTextStyle::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyle.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTextStyle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyle.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTextStyle::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTextStyle.def("ReadStep", (void (RWStepVisual_RWTextStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TextStyle> &) const) &RWStepVisual_RWTextStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTextStyle.def("WriteStep", (void (RWStepVisual_RWTextStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TextStyle> &) const) &RWStepVisual_RWTextStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTextStyle.def("Share", (void (RWStepVisual_RWTextStyle::*)(const opencascade::handle<StepVisual_TextStyle> &, Interface_EntityIterator &) const) &RWStepVisual_RWTextStyle::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTEXTSTYLEFORDEFINEDFONT
py::class_<RWStepVisual_RWTextStyleForDefinedFont> cls_RWStepVisual_RWTextStyleForDefinedFont(mod, "RWStepVisual_RWTextStyleForDefinedFont", "Read & Write Module for TextStyleForDefinedFont");

// Constructors
cls_RWStepVisual_RWTextStyleForDefinedFont.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTextStyleForDefinedFont.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTextStyleForDefinedFont::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTextStyleForDefinedFont.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTextStyleForDefinedFont::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyleForDefinedFont.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTextStyleForDefinedFont::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTextStyleForDefinedFont.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTextStyleForDefinedFont::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyleForDefinedFont.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTextStyleForDefinedFont::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyleForDefinedFont.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTextStyleForDefinedFont::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTextStyleForDefinedFont.def("ReadStep", (void (RWStepVisual_RWTextStyleForDefinedFont::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TextStyleForDefinedFont> &) const) &RWStepVisual_RWTextStyleForDefinedFont::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTextStyleForDefinedFont.def("WriteStep", (void (RWStepVisual_RWTextStyleForDefinedFont::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TextStyleForDefinedFont> &) const) &RWStepVisual_RWTextStyleForDefinedFont::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTextStyleForDefinedFont.def("Share", (void (RWStepVisual_RWTextStyleForDefinedFont::*)(const opencascade::handle<StepVisual_TextStyleForDefinedFont> &, Interface_EntityIterator &) const) &RWStepVisual_RWTextStyleForDefinedFont::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWTEXTSTYLEWITHBOXCHARACTERISTICS
py::class_<RWStepVisual_RWTextStyleWithBoxCharacteristics> cls_RWStepVisual_RWTextStyleWithBoxCharacteristics(mod, "RWStepVisual_RWTextStyleWithBoxCharacteristics", "Read & Write Module for TextStyleWithBoxCharacteristics");

// Constructors
cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def(py::init<>());

// Methods
// cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWTextStyleWithBoxCharacteristics::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWTextStyleWithBoxCharacteristics::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWTextStyleWithBoxCharacteristics::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWTextStyleWithBoxCharacteristics::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWTextStyleWithBoxCharacteristics::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWTextStyleWithBoxCharacteristics::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def("ReadStep", (void (RWStepVisual_RWTextStyleWithBoxCharacteristics::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_TextStyleWithBoxCharacteristics> &) const) &RWStepVisual_RWTextStyleWithBoxCharacteristics::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def("WriteStep", (void (RWStepVisual_RWTextStyleWithBoxCharacteristics::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_TextStyleWithBoxCharacteristics> &) const) &RWStepVisual_RWTextStyleWithBoxCharacteristics::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWTextStyleWithBoxCharacteristics.def("Share", (void (RWStepVisual_RWTextStyleWithBoxCharacteristics::*)(const opencascade::handle<StepVisual_TextStyleWithBoxCharacteristics> &, Interface_EntityIterator &) const) &RWStepVisual_RWTextStyleWithBoxCharacteristics::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPVISUAL_RWVIEWVOLUME
py::class_<RWStepVisual_RWViewVolume> cls_RWStepVisual_RWViewVolume(mod, "RWStepVisual_RWViewVolume", "Read & Write Module for ViewVolume");

// Constructors
cls_RWStepVisual_RWViewVolume.def(py::init<>());

// Methods
// cls_RWStepVisual_RWViewVolume.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWViewVolume::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWViewVolume.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWViewVolume::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWViewVolume.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWViewVolume::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWViewVolume.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWViewVolume::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWViewVolume.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWViewVolume::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWViewVolume.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWViewVolume::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWViewVolume.def("ReadStep", (void (RWStepVisual_RWViewVolume::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_ViewVolume> &) const) &RWStepVisual_RWViewVolume::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWViewVolume.def("WriteStep", (void (RWStepVisual_RWViewVolume::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_ViewVolume> &) const) &RWStepVisual_RWViewVolume::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWViewVolume.def("Share", (void (RWStepVisual_RWViewVolume::*)(const opencascade::handle<StepVisual_ViewVolume> &, Interface_EntityIterator &) const) &RWStepVisual_RWViewVolume::Share, "None", py::arg("ent"), py::arg("iter"));


}
