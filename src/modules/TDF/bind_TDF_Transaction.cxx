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
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Data.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Delta.hxx>
#include <TDF_Transaction.hxx>

void bind_TDF_Transaction(py::module &mod){

py::class_<TDF_Transaction> cls_TDF_Transaction(mod, "TDF_Transaction", "This class offers services to open, commit or abort a transaction in a more secure way than using Data from TDF. If you forget to close a transaction, it will be automaticaly aborted at the destruction of this object, at the closure of its scope.");

// Constructors
cls_TDF_Transaction.def(py::init<>());
cls_TDF_Transaction.def(py::init<const TCollection_AsciiString &>(), py::arg("aName"));
cls_TDF_Transaction.def(py::init<const opencascade::handle<TDF_Data> &>(), py::arg("aDF"));
cls_TDF_Transaction.def(py::init<const opencascade::handle<TDF_Data> &, const TCollection_AsciiString &>(), py::arg("aDF"), py::arg("aName"));

// Fields

// Methods
// cls_TDF_Transaction.def_static("operator new_", (void * (*)(size_t)) &TDF_Transaction::operator new, "None", py::arg("theSize"));
// cls_TDF_Transaction.def_static("operator delete_", (void (*)(void *)) &TDF_Transaction::operator delete, "None", py::arg("theAddress"));
// cls_TDF_Transaction.def_static("operator new[]_", (void * (*)(size_t)) &TDF_Transaction::operator new[], "None", py::arg("theSize"));
// cls_TDF_Transaction.def_static("operator delete[]_", (void (*)(void *)) &TDF_Transaction::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_Transaction.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_Transaction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_Transaction.def_static("operator delete_", (void (*)(void *, void *)) &TDF_Transaction::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_Transaction.def("Initialize", (void (TDF_Transaction::*)(const opencascade::handle<TDF_Data> &)) &TDF_Transaction::Initialize, "Aborts all the transactions on <myDF> and sets <aDF> to build a transaction context on <aDF>, ready to be opened.", py::arg("aDF"));
cls_TDF_Transaction.def("Open", (Standard_Integer (TDF_Transaction::*)()) &TDF_Transaction::Open, "If not yet done, opens a new transaction on <myDF>. Returns the index of the just opened transaction.");
cls_TDF_Transaction.def("Commit", [](TDF_Transaction &self) -> opencascade::handle<TDF_Delta> { return self.Commit(); });
cls_TDF_Transaction.def("Commit", (opencascade::handle<TDF_Delta> (TDF_Transaction::*)(const Standard_Boolean)) &TDF_Transaction::Commit, "Commits the transactions until AND including the current opened one.", py::arg("withDelta"));
cls_TDF_Transaction.def("Abort", (void (TDF_Transaction::*)()) &TDF_Transaction::Abort, "Aborts the transactions until AND including the current opened one.");
cls_TDF_Transaction.def("Data", (opencascade::handle<TDF_Data> (TDF_Transaction::*)() const) &TDF_Transaction::Data, "Returns the Data from TDF.");
cls_TDF_Transaction.def("Transaction", (Standard_Integer (TDF_Transaction::*)() const) &TDF_Transaction::Transaction, "Returns the number of the transaction opened by <me>.");
cls_TDF_Transaction.def("Name", (const TCollection_AsciiString & (TDF_Transaction::*)() const) &TDF_Transaction::Name, "Returns the transaction name.");
cls_TDF_Transaction.def("IsOpen", (Standard_Boolean (TDF_Transaction::*)() const) &TDF_Transaction::IsOpen, "Returns true if the transaction is open.");

// Enums

}