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
#include <StepShape_Block.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_Block(py::module &mod){

py::class_<StepShape_Block, opencascade::handle<StepShape_Block>, StepGeom_GeometricRepresentationItem> cls_StepShape_Block(mod, "StepShape_Block", "None");

// Constructors
cls_StepShape_Block.def(py::init<>());

// Fields

// Methods
cls_StepShape_Block.def("Init", (void (StepShape_Block::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepShape_Block::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aX"), py::arg("aY"), py::arg("aZ"));
cls_StepShape_Block.def("SetPosition", (void (StepShape_Block::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepShape_Block::SetPosition, "None", py::arg("aPosition"));
cls_StepShape_Block.def("Position", (opencascade::handle<StepGeom_Axis2Placement3d> (StepShape_Block::*)() const) &StepShape_Block::Position, "None");
cls_StepShape_Block.def("SetX", (void (StepShape_Block::*)(const Standard_Real)) &StepShape_Block::SetX, "None", py::arg("aX"));
cls_StepShape_Block.def("X", (Standard_Real (StepShape_Block::*)() const) &StepShape_Block::X, "None");
cls_StepShape_Block.def("SetY", (void (StepShape_Block::*)(const Standard_Real)) &StepShape_Block::SetY, "None", py::arg("aY"));
cls_StepShape_Block.def("Y", (Standard_Real (StepShape_Block::*)() const) &StepShape_Block::Y, "None");
cls_StepShape_Block.def("SetZ", (void (StepShape_Block::*)(const Standard_Real)) &StepShape_Block::SetZ, "None", py::arg("aZ"));
cls_StepShape_Block.def("Z", (Standard_Real (StepShape_Block::*)() const) &StepShape_Block::Z, "None");
cls_StepShape_Block.def_static("get_type_name_", (const char * (*)()) &StepShape_Block::get_type_name, "None");
cls_StepShape_Block.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Block::get_type_descriptor, "None");
cls_StepShape_Block.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Block::*)() const) &StepShape_Block::DynamicType, "None");

// Enums

}