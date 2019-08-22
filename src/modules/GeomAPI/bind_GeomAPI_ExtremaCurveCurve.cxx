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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtCC.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomAPI_ExtremaCurveCurve.hxx>

void bind_GeomAPI_ExtremaCurveCurve(py::module &mod){

py::class_<GeomAPI_ExtremaCurveCurve> cls_GeomAPI_ExtremaCurveCurve(mod, "GeomAPI_ExtremaCurveCurve", "Describes functions for computing all the extrema between two 3D curves. An ExtremaCurveCurve algorithm minimizes or maximizes the distance between a point on the first curve and a point on the second curve. Thus, it computes start and end points of perpendiculars common to the two curves (an intersection point is not an extremum unless the two curves are tangential at this point). Solutions consist of pairs of points, and an extremum is considered to be a segment joining the two points of a solution. An ExtremaCurveCurve object provides a framework for: - defining the construction of the extrema, - implementing the construction algorithm, and - consulting the results. Warning In some cases, the nearest points between two curves do not correspond to one of the computed extrema. Instead, they may be given by: - a limit point of one curve and one of the following: - its orthogonal projection on the other curve, - a limit point of the other curve; or - an intersection point between the two curves.");

// Constructors
cls_GeomAPI_ExtremaCurveCurve.def(py::init<>());
cls_GeomAPI_ExtremaCurveCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("C1"), py::arg("C2"));
cls_GeomAPI_ExtremaCurveCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U1min"), py::arg("U1max"), py::arg("U2min"), py::arg("U2max"));

// Fields

// Methods
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ExtremaCurveCurve::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ExtremaCurveCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ExtremaCurveCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ExtremaCurveCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ExtremaCurveCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ExtremaCurveCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ExtremaCurveCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ExtremaCurveCurve.def("Init", (void (GeomAPI_ExtremaCurveCurve::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomAPI_ExtremaCurveCurve::Init, "Initializes this algorithm with the given arguments and computes the extrema between the curves C1 and C2", py::arg("C1"), py::arg("C2"));
cls_GeomAPI_ExtremaCurveCurve.def("Init", (void (GeomAPI_ExtremaCurveCurve::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomAPI_ExtremaCurveCurve::Init, "Initializes this algorithm with the given arguments and computes the extrema between : - the portion of the curve C1 limited by the two points of parameter (U1min,U1max), and - the portion of the curve C2 limited by the two points of parameter (U2min,U2max). Warning Use the function NbExtrema to obtain the number of solutions. If this algorithm fails, NbExtrema returns 0.", py::arg("C1"), py::arg("C2"), py::arg("U1min"), py::arg("U1max"), py::arg("U2min"), py::arg("U2max"));
cls_GeomAPI_ExtremaCurveCurve.def("NbExtrema", (Standard_Integer (GeomAPI_ExtremaCurveCurve::*)() const) &GeomAPI_ExtremaCurveCurve::NbExtrema, "Returns the number of extrema computed by this algorithm. Note: if this algorithm fails, NbExtrema returns 0.");
cls_GeomAPI_ExtremaCurveCurve.def("Points", (void (GeomAPI_ExtremaCurveCurve::*)(const Standard_Integer, gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaCurveCurve::Points, "Returns the points P1 on the first curve and P2 on the second curve, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaCurveCurve.def("Parameters", [](GeomAPI_ExtremaCurveCurve &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & U2){ self.Parameters(Index, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "Returns the parameters U1 of the point on the first curve and U2 of the point on the second curve, which are the ends of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"), py::arg("U1"), py::arg("U2"));
cls_GeomAPI_ExtremaCurveCurve.def("Distance", (Standard_Real (GeomAPI_ExtremaCurveCurve::*)(const Standard_Integer) const) &GeomAPI_ExtremaCurveCurve::Distance, "Computes the distance between the end points of the extremum of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbExtrema ], where NbExtrema is the number of extrema computed by this algorithm.", py::arg("Index"));
cls_GeomAPI_ExtremaCurveCurve.def("NearestPoints", (void (GeomAPI_ExtremaCurveCurve::*)(gp_Pnt &, gp_Pnt &) const) &GeomAPI_ExtremaCurveCurve::NearestPoints, "Returns the points P1 on the first curve and P2 on the second curve, which are the ends of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.", py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaCurveCurve.def("LowerDistanceParameters", [](GeomAPI_ExtremaCurveCurve &self, Standard_Real & U1, Standard_Real & U2){ self.LowerDistanceParameters(U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "Returns the parameters U1 of the point on the first curve and U2 of the point on the second curve, which are the ends of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.", py::arg("U1"), py::arg("U2"));
cls_GeomAPI_ExtremaCurveCurve.def("LowerDistance", (Standard_Real (GeomAPI_ExtremaCurveCurve::*)() const) &GeomAPI_ExtremaCurveCurve::LowerDistance, "Computes the distance between the end points of the shortest extremum computed by this algorithm. Exceptions StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ExtremaCurveCurve.def("Extrema", (const Extrema_ExtCC & (GeomAPI_ExtremaCurveCurve::*)() const) &GeomAPI_ExtremaCurveCurve::Extrema, "return the algorithmic object from Extrema");
cls_GeomAPI_ExtremaCurveCurve.def("TotalNearestPoints", (Standard_Boolean (GeomAPI_ExtremaCurveCurve::*)(gp_Pnt &, gp_Pnt &)) &GeomAPI_ExtremaCurveCurve::TotalNearestPoints, "set in <P1> and <P2> the couple solution points such a the distance [P1,P2] is the minimum. taking in account extremity points of curves.", py::arg("P1"), py::arg("P2"));
cls_GeomAPI_ExtremaCurveCurve.def("TotalLowerDistanceParameters", [](GeomAPI_ExtremaCurveCurve &self, Standard_Real & U1, Standard_Real & U2){ Standard_Boolean rv = self.TotalLowerDistanceParameters(U1, U2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, U1, U2); }, "set in <U1> and <U2> the parameters of the couple solution points which represents the total nearest solution.", py::arg("U1"), py::arg("U2"));
cls_GeomAPI_ExtremaCurveCurve.def("TotalLowerDistance", (Standard_Real (GeomAPI_ExtremaCurveCurve::*)()) &GeomAPI_ExtremaCurveCurve::TotalLowerDistance, "return the distance of the total nearest couple solution point. if <myExtCC> is not done");

// Enums

}