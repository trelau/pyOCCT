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
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <Extrema_ExtElC2d.hxx>

void bind_Extrema_ExtElC2d(py::module &mod){

py::class_<Extrema_ExtElC2d> cls_Extrema_ExtElC2d(mod, "Extrema_ExtElC2d", "It calculates all the distance between two elementary curves. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtElC2d.def(py::init<>());
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Lin2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("AngTol"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Circ2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Elips2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Hypr2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Lin2d &, const gp_Parab2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Circ2d &, const gp_Circ2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Circ2d &, const gp_Elips2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Circ2d &, const gp_Hypr2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC2d.def(py::init<const gp_Circ2d &, const gp_Parab2d &>(), py::arg("C1"), py::arg("C2"));

// Fields

// Methods
// cls_Extrema_ExtElC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtElC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtElC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtElC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtElC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtElC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtElC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtElC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtElC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtElC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtElC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtElC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtElC2d.def("IsDone", (Standard_Boolean (Extrema_ExtElC2d::*)() const) &Extrema_ExtElC2d::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtElC2d.def("IsParallel", (Standard_Boolean (Extrema_ExtElC2d::*)() const) &Extrema_ExtElC2d::IsParallel, "Returns True if the two curves are parallel.");
cls_Extrema_ExtElC2d.def("NbExt", (Standard_Integer (Extrema_ExtElC2d::*)() const) &Extrema_ExtElC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtElC2d.def("SquareDistance", [](Extrema_ExtElC2d &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtElC2d.def("SquareDistance", (Standard_Real (Extrema_ExtElC2d::*)(const Standard_Integer) const) &Extrema_ExtElC2d::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtElC2d.def("Points", (void (Extrema_ExtElC2d::*)(const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_ExtElC2d::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// Enums

}