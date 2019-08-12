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
#include <NCollection_AlignedAllocator.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_NCollection_AlignedAllocator(py::module &mod){

py::class_<NCollection_AlignedAllocator, opencascade::handle<NCollection_AlignedAllocator>, NCollection_BaseAllocator> cls_NCollection_AlignedAllocator(mod, "NCollection_AlignedAllocator", "NCollection allocator with managed memory alignment capabilities.");

// Constructors
cls_NCollection_AlignedAllocator.def(py::init<const size_t>(), py::arg("theAlignment"));

// Fields

// Methods
cls_NCollection_AlignedAllocator.def("Allocate", (void * (NCollection_AlignedAllocator::*)(const size_t)) &NCollection_AlignedAllocator::Allocate, "Allocate memory with given size. Returns NULL on failure.", py::arg("theSize"));
cls_NCollection_AlignedAllocator.def("Free", (void (NCollection_AlignedAllocator::*)(void *)) &NCollection_AlignedAllocator::Free, "Free a previously allocated memory.", py::arg("thePtr"));
cls_NCollection_AlignedAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_AlignedAllocator::get_type_name, "None");
cls_NCollection_AlignedAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_AlignedAllocator::get_type_descriptor, "None");
cls_NCollection_AlignedAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_AlignedAllocator::*)() const) &NCollection_AlignedAllocator::DynamicType, "None");

// Enums

}