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
#include <Law_BSpline.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Law_BSplineKnotSplitting.hxx>

void bind_Law_BSplineKnotSplitting(py::module &mod){

py::class_<Law_BSplineKnotSplitting, std::unique_ptr<Law_BSplineKnotSplitting>> cls_Law_BSplineKnotSplitting(mod, "Law_BSplineKnotSplitting", "For a B-spline curve the discontinuities are localised at the knot values and between two knots values the B-spline is infinitely continuously differentiable. At a knot of range index the continuity is equal to : Degree - Mult (Index) where Degree is the degree of the basis B-spline functions and Mult the multiplicity of the knot of range Index. If for your computation you need to have B-spline curves with a minima of continuity it can be interesting to know between which knot values, a B-spline curve arc, has a continuity of given order. This algorithm computes the indexes of the knots where you should split the curve, to obtain arcs with a constant continuity given at the construction time. The splitting values are in the range [FirstUKnotValue, LastUKnotValue] (See class B-spline curve from package Geom). If you just want to compute the local derivatives on the curve you don't need to create the B-spline curve arcs, you can use the functions LocalD1, LocalD2, LocalD3, LocalDN of the class BSplineCurve.");

// Constructors
cls_Law_BSplineKnotSplitting.def(py::init<const opencascade::handle<Law_BSpline> &, const Standard_Integer>(), py::arg("BasisLaw"), py::arg("ContinuityRange"));

// Fields

// Methods
// cls_Law_BSplineKnotSplitting.def_static("operator new_", (void * (*)(size_t)) &Law_BSplineKnotSplitting::operator new, "None", py::arg("theSize"));
// cls_Law_BSplineKnotSplitting.def_static("operator delete_", (void (*)(void *)) &Law_BSplineKnotSplitting::operator delete, "None", py::arg("theAddress"));
// cls_Law_BSplineKnotSplitting.def_static("operator new[]_", (void * (*)(size_t)) &Law_BSplineKnotSplitting::operator new[], "None", py::arg("theSize"));
// cls_Law_BSplineKnotSplitting.def_static("operator delete[]_", (void (*)(void *)) &Law_BSplineKnotSplitting::operator delete[], "None", py::arg("theAddress"));
// cls_Law_BSplineKnotSplitting.def_static("operator new_", (void * (*)(size_t, void *)) &Law_BSplineKnotSplitting::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Law_BSplineKnotSplitting.def_static("operator delete_", (void (*)(void *, void *)) &Law_BSplineKnotSplitting::operator delete, "None", py::arg(""), py::arg(""));
cls_Law_BSplineKnotSplitting.def("NbSplits", (Standard_Integer (Law_BSplineKnotSplitting::*)() const) &Law_BSplineKnotSplitting::NbSplits, "Returns the number of knots corresponding to the splitting.");
cls_Law_BSplineKnotSplitting.def("Splitting", (void (Law_BSplineKnotSplitting::*)(TColStd_Array1OfInteger &) const) &Law_BSplineKnotSplitting::Splitting, "Returns the indexes of the BSpline curve knots corresponding to the splitting.", py::arg("SplitValues"));
cls_Law_BSplineKnotSplitting.def("SplitValue", (Standard_Integer (Law_BSplineKnotSplitting::*)(const Standard_Integer) const) &Law_BSplineKnotSplitting::SplitValue, "Returns the index of the knot corresponding to the splitting of range Index.", py::arg("Index"));

// Enums

}