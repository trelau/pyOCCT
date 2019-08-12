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
#include <Transfer_Binder.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_StatusExec.hxx>
#include <Interface_Check.hxx>
#include <Transfer_HSequenceOfBinder.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Transfer_TransferIterator.hxx>

void bind_Transfer_TransferIterator(py::module &mod){

py::class_<Transfer_TransferIterator, std::unique_ptr<Transfer_TransferIterator, Deleter<Transfer_TransferIterator>>> cls_Transfer_TransferIterator(mod, "Transfer_TransferIterator", "Defines an Iterator on the result of a Transfer Available for Normal Results or not (Erroneous Transfer) It gives several kinds of Informations, and allows to consider various criteria (criteria are cumulative)");

// Constructors
cls_Transfer_TransferIterator.def(py::init<>());

// Fields

// Methods
// cls_Transfer_TransferIterator.def_static("operator new_", (void * (*)(size_t)) &Transfer_TransferIterator::operator new, "None", py::arg("theSize"));
// cls_Transfer_TransferIterator.def_static("operator delete_", (void (*)(void *)) &Transfer_TransferIterator::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_TransferIterator.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_TransferIterator::operator new[], "None", py::arg("theSize"));
// cls_Transfer_TransferIterator.def_static("operator delete[]_", (void (*)(void *)) &Transfer_TransferIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_TransferIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_TransferIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_TransferIterator.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_TransferIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_TransferIterator.def("AddItem", (void (Transfer_TransferIterator::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_TransferIterator::AddItem, "Adds a Binder to the iteration list (construction)", py::arg("atr"));
cls_Transfer_TransferIterator.def("SelectBinder", (void (Transfer_TransferIterator::*)(const opencascade::handle<Standard_Type> &, const Standard_Boolean)) &Transfer_TransferIterator::SelectBinder, "Selects Items on the Type of Binder : keep only Binders which are of a given Type (if keep is True) or reject only them (if keep is False)", py::arg("atype"), py::arg("keep"));
cls_Transfer_TransferIterator.def("SelectResult", (void (Transfer_TransferIterator::*)(const opencascade::handle<Standard_Type> &, const Standard_Boolean)) &Transfer_TransferIterator::SelectResult, "Selects Items on the Type of Result. Considers only Unique Results. Considers Dynamic Type for Transient Result, Static Type (the one given to define the Binder) else.", py::arg("atype"), py::arg("keep"));
cls_Transfer_TransferIterator.def("SelectUnique", (void (Transfer_TransferIterator::*)(const Standard_Boolean)) &Transfer_TransferIterator::SelectUnique, "Select Items according Unicity : keep only Unique Results (if keep is True) or keep only Multiple Results (if keep is False)", py::arg("keep"));
cls_Transfer_TransferIterator.def("SelectItem", (void (Transfer_TransferIterator::*)(const Standard_Integer, const Standard_Boolean)) &Transfer_TransferIterator::SelectItem, "Selects/Unselect (according to <keep> an item designated by its rank <num> in the list Used by sub-classes which have specific criteria", py::arg("num"), py::arg("keep"));
cls_Transfer_TransferIterator.def("Number", (Standard_Integer (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::Number, "Returns count of Binders to be iterated");
cls_Transfer_TransferIterator.def("Start", (void (Transfer_TransferIterator::*)()) &Transfer_TransferIterator::Start, "Clears Iteration in progress, to allow it to be restarted");
cls_Transfer_TransferIterator.def("More", (Standard_Boolean (Transfer_TransferIterator::*)()) &Transfer_TransferIterator::More, "Returns True if there are other Items to iterate");
cls_Transfer_TransferIterator.def("Next", (void (Transfer_TransferIterator::*)()) &Transfer_TransferIterator::Next, "Sets Iteration to the next Item");
cls_Transfer_TransferIterator.def("Value", (const opencascade::handle<Transfer_Binder> & (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::Value, "Returns the current Binder");
cls_Transfer_TransferIterator.def("HasResult", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasResult, "Returns True if current Item brings a Result, Transient (Handle) or not or Multiple. That is to say, if it corresponds to a normally acheived Transfer, Transient Result is read by specific TransientResult below. Other kind of Result must be read specifically from its Binder");
cls_Transfer_TransferIterator.def("HasUniqueResult", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasUniqueResult, "Returns True if Current Item has a Unique Result");
cls_Transfer_TransferIterator.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::ResultType, "Returns the Type of the Result of the current Item, if Unique. If No Unique Result (Error Transfert or Multiple Result), returns a Null Handle The Type is : the Dynamic Type for a Transient Result, the Type defined by the Binder Class else");
cls_Transfer_TransferIterator.def("HasTransientResult", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasTransientResult, "Returns True if the current Item has a Transient Unique Result (if yes, use TransientResult to get it)");
cls_Transfer_TransferIterator.def("TransientResult", (const opencascade::handle<Standard_Transient> & (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::TransientResult, "Returns the Transient Result of the current Item if there is (else, returns a null Handle) Supposes that Binding is done by a SimpleBinderOfTransient");
cls_Transfer_TransferIterator.def("Status", (Transfer_StatusExec (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::Status, "Returns Execution Status of current Binder Normal transfer corresponds to StatusDone");
cls_Transfer_TransferIterator.def("HasFails", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasFails, "Returns True if Fail Messages are recorded with the current Binder. They can then be read through Check (see below)");
cls_Transfer_TransferIterator.def("HasWarnings", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasWarnings, "Returns True if Warning Messages are recorded with the current Binder. They can then be read through Check (see below)");
cls_Transfer_TransferIterator.def("Check", (const opencascade::handle<Interface_Check> (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::Check, "Returns Check associated to current Binder (in case of error, it brings Fail messages) (in case of warnings, it brings Warning messages)");

// Enums

}