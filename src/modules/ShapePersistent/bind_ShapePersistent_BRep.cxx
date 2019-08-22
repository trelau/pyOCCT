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
#include <ShapePersistent_TopoDS.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <ShapePersistent_BRep.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_ListOfPointRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <BRep_PointRepresentation.hxx>
#include <StdObject_Location.hxx>
#include <ShapePersistent_Geom.hxx>
#include <ShapePersistent_Geom2d.hxx>
#include <BRep_ListOfCurveRepresentation.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <gp_Pnt2d.hxx>
#include <ShapePersistent_Poly.hxx>
#include <TopoDS_TShape.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <TopoDS_Edge.hxx>
#include <ShapePersistent_TriangleMode.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Curve.hxx>
#include <TopLoc_Location.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <GeomAbs_Shape.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_Polygon2D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Triangulation.hxx>

void bind_ShapePersistent_BRep(py::module &mod){

/*
py::class_<ShapePersistent_BRep> cls_ShapePersistent_BRep(mod, "ShapePersistent_BRep", "None");

// Constructors

// Fields

// Methods
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<TVertex::pTObjectT> (*)(const TopoDS_Vertex &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a vertex", py::arg("theVertex"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<TEdge::pTObjectT> (*)(const TopoDS_Edge &, StdObjMgt_TransientPersistentMap &, ShapePersistent_TriangleMode)) &ShapePersistent_BRep::Translate, "Create a persistent object for an edge", py::arg("theEdge"), py::arg("theMap"), py::arg("theTriangleMode"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<TFace::pTObjectT> (*)(const TopoDS_Face &, StdObjMgt_TransientPersistentMap &, ShapePersistent_TriangleMode)) &ShapePersistent_BRep::Translate, "Create a persistent object for a face", py::arg("theFace"), py::arg("theMap"), py::arg("theTriangleMode"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PointOnCurve> (*)(Standard_Real, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a point on a 3D curve", py::arg("theParam"), py::arg("theCurve"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PointOnCurveOnSurface> (*)(Standard_Real, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a point on a 3D curve on a surface", py::arg("theParam"), py::arg("theCurve"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PointOnSurface> (*)(Standard_Real, Standard_Real, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a point on a surface", py::arg("theParam"), py::arg("theParam2"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<CurveOnSurface> (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a curve on a surface", py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<CurveOnClosedSurface> (*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const GeomAbs_Shape, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a curve on a closed surface", py::arg("theCurve"), py::arg("theCurve2"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theContinuity"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<CurveOn2Surfaces> (*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &, const GeomAbs_Shape, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a curve on two surfaces", py::arg("theSurf"), py::arg("theSurf2"), py::arg("theLoc"), py::arg("theLoc2"), py::arg("theContinuity"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<Curve3D> (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a 3D curve", py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<Polygon3D> (*)(const opencascade::handle<Poly_Polygon3D> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a 3D polygon", py::arg("thePoly"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PolygonOnClosedSurface> (*)(const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a polygon on a closed surface", py::arg("thePoly"), py::arg("thePoly2"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PolygonOnSurface> (*)(const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a polygon on a surface", py::arg("thePoly"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PolygonOnClosedTriangulation> (*)(const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a polygon on a surface", py::arg("thePolyOnTriang"), py::arg("thePolyOnTriang2"), py::arg("thePolyTriang"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PolygonOnTriangulation> (*)(const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a polygon on a surface", py::arg("thePolyOnTriang"), py::arg("thePolyTriang"), py::arg("theLoc"), py::arg("theMap"));

// Enums
*/

}