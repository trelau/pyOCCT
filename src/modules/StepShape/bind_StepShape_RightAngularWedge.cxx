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
#include <StepGeom_Axis2Placement3d.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_RightAngularWedge.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_RightAngularWedge(py::module &mod){

py::class_<StepShape_RightAngularWedge, opencascade::handle<StepShape_RightAngularWedge>, StepGeom_GeometricRepresentationItem> cls_StepShape_RightAngularWedge(mod, "StepShape_RightAngularWedge", "None");

// Constructors
cls_StepShape_RightAngularWedge.def(py::init<>());

// Fields

// Methods
cls_StepShape_RightAngularWedge.def("Init", (void (StepShape_RightAngularWedge::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &StepShape_RightAngularWedge::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aX"), py::arg("aY"), py::arg("aZ"), py::arg("aLtx"));
cls_StepShape_RightAngularWedge.def("SetPosition", (void (StepShape_RightAngularWedge::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepShape_RightAngularWedge::SetPosition, "None", py::arg("aPosition"));
cls_StepShape_RightAngularWedge.def("Position", (opencascade::handle<StepGeom_Axis2Placement3d> (StepShape_RightAngularWedge::*)() const) &StepShape_RightAngularWedge::Position, "None");
cls_StepShape_RightAngularWedge.def("SetX", (void (StepShape_RightAngularWedge::*)(const Standard_Real)) &StepShape_RightAngularWedge::SetX, "None", py::arg("aX"));
cls_StepShape_RightAngularWedge.def("X", (Standard_Real (StepShape_RightAngularWedge::*)() const) &StepShape_RightAngularWedge::X, "None");
cls_StepShape_RightAngularWedge.def("SetY", (void (StepShape_RightAngularWedge::*)(const Standard_Real)) &StepShape_RightAngularWedge::SetY, "None", py::arg("aY"));
cls_StepShape_RightAngularWedge.def("Y", (Standard_Real (StepShape_RightAngularWedge::*)() const) &StepShape_RightAngularWedge::Y, "None");
cls_StepShape_RightAngularWedge.def("SetZ", (void (StepShape_RightAngularWedge::*)(const Standard_Real)) &StepShape_RightAngularWedge::SetZ, "None", py::arg("aZ"));
cls_StepShape_RightAngularWedge.def("Z", (Standard_Real (StepShape_RightAngularWedge::*)() const) &StepShape_RightAngularWedge::Z, "None");
cls_StepShape_RightAngularWedge.def("SetLtx", (void (StepShape_RightAngularWedge::*)(const Standard_Real)) &StepShape_RightAngularWedge::SetLtx, "None", py::arg("aLtx"));
cls_StepShape_RightAngularWedge.def("Ltx", (Standard_Real (StepShape_RightAngularWedge::*)() const) &StepShape_RightAngularWedge::Ltx, "None");
cls_StepShape_RightAngularWedge.def_static("get_type_name_", (const char * (*)()) &StepShape_RightAngularWedge::get_type_name, "None");
cls_StepShape_RightAngularWedge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RightAngularWedge::get_type_descriptor, "None");
cls_StepShape_RightAngularWedge.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RightAngularWedge::*)() const) &StepShape_RightAngularWedge::DynamicType, "None");

// Enums

}