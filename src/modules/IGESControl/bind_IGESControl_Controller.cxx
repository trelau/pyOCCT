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
#include <XSControl_Controller.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <TopoDS_Shape.hxx>
#include <Transfer_FinderProcess.hxx>
#include <XSControl_WorkSession.hxx>
#include <IGESControl_Controller.hxx>
#include <Standard_Type.hxx>

void bind_IGESControl_Controller(py::module &mod){

py::class_<IGESControl_Controller, opencascade::handle<IGESControl_Controller>, XSControl_Controller> cls_IGESControl_Controller(mod, "IGESControl_Controller", "Controller for IGES-5.1");

// Constructors
cls_IGESControl_Controller.def(py::init<>());
cls_IGESControl_Controller.def(py::init<const Standard_Boolean>(), py::arg("modefnes"));

// Fields

// Methods
cls_IGESControl_Controller.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (IGESControl_Controller::*)() const) &IGESControl_Controller::NewModel, "Creates a new empty Model ready to receive data of the Norm. It is taken from IGES Template Model");
cls_IGESControl_Controller.def("ActorRead", (opencascade::handle<Transfer_ActorOfTransientProcess> (IGESControl_Controller::*)(const opencascade::handle<Interface_InterfaceModel> &) const) &IGESControl_Controller::ActorRead, "Returns the Actor for Read attached to the pair (norm,appli) It is an Actor from IGESToBRep, adapted from an IGESModel : Unit, tolerances", py::arg("model"));
cls_IGESControl_Controller.def("TransferWriteShape", [](IGESControl_Controller &self, const TopoDS_Shape & a0, const opencascade::handle<Transfer_FinderProcess> & a1, const opencascade::handle<Interface_InterfaceModel> & a2) -> IFSelect_ReturnStatus { return self.TransferWriteShape(a0, a1, a2); });
cls_IGESControl_Controller.def("TransferWriteShape", (IFSelect_ReturnStatus (IGESControl_Controller::*)(const TopoDS_Shape &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer) const) &IGESControl_Controller::TransferWriteShape, "Takes one Shape and transfers it to the InterfaceModel (already created by NewModel for instance) <modetrans> is to be interpreted by each kind of XstepAdaptor Returns a status : 0 OK 1 No result 2 Fail -1 bad modeshape -2 bad model (requires an IGESModel) modeshape : 0 groupe of face (version < 5.1) 1 BREP-version 5.1 of IGES", py::arg("shape"), py::arg("FP"), py::arg("model"), py::arg("modetrans"));
cls_IGESControl_Controller.def_static("Init_", (Standard_Boolean (*)()) &IGESControl_Controller::Init, "Standard Initialisation. It creates a Controller for IGES and records it to various names, available to select it later Returns True when done, False if could not be done Also, it creates and records an Adaptor for FNES");
cls_IGESControl_Controller.def("Customise", (void (IGESControl_Controller::*)(opencascade::handle<XSControl_WorkSession> &)) &IGESControl_Controller::Customise, "None", py::arg("WS"));
cls_IGESControl_Controller.def_static("get_type_name_", (const char * (*)()) &IGESControl_Controller::get_type_name, "None");
cls_IGESControl_Controller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_Controller::get_type_descriptor, "None");
cls_IGESControl_Controller.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_Controller::*)() const) &IGESControl_Controller::DynamicType, "None");

// Enums

}