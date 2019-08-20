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
#include <MAT2d_BiInt.hxx>
#include <MAT2d_MapBiIntHasher.hxx>

void bind_MAT2d_MapBiIntHasher(py::module &mod){

py::class_<MAT2d_MapBiIntHasher, std::unique_ptr<MAT2d_MapBiIntHasher>> cls_MAT2d_MapBiIntHasher(mod, "MAT2d_MapBiIntHasher", "None");

// Constructors

// Fields

// Methods
// cls_MAT2d_MapBiIntHasher.def_static("operator new_", (void * (*)(size_t)) &MAT2d_MapBiIntHasher::operator new, "None", py::arg("theSize"));
// cls_MAT2d_MapBiIntHasher.def_static("operator delete_", (void (*)(void *)) &MAT2d_MapBiIntHasher::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_MapBiIntHasher.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_MapBiIntHasher::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_MapBiIntHasher.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_MapBiIntHasher::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_MapBiIntHasher.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_MapBiIntHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_MapBiIntHasher.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_MapBiIntHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_MapBiIntHasher.def_static("HashCode_", (Standard_Integer (*)(const MAT2d_BiInt &, const Standard_Integer)) &MAT2d_MapBiIntHasher::HashCode, "None", py::arg("Key1"), py::arg("Upper"));
cls_MAT2d_MapBiIntHasher.def_static("IsEqual_", (Standard_Boolean (*)(const MAT2d_BiInt &, const MAT2d_BiInt &)) &MAT2d_MapBiIntHasher::IsEqual, "None", py::arg("Key1"), py::arg("Key2"));

// Enums

}