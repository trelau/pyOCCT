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
#include <NCollection_SparseArrayBase.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_WinHeapAllocator.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_NCollection_WinHeapAllocator(py::module &mod){

py::class_<NCollection_WinHeapAllocator, opencascade::handle<NCollection_WinHeapAllocator>, NCollection_BaseAllocator> cls_NCollection_WinHeapAllocator(mod, "NCollection_WinHeapAllocator", "This memory allocator creates dedicated heap for allocations. This technics available only on Windows platform (no alternative on Unix systems). It may be used to take control over memory fragmentation because on destruction ALL allocated memory will be released to the system.");

// Constructors
cls_NCollection_WinHeapAllocator.def(py::init<>());
cls_NCollection_WinHeapAllocator.def(py::init<const size_t>(), py::arg("theInitSizeBytes"));

// Fields

// Methods
cls_NCollection_WinHeapAllocator.def("Allocate", (void * (NCollection_WinHeapAllocator::*)(const Standard_Size)) &NCollection_WinHeapAllocator::Allocate, "Allocate memory", py::arg("theSize"));
cls_NCollection_WinHeapAllocator.def("Free", (void (NCollection_WinHeapAllocator::*)(void *)) &NCollection_WinHeapAllocator::Free, "Release memory", py::arg("theAddress"));
cls_NCollection_WinHeapAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_WinHeapAllocator::get_type_name, "None");
cls_NCollection_WinHeapAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_WinHeapAllocator::get_type_descriptor, "None");
cls_NCollection_WinHeapAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_WinHeapAllocator::*)() const) &NCollection_WinHeapAllocator::DynamicType, "None");

// Enums

}