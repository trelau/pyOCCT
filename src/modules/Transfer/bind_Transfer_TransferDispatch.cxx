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
#include <Interface_CopyTool.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_Protocol.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_TransferDispatch.hxx>

void bind_Transfer_TransferDispatch(py::module &mod){

py::class_<Transfer_TransferDispatch, std::unique_ptr<Transfer_TransferDispatch>, Interface_CopyTool> cls_Transfer_TransferDispatch(mod, "Transfer_TransferDispatch", "A TransferDispatch is aimed to dispatch Entities between two Interface Models, by default by copying them, as CopyTool, but with more capabilities of adapting : Copy is redefined to firstly pass the hand to a TransferProcess. If this gives no result, standard Copy is called.");

// Constructors
cls_Transfer_TransferDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Transfer_TransferDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Transfer_TransferDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));

// Fields

// Methods
// cls_Transfer_TransferDispatch.def_static("operator new_", (void * (*)(size_t)) &Transfer_TransferDispatch::operator new, "None", py::arg("theSize"));
// cls_Transfer_TransferDispatch.def_static("operator delete_", (void (*)(void *)) &Transfer_TransferDispatch::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_TransferDispatch.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_TransferDispatch::operator new[], "None", py::arg("theSize"));
// cls_Transfer_TransferDispatch.def_static("operator delete[]_", (void (*)(void *)) &Transfer_TransferDispatch::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_TransferDispatch.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_TransferDispatch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_TransferDispatch.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_TransferDispatch::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_TransferDispatch.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (Transfer_TransferDispatch::*)() const) &Transfer_TransferDispatch::TransientProcess, "Returns the content of Control Object, as a TransientProcess");
cls_Transfer_TransferDispatch.def("Copy", (Standard_Boolean (Transfer_TransferDispatch::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &, const Standard_Boolean, const Standard_Boolean)) &Transfer_TransferDispatch::Copy, "Copies an Entity by calling the method Transferring from the TransferProcess. If this called produces a Null Binder, then the standard, inherited Copy is called", py::arg("entfrom"), py::arg("entto"), py::arg("mapped"), py::arg("errstat"));

// Enums

}