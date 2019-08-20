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
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <BndLib_Add3dCurve.hxx>

void bind_BndLib_Add3dCurve(py::module &mod){

py::class_<BndLib_Add3dCurve, std::unique_ptr<BndLib_Add3dCurve>> cls_BndLib_Add3dCurve(mod, "BndLib_Add3dCurve", "Computes the bounding box for a curve in 3d. Functions to add a 3D curve to a bounding box. The 3D curve is defined from a Geom curve.");

// Constructors

// Fields

// Methods
// cls_BndLib_Add3dCurve.def_static("operator new_", (void * (*)(size_t)) &BndLib_Add3dCurve::operator new, "None", py::arg("theSize"));
// cls_BndLib_Add3dCurve.def_static("operator delete_", (void (*)(void *)) &BndLib_Add3dCurve::operator delete, "None", py::arg("theAddress"));
// cls_BndLib_Add3dCurve.def_static("operator new[]_", (void * (*)(size_t)) &BndLib_Add3dCurve::operator new[], "None", py::arg("theSize"));
// cls_BndLib_Add3dCurve.def_static("operator delete[]_", (void (*)(void *)) &BndLib_Add3dCurve::operator delete[], "None", py::arg("theAddress"));
// cls_BndLib_Add3dCurve.def_static("operator new_", (void * (*)(size_t, void *)) &BndLib_Add3dCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BndLib_Add3dCurve.def_static("operator delete_", (void (*)(void *, void *)) &BndLib_Add3dCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_BndLib_Add3dCurve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::Add, "Adds to the bounding box B the curve C B is then enlarged by the tolerance value Tol. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, if not, the points of an approximation of the curve C. Warning C is an adapted curve, that is, an object which is an interface between: - the services provided by a 3D curve from the package Geom - and those required of the curve by the computation algorithm. The adapted curve is created in the following way: Handle(Geom_Curve) mycurve = ... ; GeomAdaptor_Curve C(mycurve); The bounding box B is then enlarged by adding it: Bnd_Box B; // ... Standard_Real Tol = ... ; Add3dCurve::Add ( C, Tol, B ); Exceptions Standard_Failure if the curve is built from: - a Geom_Line, or - a Geom_Parabola, or - a Geom_Hyperbola, and P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add3dCurve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::Add, "Adds to the bounding box B the curve C the arc of the curve C limited by the two parameter values P1 and P2. Note: depending on the type of curve, one of the following representations of the curve C is used to include it in the bounding box B: - an exact representation if C is built from a line, a circle or a conic curve, - the poles of the curve if C is built from a Bezier curve or a BSpline curve, if not, the points of an approximation of the curve C. Warning C is an adapted curve, that is, an object which is an interface between: - the services provided by a 3D curve from the package Geom - and those required of the curve by the computation algorithm. The adapted curve is created in the following way: Handle(Geom_Curve) mycurve = ... ; GeomAdaptor_Curve C(mycurve); The bounding box B is then enlarged by adding it: Bnd_Box B; // ... Standard_Real Tol = ... ; Add3dCurve::Add ( C, Tol, B ); Exceptions Standard_Failure if the curve is built from: - a Geom_Line, or - a Geom_Parabola, or - a Geom_Hyperbola, and P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add3dCurve.def_static("AddOptimal_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::AddOptimal, "Adds to the bounding box B the curve C These methods use more precise algorithms for building bnd box then methods Add(...)", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add3dCurve.def_static("AddOptimal_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::AddOptimal, "None", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("B"));
cls_BndLib_Add3dCurve.def_static("AddGenCurv_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib_Add3dCurve::AddGenCurv, "Adds to the bounding box B the curve C using numerical minimization algorithms This method is used in AddOptimal for not analytical curves. if Tol < Precision::Confusion(), Precision:;Confusion is used as computation tolerance", py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("Tol"), py::arg("B"));

// Enums

}