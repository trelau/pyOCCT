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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <GccInt_Bisec.hxx>
#include <GccAna_LinPnt2dBisec.hxx>

void bind_GccAna_LinPnt2dBisec(py::module &mod){

py::class_<GccAna_LinPnt2dBisec, std::unique_ptr<GccAna_LinPnt2dBisec, Deleter<GccAna_LinPnt2dBisec>>> cls_GccAna_LinPnt2dBisec(mod, "GccAna_LinPnt2dBisec", "Describes functions for building bisecting curves between a 2D line and a point. A bisecting curve between a line and a point is such a curve that each of its points is at the same distance from the circle and the point. It can be a parabola or a line, depending on the relative position of the line and the circle. There is always one unique solution. A LinPnt2dBisec object provides a framework for: - defining the construction of the bisecting curve, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GccAna_LinPnt2dBisec.def(py::init<const gp_Lin2d &, const gp_Pnt2d &>(), py::arg("Line1"), py::arg("Point2"));

// Fields

// Methods
// cls_GccAna_LinPnt2dBisec.def_static("operator new_", (void * (*)(size_t)) &GccAna_LinPnt2dBisec::operator new, "None", py::arg("theSize"));
// cls_GccAna_LinPnt2dBisec.def_static("operator delete_", (void (*)(void *)) &GccAna_LinPnt2dBisec::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_LinPnt2dBisec.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_LinPnt2dBisec::operator new[], "None", py::arg("theSize"));
// cls_GccAna_LinPnt2dBisec.def_static("operator delete[]_", (void (*)(void *)) &GccAna_LinPnt2dBisec::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_LinPnt2dBisec.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_LinPnt2dBisec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_LinPnt2dBisec.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_LinPnt2dBisec::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_LinPnt2dBisec.def("IsDone", (Standard_Boolean (GccAna_LinPnt2dBisec::*)() const) &GccAna_LinPnt2dBisec::IsDone, "Returns True if the algorithm succeeded.");
cls_GccAna_LinPnt2dBisec.def("ThisSolution", (opencascade::handle<GccInt_Bisec> (GccAna_LinPnt2dBisec::*)() const) &GccAna_LinPnt2dBisec::ThisSolution, "Returns the number of solutions. It raises NotDone if the construction algorithm didn't succeed.");

// Enums

}