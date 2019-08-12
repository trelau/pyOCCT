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
#include <Transfer_ActorOfProcessForFinder.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_Binder.hxx>
#include <Transfer_Finder.hxx>
#include <Transfer_ProcessForFinder.hxx>
#include <Transfer_FinderProcess.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_ActorOfFinderProcess.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_ActorOfFinderProcess(py::module &mod){

py::class_<Transfer_ActorOfFinderProcess, opencascade::handle<Transfer_ActorOfFinderProcess>, Transfer_ActorOfProcessForFinder> cls_Transfer_ActorOfFinderProcess(mod, "Transfer_ActorOfFinderProcess", "The original class was renamed. Compatibility only");

// Constructors
cls_Transfer_ActorOfFinderProcess.def(py::init<>());

// Fields

// Methods
cls_Transfer_ActorOfFinderProcess.def("ModeTrans", (Standard_Integer & (Transfer_ActorOfFinderProcess::*)()) &Transfer_ActorOfFinderProcess::ModeTrans, "Returns the Transfer Mode, modifiable");
cls_Transfer_ActorOfFinderProcess.def("Transferring", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfFinderProcess::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_ProcessForFinder> &)) &Transfer_ActorOfFinderProcess::Transferring, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfFinderProcess.def("Transfer", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfFinderProcess::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_FinderProcess> &)) &Transfer_ActorOfFinderProcess::Transfer, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfFinderProcess.def("TransferTransient", (opencascade::handle<Standard_Transient> (Transfer_ActorOfFinderProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_FinderProcess> &)) &Transfer_ActorOfFinderProcess::TransferTransient, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfFinderProcess.def_static("get_type_name_", (const char * (*)()) &Transfer_ActorOfFinderProcess::get_type_name, "None");
cls_Transfer_ActorOfFinderProcess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ActorOfFinderProcess::get_type_descriptor, "None");
cls_Transfer_ActorOfFinderProcess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ActorOfFinderProcess::*)() const) &Transfer_ActorOfFinderProcess::DynamicType, "None");

// Enums

}