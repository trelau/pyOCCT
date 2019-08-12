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
#include <Interface_ReaderModule.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_GlobalNodeOfReaderLib.hxx>
#include <Standard_Type.hxx>

void bind_Interface_GlobalNodeOfReaderLib(py::module &mod){

py::class_<Interface_GlobalNodeOfReaderLib, opencascade::handle<Interface_GlobalNodeOfReaderLib>, Standard_Transient> cls_Interface_GlobalNodeOfReaderLib(mod, "Interface_GlobalNodeOfReaderLib", "None");

// Constructors
cls_Interface_GlobalNodeOfReaderLib.def(py::init<>());

// Fields

// Methods
cls_Interface_GlobalNodeOfReaderLib.def("Add", (void (Interface_GlobalNodeOfReaderLib::*)(const opencascade::handle<Interface_ReaderModule> &, const opencascade::handle<Interface_Protocol> &)) &Interface_GlobalNodeOfReaderLib::Add, "Adds a Module bound with a Protocol to the list : does nothing if already in the list, THAT IS, Same Type (exact match) and Same State (that is, IsEqual is not required) Once added, stores its attached Protocol in correspondance", py::arg("amodule"), py::arg("aprotocol"));
cls_Interface_GlobalNodeOfReaderLib.def("Module", (const opencascade::handle<Interface_ReaderModule> & (Interface_GlobalNodeOfReaderLib::*)() const) &Interface_GlobalNodeOfReaderLib::Module, "Returns the Module stored in a given GlobalNode");
cls_Interface_GlobalNodeOfReaderLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_GlobalNodeOfReaderLib::*)() const) &Interface_GlobalNodeOfReaderLib::Protocol, "Returns the attached Protocol stored in a given GlobalNode");
cls_Interface_GlobalNodeOfReaderLib.def("Next", (const opencascade::handle<Interface_GlobalNodeOfReaderLib> & (Interface_GlobalNodeOfReaderLib::*)() const) &Interface_GlobalNodeOfReaderLib::Next, "Returns the Next GlobalNode. If none is defined, returned value is a Null Handle");
cls_Interface_GlobalNodeOfReaderLib.def_static("get_type_name_", (const char * (*)()) &Interface_GlobalNodeOfReaderLib::get_type_name, "None");
cls_Interface_GlobalNodeOfReaderLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_GlobalNodeOfReaderLib::get_type_descriptor, "None");
cls_Interface_GlobalNodeOfReaderLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_GlobalNodeOfReaderLib::*)() const) &Interface_GlobalNodeOfReaderLib::DynamicType, "None");

// Enums

}