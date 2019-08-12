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
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtSS.hxx>
#include <GeomAPI_ExtremaSurfaceSurface.hxx>

void bind_GeomAPI_ExtremaSurfaceSurface(py::module &mod){

py::class_<GeomAPI_ExtremaSurfaceSurface, std::unique_ptr<GeomAPI_ExtremaSurfaceSurface, Deleter<GeomAPI_ExtremaSurfaceSurface>>> cls_GeomAPI_ExtremaSurfaceSurface(mod, "GeomAPI_ExtremaSurfaceSurface", "Describes functions for computing all the extrema between two surfaces. An ExtremaSurfaceSurface algorithm minimizes or maximizes the distance between a point on the first surface and a point on the second surface. Results are start and end points of perpendiculars common to the two surfaces. Solutions consist of pairs of points, and an extremum is considered to be a segment joining the two points of a solution. An ExtremaSurfaceSurface object provides a framework for: - defining the construction of the extrema, - implementing the construction algorithm, and - consulting the results. Warning In some cases, the nearest points between the two surfaces do not correspond to one of the computed extrema. Instead, they may be given by: - a point of a bounding curve of one surface and one of the following: - its orthogonal projection on the other surface, - a point of a bounding curve of the other surface; or - any point on intersection curves between the two surfaces.");

// Constructors
cls_GeomAPI_ExtremaSurfaceSurface.def(py::init<>());
cls_GeomAPI_ExtremaSurfaceSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("S1"), py::arg("S2"));
cls_GeomAPI_ExtremaSurfaceSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("U1min"), py::arg("U1max"), py::arg("V1min"), py::arg("V1max"), py::arg("U2min"), py::arg("U2max"), py::arg("V2min"), py::arg("V2max"));

// Fields

// Methods
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ExtremaSurfaceSurface::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ExtremaSurfaceSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ExtremaSurfaceSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ExtremaSurfaceSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ExtremaSurfaceSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ExtremaSurfaceSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ExtremaSurfaceSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ExtremaSurfaceSurface.def("Init", (void (GeomAPI_ExtremaSurfaceSurface::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &)) &GeomAPI_ExtremaSurfaceSurface::Init, "Initializes this algorithm with the given arguments and computes the extrema distances between the surfaces <S1> and <S2>", py::arg("S1"), py::arg("S2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("Init", (void (GeomAPI_ExtremaSurfaceSurface::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomAPI_ExtremaSurfaceSurface::Init, "Initializes this algorithm with the given arguments and computes the extrema distances between - the portion of the surface S1 limited by the two values of parameter (U1min,U1max) in the u parametric direction, and by the two values of parameter (V1min,V1max) in the v parametric direction, and - the portion of the surface S2 limited by the two values of parameter (U2min,U2max) in the u parametric direction, and by the two values of parameter (V2min,V2max) in the v parametric direction.", py::arg("S1"), py::arg("S2"), py::arg("U1min"), py::arg("U1max"), py::arg("V1min"), py::arg("V1max"), py::arg("U2min"), py::arg("U2max"), py::arg("V2min"), py::arg("V2max"));
cls_GeomAPI_ExtremaSurfaceSurface.def("NbExtrema", (Standard_Integer (GeomAPI_ExtremaSurfaceSurface::*)() const) &GeomAPI_ExtremaSurfaceSurface::NbExtrema, "Returns the number of extrema computed by this algorithm. Note: if this algorithm fails, NbExtrema returns 0.");
cls_GeomAPI_ExtremaSurfaceSurface.def("Points", (void (GeomAPI_ExtremaSurfaceSurface::*)(const Standard_Integer, gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaSurfaceSurface::Points, "Returns the points P1 on the first surface and P2 on the second surface, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("Parameters", [](GeomAPI_ExtremaSurfaceSurface &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.Parameters(Index, U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters (U1,V1) of the point on the first surface, and (U2,V2) of the point on the second surface, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("Distance", (Standard_Real (GeomAPI_ExtremaSurfaceSurface::*)(const Standard_Integer) const) &GeomAPI_ExtremaSurfaceSurface::Distance, "Computes the distance between the end points of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"));
cls_GeomAPI_ExtremaSurfaceSurface.def("NearestPoints", (void (GeomAPI_ExtremaSurfaceSurface::*)(gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaSurfaceSurface::NearestPoints, "Returns the points P1 on the first surface and P2 on the second surface, which are the ends of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.", py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("LowerDistanceParameters", [](GeomAPI_ExtremaSurfaceSurface &self, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.LowerDistanceParameters(U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters (U1,V1) of the point on the first surface and (U2,V2) of the point on the second surface, which are the ends of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_GeomAPI_ExtremaSurfaceSurface.def("LowerDistance", (Standard_Real (GeomAPI_ExtremaSurfaceSurface::*)() const) &GeomAPI_ExtremaSurfaceSurface::LowerDistance, "Computes the distance between the end points of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ExtremaSurfaceSurface.def("Extrema", (const Extrema_ExtSS & (GeomAPI_ExtremaSurfaceSurface::*)() const) &GeomAPI_ExtremaSurfaceSurface::Extrema, "return the algorithmic object from Extrema");

// Enums

}