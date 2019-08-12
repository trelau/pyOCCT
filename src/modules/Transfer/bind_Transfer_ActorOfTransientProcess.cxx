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
#include <Transfer_ActorOfProcessForTransient.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_Binder.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_ProcessForTransient.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_ActorOfTransientProcess(py::module &mod){

py::class_<Transfer_ActorOfTransientProcess, opencascade::handle<Transfer_ActorOfTransientProcess>, Transfer_ActorOfProcessForTransient> cls_Transfer_ActorOfTransientProcess(mod, "Transfer_ActorOfTransientProcess", "The original class was renamed. Compatibility only");

// Constructors
cls_Transfer_ActorOfTransientProcess.def(py::init<>());

// Fields

// Methods
cls_Transfer_ActorOfTransientProcess.def("Transferring", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfTransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_ProcessForTransient> &)) &Transfer_ActorOfTransientProcess::Transferring, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfTransientProcess.def("Transfer", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfTransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &Transfer_ActorOfTransientProcess::Transfer, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfTransientProcess.def("TransferTransient", (opencascade::handle<Standard_Transient> (Transfer_ActorOfTransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &Transfer_ActorOfTransientProcess::TransferTransient, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfTransientProcess.def_static("get_type_name_", (const char * (*)()) &Transfer_ActorOfTransientProcess::get_type_name, "None");
cls_Transfer_ActorOfTransientProcess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ActorOfTransientProcess::get_type_descriptor, "None");
cls_Transfer_ActorOfTransientProcess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ActorOfTransientProcess::*)() const) &Transfer_ActorOfTransientProcess::DynamicType, "None");

// Enums

}