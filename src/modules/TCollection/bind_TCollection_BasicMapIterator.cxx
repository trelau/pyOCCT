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
#include <Standard_TypeDef.hxx>
#include <TCollection_BasicMap.hxx>
#include <TCollection_BasicMapIterator.hxx>

void bind_TCollection_BasicMapIterator(py::module &mod){

py::class_<TCollection_BasicMapIterator, std::unique_ptr<TCollection_BasicMapIterator>> cls_TCollection_BasicMapIterator(mod, "TCollection_BasicMapIterator", "This class provides basic services for the iterators on Maps. The iterators are inherited from this one.");

// Constructors

// Fields

// Methods
// cls_TCollection_BasicMapIterator.def_static("operator new_", (void * (*)(size_t)) &TCollection_BasicMapIterator::operator new, "None", py::arg("theSize"));
// cls_TCollection_BasicMapIterator.def_static("operator delete_", (void (*)(void *)) &TCollection_BasicMapIterator::operator delete, "None", py::arg("theAddress"));
// cls_TCollection_BasicMapIterator.def_static("operator new[]_", (void * (*)(size_t)) &TCollection_BasicMapIterator::operator new[], "None", py::arg("theSize"));
// cls_TCollection_BasicMapIterator.def_static("operator delete[]_", (void (*)(void *)) &TCollection_BasicMapIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TCollection_BasicMapIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TCollection_BasicMapIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TCollection_BasicMapIterator.def_static("operator delete_", (void (*)(void *, void *)) &TCollection_BasicMapIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TCollection_BasicMapIterator.def("Reset", (void (TCollection_BasicMapIterator::*)()) &TCollection_BasicMapIterator::Reset, "Resets the iterator to the first node.");
cls_TCollection_BasicMapIterator.def("More", (Standard_Boolean (TCollection_BasicMapIterator::*)() const) &TCollection_BasicMapIterator::More, "Returns true if there is a current entry for this iterator in the map. Use the function Next to set this iterator to the position of the next entry, if it exists.");
cls_TCollection_BasicMapIterator.def("Next", (void (TCollection_BasicMapIterator::*)()) &TCollection_BasicMapIterator::Next, "Sets this iterator to the position of the next entry of the map. Nothing is changed if there is no more entry to explore in the map: this iterator is always positioned on the last entry of the map but the function More returns false.");

// Enums

}