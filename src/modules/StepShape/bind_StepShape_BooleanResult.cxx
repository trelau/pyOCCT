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
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_BooleanOperator.hxx>
#include <StepShape_BooleanOperand.hxx>
#include <StepShape_BooleanResult.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_BooleanResult(py::module &mod){

py::class_<StepShape_BooleanResult, opencascade::handle<StepShape_BooleanResult>, StepGeom_GeometricRepresentationItem> cls_StepShape_BooleanResult(mod, "StepShape_BooleanResult", "None");

// Constructors
cls_StepShape_BooleanResult.def(py::init<>());

// Fields

// Methods
cls_StepShape_BooleanResult.def("Init", (void (StepShape_BooleanResult::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepShape_BooleanOperator, const StepShape_BooleanOperand &, const StepShape_BooleanOperand &)) &StepShape_BooleanResult::Init, "None", py::arg("aName"), py::arg("aOperator"), py::arg("aFirstOperand"), py::arg("aSecondOperand"));
cls_StepShape_BooleanResult.def("SetOperator", (void (StepShape_BooleanResult::*)(const StepShape_BooleanOperator)) &StepShape_BooleanResult::SetOperator, "None", py::arg("aOperator"));
cls_StepShape_BooleanResult.def("Operator", (StepShape_BooleanOperator (StepShape_BooleanResult::*)() const) &StepShape_BooleanResult::Operator, "None");
cls_StepShape_BooleanResult.def("SetFirstOperand", (void (StepShape_BooleanResult::*)(const StepShape_BooleanOperand &)) &StepShape_BooleanResult::SetFirstOperand, "None", py::arg("aFirstOperand"));
cls_StepShape_BooleanResult.def("FirstOperand", (StepShape_BooleanOperand (StepShape_BooleanResult::*)() const) &StepShape_BooleanResult::FirstOperand, "None");
cls_StepShape_BooleanResult.def("SetSecondOperand", (void (StepShape_BooleanResult::*)(const StepShape_BooleanOperand &)) &StepShape_BooleanResult::SetSecondOperand, "None", py::arg("aSecondOperand"));
cls_StepShape_BooleanResult.def("SecondOperand", (StepShape_BooleanOperand (StepShape_BooleanResult::*)() const) &StepShape_BooleanResult::SecondOperand, "None");
cls_StepShape_BooleanResult.def_static("get_type_name_", (const char * (*)()) &StepShape_BooleanResult::get_type_name, "None");
cls_StepShape_BooleanResult.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_BooleanResult::get_type_descriptor, "None");
cls_StepShape_BooleanResult.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_BooleanResult::*)() const) &StepShape_BooleanResult::DynamicType, "None");

// Enums

}