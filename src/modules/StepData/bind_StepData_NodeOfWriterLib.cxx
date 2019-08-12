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
#include <StepData_GlobalNodeOfWriterLib.hxx>
#include <StepData_ReadWriteModule.hxx>
#include <StepData_Protocol.hxx>
#include <StepData_NodeOfWriterLib.hxx>
#include <Standard_Type.hxx>

void bind_StepData_NodeOfWriterLib(py::module &mod){

py::class_<StepData_NodeOfWriterLib, opencascade::handle<StepData_NodeOfWriterLib>, Standard_Transient> cls_StepData_NodeOfWriterLib(mod, "StepData_NodeOfWriterLib", "None");

// Constructors
cls_StepData_NodeOfWriterLib.def(py::init<>());

// Fields

// Methods
cls_StepData_NodeOfWriterLib.def("AddNode", (void (StepData_NodeOfWriterLib::*)(const opencascade::handle<StepData_GlobalNodeOfWriterLib> &)) &StepData_NodeOfWriterLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_StepData_NodeOfWriterLib.def("Module", (const opencascade::handle<StepData_ReadWriteModule> & (StepData_NodeOfWriterLib::*)() const) &StepData_NodeOfWriterLib::Module, "Returns the Module designated by a precise Node");
cls_StepData_NodeOfWriterLib.def("Protocol", (const opencascade::handle<StepData_Protocol> & (StepData_NodeOfWriterLib::*)() const) &StepData_NodeOfWriterLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_StepData_NodeOfWriterLib.def("Next", (const opencascade::handle<StepData_NodeOfWriterLib> & (StepData_NodeOfWriterLib::*)() const) &StepData_NodeOfWriterLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_StepData_NodeOfWriterLib.def_static("get_type_name_", (const char * (*)()) &StepData_NodeOfWriterLib::get_type_name, "None");
cls_StepData_NodeOfWriterLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_NodeOfWriterLib::get_type_descriptor, "None");
cls_StepData_NodeOfWriterLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_NodeOfWriterLib::*)() const) &StepData_NodeOfWriterLib::DynamicType, "None");

// Enums

}