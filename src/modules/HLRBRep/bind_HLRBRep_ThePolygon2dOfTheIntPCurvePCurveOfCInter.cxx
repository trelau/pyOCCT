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
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Domain.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.hxx>

void bind_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter(py::module &mod){

py::class_<HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter, std::unique_ptr<HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter, Deleter<HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter>>, Intf_Polygon2d> cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter(mod, "HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter", "None");

// Constructors
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def(py::init<const Standard_Address &, const Standard_Integer, const IntRes2d_Domain &, const Standard_Real>(), py::arg("Curve"), py::arg("NbPnt"), py::arg("Domain"), py::arg("Tol"));

// Fields

// Methods
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("ComputeWithBox", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Address &, const Bnd_Box2d &)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::ComputeWithBox, "The current polygon is modified if most of the points of the polygon are are outside the box <OtherBox>. In this situation, bounds are computed to build a polygon inside or near the OtherBox.", py::arg("Curve"), py::arg("OtherBox"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("DeflectionOverEstimation", (Standard_Real (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::DeflectionOverEstimation, "None");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("SetDeflectionOverEstimation", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Real)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::SetDeflectionOverEstimation, "None", py::arg("x"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("Closed", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Boolean)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::Closed, "None", py::arg("clos"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("Closed", (Standard_Boolean (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::Closed, "Returns True if the polyline is closed.");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("NbSegments", (Standard_Integer (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::NbSegments, "Give the number of Segments in the polyline.");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("Segment", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::Segment, "Returns the points of the segment <Index> in the Polygon.", py::arg("theIndex"), py::arg("theBegin"), py::arg("theEnd"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("InfParameter", (Standard_Real (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::InfParameter, "Returns the parameter (On the curve) of the first point of the Polygon");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("SupParameter", (Standard_Real (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::SupParameter, "Returns the parameter (On the curve) of the last point of the Polygon");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("AutoIntersectionIsPossible", (Standard_Boolean (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::AutoIntersectionIsPossible, "None");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("ApproxParamOnCurve", (Standard_Real (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Integer, const Standard_Real) const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::ApproxParamOnCurve, "Give an approximation of the parameter on the curve according to the discretization of the Curve.", py::arg("Index"), py::arg("ParamOnLine"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("CalculRegion", (Standard_Integer (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real) const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::CalculRegion, "None", py::arg("x"), py::arg("y"), py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("Dump", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::Dump, "None");

// Enums

}