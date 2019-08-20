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
#include <IntSurf_Couple.hxx>

void bind_IntSurf_Couple(py::module &mod){

py::class_<IntSurf_Couple, std::unique_ptr<IntSurf_Couple>> cls_IntSurf_Couple(mod, "IntSurf_Couple", "creation d 'un couple de 2 entiers");

// Constructors
cls_IntSurf_Couple.def(py::init<>());
cls_IntSurf_Couple.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Index1"), py::arg("Index2"));

// Fields

// Methods
// cls_IntSurf_Couple.def_static("operator new_", (void * (*)(size_t)) &IntSurf_Couple::operator new, "None", py::arg("theSize"));
// cls_IntSurf_Couple.def_static("operator delete_", (void (*)(void *)) &IntSurf_Couple::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_Couple.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_Couple::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_Couple.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_Couple::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_Couple.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_Couple::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_Couple.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_Couple::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_Couple.def("First", (Standard_Integer (IntSurf_Couple::*)() const) &IntSurf_Couple::First, "returns the first element");
cls_IntSurf_Couple.def("Second", (Standard_Integer (IntSurf_Couple::*)() const) &IntSurf_Couple::Second, "returns the Second element");

// Enums

}