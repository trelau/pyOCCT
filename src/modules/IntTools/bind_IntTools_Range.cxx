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
#include <IntTools_Range.hxx>

void bind_IntTools_Range(py::module &mod){

py::class_<IntTools_Range, std::unique_ptr<IntTools_Range, Deleter<IntTools_Range>>> cls_IntTools_Range(mod, "IntTools_Range", "The class describes the 1-d range [myFirst, myLast].");

// Constructors
cls_IntTools_Range.def(py::init<>());
cls_IntTools_Range.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("aFirst"), py::arg("aLast"));

// Fields

// Methods
// cls_IntTools_Range.def_static("operator new_", (void * (*)(size_t)) &IntTools_Range::operator new, "None", py::arg("theSize"));
// cls_IntTools_Range.def_static("operator delete_", (void (*)(void *)) &IntTools_Range::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_Range.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_Range::operator new[], "None", py::arg("theSize"));
// cls_IntTools_Range.def_static("operator delete[]_", (void (*)(void *)) &IntTools_Range::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_Range.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_Range::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_Range.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_Range::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_Range.def("SetFirst", (void (IntTools_Range::*)(const Standard_Real)) &IntTools_Range::SetFirst, "Modifier", py::arg("aFirst"));
cls_IntTools_Range.def("SetLast", (void (IntTools_Range::*)(const Standard_Real)) &IntTools_Range::SetLast, "Modifier", py::arg("aLast"));
cls_IntTools_Range.def("First", (Standard_Real (IntTools_Range::*)() const) &IntTools_Range::First, "Selector");
cls_IntTools_Range.def("Last", (Standard_Real (IntTools_Range::*)() const) &IntTools_Range::Last, "Selector");
cls_IntTools_Range.def("Range", [](IntTools_Range &self, Standard_Real & aFirst, Standard_Real & aLast){ self.Range(aFirst, aLast); return std::tuple<Standard_Real &, Standard_Real &>(aFirst, aLast); }, "Selector", py::arg("aFirst"), py::arg("aLast"));

// Enums

}