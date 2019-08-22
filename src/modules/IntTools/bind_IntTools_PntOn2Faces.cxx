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
#include <IntTools_PntOnFace.hxx>
#include <Standard_TypeDef.hxx>
#include <IntTools_PntOn2Faces.hxx>

void bind_IntTools_PntOn2Faces(py::module &mod){

py::class_<IntTools_PntOn2Faces> cls_IntTools_PntOn2Faces(mod, "IntTools_PntOn2Faces", "Contains two points PntOnFace from IntTools and a flag");

// Constructors
cls_IntTools_PntOn2Faces.def(py::init<>());
cls_IntTools_PntOn2Faces.def(py::init<const IntTools_PntOnFace &, const IntTools_PntOnFace &>(), py::arg("aP1"), py::arg("aP2"));

// Fields

// Methods
// cls_IntTools_PntOn2Faces.def_static("operator new_", (void * (*)(size_t)) &IntTools_PntOn2Faces::operator new, "None", py::arg("theSize"));
// cls_IntTools_PntOn2Faces.def_static("operator delete_", (void (*)(void *)) &IntTools_PntOn2Faces::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_PntOn2Faces.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_PntOn2Faces::operator new[], "None", py::arg("theSize"));
// cls_IntTools_PntOn2Faces.def_static("operator delete[]_", (void (*)(void *)) &IntTools_PntOn2Faces::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_PntOn2Faces.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_PntOn2Faces::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_PntOn2Faces.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_PntOn2Faces::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_PntOn2Faces.def("SetP1", (void (IntTools_PntOn2Faces::*)(const IntTools_PntOnFace &)) &IntTools_PntOn2Faces::SetP1, "Modifier", py::arg("aP1"));
cls_IntTools_PntOn2Faces.def("SetP2", (void (IntTools_PntOn2Faces::*)(const IntTools_PntOnFace &)) &IntTools_PntOn2Faces::SetP2, "Modifier", py::arg("aP2"));
cls_IntTools_PntOn2Faces.def("SetValid", (void (IntTools_PntOn2Faces::*)(const Standard_Boolean)) &IntTools_PntOn2Faces::SetValid, "Modifier", py::arg("bF"));
cls_IntTools_PntOn2Faces.def("P1", (const IntTools_PntOnFace & (IntTools_PntOn2Faces::*)() const) &IntTools_PntOn2Faces::P1, "Selector");
cls_IntTools_PntOn2Faces.def("P2", (const IntTools_PntOnFace & (IntTools_PntOn2Faces::*)() const) &IntTools_PntOn2Faces::P2, "Selector");
cls_IntTools_PntOn2Faces.def("IsValid", (Standard_Boolean (IntTools_PntOn2Faces::*)() const) &IntTools_PntOn2Faces::IsValid, "Selector");

// Enums

}