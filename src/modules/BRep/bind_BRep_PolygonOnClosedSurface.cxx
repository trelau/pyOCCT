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
#include <BRep_PolygonOnSurface.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Polygon2D.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <BRep_PolygonOnClosedSurface.hxx>
#include <Standard_Type.hxx>

void bind_BRep_PolygonOnClosedSurface(py::module &mod){

py::class_<BRep_PolygonOnClosedSurface, opencascade::handle<BRep_PolygonOnClosedSurface>, BRep_PolygonOnSurface> cls_BRep_PolygonOnClosedSurface(mod, "BRep_PolygonOnClosedSurface", "Representation by two 2d polygons in the parametric space of a surface.");

// Constructors
cls_BRep_PolygonOnClosedSurface.def(py::init<const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("P1"), py::arg("P2"), py::arg("S"), py::arg("L"));

// Fields

// Methods
cls_BRep_PolygonOnClosedSurface.def("IsPolygonOnClosedSurface", (Standard_Boolean (BRep_PolygonOnClosedSurface::*)() const) &BRep_PolygonOnClosedSurface::IsPolygonOnClosedSurface, "returns True.");
cls_BRep_PolygonOnClosedSurface.def("Polygon2", (const opencascade::handle<Poly_Polygon2D> & (BRep_PolygonOnClosedSurface::*)() const) &BRep_PolygonOnClosedSurface::Polygon2, "None");
cls_BRep_PolygonOnClosedSurface.def("Polygon2", (void (BRep_PolygonOnClosedSurface::*)(const opencascade::handle<Poly_Polygon2D> &)) &BRep_PolygonOnClosedSurface::Polygon2, "None", py::arg("P"));
cls_BRep_PolygonOnClosedSurface.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_PolygonOnClosedSurface::*)() const) &BRep_PolygonOnClosedSurface::Copy, "Return a copy of this representation.");
cls_BRep_PolygonOnClosedSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PolygonOnClosedSurface::get_type_name, "None");
cls_BRep_PolygonOnClosedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PolygonOnClosedSurface::get_type_descriptor, "None");
cls_BRep_PolygonOnClosedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PolygonOnClosedSurface::*)() const) &BRep_PolygonOnClosedSurface::DynamicType, "None");

// Enums

}