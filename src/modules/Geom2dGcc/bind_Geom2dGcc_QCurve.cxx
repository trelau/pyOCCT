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
#include <Geom2dGcc_QCurve.hxx>

void bind_Geom2dGcc_QCurve(py::module &mod){

py::class_<Geom2dGcc_QCurve, std::unique_ptr<Geom2dGcc_QCurve, Deleter<Geom2dGcc_QCurve>>> cls_Geom2dGcc_QCurve(mod, "Geom2dGcc_QCurve", "Creates a qualified 2d line.");

// Constructors
cls_Geom2dGcc_QCurve.def(py::init<const Geom2dAdaptor_Curve &, const GccEnt_Position>(), py::arg("Curve"), py::arg("Qualifier"));

// Fields

// Methods
// cls_Geom2dGcc_QCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_QCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_QCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_QCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_QCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_QCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_QCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_QCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_QCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_QCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_QCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_QCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_QCurve.def("Qualified", (Geom2dAdaptor_Curve (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::Qualified, "None");
cls_Geom2dGcc_QCurve.def("Qualifier", (GccEnt_Position (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::Qualifier, "None");
cls_Geom2dGcc_QCurve.def("IsUnqualified", (Standard_Boolean (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::IsUnqualified, "Returns true if the solution is unqualified and false in the other cases.");
cls_Geom2dGcc_QCurve.def("IsEnclosing", (Standard_Boolean (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::IsEnclosing, "Returns true if the solution is Enclosing the Curv and false in the other cases.");
cls_Geom2dGcc_QCurve.def("IsEnclosed", (Standard_Boolean (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::IsEnclosed, "Returns true if the solution is Enclosed in the Curv and false in the other cases.");
cls_Geom2dGcc_QCurve.def("IsOutside", (Standard_Boolean (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::IsOutside, "Returns true if the solution is Outside the Curv and false in the other cases.");

// Enums

}