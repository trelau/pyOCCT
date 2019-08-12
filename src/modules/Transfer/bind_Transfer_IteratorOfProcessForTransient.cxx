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
#include <Standard_Transient.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Transfer_IteratorOfProcessForTransient.hxx>

void bind_Transfer_IteratorOfProcessForTransient(py::module &mod){

py::class_<Transfer_IteratorOfProcessForTransient, std::unique_ptr<Transfer_IteratorOfProcessForTransient, Deleter<Transfer_IteratorOfProcessForTransient>>, Transfer_TransferIterator> cls_Transfer_IteratorOfProcessForTransient(mod, "Transfer_IteratorOfProcessForTransient", "None");

// Constructors
cls_Transfer_IteratorOfProcessForTransient.def(py::init<const Standard_Boolean>(), py::arg("withstarts"));

// Fields

// Methods
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator new_", (void * (*)(size_t)) &Transfer_IteratorOfProcessForTransient::operator new, "None", py::arg("theSize"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator delete_", (void (*)(void *)) &Transfer_IteratorOfProcessForTransient::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_IteratorOfProcessForTransient::operator new[], "None", py::arg("theSize"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator delete[]_", (void (*)(void *)) &Transfer_IteratorOfProcessForTransient::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_IteratorOfProcessForTransient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_IteratorOfProcessForTransient::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_IteratorOfProcessForTransient.def("Add", (void (Transfer_IteratorOfProcessForTransient::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_IteratorOfProcessForTransient::Add, "Adds a Binder to the iteration list (construction) with no corresponding Starting Object (note that Result is brought by Binder)", py::arg("binder"));
cls_Transfer_IteratorOfProcessForTransient.def("Add", (void (Transfer_IteratorOfProcessForTransient::*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Standard_Transient> &)) &Transfer_IteratorOfProcessForTransient::Add, "Adds a Binder to the iteration list, associated with its corresponding Starting Object 'start' Starting Object is ignored if not required at Creation time", py::arg("binder"), py::arg("start"));
cls_Transfer_IteratorOfProcessForTransient.def("Filter", [](Transfer_IteratorOfProcessForTransient &self, const opencascade::handle<TColStd_HSequenceOfTransient> & a0) -> void { return self.Filter(a0); });
cls_Transfer_IteratorOfProcessForTransient.def("Filter", (void (Transfer_IteratorOfProcessForTransient::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const Standard_Boolean)) &Transfer_IteratorOfProcessForTransient::Filter, "After having added all items, keeps or rejects items which are attached to starting data given by <only> <keep> = True (D) : keeps. <keep> = False : rejects Does nothing if <withstarts> was False", py::arg("list"), py::arg("keep"));
cls_Transfer_IteratorOfProcessForTransient.def("HasStarting", (Standard_Boolean (Transfer_IteratorOfProcessForTransient::*)() const) &Transfer_IteratorOfProcessForTransient::HasStarting, "Returns True if Starting Object is available (defined at Creation Time)");
cls_Transfer_IteratorOfProcessForTransient.def("Starting", (const opencascade::handle<Standard_Transient> & (Transfer_IteratorOfProcessForTransient::*)() const) &Transfer_IteratorOfProcessForTransient::Starting, "Returns corresponding Starting Object");

// Enums

}