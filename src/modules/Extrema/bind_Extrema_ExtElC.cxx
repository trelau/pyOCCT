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
#include <Standard_TypeDef.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Extrema_POnCurv.hxx>
#include <Extrema_ExtElC.hxx>

void bind_Extrema_ExtElC(py::module &mod){

py::class_<Extrema_ExtElC, std::unique_ptr<Extrema_ExtElC, Deleter<Extrema_ExtElC>>> cls_Extrema_ExtElC(mod, "Extrema_ExtElC", "It calculates all the distance between two elementary curves. These distances can be maximum or minimum.");

// Constructors
cls_Extrema_ExtElC.def(py::init<>());
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Lin &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("AngTol"));
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Circ &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Elips &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Hypr &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC.def(py::init<const gp_Lin &, const gp_Parab &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_ExtElC.def(py::init<const gp_Circ &, const gp_Circ &>(), py::arg("C1"), py::arg("C2"));

// Fields

// Methods
// cls_Extrema_ExtElC.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtElC::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtElC.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtElC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtElC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtElC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtElC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtElC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtElC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtElC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtElC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtElC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtElC.def("IsDone", (Standard_Boolean (Extrema_ExtElC::*)() const) &Extrema_ExtElC::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtElC.def("IsParallel", (Standard_Boolean (Extrema_ExtElC::*)() const) &Extrema_ExtElC::IsParallel, "Returns True if the two curves are parallel.");
cls_Extrema_ExtElC.def("NbExt", (Standard_Integer (Extrema_ExtElC::*)() const) &Extrema_ExtElC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtElC.def("SquareDistance", [](Extrema_ExtElC &self) -> Standard_Real { return self.SquareDistance(); });
cls_Extrema_ExtElC.def("SquareDistance", (Standard_Real (Extrema_ExtElC::*)(const Standard_Integer) const) &Extrema_ExtElC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_ExtElC.def("Points", (void (Extrema_ExtElC::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_ExtElC::Points, "Returns the points of the Nth extremum distance. P1 is on the first curve, P2 on the second one.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// Enums

}