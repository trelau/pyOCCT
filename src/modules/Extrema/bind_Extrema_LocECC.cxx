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
#include <Extrema_POnCurv.hxx>
#include <Extrema_LocECC.hxx>

void bind_Extrema_LocECC(py::module &mod){

py::class_<Extrema_LocECC, std::unique_ptr<Extrema_LocECC>> cls_Extrema_LocECC(mod, "Extrema_LocECC", "None");

// Constructors
cls_Extrema_LocECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U0"), py::arg("V0"), py::arg("TolU"), py::arg("TolV"));

// Fields

// Methods
// cls_Extrema_LocECC.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocECC::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocECC.def_static("operator delete_", (void (*)(void *)) &Extrema_LocECC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocECC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocECC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocECC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocECC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocECC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocECC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocECC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocECC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocECC.def("IsDone", (Standard_Boolean (Extrema_LocECC::*)() const) &Extrema_LocECC::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocECC.def("SquareDistance", (Standard_Real (Extrema_LocECC::*)() const) &Extrema_LocECC::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocECC.def("Point", (void (Extrema_LocECC::*)(Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_LocECC::Point, "Returns the points of the extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("P1"), py::arg("P2"));

// Enums

}