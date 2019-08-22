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
#include <Interface_EntityIterator.hxx>
#include <Transfer_TransferIterator.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_FinderProcess.hxx>
#include <Transfer_TransferInput.hxx>

void bind_Transfer_TransferInput(py::module &mod){

py::class_<Transfer_TransferInput> cls_Transfer_TransferInput(mod, "Transfer_TransferInput", "A TransferInput is a Tool which fills an InterfaceModel with the result of the Transfer of CasCade Objects, once determined The Result comes from a TransferProcess, either from Transient (the Complete Result is considered, it must contain only Transient Objects)");

// Constructors
cls_Transfer_TransferInput.def(py::init<>());

// Fields

// Methods
// cls_Transfer_TransferInput.def_static("operator new_", (void * (*)(size_t)) &Transfer_TransferInput::operator new, "None", py::arg("theSize"));
// cls_Transfer_TransferInput.def_static("operator delete_", (void (*)(void *)) &Transfer_TransferInput::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_TransferInput.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_TransferInput::operator new[], "None", py::arg("theSize"));
// cls_Transfer_TransferInput.def_static("operator delete[]_", (void (*)(void *)) &Transfer_TransferInput::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_TransferInput.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_TransferInput::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_TransferInput.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_TransferInput::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_TransferInput.def("Entities", (Interface_EntityIterator (Transfer_TransferInput::*)(Transfer_TransferIterator &) const) &Transfer_TransferInput::Entities, "Takes the transient items stored in a TransferIterator", py::arg("list"));
cls_Transfer_TransferInput.def("FillModel", (void (Transfer_TransferInput::*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Interface_InterfaceModel> &) const) &Transfer_TransferInput::FillModel, "Fills an InterfaceModel with the Complete Result of a Transfer stored in a TransientProcess (Starting Objects are Transient) The complete result is exactly added to the model", py::arg("proc"), py::arg("amodel"));
cls_Transfer_TransferInput.def("FillModel", [](Transfer_TransferInput &self, const opencascade::handle<Transfer_TransientProcess> & a0, const opencascade::handle<Interface_InterfaceModel> & a1, const opencascade::handle<Interface_Protocol> & a2) -> void { return self.FillModel(a0, a1, a2); });
cls_Transfer_TransferInput.def("FillModel", (void (Transfer_TransferInput::*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const Standard_Boolean) const) &Transfer_TransferInput::FillModel, "Fills an InterfaceModel with results of the Transfer recorded in a TransientProcess (Starting Objects are Transient) : Root Result if <roots> is True (Default), Complete Result else The entities added to the model are determined from the result by by adding the referenced entities", py::arg("proc"), py::arg("amodel"), py::arg("proto"), py::arg("roots"));
cls_Transfer_TransferInput.def("FillModel", (void (Transfer_TransferInput::*)(const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &) const) &Transfer_TransferInput::FillModel, "Fills an InterfaceModel with the Complete Result of a Transfer stored in a TransientProcess (Starting Objects are Transient) The complete result is exactly added to the model", py::arg("proc"), py::arg("amodel"));
cls_Transfer_TransferInput.def("FillModel", [](Transfer_TransferInput &self, const opencascade::handle<Transfer_FinderProcess> & a0, const opencascade::handle<Interface_InterfaceModel> & a1, const opencascade::handle<Interface_Protocol> & a2) -> void { return self.FillModel(a0, a1, a2); });
cls_Transfer_TransferInput.def("FillModel", (void (Transfer_TransferInput::*)(const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const Standard_Boolean) const) &Transfer_TransferInput::FillModel, "Fills an InterfaceModel with results of the Transfer recorded in a TransientProcess (Starting Objects are Transient) : Root Result if <roots> is True (Default), Complete Result else The entities added to the model are determined from the result by by adding the referenced entities", py::arg("proc"), py::arg("amodel"), py::arg("proto"), py::arg("roots"));

// Enums

}