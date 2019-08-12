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
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_GeometricToleranceWithDefinedUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeometricToleranceWithDefinedUnit(py::module &mod){

py::class_<StepDimTol_GeometricToleranceWithDefinedUnit, opencascade::handle<StepDimTol_GeometricToleranceWithDefinedUnit>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeometricToleranceWithDefinedUnit(mod, "StepDimTol_GeometricToleranceWithDefinedUnit", "Representation of STEP entity GeometricToleranceWithDefinedUnit");

// Constructors
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::Init, "Initialize all fields (own and inherited) AP214", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::Init, "Initialize all fields (own and inherited) AP242", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("UnitSize", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithDefinedUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedUnit::UnitSize, "Returns field UnitSize");
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("SetUnitSize", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::SetUnitSize, "Set field UnitSize", py::arg("theUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDefinedUnit::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDefinedUnit::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDefinedUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedUnit::DynamicType, "None");

// Enums

}