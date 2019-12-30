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
#ifndef __NCollection_StlIterator__
#define __NCollection_StlIterator__

#include <NCollection_StlIterator.hxx>
#include <Standard_Assert.hxx>

template <typename Category, typename BaseIterator, typename ItemType, bool IsConstant>
void bind_NCollection_StlIterator(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>, std::iterator<Category, ItemType, ptrdiff_t, typename opencascade::std::conditional<IsConstant, const ItemType *, ItemType *>::type, typename opencascade::std::conditional<IsConstant, const ItemType &, ItemType &>::type>> cls_NCollection_StlIterator(mod, name.c_str(), "Helper class that allows to use NCollection iterators as STL iterators. NCollection iterator can be extended to STL iterator of any category by adding necessary methods: STL forward iterator requires IsEqual method, STL bidirectional iterator requires Previous method, and STL random access iterator requires Offset and Differ methods. See NCollection_Vector as example of declaring custom STL iterators.", local);

// Constructors
cls_NCollection_StlIterator.def(py::init<>());
cls_NCollection_StlIterator.def(py::init<const BaseIterator &>(), py::arg("theIterator"));
cls_NCollection_StlIterator.def(py::init<const NCollection_StlIterator<Category, BaseIterator, ItemType, false> &>(), py::arg("theIterator"));

// Methods
// cls_NCollection_StlIterator.def("operator=", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, false> &)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator=, "Assignment of non-const iterator to const one", py::arg("theIterator"));
cls_NCollection_StlIterator.def("Iterator", (const BaseIterator & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)() const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::Iterator, "Access to NCollection iterator instance");
cls_NCollection_StlIterator.def("ChangeIterator", (BaseIterator & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)()) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::ChangeIterator, "Access to NCollection iterator instance");
cls_NCollection_StlIterator.def("__eq__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator==, py::is_operator(), "Test for equality", py::arg("theOther"));
cls_NCollection_StlIterator.def("__ne__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator!=, py::is_operator(), "Test for inequality", py::arg("theOther"));
cls_NCollection_StlIterator.def("__mul__", (typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::reference (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)() const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator*, py::is_operator(), "Get reference to current item");
// cls_NCollection_StlIterator.def("operator->", (typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::pointer (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)() const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator->, "Dereferencing operator");
cls_NCollection_StlIterator.def("plus_plus", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)()) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator++, py::is_operator(), "Prefix increment");
cls_NCollection_StlIterator.def("plus_plus", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(int)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator++, py::is_operator(), "Postfix increment", py::arg(""));
cls_NCollection_StlIterator.def("minus_minus", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)()) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator--, py::is_operator(), "Prefix decrement");
cls_NCollection_StlIterator.def("minus_minus", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(int)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator--, py::is_operator(), "Postfix decrement", py::arg(""));
cls_NCollection_StlIterator.def("__iadd__", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator+=, py::is_operator(), "Move forward", py::arg("theOffset"));
cls_NCollection_StlIterator.def("__add__", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator+, py::is_operator(), "Addition", py::arg("theOffset"));
cls_NCollection_StlIterator.def("__isub__", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator-=, py::is_operator(), "Move backward", py::arg("theOffset"));
cls_NCollection_StlIterator.def("__sub__", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator-, py::is_operator(), "Decrease", py::arg("theOffset"));
cls_NCollection_StlIterator.def("__sub__", (typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator-, py::is_operator(), "Difference", py::arg("theOther"));
cls_NCollection_StlIterator.def("__getitem__", (typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::reference (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator[], py::is_operator(), "Get item at offset from current", py::arg("theOffset"));
cls_NCollection_StlIterator.def("__lt__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator<, py::is_operator(), "Comparison", py::arg("theOther"));
cls_NCollection_StlIterator.def("__gt__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator>, py::is_operator(), "Comparison", py::arg("theOther"));
cls_NCollection_StlIterator.def("__le__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator<=, py::is_operator(), "Comparison", py::arg("theOther"));
cls_NCollection_StlIterator.def("__ge__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator>=, py::is_operator(), "Comparison", py::arg("theOther"));

}

#endif