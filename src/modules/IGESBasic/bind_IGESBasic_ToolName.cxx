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
#include <IGESBasic_Name.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESBasic_ToolName.hxx>

void bind_IGESBasic_ToolName(py::module &mod){

py::class_<IGESBasic_ToolName, std::unique_ptr<IGESBasic_ToolName, Deleter<IGESBasic_ToolName>>> cls_IGESBasic_ToolName(mod, "IGESBasic_ToolName", "Tool to work on a Name. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolName.def(py::init<>());

// Fields

// Methods
// cls_IGESBasic_ToolName.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolName::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolName.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolName::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolName.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolName::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolName.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolName::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolName.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolName::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolName.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolName::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolName.def("ReadOwnParams", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolName::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolName.def("WriteOwnParams", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, IGESData_IGESWriter &) const) &IGESBasic_ToolName::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolName.def("OwnShared", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, Interface_EntityIterator &) const) &IGESBasic_ToolName::OwnShared, "Lists the Entities shared by a Name <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolName.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &) const) &IGESBasic_ToolName::OwnCorrect, "Sets automatic unambiguous Correction on a Name (NbPropertyValues forced to 1)", py::arg("ent"));
cls_IGESBasic_ToolName.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &) const) &IGESBasic_ToolName::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolName.def("OwnCheck", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolName::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolName.def("OwnCopy", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, const opencascade::handle<IGESBasic_Name> &, Interface_CopyTool &) const) &IGESBasic_ToolName::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolName.def("OwnDump", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolName::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}