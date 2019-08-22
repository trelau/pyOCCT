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

void bind_Standard(py::module &mod){

py::class_<Standard> cls_Standard(mod, "Standard", "The package Standard provides global memory allocator and other basic services used by other OCCT components.");

// Constructors

// Fields

// Methods
// cls_Standard.def_static("operator new_", (void * (*)(size_t)) &Standard::operator new, "None", py::arg("theSize"));
// cls_Standard.def_static("operator delete_", (void (*)(void *)) &Standard::operator delete, "None", py::arg("theAddress"));
// cls_Standard.def_static("operator new[]_", (void * (*)(size_t)) &Standard::operator new[], "None", py::arg("theSize"));
// cls_Standard.def_static("operator delete[]_", (void (*)(void *)) &Standard::operator delete[], "None", py::arg("theAddress"));
// cls_Standard.def_static("operator new_", (void * (*)(size_t, void *)) &Standard::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard.def_static("operator delete_", (void (*)(void *, void *)) &Standard::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard.def_static("Allocate_", (Standard_Address (*)(const Standard_Size)) &Standard::Allocate, "Allocates memory blocks aSize - bytes to allocate", py::arg("aSize"));
cls_Standard.def_static("Free_", (void (*)(const Standard_Address)) &Standard::Free, "Deallocates memory blocks", py::arg("thePtr"));
cls_Standard.def_static("Reallocate_", (Standard_Address (*)(const Standard_Address, const Standard_Size)) &Standard::Reallocate, "Reallocates memory blocks aStorage - previously allocated memory block aNewSize - new size in bytes", py::arg("aStorage"), py::arg("aNewSize"));
cls_Standard.def_static("AllocateAligned_", (Standard_Address (*)(const Standard_Size, const Standard_Size)) &Standard::AllocateAligned, "Allocates aligned memory blocks. Should be used with CPU instructions which require specific alignment. For example: SSE requires 16 bytes, AVX requires 32 bytes.", py::arg("theSize"), py::arg("theAlign"));
cls_Standard.def_static("FreeAligned_", (void (*)(const Standard_Address)) &Standard::FreeAligned, "Deallocates memory blocks", py::arg("thePtrAligned"));
cls_Standard.def_static("Purge_", (Standard_Integer (*)()) &Standard::Purge, "Deallocates the storage retained on the free list and clears the list. Returns non-zero if some memory has been actually freed.");

// Enums

}