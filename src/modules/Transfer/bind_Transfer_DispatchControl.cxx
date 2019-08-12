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
#include <Interface_CopyControl.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_DispatchControl.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_DispatchControl(py::module &mod){

py::class_<Transfer_DispatchControl, opencascade::handle<Transfer_DispatchControl>, Interface_CopyControl> cls_Transfer_DispatchControl(mod, "Transfer_DispatchControl", "This is an auxiliary class for TransferDispatch, which allows to record simple copies, as CopyControl from Interface, but based on a TransientProcess. Hence, it allows in addition more actions (such as recording results of adaptations)");

// Constructors
cls_Transfer_DispatchControl.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("model"), py::arg("TP"));

// Fields

// Methods
cls_Transfer_DispatchControl.def("TransientProcess", (const opencascade::handle<Transfer_TransientProcess> & (Transfer_DispatchControl::*)() const) &Transfer_DispatchControl::TransientProcess, "Returns the content of the DispatchControl : it can be used for a direct call, if the basic methods do not suffice");
cls_Transfer_DispatchControl.def("StartingModel", (const opencascade::handle<Interface_InterfaceModel> & (Transfer_DispatchControl::*)() const) &Transfer_DispatchControl::StartingModel, "Returns the Model from which the transfer is to be done");
cls_Transfer_DispatchControl.def("Clear", (void (Transfer_DispatchControl::*)()) &Transfer_DispatchControl::Clear, "Clears the List of Copied Results");
cls_Transfer_DispatchControl.def("Bind", (void (Transfer_DispatchControl::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Transfer_DispatchControl::Bind, "Binds a (Transient) Result to a (Transient) Starting Entity", py::arg("ent"), py::arg("res"));
cls_Transfer_DispatchControl.def("Search", (Standard_Boolean (Transfer_DispatchControl::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Transfer_DispatchControl::Search, "Searches for the Result bound to a Starting Entity If Found, returns True and fills <res> Else, returns False and nullifies <res>", py::arg("ent"), py::arg("res"));
cls_Transfer_DispatchControl.def_static("get_type_name_", (const char * (*)()) &Transfer_DispatchControl::get_type_name, "None");
cls_Transfer_DispatchControl.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_DispatchControl::get_type_descriptor, "None");
cls_Transfer_DispatchControl.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_DispatchControl::*)() const) &Transfer_DispatchControl::DynamicType, "None");

// Enums

}