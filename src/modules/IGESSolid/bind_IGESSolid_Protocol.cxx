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
#include <IGESSolid_Protocol.hxx>

void bind_IGESSolid_Protocol(py::module &mod){

py::class_<IGESSolid_Protocol, opencascade::handle<IGESSolid_Protocol>, IGESData_Protocol> cls_IGESSolid_Protocol(mod, "IGESSolid_Protocol", "Description of Protocol for IGESSolid");

// Constructors
cls_IGESSolid_Protocol.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Protocol.def("NbResources", (Standard_Integer (IGESSolid_Protocol::*)() const) &IGESSolid_Protocol::NbResources, "Gives the count of Resource Protocol. Here, one (Protocol from IGESGeom)");
cls_IGESSolid_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESSolid_Protocol::*)(const Standard_Integer) const) &IGESSolid_Protocol::Resource, "Returns a Resource, given a rank.", py::arg("num"));
cls_IGESSolid_Protocol.def("TypeNumber", (Standard_Integer (IGESSolid_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &IGESSolid_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type This Case Number is then used in Libraries : the various Modules attached to this class of Protocol must use them in accordance (for a given value of TypeNumber, they must consider the same Type as the Protocol defines)", py::arg("atype"));
cls_IGESSolid_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Protocol::get_type_name, "None");
cls_IGESSolid_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Protocol::get_type_descriptor, "None");
cls_IGESSolid_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Protocol::*)() const) &IGESSolid_Protocol::DynamicType, "None");

// Enums

}