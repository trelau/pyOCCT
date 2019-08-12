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
#include <StepGeom_Placement.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Direction.hxx>
#include <StepGeom_Axis1Placement.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Axis1Placement(py::module &mod){

py::class_<StepGeom_Axis1Placement, opencascade::handle<StepGeom_Axis1Placement>, StepGeom_Placement> cls_StepGeom_Axis1Placement(mod, "StepGeom_Axis1Placement", "None");

// Constructors
cls_StepGeom_Axis1Placement.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Axis1Placement.def("Init", (void (StepGeom_Axis1Placement::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis1Placement::Init, "None", py::arg("aName"), py::arg("aLocation"), py::arg("hasAaxis"), py::arg("aAxis"));
cls_StepGeom_Axis1Placement.def("SetAxis", (void (StepGeom_Axis1Placement::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis1Placement::SetAxis, "None", py::arg("aAxis"));
cls_StepGeom_Axis1Placement.def("UnSetAxis", (void (StepGeom_Axis1Placement::*)()) &StepGeom_Axis1Placement::UnSetAxis, "None");
cls_StepGeom_Axis1Placement.def("Axis", (opencascade::handle<StepGeom_Direction> (StepGeom_Axis1Placement::*)() const) &StepGeom_Axis1Placement::Axis, "None");
cls_StepGeom_Axis1Placement.def("HasAxis", (Standard_Boolean (StepGeom_Axis1Placement::*)() const) &StepGeom_Axis1Placement::HasAxis, "None");
cls_StepGeom_Axis1Placement.def_static("get_type_name_", (const char * (*)()) &StepGeom_Axis1Placement::get_type_name, "None");
cls_StepGeom_Axis1Placement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Axis1Placement::get_type_descriptor, "None");
cls_StepGeom_Axis1Placement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Axis1Placement::*)() const) &StepGeom_Axis1Placement::DynamicType, "None");

// Enums

}