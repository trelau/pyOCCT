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

void bind_RWStepVisual_RWAnnotationCurveOccurrence(py::module &);
void bind_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem(py::module &);
void bind_RWStepVisual_RWAnnotationFillArea(py::module &);
void bind_RWStepVisual_RWAnnotationFillAreaOccurrence(py::module &);
void bind_RWStepVisual_RWAnnotationOccurrence(py::module &);
void bind_RWStepVisual_RWAnnotationPlane(py::module &);
void bind_RWStepVisual_RWAreaInSet(py::module &);
void bind_RWStepVisual_RWBackgroundColour(py::module &);
void bind_RWStepVisual_RWCameraImage(py::module &);
void bind_RWStepVisual_RWCameraModel(py::module &);
void bind_RWStepVisual_RWCameraModelD2(py::module &);
void bind_RWStepVisual_RWCameraModelD3(py::module &);
void bind_RWStepVisual_RWCameraModelD3MultiClipping(py::module &);
void bind_RWStepVisual_RWCameraModelD3MultiClippingIntersection(py::module &);
void bind_RWStepVisual_RWCameraModelD3MultiClippingUnion(py::module &);
void bind_RWStepVisual_RWCameraUsage(py::module &);
void bind_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation(py::module &);
void bind_RWStepVisual_RWColour(py::module &);
void bind_RWStepVisual_RWColourRgb(py::module &);
void bind_RWStepVisual_RWColourSpecification(py::module &);
void bind_RWStepVisual_RWCompositeText(py::module &);
void bind_RWStepVisual_RWCompositeTextWithExtent(py::module &);
void bind_RWStepVisual_RWContextDependentInvisibility(py::module &);
void bind_RWStepVisual_RWContextDependentOverRidingStyledItem(py::module &);
void bind_RWStepVisual_RWCoordinatesList(py::module &);
void bind_RWStepVisual_RWCurveStyle(py::module &);
void bind_RWStepVisual_RWCurveStyleFont(py::module &);
void bind_RWStepVisual_RWCurveStyleFontPattern(py::module &);
void bind_RWStepVisual_RWDraughtingCallout(py::module &);
void bind_RWStepVisual_RWDraughtingModel(py::module &);
void bind_RWStepVisual_RWDraughtingPreDefinedColour(py::module &);
void bind_RWStepVisual_RWDraughtingPreDefinedCurveFont(py::module &);
void bind_RWStepVisual_RWExternallyDefinedCurveFont(py::module &);
void bind_RWStepVisual_RWFillAreaStyle(py::module &);
void bind_RWStepVisual_RWFillAreaStyleColour(py::module &);
void bind_RWStepVisual_RWInvisibility(py::module &);
void bind_RWStepVisual_RWMechanicalDesignGeometricPresentationArea(py::module &);
void bind_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation(py::module &);
void bind_RWStepVisual_RWOverRidingStyledItem(py::module &);
void bind_RWStepVisual_RWPlanarBox(py::module &);
void bind_RWStepVisual_RWPlanarExtent(py::module &);
void bind_RWStepVisual_RWPointStyle(py::module &);
void bind_RWStepVisual_RWPreDefinedColour(py::module &);
void bind_RWStepVisual_RWPreDefinedCurveFont(py::module &);
void bind_RWStepVisual_RWPreDefinedItem(py::module &);
void bind_RWStepVisual_RWPresentationArea(py::module &);
void bind_RWStepVisual_RWPresentationLayerAssignment(py::module &);
void bind_RWStepVisual_RWPresentationLayerUsage(py::module &);
void bind_RWStepVisual_RWPresentationRepresentation(py::module &);
void bind_RWStepVisual_RWPresentationSet(py::module &);
void bind_RWStepVisual_RWPresentationSize(py::module &);
void bind_RWStepVisual_RWPresentationStyleAssignment(py::module &);
void bind_RWStepVisual_RWPresentationStyleByContext(py::module &);
void bind_RWStepVisual_RWPresentationView(py::module &);
void bind_RWStepVisual_RWPresentedItemRepresentation(py::module &);
void bind_RWStepVisual_RWStyledItem(py::module &);
void bind_RWStepVisual_RWSurfaceSideStyle(py::module &);
void bind_RWStepVisual_RWSurfaceStyleBoundary(py::module &);
void bind_RWStepVisual_RWSurfaceStyleControlGrid(py::module &);
void bind_RWStepVisual_RWSurfaceStyleFillArea(py::module &);
void bind_RWStepVisual_RWSurfaceStyleParameterLine(py::module &);
void bind_RWStepVisual_RWSurfaceStyleSegmentationCurve(py::module &);
void bind_RWStepVisual_RWSurfaceStyleSilhouette(py::module &);
void bind_RWStepVisual_RWSurfaceStyleUsage(py::module &);
void bind_RWStepVisual_RWTemplate(py::module &);
void bind_RWStepVisual_RWTemplateInstance(py::module &);
void bind_RWStepVisual_RWTessellatedAnnotationOccurrence(py::module &);
void bind_RWStepVisual_RWTessellatedCurveSet(py::module &);
void bind_RWStepVisual_RWTessellatedGeometricSet(py::module &);
void bind_RWStepVisual_RWTessellatedItem(py::module &);
void bind_RWStepVisual_RWTextLiteral(py::module &);
void bind_RWStepVisual_RWTextStyle(py::module &);
void bind_RWStepVisual_RWTextStyleForDefinedFont(py::module &);
void bind_RWStepVisual_RWTextStyleWithBoxCharacteristics(py::module &);
void bind_RWStepVisual_RWViewVolume(py::module &);

PYBIND11_MODULE(RWStepVisual, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepVisual");

bind_RWStepVisual_RWAnnotationCurveOccurrence(mod);
bind_RWStepVisual_RWAnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem(mod);
bind_RWStepVisual_RWAnnotationFillArea(mod);
bind_RWStepVisual_RWAnnotationFillAreaOccurrence(mod);
bind_RWStepVisual_RWAnnotationOccurrence(mod);
bind_RWStepVisual_RWAnnotationPlane(mod);
bind_RWStepVisual_RWAreaInSet(mod);
bind_RWStepVisual_RWBackgroundColour(mod);
bind_RWStepVisual_RWCameraImage(mod);
bind_RWStepVisual_RWCameraModel(mod);
bind_RWStepVisual_RWCameraModelD2(mod);
bind_RWStepVisual_RWCameraModelD3(mod);
bind_RWStepVisual_RWCameraModelD3MultiClipping(mod);
bind_RWStepVisual_RWCameraModelD3MultiClippingIntersection(mod);
bind_RWStepVisual_RWCameraModelD3MultiClippingUnion(mod);
bind_RWStepVisual_RWCameraUsage(mod);
bind_RWStepVisual_RWCharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation(mod);
bind_RWStepVisual_RWColour(mod);
bind_RWStepVisual_RWColourRgb(mod);
bind_RWStepVisual_RWColourSpecification(mod);
bind_RWStepVisual_RWCompositeText(mod);
bind_RWStepVisual_RWCompositeTextWithExtent(mod);
bind_RWStepVisual_RWContextDependentInvisibility(mod);
bind_RWStepVisual_RWContextDependentOverRidingStyledItem(mod);
bind_RWStepVisual_RWCoordinatesList(mod);
bind_RWStepVisual_RWCurveStyle(mod);
bind_RWStepVisual_RWCurveStyleFont(mod);
bind_RWStepVisual_RWCurveStyleFontPattern(mod);
bind_RWStepVisual_RWDraughtingCallout(mod);
bind_RWStepVisual_RWDraughtingModel(mod);
bind_RWStepVisual_RWDraughtingPreDefinedColour(mod);
bind_RWStepVisual_RWDraughtingPreDefinedCurveFont(mod);
bind_RWStepVisual_RWExternallyDefinedCurveFont(mod);
bind_RWStepVisual_RWFillAreaStyle(mod);
bind_RWStepVisual_RWFillAreaStyleColour(mod);
bind_RWStepVisual_RWInvisibility(mod);
bind_RWStepVisual_RWMechanicalDesignGeometricPresentationArea(mod);
bind_RWStepVisual_RWMechanicalDesignGeometricPresentationRepresentation(mod);
bind_RWStepVisual_RWOverRidingStyledItem(mod);
bind_RWStepVisual_RWPlanarBox(mod);
bind_RWStepVisual_RWPlanarExtent(mod);
bind_RWStepVisual_RWPointStyle(mod);
bind_RWStepVisual_RWPreDefinedColour(mod);
bind_RWStepVisual_RWPreDefinedCurveFont(mod);
bind_RWStepVisual_RWPreDefinedItem(mod);
bind_RWStepVisual_RWPresentationArea(mod);
bind_RWStepVisual_RWPresentationLayerAssignment(mod);
bind_RWStepVisual_RWPresentationLayerUsage(mod);
bind_RWStepVisual_RWPresentationRepresentation(mod);
bind_RWStepVisual_RWPresentationSet(mod);
bind_RWStepVisual_RWPresentationSize(mod);
bind_RWStepVisual_RWPresentationStyleAssignment(mod);
bind_RWStepVisual_RWPresentationStyleByContext(mod);
bind_RWStepVisual_RWPresentationView(mod);
bind_RWStepVisual_RWPresentedItemRepresentation(mod);
bind_RWStepVisual_RWStyledItem(mod);
bind_RWStepVisual_RWSurfaceSideStyle(mod);
bind_RWStepVisual_RWSurfaceStyleBoundary(mod);
bind_RWStepVisual_RWSurfaceStyleControlGrid(mod);
bind_RWStepVisual_RWSurfaceStyleFillArea(mod);
bind_RWStepVisual_RWSurfaceStyleParameterLine(mod);
bind_RWStepVisual_RWSurfaceStyleSegmentationCurve(mod);
bind_RWStepVisual_RWSurfaceStyleSilhouette(mod);
bind_RWStepVisual_RWSurfaceStyleUsage(mod);
bind_RWStepVisual_RWTemplate(mod);
bind_RWStepVisual_RWTemplateInstance(mod);
bind_RWStepVisual_RWTessellatedAnnotationOccurrence(mod);
bind_RWStepVisual_RWTessellatedCurveSet(mod);
bind_RWStepVisual_RWTessellatedGeometricSet(mod);
bind_RWStepVisual_RWTessellatedItem(mod);
bind_RWStepVisual_RWTextLiteral(mod);
bind_RWStepVisual_RWTextStyle(mod);
bind_RWStepVisual_RWTextStyleForDefinedFont(mod);
bind_RWStepVisual_RWTextStyleWithBoxCharacteristics(mod);
bind_RWStepVisual_RWViewVolume(mod);

}
