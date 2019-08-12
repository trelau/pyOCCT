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
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Extrema_ExtCC2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Geom2dAPI_ExtremaCurveCurve.hxx>

void bind_Geom2dAPI_ExtremaCurveCurve(py::module &mod){

py::class_<Geom2dAPI_ExtremaCurveCurve, std::unique_ptr<Geom2dAPI_ExtremaCurveCurve, Deleter<Geom2dAPI_ExtremaCurveCurve>>> cls_Geom2dAPI_ExtremaCurveCurve(mod, "Geom2dAPI_ExtremaCurveCurve", "Describes functions for computing all the extrema between two 2D curves. An ExtremaCurveCurve algorithm minimizes or maximizes the distance between a point on the first curve and a point on the second curve. Thus, it computes the start point and end point of perpendiculars common to the two curves (an intersection point is not an extremum except where the two curves are tangential at this point). Solutions consist of pairs of points, and an extremum is considered to be a segment joining the two points of a solution. An ExtremaCurveCurve object provides a framework for: - defining the construction of the extrema, - implementing the construction algorithm, and - consulting the results. Warning In some cases, the nearest points between two curves do not correspond to one of the computed extrema. Instead, they may be given by: - a limit point of one curve and one of the following: - its orthogonal projection on the other curve, - a limit point of the other curve; or - an intersection point between the two curves.");

// Constructors
cls_Geom2dAPI_ExtremaCurveCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1min"), py::arg("U1max"), py::arg("U2min"), py::arg("U2max"));

// Fields

// Methods
// cls_Geom2dAPI_ExtremaCurveCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dAPI_ExtremaCurveCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dAPI_ExtremaCurveCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dAPI_ExtremaCurveCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dAPI_ExtremaCurveCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dAPI_ExtremaCurveCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dAPI_ExtremaCurveCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dAPI_ExtremaCurveCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dAPI_ExtremaCurveCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dAPI_ExtremaCurveCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dAPI_ExtremaCurveCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dAPI_ExtremaCurveCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dAPI_ExtremaCurveCurve.def("NbExtrema", (Standard_Integer (Geom2dAPI_ExtremaCurveCurve::*)() const) &Geom2dAPI_ExtremaCurveCurve::NbExtrema, "Returns the number of extrema computed by this algorithm. Note: if this algorithm fails, NbExtrema returns 0.");
cls_Geom2dAPI_ExtremaCurveCurve.def("Points", (void (Geom2dAPI_ExtremaCurveCurve::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const) &Geom2dAPI_ExtremaCurveCurve::Points, "Returns the points P1 on the first curve and P2 on the second curve, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("P1"), py::arg("P2"));
cls_Geom2dAPI_ExtremaCurveCurve.def("Parameters", [](Geom2dAPI_ExtremaCurveCurve &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & U2){ self.Parameters(Index, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "Returns the parameters U1 of the point on the first curve and U2 of the point on the second curve, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("U1"), py::arg("U2"));
cls_Geom2dAPI_ExtremaCurveCurve.def("Distance", (Standard_Real (Geom2dAPI_ExtremaCurveCurve::*)(const Standard_Integer) const) &Geom2dAPI_ExtremaCurveCurve::Distance, "Computes the distance between the end points of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"));
cls_Geom2dAPI_ExtremaCurveCurve.def("NearestPoints", (void (Geom2dAPI_ExtremaCurveCurve::*)(gp_Pnt2d &, gp_Pnt2d &) const) &Geom2dAPI_ExtremaCurveCurve::NearestPoints, "Returns the points P1 on the first curve and P2 on the second curve, which are the ends of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.", py::arg("P1"), py::arg("P2"));
cls_Geom2dAPI_ExtremaCurveCurve.def("LowerDistanceParameters", [](Geom2dAPI_ExtremaCurveCurve &self, Standard_Real & U1, Standard_Real & U2){ self.LowerDistanceParameters(U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "Returns the parameters U1 of the point on the first curve and U2 of the point on the second curve, which are the ends of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.", py::arg("U1"), py::arg("U2"));
cls_Geom2dAPI_ExtremaCurveCurve.def("LowerDistance", (Standard_Real (Geom2dAPI_ExtremaCurveCurve::*)() const) &Geom2dAPI_ExtremaCurveCurve::LowerDistance, "Computes the distance between the end points of the shortest extremum computed by this algorithm. Exceptions - StdFail_NotDone if this algorithm fails.");
cls_Geom2dAPI_ExtremaCurveCurve.def("Extrema", (const Extrema_ExtCC2d & (Geom2dAPI_ExtremaCurveCurve::*)() const) &Geom2dAPI_ExtremaCurveCurve::Extrema, "None");

// Enums

}