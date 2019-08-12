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
#include <BRep_CurveRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Polygon2D.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_PolygonOnSurface.hxx>
#include <Standard_Type.hxx>

void bind_BRep_PolygonOnSurface(py::module &mod){

py::class_<BRep_PolygonOnSurface, opencascade::handle<BRep_PolygonOnSurface>, BRep_CurveRepresentation> cls_BRep_PolygonOnSurface(mod, "BRep_PolygonOnSurface", "Representation of a 2D polygon in the parametric space of a surface.");

// Constructors
cls_BRep_PolygonOnSurface.def(py::init<const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("P"), py::arg("S"), py::arg("L"));

// Fields

// Methods
cls_BRep_PolygonOnSurface.def("IsPolygonOnSurface", (Standard_Boolean (BRep_PolygonOnSurface::*)() const) &BRep_PolygonOnSurface::IsPolygonOnSurface, "A 2D polygon representation in the parametric space of a surface.");
cls_BRep_PolygonOnSurface.def("IsPolygonOnSurface", (Standard_Boolean (BRep_PolygonOnSurface::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_PolygonOnSurface::IsPolygonOnSurface, "A 2D polygon representation in the parametric space of a surface.", py::arg("S"), py::arg("L"));
cls_BRep_PolygonOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_PolygonOnSurface::*)() const) &BRep_PolygonOnSurface::Surface, "None");
cls_BRep_PolygonOnSurface.def("Polygon", (const opencascade::handle<Poly_Polygon2D> & (BRep_PolygonOnSurface::*)() const) &BRep_PolygonOnSurface::Polygon, "None");
cls_BRep_PolygonOnSurface.def("Polygon", (void (BRep_PolygonOnSurface::*)(const opencascade::handle<Poly_Polygon2D> &)) &BRep_PolygonOnSurface::Polygon, "None", py::arg("P"));
cls_BRep_PolygonOnSurface.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_PolygonOnSurface::*)() const) &BRep_PolygonOnSurface::Copy, "Return a copy of this representation.");
cls_BRep_PolygonOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PolygonOnSurface::get_type_name, "None");
cls_BRep_PolygonOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PolygonOnSurface::get_type_descriptor, "None");
cls_BRep_PolygonOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PolygonOnSurface::*)() const) &BRep_PolygonOnSurface::DynamicType, "None");

// Enums

}