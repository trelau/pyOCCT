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
#include <StepGeom_Curve.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_Logical.hxx>
#include <StepGeom_Direction.hxx>
#include <StepGeom_OffsetCurve3d.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_OffsetCurve3d(py::module &mod){

py::class_<StepGeom_OffsetCurve3d, opencascade::handle<StepGeom_OffsetCurve3d>, StepGeom_Curve> cls_StepGeom_OffsetCurve3d(mod, "StepGeom_OffsetCurve3d", "None");

// Constructors
cls_StepGeom_OffsetCurve3d.def(py::init<>());

// Fields

// Methods
cls_StepGeom_OffsetCurve3d.def("Init", (void (StepGeom_OffsetCurve3d::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const Standard_Real, const StepData_Logical, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_OffsetCurve3d::Init, "None", py::arg("aName"), py::arg("aBasisCurve"), py::arg("aDistance"), py::arg("aSelfIntersect"), py::arg("aRefDirection"));
cls_StepGeom_OffsetCurve3d.def("SetBasisCurve", (void (StepGeom_OffsetCurve3d::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_OffsetCurve3d::SetBasisCurve, "None", py::arg("aBasisCurve"));
cls_StepGeom_OffsetCurve3d.def("BasisCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::BasisCurve, "None");
cls_StepGeom_OffsetCurve3d.def("SetDistance", (void (StepGeom_OffsetCurve3d::*)(const Standard_Real)) &StepGeom_OffsetCurve3d::SetDistance, "None", py::arg("aDistance"));
cls_StepGeom_OffsetCurve3d.def("Distance", (Standard_Real (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::Distance, "None");
cls_StepGeom_OffsetCurve3d.def("SetSelfIntersect", (void (StepGeom_OffsetCurve3d::*)(const StepData_Logical)) &StepGeom_OffsetCurve3d::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_OffsetCurve3d.def("SelfIntersect", (StepData_Logical (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::SelfIntersect, "None");
cls_StepGeom_OffsetCurve3d.def("SetRefDirection", (void (StepGeom_OffsetCurve3d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_OffsetCurve3d::SetRefDirection, "None", py::arg("aRefDirection"));
cls_StepGeom_OffsetCurve3d.def("RefDirection", (opencascade::handle<StepGeom_Direction> (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::RefDirection, "None");
cls_StepGeom_OffsetCurve3d.def_static("get_type_name_", (const char * (*)()) &StepGeom_OffsetCurve3d::get_type_name, "None");
cls_StepGeom_OffsetCurve3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_OffsetCurve3d::get_type_descriptor, "None");
cls_StepGeom_OffsetCurve3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::DynamicType, "None");

// Enums

}