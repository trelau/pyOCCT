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
#include <StepGeom_Direction.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Vector.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Vector(py::module &mod){

py::class_<StepGeom_Vector, opencascade::handle<StepGeom_Vector>, StepGeom_GeometricRepresentationItem> cls_StepGeom_Vector(mod, "StepGeom_Vector", "None");

// Constructors
cls_StepGeom_Vector.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Vector.def("Init", (void (StepGeom_Vector::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Direction> &, const Standard_Real)) &StepGeom_Vector::Init, "None", py::arg("aName"), py::arg("aOrientation"), py::arg("aMagnitude"));
cls_StepGeom_Vector.def("SetOrientation", (void (StepGeom_Vector::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Vector::SetOrientation, "None", py::arg("aOrientation"));
cls_StepGeom_Vector.def("Orientation", (opencascade::handle<StepGeom_Direction> (StepGeom_Vector::*)() const) &StepGeom_Vector::Orientation, "None");
cls_StepGeom_Vector.def("SetMagnitude", (void (StepGeom_Vector::*)(const Standard_Real)) &StepGeom_Vector::SetMagnitude, "None", py::arg("aMagnitude"));
cls_StepGeom_Vector.def("Magnitude", (Standard_Real (StepGeom_Vector::*)() const) &StepGeom_Vector::Magnitude, "None");
cls_StepGeom_Vector.def_static("get_type_name_", (const char * (*)()) &StepGeom_Vector::get_type_name, "None");
cls_StepGeom_Vector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Vector::get_type_descriptor, "None");
cls_StepGeom_Vector.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Vector::*)() const) &StepGeom_Vector::DynamicType, "None");

// Enums

}