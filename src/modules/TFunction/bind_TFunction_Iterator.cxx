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
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelList.hxx>
#include <TFunction_ExecutionStatus.hxx>
#include <Standard_OStream.hxx>
#include <TDF_LabelMap.hxx>
#include <Standard_Handle.hxx>
#include <TFunction_Scope.hxx>
#include <TFunction_Iterator.hxx>

void bind_TFunction_Iterator(py::module &mod){

py::class_<TFunction_Iterator, std::unique_ptr<TFunction_Iterator, Deleter<TFunction_Iterator>>> cls_TFunction_Iterator(mod, "TFunction_Iterator", "Iterator of the graph of functions");

// Constructors
cls_TFunction_Iterator.def(py::init<>());
cls_TFunction_Iterator.def(py::init<const TDF_Label &>(), py::arg("Access"));

// Fields

// Methods
// cls_TFunction_Iterator.def_static("operator new_", (void * (*)(size_t)) &TFunction_Iterator::operator new, "None", py::arg("theSize"));
// cls_TFunction_Iterator.def_static("operator delete_", (void (*)(void *)) &TFunction_Iterator::operator delete, "None", py::arg("theAddress"));
// cls_TFunction_Iterator.def_static("operator new[]_", (void * (*)(size_t)) &TFunction_Iterator::operator new[], "None", py::arg("theSize"));
// cls_TFunction_Iterator.def_static("operator delete[]_", (void (*)(void *)) &TFunction_Iterator::operator delete[], "None", py::arg("theAddress"));
// cls_TFunction_Iterator.def_static("operator new_", (void * (*)(size_t, void *)) &TFunction_Iterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TFunction_Iterator.def_static("operator delete_", (void (*)(void *, void *)) &TFunction_Iterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TFunction_Iterator.def("Init", (void (TFunction_Iterator::*)(const TDF_Label &)) &TFunction_Iterator::Init, "Initializes the Iterator.", py::arg("Access"));
cls_TFunction_Iterator.def("SetUsageOfExecutionStatus", (void (TFunction_Iterator::*)(const Standard_Boolean)) &TFunction_Iterator::SetUsageOfExecutionStatus, "Defines the mode of iteration - usage or not of the execution status. If the iterator takes into account the execution status, the method ::Current() returns only 'not executed' functions while their status is not changed. If the iterator ignores the execution status, the method ::Current() returns the functions following their dependencies and ignoring the execution status.", py::arg("usage"));
cls_TFunction_Iterator.def("GetUsageOfExecutionStatus", (Standard_Boolean (TFunction_Iterator::*)() const) &TFunction_Iterator::GetUsageOfExecutionStatus, "Returns usage of execution status by the iterator.");
cls_TFunction_Iterator.def("GetMaxNbThreads", (Standard_Integer (TFunction_Iterator::*)() const) &TFunction_Iterator::GetMaxNbThreads, "Analyses the graph of dependencies and returns maximum number of threads may be used to calculate the model.");
cls_TFunction_Iterator.def("Current", (const TDF_LabelList & (TFunction_Iterator::*)() const) &TFunction_Iterator::Current, "Returns the current list of functions. If the iterator uses the execution status, the returned list contains only the functions with 'not executed' status.");
cls_TFunction_Iterator.def("More", (Standard_Boolean (TFunction_Iterator::*)() const) &TFunction_Iterator::More, "Returns false if the graph of functions is fully iterated.");
cls_TFunction_Iterator.def("Next", (void (TFunction_Iterator::*)()) &TFunction_Iterator::Next, "Switches the iterator to the next list of current functions.");
cls_TFunction_Iterator.def("GetStatus", (TFunction_ExecutionStatus (TFunction_Iterator::*)(const TDF_Label &) const) &TFunction_Iterator::GetStatus, "A help-function aimed to help the user to check the status of retrurned function. It calls TFunction_GraphNode::GetStatus() inside.", py::arg("func"));
cls_TFunction_Iterator.def("SetStatus", (void (TFunction_Iterator::*)(const TDF_Label &, const TFunction_ExecutionStatus) const) &TFunction_Iterator::SetStatus, "A help-function aimed to help the user to change the execution status of a function. It calls TFunction_GraphNode::SetStatus() inside.", py::arg("func"), py::arg("status"));
cls_TFunction_Iterator.def("Dump", (Standard_OStream & (TFunction_Iterator::*)(Standard_OStream &) const) &TFunction_Iterator::Dump, "None", py::arg("OS"));

// Enums

}