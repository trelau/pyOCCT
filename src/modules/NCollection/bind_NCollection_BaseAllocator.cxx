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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>

void bind_NCollection_BaseAllocator(py::module &mod){

py::class_<NCollection_BaseAllocator, opencascade::handle<NCollection_BaseAllocator>, Standard_Transient> cls_NCollection_BaseAllocator(mod, "NCollection_BaseAllocator", "Purpose: Basic class for memory allocation wizards. Defines the interface for devising different allocators firstly to be used by collections of NCollection, though it it is not deferred. It allocates/frees the memory through Standard procedures, thus it is unnecessary (and sometimes injurious) to have more than one such allocator. To avoid creation of multiple objects the constructors were maid inaccessible. To create the BaseAllocator use the method CommonBaseAllocator. Note that this object is managed by Handle.");

// Constructors

// Fields

// Methods
cls_NCollection_BaseAllocator.def("Allocate", (void * (NCollection_BaseAllocator::*)(const size_t)) &NCollection_BaseAllocator::Allocate, "None", py::arg("size"));
cls_NCollection_BaseAllocator.def("Free", (void (NCollection_BaseAllocator::*)(void *)) &NCollection_BaseAllocator::Free, "None", py::arg("anAddress"));
cls_NCollection_BaseAllocator.def_static("CommonBaseAllocator_", (const opencascade::handle<NCollection_BaseAllocator> & (*)()) &NCollection_BaseAllocator::CommonBaseAllocator, "CommonBaseAllocator This method is designed to have the only one BaseAllocator (to avoid useless copying of collections). However one can use operator new to create more BaseAllocators, but it is injurious.");
cls_NCollection_BaseAllocator.def_static("StandardCallBack_", (void (*)(const Standard_Boolean, const Standard_Address, const Standard_Size, const Standard_Size)) &NCollection_BaseAllocator::StandardCallBack, "Callback function to register alloc/free calls", py::arg("theIsAlloc"), py::arg("theStorage"), py::arg("theRoundSize"), py::arg("theSize"));
cls_NCollection_BaseAllocator.def_static("PrintMemUsageStatistics_", (void (*)()) &NCollection_BaseAllocator::PrintMemUsageStatistics, "Prints memory usage statistics cumulated by StandardCallBack");
cls_NCollection_BaseAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_BaseAllocator::get_type_name, "None");
cls_NCollection_BaseAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_BaseAllocator::get_type_descriptor, "None");
cls_NCollection_BaseAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_BaseAllocator::*)() const) &NCollection_BaseAllocator::DynamicType, "None");

// Enums

}