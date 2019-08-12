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
#include <Interface_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_Transient.hxx>
#include <IGESData_Protocol.hxx>

void bind_IGESData_Protocol(py::module &mod){

py::class_<IGESData_Protocol, opencascade::handle<IGESData_Protocol>, Interface_Protocol> cls_IGESData_Protocol(mod, "IGESData_Protocol", "Description of basic Protocol for IGES This comprises treatement of IGESModel and Recognition of Undefined-FreeFormat-Entity");

// Constructors
cls_IGESData_Protocol.def(py::init<>());

// Fields

// Methods
cls_IGESData_Protocol.def("NbResources", (Standard_Integer (IGESData_Protocol::*)() const) &IGESData_Protocol::NbResources, "Gives the count of Resource Protocol. Here, none");
cls_IGESData_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESData_Protocol::*)(const Standard_Integer) const) &IGESData_Protocol::Resource, "Returns a Resource, given a rank. Here, none", py::arg("num"));
cls_IGESData_Protocol.def("TypeNumber", (Standard_Integer (IGESData_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &IGESData_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type Here, Undefined and Free Format Entities have the Number 1.", py::arg("atype"));
cls_IGESData_Protocol.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (IGESData_Protocol::*)() const) &IGESData_Protocol::NewModel, "Creates an empty Model for IGES Norm");
cls_IGESData_Protocol.def("IsSuitableModel", (Standard_Boolean (IGESData_Protocol::*)(const opencascade::handle<Interface_InterfaceModel> &) const) &IGESData_Protocol::IsSuitableModel, "Returns True if <model> is a Model of IGES Norm", py::arg("model"));
cls_IGESData_Protocol.def("UnknownEntity", (opencascade::handle<Standard_Transient> (IGESData_Protocol::*)() const) &IGESData_Protocol::UnknownEntity, "Creates a new Unknown Entity for IGES (UndefinedEntity)");
cls_IGESData_Protocol.def("IsUnknownEntity", (Standard_Boolean (IGESData_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &IGESData_Protocol::IsUnknownEntity, "Returns True if <ent> is an Unknown Entity for the Norm, i.e. Type UndefinedEntity, status Unknown", py::arg("ent"));
cls_IGESData_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESData_Protocol::get_type_name, "None");
cls_IGESData_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_Protocol::get_type_descriptor, "None");
cls_IGESData_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_Protocol::*)() const) &IGESData_Protocol::DynamicType, "None");

// Enums

}