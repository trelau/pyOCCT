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
#pragma once

#include <pyOCCT_Common.hxx>
#include <NCollection_UBTreeFiller.hxx>
#include <NCollection_UBTree.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <NCollection_Vector.hxx>

template <typename TheObjType, typename TheBndType>
void bind_NCollection_UBTreeFiller(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_UBTreeFiller<TheObjType, TheBndType>> cls_NCollection_UBTreeFiller(mod, name.c_str(), "This class is used to fill an UBTree in a random order. The quality of a tree is much better (from the point of view of the search time) if objects are added to it in a random order to avoid adding a chain of neerby objects one following each other.", local);

// Constructors
cls_NCollection_UBTreeFiller.def(py::init<typename NCollection_UBTreeFiller<TheObjType, TheBndType>::UBTree &>(), py::arg("theTree"));
cls_NCollection_UBTreeFiller.def(py::init<typename NCollection_UBTreeFiller<TheObjType, TheBndType>::UBTree &, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theTree"), py::arg("theAlloc"));
cls_NCollection_UBTreeFiller.def(py::init<typename NCollection_UBTreeFiller<TheObjType, TheBndType>::UBTree &, const opencascade::handle<NCollection_BaseAllocator> &, const Standard_Boolean>(), py::arg("theTree"), py::arg("theAlloc"), py::arg("isFullRandom"));

// Methods
cls_NCollection_UBTreeFiller.def("Add", (void (NCollection_UBTreeFiller<TheObjType, TheBndType>::*)(const TheObjType &, const TheBndType &)) &NCollection_UBTreeFiller<TheObjType, TheBndType>::Add, "Adds a pair (theObj, theBnd) to my sequence", py::arg("theObj"), py::arg("theBnd"));
cls_NCollection_UBTreeFiller.def("Fill", (Standard_Integer (NCollection_UBTreeFiller<TheObjType, TheBndType>::*)()) &NCollection_UBTreeFiller<TheObjType, TheBndType>::Fill, "Fills the tree with the objects from my sequence. This method clears the internal buffer of added items making sure that no item would be added twice.");
cls_NCollection_UBTreeFiller.def("Reset", (void (NCollection_UBTreeFiller<TheObjType, TheBndType>::*)()) &NCollection_UBTreeFiller<TheObjType, TheBndType>::Reset, "Remove all data from Filler, partculary if the Tree no more needed so the destructor of this Filler should not populate the useless Tree.");
cls_NCollection_UBTreeFiller.def("CheckTree", (Standard_Integer (NCollection_UBTreeFiller<TheObjType, TheBndType>::*)(Standard_OStream &)) &NCollection_UBTreeFiller<TheObjType, TheBndType>::CheckTree, "Check the filled tree for the total number of items and the balance outputting these results to ostream.", py::arg("theStream"));

}
