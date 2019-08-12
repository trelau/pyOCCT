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
#include <Interface_GeneralModule.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_GlobalNodeOfGeneralLib.hxx>
#include <Standard_Type.hxx>

void bind_Interface_GlobalNodeOfGeneralLib(py::module &mod){

py::class_<Interface_GlobalNodeOfGeneralLib, opencascade::handle<Interface_GlobalNodeOfGeneralLib>, Standard_Transient> cls_Interface_GlobalNodeOfGeneralLib(mod, "Interface_GlobalNodeOfGeneralLib", "None");

// Constructors
cls_Interface_GlobalNodeOfGeneralLib.def(py::init<>());

// Fields

// Methods
cls_Interface_GlobalNodeOfGeneralLib.def("Add", (void (Interface_GlobalNodeOfGeneralLib::*)(const opencascade::handle<Interface_GeneralModule> &, const opencascade::handle<Interface_Protocol> &)) &Interface_GlobalNodeOfGeneralLib::Add, "Adds a Module bound with a Protocol to the list : does nothing if already in the list, THAT IS, Same Type (exact match) and Same State (that is, IsEqual is not required) Once added, stores its attached Protocol in correspondance", py::arg("amodule"), py::arg("aprotocol"));
cls_Interface_GlobalNodeOfGeneralLib.def("Module", (const opencascade::handle<Interface_GeneralModule> & (Interface_GlobalNodeOfGeneralLib::*)() const) &Interface_GlobalNodeOfGeneralLib::Module, "Returns the Module stored in a given GlobalNode");
cls_Interface_GlobalNodeOfGeneralLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_GlobalNodeOfGeneralLib::*)() const) &Interface_GlobalNodeOfGeneralLib::Protocol, "Returns the attached Protocol stored in a given GlobalNode");
cls_Interface_GlobalNodeOfGeneralLib.def("Next", (const opencascade::handle<Interface_GlobalNodeOfGeneralLib> & (Interface_GlobalNodeOfGeneralLib::*)() const) &Interface_GlobalNodeOfGeneralLib::Next, "Returns the Next GlobalNode. If none is defined, returned value is a Null Handle");
cls_Interface_GlobalNodeOfGeneralLib.def_static("get_type_name_", (const char * (*)()) &Interface_GlobalNodeOfGeneralLib::get_type_name, "None");
cls_Interface_GlobalNodeOfGeneralLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_GlobalNodeOfGeneralLib::get_type_descriptor, "None");
cls_Interface_GlobalNodeOfGeneralLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_GlobalNodeOfGeneralLib::*)() const) &Interface_GlobalNodeOfGeneralLib::DynamicType, "None");

// Enums

}