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
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_GeometricToleranceWithDatumReference.hxx>
#include <StepDimTol_GeometricToleranceWithModifiers.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepDimTol_GeometricToleranceType.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(py::module &mod){

py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol>, StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theGTWM"), py::arg("theMaxTol"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aGTWM"), py::arg("theMaxTol"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("SetMaxTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::SetMaxTolerance, "None", py::arg("theMaxTol"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("GetMaxTolerance", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::GetMaxTolerance, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::DynamicType, "None");

// Enums

}