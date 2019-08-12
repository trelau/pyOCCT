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
#include <Extrema_POnCurv2d.hxx>
#include <Extrema_LocECC2d.hxx>

void bind_Extrema_LocECC2d(py::module &mod){

py::class_<Extrema_LocECC2d, std::unique_ptr<Extrema_LocECC2d, Deleter<Extrema_LocECC2d>>> cls_Extrema_LocECC2d(mod, "Extrema_LocECC2d", "None");

// Constructors
cls_Extrema_LocECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U0"), py::arg("V0"), py::arg("TolU"), py::arg("TolV"));

// Fields

// Methods
// cls_Extrema_LocECC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocECC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocECC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_LocECC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocECC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocECC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocECC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocECC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocECC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocECC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocECC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocECC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocECC2d.def("IsDone", (Standard_Boolean (Extrema_LocECC2d::*)() const) &Extrema_LocECC2d::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocECC2d.def("SquareDistance", (Standard_Real (Extrema_LocECC2d::*)() const) &Extrema_LocECC2d::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocECC2d.def("Point", (void (Extrema_LocECC2d::*)(Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_LocECC2d::Point, "Returns the points of the extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("P1"), py::arg("P2"));

// Enums

}