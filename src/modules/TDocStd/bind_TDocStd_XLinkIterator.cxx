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
#include <TDocStd_XLink.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_XLinkPtr.hxx>
#include <TDocStd_XLinkIterator.hxx>

void bind_TDocStd_XLinkIterator(py::module &mod){

py::class_<TDocStd_XLinkIterator, std::unique_ptr<TDocStd_XLinkIterator, Deleter<TDocStd_XLinkIterator>>> cls_TDocStd_XLinkIterator(mod, "TDocStd_XLinkIterator", "Iterates on Reference attributes. This is an iterator giving all the external references of a Document.");

// Constructors
cls_TDocStd_XLinkIterator.def(py::init<>());
cls_TDocStd_XLinkIterator.def(py::init<const opencascade::handle<TDocStd_Document> &>(), py::arg("D"));

// Fields

// Methods
// cls_TDocStd_XLinkIterator.def_static("operator new_", (void * (*)(size_t)) &TDocStd_XLinkIterator::operator new, "None", py::arg("theSize"));
// cls_TDocStd_XLinkIterator.def_static("operator delete_", (void (*)(void *)) &TDocStd_XLinkIterator::operator delete, "None", py::arg("theAddress"));
// cls_TDocStd_XLinkIterator.def_static("operator new[]_", (void * (*)(size_t)) &TDocStd_XLinkIterator::operator new[], "None", py::arg("theSize"));
// cls_TDocStd_XLinkIterator.def_static("operator delete[]_", (void (*)(void *)) &TDocStd_XLinkIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TDocStd_XLinkIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TDocStd_XLinkIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDocStd_XLinkIterator.def_static("operator delete_", (void (*)(void *, void *)) &TDocStd_XLinkIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TDocStd_XLinkIterator.def("Initialize", (void (TDocStd_XLinkIterator::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_XLinkIterator::Initialize, "Restarts an iteration with <D>.", py::arg("D"));
cls_TDocStd_XLinkIterator.def("More", (Standard_Boolean (TDocStd_XLinkIterator::*)() const) &TDocStd_XLinkIterator::More, "Returns True if there is a current Item in the iteration.");
cls_TDocStd_XLinkIterator.def("Next", (void (TDocStd_XLinkIterator::*)()) &TDocStd_XLinkIterator::Next, "Move to the next item; raises if there is no more item.");
cls_TDocStd_XLinkIterator.def("Value", (TDocStd_XLinkPtr (TDocStd_XLinkIterator::*)() const) &TDocStd_XLinkIterator::Value, "Returns the current item; a null handle if there is none.");

// Enums

}