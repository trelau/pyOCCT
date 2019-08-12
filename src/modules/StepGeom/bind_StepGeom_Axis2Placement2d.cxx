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
#include <StepGeom_Axis2Placement2d.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Axis2Placement2d(py::module &mod){

py::class_<StepGeom_Axis2Placement2d, opencascade::handle<StepGeom_Axis2Placement2d>, StepGeom_Placement> cls_StepGeom_Axis2Placement2d(mod, "StepGeom_Axis2Placement2d", "None");

// Constructors
cls_StepGeom_Axis2Placement2d.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Axis2Placement2d.def("Init", (void (StepGeom_Axis2Placement2d::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement2d::Init, "None", py::arg("aName"), py::arg("aLocation"), py::arg("hasArefDirection"), py::arg("aRefDirection"));
cls_StepGeom_Axis2Placement2d.def("SetRefDirection", (void (StepGeom_Axis2Placement2d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement2d::SetRefDirection, "None", py::arg("aRefDirection"));
cls_StepGeom_Axis2Placement2d.def("UnSetRefDirection", (void (StepGeom_Axis2Placement2d::*)()) &StepGeom_Axis2Placement2d::UnSetRefDirection, "None");
cls_StepGeom_Axis2Placement2d.def("RefDirection", (opencascade::handle<StepGeom_Direction> (StepGeom_Axis2Placement2d::*)() const) &StepGeom_Axis2Placement2d::RefDirection, "None");
cls_StepGeom_Axis2Placement2d.def("HasRefDirection", (Standard_Boolean (StepGeom_Axis2Placement2d::*)() const) &StepGeom_Axis2Placement2d::HasRefDirection, "None");
cls_StepGeom_Axis2Placement2d.def_static("get_type_name_", (const char * (*)()) &StepGeom_Axis2Placement2d::get_type_name, "None");
cls_StepGeom_Axis2Placement2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Axis2Placement2d::get_type_descriptor, "None");
cls_StepGeom_Axis2Placement2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Axis2Placement2d::*)() const) &StepGeom_Axis2Placement2d::DynamicType, "None");

// Enums

}