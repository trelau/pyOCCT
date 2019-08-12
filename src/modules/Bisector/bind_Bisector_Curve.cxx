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
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Bisector_Curve.hxx>
#include <Standard_Type.hxx>

void bind_Bisector_Curve(py::module &mod){

py::class_<Bisector_Curve, opencascade::handle<Bisector_Curve>, Geom2d_Curve> cls_Bisector_Curve(mod, "Bisector_Curve", "None");

// Fields

// Methods
cls_Bisector_Curve.def("Parameter", (Standard_Real (Bisector_Curve::*)(const gp_Pnt2d &) const) &Bisector_Curve::Parameter, "None", py::arg("P"));
cls_Bisector_Curve.def("IsExtendAtStart", (Standard_Boolean (Bisector_Curve::*)() const) &Bisector_Curve::IsExtendAtStart, "None");
cls_Bisector_Curve.def("IsExtendAtEnd", (Standard_Boolean (Bisector_Curve::*)() const) &Bisector_Curve::IsExtendAtEnd, "None");
cls_Bisector_Curve.def("NbIntervals", (Standard_Integer (Bisector_Curve::*)() const) &Bisector_Curve::NbIntervals, "If necessary, breaks the curve in intervals of continuity <C1>. And returns the number of intervals.");
cls_Bisector_Curve.def("IntervalFirst", (Standard_Real (Bisector_Curve::*)(const Standard_Integer) const) &Bisector_Curve::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("Index"));
cls_Bisector_Curve.def("IntervalLast", (Standard_Real (Bisector_Curve::*)(const Standard_Integer) const) &Bisector_Curve::IntervalLast, "Returns the last parameter of the current interval.", py::arg("Index"));
cls_Bisector_Curve.def_static("get_type_name_", (const char * (*)()) &Bisector_Curve::get_type_name, "None");
cls_Bisector_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bisector_Curve::get_type_descriptor, "None");
cls_Bisector_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bisector_Curve::*)() const) &Bisector_Curve::DynamicType, "None");

// Enums

}