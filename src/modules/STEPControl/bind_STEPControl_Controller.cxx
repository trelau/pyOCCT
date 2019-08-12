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
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <XSControl_WorkSession.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <TopoDS_Shape.hxx>
#include <Transfer_FinderProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <STEPControl_Controller.hxx>
#include <Standard_Type.hxx>

void bind_STEPControl_Controller(py::module &mod){

py::class_<STEPControl_Controller, opencascade::handle<STEPControl_Controller>, XSControl_Controller> cls_STEPControl_Controller(mod, "STEPControl_Controller", "defines basic controller for STEP processor");

// Constructors
cls_STEPControl_Controller.def(py::init<>());

// Fields

// Methods
cls_STEPControl_Controller.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (STEPControl_Controller::*)() const) &STEPControl_Controller::NewModel, "Creates a new empty Model ready to receive data of the Norm. It is taken from STEP Template Model");
cls_STEPControl_Controller.def("Customise", (void (STEPControl_Controller::*)(opencascade::handle<XSControl_WorkSession> &)) &STEPControl_Controller::Customise, "None", py::arg("WS"));
cls_STEPControl_Controller.def("TransferWriteShape", [](STEPControl_Controller &self, const TopoDS_Shape & a0, const opencascade::handle<Transfer_FinderProcess> & a1, const opencascade::handle<Interface_InterfaceModel> & a2) -> IFSelect_ReturnStatus { return self.TransferWriteShape(a0, a1, a2); });
cls_STEPControl_Controller.def("TransferWriteShape", (IFSelect_ReturnStatus (STEPControl_Controller::*)(const TopoDS_Shape &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer) const) &STEPControl_Controller::TransferWriteShape, "Takes one Shape and transfers it to the InterfaceModel (already created by NewModel for instance) <modeshape> is to be interpreted by each kind of XstepAdaptor Returns a status : 0 OK 1 No result 2 Fail -1 bad modeshape -2 bad model (requires a StepModel) modeshape : 1 Facetted BRep, 2 Shell, 3 Manifold Solid", py::arg("shape"), py::arg("FP"), py::arg("model"), py::arg("modetrans"));
cls_STEPControl_Controller.def_static("Init_", (Standard_Boolean (*)()) &STEPControl_Controller::Init, "Standard Initialisation. It creates a Controller for STEP and records it to various names, available to select it later Returns True when done, False if could not be done");
cls_STEPControl_Controller.def_static("get_type_name_", (const char * (*)()) &STEPControl_Controller::get_type_name, "None");
cls_STEPControl_Controller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPControl_Controller::get_type_descriptor, "None");
cls_STEPControl_Controller.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPControl_Controller::*)() const) &STEPControl_Controller::DynamicType, "None");

// Enums

}