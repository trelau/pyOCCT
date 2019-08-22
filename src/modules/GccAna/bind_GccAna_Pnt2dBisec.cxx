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
#include <Standard_TypeDef.hxx>
#include <gp_Lin2d.hxx>
#include <GccAna_Pnt2dBisec.hxx>

void bind_GccAna_Pnt2dBisec(py::module &mod){

py::class_<GccAna_Pnt2dBisec> cls_GccAna_Pnt2dBisec(mod, "GccAna_Pnt2dBisec", "This class implements the algorithms used to create the bisecting line between two 2d points Describes functions for building a bisecting line between two 2D points. The bisecting line between two points is the bisector of the segment which joins the two points, if these are not coincident. The algorithm does not find a solution if the two points are coincident. A Pnt2dBisec object provides a framework for: - defining the construction of the bisecting line, - implementing the construction algorithm, and consulting the result.");

// Constructors
cls_GccAna_Pnt2dBisec.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Point1"), py::arg("Point2"));

// Fields

// Methods
// cls_GccAna_Pnt2dBisec.def_static("operator new_", (void * (*)(size_t)) &GccAna_Pnt2dBisec::operator new, "None", py::arg("theSize"));
// cls_GccAna_Pnt2dBisec.def_static("operator delete_", (void (*)(void *)) &GccAna_Pnt2dBisec::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Pnt2dBisec.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Pnt2dBisec::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Pnt2dBisec.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Pnt2dBisec::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Pnt2dBisec.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Pnt2dBisec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Pnt2dBisec.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Pnt2dBisec::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Pnt2dBisec.def("IsDone", (Standard_Boolean (GccAna_Pnt2dBisec::*)() const) &GccAna_Pnt2dBisec::IsDone, "Returns true (this construction algorithm never fails).");
cls_GccAna_Pnt2dBisec.def("HasSolution", (Standard_Boolean (GccAna_Pnt2dBisec::*)() const) &GccAna_Pnt2dBisec::HasSolution, "Returns true if this algorithm has a solution, i.e. if the two points are not coincident.");
cls_GccAna_Pnt2dBisec.def("ThisSolution", (gp_Lin2d (GccAna_Pnt2dBisec::*)() const) &GccAna_Pnt2dBisec::ThisSolution, "Returns a line, representing the solution computed by this algorithm.");

// Enums

}