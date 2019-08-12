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
#include <TopOpeBRep_Bipoint.hxx>

void bind_TopOpeBRep_Bipoint(py::module &mod){

py::class_<TopOpeBRep_Bipoint, std::unique_ptr<TopOpeBRep_Bipoint, Deleter<TopOpeBRep_Bipoint>>> cls_TopOpeBRep_Bipoint(mod, "TopOpeBRep_Bipoint", "None");

// Constructors
cls_TopOpeBRep_Bipoint.def(py::init<>());
cls_TopOpeBRep_Bipoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("I1"), py::arg("I2"));

// Fields

// Methods
// cls_TopOpeBRep_Bipoint.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_Bipoint::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_Bipoint.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_Bipoint::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_Bipoint.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_Bipoint::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_Bipoint.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_Bipoint::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_Bipoint.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_Bipoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_Bipoint.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_Bipoint::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_Bipoint.def("I1", (Standard_Integer (TopOpeBRep_Bipoint::*)() const) &TopOpeBRep_Bipoint::I1, "None");
cls_TopOpeBRep_Bipoint.def("I2", (Standard_Integer (TopOpeBRep_Bipoint::*)() const) &TopOpeBRep_Bipoint::I2, "None");

// Enums

}