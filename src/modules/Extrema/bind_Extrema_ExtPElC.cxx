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
#include <gp_Pnt.hxx>
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Extrema_POnCurv.hxx>
#include <Extrema_ExtPElC.hxx>

void bind_Extrema_ExtPElC(py::module &mod){

py::class_<Extrema_ExtPElC, std::unique_ptr<Extrema_ExtPElC, Deleter<Extrema_ExtPElC>>> cls_Extrema_ExtPElC(mod, "Extrema_ExtPElC", "It calculates all the distances between a point and an elementary curve. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtPElC.def(py::init<>());
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Elips &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Hypr &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def(py::init<const gp_Pnt &, const gp_Parab &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));

// Fields

// Methods
// cls_Extrema_ExtPElC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPElC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPElC.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPElC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPElC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPElC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPElC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPElC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPElC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPElC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPElC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPElC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Elips &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Hypr &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("Perform", (void (Extrema_ExtPElC::*)(const gp_Pnt &, const gp_Parab &, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPElC::Perform, "None", py::arg("P"), py::arg("C"), py::arg("Tol"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtPElC.def("IsDone", (Standard_Boolean (Extrema_ExtPElC::*)() const) &Extrema_ExtPElC::IsDone, "True if the distances are found.");
cls_Extrema_ExtPElC.def("NbExt", (Standard_Integer (Extrema_ExtPElC::*)() const) &Extrema_ExtPElC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPElC.def("SquareDistance", (Standard_Real (Extrema_ExtPElC::*)(const Standard_Integer) const) &Extrema_ExtPElC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtPElC.def("IsMin", (Standard_Boolean (Extrema_ExtPElC::*)(const Standard_Integer) const) &Extrema_ExtPElC::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_ExtPElC.def("Point", (const Extrema_POnCurv & (Extrema_ExtPElC::*)(const Standard_Integer) const) &Extrema_ExtPElC::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// Enums

}