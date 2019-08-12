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
#include <BRep_GCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <BRep_CurveOnSurface.hxx>
#include <Standard_Type.hxx>

void bind_BRep_CurveOnSurface(py::module &mod){

py::class_<BRep_CurveOnSurface, opencascade::handle<BRep_CurveOnSurface>, BRep_GCurve> cls_BRep_CurveOnSurface(mod, "BRep_CurveOnSurface", "Representation of a curve by a curve in the parametric space of a surface.");

// Constructors
cls_BRep_CurveOnSurface.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("PC"), py::arg("S"), py::arg("L"));

// Fields

// Methods
cls_BRep_CurveOnSurface.def("SetUVPoints", (void (BRep_CurveOnSurface::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &BRep_CurveOnSurface::SetUVPoints, "None", py::arg("P1"), py::arg("P2"));
cls_BRep_CurveOnSurface.def("UVPoints", (void (BRep_CurveOnSurface::*)(gp_Pnt2d &, gp_Pnt2d &) const) &BRep_CurveOnSurface::UVPoints, "None", py::arg("P1"), py::arg("P2"));
cls_BRep_CurveOnSurface.def("D0", (void (BRep_CurveOnSurface::*)(const Standard_Real, gp_Pnt &) const) &BRep_CurveOnSurface::D0, "Computes the point at parameter U.", py::arg("U"), py::arg("P"));
cls_BRep_CurveOnSurface.def("IsCurveOnSurface", (Standard_Boolean (BRep_CurveOnSurface::*)() const) &BRep_CurveOnSurface::IsCurveOnSurface, "Returns True.");
cls_BRep_CurveOnSurface.def("IsCurveOnSurface", (Standard_Boolean (BRep_CurveOnSurface::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_CurveOnSurface::IsCurveOnSurface, "A curve in the parametric space of a surface.", py::arg("S"), py::arg("L"));
cls_BRep_CurveOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_CurveOnSurface::*)() const) &BRep_CurveOnSurface::Surface, "None");
cls_BRep_CurveOnSurface.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRep_CurveOnSurface::*)() const) &BRep_CurveOnSurface::PCurve, "None");
cls_BRep_CurveOnSurface.def("PCurve", (void (BRep_CurveOnSurface::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_CurveOnSurface::PCurve, "None", py::arg("C"));
cls_BRep_CurveOnSurface.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_CurveOnSurface::*)() const) &BRep_CurveOnSurface::Copy, "Return a copy of this representation.");
cls_BRep_CurveOnSurface.def("Update", (void (BRep_CurveOnSurface::*)()) &BRep_CurveOnSurface::Update, "Recomputes any derived data after a modification. This is called when the range is modified.");
cls_BRep_CurveOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_CurveOnSurface::get_type_name, "None");
cls_BRep_CurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_CurveOnSurface::get_type_descriptor, "None");
cls_BRep_CurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_CurveOnSurface::*)() const) &BRep_CurveOnSurface::DynamicType, "None");

// Enums

}