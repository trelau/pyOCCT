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

void bind_RWStepDimTol_RWAngularityTolerance(py::module &);
void bind_RWStepDimTol_RWCircularRunoutTolerance(py::module &);
void bind_RWStepDimTol_RWCoaxialityTolerance(py::module &);
void bind_RWStepDimTol_RWCommonDatum(py::module &);
void bind_RWStepDimTol_RWConcentricityTolerance(py::module &);
void bind_RWStepDimTol_RWCylindricityTolerance(py::module &);
void bind_RWStepDimTol_RWDatum(py::module &);
void bind_RWStepDimTol_RWDatumFeature(py::module &);
void bind_RWStepDimTol_RWDatumReference(py::module &);
void bind_RWStepDimTol_RWDatumReferenceCompartment(py::module &);
void bind_RWStepDimTol_RWDatumReferenceElement(py::module &);
void bind_RWStepDimTol_RWDatumReferenceModifierWithValue(py::module &);
void bind_RWStepDimTol_RWDatumSystem(py::module &);
void bind_RWStepDimTol_RWDatumTarget(py::module &);
void bind_RWStepDimTol_RWFlatnessTolerance(py::module &);
void bind_RWStepDimTol_RWGeneralDatumReference(py::module &);
void bind_RWStepDimTol_RWGeometricTolerance(py::module &);
void bind_RWStepDimTol_RWGeometricToleranceRelationship(py::module &);
void bind_RWStepDimTol_RWGeometricToleranceWithDatumReference(py::module &);
void bind_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit(py::module &);
void bind_RWStepDimTol_RWGeometricToleranceWithDefinedUnit(py::module &);
void bind_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance(py::module &);
void bind_RWStepDimTol_RWGeometricToleranceWithModifiers(py::module &);
void bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef(py::module &);
void bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(py::module &);
void bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod(py::module &);
void bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(py::module &);
void bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol(py::module &);
void bind_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol(py::module &);
void bind_RWStepDimTol_RWGeoTolAndGeoTolWthMod(py::module &);
void bind_RWStepDimTol_RWLineProfileTolerance(py::module &);
void bind_RWStepDimTol_RWModifiedGeometricTolerance(py::module &);
void bind_RWStepDimTol_RWNonUniformZoneDefinition(py::module &);
void bind_RWStepDimTol_RWParallelismTolerance(py::module &);
void bind_RWStepDimTol_RWPerpendicularityTolerance(py::module &);
void bind_RWStepDimTol_RWPlacedDatumTargetFeature(py::module &);
void bind_RWStepDimTol_RWPositionTolerance(py::module &);
void bind_RWStepDimTol_RWProjectedZoneDefinition(py::module &);
void bind_RWStepDimTol_RWRoundnessTolerance(py::module &);
void bind_RWStepDimTol_RWRunoutZoneDefinition(py::module &);
void bind_RWStepDimTol_RWRunoutZoneOrientation(py::module &);
void bind_RWStepDimTol_RWStraightnessTolerance(py::module &);
void bind_RWStepDimTol_RWSurfaceProfileTolerance(py::module &);
void bind_RWStepDimTol_RWSymmetryTolerance(py::module &);
void bind_RWStepDimTol_RWToleranceZone(py::module &);
void bind_RWStepDimTol_RWToleranceZoneDefinition(py::module &);
void bind_RWStepDimTol_RWToleranceZoneForm(py::module &);
void bind_RWStepDimTol_RWTotalRunoutTolerance(py::module &);
void bind_RWStepDimTol_RWUnequallyDisposedGeometricTolerance(py::module &);

PYBIND11_MODULE(RWStepDimTol, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepDimTol");

bind_RWStepDimTol_RWAngularityTolerance(mod);
bind_RWStepDimTol_RWCircularRunoutTolerance(mod);
bind_RWStepDimTol_RWCoaxialityTolerance(mod);
bind_RWStepDimTol_RWCommonDatum(mod);
bind_RWStepDimTol_RWConcentricityTolerance(mod);
bind_RWStepDimTol_RWCylindricityTolerance(mod);
bind_RWStepDimTol_RWDatum(mod);
bind_RWStepDimTol_RWDatumFeature(mod);
bind_RWStepDimTol_RWDatumReference(mod);
bind_RWStepDimTol_RWDatumReferenceCompartment(mod);
bind_RWStepDimTol_RWDatumReferenceElement(mod);
bind_RWStepDimTol_RWDatumReferenceModifierWithValue(mod);
bind_RWStepDimTol_RWDatumSystem(mod);
bind_RWStepDimTol_RWDatumTarget(mod);
bind_RWStepDimTol_RWFlatnessTolerance(mod);
bind_RWStepDimTol_RWGeneralDatumReference(mod);
bind_RWStepDimTol_RWGeometricTolerance(mod);
bind_RWStepDimTol_RWGeometricToleranceRelationship(mod);
bind_RWStepDimTol_RWGeometricToleranceWithDatumReference(mod);
bind_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit(mod);
bind_RWStepDimTol_RWGeometricToleranceWithDefinedUnit(mod);
bind_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance(mod);
bind_RWStepDimTol_RWGeometricToleranceWithModifiers(mod);
bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef(mod);
bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(mod);
bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod(mod);
bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(mod);
bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol(mod);
bind_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol(mod);
bind_RWStepDimTol_RWGeoTolAndGeoTolWthMod(mod);
bind_RWStepDimTol_RWLineProfileTolerance(mod);
bind_RWStepDimTol_RWModifiedGeometricTolerance(mod);
bind_RWStepDimTol_RWNonUniformZoneDefinition(mod);
bind_RWStepDimTol_RWParallelismTolerance(mod);
bind_RWStepDimTol_RWPerpendicularityTolerance(mod);
bind_RWStepDimTol_RWPlacedDatumTargetFeature(mod);
bind_RWStepDimTol_RWPositionTolerance(mod);
bind_RWStepDimTol_RWProjectedZoneDefinition(mod);
bind_RWStepDimTol_RWRoundnessTolerance(mod);
bind_RWStepDimTol_RWRunoutZoneDefinition(mod);
bind_RWStepDimTol_RWRunoutZoneOrientation(mod);
bind_RWStepDimTol_RWStraightnessTolerance(mod);
bind_RWStepDimTol_RWSurfaceProfileTolerance(mod);
bind_RWStepDimTol_RWSymmetryTolerance(mod);
bind_RWStepDimTol_RWToleranceZone(mod);
bind_RWStepDimTol_RWToleranceZoneDefinition(mod);
bind_RWStepDimTol_RWToleranceZoneForm(mod);
bind_RWStepDimTol_RWTotalRunoutTolerance(mod);
bind_RWStepDimTol_RWUnequallyDisposedGeometricTolerance(mod);

}
