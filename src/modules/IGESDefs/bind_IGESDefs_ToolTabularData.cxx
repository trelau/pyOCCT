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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESDefs_TabularData.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESDefs_ToolTabularData.hxx>

void bind_IGESDefs_ToolTabularData(py::module &mod){

py::class_<IGESDefs_ToolTabularData, std::unique_ptr<IGESDefs_ToolTabularData>> cls_IGESDefs_ToolTabularData(mod, "IGESDefs_ToolTabularData", "Tool to work on a TabularData. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDefs_ToolTabularData.def(py::init<>());

// Fields

// Methods
// cls_IGESDefs_ToolTabularData.def_static("operator new_", (void * (*)(size_t)) &IGESDefs_ToolTabularData::operator new, "None", py::arg("theSize"));
// cls_IGESDefs_ToolTabularData.def_static("operator delete_", (void (*)(void *)) &IGESDefs_ToolTabularData::operator delete, "None", py::arg("theAddress"));
// cls_IGESDefs_ToolTabularData.def_static("operator new[]_", (void * (*)(size_t)) &IGESDefs_ToolTabularData::operator new[], "None", py::arg("theSize"));
// cls_IGESDefs_ToolTabularData.def_static("operator delete[]_", (void (*)(void *)) &IGESDefs_ToolTabularData::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDefs_ToolTabularData.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDefs_ToolTabularData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDefs_ToolTabularData.def_static("operator delete_", (void (*)(void *, void *)) &IGESDefs_ToolTabularData::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDefs_ToolTabularData.def("ReadOwnParams", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDefs_ToolTabularData::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDefs_ToolTabularData.def("WriteOwnParams", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, IGESData_IGESWriter &) const) &IGESDefs_ToolTabularData::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDefs_ToolTabularData.def("OwnShared", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, Interface_EntityIterator &) const) &IGESDefs_ToolTabularData::OwnShared, "Lists the Entities shared by a TabularData <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDefs_ToolTabularData.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &) const) &IGESDefs_ToolTabularData::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDefs_ToolTabularData.def("OwnCheck", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDefs_ToolTabularData::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDefs_ToolTabularData.def("OwnCopy", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, const opencascade::handle<IGESDefs_TabularData> &, Interface_CopyTool &) const) &IGESDefs_ToolTabularData::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDefs_ToolTabularData.def("OwnDump", (void (IGESDefs_ToolTabularData::*)(const opencascade::handle<IGESDefs_TabularData> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDefs_ToolTabularData::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}