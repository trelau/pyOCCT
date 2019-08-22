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
#include <Transfer_TransferIterator.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_Binder.hxx>
#include <Transfer_Finder.hxx>
#include <Transfer_HSequenceOfFinder.hxx>
#include <Transfer_IteratorOfProcessForFinder.hxx>

void bind_Transfer_IteratorOfProcessForFinder(py::module &mod){

py::class_<Transfer_IteratorOfProcessForFinder, Transfer_TransferIterator> cls_Transfer_IteratorOfProcessForFinder(mod, "Transfer_IteratorOfProcessForFinder", "None");

// Constructors
cls_Transfer_IteratorOfProcessForFinder.def(py::init<const Standard_Boolean>(), py::arg("withstarts"));

// Fields

// Methods
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator new_", (void * (*)(size_t)) &Transfer_IteratorOfProcessForFinder::operator new, "None", py::arg("theSize"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator delete_", (void (*)(void *)) &Transfer_IteratorOfProcessForFinder::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_IteratorOfProcessForFinder::operator new[], "None", py::arg("theSize"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator delete[]_", (void (*)(void *)) &Transfer_IteratorOfProcessForFinder::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_IteratorOfProcessForFinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_IteratorOfProcessForFinder::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_IteratorOfProcessForFinder.def("Add", (void (Transfer_IteratorOfProcessForFinder::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_IteratorOfProcessForFinder::Add, "Adds a Binder to the iteration list (construction) with no corresponding Starting Object (note that Result is brought by Binder)", py::arg("binder"));
cls_Transfer_IteratorOfProcessForFinder.def("Add", (void (Transfer_IteratorOfProcessForFinder::*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Transfer_Finder> &)) &Transfer_IteratorOfProcessForFinder::Add, "Adds a Binder to the iteration list, associated with its corresponding Starting Object 'start' Starting Object is ignored if not required at Creation time", py::arg("binder"), py::arg("start"));
cls_Transfer_IteratorOfProcessForFinder.def("Filter", [](Transfer_IteratorOfProcessForFinder &self, const opencascade::handle<Transfer_HSequenceOfFinder> & a0) -> void { return self.Filter(a0); });
cls_Transfer_IteratorOfProcessForFinder.def("Filter", (void (Transfer_IteratorOfProcessForFinder::*)(const opencascade::handle<Transfer_HSequenceOfFinder> &, const Standard_Boolean)) &Transfer_IteratorOfProcessForFinder::Filter, "After having added all items, keeps or rejects items which are attached to starting data given by <only> <keep> = True (D) : keeps. <keep> = False : rejects Does nothing if <withstarts> was False", py::arg("list"), py::arg("keep"));
cls_Transfer_IteratorOfProcessForFinder.def("HasStarting", (Standard_Boolean (Transfer_IteratorOfProcessForFinder::*)() const) &Transfer_IteratorOfProcessForFinder::HasStarting, "Returns True if Starting Object is available (defined at Creation Time)");
cls_Transfer_IteratorOfProcessForFinder.def("Starting", (const opencascade::handle<Transfer_Finder> & (Transfer_IteratorOfProcessForFinder::*)() const) &Transfer_IteratorOfProcessForFinder::Starting, "Returns corresponding Starting Object");

// Enums

}