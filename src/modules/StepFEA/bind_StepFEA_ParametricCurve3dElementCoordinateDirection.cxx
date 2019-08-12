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
#include <StepFEA_FeaRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Direction.hxx>
#include <StepFEA_ParametricCurve3dElementCoordinateDirection.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_ParametricCurve3dElementCoordinateDirection(py::module &mod){

py::class_<StepFEA_ParametricCurve3dElementCoordinateDirection, opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateDirection>, StepFEA_FeaRepresentationItem> cls_StepFEA_ParametricCurve3dElementCoordinateDirection(mod, "StepFEA_ParametricCurve3dElementCoordinateDirection", "Representation of STEP entity ParametricCurve3dElementCoordinateDirection");

// Constructors
cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def(py::init<>());

// Fields

// Methods
cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def("Init", (void (StepFEA_ParametricCurve3dElementCoordinateDirection::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Direction> &)) &StepFEA_ParametricCurve3dElementCoordinateDirection::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aOrientation"));
cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def("Orientation", (opencascade::handle<StepGeom_Direction> (StepFEA_ParametricCurve3dElementCoordinateDirection::*)() const) &StepFEA_ParametricCurve3dElementCoordinateDirection::Orientation, "Returns field Orientation");
cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def("SetOrientation", (void (StepFEA_ParametricCurve3dElementCoordinateDirection::*)(const opencascade::handle<StepGeom_Direction> &)) &StepFEA_ParametricCurve3dElementCoordinateDirection::SetOrientation, "Set field Orientation", py::arg("Orientation"));
cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def_static("get_type_name_", (const char * (*)()) &StepFEA_ParametricCurve3dElementCoordinateDirection::get_type_name, "None");
cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ParametricCurve3dElementCoordinateDirection::get_type_descriptor, "None");
cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ParametricCurve3dElementCoordinateDirection::*)() const) &StepFEA_ParametricCurve3dElementCoordinateDirection::DynamicType, "None");

// Enums

}