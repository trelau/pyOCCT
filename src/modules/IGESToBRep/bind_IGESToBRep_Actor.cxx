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
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_Binder.hxx>
#include <Transfer_TransientProcess.hxx>
#include <IGESToBRep_Actor.hxx>
#include <Standard_Type.hxx>

void bind_IGESToBRep_Actor(py::module &mod){

py::class_<IGESToBRep_Actor, opencascade::handle<IGESToBRep_Actor>, Transfer_ActorOfTransientProcess> cls_IGESToBRep_Actor(mod, "IGESToBRep_Actor", "This class performs the transfer of an Entity from IGESToBRep");

// Constructors
cls_IGESToBRep_Actor.def(py::init<>());

// Fields

// Methods
cls_IGESToBRep_Actor.def("SetModel", (void (IGESToBRep_Actor::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESToBRep_Actor::SetModel, "None", py::arg("model"));
cls_IGESToBRep_Actor.def("SetContinuity", [](IGESToBRep_Actor &self) -> void { return self.SetContinuity(); });
cls_IGESToBRep_Actor.def("SetContinuity", (void (IGESToBRep_Actor::*)(const Standard_Integer)) &IGESToBRep_Actor::SetContinuity, "---Purpose By default continuity = 0 if continuity = 1 : try C1 if continuity = 2 : try C2", py::arg("continuity"));
cls_IGESToBRep_Actor.def("GetContinuity", (Standard_Integer (IGESToBRep_Actor::*)() const) &IGESToBRep_Actor::GetContinuity, "Return 'thecontinuity'");
cls_IGESToBRep_Actor.def("Recognize", (Standard_Boolean (IGESToBRep_Actor::*)(const opencascade::handle<Standard_Transient> &)) &IGESToBRep_Actor::Recognize, "None", py::arg("start"));
cls_IGESToBRep_Actor.def("Transfer", (opencascade::handle<Transfer_Binder> (IGESToBRep_Actor::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &IGESToBRep_Actor::Transfer, "None", py::arg("start"), py::arg("TP"));
cls_IGESToBRep_Actor.def("UsedTolerance", (Standard_Real (IGESToBRep_Actor::*)() const) &IGESToBRep_Actor::UsedTolerance, "Returns the tolerance which was actually used, either from the file or from statics");
cls_IGESToBRep_Actor.def_static("get_type_name_", (const char * (*)()) &IGESToBRep_Actor::get_type_name, "None");
cls_IGESToBRep_Actor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESToBRep_Actor::get_type_descriptor, "None");
cls_IGESToBRep_Actor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESToBRep_Actor::*)() const) &IGESToBRep_Actor::DynamicType, "None");

// Enums

}