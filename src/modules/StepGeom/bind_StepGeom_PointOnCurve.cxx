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
#include <StepGeom_Point.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_PointOnCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_PointOnCurve(py::module &mod){

py::class_<StepGeom_PointOnCurve, opencascade::handle<StepGeom_PointOnCurve>, StepGeom_Point> cls_StepGeom_PointOnCurve(mod, "StepGeom_PointOnCurve", "None");

// Constructors
cls_StepGeom_PointOnCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_PointOnCurve.def("Init", (void (StepGeom_PointOnCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const Standard_Real)) &StepGeom_PointOnCurve::Init, "None", py::arg("aName"), py::arg("aBasisCurve"), py::arg("aPointParameter"));
cls_StepGeom_PointOnCurve.def("SetBasisCurve", (void (StepGeom_PointOnCurve::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_PointOnCurve::SetBasisCurve, "None", py::arg("aBasisCurve"));
cls_StepGeom_PointOnCurve.def("BasisCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_PointOnCurve::*)() const) &StepGeom_PointOnCurve::BasisCurve, "None");
cls_StepGeom_PointOnCurve.def("SetPointParameter", (void (StepGeom_PointOnCurve::*)(const Standard_Real)) &StepGeom_PointOnCurve::SetPointParameter, "None", py::arg("aPointParameter"));
cls_StepGeom_PointOnCurve.def("PointParameter", (Standard_Real (StepGeom_PointOnCurve::*)() const) &StepGeom_PointOnCurve::PointParameter, "None");
cls_StepGeom_PointOnCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_PointOnCurve::get_type_name, "None");
cls_StepGeom_PointOnCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_PointOnCurve::get_type_descriptor, "None");
cls_StepGeom_PointOnCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_PointOnCurve::*)() const) &StepGeom_PointOnCurve::DynamicType, "None");

// Enums

}