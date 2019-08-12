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
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_BaseVector.hxx>
#include <Standard_OutOfRange.hxx>

void bind_NCollection_BaseVector(py::module &mod){

py::class_<NCollection_BaseVector, std::unique_ptr<NCollection_BaseVector, py::nodelete>> cls_NCollection_BaseVector(mod, "NCollection_BaseVector", "Class NCollection_BaseVector - base for NCollection_Vector template");

// Constructors

// Fields

// Methods
// cls_NCollection_BaseVector.def_static("operator new_", (void * (*)(size_t)) &NCollection_BaseVector::operator new, "None", py::arg("theSize"));
// cls_NCollection_BaseVector.def_static("operator delete_", (void (*)(void *)) &NCollection_BaseVector::operator delete, "None", py::arg("theAddress"));
// cls_NCollection_BaseVector.def_static("operator new[]_", (void * (*)(size_t)) &NCollection_BaseVector::operator new[], "None", py::arg("theSize"));
// cls_NCollection_BaseVector.def_static("operator delete[]_", (void (*)(void *)) &NCollection_BaseVector::operator delete[], "None", py::arg("theAddress"));
// cls_NCollection_BaseVector.def_static("operator new_", (void * (*)(size_t, void *)) &NCollection_BaseVector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_NCollection_BaseVector.def_static("operator delete_", (void (*)(void *, void *)) &NCollection_BaseVector::operator delete, "None", py::arg(""), py::arg(""));
// cls_NCollection_BaseVector.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_BaseVector::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_NCollection_BaseVector.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_BaseVector::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_NCollection_BaseVector.def("Clear", (void (NCollection_BaseVector::*)()) &NCollection_BaseVector::Clear, "Empty the vector of its objects");
cls_NCollection_BaseVector.def("SetIncrement", (void (NCollection_BaseVector::*)(const Standard_Integer)) &NCollection_BaseVector::SetIncrement, "None", py::arg("aIncrement"));
cls_NCollection_BaseVector.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_BaseVector::*)() const) &NCollection_BaseVector::Allocator, "Returns attached allocator");

// Enums

}