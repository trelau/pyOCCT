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
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_IncAllocator.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_NCollection_IncAllocator(py::module &mod){

py::class_<NCollection_IncAllocator, opencascade::handle<NCollection_IncAllocator>, NCollection_BaseAllocator> cls_NCollection_IncAllocator(mod, "NCollection_IncAllocator", "Class NCollection_IncAllocator - incremental memory allocator. This class allocates memory on request returning the pointer to an allocated block. This memory is never returned to the system until the allocator is destroyed.");

// Constructors
cls_NCollection_IncAllocator.def(py::init<>());
cls_NCollection_IncAllocator.def(py::init<const size_t>(), py::arg("theBlockSize"));

// Fields

// Methods
cls_NCollection_IncAllocator.def("Allocate", (void * (NCollection_IncAllocator::*)(const size_t)) &NCollection_IncAllocator::Allocate, "Allocate memory with given size. Returns NULL on failure", py::arg("size"));
cls_NCollection_IncAllocator.def("Free", (void (NCollection_IncAllocator::*)(void *)) &NCollection_IncAllocator::Free, "Free a previously allocated memory. Does nothing", py::arg("anAddress"));
cls_NCollection_IncAllocator.def("GetMemSize", (size_t (NCollection_IncAllocator::*)() const) &NCollection_IncAllocator::GetMemSize, "Diagnostic method, returns the total allocated size");
cls_NCollection_IncAllocator.def("Reallocate", (void * (NCollection_IncAllocator::*)(void *, const size_t, const size_t)) &NCollection_IncAllocator::Reallocate, "Reallocation: it is always allowed but is only efficient with the last allocated item", py::arg("anAddress"), py::arg("oldSize"), py::arg("newSize"));
cls_NCollection_IncAllocator.def("Reset", [](NCollection_IncAllocator &self) -> void { return self.Reset(); });
cls_NCollection_IncAllocator.def("Reset", (void (NCollection_IncAllocator::*)(const Standard_Boolean)) &NCollection_IncAllocator::Reset, "Re-initialize the allocator so that the next Allocate call should start allocating in the very begining as though the allocator is just constructed. Warning: make sure that all previously allocated data are no more used in your code!", py::arg("doReleaseMem"));
cls_NCollection_IncAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_IncAllocator::get_type_name, "None");
cls_NCollection_IncAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_IncAllocator::get_type_descriptor, "None");
cls_NCollection_IncAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_IncAllocator::*)() const) &NCollection_IncAllocator::DynamicType, "None");

// Enums

}