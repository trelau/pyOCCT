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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESData_Protocol.hxx>
#include <IGESData_GlobalNodeOfSpecificLib.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_GlobalNodeOfSpecificLib(py::module &mod){

py::class_<IGESData_GlobalNodeOfSpecificLib, opencascade::handle<IGESData_GlobalNodeOfSpecificLib>, Standard_Transient> cls_IGESData_GlobalNodeOfSpecificLib(mod, "IGESData_GlobalNodeOfSpecificLib", "None");

// Constructors
cls_IGESData_GlobalNodeOfSpecificLib.def(py::init<>());

// Fields

// Methods
cls_IGESData_GlobalNodeOfSpecificLib.def("Add", (void (IGESData_GlobalNodeOfSpecificLib::*)(const opencascade::handle<IGESData_SpecificModule> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_GlobalNodeOfSpecificLib::Add, "Adds a Module bound with a Protocol to the list : does nothing if already in the list, THAT IS, Same Type (exact match) and Same State (that is, IsEqual is not required) Once added, stores its attached Protocol in correspondance", py::arg("amodule"), py::arg("aprotocol"));
cls_IGESData_GlobalNodeOfSpecificLib.def("Module", (const opencascade::handle<IGESData_SpecificModule> & (IGESData_GlobalNodeOfSpecificLib::*)() const) &IGESData_GlobalNodeOfSpecificLib::Module, "Returns the Module stored in a given GlobalNode");
cls_IGESData_GlobalNodeOfSpecificLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_GlobalNodeOfSpecificLib::*)() const) &IGESData_GlobalNodeOfSpecificLib::Protocol, "Returns the attached Protocol stored in a given GlobalNode");
cls_IGESData_GlobalNodeOfSpecificLib.def("Next", (const opencascade::handle<IGESData_GlobalNodeOfSpecificLib> & (IGESData_GlobalNodeOfSpecificLib::*)() const) &IGESData_GlobalNodeOfSpecificLib::Next, "Returns the Next GlobalNode. If none is defined, returned value is a Null Handle");
cls_IGESData_GlobalNodeOfSpecificLib.def_static("get_type_name_", (const char * (*)()) &IGESData_GlobalNodeOfSpecificLib::get_type_name, "None");
cls_IGESData_GlobalNodeOfSpecificLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_GlobalNodeOfSpecificLib::get_type_descriptor, "None");
cls_IGESData_GlobalNodeOfSpecificLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_GlobalNodeOfSpecificLib::*)() const) &IGESData_GlobalNodeOfSpecificLib::DynamicType, "None");

// Enums

}