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
#include <IGESData_ReadWriteModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <IGESDraw_ReadWriteModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_ReadWriteModule(py::module &mod){

py::class_<IGESDraw_ReadWriteModule, opencascade::handle<IGESDraw_ReadWriteModule>, IGESData_ReadWriteModule> cls_IGESDraw_ReadWriteModule(mod, "IGESDraw_ReadWriteModule", "Defines Draw File Access Module for IGESDraw (specific parts) Specific actions concern : Read and Write Own Parameters of an IGESEntity.");

// Constructors
cls_IGESDraw_ReadWriteModule.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_ReadWriteModule.def("CaseIGES", (Standard_Integer (IGESDraw_ReadWriteModule::*)(const Standard_Integer, const Standard_Integer) const) &IGESDraw_ReadWriteModule::CaseIGES, "Defines Case Numbers for Entities of IGESDraw", py::arg("typenum"), py::arg("formnum"));
cls_IGESDraw_ReadWriteModule.def("ReadOwnParams", (void (IGESDraw_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDraw_ReadWriteModule::ReadOwnParams, "Reads own parameters from file for an Entity of IGESDraw", py::arg("CN"), py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDraw_ReadWriteModule.def("WriteOwnParams", (void (IGESDraw_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, IGESData_IGESWriter &) const) &IGESDraw_ReadWriteModule::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("CN"), py::arg("ent"), py::arg("IW"));
cls_IGESDraw_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &IGESDraw_ReadWriteModule::get_type_name, "None");
cls_IGESDraw_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_ReadWriteModule::get_type_descriptor, "None");
cls_IGESDraw_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_ReadWriteModule::*)() const) &IGESDraw_ReadWriteModule::DynamicType, "None");

// Enums

}