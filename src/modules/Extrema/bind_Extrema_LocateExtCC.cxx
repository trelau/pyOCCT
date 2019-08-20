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
#include <Extrema_LocateExtCC.hxx>

void bind_Extrema_LocateExtCC(py::module &mod){

py::class_<Extrema_LocateExtCC, std::unique_ptr<Extrema_LocateExtCC>> cls_Extrema_LocateExtCC(mod, "Extrema_LocateExtCC", "It calculates the distance between two curves with a close point; these distances can be maximum or minimum.");

// Constructors
cls_Extrema_LocateExtCC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("U0"), py::arg("V0"));

// Fields

// Methods
// cls_Extrema_LocateExtCC.def_static("operator new_", (void * (*)(size_t)) &Extrema_LocateExtCC::operator new, "None", py::arg("theSize"));
// cls_Extrema_LocateExtCC.def_static("operator delete_", (void (*)(void *)) &Extrema_LocateExtCC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_LocateExtCC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_LocateExtCC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_LocateExtCC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_LocateExtCC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_LocateExtCC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_LocateExtCC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_LocateExtCC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_LocateExtCC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_LocateExtCC.def("IsDone", (Standard_Boolean (Extrema_LocateExtCC::*)() const) &Extrema_LocateExtCC::IsDone, "Returns True if the distance is found.");
cls_Extrema_LocateExtCC.def("SquareDistance", (Standard_Real (Extrema_LocateExtCC::*)() const) &Extrema_LocateExtCC::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_LocateExtCC.def("Point", (void (Extrema_LocateExtCC::*)(Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_LocateExtCC::Point, "Returns the points of the extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("P1"), py::arg("P2"));

// Enums

}