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
#include <BRep_CurveOnSurface.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <BRep_CurveOnClosedSurface.hxx>
#include <Standard_Type.hxx>

void bind_BRep_CurveOnClosedSurface(py::module &mod){

py::class_<BRep_CurveOnClosedSurface, opencascade::handle<BRep_CurveOnClosedSurface>, BRep_CurveOnSurface> cls_BRep_CurveOnClosedSurface(mod, "BRep_CurveOnClosedSurface", "Representation of a curve by two pcurves on a closed surface.");

// Constructors
cls_BRep_CurveOnClosedSurface.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const GeomAbs_Shape>(), py::arg("PC1"), py::arg("PC2"), py::arg("S"), py::arg("L"), py::arg("C"));

// Fields

// Methods
cls_BRep_CurveOnClosedSurface.def("SetUVPoints2", (void (BRep_CurveOnClosedSurface::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &BRep_CurveOnClosedSurface::SetUVPoints2, "None", py::arg("P1"), py::arg("P2"));
cls_BRep_CurveOnClosedSurface.def("UVPoints2", (void (BRep_CurveOnClosedSurface::*)(gp_Pnt2d &, gp_Pnt2d &) const) &BRep_CurveOnClosedSurface::UVPoints2, "None", py::arg("P1"), py::arg("P2"));
cls_BRep_CurveOnClosedSurface.def("IsCurveOnClosedSurface", (Standard_Boolean (BRep_CurveOnClosedSurface::*)() const) &BRep_CurveOnClosedSurface::IsCurveOnClosedSurface, "Returns True.");
cls_BRep_CurveOnClosedSurface.def("IsRegularity", (Standard_Boolean (BRep_CurveOnClosedSurface::*)() const) &BRep_CurveOnClosedSurface::IsRegularity, "Returns True");
cls_BRep_CurveOnClosedSurface.def("IsRegularity", (Standard_Boolean (BRep_CurveOnClosedSurface::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &) const) &BRep_CurveOnClosedSurface::IsRegularity, "A curve on two surfaces (continuity).", py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
cls_BRep_CurveOnClosedSurface.def("PCurve2", (const opencascade::handle<Geom2d_Curve> & (BRep_CurveOnClosedSurface::*)() const) &BRep_CurveOnClosedSurface::PCurve2, "None");
cls_BRep_CurveOnClosedSurface.def("Surface2", (const opencascade::handle<Geom_Surface> & (BRep_CurveOnClosedSurface::*)() const) &BRep_CurveOnClosedSurface::Surface2, "Returns Surface()");
cls_BRep_CurveOnClosedSurface.def("Location2", (const TopLoc_Location & (BRep_CurveOnClosedSurface::*)() const) &BRep_CurveOnClosedSurface::Location2, "Returns Location()");
cls_BRep_CurveOnClosedSurface.def("Continuity", (const GeomAbs_Shape & (BRep_CurveOnClosedSurface::*)() const) &BRep_CurveOnClosedSurface::Continuity, "None");
cls_BRep_CurveOnClosedSurface.def("Continuity", (void (BRep_CurveOnClosedSurface::*)(const GeomAbs_Shape)) &BRep_CurveOnClosedSurface::Continuity, "None", py::arg("C"));
cls_BRep_CurveOnClosedSurface.def("PCurve2", (void (BRep_CurveOnClosedSurface::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_CurveOnClosedSurface::PCurve2, "None", py::arg("C"));
cls_BRep_CurveOnClosedSurface.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_CurveOnClosedSurface::*)() const) &BRep_CurveOnClosedSurface::Copy, "Return a copy of this representation.");
cls_BRep_CurveOnClosedSurface.def("Update", (void (BRep_CurveOnClosedSurface::*)()) &BRep_CurveOnClosedSurface::Update, "Recomputes any derived data after a modification. This is called when the range is modified.");
cls_BRep_CurveOnClosedSurface.def_static("get_type_name_", (const char * (*)()) &BRep_CurveOnClosedSurface::get_type_name, "None");
cls_BRep_CurveOnClosedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_CurveOnClosedSurface::get_type_descriptor, "None");
cls_BRep_CurveOnClosedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_CurveOnClosedSurface::*)() const) &BRep_CurveOnClosedSurface::DynamicType, "None");

// Enums

}