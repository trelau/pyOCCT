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
#include <BOPDS_Pave.hxx>
#include <BOPDS_PaveMapHasher.hxx>

void bind_BOPDS_PaveMapHasher(py::module &mod){

py::class_<BOPDS_PaveMapHasher> cls_BOPDS_PaveMapHasher(mod, "BOPDS_PaveMapHasher", "None");

// Constructors

// Fields

// Methods
// cls_BOPDS_PaveMapHasher.def_static("operator new_", (void * (*)(size_t)) &BOPDS_PaveMapHasher::operator new, "None", py::arg("theSize"));
// cls_BOPDS_PaveMapHasher.def_static("operator delete_", (void (*)(void *)) &BOPDS_PaveMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_PaveMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_PaveMapHasher::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_PaveMapHasher.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_PaveMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_PaveMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_PaveMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_PaveMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_PaveMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_PaveMapHasher.def_static("HashCode_", (Standard_Integer (*)(const BOPDS_Pave &, const Standard_Integer)) &BOPDS_PaveMapHasher::HashCode, "None", py::arg("aPave"), py::arg("Upper"));
cls_BOPDS_PaveMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const BOPDS_Pave &, const BOPDS_Pave &)) &BOPDS_PaveMapHasher::IsEqual, "None", py::arg("aPave1"), py::arg("aPave2"));

// Enums

}