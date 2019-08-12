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
#include <StepGeom_Axis1Placement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_RightCircularCylinder.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_RightCircularCylinder(py::module &mod){

py::class_<StepShape_RightCircularCylinder, opencascade::handle<StepShape_RightCircularCylinder>, StepGeom_GeometricRepresentationItem> cls_StepShape_RightCircularCylinder(mod, "StepShape_RightCircularCylinder", "None");

// Constructors
cls_StepShape_RightCircularCylinder.def(py::init<>());

// Fields

// Methods
cls_StepShape_RightCircularCylinder.def("Init", (void (StepShape_RightCircularCylinder::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real, const Standard_Real)) &StepShape_RightCircularCylinder::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aHeight"), py::arg("aRadius"));
cls_StepShape_RightCircularCylinder.def("SetPosition", (void (StepShape_RightCircularCylinder::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_RightCircularCylinder::SetPosition, "None", py::arg("aPosition"));
cls_StepShape_RightCircularCylinder.def("Position", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_RightCircularCylinder::*)() const) &StepShape_RightCircularCylinder::Position, "None");
cls_StepShape_RightCircularCylinder.def("SetHeight", (void (StepShape_RightCircularCylinder::*)(const Standard_Real)) &StepShape_RightCircularCylinder::SetHeight, "None", py::arg("aHeight"));
cls_StepShape_RightCircularCylinder.def("Height", (Standard_Real (StepShape_RightCircularCylinder::*)() const) &StepShape_RightCircularCylinder::Height, "None");
cls_StepShape_RightCircularCylinder.def("SetRadius", (void (StepShape_RightCircularCylinder::*)(const Standard_Real)) &StepShape_RightCircularCylinder::SetRadius, "None", py::arg("aRadius"));
cls_StepShape_RightCircularCylinder.def("Radius", (Standard_Real (StepShape_RightCircularCylinder::*)() const) &StepShape_RightCircularCylinder::Radius, "None");
cls_StepShape_RightCircularCylinder.def_static("get_type_name_", (const char * (*)()) &StepShape_RightCircularCylinder::get_type_name, "None");
cls_StepShape_RightCircularCylinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RightCircularCylinder::get_type_descriptor, "None");
cls_StepShape_RightCircularCylinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RightCircularCylinder::*)() const) &StepShape_RightCircularCylinder::DynamicType, "None");

// Enums

}