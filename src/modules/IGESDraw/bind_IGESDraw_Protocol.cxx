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
#include <IGESData_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_Type.hxx>
#include <IGESDraw_Protocol.hxx>

void bind_IGESDraw_Protocol(py::module &mod){

py::class_<IGESDraw_Protocol, opencascade::handle<IGESDraw_Protocol>, IGESData_Protocol> cls_IGESDraw_Protocol(mod, "IGESDraw_Protocol", "Description of Protocol for IGESDraw");

// Constructors
cls_IGESDraw_Protocol.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_Protocol.def("NbResources", (Standard_Integer (IGESDraw_Protocol::*)() const) &IGESDraw_Protocol::NbResources, "Gives the count of Resource Protocol. Here, one (Protocol from IGESDimen)");
cls_IGESDraw_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESDraw_Protocol::*)(const Standard_Integer) const) &IGESDraw_Protocol::Resource, "Returns a Resource, given a rank.", py::arg("num"));
cls_IGESDraw_Protocol.def("TypeNumber", (Standard_Integer (IGESDraw_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &IGESDraw_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type This Case Number is then used in Libraries : the various Modules attached to this class of Protocol must use them in accordance (for a given value of TypeNumber, they must consider the same Type as the Protocol defines)", py::arg("atype"));
cls_IGESDraw_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESDraw_Protocol::get_type_name, "None");
cls_IGESDraw_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_Protocol::get_type_descriptor, "None");
cls_IGESDraw_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_Protocol::*)() const) &IGESDraw_Protocol::DynamicType, "None");

// Enums

}