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
#include <Interface_GlobalNodeOfGeneralLib.hxx>
#include <Interface_GeneralModule.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_NodeOfGeneralLib.hxx>
#include <Standard_Type.hxx>

void bind_Interface_NodeOfGeneralLib(py::module &mod){

py::class_<Interface_NodeOfGeneralLib, opencascade::handle<Interface_NodeOfGeneralLib>, Standard_Transient> cls_Interface_NodeOfGeneralLib(mod, "Interface_NodeOfGeneralLib", "None");

// Constructors
cls_Interface_NodeOfGeneralLib.def(py::init<>());

// Fields

// Methods
cls_Interface_NodeOfGeneralLib.def("AddNode", (void (Interface_NodeOfGeneralLib::*)(const opencascade::handle<Interface_GlobalNodeOfGeneralLib> &)) &Interface_NodeOfGeneralLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_Interface_NodeOfGeneralLib.def("Module", (const opencascade::handle<Interface_GeneralModule> & (Interface_NodeOfGeneralLib::*)() const) &Interface_NodeOfGeneralLib::Module, "Returns the Module designated by a precise Node");
cls_Interface_NodeOfGeneralLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_NodeOfGeneralLib::*)() const) &Interface_NodeOfGeneralLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_Interface_NodeOfGeneralLib.def("Next", (const opencascade::handle<Interface_NodeOfGeneralLib> & (Interface_NodeOfGeneralLib::*)() const) &Interface_NodeOfGeneralLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_Interface_NodeOfGeneralLib.def_static("get_type_name_", (const char * (*)()) &Interface_NodeOfGeneralLib::get_type_name, "None");
cls_Interface_NodeOfGeneralLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_NodeOfGeneralLib::get_type_descriptor, "None");
cls_Interface_NodeOfGeneralLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_NodeOfGeneralLib::*)() const) &Interface_NodeOfGeneralLib::DynamicType, "None");

// Enums

}