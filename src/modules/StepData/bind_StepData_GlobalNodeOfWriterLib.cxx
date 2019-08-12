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
#include <StepData_ReadWriteModule.hxx>
#include <StepData_Protocol.hxx>
#include <StepData_GlobalNodeOfWriterLib.hxx>
#include <Standard_Type.hxx>

void bind_StepData_GlobalNodeOfWriterLib(py::module &mod){

py::class_<StepData_GlobalNodeOfWriterLib, opencascade::handle<StepData_GlobalNodeOfWriterLib>, Standard_Transient> cls_StepData_GlobalNodeOfWriterLib(mod, "StepData_GlobalNodeOfWriterLib", "None");

// Constructors
cls_StepData_GlobalNodeOfWriterLib.def(py::init<>());

// Fields

// Methods
cls_StepData_GlobalNodeOfWriterLib.def("Add", (void (StepData_GlobalNodeOfWriterLib::*)(const opencascade::handle<StepData_ReadWriteModule> &, const opencascade::handle<StepData_Protocol> &)) &StepData_GlobalNodeOfWriterLib::Add, "Adds a Module bound with a Protocol to the list : does nothing if already in the list, THAT IS, Same Type (exact match) and Same State (that is, IsEqual is not required) Once added, stores its attached Protocol in correspondance", py::arg("amodule"), py::arg("aprotocol"));
cls_StepData_GlobalNodeOfWriterLib.def("Module", (const opencascade::handle<StepData_ReadWriteModule> & (StepData_GlobalNodeOfWriterLib::*)() const) &StepData_GlobalNodeOfWriterLib::Module, "Returns the Module stored in a given GlobalNode");
cls_StepData_GlobalNodeOfWriterLib.def("Protocol", (const opencascade::handle<StepData_Protocol> & (StepData_GlobalNodeOfWriterLib::*)() const) &StepData_GlobalNodeOfWriterLib::Protocol, "Returns the attached Protocol stored in a given GlobalNode");
cls_StepData_GlobalNodeOfWriterLib.def("Next", (const opencascade::handle<StepData_GlobalNodeOfWriterLib> & (StepData_GlobalNodeOfWriterLib::*)() const) &StepData_GlobalNodeOfWriterLib::Next, "Returns the Next GlobalNode. If none is defined, returned value is a Null Handle");
cls_StepData_GlobalNodeOfWriterLib.def_static("get_type_name_", (const char * (*)()) &StepData_GlobalNodeOfWriterLib::get_type_name, "None");
cls_StepData_GlobalNodeOfWriterLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_GlobalNodeOfWriterLib::get_type_descriptor, "None");
cls_StepData_GlobalNodeOfWriterLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_GlobalNodeOfWriterLib::*)() const) &StepData_GlobalNodeOfWriterLib::DynamicType, "None");

// Enums

}