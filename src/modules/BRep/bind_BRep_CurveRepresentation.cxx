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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <Poly_Triangulation.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_Polygon2D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_BRep_CurveRepresentation(py::module &mod){

py::class_<BRep_CurveRepresentation, opencascade::handle<BRep_CurveRepresentation>, Standard_Transient> cls_BRep_CurveRepresentation(mod, "BRep_CurveRepresentation", "Root class for the curve representations. Contains a location.");

// Fields

// Methods
cls_BRep_CurveRepresentation.def("IsCurve3D", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsCurve3D, "A 3D curve representation.");
cls_BRep_CurveRepresentation.def("IsCurveOnSurface", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsCurveOnSurface, "A curve in the parametric space of a surface.");
cls_BRep_CurveRepresentation.def("IsRegularity", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsRegularity, "A continuity between two surfaces.");
cls_BRep_CurveRepresentation.def("IsCurveOnClosedSurface", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsCurveOnClosedSurface, "A curve with two parametric curves on the same surface.");
cls_BRep_CurveRepresentation.def("IsCurveOnSurface", (Standard_Boolean (BRep_CurveRepresentation::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_CurveRepresentation::IsCurveOnSurface, "Is it a curve in the parametric space of <S> with location <L>.", py::arg("S"), py::arg("L"));
cls_BRep_CurveRepresentation.def("IsRegularity", (Standard_Boolean (BRep_CurveRepresentation::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &) const) &BRep_CurveRepresentation::IsRegularity, "Is it a regularity between <S1> and <S2> with location <L1> and <L2>.", py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
cls_BRep_CurveRepresentation.def("IsPolygon3D", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsPolygon3D, "A 3D polygon representation.");
cls_BRep_CurveRepresentation.def("IsPolygonOnTriangulation", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsPolygonOnTriangulation, "A representation by an array of nodes on a triangulation.");
cls_BRep_CurveRepresentation.def("IsPolygonOnTriangulation", (Standard_Boolean (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const) &BRep_CurveRepresentation::IsPolygonOnTriangulation, "Is it a polygon in the definition of <T> with location <L>.", py::arg("T"), py::arg("L"));
cls_BRep_CurveRepresentation.def("IsPolygonOnClosedTriangulation", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsPolygonOnClosedTriangulation, "A representation by two arrays of nodes on a triangulation.");
cls_BRep_CurveRepresentation.def("IsPolygonOnSurface", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsPolygonOnSurface, "A polygon in the parametric space of a surface.");
cls_BRep_CurveRepresentation.def("IsPolygonOnSurface", (Standard_Boolean (BRep_CurveRepresentation::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_CurveRepresentation::IsPolygonOnSurface, "Is it a polygon in the parametric space of <S> with location <L>.", py::arg("S"), py::arg("L"));
cls_BRep_CurveRepresentation.def("IsPolygonOnClosedSurface", (Standard_Boolean (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::IsPolygonOnClosedSurface, "Two 2D polygon representations in the parametric space of a surface.");
cls_BRep_CurveRepresentation.def("Location", (const TopLoc_Location & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Location, "None");
cls_BRep_CurveRepresentation.def("Location", (void (BRep_CurveRepresentation::*)(const TopLoc_Location &)) &BRep_CurveRepresentation::Location, "None", py::arg("L"));
cls_BRep_CurveRepresentation.def("Curve3D", (const opencascade::handle<Geom_Curve> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Curve3D, "None");
cls_BRep_CurveRepresentation.def("Curve3D", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Geom_Curve> &)) &BRep_CurveRepresentation::Curve3D, "None", py::arg("C"));
cls_BRep_CurveRepresentation.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Surface, "None");
cls_BRep_CurveRepresentation.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::PCurve, "None");
cls_BRep_CurveRepresentation.def("PCurve", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_CurveRepresentation::PCurve, "None", py::arg("C"));
cls_BRep_CurveRepresentation.def("PCurve2", (const opencascade::handle<Geom2d_Curve> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::PCurve2, "None");
cls_BRep_CurveRepresentation.def("PCurve2", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_CurveRepresentation::PCurve2, "None", py::arg("C"));
cls_BRep_CurveRepresentation.def("Polygon3D", (const opencascade::handle<Poly_Polygon3D> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Polygon3D, "None");
cls_BRep_CurveRepresentation.def("Polygon3D", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_Polygon3D> &)) &BRep_CurveRepresentation::Polygon3D, "None", py::arg("P"));
cls_BRep_CurveRepresentation.def("Polygon", (const opencascade::handle<Poly_Polygon2D> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Polygon, "None");
cls_BRep_CurveRepresentation.def("Polygon", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_Polygon2D> &)) &BRep_CurveRepresentation::Polygon, "None", py::arg("P"));
cls_BRep_CurveRepresentation.def("Polygon2", (const opencascade::handle<Poly_Polygon2D> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Polygon2, "None");
cls_BRep_CurveRepresentation.def("Polygon2", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_Polygon2D> &)) &BRep_CurveRepresentation::Polygon2, "None", py::arg("P"));
cls_BRep_CurveRepresentation.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Triangulation, "None");
cls_BRep_CurveRepresentation.def("PolygonOnTriangulation", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::PolygonOnTriangulation, "None");
cls_BRep_CurveRepresentation.def("PolygonOnTriangulation", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRep_CurveRepresentation::PolygonOnTriangulation, "None", py::arg("P"));
cls_BRep_CurveRepresentation.def("PolygonOnTriangulation2", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::PolygonOnTriangulation2, "None");
cls_BRep_CurveRepresentation.def("PolygonOnTriangulation2", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRep_CurveRepresentation::PolygonOnTriangulation2, "None", py::arg("P2"));
cls_BRep_CurveRepresentation.def("Surface2", (const opencascade::handle<Geom_Surface> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Surface2, "None");
cls_BRep_CurveRepresentation.def("Location2", (const TopLoc_Location & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Location2, "None");
cls_BRep_CurveRepresentation.def("Continuity", (const GeomAbs_Shape & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Continuity, "None");
cls_BRep_CurveRepresentation.def("Continuity", (void (BRep_CurveRepresentation::*)(const GeomAbs_Shape)) &BRep_CurveRepresentation::Continuity, "None", py::arg("C"));
cls_BRep_CurveRepresentation.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::Copy, "Return a copy of this representation.");
cls_BRep_CurveRepresentation.def_static("get_type_name_", (const char * (*)()) &BRep_CurveRepresentation::get_type_name, "None");
cls_BRep_CurveRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_CurveRepresentation::get_type_descriptor, "None");
cls_BRep_CurveRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_CurveRepresentation::*)() const) &BRep_CurveRepresentation::DynamicType, "None");

// Enums

}