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
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <BndLib_Add2dCurve.hxx>

void bind_BndLib_Add2dCurve(py::module &mod){

py::class_<BndLib_Add2dCurve, std::unique_ptr<BndLib_Add2dCurve, Deleter<BndLib_Add2dCurve>>> cls_BndLib_Add2dCurve(mod, "BndLib_Add2dCurve", "Computes the bounding box for a curve in 2d . Functions to add a 2D curve to a bounding box. The 2D curve is defined from a Geom2d curve.");

// Constructors

// Fields

// Methods
// cls_BndLib_Add2dCurve.def_static("operator new_", (void * (*)(size_t)) &BndLib_Add2dCurve::operator new, "None", py::arg("theSize"));
// cls_BndLib_Add2dCurve.def_static("operator delete_", (void (*)(void *)) &BndLib_Add2dCurve::operator delete, "None", py::arg("theAddress"));
// cls_BndLib_Add2dCurve.def_static("operator new[]_", (void * (*)(size_t)) &BndLib_Add2dCurve::operator new[], "None", py::arg("theSize"));
// cls_BndLib_Add2dCurve.def_static("operator delete[]_", (void (*)(void *)) &BndLib_Add2dCurve::operator delete[], "None", py::arg("theAddress"));
// cls_BndLib_Add2dCurve.def_static("operator new_", (void * (*)(size_t, void *)) &BndLib_Add2dCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BndLib_Add2dCurve.def_static("operator delete_", (void (*)(void *, void *)) &BndLib_Add2dCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_BndLib_Add2dCurve.def_static("Add_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::Add, "Adds to the bounding box B the curve C B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, - if not, the points of an approximation of the curve C. Warning C is an adapted curve, that is, an object which is an interface between: - the services provided by a 2D curve from the package Geom2d - and those required of the curve by the computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve C(mycurve); The bounding box B is then enlarged by adding it: Bnd_Box2d B; // ... Standard_Real Tol = ... ; Add2dCurve::Add ( C, Tol, B ); Exceptions Standard_Failure if the curve is built from: - a Geom_Line, or - a Geom_Parabola, or - a Geom_Hyperbola, and P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add2dCurve.def_static("Add_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::Add, "Adds to the bounding box Bthe arc of the curve C limited by the two parameter values P1 and P2. B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, - if not, the points of an approximation of the curve C. Warning C is an adapted curve, that is, an object which is an interface between: - the services provided by a 2D curve from the package Geom2d - and those required of the curve by the computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve C(mycurve); The bounding box B is then enlarged by adding it: Bnd_Box2d B; // ... Standard_Real Tol = ... ; Add2dCurve::Add ( C, Tol, B ); Exceptions Standard_Failure if the curve is built from: - a Geom_Line, or - a Geom_Parabola, or - a Geom_Hyperbola, and P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add2dCurve.def_static("Add_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::Add, "Adds to the bounding box B the curve C B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, - if not, the points of an approximation of the curve C.", py::arg("C"), py::arg("Tol"), py::arg("Box"));
cls_BndLib_Add2dCurve.def_static("Add_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::Add, "Adds to the bounding box B the part of curve C B is then enlarged by the tolerance value Tol. U1, U2 - the parametric range to comute the bounding box; Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, - if not, the points of an approximation of the curve C.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add2dCurve.def_static("AddOptimal_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib_Add2dCurve::AddOptimal, "Adds to the bounding box B the part of curve C B is then enlarged by the tolerance value Tol. U1, U2 - the parametric range to comute the bounding box; Note: depending on the type of curve, one of the following algorithms is used to include it in the bounding box B: - an exact analytical if C is built from a line, a circle or a conic curve, - numerical calculation of bounding box sizes, based on minimization algorithm, for other types of curve If Tol = < Precision::PConfusion(), Precision::PConfusion is used as tolerance for calculation", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));

// Enums

}