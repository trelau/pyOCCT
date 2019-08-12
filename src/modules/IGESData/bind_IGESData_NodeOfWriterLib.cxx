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
#include <IGESData_GlobalNodeOfWriterLib.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESData_Protocol.hxx>
#include <IGESData_NodeOfWriterLib.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_NodeOfWriterLib(py::module &mod){

py::class_<IGESData_NodeOfWriterLib, opencascade::handle<IGESData_NodeOfWriterLib>, Standard_Transient> cls_IGESData_NodeOfWriterLib(mod, "IGESData_NodeOfWriterLib", "None");

// Constructors
cls_IGESData_NodeOfWriterLib.def(py::init<>());

// Fields

// Methods
cls_IGESData_NodeOfWriterLib.def("AddNode", (void (IGESData_NodeOfWriterLib::*)(const opencascade::handle<IGESData_GlobalNodeOfWriterLib> &)) &IGESData_NodeOfWriterLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_IGESData_NodeOfWriterLib.def("Module", (const opencascade::handle<IGESData_ReadWriteModule> & (IGESData_NodeOfWriterLib::*)() const) &IGESData_NodeOfWriterLib::Module, "Returns the Module designated by a precise Node");
cls_IGESData_NodeOfWriterLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_NodeOfWriterLib::*)() const) &IGESData_NodeOfWriterLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_IGESData_NodeOfWriterLib.def("Next", (const opencascade::handle<IGESData_NodeOfWriterLib> & (IGESData_NodeOfWriterLib::*)() const) &IGESData_NodeOfWriterLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_IGESData_NodeOfWriterLib.def_static("get_type_name_", (const char * (*)()) &IGESData_NodeOfWriterLib::get_type_name, "None");
cls_IGESData_NodeOfWriterLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_NodeOfWriterLib::get_type_descriptor, "None");
cls_IGESData_NodeOfWriterLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_NodeOfWriterLib::*)() const) &IGESData_NodeOfWriterLib::DynamicType, "None");

// Enums

}