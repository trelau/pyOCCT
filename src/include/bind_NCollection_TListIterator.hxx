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
#ifndef __NCollection_TListIterator__
#define __NCollection_TListIterator__

#include <pyOCCT_Common.hxx>
#include <NCollection_BaseList.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_TListIterator.hxx>

template <typename TheItemType>
void bind_NCollection_TListIterator(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_TListIterator<TheItemType>, NCollection_BaseList::Iterator> cls_NCollection_TListIterator(mod, name.c_str(), "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class", local);

// Constructors
cls_NCollection_TListIterator.def(py::init<>());
cls_NCollection_TListIterator.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));

// Fields

// Methods
cls_NCollection_TListIterator.def("More", (Standard_Boolean (NCollection_TListIterator<TheItemType>::*)() const) &NCollection_TListIterator<TheItemType>::More, "Check end");
cls_NCollection_TListIterator.def("Next", (void (NCollection_TListIterator<TheItemType>::*)()) &NCollection_TListIterator<TheItemType>::Next, "Make step");
cls_NCollection_TListIterator.def("Value", (const TheItemType & (NCollection_TListIterator<TheItemType>::*)() const) &NCollection_TListIterator<TheItemType>::Value, "Constant Value access");
cls_NCollection_TListIterator.def("Value", (TheItemType & (NCollection_TListIterator<TheItemType>::*)()) &NCollection_TListIterator<TheItemType>::Value, "Non-const Value access");
cls_NCollection_TListIterator.def("ChangeValue", (TheItemType & (NCollection_TListIterator<TheItemType>::*)() const) &NCollection_TListIterator<TheItemType>::ChangeValue, "Non-const Value access");

// Enums

}

#endif