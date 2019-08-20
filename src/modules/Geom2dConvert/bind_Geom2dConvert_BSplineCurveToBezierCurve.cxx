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
#include <Geom2d_BezierCurve.hxx>
#include <TColGeom2d_Array1OfBezierCurve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dConvert_BSplineCurveToBezierCurve.hxx>

void bind_Geom2dConvert_BSplineCurveToBezierCurve(py::module &mod){

py::class_<Geom2dConvert_BSplineCurveToBezierCurve, std::unique_ptr<Geom2dConvert_BSplineCurveToBezierCurve>> cls_Geom2dConvert_BSplineCurveToBezierCurve(mod, "Geom2dConvert_BSplineCurveToBezierCurve", "An algorithm to convert a BSpline curve into a series of adjacent Bezier curves. A BSplineCurveToBezierCurve object provides a framework for: - defining the BSpline curve to be converted - implementing the construction algorithm, and - consulting the results. References : Generating the Bezier points of B-spline curves and surfaces (Wolfgang Bohm) CAD volume 13 number 6 november 1981");

// Constructors
cls_Geom2dConvert_BSplineCurveToBezierCurve.def(py::init<const opencascade::handle<Geom2d_BSplineCurve> &>(), py::arg("BasisCurve"));
cls_Geom2dConvert_BSplineCurveToBezierCurve.def(py::init<const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("BasisCurve"), py::arg("U1"), py::arg("U2"), py::arg("ParametricTolerance"));

// Fields

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

// Enums

}