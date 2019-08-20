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
#include <TCollection_BaseSequence.hxx>

void bind_TCollection_BaseSequence(py::module &mod){

py::class_<TCollection_BaseSequence, std::unique_ptr<TCollection_BaseSequence>> cls_TCollection_BaseSequence(mod, "TCollection_BaseSequence", "Definition of a base class for all instanciations of sequence.");

// Constructors

// Fields

// Methods
// cls_TCollection_BaseSequence.def_static("operator new_", (void * (*)(size_t)) &TCollection_BaseSequence::operator new, "None", py::arg("theSize"));
// cls_TCollection_BaseSequence.def_static("operator delete_", (void (*)(void *)) &TCollection_BaseSequence::operator delete, "None", py::arg("theAddress"));
// cls_TCollection_BaseSequence.def_static("operator new[]_", (void * (*)(size_t)) &TCollection_BaseSequence::operator new[], "None", py::arg("theSize"));
// cls_TCollection_BaseSequence.def_static("operator delete[]_", (void (*)(void *)) &TCollection_BaseSequence::operator delete[], "None", py::arg("theAddress"));
// cls_TCollection_BaseSequence.def_static("operator new_", (void * (*)(size_t, void *)) &TCollection_BaseSequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TCollection_BaseSequence.def_static("operator delete_", (void (*)(void *, void *)) &TCollection_BaseSequence::operator delete, "None", py::arg(""), py::arg(""));
cls_TCollection_BaseSequence.def("IsEmpty", (Standard_Boolean (TCollection_BaseSequence::*)() const) &TCollection_BaseSequence::IsEmpty, "returns True if the sequence <me> contains no elements.");
cls_TCollection_BaseSequence.def("Length", (Standard_Integer (TCollection_BaseSequence::*)() const) &TCollection_BaseSequence::Length, "Returns the number of element(s) in the sequence. Returns zero if the sequence is empty.");
cls_TCollection_BaseSequence.def("Reverse", (void (TCollection_BaseSequence::*)()) &TCollection_BaseSequence::Reverse, "Reverses the order of items on <me>. Example: before me = (A B C) after me = (C B A)");
cls_TCollection_BaseSequence.def("Exchange", (void (TCollection_BaseSequence::*)(const Standard_Integer, const Standard_Integer)) &TCollection_BaseSequence::Exchange, "Swaps elements which are located at positions <I> and <J> in <me>. Raises an exception if I or J is out of bound. Example: before me = (A B C), I = 1, J = 3 after me = (C B A)", py::arg("I"), py::arg("J"));

// Enums

}