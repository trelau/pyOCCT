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
#include <Geom2d_BSplineCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2d_Curve.hxx>
#include <Convert_ParameterisationType.hxx>
#include <TColGeom2d_Array1OfBSplineCurve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColGeom2d_HArray1OfBSplineCurve.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Geom2dConvert_BSplineCurveKnotSplitting.hxx>
#include <Geom2dConvert_BSplineCurveToBezierCurve.hxx>
#include <Geom2dConvert_CompCurveToBSplineCurve.hxx>
#include <Geom2dConvert_ApproxCurve.hxx>
#include <Geom2dConvert.hxx>

void bind_Geom2dConvert(py::module &mod){

py::class_<Geom2dConvert> cls_Geom2dConvert(mod, "Geom2dConvert", "This package provides an implementation of algorithmes to do the conversion between equivalent geometric entities from package Geom2d. It gives the possibility : . to obtain the B-spline representation of bounded curves. . to split a B-spline curve into several B-spline curves with some constraints of continuity, . to convert a B-spline curve into several Bezier curves or surfaces. All the geometric entities used in this package are bounded. References : . Generating the Bezier Points of B-spline curves and surfaces (Wolfgang Bohm) CAGD volume 13 number 6 november 1981 . On NURBS: A Survey (Leslie Piegl) IEEE Computer Graphics and Application January 1991 . Curve and surface construction using rational B-splines (Leslie Piegl and Wayne Tiller) CAD Volume 19 number 9 november 1987 . A survey of curve and surface methods in CAGD (Wolfgang BOHM) CAGD 1 1984");

// Constructors

// Fields

// Methods
// cls_Geom2dConvert.def_static("operator new_", (void * (*)(size_t)) &Geom2dConvert::operator new, "None", py::arg("theSize"));
// cls_Geom2dConvert.def_static("operator delete_", (void (*)(void *)) &Geom2dConvert::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dConvert.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dConvert::operator new[], "None", py::arg("theSize"));
// cls_Geom2dConvert.def_static("operator delete[]_", (void (*)(void *)) &Geom2dConvert::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dConvert.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dConvert::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dConvert.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dConvert::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dConvert.def_static("SplitBSplineCurve_", [](const opencascade::handle<Geom2d_BSplineCurve> & a0, const Standard_Integer a1, const Standard_Integer a2) -> opencascade::handle<Geom2d_BSplineCurve> { return Geom2dConvert::SplitBSplineCurve(a0, a1, a2); });
cls_Geom2dConvert.def_static("SplitBSplineCurve_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Geom2dConvert::SplitBSplineCurve, "-- Convert a curve to BSpline by Approximation", py::arg("C"), py::arg("FromK1"), py::arg("ToK2"), py::arg("SameOrientation"));
cls_Geom2dConvert.def_static("SplitBSplineCurve_", [](const opencascade::handle<Geom2d_BSplineCurve> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> opencascade::handle<Geom2d_BSplineCurve> { return Geom2dConvert::SplitBSplineCurve(a0, a1, a2, a3); });
cls_Geom2dConvert.def_static("SplitBSplineCurve_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Geom2dConvert::SplitBSplineCurve, "This function computes the segment of B-spline curve between the parametric values FromU1, ToU2. If C is periodic the arc has the same orientation as C if SameOrientation = True. If C is not periodic SameOrientation is not used for the computation and C is oriented fromU1 toU2. If U1 and U2 and two parametric values we consider that U1 = U2 if Abs (U1 - U2) <= ParametricTolerance and ParametricTolerance must be greater or equal to Resolution from package gp.", py::arg("C"), py::arg("FromU1"), py::arg("ToU2"), py::arg("ParametricTolerance"), py::arg("SameOrientation"));
cls_Geom2dConvert.def_static("CurveToBSplineCurve_", [](const opencascade::handle<Geom2d_Curve> & a0) -> opencascade::handle<Geom2d_BSplineCurve> { return Geom2dConvert::CurveToBSplineCurve(a0); });
cls_Geom2dConvert.def_static("CurveToBSplineCurve_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Geom2d_Curve> &, const Convert_ParameterisationType)) &Geom2dConvert::CurveToBSplineCurve, "This function converts a non infinite curve from Geom into a B-spline curve. C must be an ellipse or a circle or a trimmed conic or a trimmed line or a Bezier curve or a trimmed Bezier curve or a BSpline curve or a trimmed BSpline curve or an Offset curve or a trimmed Offset curve. The returned B-spline is not periodic except if C is a Circle or an Ellipse. ParameterisationType applies only if the curve is a Circle or an ellipse : TgtThetaOver2, TgtThetaOver2_1, TgtThetaOver2_2, TgtThetaOver2_3, TgtThetaOver2_4, Purpose: this is the classical rational parameterisation 2 1 - t cos(theta) = ------ 2 1 + t", py::arg("C"), py::arg("Parameterisation"));
cls_Geom2dConvert.def_static("ConcatG1_", (void (*)(TColGeom2d_Array1OfBSplineCurve &, const TColStd_Array1OfReal &, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> &, const Standard_Boolean, const Standard_Real)) &Geom2dConvert::ConcatG1, "This Method concatenates G1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedTolerance indicates if the ArrayOfCurves is closed. In this case ClosedTolerance contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfConcatenated"), py::arg("ClosedFlag"), py::arg("ClosedTolerance"));
cls_Geom2dConvert.def_static("ConcatC1_", (void (*)(TColGeom2d_Array1OfBSplineCurve &, const TColStd_Array1OfReal &, opencascade::handle<TColStd_HArray1OfInteger> &, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> &, const Standard_Boolean, const Standard_Real)) &Geom2dConvert::ConcatC1, "This Method concatenates C1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedTolerance indicates if the ArrayOfCurves is closed. In this case ClosedTolerance contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfIndices"), py::arg("ArrayOfConcatenated"), py::arg("ClosedFlag"), py::arg("ClosedTolerance"));
cls_Geom2dConvert.def_static("ConcatC1_", (void (*)(TColGeom2d_Array1OfBSplineCurve &, const TColStd_Array1OfReal &, opencascade::handle<TColStd_HArray1OfInteger> &, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> &, const Standard_Boolean, const Standard_Real, const Standard_Real)) &Geom2dConvert::ConcatC1, "This Method concatenates C1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedTolerance indicates if the ArrayOfCurves is closed. In this case ClosedTolerance contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfIndices"), py::arg("ArrayOfConcatenated"), py::arg("ClosedFlag"), py::arg("ClosedTolerance"), py::arg("AngularTolerance"));
cls_Geom2dConvert.def_static("C0BSplineToC1BSplineCurve_", (void (*)(opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real)) &Geom2dConvert::C0BSplineToC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns a new BSpline which could still be C0. tolerance is a geometrical tolerance", py::arg("BS"), py::arg("Tolerance"));
cls_Geom2dConvert.def_static("C0BSplineToArrayOfC1BSplineCurve_", (void (*)(const opencascade::handle<Geom2d_BSplineCurve> &, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> &, const Standard_Real)) &Geom2dConvert::C0BSplineToArrayOfC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns an array of BSpline C1. Tolerance is a geometrical tolerance", py::arg("BS"), py::arg("tabBS"), py::arg("Tolerance"));
cls_Geom2dConvert.def_static("C0BSplineToArrayOfC1BSplineCurve_", (void (*)(const opencascade::handle<Geom2d_BSplineCurve> &, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> &, const Standard_Real, const Standard_Real)) &Geom2dConvert::C0BSplineToArrayOfC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns an array of BSpline C1. tolerance is a geometrical tolerance", py::arg("BS"), py::arg("tabBS"), py::arg("AngularTolerance"), py::arg("Tolerance"));

// Enums

}