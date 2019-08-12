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
#include <BRep_PointsOnSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <BRep_PointOnCurveOnSurface.hxx>
#include <Standard_Type.hxx>

void bind_BRep_PointOnCurveOnSurface(py::module &mod){

py::class_<BRep_PointOnCurveOnSurface, opencascade::handle<BRep_PointOnCurveOnSurface>, BRep_PointsOnSurface> cls_BRep_PointOnCurveOnSurface(mod, "BRep_PointOnCurveOnSurface", "Representation by a parameter on a curve on a surface.");

// Constructors
cls_BRep_PointOnCurveOnSurface.def(py::init<const Standard_Real, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("P"), py::arg("C"), py::arg("S"), py::arg("L"));

// Fields

// Methods
cls_BRep_PointOnCurveOnSurface.def("IsPointOnCurveOnSurface", (Standard_Boolean (BRep_PointOnCurveOnSurface::*)() const) &BRep_PointOnCurveOnSurface::IsPointOnCurveOnSurface, "Returns True");
cls_BRep_PointOnCurveOnSurface.def("IsPointOnCurveOnSurface", (Standard_Boolean (BRep_PointOnCurveOnSurface::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_PointOnCurveOnSurface::IsPointOnCurveOnSurface, "None", py::arg("PC"), py::arg("S"), py::arg("L"));
cls_BRep_PointOnCurveOnSurface.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRep_PointOnCurveOnSurface::*)() const) &BRep_PointOnCurveOnSurface::PCurve, "None");
cls_BRep_PointOnCurveOnSurface.def("PCurve", (void (BRep_PointOnCurveOnSurface::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_PointOnCurveOnSurface::PCurve, "None", py::arg("C"));
cls_BRep_PointOnCurveOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PointOnCurveOnSurface::get_type_name, "None");
cls_BRep_PointOnCurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointOnCurveOnSurface::get_type_descriptor, "None");
cls_BRep_PointOnCurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointOnCurveOnSurface::*)() const) &BRep_PointOnCurveOnSurface::DynamicType, "None");

// Enums

}