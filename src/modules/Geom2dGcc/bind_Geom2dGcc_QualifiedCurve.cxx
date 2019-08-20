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
#include <Geom2dAdaptor_Curve.hxx>
#include <GccEnt_Position.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dGcc_QualifiedCurve.hxx>

void bind_Geom2dGcc_QualifiedCurve(py::module &mod){

py::class_<Geom2dGcc_QualifiedCurve, std::unique_ptr<Geom2dGcc_QualifiedCurve>> cls_Geom2dGcc_QualifiedCurve(mod, "Geom2dGcc_QualifiedCurve", "Describes functions for building a qualified 2D curve. A qualified 2D curve is a curve with a qualifier which specifies whether the solution of a construction algorithm using the qualified curve (as an argument): - encloses the curve, or - is enclosed by the curve, or - is built so that both the curve and it are external to one another, or - is undefined (all solutions apply).");

// Constructors
cls_Geom2dGcc_QualifiedCurve.def(py::init<const Geom2dAdaptor_Curve &, const GccEnt_Position>(), py::arg("Curve"), py::arg("Qualifier"));

// Fields

// Methods
// cls_Geom2dGcc_QualifiedCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_QualifiedCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_QualifiedCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_QualifiedCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_QualifiedCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_QualifiedCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_QualifiedCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_QualifiedCurve.def("Qualified", (Geom2dAdaptor_Curve (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::Qualified, "Returns a 2D curve to which the qualifier is assigned. Warning The returned curve is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The Geom2d curve on which the adapted curve is based can be obtained in the following way: myQualifiedCurve = ... ; Geom2dAdaptor_Curve myAdaptedCurve = myQualifiedCurve.Qualified(); Handle(Geom2d_Curve) = myAdaptedCurve.Curve();");
cls_Geom2dGcc_QualifiedCurve.def("Qualifier", (GccEnt_Position (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::Qualifier, "Returns - the qualifier of this qualified curve if it is enclosing, enclosed or outside, or - GccEnt_noqualifier if it is unqualified.");
cls_Geom2dGcc_QualifiedCurve.def("IsUnqualified", (Standard_Boolean (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::IsUnqualified, "Returns true if the solution is unqualified and false in the other cases.");
cls_Geom2dGcc_QualifiedCurve.def("IsEnclosing", (Standard_Boolean (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::IsEnclosing, "It returns true if the solution is Enclosing the Curv and false in the other cases.");
cls_Geom2dGcc_QualifiedCurve.def("IsEnclosed", (Standard_Boolean (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::IsEnclosed, "It returns true if the solution is Enclosed in the Curv and false in the other cases.");
cls_Geom2dGcc_QualifiedCurve.def("IsOutside", (Standard_Boolean (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::IsOutside, "It returns true if the solution is Outside the Curv and false in the other cases.");

// Enums

}