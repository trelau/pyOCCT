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

void bind_StepDimTol_GeometricToleranceModifier(py::module &);
void bind_StepDimTol_GeometricToleranceType(py::module &);
void bind_StepDimTol_DatumReferenceModifierType(py::module &);
void bind_StepDimTol_SimpleDatumReferenceModifier(py::module &);
void bind_StepDimTol_AreaUnitType(py::module &);
void bind_StepDimTol_LimitCondition(py::module &);
void bind_StepDimTol_GeometricToleranceTarget(py::module &);
void bind_StepDimTol_GeometricTolerance(py::module &);
void bind_StepDimTol_DatumReferenceModifierWithValue(py::module &);
void bind_StepDimTol_SimpleDatumReferenceModifierMember(py::module &);
void bind_StepDimTol_DatumReferenceModifier(py::module &);
void bind_StepDimTol_Array1OfDatumReferenceModifier(py::module &);
void bind_StepDimTol_HArray1OfDatumReferenceModifier(py::module &);
void bind_StepDimTol_Datum(py::module &);
void bind_StepDimTol_DatumSystemOrReference(py::module &);
void bind_StepDimTol_Array1OfDatumSystemOrReference(py::module &);
void bind_StepDimTol_HArray1OfDatumSystemOrReference(py::module &);
void bind_StepDimTol_DatumReference(py::module &);
void bind_StepDimTol_Array1OfDatumReference(py::module &);
void bind_StepDimTol_HArray1OfDatumReference(py::module &);
void bind_StepDimTol_GeometricToleranceWithDatumReference(py::module &);
void bind_StepDimTol_AngularityTolerance(py::module &);
void bind_StepDimTol_DatumOrCommonDatum(py::module &);
void bind_StepDimTol_GeneralDatumReference(py::module &);
void bind_StepDimTol_DatumReferenceCompartment(py::module &);
void bind_StepDimTol_Array1OfDatumReferenceCompartment(py::module &);
void bind_StepDimTol_DatumReferenceElement(py::module &);
void bind_StepDimTol_Array1OfDatumReferenceElement(py::module &);
void bind_StepDimTol_Array1OfGeometricToleranceModifier(py::module &);
void bind_StepDimTol_ToleranceZoneTarget(py::module &);
void bind_StepDimTol_Array1OfToleranceZoneTarget(py::module &);
void bind_StepDimTol_CircularRunoutTolerance(py::module &);
void bind_StepDimTol_CoaxialityTolerance(py::module &);
void bind_StepDimTol_CommonDatum(py::module &);
void bind_StepDimTol_ConcentricityTolerance(py::module &);
void bind_StepDimTol_CylindricityTolerance(py::module &);
void bind_StepDimTol_DatumFeature(py::module &);
void bind_StepDimTol_HArray1OfDatumReferenceCompartment(py::module &);
void bind_StepDimTol_DatumSystem(py::module &);
void bind_StepDimTol_DatumTarget(py::module &);
void bind_StepDimTol_FlatnessTolerance(py::module &);
void bind_StepDimTol_GeometricToleranceRelationship(py::module &);
void bind_StepDimTol_GeometricToleranceWithDefinedUnit(py::module &);
void bind_StepDimTol_GeometricToleranceWithDefinedAreaUnit(py::module &);
void bind_StepDimTol_HArray1OfGeometricToleranceModifier(py::module &);
void bind_StepDimTol_GeometricToleranceWithModifiers(py::module &);
void bind_StepDimTol_GeometricToleranceWithMaximumTolerance(py::module &);
void bind_StepDimTol_GeoTolAndGeoTolWthDatRef(py::module &);
void bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod(py::module &);
void bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(py::module &);
void bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(py::module &);
void bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol(py::module &);
void bind_StepDimTol_GeoTolAndGeoTolWthMod(py::module &);
void bind_StepDimTol_GeoTolAndGeoTolWthMaxTol(py::module &);
void bind_StepDimTol_HArray1OfDatumReferenceElement(py::module &);
void bind_StepDimTol_HArray1OfToleranceZoneTarget(py::module &);
void bind_StepDimTol_LineProfileTolerance(py::module &);
void bind_StepDimTol_ModifiedGeometricTolerance(py::module &);
void bind_StepDimTol_ToleranceZoneForm(py::module &);
void bind_StepDimTol_ToleranceZone(py::module &);
void bind_StepDimTol_ToleranceZoneDefinition(py::module &);
void bind_StepDimTol_NonUniformZoneDefinition(py::module &);
void bind_StepDimTol_ParallelismTolerance(py::module &);
void bind_StepDimTol_PerpendicularityTolerance(py::module &);
void bind_StepDimTol_PlacedDatumTargetFeature(py::module &);
void bind_StepDimTol_PositionTolerance(py::module &);
void bind_StepDimTol_ProjectedZoneDefinition(py::module &);
void bind_StepDimTol_RoundnessTolerance(py::module &);
void bind_StepDimTol_RunoutZoneOrientation(py::module &);
void bind_StepDimTol_RunoutZoneDefinition(py::module &);
void bind_StepDimTol_ShapeToleranceSelect(py::module &);
void bind_StepDimTol_StraightnessTolerance(py::module &);
void bind_StepDimTol_SurfaceProfileTolerance(py::module &);
void bind_StepDimTol_SymmetryTolerance(py::module &);
void bind_StepDimTol_TotalRunoutTolerance(py::module &);
void bind_StepDimTol_UnequallyDisposedGeometricTolerance(py::module &);

PYBIND11_MODULE(StepDimTol, mod) {

py::module::import("OCCT.StepData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.NCollection");

bind_StepDimTol_GeometricToleranceModifier(mod);
bind_StepDimTol_GeometricToleranceType(mod);
bind_StepDimTol_DatumReferenceModifierType(mod);
bind_StepDimTol_SimpleDatumReferenceModifier(mod);
bind_StepDimTol_AreaUnitType(mod);
bind_StepDimTol_LimitCondition(mod);
bind_StepDimTol_GeometricToleranceTarget(mod);
bind_StepDimTol_GeometricTolerance(mod);
bind_StepDimTol_DatumReferenceModifierWithValue(mod);
bind_StepDimTol_SimpleDatumReferenceModifierMember(mod);
bind_StepDimTol_DatumReferenceModifier(mod);
bind_StepDimTol_Array1OfDatumReferenceModifier(mod);
bind_StepDimTol_HArray1OfDatumReferenceModifier(mod);
bind_StepDimTol_Datum(mod);
bind_StepDimTol_DatumSystemOrReference(mod);
bind_StepDimTol_Array1OfDatumSystemOrReference(mod);
bind_StepDimTol_HArray1OfDatumSystemOrReference(mod);
bind_StepDimTol_DatumReference(mod);
bind_StepDimTol_Array1OfDatumReference(mod);
bind_StepDimTol_HArray1OfDatumReference(mod);
bind_StepDimTol_GeometricToleranceWithDatumReference(mod);
bind_StepDimTol_AngularityTolerance(mod);
bind_StepDimTol_DatumOrCommonDatum(mod);
bind_StepDimTol_GeneralDatumReference(mod);
bind_StepDimTol_DatumReferenceCompartment(mod);
bind_StepDimTol_Array1OfDatumReferenceCompartment(mod);
bind_StepDimTol_DatumReferenceElement(mod);
bind_StepDimTol_Array1OfDatumReferenceElement(mod);
bind_StepDimTol_Array1OfGeometricToleranceModifier(mod);
bind_StepDimTol_ToleranceZoneTarget(mod);
bind_StepDimTol_Array1OfToleranceZoneTarget(mod);
bind_StepDimTol_CircularRunoutTolerance(mod);
bind_StepDimTol_CoaxialityTolerance(mod);
bind_StepDimTol_CommonDatum(mod);
bind_StepDimTol_ConcentricityTolerance(mod);
bind_StepDimTol_CylindricityTolerance(mod);
bind_StepDimTol_DatumFeature(mod);
bind_StepDimTol_HArray1OfDatumReferenceCompartment(mod);
bind_StepDimTol_DatumSystem(mod);
bind_StepDimTol_DatumTarget(mod);
bind_StepDimTol_FlatnessTolerance(mod);
bind_StepDimTol_GeometricToleranceRelationship(mod);
bind_StepDimTol_GeometricToleranceWithDefinedUnit(mod);
bind_StepDimTol_GeometricToleranceWithDefinedAreaUnit(mod);
bind_StepDimTol_HArray1OfGeometricToleranceModifier(mod);
bind_StepDimTol_GeometricToleranceWithModifiers(mod);
bind_StepDimTol_GeometricToleranceWithMaximumTolerance(mod);
bind_StepDimTol_GeoTolAndGeoTolWthDatRef(mod);
bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod(mod);
bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(mod);
bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(mod);
bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol(mod);
bind_StepDimTol_GeoTolAndGeoTolWthMod(mod);
bind_StepDimTol_GeoTolAndGeoTolWthMaxTol(mod);
bind_StepDimTol_HArray1OfDatumReferenceElement(mod);
bind_StepDimTol_HArray1OfToleranceZoneTarget(mod);
bind_StepDimTol_LineProfileTolerance(mod);
bind_StepDimTol_ModifiedGeometricTolerance(mod);
bind_StepDimTol_ToleranceZoneForm(mod);
bind_StepDimTol_ToleranceZone(mod);
bind_StepDimTol_ToleranceZoneDefinition(mod);
bind_StepDimTol_NonUniformZoneDefinition(mod);
bind_StepDimTol_ParallelismTolerance(mod);
bind_StepDimTol_PerpendicularityTolerance(mod);
bind_StepDimTol_PlacedDatumTargetFeature(mod);
bind_StepDimTol_PositionTolerance(mod);
bind_StepDimTol_ProjectedZoneDefinition(mod);
bind_StepDimTol_RoundnessTolerance(mod);
bind_StepDimTol_RunoutZoneOrientation(mod);
bind_StepDimTol_RunoutZoneDefinition(mod);
bind_StepDimTol_ShapeToleranceSelect(mod);
bind_StepDimTol_StraightnessTolerance(mod);
bind_StepDimTol_SurfaceProfileTolerance(mod);
bind_StepDimTol_SymmetryTolerance(mod);
bind_StepDimTol_TotalRunoutTolerance(mod);
bind_StepDimTol_UnequallyDisposedGeometricTolerance(mod);

}
