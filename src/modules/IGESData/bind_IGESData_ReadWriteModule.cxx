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
#include <Interface_ReaderModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_FileReaderData.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_ReadWriteModule(py::module &mod){

py::class_<IGESData_ReadWriteModule, opencascade::handle<IGESData_ReadWriteModule>, Interface_ReaderModule> cls_IGESData_ReadWriteModule(mod, "IGESData_ReadWriteModule", "Defines basic File Access Module, under the control of IGESReaderTool for Reading and IGESWriter for Writing : Specific actions concern : Read and Write Own Parameters of an IGESEntity. The common parts (Directory Entry, Lists of Associativities and Properties) are processed by IGESReaderTool & IGESWriter");

// Fields

// Methods
cls_IGESData_ReadWriteModule.def("CaseNum", (Standard_Integer (IGESData_ReadWriteModule::*)(const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer) const) &IGESData_ReadWriteModule::CaseNum, "Translates the Type of record <num> in <data> to a positive Case Number, or 0 if failed. Works with IGESReaderData which provides Type & Form Numbers, and calls CaseIGES (see below)", py::arg("data"), py::arg("num"));
cls_IGESData_ReadWriteModule.def("CaseIGES", (Standard_Integer (IGESData_ReadWriteModule::*)(const Standard_Integer, const Standard_Integer) const) &IGESData_ReadWriteModule::CaseIGES, "Defines Case Numbers corresponding to the Entity Types taken into account by a sub-class of ReadWriteModule (hence, each sub-class of ReadWriteModule has to redefine this method) Called by CaseNum. Its result will then be used to call Read, etc ...", py::arg("typenum"), py::arg("formnum"));
cls_IGESData_ReadWriteModule.def("Read", (void (IGESData_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &IGESData_ReadWriteModule::Read, "General Read Function. See IGESReaderTool for more info", py::arg("CN"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_IGESData_ReadWriteModule.def("ReadOwnParams", (void (IGESData_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESData_ReadWriteModule::ReadOwnParams, "Reads own parameters from file for an Entity; <PR> gives access to them, <IR> detains parameter types and values For each class, there must be a specific action provided Note that Properties and Associativities Lists are Read by specific methods (see below), they are called under control of reading process (only one call) according Stage recorded in ParamReader", py::arg("CN"), py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESData_ReadWriteModule.def("WriteOwnParams", (void (IGESData_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, IGESData_IGESWriter &) const) &IGESData_ReadWriteModule::WriteOwnParams, "Writes own parameters to IGESWriter; defined for each class (to be redefined for other IGES ReadWriteModules) Warning : Properties and Associativities are directly managed by WriteIGES, must not be sent by this method", py::arg("CN"), py::arg("ent"), py::arg("IW"));
cls_IGESData_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &IGESData_ReadWriteModule::get_type_name, "None");
cls_IGESData_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_ReadWriteModule::get_type_descriptor, "None");
cls_IGESData_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_ReadWriteModule::*)() const) &IGESData_ReadWriteModule::DynamicType, "None");

// Enums

}