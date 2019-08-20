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
#include <TColgp_Array1OfPnt.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Approx_ParametrizationType.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomAPI_PointsToBSpline.hxx>

void bind_GeomAPI_PointsToBSpline(py::module &mod){

py::class_<GeomAPI_PointsToBSpline, std::unique_ptr<GeomAPI_PointsToBSpline>> cls_GeomAPI_PointsToBSpline(mod, "GeomAPI_PointsToBSpline", "This class is used to approximate a BsplineCurve passing through an array of points, with a given Continuity. Describes functions for building a 3D BSpline curve which approximates a set of points. A PointsToBSpline object provides a framework for: - defining the data of the BSpline curve to be built, - implementing the approximation algorithm, and consulting the results.");

// Constructors
cls_GeomAPI_PointsToBSpline.def(py::init<>());
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("Points"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Integer>(), py::arg("Points"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Integer, const Standard_Integer>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType>(), py::arg("Points"), py::arg("ParType"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("Points"), py::arg("Parameters"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer>(), py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer, const Standard_Integer>(), py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"));
cls_GeomAPI_PointsToBSpline.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));

// Fields

// Methods
// cls_GeomAPI_PointsToBSpline.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_PointsToBSpline::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_PointsToBSpline.def_static("operator delete_", (void (*)(void *)) &GeomAPI_PointsToBSpline::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_PointsToBSpline.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_PointsToBSpline::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_PointsToBSpline.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_PointsToBSpline::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_PointsToBSpline.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_PointsToBSpline::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_PointsToBSpline.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_PointsToBSpline::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0) -> void { return self.Init(a0); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Integer a1, const Standard_Integer a2, const GeomAbs_Shape a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSpline.def("Init", (void (GeomAPI_PointsToBSpline::*)(const TColgp_Array1OfPnt &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSpline::Init, "Approximate a BSpline Curve passing through an array of Point. The resulting BSpline will have the following properties: 1- his degree will be in the range [Degmin,Degmax] 2- his continuity will be at least <Continuity> 3- the distance from the point <Points> to the BSpline will be lower to Tol3D", py::arg("Points"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Approx_ParametrizationType a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2, const Standard_Integer a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Approx_ParametrizationType a1, const Standard_Integer a2, const Standard_Integer a3, const GeomAbs_Shape a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSpline.def("Init", (void (GeomAPI_PointsToBSpline::*)(const TColgp_Array1OfPnt &, const Approx_ParametrizationType, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSpline::Init, "Approximate a BSpline Curve passing through an array of Point. The resulting BSpline will have the following properties: 1- his degree will be in the range [Degmin,Degmax] 2- his continuity will be at least <Continuity> 3- the distance from the point <Points> to the BSpline will be lower to Tol3D", py::arg("Points"), py::arg("ParType"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal & a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal & a1, const Standard_Integer a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal & a1, const Standard_Integer a2, const Standard_Integer a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const TColStd_Array1OfReal & a1, const Standard_Integer a2, const Standard_Integer a3, const GeomAbs_Shape a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSpline.def("Init", (void (GeomAPI_PointsToBSpline::*)(const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSpline::Init, "Approximate a BSpline Curve passing through an array of Point, which parameters are given by the array <Parameters>. The resulting BSpline will have the following properties: 1- his degree will be in the range [Degmin,Degmax] 2- his continuity will be at least <Continuity> 3- the distance from the point <Points> to the BSpline will be lower to Tol3D", py::arg("Points"), py::arg("Parameters"), py::arg("DegMin"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_PointsToBSpline.def("Init", [](GeomAPI_PointsToBSpline &self, const TColgp_Array1OfPnt & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const GeomAbs_Shape a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomAPI_PointsToBSpline.def("Init", (void (GeomAPI_PointsToBSpline::*)(const TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real)) &GeomAPI_PointsToBSpline::Init, "Approximate a BSpline Curve passing through an array of Point using variational smoothing algorithm, which tries to minimize additional criterium: Weight1*CurveLength + Weight2*Curvature + Weight3*Torsion", py::arg("Points"), py::arg("Weight1"), py::arg("Weight2"), py::arg("Weight3"), py::arg("DegMax"), py::arg("Continuity"), py::arg("Tol3D"));
cls_GeomAPI_PointsToBSpline.def("Curve", (const opencascade::handle<Geom_BSplineCurve> & (GeomAPI_PointsToBSpline::*)() const) &GeomAPI_PointsToBSpline::Curve, "Returns the computed BSpline curve. Raises StdFail_NotDone if the curve is not built.");
cls_GeomAPI_PointsToBSpline.def("IsDone", (Standard_Boolean (GeomAPI_PointsToBSpline::*)() const) &GeomAPI_PointsToBSpline::IsDone, "None");

// Enums

}