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

void bind_BRep_Builder(py::module &);
void bind_BRep_TFace(py::module &);
void bind_BRep_PointRepresentation(py::module &);
void bind_BRep_ListOfPointRepresentation(py::module &);
void bind_BRep_ListIteratorOfListOfPointRepresentation(py::module &);
void bind_BRep_TVertex(py::module &);
void bind_BRep_Tool(py::module &);
void bind_BRep_CurveRepresentation(py::module &);
void bind_BRep_GCurve(py::module &);
void bind_BRep_Curve3D(py::module &);
void bind_BRep_CurveOn2Surfaces(py::module &);
void bind_BRep_CurveOnSurface(py::module &);
void bind_BRep_CurveOnClosedSurface(py::module &);
void bind_BRep_ListOfCurveRepresentation(py::module &);
void bind_BRep_ListIteratorOfListOfCurveRepresentation(py::module &);
void bind_BRep_PointOnCurve(py::module &);
void bind_BRep_PointsOnSurface(py::module &);
void bind_BRep_PointOnCurveOnSurface(py::module &);
void bind_BRep_PointOnSurface(py::module &);
void bind_BRep_Polygon3D(py::module &);
void bind_BRep_PolygonOnSurface(py::module &);
void bind_BRep_PolygonOnClosedSurface(py::module &);
void bind_BRep_PolygonOnTriangulation(py::module &);
void bind_BRep_PolygonOnClosedTriangulation(py::module &);
void bind_BRep_TEdge(py::module &);

PYBIND11_MODULE(BRep, mod) {

py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopAbs");

bind_BRep_Builder(mod);
bind_BRep_TFace(mod);
bind_BRep_PointRepresentation(mod);
bind_BRep_ListOfPointRepresentation(mod);
bind_BRep_ListIteratorOfListOfPointRepresentation(mod);
bind_BRep_TVertex(mod);
bind_BRep_Tool(mod);
bind_BRep_CurveRepresentation(mod);
bind_BRep_GCurve(mod);
bind_BRep_Curve3D(mod);
bind_BRep_CurveOn2Surfaces(mod);
bind_BRep_CurveOnSurface(mod);
bind_BRep_CurveOnClosedSurface(mod);
bind_BRep_ListOfCurveRepresentation(mod);
bind_BRep_ListIteratorOfListOfCurveRepresentation(mod);
bind_BRep_PointOnCurve(mod);
bind_BRep_PointsOnSurface(mod);
bind_BRep_PointOnCurveOnSurface(mod);
bind_BRep_PointOnSurface(mod);
bind_BRep_Polygon3D(mod);
bind_BRep_PolygonOnSurface(mod);
bind_BRep_PolygonOnClosedSurface(mod);
bind_BRep_PolygonOnTriangulation(mod);
bind_BRep_PolygonOnClosedTriangulation(mod);
bind_BRep_TEdge(mod);

}
