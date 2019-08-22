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
#include <IGESGraph_TextDisplayTemplate.hxx>
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
#include <IGESGraph_ToolTextDisplayTemplate.hxx>

void bind_IGESGraph_ToolTextDisplayTemplate(py::module &mod){

py::class_<IGESGraph_ToolTextDisplayTemplate> cls_IGESGraph_ToolTextDisplayTemplate(mod, "IGESGraph_ToolTextDisplayTemplate", "Tool to work on a TextDisplayTemplate. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESGraph_ToolTextDisplayTemplate.def(py::init<>());

// Fields

// Methods
// cls_IGESGraph_ToolTextDisplayTemplate.def_static("operator new_", (void * (*)(size_t)) &IGESGraph_ToolTextDisplayTemplate::operator new, "None", py::arg("theSize"));
// cls_IGESGraph_ToolTextDisplayTemplate.def_static("operator delete_", (void (*)(void *)) &IGESGraph_ToolTextDisplayTemplate::operator delete, "None", py::arg("theAddress"));
// cls_IGESGraph_ToolTextDisplayTemplate.def_static("operator new[]_", (void * (*)(size_t)) &IGESGraph_ToolTextDisplayTemplate::operator new[], "None", py::arg("theSize"));
// cls_IGESGraph_ToolTextDisplayTemplate.def_static("operator delete[]_", (void (*)(void *)) &IGESGraph_ToolTextDisplayTemplate::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGraph_ToolTextDisplayTemplate.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGraph_ToolTextDisplayTemplate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGraph_ToolTextDisplayTemplate.def_static("operator delete_", (void (*)(void *, void *)) &IGESGraph_ToolTextDisplayTemplate::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGraph_ToolTextDisplayTemplate.def("ReadOwnParams", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESGraph_ToolTextDisplayTemplate::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESGraph_ToolTextDisplayTemplate.def("WriteOwnParams", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, IGESData_IGESWriter &) const) &IGESGraph_ToolTextDisplayTemplate::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESGraph_ToolTextDisplayTemplate.def("OwnShared", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, Interface_EntityIterator &) const) &IGESGraph_ToolTextDisplayTemplate::OwnShared, "Lists the Entities shared by a TextDisplayTemplate <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESGraph_ToolTextDisplayTemplate.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &) const) &IGESGraph_ToolTextDisplayTemplate::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESGraph_ToolTextDisplayTemplate.def("OwnCheck", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGraph_ToolTextDisplayTemplate::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGraph_ToolTextDisplayTemplate.def("OwnCopy", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const opencascade::handle<IGESGraph_TextDisplayTemplate> &, Interface_CopyTool &) const) &IGESGraph_ToolTextDisplayTemplate::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGraph_ToolTextDisplayTemplate.def("OwnDump", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGraph_ToolTextDisplayTemplate::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}