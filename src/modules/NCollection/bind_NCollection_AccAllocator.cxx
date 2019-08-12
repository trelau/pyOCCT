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
#include <NCollection_AccAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_NCollection_AccAllocator(py::module &mod){

py::class_<NCollection_AccAllocator, opencascade::handle<NCollection_AccAllocator>, NCollection_BaseAllocator> cls_NCollection_AccAllocator(mod, "NCollection_AccAllocator", "Class NCollection_AccAllocator - accumulating memory allocator. This class allocates memory on request returning the pointer to the allocated space. The allocation units are grouped in blocks requested from the system as required. This memory is returned to the system when all allocations in a block are freed.");

// Constructors
cls_NCollection_AccAllocator.def(py::init<>());
cls_NCollection_AccAllocator.def(py::init<const size_t>(), py::arg("theBlockSize"));

// Fields

// Methods
cls_NCollection_AccAllocator.def("Allocate", (void * (NCollection_AccAllocator::*)(const size_t)) &NCollection_AccAllocator::Allocate, "Allocate memory with given size", py::arg("theSize"));
cls_NCollection_AccAllocator.def("Free", (void (NCollection_AccAllocator::*)(void *)) &NCollection_AccAllocator::Free, "Free a previously allocated memory; memory is returned to the OS when all allocations in some block are freed", py::arg("theAddress"));
cls_NCollection_AccAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_AccAllocator::get_type_name, "None");
cls_NCollection_AccAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_AccAllocator::get_type_descriptor, "None");
cls_NCollection_AccAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_AccAllocator::*)() const) &NCollection_AccAllocator::DynamicType, "None");

// Enums

}