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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeometricTolerance(py::module &mod){

py::class_<StepDimTol_GeometricTolerance, opencascade::handle<StepDimTol_GeometricTolerance>, Standard_Transient> cls_StepDimTol_GeometricTolerance(mod, "StepDimTol_GeometricTolerance", "Representation of STEP entity GeometricTolerance");

// Constructors
cls_StepDimTol_GeometricTolerance.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeometricTolerance.def("Init", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_GeometricTolerance::Init, "Initialize all fields (own and inherited) AP214", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"));
cls_StepDimTol_GeometricTolerance.def("Init", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &)) &StepDimTol_GeometricTolerance::Init, "Initialize all fields (own and inherited) AP242", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"));
cls_StepDimTol_GeometricTolerance.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::Name, "Returns field Name");
cls_StepDimTol_GeometricTolerance.def("SetName", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricTolerance::SetName, "Set field Name", py::arg("theName"));
cls_StepDimTol_GeometricTolerance.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::Description, "Returns field Description");
cls_StepDimTol_GeometricTolerance.def("SetDescription", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricTolerance::SetDescription, "Set field Description", py::arg("theDescription"));
cls_StepDimTol_GeometricTolerance.def("Magnitude", (opencascade::handle<StepBasic_MeasureWithUnit> (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::Magnitude, "Returns field Magnitude");
cls_StepDimTol_GeometricTolerance.def("SetMagnitude", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepDimTol_GeometricTolerance::SetMagnitude, "Set field Magnitude", py::arg("theMagnitude"));
cls_StepDimTol_GeometricTolerance.def("TolerancedShapeAspect", (StepDimTol_GeometricToleranceTarget (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::TolerancedShapeAspect, "Returns field TolerancedShapeAspect Note: in AP214(203) type of this attribute can be only StepRepr_ShapeAspect");
cls_StepDimTol_GeometricTolerance.def("SetTolerancedShapeAspect", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_GeometricTolerance::SetTolerancedShapeAspect, "Set field TolerancedShapeAspect AP214", py::arg("theTolerancedShapeAspect"));
cls_StepDimTol_GeometricTolerance.def("SetTolerancedShapeAspect", (void (StepDimTol_GeometricTolerance::*)(const StepDimTol_GeometricToleranceTarget &)) &StepDimTol_GeometricTolerance::SetTolerancedShapeAspect, "Set field TolerancedShapeAspect AP242", py::arg("theTolerancedShapeAspect"));
cls_StepDimTol_GeometricTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricTolerance::get_type_name, "None");
cls_StepDimTol_GeometricTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricTolerance::get_type_descriptor, "None");
cls_StepDimTol_GeometricTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::DynamicType, "None");

// Enums

}