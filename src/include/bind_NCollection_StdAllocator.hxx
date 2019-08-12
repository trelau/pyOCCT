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
#ifndef __NCollection_StdAllocator__
#define __NCollection_StdAllocator__

#include <pyOCCT_Common.hxx>
#include <NCollection_StdAllocator.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>

template <typename T>
void bind_NCollection_StdAllocator(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_StdAllocator<T>, std::unique_ptr<NCollection_StdAllocator<T>, Deleter<NCollection_StdAllocator<T>>>> cls_NCollection_StdAllocator(mod, name.c_str(), "Implements allocator requirements as defined in ISO C++ Standard 2003, section 20.1.5. The allocator uses instance of the NCollection_BaseAllocator (sub)class for memory allocation/deallocation. The allocator can be used with standard containers (std::vector, std::map, etc) to take advantage of NCollection_IncAllocator which implements memory region concept, and hence to increase performance in specific cases.", local);

// Constructors
cls_NCollection_StdAllocator.def(py::init<>());
cls_NCollection_StdAllocator.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));

// Fields

// Methods
cls_NCollection_StdAllocator.def("address", (NCollection_StdAllocator<T>::pointer (NCollection_StdAllocator<T>::*)(NCollection_StdAllocator<T>::reference) const) &NCollection_StdAllocator<T>::address, "Returns an object address. Returns &x.", py::arg("x"));
cls_NCollection_StdAllocator.def("address", (NCollection_StdAllocator<T>::const_pointer (NCollection_StdAllocator<T>::*)(NCollection_StdAllocator<T>::const_reference) const) &NCollection_StdAllocator<T>::address, "Returns an object address. Returns &x.", py::arg("x"));
cls_NCollection_StdAllocator.def("allocate", [](NCollection_StdAllocator<T> &self, NCollection_StdAllocator<T>::size_type a0) -> NCollection_StdAllocator<T>::pointer { return self.allocate(a0); });
cls_NCollection_StdAllocator.def("allocate", (NCollection_StdAllocator<T>::pointer (NCollection_StdAllocator<T>::*)(NCollection_StdAllocator<T>::size_type, const void *)) &NCollection_StdAllocator<T>::allocate, "Allocates memory for n objects. Uses underlying allocator to allocate memory.", py::arg("n"), py::arg(""));
cls_NCollection_StdAllocator.def("deallocate", (void (NCollection_StdAllocator<T>::*)(NCollection_StdAllocator<T>::pointer, NCollection_StdAllocator<T>::size_type)) &NCollection_StdAllocator<T>::deallocate, "Frees previously allocated memory. Uses underlying allocator to deallocate memory.", py::arg("p"), py::arg(""));
cls_NCollection_StdAllocator.def("max_size", (NCollection_StdAllocator<T>::size_type (NCollection_StdAllocator<T>::*)() const) &NCollection_StdAllocator<T>::max_size, "Returns the largest value for which method allocate might succeed.");
cls_NCollection_StdAllocator.def("construct", (void (NCollection_StdAllocator<T>::*)(NCollection_StdAllocator<T>::pointer, NCollection_StdAllocator<T>::const_reference)) &NCollection_StdAllocator<T>::construct, "Constructs an object. Uses placement new operator and copy constructor to construct an object.", py::arg("p"), py::arg("val"));
cls_NCollection_StdAllocator.def("destroy", (void (NCollection_StdAllocator<T>::*)(NCollection_StdAllocator<T>::pointer)) &NCollection_StdAllocator<T>::destroy, "Destroys the object. Uses object destructor.", py::arg("p"));
cls_NCollection_StdAllocator.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_StdAllocator<T>::*)() const) &NCollection_StdAllocator<T>::Allocator, "Returns an underlying NCollection_BaseAllocator instance. Returns an object specified in the constructor.");

// Enums

}

#endif