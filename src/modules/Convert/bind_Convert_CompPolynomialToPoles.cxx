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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <Convert_CompPolynomialToPoles.hxx>

void bind_Convert_CompPolynomialToPoles(py::module &mod){

py::class_<Convert_CompPolynomialToPoles> cls_Convert_CompPolynomialToPoles(mod, "Convert_CompPolynomialToPoles", "Convert a serie of Polynomial N-Dimensional Curves that are have continuity CM to an N-Dimensional Bspline Curve that has continuity CM. (to convert an function (curve) polynomial by span in a BSpline) This class uses the following arguments : NumCurves : the number of Polynomial Curves Continuity: the requested continuity for the n-dimensional Spline Dimension : the dimension of the Spline MaxDegree : maximum allowed degree for each composite polynomial segment. NumCoeffPerCurve : the number of coefficient per segments = degree - 1 Coefficients : the coefficients organized in the following way [1..<myNumPolynomials>][1..myMaxDegree +1][1..myDimension] that is : index [n,d,i] is at slot (n-1) * (myMaxDegree + 1) * myDimension + (d-1) * myDimension + i PolynomialIntervals : nth polynomial represents a polynomial between myPolynomialIntervals->Value(n,0) and myPolynomialIntervals->Value(n,1) TrueIntervals : the nth polynomial has to be mapped linearly to be defined on the following interval : myTrueIntervals->Value(n) and myTrueIntervals->Value(n+1) so that it represent adequatly the function with the required continuity");

// Constructors
cls_Convert_CompPolynomialToPoles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &>(), py::arg("NumCurves"), py::arg("Continuity"), py::arg("Dimension"), py::arg("MaxDegree"), py::arg("NumCoeffPerCurve"), py::arg("Coefficients"), py::arg("PolynomialIntervals"), py::arg("TrueIntervals"));
cls_Convert_CompPolynomialToPoles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array1OfInteger &, const TColStd_Array1OfInteger &, const TColStd_Array1OfReal &, const TColStd_Array2OfReal &, const TColStd_Array1OfReal &>(), py::arg("NumCurves"), py::arg("Dimension"), py::arg("MaxDegree"), py::arg("Continuity"), py::arg("NumCoeffPerCurve"), py::arg("Coefficients"), py::arg("PolynomialIntervals"), py::arg("TrueIntervals"));
cls_Convert_CompPolynomialToPoles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("Dimension"), py::arg("MaxDegree"), py::arg("Degree"), py::arg("Coefficients"), py::arg("PolynomialIntervals"), py::arg("TrueIntervals"));

// Fields

// Methods
// cls_Convert_CompPolynomialToPoles.def_static("operator new_", (void * (*)(size_t)) &Convert_CompPolynomialToPoles::operator new, "None", py::arg("theSize"));
// cls_Convert_CompPolynomialToPoles.def_static("operator delete_", (void (*)(void *)) &Convert_CompPolynomialToPoles::operator delete, "None", py::arg("theAddress"));
// cls_Convert_CompPolynomialToPoles.def_static("operator new[]_", (void * (*)(size_t)) &Convert_CompPolynomialToPoles::operator new[], "None", py::arg("theSize"));
// cls_Convert_CompPolynomialToPoles.def_static("operator delete[]_", (void (*)(void *)) &Convert_CompPolynomialToPoles::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_CompPolynomialToPoles.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_CompPolynomialToPoles::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_CompPolynomialToPoles.def_static("operator delete_", (void (*)(void *, void *)) &Convert_CompPolynomialToPoles::operator delete, "None", py::arg(""), py::arg(""));
cls_Convert_CompPolynomialToPoles.def("NbPoles", (Standard_Integer (Convert_CompPolynomialToPoles::*)() const) &Convert_CompPolynomialToPoles::NbPoles, "number of poles of the n-dimensional BSpline");
cls_Convert_CompPolynomialToPoles.def("Poles", (void (Convert_CompPolynomialToPoles::*)(opencascade::handle<TColStd_HArray2OfReal> &) const) &Convert_CompPolynomialToPoles::Poles, "returns the poles of the n-dimensional BSpline in the following format : [1..NumPoles][1..Dimension]", py::arg("Poles"));
cls_Convert_CompPolynomialToPoles.def("Degree", (Standard_Integer (Convert_CompPolynomialToPoles::*)() const) &Convert_CompPolynomialToPoles::Degree, "None");
cls_Convert_CompPolynomialToPoles.def("NbKnots", (Standard_Integer (Convert_CompPolynomialToPoles::*)() const) &Convert_CompPolynomialToPoles::NbKnots, "Degree of the n-dimensional Bspline");
cls_Convert_CompPolynomialToPoles.def("Knots", (void (Convert_CompPolynomialToPoles::*)(opencascade::handle<TColStd_HArray1OfReal> &) const) &Convert_CompPolynomialToPoles::Knots, "Knots of the n-dimensional Bspline", py::arg("K"));
cls_Convert_CompPolynomialToPoles.def("Multiplicities", (void (Convert_CompPolynomialToPoles::*)(opencascade::handle<TColStd_HArray1OfInteger> &) const) &Convert_CompPolynomialToPoles::Multiplicities, "Multiplicities of the knots in the BSpline", py::arg("M"));
cls_Convert_CompPolynomialToPoles.def("IsDone", (Standard_Boolean (Convert_CompPolynomialToPoles::*)() const) &Convert_CompPolynomialToPoles::IsDone, "None");

// Enums

}