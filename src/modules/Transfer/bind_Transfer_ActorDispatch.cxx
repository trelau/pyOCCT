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
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_Protocol.hxx>
#include <Transfer_TransferDispatch.hxx>
#include <Transfer_Binder.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Transfer_ActorDispatch.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_ActorDispatch(py::module &mod){

py::class_<Transfer_ActorDispatch, opencascade::handle<Transfer_ActorDispatch>, Transfer_ActorOfTransientProcess> cls_Transfer_ActorDispatch(mod, "Transfer_ActorDispatch", "This class allows to work with a TransferDispatch, i.e. to transfer entities from a data set to another one defined by the same interface norm, with the following features : - ActorDispatch itself acts as a default actor, i.e. it copies entities with the general service Copy, as CopyTool does - it allows to add other actors for specific ways of transfer, which may include data modifications, conversions ... - and other features from TransferDispatch (such as mapping other than one-one)");

// Constructors
cls_Transfer_ActorDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Transfer_ActorDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Transfer_ActorDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));

// Fields

// Methods
cls_Transfer_ActorDispatch.def("AddActor", (void (Transfer_ActorDispatch::*)(const opencascade::handle<Transfer_ActorOfTransientProcess> &)) &Transfer_ActorDispatch::AddActor, "Utility which adds an actor to the default <me> (it calls SetActor from the TransientProcess)", py::arg("actor"));
cls_Transfer_ActorDispatch.def("TransferDispatch", (Transfer_TransferDispatch & (Transfer_ActorDispatch::*)()) &Transfer_ActorDispatch::TransferDispatch, "Returns the TransferDispatch, which does the work, records the intermediate data, etc... See TransferDispatch & CopyTool, to see the available methods");
cls_Transfer_ActorDispatch.def("Transfer", (opencascade::handle<Transfer_Binder> (Transfer_ActorDispatch::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &Transfer_ActorDispatch::Transfer, "Specific action : it calls the method Transfer from CopyTool i.e. the general service Copy, then returns the Binder produced by the TransientProcess", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorDispatch.def_static("get_type_name_", (const char * (*)()) &Transfer_ActorDispatch::get_type_name, "None");
cls_Transfer_ActorDispatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ActorDispatch::get_type_descriptor, "None");
cls_Transfer_ActorDispatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ActorDispatch::*)() const) &Transfer_ActorDispatch::DynamicType, "None");

// Enums

}