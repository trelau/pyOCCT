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
#include <Geom2dGcc_QualifiedCurve.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Geom2dGcc_CurveTool.hxx>
#include <Geom2dGcc_Circ2d3Tan.hxx>
#include <Geom2dGcc_Circ2d2TanRad.hxx>
#include <Geom2dGcc_Circ2d2TanOn.hxx>
#include <Geom2dGcc_Circ2dTanOnRad.hxx>
#include <Geom2dGcc_Circ2dTanCen.hxx>
#include <Geom2dGcc_Lin2d2Tan.hxx>
#include <Geom2dGcc_Lin2dTanObl.hxx>
#include <Geom2dGcc_QCurve.hxx>
#include <Geom2dGcc_Circ2d2TanOnGeo.hxx>
#include <Geom2dGcc_Circ2d2TanRadGeo.hxx>
#include <Geom2dGcc_Circ2dTanCenGeo.hxx>
#include <Geom2dGcc_Circ2dTanOnRadGeo.hxx>
#include <Geom2dGcc_Circ2d3TanIter.hxx>
#include <Geom2dGcc_FunctionTanCuCuCu.hxx>
#include <Geom2dGcc_Circ2d2TanOnIter.hxx>
#include <Geom2dGcc_FunctionTanCuCuOnCu.hxx>
#include <Geom2dGcc_Lin2dTanOblIter.hxx>
#include <Geom2dGcc_FunctionTanObl.hxx>
#include <Geom2dGcc_Lin2d2TanIter.hxx>
#include <Geom2dGcc_FunctionTanCuCu.hxx>
#include <Geom2dGcc_FunctionTanCuPnt.hxx>
#include <Geom2dGcc_FunctionTanCirCu.hxx>
#include <Geom2dGcc.hxx>

void bind_Geom2dGcc(py::module &mod){

py::class_<Geom2dGcc, std::unique_ptr<Geom2dGcc>> cls_Geom2dGcc(mod, "Geom2dGcc", "The Geom2dGcc package describes qualified 2D curves used in the construction of constrained geometric objects by an algorithm provided by the Geom2dGcc package. A qualified 2D curve is a curve with a qualifier which specifies whether the solution of a construction algorithm using the qualified curve (as an argument): - encloses the curve, or - is enclosed by the curve, or - is built so that both the curve and this solution are external to one another, or - is undefined (all solutions apply). These package methods provide simpler functions to construct a qualified curve. Note: the interior of a curve is defined as the left-hand side of the curve in relation to its orientation.");

// Constructors

// Fields

// Methods
// cls_Geom2dGcc.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc.def_static("Unqualified_", (Geom2dGcc_QualifiedCurve (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc::Unqualified, "Constructs such a qualified curve that the relative position of the solution computed by a construction algorithm using the qualified curve to the circle or line is not qualified, i.e. all solutions apply. Warning Obj is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve Obj ( mycurve ) ; The qualified curve is then constructed with this object: Geom2dGcc_QualifiedCurve myQCurve = Geom2dGcc::Unqualified(Obj);", py::arg("Obj"));
cls_Geom2dGcc.def_static("Enclosing_", (Geom2dGcc_QualifiedCurve (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc::Enclosing, "Constructs such a qualified curve that the solution computed by a construction algorithm using the qualified curve encloses the curve. Warning Obj is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve Obj ( mycurve ) ; The qualified curve is then constructed with this object: Geom2dGcc_QualifiedCurve myQCurve = Geom2dGcc::Enclosing(Obj);", py::arg("Obj"));
cls_Geom2dGcc.def_static("Enclosed_", (Geom2dGcc_QualifiedCurve (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc::Enclosed, "Constructs such a qualified curve that the solution computed by a construction algorithm using the qualified curve is enclosed by the curve. Warning Obj is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve Obj ( mycurve ) ; The qualified curve is then constructed with this object: Geom2dGcc_QualifiedCurve myQCurve = Geom2dGcc::Enclosed(Obj);", py::arg("Obj"));
cls_Geom2dGcc.def_static("Outside_", (Geom2dGcc_QualifiedCurve (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc::Outside, "Constructs such a qualified curve that the solution computed by a construction algorithm using the qualified curve and the curve are external to one another. Warning Obj is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve Obj ( mycurve ) ; The qualified curve is then constructed with this object: Geom2dGcc_QualifiedCurve myQCurve = Geom2dGcc::Outside(Obj);", py::arg("Obj"));

// Enums

}