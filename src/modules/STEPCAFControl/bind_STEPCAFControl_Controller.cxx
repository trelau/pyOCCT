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
#include <STEPControl_Controller.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <STEPCAFControl_Controller.hxx>
#include <Standard_Type.hxx>

void bind_STEPCAFControl_Controller(py::module &mod){

py::class_<STEPCAFControl_Controller, opencascade::handle<STEPCAFControl_Controller>, STEPControl_Controller> cls_STEPCAFControl_Controller(mod, "STEPCAFControl_Controller", "Extends Controller from STEPControl in order to provide ActorWrite adapted for writing assemblies from DECAF Note that ActorRead from STEPControl is used for reading (inherited automatically)");

// Constructors
cls_STEPCAFControl_Controller.def(py::init<>());

// Fields

// Methods
cls_STEPCAFControl_Controller.def_static("Init_", (Standard_Boolean (*)()) &STEPCAFControl_Controller::Init, "Standard Initialisation. It creates a Controller for STEP-XCAF and records it to various names, available to select it later Returns True when done, False if could not be done");
cls_STEPCAFControl_Controller.def_static("get_type_name_", (const char * (*)()) &STEPCAFControl_Controller::get_type_name, "None");
cls_STEPCAFControl_Controller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPCAFControl_Controller::get_type_descriptor, "None");
cls_STEPCAFControl_Controller.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPCAFControl_Controller::*)() const) &STEPCAFControl_Controller::DynamicType, "None");

// Enums

}