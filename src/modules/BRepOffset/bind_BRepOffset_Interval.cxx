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
#include <Standard_TypeDef.hxx>
#include <BRepOffset_Type.hxx>
#include <BRepOffset_Interval.hxx>

void bind_BRepOffset_Interval(py::module &mod){

py::class_<BRepOffset_Interval> cls_BRepOffset_Interval(mod, "BRepOffset_Interval", "None");

// Constructors
cls_BRepOffset_Interval.def(py::init<>());
cls_BRepOffset_Interval.def(py::init<const Standard_Real, const Standard_Real, const BRepOffset_Type>(), py::arg("U1"), py::arg("U2"), py::arg("Type"));

// Fields

// Methods
// cls_BRepOffset_Interval.def_static("operator new_", (void * (*)(size_t)) &BRepOffset_Interval::operator new, "None", py::arg("theSize"));
// cls_BRepOffset_Interval.def_static("operator delete_", (void (*)(void *)) &BRepOffset_Interval::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffset_Interval.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffset_Interval::operator new[], "None", py::arg("theSize"));
// cls_BRepOffset_Interval.def_static("operator delete[]_", (void (*)(void *)) &BRepOffset_Interval::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffset_Interval.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffset_Interval::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffset_Interval.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffset_Interval::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffset_Interval.def("First", (void (BRepOffset_Interval::*)(const Standard_Real)) &BRepOffset_Interval::First, "None", py::arg("U"));
cls_BRepOffset_Interval.def("Last", (void (BRepOffset_Interval::*)(const Standard_Real)) &BRepOffset_Interval::Last, "None", py::arg("U"));
cls_BRepOffset_Interval.def("Type", (void (BRepOffset_Interval::*)(const BRepOffset_Type)) &BRepOffset_Interval::Type, "None", py::arg("T"));
cls_BRepOffset_Interval.def("First", (Standard_Real (BRepOffset_Interval::*)() const) &BRepOffset_Interval::First, "None");
cls_BRepOffset_Interval.def("Last", (Standard_Real (BRepOffset_Interval::*)() const) &BRepOffset_Interval::Last, "None");
cls_BRepOffset_Interval.def("Type", (BRepOffset_Type (BRepOffset_Interval::*)() const) &BRepOffset_Interval::Type, "None");

// Enums

}