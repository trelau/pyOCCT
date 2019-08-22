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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <IntAna_Int3Pln.hxx>

void bind_IntAna_Int3Pln(py::module &mod){

py::class_<IntAna_Int3Pln> cls_IntAna_Int3Pln(mod, "IntAna_Int3Pln", "Intersection between 3 planes. The algorithm searches for an intersection point. If two of the planes are parallel or identical, IsEmpty returns TRUE.");

// Constructors
cls_IntAna_Int3Pln.def(py::init<>());
cls_IntAna_Int3Pln.def(py::init<const gp_Pln &, const gp_Pln &, const gp_Pln &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));

// Fields

// Methods
// cls_IntAna_Int3Pln.def_static("operator new_", (void * (*)(size_t)) &IntAna_Int3Pln::operator new, "None", py::arg("theSize"));
// cls_IntAna_Int3Pln.def_static("operator delete_", (void (*)(void *)) &IntAna_Int3Pln::operator delete, "None", py::arg("theAddress"));
// cls_IntAna_Int3Pln.def_static("operator new[]_", (void * (*)(size_t)) &IntAna_Int3Pln::operator new[], "None", py::arg("theSize"));
// cls_IntAna_Int3Pln.def_static("operator delete[]_", (void (*)(void *)) &IntAna_Int3Pln::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna_Int3Pln.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna_Int3Pln::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna_Int3Pln.def_static("operator delete_", (void (*)(void *, void *)) &IntAna_Int3Pln::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna_Int3Pln.def("Perform", (void (IntAna_Int3Pln::*)(const gp_Pln &, const gp_Pln &, const gp_Pln &)) &IntAna_Int3Pln::Perform, "Determination of the intersection point between 3 planes.", py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_IntAna_Int3Pln.def("IsDone", (Standard_Boolean (IntAna_Int3Pln::*)() const) &IntAna_Int3Pln::IsDone, "Returns True if the computation was successful.");
cls_IntAna_Int3Pln.def("IsEmpty", (Standard_Boolean (IntAna_Int3Pln::*)() const) &IntAna_Int3Pln::IsEmpty, "Returns TRUE if there is no intersection POINT. If 2 planes are identical or parallel, IsEmpty will return TRUE.");
cls_IntAna_Int3Pln.def("Value", (const gp_Pnt & (IntAna_Int3Pln::*)() const) &IntAna_Int3Pln::Value, "Returns the intersection point.");

// Enums

}