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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESData_SpecificModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_SpecificModule(py::module &mod){

py::class_<IGESData_SpecificModule, opencascade::handle<IGESData_SpecificModule>, Standard_Transient> cls_IGESData_SpecificModule(mod, "IGESData_SpecificModule", "This class defines some Services which are specifically attached to IGES Entities : Dump");

// Fields

// Methods
cls_IGESData_SpecificModule.def("OwnDump", (void (IGESData_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESData_SpecificModule::OwnDump, "Specific Dump for each type of IGES Entity : it concerns only own parameters, the general data (Directory Part, Lists) are taken into account by the IGESDumper See class IGESDumper for the rules to follow for <own> and <attached> level", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESData_SpecificModule.def("OwnCorrect", (Standard_Boolean (IGESData_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_SpecificModule::OwnCorrect, "Specific Automatic Correction on own Parameters of an Entity. It works by setting in accordance redundant data, if there are when there is no ambiguity (else, it does nothing). Remark that classic Corrections on Directory Entry (to set void data) are taken into account alsewhere.", py::arg("CN"), py::arg("ent"));
cls_IGESData_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESData_SpecificModule::get_type_name, "None");
cls_IGESData_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_SpecificModule::get_type_descriptor, "None");
cls_IGESData_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_SpecificModule::*)() const) &IGESData_SpecificModule::DynamicType, "None");

// Enums

}