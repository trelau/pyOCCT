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
#include <NCollection_StdAllocator.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Handle.hxx>

void bind_NCollection_StdAllocator(py::module &mod){

py::class_<NCollection_StdAllocator<void>, std::unique_ptr<NCollection_StdAllocator<void>, Deleter<NCollection_StdAllocator<void>>>> cls_NCollection_StdAllocator(mod, "NCollection_StdAllocator", "Implements specialization NCollection_StdAllocator<void>. Specialization is of low value and should normally be avoided in favor of a typed specialization.");

// Constructors
cls_NCollection_StdAllocator.def(py::init<>());
cls_NCollection_StdAllocator.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
cls_NCollection_StdAllocator.def(py::init<const NCollection_StdAllocator<void> &>(), py::arg("X"));

// Fields

// Methods
cls_NCollection_StdAllocator.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_StdAllocator<void>::*)() const) &NCollection_StdAllocator<void>::Allocator, "Returns an underlying NCollection_BaseAllocator instance. Returns an object specified in the constructor.");
// cls_NCollection_StdAllocator.def("operator=", (NCollection_StdAllocator<void> & (NCollection_StdAllocator<void>::*)(const NCollection_StdAllocator<void> &)) &NCollection_StdAllocator<void>::operator=, "Assignment operator", py::arg("X"));

// Enums

}