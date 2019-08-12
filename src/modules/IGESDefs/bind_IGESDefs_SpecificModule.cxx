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
#include <IGESData_SpecificModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESDefs_SpecificModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_SpecificModule(py::module &mod){

py::class_<IGESDefs_SpecificModule, opencascade::handle<IGESDefs_SpecificModule>, IGESData_SpecificModule> cls_IGESDefs_SpecificModule(mod, "IGESDefs_SpecificModule", "Defines Services attached to IGES Entities : Dump, for IGESDefs");

// Constructors
cls_IGESDefs_SpecificModule.def(py::init<>());

// Fields

// Methods
cls_IGESDefs_SpecificModule.def("OwnDump", (void (IGESDefs_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDefs_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESDefs", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESDefs_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESDefs_SpecificModule::get_type_name, "None");
cls_IGESDefs_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_SpecificModule::get_type_descriptor, "None");
cls_IGESDefs_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_SpecificModule::*)() const) &IGESDefs_SpecificModule::DynamicType, "None");

// Enums

}