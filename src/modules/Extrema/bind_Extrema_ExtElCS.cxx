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
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <gp_Circ.hxx>
#include <gp_Hypr.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv.hxx>
#include <Extrema_POnSurf.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Extrema_HArray1OfPOnCurv.hxx>
#include <Extrema_HArray1OfPOnSurf.hxx>
#include <Extrema_ExtElCS.hxx>

void bind_Extrema_ExtElCS(py::module &mod){

py::class_<Extrema_ExtElCS, std::unique_ptr<Extrema_ExtElCS>> cls_Extrema_ExtElCS(mod, "Extrema_ExtElCS", "It calculates all the distances between a curve and a surface. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtElCS.def(py::init<>());
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Pln &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Cylinder &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Cone &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Sphere &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Lin &, const gp_Torus &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Pln &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Cylinder &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Cone &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Sphere &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Circ &, const gp_Torus &>(), py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def(py::init<const gp_Hypr &, const gp_Pln &>(), py::arg("C"), py::arg("S"));

// Fields

// Methods
// cls_Extrema_ExtElCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtElCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtElCS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtElCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtElCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtElCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtElCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtElCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtElCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtElCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtElCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtElCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Pln &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Cylinder &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Cone &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Sphere &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Lin &, const gp_Torus &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Pln &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Cylinder &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Cone &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Sphere &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Circ &, const gp_Torus &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("Perform", (void (Extrema_ExtElCS::*)(const gp_Hypr &, const gp_Pln &)) &Extrema_ExtElCS::Perform, "None", py::arg("C"), py::arg("S"));
cls_Extrema_ExtElCS.def("IsDone", (Standard_Boolean (Extrema_ExtElCS::*)() const) &Extrema_ExtElCS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtElCS.def("IsParallel", (Standard_Boolean (Extrema_ExtElCS::*)() const) &Extrema_ExtElCS::IsParallel, "Returns True if the curve is on a parallel surface.");
cls_Extrema_ExtElCS.def("NbExt", (Standard_Integer (Extrema_ExtElCS::*)() const) &Extrema_ExtElCS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtElCS.def("SquareDistance", [](Extrema_ExtElCS &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtElCS.def("SquareDistance", (Standard_Real (Extrema_ExtElCS::*)(const Standard_Integer) const) &Extrema_ExtElCS::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtElCS.def("Points", (void (Extrema_ExtElCS::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnSurf &) const) &Extrema_ExtElCS::Points, "Returns the points of the Nth extremum distance. P1 is on the curve, P2 on the surface.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// Enums

}