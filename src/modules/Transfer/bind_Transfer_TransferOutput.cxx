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
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_Transient.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_Graph.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_TransferOutput.hxx>

void bind_Transfer_TransferOutput(py::module &mod){

py::class_<Transfer_TransferOutput> cls_Transfer_TransferOutput(mod, "Transfer_TransferOutput", "A TransferOutput is a Tool which manages the transfer of entities created by an Interface, stored in an InterfaceModel, into a set of Objects suitable for an Application Objects to be transferred are given, by method Transfer (which calls Transfer from TransientProcess) A default action is available to get all roots of the Model Result is given as a TransferIterator (see TransferProcess) Also, it is possible to pilot directly the TransientProcess");

// Constructors
cls_Transfer_TransferOutput.def(py::init<const opencascade::handle<Transfer_ActorOfTransientProcess> &, const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("actor"), py::arg("amodel"));
cls_Transfer_TransferOutput.def(py::init<const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("proc"), py::arg("amodel"));

// Fields

// Methods
// cls_Transfer_TransferOutput.def_static("operator new_", (void * (*)(size_t)) &Transfer_TransferOutput::operator new, "None", py::arg("theSize"));
// cls_Transfer_TransferOutput.def_static("operator delete_", (void (*)(void *)) &Transfer_TransferOutput::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_TransferOutput.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_TransferOutput::operator new[], "None", py::arg("theSize"));
// cls_Transfer_TransferOutput.def_static("operator delete[]_", (void (*)(void *)) &Transfer_TransferOutput::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_TransferOutput.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_TransferOutput::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_TransferOutput.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_TransferOutput::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_TransferOutput.def("Model", (opencascade::handle<Interface_InterfaceModel> (Transfer_TransferOutput::*)() const) &Transfer_TransferOutput::Model, "Returns the Starting Model");
cls_Transfer_TransferOutput.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (Transfer_TransferOutput::*)() const) &Transfer_TransferOutput::TransientProcess, "Returns the TransientProcess used to work");
cls_Transfer_TransferOutput.def("Transfer", (void (Transfer_TransferOutput::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_TransferOutput::Transfer, "Transfer checks that all taken Entities come from the same Model, then calls Transfer from TransientProcess", py::arg("obj"));
cls_Transfer_TransferOutput.def("TransferRoots", (void (Transfer_TransferOutput::*)(const opencascade::handle<Interface_Protocol> &)) &Transfer_TransferOutput::TransferRoots, "Runs transfer on the roots of the Interface Model The Roots are computed with a ShareFlags created from a Protocol given as Argument", py::arg("protocol"));
cls_Transfer_TransferOutput.def("TransferRoots", (void (Transfer_TransferOutput::*)(const Interface_Graph &)) &Transfer_TransferOutput::TransferRoots, "Runs transfer on the roots defined by a Graph of dependences (which detains also a Model and its Entities) Roots are computed with a ShareFlags created from the Graph", py::arg("G"));
cls_Transfer_TransferOutput.def("TransferRoots", (void (Transfer_TransferOutput::*)()) &Transfer_TransferOutput::TransferRoots, "Runs transfer on the roots of the Interface Model Remark : the Roots are computed with a ShareFlags created from the Active Protocol");
cls_Transfer_TransferOutput.def("ListForStatus", [](Transfer_TransferOutput &self, const Standard_Boolean a0) -> Interface_EntityIterator { return self.ListForStatus(a0); });
cls_Transfer_TransferOutput.def("ListForStatus", (Interface_EntityIterator (Transfer_TransferOutput::*)(const Standard_Boolean, const Standard_Boolean) const) &Transfer_TransferOutput::ListForStatus, "Returns the list of Starting Entities with these criteria : - <normal> False, gives the entities bound with ABNORMAL STATUS (e.g. : Fail recorded, Exception raised during Transfer) - <normal> True, gives Entities with or without a Result, but with no Fail, no Exception (Warnings are not counted) - <roots> False, considers all entities recorded (either for Result, or for at least one Fail or Warning message) - <roots> True (Default), considers only roots of Transfer (the Entities recorded at highest level) This method is based on AbnormalResult from TransferProcess", py::arg("normal"), py::arg("roots"));
cls_Transfer_TransferOutput.def("ModelForStatus", [](Transfer_TransferOutput &self, const opencascade::handle<Interface_Protocol> & a0, const Standard_Boolean a1) -> opencascade::handle<Interface_InterfaceModel> { return self.ModelForStatus(a0, a1); });
cls_Transfer_TransferOutput.def("ModelForStatus", (opencascade::handle<Interface_InterfaceModel> (Transfer_TransferOutput::*)(const opencascade::handle<Interface_Protocol> &, const Standard_Boolean, const Standard_Boolean) const) &Transfer_TransferOutput::ModelForStatus, "Fills a Model with the list determined by ListForStatus This model starts from scratch (made by NewEmptyModel from the current Model), then is filled by AddWithRefs", py::arg("protocol"), py::arg("normal"), py::arg("roots"));

// Enums

}