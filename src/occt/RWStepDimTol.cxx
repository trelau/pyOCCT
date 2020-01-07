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
#include <StepDimTol_AngularityTolerance.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepDimTol_RWAngularityTolerance.hxx>
#include <StepDimTol_CircularRunoutTolerance.hxx>
#include <RWStepDimTol_RWCircularRunoutTolerance.hxx>
#include <StepDimTol_CoaxialityTolerance.hxx>
#include <RWStepDimTol_RWCoaxialityTolerance.hxx>
#include <StepDimTol_CommonDatum.hxx>
#include <RWStepDimTol_RWCommonDatum.hxx>
#include <StepDimTol_ConcentricityTolerance.hxx>
#include <RWStepDimTol_RWConcentricityTolerance.hxx>
#include <StepDimTol_CylindricityTolerance.hxx>
#include <RWStepDimTol_RWCylindricityTolerance.hxx>
#include <StepDimTol_Datum.hxx>
#include <RWStepDimTol_RWDatum.hxx>
#include <StepDimTol_DatumFeature.hxx>
#include <RWStepDimTol_RWDatumFeature.hxx>
#include <StepDimTol_DatumReference.hxx>
#include <RWStepDimTol_RWDatumReference.hxx>
#include <StepDimTol_DatumReferenceCompartment.hxx>
#include <RWStepDimTol_RWDatumReferenceCompartment.hxx>
#include <StepDimTol_DatumReferenceElement.hxx>
#include <RWStepDimTol_RWDatumReferenceElement.hxx>
#include <StepDimTol_DatumReferenceModifierWithValue.hxx>
#include <RWStepDimTol_RWDatumReferenceModifierWithValue.hxx>
#include <StepDimTol_DatumSystem.hxx>
#include <RWStepDimTol_RWDatumSystem.hxx>
#include <StepDimTol_DatumTarget.hxx>
#include <RWStepDimTol_RWDatumTarget.hxx>
#include <StepDimTol_FlatnessTolerance.hxx>
#include <RWStepDimTol_RWFlatnessTolerance.hxx>
#include <StepDimTol_GeneralDatumReference.hxx>
#include <RWStepDimTol_RWGeneralDatumReference.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <RWStepDimTol_RWGeometricTolerance.hxx>
#include <StepDimTol_GeometricToleranceRelationship.hxx>
#include <RWStepDimTol_RWGeometricToleranceRelationship.hxx>
#include <StepDimTol_GeometricToleranceWithDatumReference.hxx>
#include <RWStepDimTol_RWGeometricToleranceWithDatumReference.hxx>
#include <StepDimTol_GeometricToleranceWithDefinedAreaUnit.hxx>
#include <RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.hxx>
#include <StepDimTol_GeometricToleranceWithDefinedUnit.hxx>
#include <RWStepDimTol_RWGeometricToleranceWithDefinedUnit.hxx>
#include <StepDimTol_GeometricToleranceWithMaximumTolerance.hxx>
#include <RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.hxx>
#include <StepDimTol_GeometricToleranceWithModifiers.hxx>
#include <RWStepDimTol_RWGeometricToleranceWithModifiers.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRef.hxx>
#include <RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.hxx>
#include <RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.hxx>
#include <RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.hxx>
#include <RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.hxx>
#include <RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthMaxTol.hxx>
#include <RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthMod.hxx>
#include <RWStepDimTol_RWGeoTolAndGeoTolWthMod.hxx>
#include <StepDimTol_LineProfileTolerance.hxx>
#include <RWStepDimTol_RWLineProfileTolerance.hxx>
#include <StepDimTol_ModifiedGeometricTolerance.hxx>
#include <RWStepDimTol_RWModifiedGeometricTolerance.hxx>
#include <StepDimTol_NonUniformZoneDefinition.hxx>
#include <RWStepDimTol_RWNonUniformZoneDefinition.hxx>
#include <StepDimTol_ParallelismTolerance.hxx>
#include <RWStepDimTol_RWParallelismTolerance.hxx>
#include <StepDimTol_PerpendicularityTolerance.hxx>
#include <RWStepDimTol_RWPerpendicularityTolerance.hxx>
#include <StepDimTol_PlacedDatumTargetFeature.hxx>
#include <RWStepDimTol_RWPlacedDatumTargetFeature.hxx>
#include <StepDimTol_PositionTolerance.hxx>
#include <RWStepDimTol_RWPositionTolerance.hxx>
#include <StepDimTol_ProjectedZoneDefinition.hxx>
#include <RWStepDimTol_RWProjectedZoneDefinition.hxx>
#include <StepDimTol_RoundnessTolerance.hxx>
#include <RWStepDimTol_RWRoundnessTolerance.hxx>
#include <StepDimTol_RunoutZoneDefinition.hxx>
#include <RWStepDimTol_RWRunoutZoneDefinition.hxx>
#include <StepDimTol_RunoutZoneOrientation.hxx>
#include <RWStepDimTol_RWRunoutZoneOrientation.hxx>
#include <StepDimTol_StraightnessTolerance.hxx>
#include <RWStepDimTol_RWStraightnessTolerance.hxx>
#include <StepDimTol_SurfaceProfileTolerance.hxx>
#include <RWStepDimTol_RWSurfaceProfileTolerance.hxx>
#include <StepDimTol_SymmetryTolerance.hxx>
#include <RWStepDimTol_RWSymmetryTolerance.hxx>
#include <StepDimTol_ToleranceZone.hxx>
#include <RWStepDimTol_RWToleranceZone.hxx>
#include <StepDimTol_ToleranceZoneDefinition.hxx>
#include <RWStepDimTol_RWToleranceZoneDefinition.hxx>
#include <StepDimTol_ToleranceZoneForm.hxx>
#include <RWStepDimTol_RWToleranceZoneForm.hxx>
#include <StepDimTol_TotalRunoutTolerance.hxx>
#include <RWStepDimTol_RWTotalRunoutTolerance.hxx>
#include <StepDimTol_UnequallyDisposedGeometricTolerance.hxx>
#include <RWStepDimTol_RWUnequallyDisposedGeometricTolerance.hxx>

PYBIND11_MODULE(RWStepDimTol, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepDimTol");

// CLASS: RWSTEPDIMTOL_RWANGULARITYTOLERANCE
py::class_<RWStepDimTol_RWAngularityTolerance> cls_RWStepDimTol_RWAngularityTolerance(mod, "RWStepDimTol_RWAngularityTolerance", "Read & Write tool for AngularityTolerance");

// Constructors
cls_RWStepDimTol_RWAngularityTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWAngularityTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWAngularityTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWAngularityTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWAngularityTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWAngularityTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWAngularityTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWAngularityTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWAngularityTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWAngularityTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWAngularityTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWAngularityTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWAngularityTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWAngularityTolerance.def("ReadStep", (void (RWStepDimTol_RWAngularityTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_AngularityTolerance> &) const) &RWStepDimTol_RWAngularityTolerance::ReadStep, "Reads AngularityTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWAngularityTolerance.def("WriteStep", (void (RWStepDimTol_RWAngularityTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_AngularityTolerance> &) const) &RWStepDimTol_RWAngularityTolerance::WriteStep, "Writes AngularityTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWAngularityTolerance.def("Share", (void (RWStepDimTol_RWAngularityTolerance::*)(const opencascade::handle<StepDimTol_AngularityTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWAngularityTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWCIRCULARRUNOUTTOLERANCE
py::class_<RWStepDimTol_RWCircularRunoutTolerance> cls_RWStepDimTol_RWCircularRunoutTolerance(mod, "RWStepDimTol_RWCircularRunoutTolerance", "Read & Write tool for CircularRunoutTolerance");

// Constructors
cls_RWStepDimTol_RWCircularRunoutTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWCircularRunoutTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWCircularRunoutTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCircularRunoutTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWCircularRunoutTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCircularRunoutTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWCircularRunoutTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCircularRunoutTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWCircularRunoutTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCircularRunoutTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWCircularRunoutTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWCircularRunoutTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWCircularRunoutTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWCircularRunoutTolerance.def("ReadStep", (void (RWStepDimTol_RWCircularRunoutTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_CircularRunoutTolerance> &) const) &RWStepDimTol_RWCircularRunoutTolerance::ReadStep, "Reads CircularRunoutTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWCircularRunoutTolerance.def("WriteStep", (void (RWStepDimTol_RWCircularRunoutTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_CircularRunoutTolerance> &) const) &RWStepDimTol_RWCircularRunoutTolerance::WriteStep, "Writes CircularRunoutTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWCircularRunoutTolerance.def("Share", (void (RWStepDimTol_RWCircularRunoutTolerance::*)(const opencascade::handle<StepDimTol_CircularRunoutTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWCircularRunoutTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWCOAXIALITYTOLERANCE
py::class_<RWStepDimTol_RWCoaxialityTolerance> cls_RWStepDimTol_RWCoaxialityTolerance(mod, "RWStepDimTol_RWCoaxialityTolerance", "Read & Write tool for CoaxialityTolerance");

// Constructors
cls_RWStepDimTol_RWCoaxialityTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWCoaxialityTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWCoaxialityTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCoaxialityTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWCoaxialityTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCoaxialityTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWCoaxialityTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCoaxialityTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWCoaxialityTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCoaxialityTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWCoaxialityTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWCoaxialityTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWCoaxialityTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWCoaxialityTolerance.def("ReadStep", (void (RWStepDimTol_RWCoaxialityTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_CoaxialityTolerance> &) const) &RWStepDimTol_RWCoaxialityTolerance::ReadStep, "Reads CoaxialityTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWCoaxialityTolerance.def("WriteStep", (void (RWStepDimTol_RWCoaxialityTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_CoaxialityTolerance> &) const) &RWStepDimTol_RWCoaxialityTolerance::WriteStep, "Writes CoaxialityTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWCoaxialityTolerance.def("Share", (void (RWStepDimTol_RWCoaxialityTolerance::*)(const opencascade::handle<StepDimTol_CoaxialityTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWCoaxialityTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWCOMMONDATUM
py::class_<RWStepDimTol_RWCommonDatum> cls_RWStepDimTol_RWCommonDatum(mod, "RWStepDimTol_RWCommonDatum", "Read & Write tool for CommonDatum");

// Constructors
cls_RWStepDimTol_RWCommonDatum.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWCommonDatum.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWCommonDatum::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCommonDatum.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWCommonDatum::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCommonDatum.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWCommonDatum::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCommonDatum.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWCommonDatum::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCommonDatum.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWCommonDatum::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWCommonDatum.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWCommonDatum::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWCommonDatum.def("ReadStep", (void (RWStepDimTol_RWCommonDatum::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_CommonDatum> &) const) &RWStepDimTol_RWCommonDatum::ReadStep, "Reads CommonDatum", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWCommonDatum.def("WriteStep", (void (RWStepDimTol_RWCommonDatum::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_CommonDatum> &) const) &RWStepDimTol_RWCommonDatum::WriteStep, "Writes CommonDatum", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWCommonDatum.def("Share", (void (RWStepDimTol_RWCommonDatum::*)(const opencascade::handle<StepDimTol_CommonDatum> &, Interface_EntityIterator &) const) &RWStepDimTol_RWCommonDatum::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWCONCENTRICITYTOLERANCE
py::class_<RWStepDimTol_RWConcentricityTolerance> cls_RWStepDimTol_RWConcentricityTolerance(mod, "RWStepDimTol_RWConcentricityTolerance", "Read & Write tool for ConcentricityTolerance");

// Constructors
cls_RWStepDimTol_RWConcentricityTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWConcentricityTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWConcentricityTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWConcentricityTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWConcentricityTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWConcentricityTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWConcentricityTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWConcentricityTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWConcentricityTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWConcentricityTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWConcentricityTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWConcentricityTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWConcentricityTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWConcentricityTolerance.def("ReadStep", (void (RWStepDimTol_RWConcentricityTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_ConcentricityTolerance> &) const) &RWStepDimTol_RWConcentricityTolerance::ReadStep, "Reads ConcentricityTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWConcentricityTolerance.def("WriteStep", (void (RWStepDimTol_RWConcentricityTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_ConcentricityTolerance> &) const) &RWStepDimTol_RWConcentricityTolerance::WriteStep, "Writes ConcentricityTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWConcentricityTolerance.def("Share", (void (RWStepDimTol_RWConcentricityTolerance::*)(const opencascade::handle<StepDimTol_ConcentricityTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWConcentricityTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWCYLINDRICITYTOLERANCE
py::class_<RWStepDimTol_RWCylindricityTolerance> cls_RWStepDimTol_RWCylindricityTolerance(mod, "RWStepDimTol_RWCylindricityTolerance", "Read & Write tool for CylindricityTolerance");

// Constructors
cls_RWStepDimTol_RWCylindricityTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWCylindricityTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWCylindricityTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWCylindricityTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWCylindricityTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWCylindricityTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWCylindricityTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWCylindricityTolerance.def("ReadStep", (void (RWStepDimTol_RWCylindricityTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_CylindricityTolerance> &) const) &RWStepDimTol_RWCylindricityTolerance::ReadStep, "Reads CylindricityTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWCylindricityTolerance.def("WriteStep", (void (RWStepDimTol_RWCylindricityTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_CylindricityTolerance> &) const) &RWStepDimTol_RWCylindricityTolerance::WriteStep, "Writes CylindricityTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWCylindricityTolerance.def("Share", (void (RWStepDimTol_RWCylindricityTolerance::*)(const opencascade::handle<StepDimTol_CylindricityTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWCylindricityTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWDATUM
py::class_<RWStepDimTol_RWDatum> cls_RWStepDimTol_RWDatum(mod, "RWStepDimTol_RWDatum", "Read & Write tool for Datum");

// Constructors
cls_RWStepDimTol_RWDatum.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWDatum.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWDatum::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatum.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWDatum::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatum.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWDatum::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatum.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWDatum::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatum.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWDatum::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWDatum.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWDatum::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWDatum.def("ReadStep", (void (RWStepDimTol_RWDatum::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_Datum> &) const) &RWStepDimTol_RWDatum::ReadStep, "Reads Datum", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWDatum.def("WriteStep", (void (RWStepDimTol_RWDatum::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_Datum> &) const) &RWStepDimTol_RWDatum::WriteStep, "Writes Datum", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWDatum.def("Share", (void (RWStepDimTol_RWDatum::*)(const opencascade::handle<StepDimTol_Datum> &, Interface_EntityIterator &) const) &RWStepDimTol_RWDatum::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWDATUMFEATURE
py::class_<RWStepDimTol_RWDatumFeature> cls_RWStepDimTol_RWDatumFeature(mod, "RWStepDimTol_RWDatumFeature", "Read & Write tool for DatumFeature");

// Constructors
cls_RWStepDimTol_RWDatumFeature.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWDatumFeature.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWDatumFeature::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumFeature.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWDatumFeature::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumFeature.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWDatumFeature::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumFeature.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWDatumFeature::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumFeature.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWDatumFeature::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumFeature.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWDatumFeature::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWDatumFeature.def("ReadStep", (void (RWStepDimTol_RWDatumFeature::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_DatumFeature> &) const) &RWStepDimTol_RWDatumFeature::ReadStep, "Reads DatumFeature", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWDatumFeature.def("WriteStep", (void (RWStepDimTol_RWDatumFeature::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_DatumFeature> &) const) &RWStepDimTol_RWDatumFeature::WriteStep, "Writes DatumFeature", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWDatumFeature.def("Share", (void (RWStepDimTol_RWDatumFeature::*)(const opencascade::handle<StepDimTol_DatumFeature> &, Interface_EntityIterator &) const) &RWStepDimTol_RWDatumFeature::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWDATUMREFERENCE
py::class_<RWStepDimTol_RWDatumReference> cls_RWStepDimTol_RWDatumReference(mod, "RWStepDimTol_RWDatumReference", "Read & Write tool for DatumReference");

// Constructors
cls_RWStepDimTol_RWDatumReference.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWDatumReference.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWDatumReference::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumReference.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWDatumReference::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReference.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWDatumReference::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumReference.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWDatumReference::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReference.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWDatumReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReference.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWDatumReference::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWDatumReference.def("ReadStep", (void (RWStepDimTol_RWDatumReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_DatumReference> &) const) &RWStepDimTol_RWDatumReference::ReadStep, "Reads DatumReference", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWDatumReference.def("WriteStep", (void (RWStepDimTol_RWDatumReference::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_DatumReference> &) const) &RWStepDimTol_RWDatumReference::WriteStep, "Writes DatumReference", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWDatumReference.def("Share", (void (RWStepDimTol_RWDatumReference::*)(const opencascade::handle<StepDimTol_DatumReference> &, Interface_EntityIterator &) const) &RWStepDimTol_RWDatumReference::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWDATUMREFERENCECOMPARTMENT
py::class_<RWStepDimTol_RWDatumReferenceCompartment> cls_RWStepDimTol_RWDatumReferenceCompartment(mod, "RWStepDimTol_RWDatumReferenceCompartment", "Read & Write tool for DatumReferenceElement");

// Constructors
cls_RWStepDimTol_RWDatumReferenceCompartment.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWDatumReferenceCompartment.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWDatumReferenceCompartment::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumReferenceCompartment.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWDatumReferenceCompartment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceCompartment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWDatumReferenceCompartment::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumReferenceCompartment.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWDatumReferenceCompartment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceCompartment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWDatumReferenceCompartment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceCompartment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWDatumReferenceCompartment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWDatumReferenceCompartment.def("ReadStep", (void (RWStepDimTol_RWDatumReferenceCompartment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_DatumReferenceCompartment> &) const) &RWStepDimTol_RWDatumReferenceCompartment::ReadStep, "Reads DatumReferenceElement", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWDatumReferenceCompartment.def("WriteStep", (void (RWStepDimTol_RWDatumReferenceCompartment::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_DatumReferenceCompartment> &) const) &RWStepDimTol_RWDatumReferenceCompartment::WriteStep, "Writes DatumReferenceElement", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWDatumReferenceCompartment.def("Share", (void (RWStepDimTol_RWDatumReferenceCompartment::*)(const opencascade::handle<StepDimTol_DatumReferenceCompartment> &, Interface_EntityIterator &) const) &RWStepDimTol_RWDatumReferenceCompartment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWDATUMREFERENCEELEMENT
py::class_<RWStepDimTol_RWDatumReferenceElement> cls_RWStepDimTol_RWDatumReferenceElement(mod, "RWStepDimTol_RWDatumReferenceElement", "Read & Write tool for DatumReferenceElement");

// Constructors
cls_RWStepDimTol_RWDatumReferenceElement.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWDatumReferenceElement.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWDatumReferenceElement::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumReferenceElement.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWDatumReferenceElement::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceElement.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWDatumReferenceElement::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumReferenceElement.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWDatumReferenceElement::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceElement.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWDatumReferenceElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceElement.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWDatumReferenceElement::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWDatumReferenceElement.def("ReadStep", (void (RWStepDimTol_RWDatumReferenceElement::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_DatumReferenceElement> &) const) &RWStepDimTol_RWDatumReferenceElement::ReadStep, "Reads DatumReferenceElement", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWDatumReferenceElement.def("WriteStep", (void (RWStepDimTol_RWDatumReferenceElement::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_DatumReferenceElement> &) const) &RWStepDimTol_RWDatumReferenceElement::WriteStep, "Writes DatumReferenceElement", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWDatumReferenceElement.def("Share", (void (RWStepDimTol_RWDatumReferenceElement::*)(const opencascade::handle<StepDimTol_DatumReferenceElement> &, Interface_EntityIterator &) const) &RWStepDimTol_RWDatumReferenceElement::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWDATUMREFERENCEMODIFIERWITHVALUE
py::class_<RWStepDimTol_RWDatumReferenceModifierWithValue> cls_RWStepDimTol_RWDatumReferenceModifierWithValue(mod, "RWStepDimTol_RWDatumReferenceModifierWithValue", "Read & Write tool for DatumReferenceModifierWithValue");

// Constructors
cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWDatumReferenceModifierWithValue::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWDatumReferenceModifierWithValue::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWDatumReferenceModifierWithValue::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWDatumReferenceModifierWithValue::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWDatumReferenceModifierWithValue::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWDatumReferenceModifierWithValue::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def("ReadStep", (void (RWStepDimTol_RWDatumReferenceModifierWithValue::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_DatumReferenceModifierWithValue> &) const) &RWStepDimTol_RWDatumReferenceModifierWithValue::ReadStep, "Reads DatumReferenceModifierWithValue", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWDatumReferenceModifierWithValue.def("WriteStep", (void (RWStepDimTol_RWDatumReferenceModifierWithValue::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_DatumReferenceModifierWithValue> &) const) &RWStepDimTol_RWDatumReferenceModifierWithValue::WriteStep, "Writes DatumReferenceModifierWithValue", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPDIMTOL_RWDATUMSYSTEM
py::class_<RWStepDimTol_RWDatumSystem> cls_RWStepDimTol_RWDatumSystem(mod, "RWStepDimTol_RWDatumSystem", "Read & Write tool for DatumSystem");

// Constructors
cls_RWStepDimTol_RWDatumSystem.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWDatumSystem.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWDatumSystem::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumSystem.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWDatumSystem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumSystem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWDatumSystem::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumSystem.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWDatumSystem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumSystem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWDatumSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumSystem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWDatumSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWDatumSystem.def("ReadStep", (void (RWStepDimTol_RWDatumSystem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_DatumSystem> &) const) &RWStepDimTol_RWDatumSystem::ReadStep, "Reads DatumSystem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWDatumSystem.def("WriteStep", (void (RWStepDimTol_RWDatumSystem::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_DatumSystem> &) const) &RWStepDimTol_RWDatumSystem::WriteStep, "Writes DatumSystem", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWDatumSystem.def("Share", (void (RWStepDimTol_RWDatumSystem::*)(const opencascade::handle<StepDimTol_DatumSystem> &, Interface_EntityIterator &) const) &RWStepDimTol_RWDatumSystem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWDATUMTARGET
py::class_<RWStepDimTol_RWDatumTarget> cls_RWStepDimTol_RWDatumTarget(mod, "RWStepDimTol_RWDatumTarget", "Read & Write tool for DatumTarget");

// Constructors
cls_RWStepDimTol_RWDatumTarget.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWDatumTarget.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWDatumTarget::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumTarget.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWDatumTarget::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumTarget.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWDatumTarget::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWDatumTarget.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWDatumTarget::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumTarget.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWDatumTarget::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWDatumTarget.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWDatumTarget::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWDatumTarget.def("ReadStep", (void (RWStepDimTol_RWDatumTarget::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_DatumTarget> &) const) &RWStepDimTol_RWDatumTarget::ReadStep, "Reads DatumTarget", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWDatumTarget.def("WriteStep", (void (RWStepDimTol_RWDatumTarget::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_DatumTarget> &) const) &RWStepDimTol_RWDatumTarget::WriteStep, "Writes DatumTarget", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWDatumTarget.def("Share", (void (RWStepDimTol_RWDatumTarget::*)(const opencascade::handle<StepDimTol_DatumTarget> &, Interface_EntityIterator &) const) &RWStepDimTol_RWDatumTarget::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWFLATNESSTOLERANCE
py::class_<RWStepDimTol_RWFlatnessTolerance> cls_RWStepDimTol_RWFlatnessTolerance(mod, "RWStepDimTol_RWFlatnessTolerance", "Read & Write tool for FlatnessTolerance");

// Constructors
cls_RWStepDimTol_RWFlatnessTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWFlatnessTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWFlatnessTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWFlatnessTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWFlatnessTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWFlatnessTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWFlatnessTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWFlatnessTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWFlatnessTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWFlatnessTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWFlatnessTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWFlatnessTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWFlatnessTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWFlatnessTolerance.def("ReadStep", (void (RWStepDimTol_RWFlatnessTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_FlatnessTolerance> &) const) &RWStepDimTol_RWFlatnessTolerance::ReadStep, "Reads FlatnessTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWFlatnessTolerance.def("WriteStep", (void (RWStepDimTol_RWFlatnessTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_FlatnessTolerance> &) const) &RWStepDimTol_RWFlatnessTolerance::WriteStep, "Writes FlatnessTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWFlatnessTolerance.def("Share", (void (RWStepDimTol_RWFlatnessTolerance::*)(const opencascade::handle<StepDimTol_FlatnessTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWFlatnessTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGENERALDATUMREFERENCE
py::class_<RWStepDimTol_RWGeneralDatumReference> cls_RWStepDimTol_RWGeneralDatumReference(mod, "RWStepDimTol_RWGeneralDatumReference", "Read & Write tool for GeneralDatumReference");

// Constructors
cls_RWStepDimTol_RWGeneralDatumReference.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeneralDatumReference.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeneralDatumReference::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeneralDatumReference.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeneralDatumReference::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeneralDatumReference.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeneralDatumReference::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeneralDatumReference.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeneralDatumReference::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeneralDatumReference.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeneralDatumReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeneralDatumReference.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeneralDatumReference::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeneralDatumReference.def("ReadStep", (void (RWStepDimTol_RWGeneralDatumReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeneralDatumReference> &) const) &RWStepDimTol_RWGeneralDatumReference::ReadStep, "Reads GeneralDatumReference", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeneralDatumReference.def("WriteStep", (void (RWStepDimTol_RWGeneralDatumReference::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeneralDatumReference> &) const) &RWStepDimTol_RWGeneralDatumReference::WriteStep, "Writes GeneralDatumReference", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeneralDatumReference.def("Share", (void (RWStepDimTol_RWGeneralDatumReference::*)(const opencascade::handle<StepDimTol_GeneralDatumReference> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeneralDatumReference::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOMETRICTOLERANCE
py::class_<RWStepDimTol_RWGeometricTolerance> cls_RWStepDimTol_RWGeometricTolerance(mod, "RWStepDimTol_RWGeometricTolerance", "Read & Write tool for GeometricTolerance");

// Constructors
cls_RWStepDimTol_RWGeometricTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeometricTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeometricTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeometricTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeometricTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeometricTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeometricTolerance.def("ReadStep", (void (RWStepDimTol_RWGeometricTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeometricTolerance> &) const) &RWStepDimTol_RWGeometricTolerance::ReadStep, "Reads GeometricTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricTolerance.def("WriteStep", (void (RWStepDimTol_RWGeometricTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeometricTolerance> &) const) &RWStepDimTol_RWGeometricTolerance::WriteStep, "Writes GeometricTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricTolerance.def("Share", (void (RWStepDimTol_RWGeometricTolerance::*)(const opencascade::handle<StepDimTol_GeometricTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeometricTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOMETRICTOLERANCERELATIONSHIP
py::class_<RWStepDimTol_RWGeometricToleranceRelationship> cls_RWStepDimTol_RWGeometricToleranceRelationship(mod, "RWStepDimTol_RWGeometricToleranceRelationship", "Read & Write tool for GeometricToleranceRelationship");

// Constructors
cls_RWStepDimTol_RWGeometricToleranceRelationship.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeometricToleranceRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeometricToleranceRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeometricToleranceRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeometricToleranceRelationship.def("ReadStep", (void (RWStepDimTol_RWGeometricToleranceRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeometricToleranceRelationship> &) const) &RWStepDimTol_RWGeometricToleranceRelationship::ReadStep, "Reads GeometricToleranceRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceRelationship.def("WriteStep", (void (RWStepDimTol_RWGeometricToleranceRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeometricToleranceRelationship> &) const) &RWStepDimTol_RWGeometricToleranceRelationship::WriteStep, "Writes GeometricToleranceRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceRelationship.def("Share", (void (RWStepDimTol_RWGeometricToleranceRelationship::*)(const opencascade::handle<StepDimTol_GeometricToleranceRelationship> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeometricToleranceRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOMETRICTOLERANCEWITHDATUMREFERENCE
py::class_<RWStepDimTol_RWGeometricToleranceWithDatumReference> cls_RWStepDimTol_RWGeometricToleranceWithDatumReference(mod, "RWStepDimTol_RWGeometricToleranceWithDatumReference", "Read & Write tool for GeometricToleranceWithDatumReference");

// Constructors
cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithDatumReference::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithDatumReference::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithDatumReference::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithDatumReference::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeometricToleranceWithDatumReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeometricToleranceWithDatumReference::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def("ReadStep", (void (RWStepDimTol_RWGeometricToleranceWithDatumReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &) const) &RWStepDimTol_RWGeometricToleranceWithDatumReference::ReadStep, "Reads GeometricToleranceWithDatumReference", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def("WriteStep", (void (RWStepDimTol_RWGeometricToleranceWithDatumReference::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &) const) &RWStepDimTol_RWGeometricToleranceWithDatumReference::WriteStep, "Writes GeometricToleranceWithDatumReference", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithDatumReference.def("Share", (void (RWStepDimTol_RWGeometricToleranceWithDatumReference::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeometricToleranceWithDatumReference::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOMETRICTOLERANCEWITHDEFINEDAREAUNIT
py::class_<RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit> cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit(mod, "RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit", "Read & Write tool for GeometricToleranceWithDefinedAreaUnit");

// Constructors
cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def("ReadStep", (void (RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDefinedAreaUnit> &) const) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::ReadStep, "Reads GeometricToleranceWithDefinedAreaUnit", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def("WriteStep", (void (RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeometricToleranceWithDefinedAreaUnit> &) const) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::WriteStep, "Writes GeometricToleranceWithDefinedAreaUnit", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit.def("Share", (void (RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDefinedAreaUnit> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeometricToleranceWithDefinedAreaUnit::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOMETRICTOLERANCEWITHDEFINEDUNIT
py::class_<RWStepDimTol_RWGeometricToleranceWithDefinedUnit> cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit(mod, "RWStepDimTol_RWGeometricToleranceWithDefinedUnit", "Read & Write tool for GeometricToleranceWithDefinedUnit");

// Constructors
cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def("ReadStep", (void (RWStepDimTol_RWGeometricToleranceWithDefinedUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDefinedUnit> &) const) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::ReadStep, "Reads GeometricToleranceWithDefinedUnit", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def("WriteStep", (void (RWStepDimTol_RWGeometricToleranceWithDefinedUnit::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeometricToleranceWithDefinedUnit> &) const) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::WriteStep, "Writes GeometricToleranceWithDefinedUnit", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithDefinedUnit.def("Share", (void (RWStepDimTol_RWGeometricToleranceWithDefinedUnit::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDefinedUnit> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeometricToleranceWithDefinedUnit::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOMETRICTOLERANCEWITHMAXIMUMTOLERANCE
py::class_<RWStepDimTol_RWGeometricToleranceWithMaximumTolerance> cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance(mod, "RWStepDimTol_RWGeometricToleranceWithMaximumTolerance", "Read & Write tool for GeometricToleranceWithMaximumTolerance");

// Constructors
cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def("ReadStep", (void (RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeometricToleranceWithMaximumTolerance> &) const) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::ReadStep, "Reads GeometricToleranceWithMaximumTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def("WriteStep", (void (RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeometricToleranceWithMaximumTolerance> &) const) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::WriteStep, "Writes GeometricToleranceWithMaximumTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithMaximumTolerance.def("Share", (void (RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithMaximumTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeometricToleranceWithMaximumTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOMETRICTOLERANCEWITHMODIFIERS
py::class_<RWStepDimTol_RWGeometricToleranceWithModifiers> cls_RWStepDimTol_RWGeometricToleranceWithModifiers(mod, "RWStepDimTol_RWGeometricToleranceWithModifiers", "Read & Write tool for GeometricToleranceWithModifiers");

// Constructors
cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithModifiers::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithModifiers::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeometricToleranceWithModifiers::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeometricToleranceWithModifiers::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeometricToleranceWithModifiers::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeometricToleranceWithModifiers::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def("ReadStep", (void (RWStepDimTol_RWGeometricToleranceWithModifiers::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &) const) &RWStepDimTol_RWGeometricToleranceWithModifiers::ReadStep, "Reads GeometricToleranceWithModifiers", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def("WriteStep", (void (RWStepDimTol_RWGeometricToleranceWithModifiers::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &) const) &RWStepDimTol_RWGeometricToleranceWithModifiers::WriteStep, "Writes GeometricToleranceWithModifiers", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeometricToleranceWithModifiers.def("Share", (void (RWStepDimTol_RWGeometricToleranceWithModifiers::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeometricToleranceWithModifiers::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOTOLANDGEOTOLWTHDATREF
py::class_<RWStepDimTol_RWGeoTolAndGeoTolWthDatRef> cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef(mod, "RWStepDimTol_RWGeoTolAndGeoTolWthDatRef", "Read & Write Module for GeoTolAndGeoTolWthDatRef");

// Constructors
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def("ReadStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRef> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def("WriteStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRef> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRef.def("Share", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::*)(const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRef> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRef::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOTOLANDGEOTOLWTHDATREFANDGEOTOLWTHMAXTOL
py::class_<RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol> cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(mod, "RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol", "Read & Write Module for GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol");

// Constructors
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("ReadStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("WriteStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("Share", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOTOLANDGEOTOLWTHDATREFANDGEOTOLWTHMOD
py::class_<RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod> cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod(mod, "RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod", "Read & Write Module for GeoTolAndGeoTolWthDatRefAndGeoTolWthMod");

// Constructors
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("ReadStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("WriteStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("Share", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOTOLANDGEOTOLWTHDATREFANDMODGEOTOLANDPOSTOL
py::class_<RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol> cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(mod, "RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol", "Read & Write Module for ReprItemAndLengthMeasureWithUni");

// Constructors
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("ReadStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("WriteStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("Share", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOTOLANDGEOTOLWTHDATREFANDUNEQDISGEOTOL
py::class_<RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol> cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol(mod, "RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol", "Read & Write Module for GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol");

// Constructors
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("ReadStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("WriteStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("Share", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOTOLANDGEOTOLWTHMAXTOL
py::class_<RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol> cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol(mod, "RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol", "Read & Write Module for GeoTolAndGeoTolWthMaxTol");

// Constructors
cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def("ReadStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMaxTol> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def("WriteStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMaxTol> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol.def("Share", (void (RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::*)(const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMaxTol> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthMaxTol::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWGEOTOLANDGEOTOLWTHMOD
py::class_<RWStepDimTol_RWGeoTolAndGeoTolWthMod> cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod(mod, "RWStepDimTol_RWGeoTolAndGeoTolWthMod", "Read & Write Module for GeoTolAndGeoTolWthMod");

// Constructors
cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def("ReadStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthMod::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMod> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def("WriteStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthMod::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMod> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthMod.def("Share", (void (RWStepDimTol_RWGeoTolAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMod> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthMod::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWLINEPROFILETOLERANCE
py::class_<RWStepDimTol_RWLineProfileTolerance> cls_RWStepDimTol_RWLineProfileTolerance(mod, "RWStepDimTol_RWLineProfileTolerance", "Read & Write tool for LineProfileTolerance");

// Constructors
cls_RWStepDimTol_RWLineProfileTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWLineProfileTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWLineProfileTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWLineProfileTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWLineProfileTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWLineProfileTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWLineProfileTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWLineProfileTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWLineProfileTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWLineProfileTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWLineProfileTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWLineProfileTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWLineProfileTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWLineProfileTolerance.def("ReadStep", (void (RWStepDimTol_RWLineProfileTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_LineProfileTolerance> &) const) &RWStepDimTol_RWLineProfileTolerance::ReadStep, "Reads LineProfileTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWLineProfileTolerance.def("WriteStep", (void (RWStepDimTol_RWLineProfileTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_LineProfileTolerance> &) const) &RWStepDimTol_RWLineProfileTolerance::WriteStep, "Writes LineProfileTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWLineProfileTolerance.def("Share", (void (RWStepDimTol_RWLineProfileTolerance::*)(const opencascade::handle<StepDimTol_LineProfileTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWLineProfileTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWMODIFIEDGEOMETRICTOLERANCE
py::class_<RWStepDimTol_RWModifiedGeometricTolerance> cls_RWStepDimTol_RWModifiedGeometricTolerance(mod, "RWStepDimTol_RWModifiedGeometricTolerance", "Read & Write tool for ModifiedGeometricTolerance");

// Constructors
cls_RWStepDimTol_RWModifiedGeometricTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWModifiedGeometricTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWModifiedGeometricTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWModifiedGeometricTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWModifiedGeometricTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWModifiedGeometricTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWModifiedGeometricTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWModifiedGeometricTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWModifiedGeometricTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWModifiedGeometricTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWModifiedGeometricTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWModifiedGeometricTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWModifiedGeometricTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWModifiedGeometricTolerance.def("ReadStep", (void (RWStepDimTol_RWModifiedGeometricTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &) const) &RWStepDimTol_RWModifiedGeometricTolerance::ReadStep, "Reads ModifiedGeometricTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWModifiedGeometricTolerance.def("WriteStep", (void (RWStepDimTol_RWModifiedGeometricTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &) const) &RWStepDimTol_RWModifiedGeometricTolerance::WriteStep, "Writes ModifiedGeometricTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWModifiedGeometricTolerance.def("Share", (void (RWStepDimTol_RWModifiedGeometricTolerance::*)(const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWModifiedGeometricTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWNONUNIFORMZONEDEFINITION
py::class_<RWStepDimTol_RWNonUniformZoneDefinition> cls_RWStepDimTol_RWNonUniformZoneDefinition(mod, "RWStepDimTol_RWNonUniformZoneDefinition", "Read & Write tool for NonUniformZoneDefinition");

// Constructors
cls_RWStepDimTol_RWNonUniformZoneDefinition.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWNonUniformZoneDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWNonUniformZoneDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWNonUniformZoneDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWNonUniformZoneDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWNonUniformZoneDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWNonUniformZoneDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWNonUniformZoneDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWNonUniformZoneDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWNonUniformZoneDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWNonUniformZoneDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWNonUniformZoneDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWNonUniformZoneDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWNonUniformZoneDefinition.def("ReadStep", (void (RWStepDimTol_RWNonUniformZoneDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_NonUniformZoneDefinition> &) const) &RWStepDimTol_RWNonUniformZoneDefinition::ReadStep, "Reads NonUniformZoneDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWNonUniformZoneDefinition.def("WriteStep", (void (RWStepDimTol_RWNonUniformZoneDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_NonUniformZoneDefinition> &) const) &RWStepDimTol_RWNonUniformZoneDefinition::WriteStep, "Writes NonUniformZoneDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWNonUniformZoneDefinition.def("Share", (void (RWStepDimTol_RWNonUniformZoneDefinition::*)(const opencascade::handle<StepDimTol_NonUniformZoneDefinition> &, Interface_EntityIterator &) const) &RWStepDimTol_RWNonUniformZoneDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWPARALLELISMTOLERANCE
py::class_<RWStepDimTol_RWParallelismTolerance> cls_RWStepDimTol_RWParallelismTolerance(mod, "RWStepDimTol_RWParallelismTolerance", "Read & Write tool for ParallelismTolerance");

// Constructors
cls_RWStepDimTol_RWParallelismTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWParallelismTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWParallelismTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWParallelismTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWParallelismTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWParallelismTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWParallelismTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWParallelismTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWParallelismTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWParallelismTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWParallelismTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWParallelismTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWParallelismTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWParallelismTolerance.def("ReadStep", (void (RWStepDimTol_RWParallelismTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_ParallelismTolerance> &) const) &RWStepDimTol_RWParallelismTolerance::ReadStep, "Reads ParallelismTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWParallelismTolerance.def("WriteStep", (void (RWStepDimTol_RWParallelismTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_ParallelismTolerance> &) const) &RWStepDimTol_RWParallelismTolerance::WriteStep, "Writes ParallelismTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWParallelismTolerance.def("Share", (void (RWStepDimTol_RWParallelismTolerance::*)(const opencascade::handle<StepDimTol_ParallelismTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWParallelismTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWPERPENDICULARITYTOLERANCE
py::class_<RWStepDimTol_RWPerpendicularityTolerance> cls_RWStepDimTol_RWPerpendicularityTolerance(mod, "RWStepDimTol_RWPerpendicularityTolerance", "Read & Write tool for PerpendicularityTolerance");

// Constructors
cls_RWStepDimTol_RWPerpendicularityTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWPerpendicularityTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWPerpendicularityTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWPerpendicularityTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWPerpendicularityTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWPerpendicularityTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWPerpendicularityTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWPerpendicularityTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWPerpendicularityTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWPerpendicularityTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWPerpendicularityTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWPerpendicularityTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWPerpendicularityTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWPerpendicularityTolerance.def("ReadStep", (void (RWStepDimTol_RWPerpendicularityTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_PerpendicularityTolerance> &) const) &RWStepDimTol_RWPerpendicularityTolerance::ReadStep, "Reads PerpendicularityTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWPerpendicularityTolerance.def("WriteStep", (void (RWStepDimTol_RWPerpendicularityTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_PerpendicularityTolerance> &) const) &RWStepDimTol_RWPerpendicularityTolerance::WriteStep, "Writes PerpendicularityTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWPerpendicularityTolerance.def("Share", (void (RWStepDimTol_RWPerpendicularityTolerance::*)(const opencascade::handle<StepDimTol_PerpendicularityTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWPerpendicularityTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWPLACEDDATUMTARGETFEATURE
py::class_<RWStepDimTol_RWPlacedDatumTargetFeature> cls_RWStepDimTol_RWPlacedDatumTargetFeature(mod, "RWStepDimTol_RWPlacedDatumTargetFeature", "Read & Write tool for PlacedDatumTargetFeature");

// Constructors
cls_RWStepDimTol_RWPlacedDatumTargetFeature.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWPlacedDatumTargetFeature.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWPlacedDatumTargetFeature::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWPlacedDatumTargetFeature.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWPlacedDatumTargetFeature::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWPlacedDatumTargetFeature.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWPlacedDatumTargetFeature::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWPlacedDatumTargetFeature.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWPlacedDatumTargetFeature::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWPlacedDatumTargetFeature.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWPlacedDatumTargetFeature::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWPlacedDatumTargetFeature.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWPlacedDatumTargetFeature::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWPlacedDatumTargetFeature.def("ReadStep", (void (RWStepDimTol_RWPlacedDatumTargetFeature::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_PlacedDatumTargetFeature> &) const) &RWStepDimTol_RWPlacedDatumTargetFeature::ReadStep, "Reads PlacedDatumTargetFeature", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWPlacedDatumTargetFeature.def("WriteStep", (void (RWStepDimTol_RWPlacedDatumTargetFeature::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_PlacedDatumTargetFeature> &) const) &RWStepDimTol_RWPlacedDatumTargetFeature::WriteStep, "Writes PlacedDatumTargetFeature", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWPlacedDatumTargetFeature.def("Share", (void (RWStepDimTol_RWPlacedDatumTargetFeature::*)(const opencascade::handle<StepDimTol_PlacedDatumTargetFeature> &, Interface_EntityIterator &) const) &RWStepDimTol_RWPlacedDatumTargetFeature::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWPOSITIONTOLERANCE
py::class_<RWStepDimTol_RWPositionTolerance> cls_RWStepDimTol_RWPositionTolerance(mod, "RWStepDimTol_RWPositionTolerance", "Read & Write tool for PositionTolerance");

// Constructors
cls_RWStepDimTol_RWPositionTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWPositionTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWPositionTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWPositionTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWPositionTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWPositionTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWPositionTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWPositionTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWPositionTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWPositionTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWPositionTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWPositionTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWPositionTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWPositionTolerance.def("ReadStep", (void (RWStepDimTol_RWPositionTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_PositionTolerance> &) const) &RWStepDimTol_RWPositionTolerance::ReadStep, "Reads PositionTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWPositionTolerance.def("WriteStep", (void (RWStepDimTol_RWPositionTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_PositionTolerance> &) const) &RWStepDimTol_RWPositionTolerance::WriteStep, "Writes PositionTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWPositionTolerance.def("Share", (void (RWStepDimTol_RWPositionTolerance::*)(const opencascade::handle<StepDimTol_PositionTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWPositionTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWPROJECTEDZONEDEFINITION
py::class_<RWStepDimTol_RWProjectedZoneDefinition> cls_RWStepDimTol_RWProjectedZoneDefinition(mod, "RWStepDimTol_RWProjectedZoneDefinition", "Read & Write tool for ProjectedZoneDefinition");

// Constructors
cls_RWStepDimTol_RWProjectedZoneDefinition.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWProjectedZoneDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWProjectedZoneDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWProjectedZoneDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWProjectedZoneDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWProjectedZoneDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWProjectedZoneDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWProjectedZoneDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWProjectedZoneDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWProjectedZoneDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWProjectedZoneDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWProjectedZoneDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWProjectedZoneDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWProjectedZoneDefinition.def("ReadStep", (void (RWStepDimTol_RWProjectedZoneDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_ProjectedZoneDefinition> &) const) &RWStepDimTol_RWProjectedZoneDefinition::ReadStep, "Reads ProjectedZoneDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWProjectedZoneDefinition.def("WriteStep", (void (RWStepDimTol_RWProjectedZoneDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_ProjectedZoneDefinition> &) const) &RWStepDimTol_RWProjectedZoneDefinition::WriteStep, "Writes ProjectedZoneDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWProjectedZoneDefinition.def("Share", (void (RWStepDimTol_RWProjectedZoneDefinition::*)(const opencascade::handle<StepDimTol_ProjectedZoneDefinition> &, Interface_EntityIterator &) const) &RWStepDimTol_RWProjectedZoneDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWROUNDNESSTOLERANCE
py::class_<RWStepDimTol_RWRoundnessTolerance> cls_RWStepDimTol_RWRoundnessTolerance(mod, "RWStepDimTol_RWRoundnessTolerance", "Read & Write tool for RoundnessTolerance");

// Constructors
cls_RWStepDimTol_RWRoundnessTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWRoundnessTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWRoundnessTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWRoundnessTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWRoundnessTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWRoundnessTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWRoundnessTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWRoundnessTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWRoundnessTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWRoundnessTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWRoundnessTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWRoundnessTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWRoundnessTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWRoundnessTolerance.def("ReadStep", (void (RWStepDimTol_RWRoundnessTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_RoundnessTolerance> &) const) &RWStepDimTol_RWRoundnessTolerance::ReadStep, "Reads RoundnessTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWRoundnessTolerance.def("WriteStep", (void (RWStepDimTol_RWRoundnessTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_RoundnessTolerance> &) const) &RWStepDimTol_RWRoundnessTolerance::WriteStep, "Writes RoundnessTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWRoundnessTolerance.def("Share", (void (RWStepDimTol_RWRoundnessTolerance::*)(const opencascade::handle<StepDimTol_RoundnessTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWRoundnessTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWRUNOUTZONEDEFINITION
py::class_<RWStepDimTol_RWRunoutZoneDefinition> cls_RWStepDimTol_RWRunoutZoneDefinition(mod, "RWStepDimTol_RWRunoutZoneDefinition", "Read & Write tool for RunoutZoneDefinition");

// Constructors
cls_RWStepDimTol_RWRunoutZoneDefinition.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWRunoutZoneDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWRunoutZoneDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWRunoutZoneDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWRunoutZoneDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWRunoutZoneDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWRunoutZoneDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWRunoutZoneDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWRunoutZoneDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWRunoutZoneDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWRunoutZoneDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWRunoutZoneDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWRunoutZoneDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWRunoutZoneDefinition.def("ReadStep", (void (RWStepDimTol_RWRunoutZoneDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_RunoutZoneDefinition> &) const) &RWStepDimTol_RWRunoutZoneDefinition::ReadStep, "Reads RunoutZoneDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWRunoutZoneDefinition.def("WriteStep", (void (RWStepDimTol_RWRunoutZoneDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_RunoutZoneDefinition> &) const) &RWStepDimTol_RWRunoutZoneDefinition::WriteStep, "Writes RunoutZoneDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWRunoutZoneDefinition.def("Share", (void (RWStepDimTol_RWRunoutZoneDefinition::*)(const opencascade::handle<StepDimTol_RunoutZoneDefinition> &, Interface_EntityIterator &) const) &RWStepDimTol_RWRunoutZoneDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWRUNOUTZONEORIENTATION
py::class_<RWStepDimTol_RWRunoutZoneOrientation> cls_RWStepDimTol_RWRunoutZoneOrientation(mod, "RWStepDimTol_RWRunoutZoneOrientation", "Read & Write tool for RunoutZoneOrientation");

// Constructors
cls_RWStepDimTol_RWRunoutZoneOrientation.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWRunoutZoneOrientation.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWRunoutZoneOrientation::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWRunoutZoneOrientation.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWRunoutZoneOrientation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWRunoutZoneOrientation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWRunoutZoneOrientation::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWRunoutZoneOrientation.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWRunoutZoneOrientation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWRunoutZoneOrientation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWRunoutZoneOrientation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWRunoutZoneOrientation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWRunoutZoneOrientation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWRunoutZoneOrientation.def("ReadStep", (void (RWStepDimTol_RWRunoutZoneOrientation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_RunoutZoneOrientation> &) const) &RWStepDimTol_RWRunoutZoneOrientation::ReadStep, "Reads RunoutZoneOrientation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWRunoutZoneOrientation.def("WriteStep", (void (RWStepDimTol_RWRunoutZoneOrientation::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_RunoutZoneOrientation> &) const) &RWStepDimTol_RWRunoutZoneOrientation::WriteStep, "Writes RunoutZoneOrientation", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPDIMTOL_RWSTRAIGHTNESSTOLERANCE
py::class_<RWStepDimTol_RWStraightnessTolerance> cls_RWStepDimTol_RWStraightnessTolerance(mod, "RWStepDimTol_RWStraightnessTolerance", "Read & Write tool for StraightnessTolerance");

// Constructors
cls_RWStepDimTol_RWStraightnessTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWStraightnessTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWStraightnessTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWStraightnessTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWStraightnessTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWStraightnessTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWStraightnessTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWStraightnessTolerance.def("ReadStep", (void (RWStepDimTol_RWStraightnessTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_StraightnessTolerance> &) const) &RWStepDimTol_RWStraightnessTolerance::ReadStep, "Reads StraightnessTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWStraightnessTolerance.def("WriteStep", (void (RWStepDimTol_RWStraightnessTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_StraightnessTolerance> &) const) &RWStepDimTol_RWStraightnessTolerance::WriteStep, "Writes StraightnessTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWStraightnessTolerance.def("Share", (void (RWStepDimTol_RWStraightnessTolerance::*)(const opencascade::handle<StepDimTol_StraightnessTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWStraightnessTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWSURFACEPROFILETOLERANCE
py::class_<RWStepDimTol_RWSurfaceProfileTolerance> cls_RWStepDimTol_RWSurfaceProfileTolerance(mod, "RWStepDimTol_RWSurfaceProfileTolerance", "Read & Write tool for SurfaceProfileTolerance");

// Constructors
cls_RWStepDimTol_RWSurfaceProfileTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWSurfaceProfileTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWSurfaceProfileTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWSurfaceProfileTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWSurfaceProfileTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWSurfaceProfileTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWSurfaceProfileTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWSurfaceProfileTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWSurfaceProfileTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWSurfaceProfileTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWSurfaceProfileTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWSurfaceProfileTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWSurfaceProfileTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWSurfaceProfileTolerance.def("ReadStep", (void (RWStepDimTol_RWSurfaceProfileTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_SurfaceProfileTolerance> &) const) &RWStepDimTol_RWSurfaceProfileTolerance::ReadStep, "Reads SurfaceProfileTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWSurfaceProfileTolerance.def("WriteStep", (void (RWStepDimTol_RWSurfaceProfileTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_SurfaceProfileTolerance> &) const) &RWStepDimTol_RWSurfaceProfileTolerance::WriteStep, "Writes SurfaceProfileTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWSurfaceProfileTolerance.def("Share", (void (RWStepDimTol_RWSurfaceProfileTolerance::*)(const opencascade::handle<StepDimTol_SurfaceProfileTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWSurfaceProfileTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWSYMMETRYTOLERANCE
py::class_<RWStepDimTol_RWSymmetryTolerance> cls_RWStepDimTol_RWSymmetryTolerance(mod, "RWStepDimTol_RWSymmetryTolerance", "Read & Write tool for SymmetryTolerance");

// Constructors
cls_RWStepDimTol_RWSymmetryTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWSymmetryTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWSymmetryTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWSymmetryTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWSymmetryTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWSymmetryTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWSymmetryTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWSymmetryTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWSymmetryTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWSymmetryTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWSymmetryTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWSymmetryTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWSymmetryTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWSymmetryTolerance.def("ReadStep", (void (RWStepDimTol_RWSymmetryTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_SymmetryTolerance> &) const) &RWStepDimTol_RWSymmetryTolerance::ReadStep, "Reads SymmetryTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWSymmetryTolerance.def("WriteStep", (void (RWStepDimTol_RWSymmetryTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_SymmetryTolerance> &) const) &RWStepDimTol_RWSymmetryTolerance::WriteStep, "Writes SymmetryTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWSymmetryTolerance.def("Share", (void (RWStepDimTol_RWSymmetryTolerance::*)(const opencascade::handle<StepDimTol_SymmetryTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWSymmetryTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWTOLERANCEZONE
py::class_<RWStepDimTol_RWToleranceZone> cls_RWStepDimTol_RWToleranceZone(mod, "RWStepDimTol_RWToleranceZone", "Read & Write tool for ToleranceZone");

// Constructors
cls_RWStepDimTol_RWToleranceZone.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWToleranceZone.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWToleranceZone::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWToleranceZone.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWToleranceZone::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZone.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWToleranceZone::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWToleranceZone.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWToleranceZone::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZone.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWToleranceZone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZone.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWToleranceZone::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWToleranceZone.def("ReadStep", (void (RWStepDimTol_RWToleranceZone::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_ToleranceZone> &) const) &RWStepDimTol_RWToleranceZone::ReadStep, "Reads ToleranceZone", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWToleranceZone.def("WriteStep", (void (RWStepDimTol_RWToleranceZone::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_ToleranceZone> &) const) &RWStepDimTol_RWToleranceZone::WriteStep, "Writes ToleranceZone", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWToleranceZone.def("Share", (void (RWStepDimTol_RWToleranceZone::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, Interface_EntityIterator &) const) &RWStepDimTol_RWToleranceZone::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWTOLERANCEZONEDEFINITION
py::class_<RWStepDimTol_RWToleranceZoneDefinition> cls_RWStepDimTol_RWToleranceZoneDefinition(mod, "RWStepDimTol_RWToleranceZoneDefinition", "Read & Write tool for ToleranceZoneDefinition");

// Constructors
cls_RWStepDimTol_RWToleranceZoneDefinition.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWToleranceZoneDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWToleranceZoneDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWToleranceZoneDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWToleranceZoneDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWToleranceZoneDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWToleranceZoneDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWToleranceZoneDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWToleranceZoneDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWToleranceZoneDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWToleranceZoneDefinition.def("ReadStep", (void (RWStepDimTol_RWToleranceZoneDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_ToleranceZoneDefinition> &) const) &RWStepDimTol_RWToleranceZoneDefinition::ReadStep, "Reads ToleranceZoneDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWToleranceZoneDefinition.def("WriteStep", (void (RWStepDimTol_RWToleranceZoneDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_ToleranceZoneDefinition> &) const) &RWStepDimTol_RWToleranceZoneDefinition::WriteStep, "Writes ToleranceZoneDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWToleranceZoneDefinition.def("Share", (void (RWStepDimTol_RWToleranceZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZoneDefinition> &, Interface_EntityIterator &) const) &RWStepDimTol_RWToleranceZoneDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWTOLERANCEZONEFORM
py::class_<RWStepDimTol_RWToleranceZoneForm> cls_RWStepDimTol_RWToleranceZoneForm(mod, "RWStepDimTol_RWToleranceZoneForm", "Read & Write tool for ToleranceZoneForm");

// Constructors
cls_RWStepDimTol_RWToleranceZoneForm.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWToleranceZoneForm::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWToleranceZoneForm::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWToleranceZoneForm::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWToleranceZoneForm::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWToleranceZoneForm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWToleranceZoneForm::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWToleranceZoneForm.def("ReadStep", (void (RWStepDimTol_RWToleranceZoneForm::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_ToleranceZoneForm> &) const) &RWStepDimTol_RWToleranceZoneForm::ReadStep, "Reads ToleranceZoneForm", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWToleranceZoneForm.def("WriteStep", (void (RWStepDimTol_RWToleranceZoneForm::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_ToleranceZoneForm> &) const) &RWStepDimTol_RWToleranceZoneForm::WriteStep, "Writes ToleranceZoneForm", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPDIMTOL_RWTOTALRUNOUTTOLERANCE
py::class_<RWStepDimTol_RWTotalRunoutTolerance> cls_RWStepDimTol_RWTotalRunoutTolerance(mod, "RWStepDimTol_RWTotalRunoutTolerance", "Read & Write tool for TotalRunoutTolerance");

// Constructors
cls_RWStepDimTol_RWTotalRunoutTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWTotalRunoutTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWTotalRunoutTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWTotalRunoutTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWTotalRunoutTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWTotalRunoutTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWTotalRunoutTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWTotalRunoutTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWTotalRunoutTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWTotalRunoutTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWTotalRunoutTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWTotalRunoutTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWTotalRunoutTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWTotalRunoutTolerance.def("ReadStep", (void (RWStepDimTol_RWTotalRunoutTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_TotalRunoutTolerance> &) const) &RWStepDimTol_RWTotalRunoutTolerance::ReadStep, "Reads TotalRunoutTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWTotalRunoutTolerance.def("WriteStep", (void (RWStepDimTol_RWTotalRunoutTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_TotalRunoutTolerance> &) const) &RWStepDimTol_RWTotalRunoutTolerance::WriteStep, "Writes TotalRunoutTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWTotalRunoutTolerance.def("Share", (void (RWStepDimTol_RWTotalRunoutTolerance::*)(const opencascade::handle<StepDimTol_TotalRunoutTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWTotalRunoutTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPDIMTOL_RWUNEQUALLYDISPOSEDGEOMETRICTOLERANCE
py::class_<RWStepDimTol_RWUnequallyDisposedGeometricTolerance> cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance(mod, "RWStepDimTol_RWUnequallyDisposedGeometricTolerance", "Read & Write tool for UnequallyDisposedGeometricTolerance");

// Constructors
cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def(py::init<>());

// Methods
// cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def("ReadStep", (void (RWStepDimTol_RWUnequallyDisposedGeometricTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &) const) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::ReadStep, "Reads UnequallyDisposedGeometricTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def("WriteStep", (void (RWStepDimTol_RWUnequallyDisposedGeometricTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &) const) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::WriteStep, "Writes UnequallyDisposedGeometricTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWUnequallyDisposedGeometricTolerance.def("Share", (void (RWStepDimTol_RWUnequallyDisposedGeometricTolerance::*)(const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWUnequallyDisposedGeometricTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));


}
