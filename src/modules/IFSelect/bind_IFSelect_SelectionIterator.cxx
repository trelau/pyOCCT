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
#include <IFSelect_Selection.hxx>
#include <IFSelect_SelectionIterator.hxx>
#include <IFSelect_TSeqOfSelection.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_HSeqOfSelection.hxx>

void bind_IFSelect_SelectionIterator(py::module &mod){

py::class_<IFSelect_SelectionIterator, std::unique_ptr<IFSelect_SelectionIterator, Deleter<IFSelect_SelectionIterator>>> cls_IFSelect_SelectionIterator(mod, "IFSelect_SelectionIterator", "Defines an Iterator on a list of Selections");

// Constructors
cls_IFSelect_SelectionIterator.def(py::init<>());
cls_IFSelect_SelectionIterator.def(py::init<const opencascade::handle<IFSelect_Selection> &>(), py::arg("sel"));

// Fields

// Methods
// cls_IFSelect_SelectionIterator.def_static("operator new_", (void * (*)(size_t)) &IFSelect_SelectionIterator::operator new, "None", py::arg("theSize"));
// cls_IFSelect_SelectionIterator.def_static("operator delete_", (void (*)(void *)) &IFSelect_SelectionIterator::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_SelectionIterator.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_SelectionIterator::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_SelectionIterator.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_SelectionIterator::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_SelectionIterator.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_SelectionIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_SelectionIterator.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_SelectionIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_SelectionIterator.def("AddFromIter", (void (IFSelect_SelectionIterator::*)(IFSelect_SelectionIterator &)) &IFSelect_SelectionIterator::AddFromIter, "Adds to an iterator the content of another one (each selection is present only once in the result)", py::arg("iter"));
cls_IFSelect_SelectionIterator.def("AddItem", (void (IFSelect_SelectionIterator::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectionIterator::AddItem, "Adds a Selection to an iterator (if not yet noted)", py::arg("sel"));
cls_IFSelect_SelectionIterator.def("AddList", (void (IFSelect_SelectionIterator::*)(const IFSelect_TSeqOfSelection &)) &IFSelect_SelectionIterator::AddList, "Adds a list of Selections to an iterator (this list comes from the description of a Selection or a Dispatch, etc...)", py::arg("list"));
cls_IFSelect_SelectionIterator.def("More", (Standard_Boolean (IFSelect_SelectionIterator::*)() const) &IFSelect_SelectionIterator::More, "Returns True if there are more Selections to get");
cls_IFSelect_SelectionIterator.def("Next", (void (IFSelect_SelectionIterator::*)()) &IFSelect_SelectionIterator::Next, "Sets iterator to the next item");
cls_IFSelect_SelectionIterator.def("Value", (const opencascade::handle<IFSelect_Selection> & (IFSelect_SelectionIterator::*)() const) &IFSelect_SelectionIterator::Value, "Returns the current Selction beeing iterated Error if count of Selection has been passed");

// Enums

}