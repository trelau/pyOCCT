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
#include <Interface_GlobalNodeOfReaderLib.hxx>
#include <Interface_ReaderModule.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_NodeOfReaderLib.hxx>
#include <Standard_Type.hxx>

void bind_Interface_NodeOfReaderLib(py::module &mod){

py::class_<Interface_NodeOfReaderLib, opencascade::handle<Interface_NodeOfReaderLib>, Standard_Transient> cls_Interface_NodeOfReaderLib(mod, "Interface_NodeOfReaderLib", "None");

// Constructors
cls_Interface_NodeOfReaderLib.def(py::init<>());

// Fields

// Methods
cls_Interface_NodeOfReaderLib.def("AddNode", (void (Interface_NodeOfReaderLib::*)(const opencascade::handle<Interface_GlobalNodeOfReaderLib> &)) &Interface_NodeOfReaderLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_Interface_NodeOfReaderLib.def("Module", (const opencascade::handle<Interface_ReaderModule> & (Interface_NodeOfReaderLib::*)() const) &Interface_NodeOfReaderLib::Module, "Returns the Module designated by a precise Node");
cls_Interface_NodeOfReaderLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_NodeOfReaderLib::*)() const) &Interface_NodeOfReaderLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_Interface_NodeOfReaderLib.def("Next", (const opencascade::handle<Interface_NodeOfReaderLib> & (Interface_NodeOfReaderLib::*)() const) &Interface_NodeOfReaderLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_Interface_NodeOfReaderLib.def_static("get_type_name_", (const char * (*)()) &Interface_NodeOfReaderLib::get_type_name, "None");
cls_Interface_NodeOfReaderLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_NodeOfReaderLib::get_type_descriptor, "None");
cls_Interface_NodeOfReaderLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_NodeOfReaderLib::*)() const) &Interface_NodeOfReaderLib::DynamicType, "None");

// Enums

}