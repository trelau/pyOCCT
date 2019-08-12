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
#include <StepDimTol_LimitCondition.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_ModifiedGeometricTolerance.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_ModifiedGeometricTolerance(py::module &mod){

py::class_<StepDimTol_ModifiedGeometricTolerance, opencascade::handle<StepDimTol_ModifiedGeometricTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_ModifiedGeometricTolerance(mod, "StepDimTol_ModifiedGeometricTolerance", "Representation of STEP entity ModifiedGeometricTolerance");

// Constructors
cls_StepDimTol_ModifiedGeometricTolerance.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_ModifiedGeometricTolerance.def("Init", (void (StepDimTol_ModifiedGeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::Init, "Initialize all fields (own and inherited) AP214", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theModifier"));
cls_StepDimTol_ModifiedGeometricTolerance.def("Init", (void (StepDimTol_ModifiedGeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::Init, "Initialize all fields (own and inherited) AP242", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theModifier"));
cls_StepDimTol_ModifiedGeometricTolerance.def("Modifier", (StepDimTol_LimitCondition (StepDimTol_ModifiedGeometricTolerance::*)() const) &StepDimTol_ModifiedGeometricTolerance::Modifier, "Returns field Modifier");
cls_StepDimTol_ModifiedGeometricTolerance.def("SetModifier", (void (StepDimTol_ModifiedGeometricTolerance::*)(const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::SetModifier, "Set field Modifier", py::arg("theModifier"));
cls_StepDimTol_ModifiedGeometricTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ModifiedGeometricTolerance::get_type_name, "None");
cls_StepDimTol_ModifiedGeometricTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ModifiedGeometricTolerance::get_type_descriptor, "None");
cls_StepDimTol_ModifiedGeometricTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ModifiedGeometricTolerance::*)() const) &StepDimTol_ModifiedGeometricTolerance::DynamicType, "None");

// Enums

}