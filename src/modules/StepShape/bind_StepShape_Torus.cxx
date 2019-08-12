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
#include <StepShape_Torus.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_Torus(py::module &mod){

py::class_<StepShape_Torus, opencascade::handle<StepShape_Torus>, StepGeom_GeometricRepresentationItem> cls_StepShape_Torus(mod, "StepShape_Torus", "None");

// Constructors
cls_StepShape_Torus.def(py::init<>());

// Fields

// Methods
cls_StepShape_Torus.def("Init", (void (StepShape_Torus::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real, const Standard_Real)) &StepShape_Torus::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aMajorRadius"), py::arg("aMinorRadius"));
cls_StepShape_Torus.def("SetPosition", (void (StepShape_Torus::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_Torus::SetPosition, "None", py::arg("aPosition"));
cls_StepShape_Torus.def("Position", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_Torus::*)() const) &StepShape_Torus::Position, "None");
cls_StepShape_Torus.def("SetMajorRadius", (void (StepShape_Torus::*)(const Standard_Real)) &StepShape_Torus::SetMajorRadius, "None", py::arg("aMajorRadius"));
cls_StepShape_Torus.def("MajorRadius", (Standard_Real (StepShape_Torus::*)() const) &StepShape_Torus::MajorRadius, "None");
cls_StepShape_Torus.def("SetMinorRadius", (void (StepShape_Torus::*)(const Standard_Real)) &StepShape_Torus::SetMinorRadius, "None", py::arg("aMinorRadius"));
cls_StepShape_Torus.def("MinorRadius", (Standard_Real (StepShape_Torus::*)() const) &StepShape_Torus::MinorRadius, "None");
cls_StepShape_Torus.def_static("get_type_name_", (const char * (*)()) &StepShape_Torus::get_type_name, "None");
cls_StepShape_Torus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Torus::get_type_descriptor, "None");
cls_StepShape_Torus.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Torus::*)() const) &StepShape_Torus::DynamicType, "None");

// Enums

}