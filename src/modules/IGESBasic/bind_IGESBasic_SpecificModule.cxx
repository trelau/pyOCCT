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
#include <IGESBasic_SpecificModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_SpecificModule(py::module &mod){

py::class_<IGESBasic_SpecificModule, opencascade::handle<IGESBasic_SpecificModule>, IGESData_SpecificModule> cls_IGESBasic_SpecificModule(mod, "IGESBasic_SpecificModule", "Defines Services attached to IGES Entities : Dump & OwnCorrect, for IGESBasic");

// Constructors
cls_IGESBasic_SpecificModule.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_SpecificModule.def("OwnDump", (void (IGESBasic_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESBasic", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESBasic_SpecificModule.def("OwnCorrect", (Standard_Boolean (IGESBasic_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESBasic_SpecificModule::OwnCorrect, "Performs non-ambiguous Corrections on Entities which support them (AssocGroupType,Hierarchy,Name,SingleParent)", py::arg("CN"), py::arg("ent"));
cls_IGESBasic_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESBasic_SpecificModule::get_type_name, "None");
cls_IGESBasic_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_SpecificModule::get_type_descriptor, "None");
cls_IGESBasic_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_SpecificModule::*)() const) &IGESBasic_SpecificModule::DynamicType, "None");

// Enums

}