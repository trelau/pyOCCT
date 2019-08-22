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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <GccInt_Bisec.hxx>
#include <GccAna_Circ2dBisec.hxx>

void bind_GccAna_Circ2dBisec(py::module &mod){

py::class_<GccAna_Circ2dBisec> cls_GccAna_Circ2dBisec(mod, "GccAna_Circ2dBisec", "This class describes functions for building bisecting curves between two 2D circles. A bisecting curve between two circles is a curve such that each of its points is at the same distance from the two circles. It can be an ellipse, hyperbola, circle or line, depending on the relative position of the two circles. The algorithm computes all the elementary curves which are solutions. There is no solution if the two circles are coincident. A Circ2dBisec object provides a framework for: - defining the construction of the bisecting curves, - implementing the construction algorithm, and consulting the result.");

// Constructors
cls_GccAna_Circ2dBisec.def(py::init<const gp_Circ2d &, const gp_Circ2d &>(), py::arg("Circ1"), py::arg("Circ2"));

// Fields

// Methods
// cls_GccAna_Circ2dBisec.def_static("operator new_", (void * (*)(size_t)) &GccAna_Circ2dBisec::operator new, "None", py::arg("theSize"));
// cls_GccAna_Circ2dBisec.def_static("operator delete_", (void (*)(void *)) &GccAna_Circ2dBisec::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Circ2dBisec.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Circ2dBisec::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Circ2dBisec.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Circ2dBisec::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Circ2dBisec.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Circ2dBisec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Circ2dBisec.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Circ2dBisec::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Circ2dBisec.def("IsDone", (Standard_Boolean (GccAna_Circ2dBisec::*)() const) &GccAna_Circ2dBisec::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_GccAna_Circ2dBisec.def("NbSolutions", (Standard_Integer (GccAna_Circ2dBisec::*)() const) &GccAna_Circ2dBisec::NbSolutions, "This method returns the number of solutions. Raises NotDone if the construction algorithm didn't succeed.");
cls_GccAna_Circ2dBisec.def("ThisSolution", (opencascade::handle<GccInt_Bisec> (GccAna_Circ2dBisec::*)(const Standard_Integer) const) &GccAna_Circ2dBisec::ThisSolution, "Returns the solution number Index Raises OutOfRange exception if Index is greater than the number of solutions. It raises NotDone if the construction algorithm didn't succeed.", py::arg("Index"));

// Enums

}