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
#include <IGESData_GlobalNodeOfSpecificLib.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESData_Protocol.hxx>
#include <IGESData_NodeOfSpecificLib.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_NodeOfSpecificLib(py::module &mod){

py::class_<IGESData_NodeOfSpecificLib, opencascade::handle<IGESData_NodeOfSpecificLib>, Standard_Transient> cls_IGESData_NodeOfSpecificLib(mod, "IGESData_NodeOfSpecificLib", "None");

// Constructors
cls_IGESData_NodeOfSpecificLib.def(py::init<>());

// Fields

// Methods
cls_IGESData_NodeOfSpecificLib.def("AddNode", (void (IGESData_NodeOfSpecificLib::*)(const opencascade::handle<IGESData_GlobalNodeOfSpecificLib> &)) &IGESData_NodeOfSpecificLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_IGESData_NodeOfSpecificLib.def("Module", (const opencascade::handle<IGESData_SpecificModule> & (IGESData_NodeOfSpecificLib::*)() const) &IGESData_NodeOfSpecificLib::Module, "Returns the Module designated by a precise Node");
cls_IGESData_NodeOfSpecificLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_NodeOfSpecificLib::*)() const) &IGESData_NodeOfSpecificLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_IGESData_NodeOfSpecificLib.def("Next", (const opencascade::handle<IGESData_NodeOfSpecificLib> & (IGESData_NodeOfSpecificLib::*)() const) &IGESData_NodeOfSpecificLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_IGESData_NodeOfSpecificLib.def_static("get_type_name_", (const char * (*)()) &IGESData_NodeOfSpecificLib::get_type_name, "None");
cls_IGESData_NodeOfSpecificLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_NodeOfSpecificLib::get_type_descriptor, "None");
cls_IGESData_NodeOfSpecificLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_NodeOfSpecificLib::*)() const) &IGESData_NodeOfSpecificLib::DynamicType, "None");

// Enums

}