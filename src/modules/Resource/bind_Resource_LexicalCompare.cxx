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
#include <TCollection_AsciiString.hxx>
#include <Resource_LexicalCompare.hxx>

void bind_Resource_LexicalCompare(py::module &mod){

py::class_<Resource_LexicalCompare> cls_Resource_LexicalCompare(mod, "Resource_LexicalCompare", "None");

// Constructors
cls_Resource_LexicalCompare.def(py::init<>());

// Fields

// Methods
// cls_Resource_LexicalCompare.def_static("operator new_", (void * (*)(size_t)) &Resource_LexicalCompare::operator new, "None", py::arg("theSize"));
// cls_Resource_LexicalCompare.def_static("operator delete_", (void (*)(void *)) &Resource_LexicalCompare::operator delete, "None", py::arg("theAddress"));
// cls_Resource_LexicalCompare.def_static("operator new[]_", (void * (*)(size_t)) &Resource_LexicalCompare::operator new[], "None", py::arg("theSize"));
// cls_Resource_LexicalCompare.def_static("operator delete[]_", (void (*)(void *)) &Resource_LexicalCompare::operator delete[], "None", py::arg("theAddress"));
// cls_Resource_LexicalCompare.def_static("operator new_", (void * (*)(size_t, void *)) &Resource_LexicalCompare::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Resource_LexicalCompare.def_static("operator delete_", (void (*)(void *, void *)) &Resource_LexicalCompare::operator delete, "None", py::arg(""), py::arg(""));
cls_Resource_LexicalCompare.def("IsLower", (Standard_Boolean (Resource_LexicalCompare::*)(const TCollection_AsciiString &, const TCollection_AsciiString &) const) &Resource_LexicalCompare::IsLower, "Returns True if <Left> is lower than <Right>.", py::arg("Left"), py::arg("Right"));

// Enums

}