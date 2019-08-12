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
#include <StepDimTol_GeometricTolerance.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_GeometricToleranceWithModifiers.hxx>
#include <StepDimTol_GeometricToleranceType.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthMod.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeoTolAndGeoTolWthMod(py::module &mod){

py::class_<StepDimTol_GeoTolAndGeoTolWthMod, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMod>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthMod(mod, "StepDimTol_GeoTolAndGeoTolWthMod", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthMod.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWM"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWM"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("SetGeometricToleranceWithModifiers", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &)) &StepDimTol_GeoTolAndGeoTolWthMod::SetGeometricToleranceWithModifiers, "None", py::arg("theGTWM"));
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("GetGeometricToleranceWithModifiers", (opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> (StepDimTol_GeoTolAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthMod::GetGeometricToleranceWithModifiers, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("SetGeometricToleranceType", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::SetGeometricToleranceType, "None", py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("GetToleranceType", (StepDimTol_GeometricToleranceType (StepDimTol_GeoTolAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthMod::GetToleranceType, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMod.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthMod::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMod.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthMod::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthMod::DynamicType, "None");

// Enums

}