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
#include <TopoDS_Builder.hxx>
#include <Standard.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>
#include <Poly_Triangulation.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <Poly_Polygon2D.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <BRep_Builder.hxx>

void bind_BRep_Builder(py::module &mod){

py::class_<BRep_Builder, TopoDS_Builder> cls_BRep_Builder(mod, "BRep_Builder", "A framework providing advanced tolerance control. It is used to build Shapes. If tolerance control is required, you are advised to: 1. build a default precision for topology, using the classes provided in the BRepAPI package 2. update the tolerance of the resulting shape. Note that only vertices, edges and faces have meaningful tolerance control. The tolerance value must always comply with the condition that face tolerances are more restrictive than edge tolerances which are more restrictive than vertex tolerances. In other words: Tol(Vertex) >= Tol(Edge) >= Tol(Face). Other rules in setting tolerance include: - you can open up tolerance but should never restrict it - an edge cannot be included within the fusion of the tolerance spheres of two vertices");

// Constructors

// Fields

// Methods
// cls_BRep_Builder.def_static("operator new_", (void * (*)(size_t)) &BRep_Builder::operator new, "None", py::arg("theSize"));
// cls_BRep_Builder.def_static("operator delete_", (void (*)(void *)) &BRep_Builder::operator delete, "None", py::arg("theAddress"));
// cls_BRep_Builder.def_static("operator new[]_", (void * (*)(size_t)) &BRep_Builder::operator new[], "None", py::arg("theSize"));
// cls_BRep_Builder.def_static("operator delete[]_", (void (*)(void *)) &BRep_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_BRep_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &BRep_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRep_Builder.def_static("operator delete_", (void (*)(void *, void *)) &BRep_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRep_Builder.def("MakeFace", (void (BRep_Builder::*)(TopoDS_Face &) const) &BRep_Builder::MakeFace, "Makes an undefined Face.", py::arg("F"));
cls_BRep_Builder.def("MakeFace", (void (BRep_Builder::*)(TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const Standard_Real) const) &BRep_Builder::MakeFace, "Makes a Face with a surface.", py::arg("F"), py::arg("S"), py::arg("Tol"));
cls_BRep_Builder.def("MakeFace", (void (BRep_Builder::*)(TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const) &BRep_Builder::MakeFace, "Makes a Face with a surface and a location.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"));
cls_BRep_Builder.def("MakeFace", (void (BRep_Builder::*)(TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &) const) &BRep_Builder::MakeFace, "Makes a Face with a triangulation. The triangulation is in the same reference system than the TFace.", py::arg("F"), py::arg("T"));
cls_BRep_Builder.def("UpdateFace", (void (BRep_Builder::*)(const TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const) &BRep_Builder::UpdateFace, "Updates the face F using the tolerance value Tol, surface S and location Location.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateFace", (void (BRep_Builder::*)(const TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &) const) &BRep_Builder::UpdateFace, "Changes a face triangulation.", py::arg("F"), py::arg("T"));
cls_BRep_Builder.def("UpdateFace", (void (BRep_Builder::*)(const TopoDS_Face &, const Standard_Real) const) &BRep_Builder::UpdateFace, "Updates the face Tolerance.", py::arg("F"), py::arg("Tol"));
cls_BRep_Builder.def("NaturalRestriction", (void (BRep_Builder::*)(const TopoDS_Face &, const Standard_Boolean) const) &BRep_Builder::NaturalRestriction, "Sets the NaturalRestriction flag of the face.", py::arg("F"), py::arg("N"));
cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &) const) &BRep_Builder::MakeEdge, "Makes an undefined Edge (no geometry).", py::arg("E"));
cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const) &BRep_Builder::MakeEdge, "Makes an Edge with a curve.", py::arg("E"), py::arg("C"), py::arg("Tol"));
cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &, const Standard_Real) const) &BRep_Builder::MakeEdge, "Makes an Edge with a curve and a location.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Poly_Polygon3D> &) const) &BRep_Builder::MakeEdge, "Makes an Edge with a polygon 3d.", py::arg("E"), py::arg("P"));
cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &) const) &BRep_Builder::MakeEdge, "makes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N"), py::arg("T"));
cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const) &BRep_Builder::MakeEdge, "makes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N"), py::arg("T"), py::arg("L"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const) &BRep_Builder::UpdateEdge, "Sets a 3D curve for the edge. If <C> is a null handle, remove any existing 3d curve.", py::arg("E"), py::arg("C"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &, const Standard_Real) const) &BRep_Builder::UpdateEdge, "Sets a 3D curve for the edge. If <C> is a null handle, remove any existing 3d curve.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &, const Standard_Real) const) &BRep_Builder::UpdateEdge, "Sets a pcurve for the edge on the face. If <C> is a null handle, remove any existing pcurve.", py::arg("E"), py::arg("C"), py::arg("F"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &, const Standard_Real) const) &BRep_Builder::UpdateEdge, "Sets pcurves for the edge on the closed face. If <C1> or <C2> is a null handle, remove any existing pcurve.", py::arg("E"), py::arg("C1"), py::arg("C2"), py::arg("F"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const) &BRep_Builder::UpdateEdge, "Sets a pcurve for the edge on the face. If <C> is a null handle, remove any existing pcurve.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &) const) &BRep_Builder::UpdateEdge, "Sets a pcurve for the edge on the face. If <C> is a null handle, remove any existing pcurve. Sets UV bounds for curve repsentation", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("Pf"), py::arg("Pl"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const) &BRep_Builder::UpdateEdge, "Sets pcurves for the edge on the closed surface. <C1> or <C2> is a null handle, remove any existing pcurve.", py::arg("E"), py::arg("C1"), py::arg("C2"), py::arg("S"), py::arg("L"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &) const) &BRep_Builder::UpdateEdge, "Sets pcurves for the edge on the closed surface. <C1> or <C2> is a null handle, remove any existing pcurve. Sets UV bounds for curve repsentation", py::arg("E"), py::arg("C1"), py::arg("C2"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("Pf"), py::arg("Pl"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon3D> &) const) &BRep_Builder::UpdateEdge, "Changes an Edge 3D polygon. A null Polygon removes the 3d Polygon.", py::arg("E"), py::arg("P"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon3D> &, const TopLoc_Location &) const) &BRep_Builder::UpdateEdge, "Changes an Edge 3D polygon. A null Polygon removes the 3d Polygon.", py::arg("E"), py::arg("P"), py::arg("L"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &) const) &BRep_Builder::UpdateEdge, "Changes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N"), py::arg("T"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const) &BRep_Builder::UpdateEdge, "Changes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N"), py::arg("T"), py::arg("L"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &) const) &BRep_Builder::UpdateEdge, "Changes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N1"), py::arg("N2"), py::arg("T"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const) &BRep_Builder::UpdateEdge, "Changes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N1"), py::arg("N2"), py::arg("T"), py::arg("L"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon2D> &, const TopoDS_Face &) const) &BRep_Builder::UpdateEdge, "Changes Edge polygon on a face.", py::arg("E"), py::arg("P"), py::arg("S"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_Builder::UpdateEdge, "Changes Edge polygon on a face.", py::arg("E"), py::arg("P"), py::arg("S"), py::arg("T"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Poly_Polygon2D> &, const TopoDS_Face &) const) &BRep_Builder::UpdateEdge, "Changes Edge polygons on a face.", py::arg("E"), py::arg("P1"), py::arg("P2"), py::arg("S"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_Builder::UpdateEdge, "Changes Edge polygons on a face.", py::arg("E"), py::arg("P1"), py::arg("P2"), py::arg("S"), py::arg("L"));
cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Real) const) &BRep_Builder::UpdateEdge, "Updates the edge tolerance.", py::arg("E"), py::arg("Tol"));
cls_BRep_Builder.def("Continuity", (void (BRep_Builder::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const GeomAbs_Shape) const) &BRep_Builder::Continuity, "Sets the geometric continuity on the edge.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("C"));
cls_BRep_Builder.def("Continuity", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &, const GeomAbs_Shape) const) &BRep_Builder::Continuity, "Sets the geometric continuity on the edge.", py::arg("E"), py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"), py::arg("C"));
cls_BRep_Builder.def("SameParameter", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Boolean) const) &BRep_Builder::SameParameter, "Sets the same parameter flag for the edge <E>.", py::arg("E"), py::arg("S"));
cls_BRep_Builder.def("SameRange", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Boolean) const) &BRep_Builder::SameRange, "Sets the same range flag for the edge <E>.", py::arg("E"), py::arg("S"));
cls_BRep_Builder.def("Degenerated", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Boolean) const) &BRep_Builder::Degenerated, "Sets the degenerated flag for the edge <E>.", py::arg("E"), py::arg("D"));
cls_BRep_Builder.def("Range", [](BRep_Builder &self, const TopoDS_Edge & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Range(a0, a1, a2); });
cls_BRep_Builder.def("Range", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Boolean) const) &BRep_Builder::Range, "Sets the range of the 3d curve if Only3d=TRUE, otherwise sets the range to all the representations", py::arg("E"), py::arg("First"), py::arg("Last"), py::arg("Only3d"));
cls_BRep_Builder.def("Range", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real, const Standard_Real) const) &BRep_Builder::Range, "Sets the range of the edge on the pcurve on the surface.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
cls_BRep_Builder.def("Range", (void (BRep_Builder::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Real) const) &BRep_Builder::Range, "Sets the range of the edge on the pcurve on the face.", py::arg("E"), py::arg("F"), py::arg("First"), py::arg("Last"));
cls_BRep_Builder.def("Transfert", (void (BRep_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &) const) &BRep_Builder::Transfert, "Add to <Eout> the geometric representations of <Ein>.", py::arg("Ein"), py::arg("Eout"));
cls_BRep_Builder.def("MakeVertex", (void (BRep_Builder::*)(TopoDS_Vertex &) const) &BRep_Builder::MakeVertex, "Makes an udefined vertex without geometry.", py::arg("V"));
cls_BRep_Builder.def("MakeVertex", (void (BRep_Builder::*)(TopoDS_Vertex &, const gp_Pnt &, const Standard_Real) const) &BRep_Builder::MakeVertex, "Makes a vertex from a 3D point.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const gp_Pnt &, const Standard_Real) const) &BRep_Builder::UpdateVertex, "Sets a 3D point on the vertex.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &, const Standard_Real) const) &BRep_Builder::UpdateVertex, "Sets the parameter for the vertex on the edge curves.", py::arg("V"), py::arg("P"), py::arg("E"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real) const) &BRep_Builder::UpdateVertex, "Sets the parameter for the vertex on the edge pcurve on the face.", py::arg("V"), py::arg("P"), py::arg("E"), py::arg("F"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const) &BRep_Builder::UpdateVertex, "Sets the parameter for the vertex on the edge pcurve on the surface.", py::arg("V"), py::arg("P"), py::arg("E"), py::arg("S"), py::arg("L"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real, const Standard_Real, const TopoDS_Face &, const Standard_Real) const) &BRep_Builder::UpdateVertex, "Sets the parameters for the vertex on the face.", py::arg("Ve"), py::arg("U"), py::arg("V"), py::arg("F"), py::arg("Tol"));
cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real) const) &BRep_Builder::UpdateVertex, "Updates the vertex tolerance.", py::arg("V"), py::arg("Tol"));
cls_BRep_Builder.def("Transfert", (void (BRep_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Vertex &, const TopoDS_Vertex &) const) &BRep_Builder::Transfert, "Transfert the parameters of Vin on Ein as the parameter of Vout on Eout.", py::arg("Ein"), py::arg("Eout"), py::arg("Vin"), py::arg("Vout"));

// Enums

}