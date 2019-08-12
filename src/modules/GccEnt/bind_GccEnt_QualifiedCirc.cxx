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
#include <GccEnt_Position.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedCirc.hxx>

void bind_GccEnt_QualifiedCirc(py::module &mod){

py::class_<GccEnt_QualifiedCirc, std::unique_ptr<GccEnt_QualifiedCirc, Deleter<GccEnt_QualifiedCirc>>> cls_GccEnt_QualifiedCirc(mod, "GccEnt_QualifiedCirc", "Creates a qualified 2d Circle. A qualified 2D circle is a circle (gp_Circ2d circle) with a qualifier which specifies whether the solution of a construction algorithm using the qualified circle (as an argument): - encloses the circle, or - is enclosed by the circle, or - is built so that both the circle and it are external to one another, or - is undefined (all solutions apply).");

// Constructors
cls_GccEnt_QualifiedCirc.def(py::init<const gp_Circ2d &, const GccEnt_Position>(), py::arg("Qualified"), py::arg("Qualifier"));

// Fields

// Methods
// cls_GccEnt_QualifiedCirc.def_static("operator new_", (void * (*)(size_t)) &GccEnt_QualifiedCirc::operator new, "None", py::arg("theSize"));
// cls_GccEnt_QualifiedCirc.def_static("operator delete_", (void (*)(void *)) &GccEnt_QualifiedCirc::operator delete, "None", py::arg("theAddress"));
// cls_GccEnt_QualifiedCirc.def_static("operator new[]_", (void * (*)(size_t)) &GccEnt_QualifiedCirc::operator new[], "None", py::arg("theSize"));
// cls_GccEnt_QualifiedCirc.def_static("operator delete[]_", (void (*)(void *)) &GccEnt_QualifiedCirc::operator delete[], "None", py::arg("theAddress"));
// cls_GccEnt_QualifiedCirc.def_static("operator new_", (void * (*)(size_t, void *)) &GccEnt_QualifiedCirc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccEnt_QualifiedCirc.def_static("operator delete_", (void (*)(void *, void *)) &GccEnt_QualifiedCirc::operator delete, "None", py::arg(""), py::arg(""));
cls_GccEnt_QualifiedCirc.def("Qualified", (gp_Circ2d (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::Qualified, "Returns a 2D circle to which the qualifier is assigned.");
cls_GccEnt_QualifiedCirc.def("Qualifier", (GccEnt_Position (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::Qualifier, "Returns - the qualifier of this qualified circle, if it is enclosing, enclosed or outside, or - GccEnt_noqualifier if it is unqualified.");
cls_GccEnt_QualifiedCirc.def("IsUnqualified", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::IsUnqualified, "Returns true if the Circ2d is Unqualified and false in the other cases.");
cls_GccEnt_QualifiedCirc.def("IsEnclosing", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::IsEnclosing, "Returns true if the solution computed by a construction algorithm using this qualified circle encloses the circle.");
cls_GccEnt_QualifiedCirc.def("IsEnclosed", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::IsEnclosed, "Returns true if the solution computed by a construction algorithm using this qualified circle is enclosed by the circle.");
cls_GccEnt_QualifiedCirc.def("IsOutside", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::IsOutside, "Returns true if both the solution computed by a construction algorithm using this qualified circle and the circle are external to one another.");

// Enums

}