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
#include <gp_Pln.hxx>
#include <gp_Sphere.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Torus.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnSurf.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Extrema_HArray1OfPOnSurf.hxx>
#include <Extrema_ExtElSS.hxx>

void bind_Extrema_ExtElSS(py::module &mod){

py::class_<Extrema_ExtElSS, std::unique_ptr<Extrema_ExtElSS>> cls_Extrema_ExtElSS(mod, "Extrema_ExtElSS", "It calculates all the distances between 2 elementary surfaces. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtElSS.def(py::init<>());
cls_Extrema_ExtElSS.def(py::init<const gp_Pln &, const gp_Pln &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Pln &, const gp_Sphere &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Sphere &, const gp_Sphere &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Sphere &, const gp_Cylinder &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Sphere &, const gp_Cone &>(), py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def(py::init<const gp_Sphere &, const gp_Torus &>(), py::arg("S1"), py::arg("S2"));

// Fields

// Methods
// cls_Extrema_ExtElSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtElSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtElSS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtElSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtElSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtElSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtElSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtElSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtElSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtElSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtElSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtElSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Pln &, const gp_Pln &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Pln &, const gp_Sphere &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Sphere &, const gp_Sphere &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Sphere &, const gp_Cylinder &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Sphere &, const gp_Cone &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("Perform", (void (Extrema_ExtElSS::*)(const gp_Sphere &, const gp_Torus &)) &Extrema_ExtElSS::Perform, "None", py::arg("S1"), py::arg("S2"));
cls_Extrema_ExtElSS.def("IsDone", (Standard_Boolean (Extrema_ExtElSS::*)() const) &Extrema_ExtElSS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtElSS.def("IsParallel", (Standard_Boolean (Extrema_ExtElSS::*)() const) &Extrema_ExtElSS::IsParallel, "Returns True if the two surfaces are parallel.");
cls_Extrema_ExtElSS.def("NbExt", (Standard_Integer (Extrema_ExtElSS::*)() const) &Extrema_ExtElSS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtElSS.def("SquareDistance", [](Extrema_ExtElSS &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtElSS.def("SquareDistance", (Standard_Real (Extrema_ExtElSS::*)(const Standard_Integer) const) &Extrema_ExtElSS::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtElSS.def("Points", (void (Extrema_ExtElSS::*)(const Standard_Integer, Extrema_POnSurf &, Extrema_POnSurf &) const) &Extrema_ExtElSS::Points, "Returns the points for the Nth resulting distance. P1 is on the first surface, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// Enums

}