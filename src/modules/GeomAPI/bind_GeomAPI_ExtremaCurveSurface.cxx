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
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtCS.hxx>
#include <GeomAPI_ExtremaCurveSurface.hxx>

void bind_GeomAPI_ExtremaCurveSurface(py::module &mod){

py::class_<GeomAPI_ExtremaCurveSurface, std::unique_ptr<GeomAPI_ExtremaCurveSurface, Deleter<GeomAPI_ExtremaCurveSurface>>> cls_GeomAPI_ExtremaCurveSurface(mod, "GeomAPI_ExtremaCurveSurface", "Describes functions for computing all the extrema between a curve and a surface. An ExtremaCurveSurface algorithm minimizes or maximizes the distance between a point on the curve and a point on the surface. Thus, it computes start and end points of perpendiculars common to the curve and the surface (an intersection point is not an extremum except where the curve and the surface are tangential at this point). Solutions consist of pairs of points, and an extremum is considered to be a segment joining the two points of a solution. An ExtremaCurveSurface object provides a framework for: - defining the construction of the extrema, - implementing the construction algorithm, and - consulting the results. Warning In some cases, the nearest points between a curve and a surface do not correspond to one of the computed extrema. Instead, they may be given by: - a point of a bounding curve of the surface and one of the following: - its orthogonal projection on the curve, - a limit point of the curve; or - a limit point of the curve and its projection on the surface; or - an intersection point between the curve and the surface.");

// Constructors
cls_GeomAPI_ExtremaCurveSurface.def(py::init<>());
cls_GeomAPI_ExtremaCurveSurface.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("Curve"), py::arg("Surface"));
cls_GeomAPI_ExtremaCurveSurface.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curve"), py::arg("Surface"), py::arg("Wmin"), py::arg("Wmax"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));

// Fields

// Methods
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ExtremaCurveSurface::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ExtremaCurveSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ExtremaCurveSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ExtremaCurveSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ExtremaCurveSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ExtremaCurveSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ExtremaCurveSurface.def("Init", (void (GeomAPI_ExtremaCurveSurface::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &)) &GeomAPI_ExtremaCurveSurface::Init, "Computes the extrema distances between the curve <C> and the surface <S>.", py::arg("Curve"), py::arg("Surface"));
cls_GeomAPI_ExtremaCurveSurface.def("Init", (void (GeomAPI_ExtremaCurveSurface::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomAPI_ExtremaCurveSurface::Init, "Computes the extrema distances between the curve <C> and the surface <S>. The solution point are computed in the domain [Wmin,Wmax] of the curve and in the domain [Umin,Umax] [Vmin,Vmax] of the surface. Warning Use the function NbExtrema to obtain the number of solutions. If this algorithm fails, NbExtrema returns 0.", py::arg("Curve"), py::arg("Surface"), py::arg("Wmin"), py::arg("Wmax"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_GeomAPI_ExtremaCurveSurface.def("NbExtrema", (Standard_Integer (GeomAPI_ExtremaCurveSurface::*)() const) &GeomAPI_ExtremaCurveSurface::NbExtrema, "Returns the number of extrema computed by this algorithm. Note: if this algorithm fails, NbExtrema returns 0.");
cls_GeomAPI_ExtremaCurveSurface.def("Points", (void (GeomAPI_ExtremaCurveSurface::*)(const Standard_Integer, gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaCurveSurface::Points, "Returns the points P1 on the curve and P2 on the surface, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaCurveSurface.def("Parameters", [](GeomAPI_ExtremaCurveSurface &self, const Standard_Integer Index, Standard_Real & W, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, W, U, V); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W, U, V); }, "Returns the parameters W of the point on the curve, and (U,V) of the point on the surface, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("W"), py::arg("U"), py::arg("V"));
cls_GeomAPI_ExtremaCurveSurface.def("Distance", (Standard_Real (GeomAPI_ExtremaCurveSurface::*)(const Standard_Integer) const) &GeomAPI_ExtremaCurveSurface::Distance, "Computes the distance between the end points of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"));
cls_GeomAPI_ExtremaCurveSurface.def("NearestPoints", (void (GeomAPI_ExtremaCurveSurface::*)(gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaCurveSurface::NearestPoints, "Returns the points PC on the curve and PS on the surface, which are the ends of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.", py::arg("PC"), py::arg("PS"));
cls_GeomAPI_ExtremaCurveSurface.def("LowerDistanceParameters", [](GeomAPI_ExtremaCurveSurface &self, Standard_Real & W, Standard_Real & U, Standard_Real & V){ self.LowerDistanceParameters(W, U, V); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W, U, V); }, "Returns the parameters W of the point on the curve and (U,V) of the point on the surface, which are the ends of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.", py::arg("W"), py::arg("U"), py::arg("V"));
cls_GeomAPI_ExtremaCurveSurface.def("LowerDistance", (Standard_Real (GeomAPI_ExtremaCurveSurface::*)() const) &GeomAPI_ExtremaCurveSurface::LowerDistance, "Computes the distance between the end points of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ExtremaCurveSurface.def("Extrema", (const Extrema_ExtCS & (GeomAPI_ExtremaCurveSurface::*)() const) &GeomAPI_ExtremaCurveSurface::Extrema, "Returns the algorithmic object from Extrema");

// Enums

}