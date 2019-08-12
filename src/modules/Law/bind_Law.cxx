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
#include <Law_BSpFunc.hxx>
#include <Law_Linear.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Law_BSpline.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Law_Interpolate.hxx>
#include <Law_Function.hxx>
#include <Law_Constant.hxx>
#include <Law_S.hxx>
#include <Law_Interpol.hxx>
#include <Law_Composite.hxx>
#include <Law_BSplineKnotSplitting.hxx>
#include <Law.hxx>

void bind_Law(py::module &mod){

py::class_<Law, std::unique_ptr<Law, Deleter<Law>>> cls_Law(mod, "Law", "Multiple services concerning 1d functions.");

// Constructors

// Fields

// Methods
// cls_Law.def_static("operator new_", (void * (*)(size_t)) &Law::operator new, "None", py::arg("theSize"));
// cls_Law.def_static("operator delete_", (void (*)(void *)) &Law::operator delete, "None", py::arg("theAddress"));
// cls_Law.def_static("operator new[]_", (void * (*)(size_t)) &Law::operator new[], "None", py::arg("theSize"));
// cls_Law.def_static("operator delete[]_", (void (*)(void *)) &Law::operator delete[], "None", py::arg("theAddress"));
// cls_Law.def_static("operator new_", (void * (*)(size_t, void *)) &Law::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Law.def_static("operator delete_", (void (*)(void *, void *)) &Law::operator delete, "None", py::arg(""), py::arg(""));
cls_Law.def_static("MixBnd_", (opencascade::handle<Law_BSpFunc> (*)(const opencascade::handle<Law_Linear> &)) &Law::MixBnd, "This algorithm searches the knot values corresponding to the splitting of a given B-spline law into several arcs with the same continuity. The continuity order is given at the construction time. Builds a 1d bspline that is near from Lin with null derivatives at the extremities.", py::arg("Lin"));
cls_Law.def_static("MixBnd_", (opencascade::handle<TColStd_HArray1OfReal> (*)(const Standard_Integer, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const opencascade::handle<Law_Linear> &)) &Law::MixBnd, "Builds the poles of the 1d bspline that is near from Lin with null derivatives at the extremities.", py::arg("Degree"), py::arg("Knots"), py::arg("Mults"), py::arg("Lin"));
cls_Law.def_static("MixTgt_", (opencascade::handle<TColStd_HArray1OfReal> (*)(const Standard_Integer, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Boolean, const Standard_Integer)) &Law::MixTgt, "Builds the poles of the 1d bspline that is null on the rigth side of Knots(Index) (on the left if NulOnTheRight is false) and that is like a t*(1-t)(1-t) curve on the left side of Knots(Index) (on the rigth if NulOnTheRight is false). The result curve is C1 with a derivative equal to 1. at first parameter (-1 at last parameter if NulOnTheRight is false). Warning: Mults(Index) must greater or equal to degree-1.", py::arg("Degree"), py::arg("Knots"), py::arg("Mults"), py::arg("NulOnTheRight"), py::arg("Index"));
cls_Law.def_static("Reparametrize_", (opencascade::handle<Law_BSpline> (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer)) &Law::Reparametrize, "Computes a 1 d curve to reparametrize a curve. Its an interpolation of NbPoints points calculated at quasi constant abscissa.", py::arg("Curve"), py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DFirst"), py::arg("DLast"), py::arg("Rev"), py::arg("NbPoints"));
cls_Law.def_static("Scale_", (opencascade::handle<Law_BSpline> (*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real)) &Law::Scale, "Computes a 1 d curve to scale a field of tangency. Value is 1. for t = (First+Last)/2 . If HasFirst value for t = First is VFirst (null derivative). If HasLast value for t = Last is VLast (null derivative).", py::arg("First"), py::arg("Last"), py::arg("HasF"), py::arg("HasL"), py::arg("VFirst"), py::arg("VLast"));
cls_Law.def_static("ScaleCub_", (opencascade::handle<Law_BSpline> (*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real)) &Law::ScaleCub, "None", py::arg("First"), py::arg("Last"), py::arg("HasF"), py::arg("HasL"), py::arg("VFirst"), py::arg("VLast"));

// Enums

}