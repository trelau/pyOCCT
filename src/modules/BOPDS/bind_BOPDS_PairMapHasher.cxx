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
#include <BOPDS_Pair.hxx>
#include <BOPDS_PairMapHasher.hxx>

void bind_BOPDS_PairMapHasher(py::module &mod){

py::class_<BOPDS_PairMapHasher, std::unique_ptr<BOPDS_PairMapHasher, Deleter<BOPDS_PairMapHasher>>> cls_BOPDS_PairMapHasher(mod, "BOPDS_PairMapHasher", "None");

// Constructors

// Fields

// Methods
// cls_BOPDS_PairMapHasher.def_static("operator new_", (void * (*)(size_t)) &BOPDS_PairMapHasher::operator new, "None", py::arg("theSize"));
// cls_BOPDS_PairMapHasher.def_static("operator delete_", (void (*)(void *)) &BOPDS_PairMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_PairMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_PairMapHasher::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_PairMapHasher.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_PairMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_PairMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_PairMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_PairMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_PairMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_PairMapHasher.def_static("HashCode_", (Standard_Integer (*)(const BOPDS_Pair &, const Standard_Integer)) &BOPDS_PairMapHasher::HashCode, "None", py::arg("thePair"), py::arg("Upper"));
cls_BOPDS_PairMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const BOPDS_Pair &, const BOPDS_Pair &)) &BOPDS_PairMapHasher::IsEqual, "None", py::arg("thePair1"), py::arg("thePair2"));

// Enums

}