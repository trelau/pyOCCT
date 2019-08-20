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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <TopLoc_Location.hxx>
#include <Poly_Triangulation.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <Poly_Polygon3D.hxx>
#include <Geom2d_Curve.hxx>
#include <Poly_Polygon2D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BRep_Tool.hxx>

void bind_BRep_Tool(py::module &mod){

py::class_<BRep_Tool, std::unique_ptr<BRep_Tool>> cls_BRep_Tool(mod, "BRep_Tool", "Provides class methods to access to the geometry of BRep shapes.");

// Constructors

// Fields

// Methods
// cls_BRep_Tool.def_static("operator new_", (void * (*)(size_t)) &BRep_Tool::operator new, "None", py::arg("theSize"));
// cls_BRep_Tool.def_static("operator delete_", (void (*)(void *)) &BRep_Tool::operator delete, "None", py::arg("theAddress"));
// cls_BRep_Tool.def_static("operator new[]_", (void * (*)(size_t)) &BRep_Tool::operator new[], "None", py::arg("theSize"));
// cls_BRep_Tool.def_static("operator delete[]_", (void (*)(void *)) &BRep_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_BRep_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &BRep_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRep_Tool.def_static("operator delete_", (void (*)(void *, void *)) &BRep_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRep_Tool.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRep_Tool::IsClosed, "If S is Shell, returns True if it has no free boundaries (edges). If S is Wire, returns True if it has no free ends (vertices). (Internal and External sub-shepes are ignored in these checks) If S is Edge, returns True if its vertices are the same. For other shape types returns S.Closed().", py::arg("S"));
cls_BRep_Tool.def_static("Surface_", (const opencascade::handle<Geom_Surface> & (*)(const TopoDS_Face &, TopLoc_Location &)) &BRep_Tool::Surface, "Returns the geometric surface of the face. Returns in <L> the location for the surface.", py::arg("F"), py::arg("L"));
cls_BRep_Tool.def_static("Surface_", (opencascade::handle<Geom_Surface> (*)(const TopoDS_Face &)) &BRep_Tool::Surface, "Returns the geometric surface of the face. It can be a copy if there is a Location.", py::arg("F"));
cls_BRep_Tool.def_static("Triangulation_", (const opencascade::handle<Poly_Triangulation> & (*)(const TopoDS_Face &, TopLoc_Location &)) &BRep_Tool::Triangulation, "Returns the Triangulation of the face. It is a null handle if there is no triangulation.", py::arg("F"), py::arg("L"));
cls_BRep_Tool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Face &)) &BRep_Tool::Tolerance, "Returns the tolerance of the face.", py::arg("F"));
cls_BRep_Tool.def_static("NaturalRestriction_", (Standard_Boolean (*)(const TopoDS_Face &)) &BRep_Tool::NaturalRestriction, "Returns the NaturalRestriction flag of the face.", py::arg("F"));
cls_BRep_Tool.def_static("IsGeometric_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::IsGeometric, "Returns True if <E> is a 3d curve or a curve on surface.", py::arg("E"));
cls_BRep_Tool.def_static("Curve_", [](const TopoDS_Edge & E, TopLoc_Location & L, Standard_Real & First, Standard_Real & Last){ const opencascade::handle<Geom_Curve> & rv = BRep_Tool::Curve(E, L, First, Last); return std::tuple<const opencascade::handle<Geom_Curve> &, Standard_Real &, Standard_Real &>(rv, First, Last); }, "Returns the 3D curve of the edge. May be a Null handle. Returns in <L> the location for the curve. In <First> and <Last> the parameter range.", py::arg("E"), py::arg("L"), py::arg("First"), py::arg("Last"));
cls_BRep_Tool.def_static("Curve_", [](const TopoDS_Edge & E, Standard_Real & First, Standard_Real & Last){ opencascade::handle<Geom_Curve> rv = BRep_Tool::Curve(E, First, Last); return std::tuple<opencascade::handle<Geom_Curve>, Standard_Real &, Standard_Real &>(rv, First, Last); }, "Returns the 3D curve of the edge. May be a Null handle. In <First> and <Last> the parameter range. It can be a copy if there is a Location.", py::arg("E"), py::arg("First"), py::arg("Last"));
cls_BRep_Tool.def_static("Polygon3D_", (const opencascade::handle<Poly_Polygon3D> & (*)(const TopoDS_Edge &, TopLoc_Location &)) &BRep_Tool::Polygon3D, "Returns the 3D polygon of the edge. May be a Null handle. Returns in <L> the location for the polygon.", py::arg("E"), py::arg("L"));
cls_BRep_Tool.def_static("CurveOnSurface_", [](const TopoDS_Edge & E, const TopoDS_Face & F, Standard_Real & First, Standard_Real & Last, Standard_Boolean * theIsStored){ opencascade::handle<Geom2d_Curve> rv = BRep_Tool::CurveOnSurface(E, F, First, Last, theIsStored); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &, Standard_Real &, Standard_Boolean *>(rv, First, Last, theIsStored); }, "Returns the curve associated to the edge in the parametric space of the face. Returns a NULL handle if this curve does not exist. Returns in <First> and <Last> the parameter range. If the surface is a plane the curve can be not stored but created a new each time. The flag pointed by <theIsStored> serves to indicate storage status. It is valued if the pointer is non-null.", py::arg("E"), py::arg("F"), py::arg("First"), py::arg("Last"), py::arg("theIsStored"));
cls_BRep_Tool.def_static("CurveOnSurface_", [](const TopoDS_Edge & E, const opencascade::handle<Geom_Surface> & S, const TopLoc_Location & L, Standard_Real & First, Standard_Real & Last, Standard_Boolean * theIsStored){ opencascade::handle<Geom2d_Curve> rv = BRep_Tool::CurveOnSurface(E, S, L, First, Last, theIsStored); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &, Standard_Real &, Standard_Boolean *>(rv, First, Last, theIsStored); }, "Returns the curve associated to the edge in the parametric space of the surface. Returns a NULL handle if this curve does not exist. Returns in <First> and <Last> the parameter range. If the surface is a plane the curve can be not stored but created a new each time. The flag pointed by <theIsStored> serves to indicate storage status. It is valued if the pointer is non-null.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"), py::arg("theIsStored"));
cls_BRep_Tool.def_static("CurveOnPlane_", [](const TopoDS_Edge & E, const opencascade::handle<Geom_Surface> & S, const TopLoc_Location & L, Standard_Real & First, Standard_Real & Last){ opencascade::handle<Geom2d_Curve> rv = BRep_Tool::CurveOnPlane(E, S, L, First, Last); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &, Standard_Real &>(rv, First, Last); }, "For the planar surface builds the 2d curve for the edge by projection of the edge on plane. Returns a NULL handle if the surface is not planar or the projection failed.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
cls_BRep_Tool.def_static("CurveOnSurface_", [](const TopoDS_Edge & E, opencascade::handle<Geom2d_Curve> & C, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & First, Standard_Real & Last){ BRep_Tool::CurveOnSurface(E, C, S, L, First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Returns in <C>, <S>, <L> a 2d curve, a surface and a location for the edge <E>. <C> and <S> are null if the edge has no curve on surface. Returns in <First> and <Last> the parameter range.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
cls_BRep_Tool.def_static("CurveOnSurface_", [](const TopoDS_Edge & E, opencascade::handle<Geom2d_Curve> & C, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & First, Standard_Real & Last, const Standard_Integer Index){ BRep_Tool::CurveOnSurface(E, C, S, L, First, Last, Index); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Returns in <C>, <S>, <L> the 2d curve, the surface and the location for the edge <E> of rank <Index>. <C> and <S> are null if the index is out of range. Returns in <First> and <Last> the parameter range.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"), py::arg("Index"));
cls_BRep_Tool.def_static("PolygonOnSurface_", (opencascade::handle<Poly_Polygon2D> (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRep_Tool::PolygonOnSurface, "Returns the polygon associated to the edge in the parametric space of the face. Returns a NULL handle if this polygon does not exist.", py::arg("E"), py::arg("F"));
cls_BRep_Tool.def_static("PolygonOnSurface_", (opencascade::handle<Poly_Polygon2D> (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &BRep_Tool::PolygonOnSurface, "Returns the polygon associated to the edge in the parametric space of the surface. Returns a NULL handle if this polygon does not exist.", py::arg("E"), py::arg("S"), py::arg("L"));
cls_BRep_Tool.def_static("PolygonOnSurface_", (void (*)(const TopoDS_Edge &, opencascade::handle<Poly_Polygon2D> &, opencascade::handle<Geom_Surface> &, TopLoc_Location &)) &BRep_Tool::PolygonOnSurface, "Returns in <C>, <S>, <L> a 2d curve, a surface and a location for the edge <E>. <C> and <S> are null if the edge has no polygon on surface.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"));
cls_BRep_Tool.def_static("PolygonOnSurface_", (void (*)(const TopoDS_Edge &, opencascade::handle<Poly_Polygon2D> &, opencascade::handle<Geom_Surface> &, TopLoc_Location &, const Standard_Integer)) &BRep_Tool::PolygonOnSurface, "Returns in <C>, <S>, <L> the 2d curve, the surface and the location for the edge <E> of rank <Index>. <C> and <S> are null if the index is out of range.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("Index"));
cls_BRep_Tool.def_static("PolygonOnTriangulation_", (const opencascade::handle<Poly_PolygonOnTriangulation> & (*)(const TopoDS_Edge &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRep_Tool::PolygonOnTriangulation, "Returns the polygon associated to the edge in the parametric space of the face. Returns a NULL handle if this polygon does not exist.", py::arg("E"), py::arg("T"), py::arg("L"));
cls_BRep_Tool.def_static("PolygonOnTriangulation_", (void (*)(const TopoDS_Edge &, opencascade::handle<Poly_PolygonOnTriangulation> &, opencascade::handle<Poly_Triangulation> &, TopLoc_Location &)) &BRep_Tool::PolygonOnTriangulation, "Returns in <P>, <T>, <L> a polygon on triangulation, a triangulation and a location for the edge <E>. <P> and <T> are null if the edge has no polygon on triangulation.", py::arg("E"), py::arg("P"), py::arg("T"), py::arg("L"));
cls_BRep_Tool.def_static("PolygonOnTriangulation_", (void (*)(const TopoDS_Edge &, opencascade::handle<Poly_PolygonOnTriangulation> &, opencascade::handle<Poly_Triangulation> &, TopLoc_Location &, const Standard_Integer)) &BRep_Tool::PolygonOnTriangulation, "Returns in <P>, <T>, <L> a polygon on triangulation, a triangulation and a location for the edge <E> for the range index. <C> and <S> are null if the edge has no polygon on triangulation.", py::arg("E"), py::arg("P"), py::arg("T"), py::arg("L"), py::arg("Index"));
cls_BRep_Tool.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRep_Tool::IsClosed, "Returns True if <E> has two PCurves in the parametric space of <F>. i.e. <F> is on a closed surface and <E> is on the closing curve.", py::arg("E"), py::arg("F"));
cls_BRep_Tool.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &BRep_Tool::IsClosed, "Returns True if <E> has two PCurves in the parametric space of <S>. i.e. <S> is a closed surface and <E> is on the closing curve.", py::arg("E"), py::arg("S"), py::arg("L"));
cls_BRep_Tool.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Edge &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRep_Tool::IsClosed, "Returns True if <E> has two arrays of indices in the triangulation <T>.", py::arg("E"), py::arg("T"), py::arg("L"));
cls_BRep_Tool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Edge &)) &BRep_Tool::Tolerance, "Returns the tolerance for <E>.", py::arg("E"));
cls_BRep_Tool.def_static("SameParameter_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::SameParameter, "Returns the SameParameter flag for the edge.", py::arg("E"));
cls_BRep_Tool.def_static("SameRange_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::SameRange, "Returns the SameRange flag for the edge.", py::arg("E"));
cls_BRep_Tool.def_static("Degenerated_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::Degenerated, "Returns True if the edge is degenerated.", py::arg("E"));
cls_BRep_Tool.def_static("Range_", [](const TopoDS_Edge & E, Standard_Real & First, Standard_Real & Last){ BRep_Tool::Range(E, First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the range of the 3d curve.", py::arg("E"), py::arg("First"), py::arg("Last"));
cls_BRep_Tool.def_static("Range_", [](const TopoDS_Edge & E, const opencascade::handle<Geom_Surface> & S, const TopLoc_Location & L, Standard_Real & First, Standard_Real & Last){ BRep_Tool::Range(E, S, L, First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the range of the edge on the pcurve on the surface.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
cls_BRep_Tool.def_static("Range_", [](const TopoDS_Edge & E, const TopoDS_Face & F, Standard_Real & First, Standard_Real & Last){ BRep_Tool::Range(E, F, First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the range of the edge on the pcurve on the face.", py::arg("E"), py::arg("F"), py::arg("First"), py::arg("Last"));
cls_BRep_Tool.def_static("UVPoints_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, gp_Pnt2d &, gp_Pnt2d &)) &BRep_Tool::UVPoints, "Gets the UV locations of the extremities of the edge.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("PFirst"), py::arg("PLast"));
cls_BRep_Tool.def_static("UVPoints_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, gp_Pnt2d &, gp_Pnt2d &)) &BRep_Tool::UVPoints, "Gets the UV locations of the extremities of the edge.", py::arg("E"), py::arg("F"), py::arg("PFirst"), py::arg("PLast"));
cls_BRep_Tool.def_static("SetUVPoints_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const gp_Pnt2d &, const gp_Pnt2d &)) &BRep_Tool::SetUVPoints, "Sets the UV locations of the extremities of the edge.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("PFirst"), py::arg("PLast"));
cls_BRep_Tool.def_static("SetUVPoints_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const gp_Pnt2d &, const gp_Pnt2d &)) &BRep_Tool::SetUVPoints, "Sets the UV locations of the extremities of the edge.", py::arg("E"), py::arg("F"), py::arg("PFirst"), py::arg("PLast"));
cls_BRep_Tool.def_static("HasContinuity_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRep_Tool::HasContinuity, "Returns True if the edge is on the surfaces of the two faces.", py::arg("E"), py::arg("F1"), py::arg("F2"));
cls_BRep_Tool.def_static("Continuity_", (GeomAbs_Shape (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRep_Tool::Continuity, "Returns the continuity.", py::arg("E"), py::arg("F1"), py::arg("F2"));
cls_BRep_Tool.def_static("HasContinuity_", (Standard_Boolean (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &)) &BRep_Tool::HasContinuity, "Returns True if the edge is on the surfaces.", py::arg("E"), py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
cls_BRep_Tool.def_static("Continuity_", (GeomAbs_Shape (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &)) &BRep_Tool::Continuity, "Returns the continuity.", py::arg("E"), py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
cls_BRep_Tool.def_static("HasContinuity_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::HasContinuity, "Returns True if the edge has regularity on some two surfaces", py::arg("E"));
cls_BRep_Tool.def_static("Pnt_", (gp_Pnt (*)(const TopoDS_Vertex &)) &BRep_Tool::Pnt, "Returns the 3d point.", py::arg("V"));
cls_BRep_Tool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Vertex &)) &BRep_Tool::Tolerance, "Returns the tolerance.", py::arg("V"));
cls_BRep_Tool.def_static("Parameter_", (Standard_Real (*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &BRep_Tool::Parameter, "Returns the parameter of <V> on <E>.", py::arg("V"), py::arg("E"));
cls_BRep_Tool.def_static("Parameter_", (Standard_Real (*)(const TopoDS_Vertex &, const TopoDS_Edge &, const TopoDS_Face &)) &BRep_Tool::Parameter, "Returns the parameters of the vertex on the pcurve of the edge on the face.", py::arg("V"), py::arg("E"), py::arg("F"));
cls_BRep_Tool.def_static("Parameter_", (Standard_Real (*)(const TopoDS_Vertex &, const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &BRep_Tool::Parameter, "Returns the parameters of the vertex on the pcurve of the edge on the surface.", py::arg("V"), py::arg("E"), py::arg("S"), py::arg("L"));
cls_BRep_Tool.def_static("Parameters_", (gp_Pnt2d (*)(const TopoDS_Vertex &, const TopoDS_Face &)) &BRep_Tool::Parameters, "Returns the parameters of the vertex on the face.", py::arg("V"), py::arg("F"));
cls_BRep_Tool.def_static("MaxTolerance_", (Standard_Real (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &BRep_Tool::MaxTolerance, "None", py::arg("theShape"), py::arg("theSubShape"));

// Enums

}