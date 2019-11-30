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
#include <Convert_ParameterisationType.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_BoundedCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2dConvert_CompCurveToBSplineCurve.hxx>
#include <Geom2d_Curve.hxx>
#include <TColGeom2d_Array1OfBSplineCurve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColGeom2d_HArray1OfBSplineCurve.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Geom2dConvert_BSplineCurveKnotSplitting.hxx>
#include <Geom2dConvert_BSplineCurveToBezierCurve.hxx>
#include <Geom2dConvert_ApproxCurve.hxx>
#include <Geom2dConvert.hxx>
#include <GeomAbs_Shape.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <TColGeom2d_Array1OfBezierCurve.hxx>

PYBIND11_MODULE(Geom2dConvert, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Convert");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColGeom2d");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Adaptor2d");

// CLASS: GEOM2DCONVERT_COMPCURVETOBSPLINECURVE
py::class_<Geom2dConvert_CompCurveToBSplineCurve> cls_Geom2dConvert_CompCurveToBSplineCurve(mod, "Geom2dConvert_CompCurveToBSplineCurve", "This algorithm converts and concat several curve in an BSplineCurve");

// Constructors
cls_Geom2dConvert_CompCurveToBSplineCurve.def(py::init<>());
cls_Geom2dConvert_CompCurveToBSplineCurve.def(py::init<const Convert_ParameterisationType>(), py::arg("Parameterisation"));
cls_Geom2dConvert_CompCurveToBSplineCurve.def(py::init<const opencascade::handle<Geom2d_BoundedCurve> &>(), py::arg("BasisCurve"));
cls_Geom2dConvert_CompCurveToBSplineCurve.def(py::init<const opencascade::handle<Geom2d_BoundedCurve> &, const Convert_ParameterisationType>(), py::arg("BasisCurve"), py::arg("Parameterisation"));

// Methods
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dConvert_CompCurveToBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dConvert_CompCurveToBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dConvert_CompCurveToBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dConvert_CompCurveToBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dConvert_CompCurveToBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dConvert_CompCurveToBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dConvert_CompCurveToBSplineCurve.def("Add", [](Geom2dConvert_CompCurveToBSplineCurve &self, const opencascade::handle<Geom2d_BoundedCurve> & a0, const Standard_Real a1) -> Standard_Boolean { return self.Add(a0, a1); });
cls_Geom2dConvert_CompCurveToBSplineCurve.def("Add", (Standard_Boolean (Geom2dConvert_CompCurveToBSplineCurve::*)(const opencascade::handle<Geom2d_BoundedCurve> &, const Standard_Real, const Standard_Boolean)) &Geom2dConvert_CompCurveToBSplineCurve::Add, "Append a curve in the BSpline Return False if the curve is not G0 with the BSplineCurve. Tolerance is used to check continuity and decrease Multiplicty at the common Knot After is usefull if BasisCurve is a closed curve .", py::arg("NewCurve"), py::arg("Tolerance"), py::arg("After"));
cls_Geom2dConvert_CompCurveToBSplineCurve.def("BSplineCurve", (opencascade::handle<Geom2d_BSplineCurve> (Geom2dConvert_CompCurveToBSplineCurve::*)() const) &Geom2dConvert_CompCurveToBSplineCurve::BSplineCurve, "None");
cls_Geom2dConvert_CompCurveToBSplineCurve.def("Clear", (void (Geom2dConvert_CompCurveToBSplineCurve::*)()) &Geom2dConvert_CompCurveToBSplineCurve::Clear, "Clear result curve");

// CLASS: GEOM2DCONVERT
py::class_<Geom2dConvert> cls_Geom2dConvert(mod, "Geom2dConvert", "This package provides an implementation of algorithmes to do the conversion between equivalent geometric entities from package Geom2d. It gives the possibility : . to obtain the B-spline representation of bounded curves. . to split a B-spline curve into several B-spline curves with some constraints of continuity, . to convert a B-spline curve into several Bezier curves or surfaces. All the geometric entities used in this package are bounded. References : . Generating the Bezier Points of B-spline curves and surfaces (Wolfgang Bohm) CAGD volume 13 number 6 november 1981 . On NURBS: A Survey (Leslie Piegl) IEEE Computer Graphics and Application January 1991 . Curve and surface construction using rational B-splines (Leslie Piegl and Wayne Tiller) CAD Volume 19 number 9 november 1987 . A survey of curve and surface methods in CAGD (Wolfgang BOHM) CAGD 1 1984");

// Constructors
cls_Geom2dConvert.def(py::init<>());

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
cls_Geom2dConvert.def_static("ConcatG1_", [](TColGeom2d_Array1OfBSplineCurve & ArrayOfCurves, const TColStd_Array1OfReal & ArrayOfToler, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> & ArrayOfConcatenated, Standard_Boolean & ClosedFlag, const Standard_Real ClosedTolerance){ Geom2dConvert::ConcatG1(ArrayOfCurves, ArrayOfToler, ArrayOfConcatenated, ClosedFlag, ClosedTolerance); return ClosedFlag; }, "This Method concatenates G1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedFlag indicates if the ArrayOfCurves is closed. In this case ClosedTolerance contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0 ClosedFlag becomes False on the output if it is impossible to build closed curve.", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfConcatenated"), py::arg("ClosedFlag"), py::arg("ClosedTolerance"));
cls_Geom2dConvert.def_static("ConcatC1_", [](TColGeom2d_Array1OfBSplineCurve & ArrayOfCurves, const TColStd_Array1OfReal & ArrayOfToler, opencascade::handle<TColStd_HArray1OfInteger> & ArrayOfIndices, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> & ArrayOfConcatenated, Standard_Boolean & ClosedFlag, const Standard_Real ClosedTolerance){ Geom2dConvert::ConcatC1(ArrayOfCurves, ArrayOfToler, ArrayOfIndices, ArrayOfConcatenated, ClosedFlag, ClosedTolerance); return ClosedFlag; }, "This Method concatenates C1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedFlag indicates if the ArrayOfCurves is closed. In this case ClosedTolerance contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0 ClosedFlag becomes False on the output if it is impossible to build closed curve.", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfIndices"), py::arg("ArrayOfConcatenated"), py::arg("ClosedFlag"), py::arg("ClosedTolerance"));
cls_Geom2dConvert.def_static("ConcatC1_", [](TColGeom2d_Array1OfBSplineCurve & ArrayOfCurves, const TColStd_Array1OfReal & ArrayOfToler, opencascade::handle<TColStd_HArray1OfInteger> & ArrayOfIndices, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> & ArrayOfConcatenated, Standard_Boolean & ClosedFlag, const Standard_Real ClosedTolerance, const Standard_Real AngularTolerance){ Geom2dConvert::ConcatC1(ArrayOfCurves, ArrayOfToler, ArrayOfIndices, ArrayOfConcatenated, ClosedFlag, ClosedTolerance, AngularTolerance); return ClosedFlag; }, "This Method concatenates C1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedFlag indicates if the ArrayOfCurves is closed. In this case ClosedTolerance contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0 ClosedFlag becomes False on the output if it is impossible to build closed curve.", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfIndices"), py::arg("ArrayOfConcatenated"), py::arg("ClosedFlag"), py::arg("ClosedTolerance"), py::arg("AngularTolerance"));
cls_Geom2dConvert.def_static("C0BSplineToC1BSplineCurve_", (void (*)(opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real)) &Geom2dConvert::C0BSplineToC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns a new BSpline which could still be C0. tolerance is a geometrical tolerance", py::arg("BS"), py::arg("Tolerance"));
cls_Geom2dConvert.def_static("C0BSplineToArrayOfC1BSplineCurve_", (void (*)(const opencascade::handle<Geom2d_BSplineCurve> &, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> &, const Standard_Real)) &Geom2dConvert::C0BSplineToArrayOfC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns an array of BSpline C1. Tolerance is a geometrical tolerance", py::arg("BS"), py::arg("tabBS"), py::arg("Tolerance"));
cls_Geom2dConvert.def_static("C0BSplineToArrayOfC1BSplineCurve_", (void (*)(const opencascade::handle<Geom2d_BSplineCurve> &, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve> &, const Standard_Real, const Standard_Real)) &Geom2dConvert::C0BSplineToArrayOfC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns an array of BSpline C1. tolerance is a geometrical tolerance", py::arg("BS"), py::arg("tabBS"), py::arg("AngularTolerance"), py::arg("Tolerance"));

// CLASS: GEOM2DCONVERT_APPROXCURVE
py::class_<Geom2dConvert_ApproxCurve> cls_Geom2dConvert_ApproxCurve(mod, "Geom2dConvert_ApproxCurve", "A framework to convert a 2D curve to a BSpline. This is done by approximation within a given tolerance.");

// Constructors
cls_Geom2dConvert_ApproxCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Curve"), py::arg("Tol2d"), py::arg("Order"), py::arg("MaxSegments"), py::arg("MaxDegree"));
cls_Geom2dConvert_ApproxCurve.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Curve"), py::arg("Tol2d"), py::arg("Order"), py::arg("MaxSegments"), py::arg("MaxDegree"));

// Methods
// cls_Geom2dConvert_ApproxCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dConvert_ApproxCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dConvert_ApproxCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dConvert_ApproxCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dConvert_ApproxCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dConvert_ApproxCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dConvert_ApproxCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dConvert_ApproxCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dConvert_ApproxCurve.def("Curve", (opencascade::handle<Geom2d_BSplineCurve> (Geom2dConvert_ApproxCurve::*)() const) &Geom2dConvert_ApproxCurve::Curve, "Returns the 2D BSpline curve resulting from the approximation algorithm.");
cls_Geom2dConvert_ApproxCurve.def("IsDone", (Standard_Boolean (Geom2dConvert_ApproxCurve::*)() const) &Geom2dConvert_ApproxCurve::IsDone, "returns Standard_True if the approximation has been done with within requiered tolerance");
cls_Geom2dConvert_ApproxCurve.def("HasResult", (Standard_Boolean (Geom2dConvert_ApproxCurve::*)() const) &Geom2dConvert_ApproxCurve::HasResult, "returns Standard_True if the approximation did come out with a result that is not NECESSARELY within the required tolerance");
cls_Geom2dConvert_ApproxCurve.def("MaxError", (Standard_Real (Geom2dConvert_ApproxCurve::*)() const) &Geom2dConvert_ApproxCurve::MaxError, "Returns the greatest distance between a point on the source conic and the BSpline curve resulting from the approximation. (>0 when an approximation has been done, 0 if no approximation)");
cls_Geom2dConvert_ApproxCurve.def("Dump", (void (Geom2dConvert_ApproxCurve::*)(Standard_OStream &) const) &Geom2dConvert_ApproxCurve::Dump, "Print on the stream o information about the object", py::arg("o"));

// CLASS: GEOM2DCONVERT_BSPLINECURVEKNOTSPLITTING
py::class_<Geom2dConvert_BSplineCurveKnotSplitting> cls_Geom2dConvert_BSplineCurveKnotSplitting(mod, "Geom2dConvert_BSplineCurveKnotSplitting", "An algorithm to determine points at which a BSpline curve should be split in order to obtain arcs of the same continuity. If you require curves with a minimum continuity for your computation, it is useful to know the points between which an arc has a continuity of a given order. The continuity order is given at the construction time. For a BSpline curve, the discontinuities are localized at the knot values. Between two knot values the BSpline is infinitely and continuously differentiable. At a given knot, the continuity is equal to: Degree - Mult, where Degree is the degree of the BSpline curve and Mult is the multiplicity of the knot. It is possible to compute the arcs which correspond to this splitting using the global function SplitBSplineCurve provided by the package Geom2dConvert. A BSplineCurveKnotSplitting object provides a framework for: - defining the curve to be analysed and the required degree of continuity, - implementing the computation algorithm, and - consulting the results.");

// Constructors
cls_Geom2dConvert_BSplineCurveKnotSplitting.def(py::init<const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Integer>(), py::arg("BasisCurve"), py::arg("ContinuityRange"));

// Methods
// cls_Geom2dConvert_BSplineCurveKnotSplitting.def_static("operator new_", (void * (*)(size_t)) &Geom2dConvert_BSplineCurveKnotSplitting::operator new, "None", py::arg("theSize"));
// cls_Geom2dConvert_BSplineCurveKnotSplitting.def_static("operator delete_", (void (*)(void *)) &Geom2dConvert_BSplineCurveKnotSplitting::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dConvert_BSplineCurveKnotSplitting.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dConvert_BSplineCurveKnotSplitting::operator new[], "None", py::arg("theSize"));
// cls_Geom2dConvert_BSplineCurveKnotSplitting.def_static("operator delete[]_", (void (*)(void *)) &Geom2dConvert_BSplineCurveKnotSplitting::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dConvert_BSplineCurveKnotSplitting.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dConvert_BSplineCurveKnotSplitting::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dConvert_BSplineCurveKnotSplitting.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dConvert_BSplineCurveKnotSplitting::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dConvert_BSplineCurveKnotSplitting.def("NbSplits", (Standard_Integer (Geom2dConvert_BSplineCurveKnotSplitting::*)() const) &Geom2dConvert_BSplineCurveKnotSplitting::NbSplits, "Returns the number of points at which the analysed BSpline curve should be split, in order to obtain arcs with the continuity required by this framework. All these points correspond to knot values. Note that the first and last points of the curve, which bound the first and last arcs, are counted among these splitting points.");
cls_Geom2dConvert_BSplineCurveKnotSplitting.def("Splitting", (void (Geom2dConvert_BSplineCurveKnotSplitting::*)(TColStd_Array1OfInteger &) const) &Geom2dConvert_BSplineCurveKnotSplitting::Splitting, "Loads the SplitValues table with the split knots values computed in this framework. Each value in the table is an index in the knots table of the BSpline curve analysed by this algorithm. The values in SplitValues are given in ascending order and comprise the indices of the knots which give the first and last points of the curve. Use two consecutive values from the table as arguments of the global function SplitBSplineCurve (provided by the package Geom2dConvert) to split the curve. Exceptions Standard_DimensionError if the array SplitValues was not created with the following bounds: - 1, and - the number of split points computed in this framework (as given by the function NbSplits).", py::arg("SplitValues"));
cls_Geom2dConvert_BSplineCurveKnotSplitting.def("SplitValue", (Standard_Integer (Geom2dConvert_BSplineCurveKnotSplitting::*)(const Standard_Integer) const) &Geom2dConvert_BSplineCurveKnotSplitting::SplitValue, "Returns the split knot of index Index to the split knots table computed in this framework. The returned value is an index in the knots table of the BSpline curve analysed by this algorithm. Notes: - If Index is equal to 1, the corresponding knot gives the first point of the curve. - If Index is equal to the number of split knots computed in this framework, the corresponding point is the last point of the curve. Exceptions Standard_RangeError if Index is less than 1 or greater than the number of split knots computed in this framework.", py::arg("Index"));

// CLASS: GEOM2DCONVERT_BSPLINECURVETOBEZIERCURVE
py::class_<Geom2dConvert_BSplineCurveToBezierCurve> cls_Geom2dConvert_BSplineCurveToBezierCurve(mod, "Geom2dConvert_BSplineCurveToBezierCurve", "An algorithm to convert a BSpline curve into a series of adjacent Bezier curves. A BSplineCurveToBezierCurve object provides a framework for: - defining the BSpline curve to be converted - implementing the construction algorithm, and - consulting the results. References : Generating the Bezier points of B-spline curves and surfaces (Wolfgang Bohm) CAD volume 13 number 6 november 1981");

// Constructors
cls_Geom2dConvert_BSplineCurveToBezierCurve.def(py::init<const opencascade::handle<Geom2d_BSplineCurve> &>(), py::arg("BasisCurve"));
cls_Geom2dConvert_BSplineCurveToBezierCurve.def(py::init<const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("BasisCurve"), py::arg("U1"), py::arg("U2"), py::arg("ParametricTolerance"));

// Methods
// cls_Geom2dConvert_BSplineCurveToBezierCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dConvert_BSplineCurveToBezierCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dConvert_BSplineCurveToBezierCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dConvert_BSplineCurveToBezierCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dConvert_BSplineCurveToBezierCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dConvert_BSplineCurveToBezierCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dConvert_BSplineCurveToBezierCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dConvert_BSplineCurveToBezierCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dConvert_BSplineCurveToBezierCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dConvert_BSplineCurveToBezierCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dConvert_BSplineCurveToBezierCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dConvert_BSplineCurveToBezierCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dConvert_BSplineCurveToBezierCurve.def("Arc", (opencascade::handle<Geom2d_BezierCurve> (Geom2dConvert_BSplineCurveToBezierCurve::*)(const Standard_Integer)) &Geom2dConvert_BSplineCurveToBezierCurve::Arc, "Constructs and returns the Bezier curve of index Index to the table of adjacent Bezier arcs computed by this algorithm. This Bezier curve has the same orientation as the BSpline curve analyzed in this framework. Exceptions Standard_OutOfRange if Index is less than 1 or greater than the number of adjacent Bezier arcs computed by this algorithm.", py::arg("Index"));
cls_Geom2dConvert_BSplineCurveToBezierCurve.def("Arcs", (void (Geom2dConvert_BSplineCurveToBezierCurve::*)(TColGeom2d_Array1OfBezierCurve &)) &Geom2dConvert_BSplineCurveToBezierCurve::Arcs, "Constructs all the Bezier curves whose data is computed by this algorithm and loads these curves into the Curves table. The Bezier curves have the same orientation as the BSpline curve analyzed in this framework. Exceptions Standard_DimensionError if the Curves array was not created with the following bounds: - 1 , and - the number of adjacent Bezier arcs computed by this algorithm (as given by the function NbArcs).", py::arg("Curves"));
cls_Geom2dConvert_BSplineCurveToBezierCurve.def("Knots", (void (Geom2dConvert_BSplineCurveToBezierCurve::*)(TColStd_Array1OfReal &) const) &Geom2dConvert_BSplineCurveToBezierCurve::Knots, "This methode returns the bspline's knots associated to the converted arcs Raises DimensionError if the length of Curves is not equal to NbArcs + 1", py::arg("TKnots"));
cls_Geom2dConvert_BSplineCurveToBezierCurve.def("NbArcs", (Standard_Integer (Geom2dConvert_BSplineCurveToBezierCurve::*)() const) &Geom2dConvert_BSplineCurveToBezierCurve::NbArcs, "Returns the number of BezierCurve arcs. If at the creation time you have decomposed the basis curve between the parametric values UFirst, ULast the number of BezierCurve arcs depends on the number of knots included inside the interval [UFirst, ULast]. If you have decomposed the whole basis B-spline curve the number of BezierCurve arcs NbArcs is equal to the number of knots less one.");


}
