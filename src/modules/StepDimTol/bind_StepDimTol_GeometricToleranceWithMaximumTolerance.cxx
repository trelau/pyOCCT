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
#include <StepDimTol_GeometricToleranceWithModifiers.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_HArray1OfGeometricToleranceModifier.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepDimTol_GeometricToleranceWithMaximumTolerance.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeometricToleranceWithMaximumTolerance(py::module &mod){

py::class_<StepDimTol_GeometricToleranceWithMaximumTolerance, opencascade::handle<StepDimTol_GeometricToleranceWithMaximumTolerance>, StepDimTol_GeometricToleranceWithModifiers> cls_StepDimTol_GeometricToleranceWithMaximumTolerance(mod, "StepDimTol_GeometricToleranceWithMaximumTolerance", "Representation of STEP entity GeometricToleranceWithMaximumTolerance");

// Constructors
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("Init", (void (StepDimTol_GeometricToleranceWithMaximumTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithMaximumTolerance::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theModifiers"), py::arg("theUnitSize"));
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("MaximumUpperTolerance", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithMaximumTolerance::*)() const) &StepDimTol_GeometricToleranceWithMaximumTolerance::MaximumUpperTolerance, "Returns field MaximumUpperTolerance");
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("SetMaximumUpperTolerance", (void (StepDimTol_GeometricToleranceWithMaximumTolerance::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithMaximumTolerance::SetMaximumUpperTolerance, "Set field MaximumUpperTolerance", py::arg("theMaximumUpperTolerance"));
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithMaximumTolerance::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithMaximumTolerance::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithMaximumTolerance::*)() const) &StepDimTol_GeometricToleranceWithMaximumTolerance::DynamicType, "None");

// Enums

}