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
#include <Bisector_PointOnBis.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf2d.hxx>
#include <Bisector_PolyBis.hxx>

void bind_Bisector_PolyBis(py::module &mod){

py::class_<Bisector_PolyBis> cls_Bisector_PolyBis(mod, "Bisector_PolyBis", "Polygon of PointOnBis");

// Constructors
cls_Bisector_PolyBis.def(py::init<>());

// Fields

// Methods
// cls_Bisector_PolyBis.def_static("operator new_", (void * (*)(size_t)) &Bisector_PolyBis::operator new, "None", py::arg("theSize"));
// cls_Bisector_PolyBis.def_static("operator delete_", (void (*)(void *)) &Bisector_PolyBis::operator delete, "None", py::arg("theAddress"));
// cls_Bisector_PolyBis.def_static("operator new[]_", (void * (*)(size_t)) &Bisector_PolyBis::operator new[], "None", py::arg("theSize"));
// cls_Bisector_PolyBis.def_static("operator delete[]_", (void (*)(void *)) &Bisector_PolyBis::operator delete[], "None", py::arg("theAddress"));
// cls_Bisector_PolyBis.def_static("operator new_", (void * (*)(size_t, void *)) &Bisector_PolyBis::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bisector_PolyBis.def_static("operator delete_", (void (*)(void *, void *)) &Bisector_PolyBis::operator delete, "None", py::arg(""), py::arg(""));
cls_Bisector_PolyBis.def("Append", (void (Bisector_PolyBis::*)(const Bisector_PointOnBis &)) &Bisector_PolyBis::Append, "None", py::arg("Point"));
cls_Bisector_PolyBis.def("Length", (Standard_Integer (Bisector_PolyBis::*)() const) &Bisector_PolyBis::Length, "None");
cls_Bisector_PolyBis.def("IsEmpty", (Standard_Boolean (Bisector_PolyBis::*)() const) &Bisector_PolyBis::IsEmpty, "None");
cls_Bisector_PolyBis.def("Value", (const Bisector_PointOnBis & (Bisector_PolyBis::*)(const Standard_Integer) const) &Bisector_PolyBis::Value, "None", py::arg("Index"));
cls_Bisector_PolyBis.def("First", (const Bisector_PointOnBis & (Bisector_PolyBis::*)() const) &Bisector_PolyBis::First, "None");
cls_Bisector_PolyBis.def("Last", (const Bisector_PointOnBis & (Bisector_PolyBis::*)() const) &Bisector_PolyBis::Last, "None");
cls_Bisector_PolyBis.def("Interval", (Standard_Integer (Bisector_PolyBis::*)(const Standard_Real) const) &Bisector_PolyBis::Interval, "None", py::arg("U"));
cls_Bisector_PolyBis.def("Transform", (void (Bisector_PolyBis::*)(const gp_Trsf2d &)) &Bisector_PolyBis::Transform, "None", py::arg("T"));

// Enums

}