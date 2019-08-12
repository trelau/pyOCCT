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
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Direction.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Direction(py::module &mod){

py::class_<StepGeom_Direction, opencascade::handle<StepGeom_Direction>, StepGeom_GeometricRepresentationItem> cls_StepGeom_Direction(mod, "StepGeom_Direction", "None");

// Constructors
cls_StepGeom_Direction.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Direction.def("Init", (void (StepGeom_Direction::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_Direction::Init, "None", py::arg("aName"), py::arg("aDirectionRatios"));
cls_StepGeom_Direction.def("SetDirectionRatios", (void (StepGeom_Direction::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_Direction::SetDirectionRatios, "None", py::arg("aDirectionRatios"));
cls_StepGeom_Direction.def("DirectionRatios", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_Direction::*)() const) &StepGeom_Direction::DirectionRatios, "None");
cls_StepGeom_Direction.def("DirectionRatiosValue", (Standard_Real (StepGeom_Direction::*)(const Standard_Integer) const) &StepGeom_Direction::DirectionRatiosValue, "None", py::arg("num"));
cls_StepGeom_Direction.def("NbDirectionRatios", (Standard_Integer (StepGeom_Direction::*)() const) &StepGeom_Direction::NbDirectionRatios, "None");
cls_StepGeom_Direction.def_static("get_type_name_", (const char * (*)()) &StepGeom_Direction::get_type_name, "None");
cls_StepGeom_Direction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Direction::get_type_descriptor, "None");
cls_StepGeom_Direction.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Direction::*)() const) &StepGeom_Direction::DynamicType, "None");

// Enums

}