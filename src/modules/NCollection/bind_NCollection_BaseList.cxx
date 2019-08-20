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
#include <NCollection_BaseList.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_ListNode.hxx>

void bind_NCollection_BaseList(py::module &mod){

py::class_<NCollection_BaseList, std::unique_ptr<NCollection_BaseList>> cls_NCollection_BaseList(mod, "NCollection_BaseList", "None");

// Constructors

// Fields

// Methods
// cls_NCollection_BaseList.def_static("operator new_", (void * (*)(size_t)) &NCollection_BaseList::operator new, "None", py::arg("theSize"));
// cls_NCollection_BaseList.def_static("operator delete_", (void (*)(void *)) &NCollection_BaseList::operator delete, "None", py::arg("theAddress"));
// cls_NCollection_BaseList.def_static("operator new[]_", (void * (*)(size_t)) &NCollection_BaseList::operator new[], "None", py::arg("theSize"));
// cls_NCollection_BaseList.def_static("operator delete[]_", (void (*)(void *)) &NCollection_BaseList::operator delete[], "None", py::arg("theAddress"));
// cls_NCollection_BaseList.def_static("operator new_", (void * (*)(size_t, void *)) &NCollection_BaseList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_NCollection_BaseList.def_static("operator delete_", (void (*)(void *, void *)) &NCollection_BaseList::operator delete, "None", py::arg(""), py::arg(""));
// cls_NCollection_BaseList.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_BaseList::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_NCollection_BaseList.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_BaseList::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_NCollection_BaseList.def("Extent", (Standard_Integer (NCollection_BaseList::*)() const) &NCollection_BaseList::Extent, "None");
cls_NCollection_BaseList.def("IsEmpty", (Standard_Boolean (NCollection_BaseList::*)() const) &NCollection_BaseList::IsEmpty, "None");
cls_NCollection_BaseList.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_BaseList::*)() const) &NCollection_BaseList::Allocator, "Returns attached allocator");

// Enums

// Nested classes
py::class_<NCollection_BaseList::Iterator, std::unique_ptr<NCollection_BaseList::Iterator>> cls_Iterator(cls_NCollection_BaseList, "Iterator", "Memory allocation");

// Constructors
cls_Iterator.def(py::init<>());
cls_Iterator.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));

// Fields
cls_Iterator.def_readwrite("myCurrent", &NCollection_BaseList::Iterator::myCurrent, "None");
cls_Iterator.def_readwrite("myPrevious", &NCollection_BaseList::Iterator::myPrevious, "None");

// Methods
cls_Iterator.def("Init", (void (NCollection_BaseList::Iterator::*)(const NCollection_BaseList &)) &NCollection_BaseList::Iterator::Init, "None", py::arg("theList"));
cls_Iterator.def("Initialize", (void (NCollection_BaseList::Iterator::*)(const NCollection_BaseList &)) &NCollection_BaseList::Iterator::Initialize, "None", py::arg("theList"));
cls_Iterator.def("More", (Standard_Boolean (NCollection_BaseList::Iterator::*)() const) &NCollection_BaseList::Iterator::More, "None");
// cls_Iterator.def("operator=", (NCollection_BaseList::Iterator & (NCollection_BaseList::Iterator::*)(const NCollection_BaseList::Iterator &)) &NCollection_BaseList::Iterator::operator=, "None", py::arg("theIt"));
cls_Iterator.def("__eq__", (Standard_Boolean (NCollection_BaseList::Iterator::*)(const NCollection_BaseList::Iterator &) const) &NCollection_BaseList::Iterator::operator==, py::is_operator(), "None", py::arg("theIt"));
cls_Iterator.def("IsEqual", (Standard_Boolean (NCollection_BaseList::Iterator::*)(const NCollection_BaseList::Iterator &) const) &NCollection_BaseList::Iterator::IsEqual, "Performs comparison of two iterators", py::arg("theOther"));

// Enums

}