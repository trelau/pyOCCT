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
#include <Geom2dInt_GInter.hxx>
#include <Geom2dAPI_InterCurveCurve.hxx>

void bind_Geom2dAPI_InterCurveCurve(py::module &mod){

py::class_<Geom2dAPI_InterCurveCurve, std::unique_ptr<Geom2dAPI_InterCurveCurve>> cls_Geom2dAPI_InterCurveCurve(mod, "Geom2dAPI_InterCurveCurve", "This class implements methods for computing - the intersections between two 2D curves, - the self-intersections of a 2D curve. Using the InterCurveCurve algorithm allows to get the following results: - intersection points in the case of cross intersections, - intersection segments in the case of tangential intersections, - nothing in the case of no intersections.");

// Constructors
cls_Geom2dAPI_InterCurveCurve.def(py::init<>());
cls_Geom2dAPI_InterCurveCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &>(), py::arg("C1"), py::arg("C2"));
cls_Geom2dAPI_InterCurveCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));
cls_Geom2dAPI_InterCurveCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("C1"));
cls_Geom2dAPI_InterCurveCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("C1"), py::arg("Tol"));

// Fields

// Methods
// cls_Geom2dAPI_InterCurveCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dAPI_InterCurveCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dAPI_InterCurveCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dAPI_InterCurveCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dAPI_InterCurveCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dAPI_InterCurveCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dAPI_InterCurveCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dAPI_InterCurveCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dAPI_InterCurveCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dAPI_InterCurveCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dAPI_InterCurveCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dAPI_InterCurveCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dAPI_InterCurveCurve.def("Init", [](Geom2dAPI_InterCurveCurve &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Curve> & a1) -> void { return self.Init(a0, a1); });
cls_Geom2dAPI_InterCurveCurve.def("Init", (void (Geom2dAPI_InterCurveCurve::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real)) &Geom2dAPI_InterCurveCurve::Init, "Initializes an algorithm with the given arguments and computes the intersections between the curves C1. and C2.", py::arg("C1"), py::arg("C2"), py::arg("Tol"));
cls_Geom2dAPI_InterCurveCurve.def("Init", [](Geom2dAPI_InterCurveCurve &self, const opencascade::handle<Geom2d_Curve> & a0) -> void { return self.Init(a0); });
cls_Geom2dAPI_InterCurveCurve.def("Init", (void (Geom2dAPI_InterCurveCurve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real)) &Geom2dAPI_InterCurveCurve::Init, "Initializes an algorithm with the given arguments and computes the self-intersections of the curve C1. Tolerance value Tol, defaulted to 1.0e-6, defines the precision of computing the intersection points. In case of a tangential intersection, Tol also defines the size of intersection segments (limited portions of the curves) where the distance between all points from two curves (or a curve in case of self-intersection) is less than Tol. Warning Use functions NbPoints and NbSegments to obtain the number of solutions. If the algorithm finds no intersections NbPoints and NbSegments return 0.", py::arg("C1"), py::arg("Tol"));
cls_Geom2dAPI_InterCurveCurve.def("NbPoints", (Standard_Integer (Geom2dAPI_InterCurveCurve::*)() const) &Geom2dAPI_InterCurveCurve::NbPoints, "Returns the number of intersection-points in case of cross intersections. NbPoints returns 0 if no intersections were found.");
cls_Geom2dAPI_InterCurveCurve.def("Point", (gp_Pnt2d (Geom2dAPI_InterCurveCurve::*)(const Standard_Integer) const) &Geom2dAPI_InterCurveCurve::Point, "Returns the intersection point of index Index. Intersection points are computed in case of cross intersections with a precision equal to the tolerance value assigned at the time of construction or in the function Init (this value is defaulted to 1.0e-6). Exceptions Standard_OutOfRange if index is not in the range [ 1,NbPoints ], where NbPoints is the number of computed intersection points", py::arg("Index"));
cls_Geom2dAPI_InterCurveCurve.def("NbSegments", (Standard_Integer (Geom2dAPI_InterCurveCurve::*)() const) &Geom2dAPI_InterCurveCurve::NbSegments, "Returns the number of tangential intersections. NbSegments returns 0 if no intersections were found");
cls_Geom2dAPI_InterCurveCurve.def("Segment", (void (Geom2dAPI_InterCurveCurve::*)(const Standard_Integer, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &) const) &Geom2dAPI_InterCurveCurve::Segment, "Use this syntax only to get solutions of tangential intersection between two curves. Output values Curve1 and Curve2 are the intersection segments on the first curve and on the second curve accordingly. Parameter Index defines a number of computed solution. An intersection segment is a portion of an initial curve limited by two points. The distance from each point of this segment to the other curve is less or equal to the tolerance value assigned at the time of construction or in function Init (this value is defaulted to 1.0e-6). Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbSegments ], where NbSegments is the number of computed tangential intersections. Standard_NullObject if the algorithm is initialized for the computing of self-intersections on a curve.", py::arg("Index"), py::arg("Curve1"), py::arg("Curve2"));
cls_Geom2dAPI_InterCurveCurve.def("Intersector", (const Geom2dInt_GInter & (Geom2dAPI_InterCurveCurve::*)() const) &Geom2dAPI_InterCurveCurve::Intersector, "return the algorithmic object from Intersection.");

// Enums

}