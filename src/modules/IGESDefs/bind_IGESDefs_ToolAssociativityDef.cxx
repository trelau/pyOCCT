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
#include <IGESDefs_AssociativityDef.hxx>
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
#include <IGESDefs_ToolAssociativityDef.hxx>

void bind_IGESDefs_ToolAssociativityDef(py::module &mod){

py::class_<IGESDefs_ToolAssociativityDef, std::unique_ptr<IGESDefs_ToolAssociativityDef, Deleter<IGESDefs_ToolAssociativityDef>>> cls_IGESDefs_ToolAssociativityDef(mod, "IGESDefs_ToolAssociativityDef", "Tool to work on a AssociativityDef. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDefs_ToolAssociativityDef.def(py::init<>());

// Fields

// Methods
// cls_IGESDefs_ToolAssociativityDef.def_static("operator new_", (void * (*)(size_t)) &IGESDefs_ToolAssociativityDef::operator new, "None", py::arg("theSize"));
// cls_IGESDefs_ToolAssociativityDef.def_static("operator delete_", (void (*)(void *)) &IGESDefs_ToolAssociativityDef::operator delete, "None", py::arg("theAddress"));
// cls_IGESDefs_ToolAssociativityDef.def_static("operator new[]_", (void * (*)(size_t)) &IGESDefs_ToolAssociativityDef::operator new[], "None", py::arg("theSize"));
// cls_IGESDefs_ToolAssociativityDef.def_static("operator delete[]_", (void (*)(void *)) &IGESDefs_ToolAssociativityDef::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDefs_ToolAssociativityDef.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDefs_ToolAssociativityDef::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDefs_ToolAssociativityDef.def_static("operator delete_", (void (*)(void *, void *)) &IGESDefs_ToolAssociativityDef::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDefs_ToolAssociativityDef.def("ReadOwnParams", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDefs_ToolAssociativityDef::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDefs_ToolAssociativityDef.def("WriteOwnParams", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, IGESData_IGESWriter &) const) &IGESDefs_ToolAssociativityDef::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDefs_ToolAssociativityDef.def("OwnShared", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, Interface_EntityIterator &) const) &IGESDefs_ToolAssociativityDef::OwnShared, "Lists the Entities shared by a AssociativityDef <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDefs_ToolAssociativityDef.def("DirChecker", (IGESData_DirChecker (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &) const) &IGESDefs_ToolAssociativityDef::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDefs_ToolAssociativityDef.def("OwnCheck", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDefs_ToolAssociativityDef::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDefs_ToolAssociativityDef.def("OwnCopy", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, const opencascade::handle<IGESDefs_AssociativityDef> &, Interface_CopyTool &) const) &IGESDefs_ToolAssociativityDef::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDefs_ToolAssociativityDef.def("OwnDump", (void (IGESDefs_ToolAssociativityDef::*)(const opencascade::handle<IGESDefs_AssociativityDef> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDefs_ToolAssociativityDef::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}