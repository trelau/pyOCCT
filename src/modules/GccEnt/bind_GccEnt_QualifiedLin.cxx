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
#include <GccEnt_Position.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedLin.hxx>

void bind_GccEnt_QualifiedLin(py::module &mod){

py::class_<GccEnt_QualifiedLin, std::unique_ptr<GccEnt_QualifiedLin, Deleter<GccEnt_QualifiedLin>>> cls_GccEnt_QualifiedLin(mod, "GccEnt_QualifiedLin", "Describes a qualified 2D line. A qualified 2D line is a line (gp_Lin2d line) with a qualifier which specifies whether the solution of a construction algorithm using the qualified line (as an argument): - is 'enclosed' by the line, or - is built so that both the line and it are external to one another, or - is undefined (all solutions apply). Note: the interior of a line is defined as the left-hand side of the line in relation to its orientation (i.e. when moving from the start to the end of the curve).");

// Constructors
cls_GccEnt_QualifiedLin.def(py::init<const gp_Lin2d &, const GccEnt_Position>(), py::arg("Qualified"), py::arg("Qualifier"));

// Fields

// Methods
// cls_GccEnt_QualifiedLin.def_static("operator new_", (void * (*)(size_t)) &GccEnt_QualifiedLin::operator new, "None", py::arg("theSize"));
// cls_GccEnt_QualifiedLin.def_static("operator delete_", (void (*)(void *)) &GccEnt_QualifiedLin::operator delete, "None", py::arg("theAddress"));
// cls_GccEnt_QualifiedLin.def_static("operator new[]_", (void * (*)(size_t)) &GccEnt_QualifiedLin::operator new[], "None", py::arg("theSize"));
// cls_GccEnt_QualifiedLin.def_static("operator delete[]_", (void (*)(void *)) &GccEnt_QualifiedLin::operator delete[], "None", py::arg("theAddress"));
// cls_GccEnt_QualifiedLin.def_static("operator new_", (void * (*)(size_t, void *)) &GccEnt_QualifiedLin::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccEnt_QualifiedLin.def_static("operator delete_", (void (*)(void *, void *)) &GccEnt_QualifiedLin::operator delete, "None", py::arg(""), py::arg(""));
cls_GccEnt_QualifiedLin.def("Qualified", (gp_Lin2d (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::Qualified, "Returns a 2D line to which the qualifier is assigned.");
cls_GccEnt_QualifiedLin.def("Qualifier", (GccEnt_Position (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::Qualifier, "Returns the qualifier of this qualified line, if it is 'enclosed' or 'outside', or - GccEnt_noqualifier if it is unqualified.");
cls_GccEnt_QualifiedLin.def("IsUnqualified", (Standard_Boolean (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::IsUnqualified, "Returns true if the solution is unqualified and false in the other cases.");
cls_GccEnt_QualifiedLin.def("IsEnclosed", (Standard_Boolean (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::IsEnclosed, "Returns true if the solution is Enclosed in the Lin2d and false in the other cases.");
cls_GccEnt_QualifiedLin.def("IsOutside", (Standard_Boolean (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::IsOutside, "Returns true if the solution is Outside the Lin2d and false in the other cases.");

// Enums

}