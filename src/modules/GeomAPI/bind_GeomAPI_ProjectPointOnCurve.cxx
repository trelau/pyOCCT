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
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_ExtPC.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>

void bind_GeomAPI_ProjectPointOnCurve(py::module &mod){

py::class_<GeomAPI_ProjectPointOnCurve, std::unique_ptr<GeomAPI_ProjectPointOnCurve, Deleter<GeomAPI_ProjectPointOnCurve>>> cls_GeomAPI_ProjectPointOnCurve(mod, "GeomAPI_ProjectPointOnCurve", "This class implements methods for computing all the orthogonal projections of a 3D point onto a 3D curve.");

// Constructors
cls_GeomAPI_ProjectPointOnCurve.def(py::init<>());
cls_GeomAPI_ProjectPointOnCurve.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Curve> &>(), py::arg("P"), py::arg("Curve"));
cls_GeomAPI_ProjectPointOnCurve.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("Curve"), py::arg("Umin"), py::arg("Usup"));

// Fields

// Methods
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ProjectPointOnCurve::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ProjectPointOnCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ProjectPointOnCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ProjectPointOnCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ProjectPointOnCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ProjectPointOnCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ProjectPointOnCurve.def("Init", (void (GeomAPI_ProjectPointOnCurve::*)(const gp_Pnt &, const opencascade::handle<Geom_Curve> &)) &GeomAPI_ProjectPointOnCurve::Init, "Init the projection of a point <P> on a curve <Curve>", py::arg("P"), py::arg("Curve"));
cls_GeomAPI_ProjectPointOnCurve.def("Init", (void (GeomAPI_ProjectPointOnCurve::*)(const gp_Pnt &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &GeomAPI_ProjectPointOnCurve::Init, "Init the projection of a point <P> on a curve <Curve> limited by the two points of parameter Umin and Usup.", py::arg("P"), py::arg("Curve"), py::arg("Umin"), py::arg("Usup"));
cls_GeomAPI_ProjectPointOnCurve.def("Init", (void (GeomAPI_ProjectPointOnCurve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &GeomAPI_ProjectPointOnCurve::Init, "Init the projection of a point <P> on a curve <Curve> limited by the two points of parameter Umin and Usup.", py::arg("Curve"), py::arg("Umin"), py::arg("Usup"));
cls_GeomAPI_ProjectPointOnCurve.def("Perform", (void (GeomAPI_ProjectPointOnCurve::*)(const gp_Pnt &)) &GeomAPI_ProjectPointOnCurve::Perform, "Performs the projection of a point on the current curve.", py::arg("P"));
cls_GeomAPI_ProjectPointOnCurve.def("NbPoints", (Standard_Integer (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::NbPoints, "Returns the number of computed orthogonal projection points. Note: if this algorithm fails, NbPoints returns 0.");
cls_GeomAPI_ProjectPointOnCurve.def("Point", (gp_Pnt (GeomAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnCurve::Point, "Returns the orthogonal projection on the curve. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnCurve.def("Parameter", (Standard_Real (GeomAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnCurve::Parameter, "Returns the parameter on the curve of the point, which is the orthogonal projection. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnCurve.def("Parameter", [](GeomAPI_ProjectPointOnCurve &self, const Standard_Integer Index, Standard_Real & U){ self.Parameter(Index, U); return U; }, "Returns the parameter on the curve of the point, which is the orthogonal projection. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.-", py::arg("Index"), py::arg("U"));
cls_GeomAPI_ProjectPointOnCurve.def("Distance", (Standard_Real (GeomAPI_ProjectPointOnCurve::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnCurve::Distance, "Computes the distance between the point and its orthogonal projection on the curve. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnCurve.def("NearestPoint", (gp_Pnt (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::NearestPoint, "Returns the nearest orthogonal projection of the point on the curve. Exceptions: StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ProjectPointOnCurve.def("LowerDistanceParameter", (Standard_Real (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::LowerDistanceParameter, "Returns the parameter on the curve of the nearest orthogonal projection of the point. Exceptions: StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ProjectPointOnCurve.def("LowerDistance", (Standard_Real (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::LowerDistance, "Computes the distance between the point and its nearest orthogonal projection on the curve. Exceptions: StdFail_NotDone if this algorithm fails.");
cls_GeomAPI_ProjectPointOnCurve.def("Extrema", (const Extrema_ExtPC & (GeomAPI_ProjectPointOnCurve::*)() const) &GeomAPI_ProjectPointOnCurve::Extrema, "return the algorithmic object from Extrema");

// Enums

}