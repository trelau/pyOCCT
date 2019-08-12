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
#include <gp_Pnt2d.hxx>
#include <Convert_ParameterisationType.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <Convert_ConicToBSplineCurve.hxx>

void bind_Convert_ConicToBSplineCurve(py::module &mod){

py::class_<Convert_ConicToBSplineCurve, std::unique_ptr<Convert_ConicToBSplineCurve, Deleter<Convert_ConicToBSplineCurve>>> cls_Convert_ConicToBSplineCurve(mod, "Convert_ConicToBSplineCurve", "Root class for algorithms which convert a conic curve into a BSpline curve (CircleToBSplineCurve, EllipseToBSplineCurve, HyperbolaToBSplineCurve, ParabolaToBSplineCurve). These algorithms all work on 2D curves from the gp package and compute all the data needed to construct a BSpline curve equivalent to the conic curve. This data consists of: - the degree of the curve, - the periodic characteristics of the curve, - a poles table with associated weights, - a knots table with associated multiplicities. The abstract class ConicToBSplineCurve provides a framework for storing and consulting this computed data. The data may then be used to construct a Geom2d_BSplineCurve curvSuper class of the following classes : This abstract class implements the methods to get the geometric representation of the B-spline curve equivalent to the conic. The B-spline is computed at the creation time in the sub classes. The B-spline curve is defined with its degree, its control points (Poles), its weights, its knots and their multiplicity. All the geometric entities used in this package are defined in 2D space. KeyWords : Convert, Conic, BSplineCurve, 2D.");

// Constructors

// Fields

// Methods
// cls_Convert_ConicToBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &Convert_ConicToBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_Convert_ConicToBSplineCurve.def_static("operator delete_", (void (*)(void *)) &Convert_ConicToBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_Convert_ConicToBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &Convert_ConicToBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_Convert_ConicToBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &Convert_ConicToBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_ConicToBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_ConicToBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_ConicToBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &Convert_ConicToBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Convert_ConicToBSplineCurve.def("Degree", (Standard_Integer (Convert_ConicToBSplineCurve::*)() const) &Convert_ConicToBSplineCurve::Degree, "Returns the degree of the BSpline curve whose data is computed in this framework.");
cls_Convert_ConicToBSplineCurve.def("NbPoles", (Standard_Integer (Convert_ConicToBSplineCurve::*)() const) &Convert_ConicToBSplineCurve::NbPoles, "Returns the number of poles of the BSpline curve whose data is computed in this framework.");
cls_Convert_ConicToBSplineCurve.def("NbKnots", (Standard_Integer (Convert_ConicToBSplineCurve::*)() const) &Convert_ConicToBSplineCurve::NbKnots, "Returns the number of knots of the BSpline curve whose data is computed in this framework.");
cls_Convert_ConicToBSplineCurve.def("IsPeriodic", (Standard_Boolean (Convert_ConicToBSplineCurve::*)() const) &Convert_ConicToBSplineCurve::IsPeriodic, "Returns true if the BSpline curve whose data is computed in this framework is periodic.");
cls_Convert_ConicToBSplineCurve.def("Pole", (gp_Pnt2d (Convert_ConicToBSplineCurve::*)(const Standard_Integer) const) &Convert_ConicToBSplineCurve::Pole, "Returns the pole of index Index to the poles table of the BSpline curve whose data is computed in this framework. Exceptions Standard_OutOfRange if Index is outside the bounds of the poles table of the BSpline curve whose data is computed in this framework.", py::arg("Index"));
cls_Convert_ConicToBSplineCurve.def("Weight", (Standard_Real (Convert_ConicToBSplineCurve::*)(const Standard_Integer) const) &Convert_ConicToBSplineCurve::Weight, "Returns the weight of the pole of index Index to the poles table of the BSpline curve whose data is computed in this framework. Exceptions Standard_OutOfRange if Index is outside the bounds of the poles table of the BSpline curve whose data is computed in this framework.", py::arg("Index"));
cls_Convert_ConicToBSplineCurve.def("Knot", (Standard_Real (Convert_ConicToBSplineCurve::*)(const Standard_Integer) const) &Convert_ConicToBSplineCurve::Knot, "Returns the knot of index Index to the knots table of the BSpline curve whose data is computed in this framework. Exceptions Standard_OutOfRange if Index is outside the bounds of the knots table of the BSpline curve whose data is computed in this framework.", py::arg("Index"));
cls_Convert_ConicToBSplineCurve.def("Multiplicity", (Standard_Integer (Convert_ConicToBSplineCurve::*)(const Standard_Integer) const) &Convert_ConicToBSplineCurve::Multiplicity, "Returns the multiplicity of the knot of index Index to the knots table of the BSpline curve whose data is computed in this framework. Exceptions Standard_OutOfRange if Index is outside the bounds of the knots table of the BSpline curve whose data is computed in this framework.", py::arg("Index"));
cls_Convert_ConicToBSplineCurve.def("BuildCosAndSin", [](Convert_ConicToBSplineCurve &self, const Convert_ParameterisationType Parametrisation, opencascade::handle<TColStd_HArray1OfReal> & CosNumerator, opencascade::handle<TColStd_HArray1OfReal> & SinNumerator, opencascade::handle<TColStd_HArray1OfReal> & Denominator, Standard_Integer & Degree, opencascade::handle<TColStd_HArray1OfReal> & Knots, opencascade::handle<TColStd_HArray1OfInteger> & Mults){ self.BuildCosAndSin(Parametrisation, CosNumerator, SinNumerator, Denominator, Degree, Knots, Mults); return Degree; }, "None", py::arg("Parametrisation"), py::arg("CosNumerator"), py::arg("SinNumerator"), py::arg("Denominator"), py::arg("Degree"), py::arg("Knots"), py::arg("Mults"));
cls_Convert_ConicToBSplineCurve.def("BuildCosAndSin", [](Convert_ConicToBSplineCurve &self, const Convert_ParameterisationType Parametrisation, const Standard_Real UFirst, const Standard_Real ULast, opencascade::handle<TColStd_HArray1OfReal> & CosNumerator, opencascade::handle<TColStd_HArray1OfReal> & SinNumerator, opencascade::handle<TColStd_HArray1OfReal> & Denominator, Standard_Integer & Degree, opencascade::handle<TColStd_HArray1OfReal> & Knots, opencascade::handle<TColStd_HArray1OfInteger> & Mults){ self.BuildCosAndSin(Parametrisation, UFirst, ULast, CosNumerator, SinNumerator, Denominator, Degree, Knots, Mults); return Degree; }, "None", py::arg("Parametrisation"), py::arg("UFirst"), py::arg("ULast"), py::arg("CosNumerator"), py::arg("SinNumerator"), py::arg("Denominator"), py::arg("Degree"), py::arg("Knots"), py::arg("Mults"));

// Enums

}