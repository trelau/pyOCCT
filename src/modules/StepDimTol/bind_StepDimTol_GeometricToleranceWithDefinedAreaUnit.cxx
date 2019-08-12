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
#include <StepDimTol_GeometricToleranceWithDefinedUnit.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepDimTol_AreaUnitType.hxx>
#include <Standard_TypeDef.hxx>
#include <StepDimTol_GeometricToleranceWithDefinedAreaUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeometricToleranceWithDefinedAreaUnit(py::module &mod){

py::class_<StepDimTol_GeometricToleranceWithDefinedAreaUnit, opencascade::handle<StepDimTol_GeometricToleranceWithDefinedAreaUnit>, StepDimTol_GeometricToleranceWithDefinedUnit> cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit(mod, "StepDimTol_GeometricToleranceWithDefinedAreaUnit", "Representation of STEP entity GeometricToleranceWithDefinedAreaUnit");

// Constructors
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_AreaUnitType, const Standard_Boolean, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"), py::arg("theAreaType"), py::arg("theHasSecondUnitSize"), py::arg("theSecondUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("AreaType", (StepDimTol_AreaUnitType (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::AreaType, "Returns field AreaType");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SetAreaType", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const StepDimTol_AreaUnitType)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SetAreaType, "Set field AreaType", py::arg("theAreaType"));
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SecondUnitSize", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SecondUnitSize, "Returns field SecondUnitSize");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SetSecondUnitSize", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SetSecondUnitSize, "Set field SecondUnitSize", py::arg("theSecondUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("HasSecondUnitSize", (Standard_Boolean (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::HasSecondUnitSize, "Indicates if SecondUnitSize field exist");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::DynamicType, "None");

// Enums

}