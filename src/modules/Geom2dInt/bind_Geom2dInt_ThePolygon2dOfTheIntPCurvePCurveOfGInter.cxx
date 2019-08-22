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
#include <Intf_Polygon2d.hxx>
#include <Standard.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Domain.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.hxx>

void bind_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter(py::module &mod){

py::class_<Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter, Intf_Polygon2d> cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter(mod, "Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const IntRes2d_Domain &, const Standard_Real>(), py::arg("Curve"), py::arg("NbPnt"), py::arg("Domain"), py::arg("Tol"));

// Fields

// Methods
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("ComputeWithBox", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Adaptor2d_Curve2d &, const Bnd_Box2d &)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::ComputeWithBox, "The current polygon is modified if most of the points of the polygon are are outside the box <OtherBox>. In this situation, bounds are computed to build a polygon inside or near the OtherBox.", py::arg("Curve"), py::arg("OtherBox"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("DeflectionOverEstimation", (Standard_Real (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::DeflectionOverEstimation, "None");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("SetDeflectionOverEstimation", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Real)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::SetDeflectionOverEstimation, "None", py::arg("x"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("Closed", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Boolean)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::Closed, "None", py::arg("clos"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("Closed", (Standard_Boolean (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::Closed, "Returns True if the polyline is closed.");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("NbSegments", (Standard_Integer (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::NbSegments, "Give the number of Segments in the polyline.");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("Segment", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::Segment, "Returns the points of the segment <Index> in the Polygon.", py::arg("theIndex"), py::arg("theBegin"), py::arg("theEnd"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("InfParameter", (Standard_Real (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::InfParameter, "Returns the parameter (On the curve) of the first point of the Polygon");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("SupParameter", (Standard_Real (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::SupParameter, "Returns the parameter (On the curve) of the last point of the Polygon");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("AutoIntersectionIsPossible", (Standard_Boolean (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::AutoIntersectionIsPossible, "None");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("ApproxParamOnCurve", (Standard_Real (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Integer, const Standard_Real) const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::ApproxParamOnCurve, "Give an approximation of the parameter on the curve according to the discretization of the Curve.", py::arg("Index"), py::arg("ParamOnLine"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("CalculRegion", (Standard_Integer (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real) const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::CalculRegion, "None", py::arg("x"), py::arg("y"), py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("Dump", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::Dump, "None");

// Enums

}