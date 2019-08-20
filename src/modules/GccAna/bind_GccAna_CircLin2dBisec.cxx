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
#include <gp_Circ2d.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <GccInt_Bisec.hxx>
#include <GccAna_CircLin2dBisec.hxx>

void bind_GccAna_CircLin2dBisec(py::module &mod){

py::class_<GccAna_CircLin2dBisec, std::unique_ptr<GccAna_CircLin2dBisec>> cls_GccAna_CircLin2dBisec(mod, "GccAna_CircLin2dBisec", "Describes functions for building bisecting curves between a 2D line and a 2D circle. A bisecting curve between a circle and a line is a curve such that each of its points is at the same distance from the circle and the line. It can be a parabola or a line, depending of the relative position of the line and the circle. The algorithm computes all the elementary curves which are solutions. A CircLin2dBisec object provides a framework for: - defining the construction of the bisecting curves, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GccAna_CircLin2dBisec.def(py::init<const gp_Circ2d &, const gp_Lin2d &>(), py::arg("Circle"), py::arg("Line"));

// Fields

// Methods
// cls_GccAna_CircLin2dBisec.def_static("operator new_", (void * (*)(size_t)) &GccAna_CircLin2dBisec::operator new, "None", py::arg("theSize"));
// cls_GccAna_CircLin2dBisec.def_static("operator delete_", (void (*)(void *)) &GccAna_CircLin2dBisec::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_CircLin2dBisec.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_CircLin2dBisec::operator new[], "None", py::arg("theSize"));
// cls_GccAna_CircLin2dBisec.def_static("operator delete[]_", (void (*)(void *)) &GccAna_CircLin2dBisec::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_CircLin2dBisec.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_CircLin2dBisec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_CircLin2dBisec.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_CircLin2dBisec::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_CircLin2dBisec.def("IsDone", (Standard_Boolean (GccAna_CircLin2dBisec::*)() const) &GccAna_CircLin2dBisec::IsDone, "Returns true (this construction algorithm never fails).");
cls_GccAna_CircLin2dBisec.def("NbSolutions", (Standard_Integer (GccAna_CircLin2dBisec::*)() const) &GccAna_CircLin2dBisec::NbSolutions, "Returns the number of curves, representing solutions computed by this algorithm.");
cls_GccAna_CircLin2dBisec.def("ThisSolution", (opencascade::handle<GccInt_Bisec> (GccAna_CircLin2dBisec::*)(const Standard_Integer) const) &GccAna_CircLin2dBisec::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm.", py::arg("Index"));

// Enums

}