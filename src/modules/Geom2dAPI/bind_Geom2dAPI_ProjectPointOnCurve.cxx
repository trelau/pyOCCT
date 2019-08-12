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
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_ExtPC2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Geom2dAPI_ProjectPointOnCurve.hxx>

void bind_Geom2dAPI_ProjectPointOnCurve(py::module &mod){

py::class_<Geom2dAPI_ProjectPointOnCurve, std::unique_ptr<Geom2dAPI_ProjectPointOnCurve, Deleter<Geom2dAPI_ProjectPointOnCurve>>> cls_Geom2dAPI_ProjectPointOnCurve(mod, "Geom2dAPI_ProjectPointOnCurve", "This class implements methods for computing all the orthogonal projections of a 2D point onto a 2D curve.");

// Constructors
cls_Geom2dAPI_ProjectPointOnCurve.def(py::init<>());
cls_Geom2dAPI_ProjectPointOnCurve.def(py::init<const gp_Pnt2d &, const opencascade::handle<Geom2d_Curve> &>(), py::arg("P"), py::arg("Curve"));
cls_Geom2dAPI_ProjectPointOnCurve.def(py::init<const gp_Pnt2d &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("Curve"), py::arg("Umin"), py::arg("Usup"));

// Fields

// Methods
// cls_Geom2dAPI_ProjectPointOnCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dAPI_ProjectPointOnCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dAPI_ProjectPointOnCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dAPI_ProjectPointOnCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dAPI_ProjectPointOnCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dAPI_ProjectPointOnCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dAPI_ProjectPointOnCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dAPI_ProjectPointOnCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dAPI_ProjectPointOnCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dAPI_ProjectPointOnCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dAPI_ProjectPointOnCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dAPI_ProjectPointOnCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dAPI_ProjectPointOnCurve.def("Init", (void (Geom2dAPI_ProjectPointOnCurve::*)(const gp_Pnt2d &, const opencascade::handle<Geom2d_Curve> &)) &Geom2dAPI_ProjectPointOnCurve::Init, "Initializes this algorithm with the given arguments, and computes the orthogonal projections of a point <P> on a curve <Curve>", py::arg("P"), py::arg("Curve"));
cls_Geom2dAPI_ProjectPointOnCurve.def("Init", (void (Geom2dAPI_ProjectPointOnCurve::*)(const gp_Pnt2d &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &Geom2dAPI_ProjectPointOnCurve::Init, "Initializes this algorithm with the given arguments, and computes the orthogonal projections of the point P onto the portion of the curve Curve limited by the two points of parameter Umin and Usup.", py::arg("P"), py::arg("Curve"), py::arg("Umin"), py::arg("Usup"));
cls_Geom2dAPI_ProjectPointOnCurve.def("NbPoints", (Standard_Integer (Geom2dAPI_ProjectPointOnCurve::*)() const) &Geom2dAPI_ProjectPointOnCurve::NbPoints, "return the number of of computed orthogonal projectionn points.");
cls_Geom2dAPI_ProjectPointOnCurve.def("Point", (gp_Pnt2d (Geom2dAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &Geom2dAPI_ProjectPointOnCurve::Point, "Returns the orthogonal projection on the curve. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_Geom2dAPI_ProjectPointOnCurve.def("Parameter", (Standard_Real (Geom2dAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &Geom2dAPI_ProjectPointOnCurve::Parameter, "Returns the parameter on the curve of a point which is the orthogonal projection. Index is a number of a computed projected point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_Geom2dAPI_ProjectPointOnCurve.def("Parameter", [](Geom2dAPI_ProjectPointOnCurve &self, const Standard_Integer Index, Standard_Real & U){ self.Parameter(Index, U); return U; }, "Returns the parameter on the curve of a point which is the orthogonal projection. Index is a number of a computed projected point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points", py::arg("Index"), py::arg("U"));
cls_Geom2dAPI_ProjectPointOnCurve.def("Distance", (Standard_Real (Geom2dAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &Geom2dAPI_ProjectPointOnCurve::Distance, "Computes the distance between the point and its computed orthogonal projection on the curve. Index is a number of computed projected point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_Geom2dAPI_ProjectPointOnCurve.def("NearestPoint", (gp_Pnt2d (Geom2dAPI_ProjectPointOnCurve::*)() const) &Geom2dAPI_ProjectPointOnCurve::NearestPoint, "Returns the nearest orthogonal projection of the point on the curve. Exceptions StdFail_NotDone if this algorithm fails.");
cls_Geom2dAPI_ProjectPointOnCurve.def("LowerDistanceParameter", (Standard_Real (Geom2dAPI_ProjectPointOnCurve::*)() const) &Geom2dAPI_ProjectPointOnCurve::LowerDistanceParameter, "Returns the parameter on the curve of the nearest orthogonal projection of the point. Exceptions StdFail_NotDone if this algorithm fails.");
cls_Geom2dAPI_ProjectPointOnCurve.def("LowerDistance", (Standard_Real (Geom2dAPI_ProjectPointOnCurve::*)() const) &Geom2dAPI_ProjectPointOnCurve::LowerDistance, "Computes the distance between the point and its nearest orthogonal projection on the curve. Exceptions StdFail_NotDone if this algorithm fails.");
cls_Geom2dAPI_ProjectPointOnCurve.def("Extrema", (const Extrema_ExtPC2d & (Geom2dAPI_ProjectPointOnCurve::*)() const) &Geom2dAPI_ProjectPointOnCurve::Extrema, "return the algorithmic object from Extrema");

// Enums

}