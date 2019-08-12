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
#include <StepGeom_Axis2Placement3d.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Axis2Placement3d(py::module &mod){

py::class_<StepGeom_Axis2Placement3d, opencascade::handle<StepGeom_Axis2Placement3d>, StepGeom_Placement> cls_StepGeom_Axis2Placement3d(mod, "StepGeom_Axis2Placement3d", "None");

// Constructors
cls_StepGeom_Axis2Placement3d.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Axis2Placement3d.def("Init", (void (StepGeom_Axis2Placement3d::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement3d::Init, "None", py::arg("aName"), py::arg("aLocation"), py::arg("hasAaxis"), py::arg("aAxis"), py::arg("hasArefDirection"), py::arg("aRefDirection"));
cls_StepGeom_Axis2Placement3d.def("SetAxis", (void (StepGeom_Axis2Placement3d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement3d::SetAxis, "None", py::arg("aAxis"));
cls_StepGeom_Axis2Placement3d.def("UnSetAxis", (void (StepGeom_Axis2Placement3d::*)()) &StepGeom_Axis2Placement3d::UnSetAxis, "None");
cls_StepGeom_Axis2Placement3d.def("Axis", (opencascade::handle<StepGeom_Direction> (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::Axis, "None");
cls_StepGeom_Axis2Placement3d.def("HasAxis", (Standard_Boolean (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::HasAxis, "None");
cls_StepGeom_Axis2Placement3d.def("SetRefDirection", (void (StepGeom_Axis2Placement3d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement3d::SetRefDirection, "None", py::arg("aRefDirection"));
cls_StepGeom_Axis2Placement3d.def("UnSetRefDirection", (void (StepGeom_Axis2Placement3d::*)()) &StepGeom_Axis2Placement3d::UnSetRefDirection, "None");
cls_StepGeom_Axis2Placement3d.def("RefDirection", (opencascade::handle<StepGeom_Direction> (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::RefDirection, "None");
cls_StepGeom_Axis2Placement3d.def("HasRefDirection", (Standard_Boolean (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::HasRefDirection, "None");
cls_StepGeom_Axis2Placement3d.def_static("get_type_name_", (const char * (*)()) &StepGeom_Axis2Placement3d::get_type_name, "None");
cls_StepGeom_Axis2Placement3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Axis2Placement3d::get_type_descriptor, "None");
cls_StepGeom_Axis2Placement3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::DynamicType, "None");

// Enums

}