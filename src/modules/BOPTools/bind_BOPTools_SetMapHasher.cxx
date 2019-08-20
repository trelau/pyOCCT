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
#include <BOPTools_Set.hxx>
#include <BOPTools_SetMapHasher.hxx>

void bind_BOPTools_SetMapHasher(py::module &mod){

py::class_<BOPTools_SetMapHasher, std::unique_ptr<BOPTools_SetMapHasher>> cls_BOPTools_SetMapHasher(mod, "BOPTools_SetMapHasher", "None");

// Constructors

// Fields

// Methods
// cls_BOPTools_SetMapHasher.def_static("operator new_", (void * (*)(size_t)) &BOPTools_SetMapHasher::operator new, "None", py::arg("theSize"));
// cls_BOPTools_SetMapHasher.def_static("operator delete_", (void (*)(void *)) &BOPTools_SetMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_SetMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_SetMapHasher::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_SetMapHasher.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_SetMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_SetMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_SetMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_SetMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_SetMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_SetMapHasher.def_static("HashCode_", (Standard_Integer (*)(const BOPTools_Set &, const Standard_Integer)) &BOPTools_SetMapHasher::HashCode, "None", py::arg("aSet"), py::arg("Upper"));
cls_BOPTools_SetMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const BOPTools_Set &, const BOPTools_Set &)) &BOPTools_SetMapHasher::IsEqual, "None", py::arg("aSet1"), py::arg("aSet2"));

// Enums

}