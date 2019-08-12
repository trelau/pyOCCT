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
#include <StepGeom_BoundedCurve.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_HArray1OfCartesianPoint.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Polyline.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Polyline(py::module &mod){

py::class_<StepGeom_Polyline, opencascade::handle<StepGeom_Polyline>, StepGeom_BoundedCurve> cls_StepGeom_Polyline(mod, "StepGeom_Polyline", "None");

// Constructors
cls_StepGeom_Polyline.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Polyline.def("Init", (void (StepGeom_Polyline::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepGeom_Polyline::Init, "None", py::arg("aName"), py::arg("aPoints"));
cls_StepGeom_Polyline.def("SetPoints", (void (StepGeom_Polyline::*)(const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepGeom_Polyline::SetPoints, "None", py::arg("aPoints"));
cls_StepGeom_Polyline.def("Points", (opencascade::handle<StepGeom_HArray1OfCartesianPoint> (StepGeom_Polyline::*)() const) &StepGeom_Polyline::Points, "None");
cls_StepGeom_Polyline.def("PointsValue", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_Polyline::*)(const Standard_Integer) const) &StepGeom_Polyline::PointsValue, "None", py::arg("num"));
cls_StepGeom_Polyline.def("NbPoints", (Standard_Integer (StepGeom_Polyline::*)() const) &StepGeom_Polyline::NbPoints, "None");
cls_StepGeom_Polyline.def_static("get_type_name_", (const char * (*)()) &StepGeom_Polyline::get_type_name, "None");
cls_StepGeom_Polyline.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Polyline::get_type_descriptor, "None");
cls_StepGeom_Polyline.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Polyline::*)() const) &StepGeom_Polyline::DynamicType, "None");

// Enums

}