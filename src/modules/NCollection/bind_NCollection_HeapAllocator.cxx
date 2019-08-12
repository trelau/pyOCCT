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
#include <Standard_Handle.hxx>
#include <NCollection_HeapAllocator.hxx>
#include <Standard_Type.hxx>

void bind_NCollection_HeapAllocator(py::module &mod){

py::class_<NCollection_HeapAllocator, opencascade::handle<NCollection_HeapAllocator>, NCollection_BaseAllocator> cls_NCollection_HeapAllocator(mod, "NCollection_HeapAllocator", "Allocator that uses the global dynamic heap (malloc / free).");

// Constructors

// Fields

// Methods
cls_NCollection_HeapAllocator.def("Allocate", (void * (NCollection_HeapAllocator::*)(const Standard_Size)) &NCollection_HeapAllocator::Allocate, "None", py::arg("theSize"));
cls_NCollection_HeapAllocator.def("Free", (void (NCollection_HeapAllocator::*)(void *)) &NCollection_HeapAllocator::Free, "None", py::arg("anAddress"));
cls_NCollection_HeapAllocator.def_static("GlobalHeapAllocator_", (const opencascade::handle<NCollection_HeapAllocator> & (*)()) &NCollection_HeapAllocator::GlobalHeapAllocator, "None");
cls_NCollection_HeapAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_HeapAllocator::get_type_name, "None");
cls_NCollection_HeapAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_HeapAllocator::get_type_descriptor, "None");
cls_NCollection_HeapAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_HeapAllocator::*)() const) &NCollection_HeapAllocator::DynamicType, "None");

// Enums

}