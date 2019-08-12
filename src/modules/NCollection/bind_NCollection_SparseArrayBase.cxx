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
#include <NCollection_SparseArrayBase.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OutOfRange.hxx>

void bind_NCollection_SparseArrayBase(py::module &mod){

py::class_<NCollection_SparseArrayBase, std::unique_ptr<NCollection_SparseArrayBase, py::nodelete>> cls_NCollection_SparseArrayBase(mod, "NCollection_SparseArrayBase", "Base class for NCollection_SparseArray; provides non-template implementation of general mechanics of block allocation, items creation / deletion etc.");

// Fields

// Methods
cls_NCollection_SparseArrayBase.def("Clear", (void (NCollection_SparseArrayBase::*)()) &NCollection_SparseArrayBase::Clear, "Clears all the data");
cls_NCollection_SparseArrayBase.def("Size", (Standard_Size (NCollection_SparseArrayBase::*)() const) &NCollection_SparseArrayBase::Size, "Returns number of currently contained items");
cls_NCollection_SparseArrayBase.def("HasValue", (Standard_Boolean (NCollection_SparseArrayBase::*)(const Standard_Size) const) &NCollection_SparseArrayBase::HasValue, "Check whether the value at given index is set", py::arg("theIndex"));
cls_NCollection_SparseArrayBase.def("UnsetValue", (Standard_Boolean (NCollection_SparseArrayBase::*)(const Standard_Size)) &NCollection_SparseArrayBase::UnsetValue, "Deletes the item from the array; returns True if that item was defined", py::arg("theIndex"));

// Enums

}