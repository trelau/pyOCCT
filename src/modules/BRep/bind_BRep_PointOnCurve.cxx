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
#include <BRep_PointRepresentation.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopLoc_Location.hxx>
#include <BRep_PointOnCurve.hxx>
#include <Standard_Type.hxx>

void bind_BRep_PointOnCurve(py::module &mod){

py::class_<BRep_PointOnCurve, opencascade::handle<BRep_PointOnCurve>, BRep_PointRepresentation> cls_BRep_PointOnCurve(mod, "BRep_PointOnCurve", "Representation by a parameter on a 3D curve.");

// Constructors
cls_BRep_PointOnCurve.def(py::init<const Standard_Real, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &>(), py::arg("P"), py::arg("C"), py::arg("L"));

// Fields

// Methods
cls_BRep_PointOnCurve.def("IsPointOnCurve", (Standard_Boolean (BRep_PointOnCurve::*)() const) &BRep_PointOnCurve::IsPointOnCurve, "Returns True");
cls_BRep_PointOnCurve.def("IsPointOnCurve", (Standard_Boolean (BRep_PointOnCurve::*)(const opencascade::handle<Geom_Curve> &, const TopLoc_Location &) const) &BRep_PointOnCurve::IsPointOnCurve, "None", py::arg("C"), py::arg("L"));
cls_BRep_PointOnCurve.def("Curve", (const opencascade::handle<Geom_Curve> & (BRep_PointOnCurve::*)() const) &BRep_PointOnCurve::Curve, "None");
cls_BRep_PointOnCurve.def("Curve", (void (BRep_PointOnCurve::*)(const opencascade::handle<Geom_Curve> &)) &BRep_PointOnCurve::Curve, "None", py::arg("C"));
cls_BRep_PointOnCurve.def_static("get_type_name_", (const char * (*)()) &BRep_PointOnCurve::get_type_name, "None");
cls_BRep_PointOnCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointOnCurve::get_type_descriptor, "None");
cls_BRep_PointOnCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointOnCurve::*)() const) &BRep_PointOnCurve::DynamicType, "None");

// Enums

}