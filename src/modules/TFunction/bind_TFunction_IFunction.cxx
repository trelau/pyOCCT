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
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <TDF_LabelList.hxx>
#include <TFunction_ExecutionStatus.hxx>
#include <TFunction_DoubleMapOfIntegerLabel.hxx>
#include <Standard_Handle.hxx>
#include <TFunction_Logbook.hxx>
#include <TFunction_Driver.hxx>
#include <TFunction_GraphNode.hxx>
#include <TFunction_IFunction.hxx>

void bind_TFunction_IFunction(py::module &mod){

py::class_<TFunction_IFunction, std::unique_ptr<TFunction_IFunction, Deleter<TFunction_IFunction>>> cls_TFunction_IFunction(mod, "TFunction_IFunction", "Interface class for usage of Function Mechanism");

// Constructors
cls_TFunction_IFunction.def(py::init<>());
cls_TFunction_IFunction.def(py::init<const TDF_Label &>(), py::arg("L"));

// Fields

// Methods
// cls_TFunction_IFunction.def_static("operator new_", (void * (*)(size_t)) &TFunction_IFunction::operator new, "None", py::arg("theSize"));
// cls_TFunction_IFunction.def_static("operator delete_", (void (*)(void *)) &TFunction_IFunction::operator delete, "None", py::arg("theAddress"));
// cls_TFunction_IFunction.def_static("operator new[]_", (void * (*)(size_t)) &TFunction_IFunction::operator new[], "None", py::arg("theSize"));
// cls_TFunction_IFunction.def_static("operator delete[]_", (void (*)(void *)) &TFunction_IFunction::operator delete[], "None", py::arg("theAddress"));
// cls_TFunction_IFunction.def_static("operator new_", (void * (*)(size_t, void *)) &TFunction_IFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TFunction_IFunction.def_static("operator delete_", (void (*)(void *, void *)) &TFunction_IFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_TFunction_IFunction.def_static("NewFunction_", (Standard_Boolean (*)(const TDF_Label &, const Standard_GUID &)) &TFunction_IFunction::NewFunction, "Sets a new function attached to a label <L> with <ID>. It creates a new TFunction_Function attribute initialized by the <ID>, a new TFunction_GraphNode with an empty list of dependencies and the status equal to TFunction_ES_WrongDefinition. It registers the function in the scope of functions for this document.", py::arg("L"), py::arg("ID"));
cls_TFunction_IFunction.def_static("DeleteFunction_", (Standard_Boolean (*)(const TDF_Label &)) &TFunction_IFunction::DeleteFunction, "Deletes a function attached to a label <L>. It deletes a TFunction_Function attribute and a TFunction_GraphNode. It deletes the functions from the scope of function of this document.", py::arg("L"));
cls_TFunction_IFunction.def_static("UpdateDependencies_", (Standard_Boolean (*)(const TDF_Label &)) &TFunction_IFunction::UpdateDependencies, "Updates dependencies for all functions of the scope. It returns false in case of an error. An empty constructor.", py::arg("Access"));
cls_TFunction_IFunction.def("Init", (void (TFunction_IFunction::*)(const TDF_Label &)) &TFunction_IFunction::Init, "Initializes the interface by the label of function.", py::arg("L"));
cls_TFunction_IFunction.def("Label", (const TDF_Label & (TFunction_IFunction::*)() const) &TFunction_IFunction::Label, "Returns a label of the function.");
cls_TFunction_IFunction.def("UpdateDependencies", (Standard_Boolean (TFunction_IFunction::*)() const) &TFunction_IFunction::UpdateDependencies, "Updates the dependencies of this function only.");
cls_TFunction_IFunction.def("Arguments", (void (TFunction_IFunction::*)(TDF_LabelList &) const) &TFunction_IFunction::Arguments, "The method fills-in the list by labels, where the arguments of the function are located.", py::arg("args"));
cls_TFunction_IFunction.def("Results", (void (TFunction_IFunction::*)(TDF_LabelList &) const) &TFunction_IFunction::Results, "The method fills-in the list by labels, where the results of the function are located.", py::arg("res"));
cls_TFunction_IFunction.def("GetPrevious", (void (TFunction_IFunction::*)(TDF_LabelList &) const) &TFunction_IFunction::GetPrevious, "Returns a list of previous functions.", py::arg("prev"));
cls_TFunction_IFunction.def("GetNext", (void (TFunction_IFunction::*)(TDF_LabelList &) const) &TFunction_IFunction::GetNext, "Returns a list of next functions.", py::arg("prev"));
cls_TFunction_IFunction.def("GetStatus", (TFunction_ExecutionStatus (TFunction_IFunction::*)() const) &TFunction_IFunction::GetStatus, "Returns the execution status of the function.");
cls_TFunction_IFunction.def("SetStatus", (void (TFunction_IFunction::*)(const TFunction_ExecutionStatus) const) &TFunction_IFunction::SetStatus, "Defines an execution status for a function.", py::arg("status"));
cls_TFunction_IFunction.def("GetAllFunctions", (const TFunction_DoubleMapOfIntegerLabel & (TFunction_IFunction::*)() const) &TFunction_IFunction::GetAllFunctions, "Returns the scope of all functions.");
cls_TFunction_IFunction.def("GetLogbook", (opencascade::handle<TFunction_Logbook> (TFunction_IFunction::*)() const) &TFunction_IFunction::GetLogbook, "Returns the Logbook - keeper of modifications.");
cls_TFunction_IFunction.def("GetDriver", [](TFunction_IFunction &self) -> opencascade::handle<TFunction_Driver> { return self.GetDriver(); });
cls_TFunction_IFunction.def("GetDriver", (opencascade::handle<TFunction_Driver> (TFunction_IFunction::*)(const Standard_Integer) const) &TFunction_IFunction::GetDriver, "Returns a driver of the function.", py::arg("thread"));
cls_TFunction_IFunction.def("GetGraphNode", (opencascade::handle<TFunction_GraphNode> (TFunction_IFunction::*)() const) &TFunction_IFunction::GetGraphNode, "Returns a graph node of the function.");

// Enums

}