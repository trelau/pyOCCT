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
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <Extrema_ExtPElC2d.hxx>

void bind_Extrema_ExtPElC2d(py::module &mod){

py::class_<Extrema_ExtPElC2d, std::unique_ptr<Extrema_ExtPElC2d>> cls_Extrema_ExtPElC2d(mod, "Extrema_ExtPElC2d", "It calculates all the distances between a point and an elementary curve. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtPElC2d.def(py::init<>());
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Elips2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Hypr2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def(py::init<const gp_Pnt2d &, const gp_Parab2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));

// Fields

// Methods
// cls_Extrema_ExtPElC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPElC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPElC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPElC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPElC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPElC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPElC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPElC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPElC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPElC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPElC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPElC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("L"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Elips2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Hypr2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("Perform", (void (Extrema_ExtPElC2d::*)(const gp_Pnt2d &, const gp_Parab2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC2d::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC2d.def("IsDone", (Standard_Boolean (Extrema_ExtPElC2d::*)() const) &Extrema_ExtPElC2d::IsDone, "True if the distances are found.");
cls_Extrema_ExtPElC2d.def("NbExt", (Standard_Integer (Extrema_ExtPElC2d::*)() const) &Extrema_ExtPElC2d::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPElC2d.def("SquareDistance", (Standard_Real (Extrema_ExtPElC2d::*)(const Standard_Integer) const) &Extrema_ExtPElC2d::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtPElC2d.def("IsMin", (Standard_Boolean (Extrema_ExtPElC2d::*)(const Standard_Integer) const) &Extrema_ExtPElC2d::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ExtPElC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_ExtPElC2d::*)(const Standard_Integer) const) &Extrema_ExtPElC2d::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// Enums

}