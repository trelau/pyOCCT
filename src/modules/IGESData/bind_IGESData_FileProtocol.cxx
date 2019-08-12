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
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Protocol.hxx>
#include <IGESData_FileProtocol.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_FileProtocol(py::module &mod){

py::class_<IGESData_FileProtocol, opencascade::handle<IGESData_FileProtocol>, IGESData_Protocol> cls_IGESData_FileProtocol(mod, "IGESData_FileProtocol", "This class allows to define complex protocols, in order to treat various sub-sets (or the complete set) of the IGES Norm, such as Solid + Draw (which are normally independant), etc... While it inherits Protocol from IGESData, it admits UndefinedEntity too");

// Constructors
cls_IGESData_FileProtocol.def(py::init<>());

// Fields

// Methods
cls_IGESData_FileProtocol.def("Add", (void (IGESData_FileProtocol::*)(const opencascade::handle<IGESData_Protocol> &)) &IGESData_FileProtocol::Add, "Adds a resource", py::arg("protocol"));
cls_IGESData_FileProtocol.def("NbResources", (Standard_Integer (IGESData_FileProtocol::*)() const) &IGESData_FileProtocol::NbResources, "Gives the count of Resources : the count of Added Protocols");
cls_IGESData_FileProtocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESData_FileProtocol::*)(const Standard_Integer) const) &IGESData_FileProtocol::Resource, "Returns a Resource, given a rank (rank of call to Add)", py::arg("num"));
cls_IGESData_FileProtocol.def_static("get_type_name_", (const char * (*)()) &IGESData_FileProtocol::get_type_name, "None");
cls_IGESData_FileProtocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_FileProtocol::get_type_descriptor, "None");
cls_IGESData_FileProtocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_FileProtocol::*)() const) &IGESData_FileProtocol::DynamicType, "None");

// Enums

}