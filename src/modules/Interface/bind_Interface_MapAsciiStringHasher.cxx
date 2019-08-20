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
#include <Interface_MapAsciiStringHasher.hxx>

void bind_Interface_MapAsciiStringHasher(py::module &mod){

py::class_<Interface_MapAsciiStringHasher, std::unique_ptr<Interface_MapAsciiStringHasher>> cls_Interface_MapAsciiStringHasher(mod, "Interface_MapAsciiStringHasher", "None");

// Constructors

// Fields

// Methods
// cls_Interface_MapAsciiStringHasher.def_static("operator new_", (void * (*)(size_t)) &Interface_MapAsciiStringHasher::operator new, "None", py::arg("theSize"));
// cls_Interface_MapAsciiStringHasher.def_static("operator delete_", (void (*)(void *)) &Interface_MapAsciiStringHasher::operator delete, "None", py::arg("theAddress"));
// cls_Interface_MapAsciiStringHasher.def_static("operator new[]_", (void * (*)(size_t)) &Interface_MapAsciiStringHasher::operator new[], "None", py::arg("theSize"));
// cls_Interface_MapAsciiStringHasher.def_static("operator delete[]_", (void (*)(void *)) &Interface_MapAsciiStringHasher::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_MapAsciiStringHasher.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_MapAsciiStringHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_MapAsciiStringHasher.def_static("operator delete_", (void (*)(void *, void *)) &Interface_MapAsciiStringHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_MapAsciiStringHasher.def_static("HashCode_", (Standard_Integer (*)(const TCollection_AsciiString &, const Standard_Integer)) &Interface_MapAsciiStringHasher::HashCode, "None", py::arg("K"), py::arg("Upper"));
cls_Interface_MapAsciiStringHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &Interface_MapAsciiStringHasher::IsEqual, "None", py::arg("K1"), py::arg("K2"));

// Enums

}