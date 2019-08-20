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
#include <IGESGraph_Pick.hxx>
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
#include <IGESGraph_ToolPick.hxx>

void bind_IGESGraph_ToolPick(py::module &mod){

py::class_<IGESGraph_ToolPick, std::unique_ptr<IGESGraph_ToolPick>> cls_IGESGraph_ToolPick(mod, "IGESGraph_ToolPick", "Tool to work on a Pick. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESGraph_ToolPick.def(py::init<>());

// Fields

// Methods
// cls_IGESGraph_ToolPick.def_static("operator new_", (void * (*)(size_t)) &IGESGraph_ToolPick::operator new, "None", py::arg("theSize"));
// cls_IGESGraph_ToolPick.def_static("operator delete_", (void (*)(void *)) &IGESGraph_ToolPick::operator delete, "None", py::arg("theAddress"));
// cls_IGESGraph_ToolPick.def_static("operator new[]_", (void * (*)(size_t)) &IGESGraph_ToolPick::operator new[], "None", py::arg("theSize"));
// cls_IGESGraph_ToolPick.def_static("operator delete[]_", (void (*)(void *)) &IGESGraph_ToolPick::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGraph_ToolPick.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGraph_ToolPick::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGraph_ToolPick.def_static("operator delete_", (void (*)(void *, void *)) &IGESGraph_ToolPick::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGraph_ToolPick.def("ReadOwnParams", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESGraph_ToolPick::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESGraph_ToolPick.def("WriteOwnParams", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, IGESData_IGESWriter &) const) &IGESGraph_ToolPick::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESGraph_ToolPick.def("OwnShared", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, Interface_EntityIterator &) const) &IGESGraph_ToolPick::OwnShared, "Lists the Entities shared by a Pick <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESGraph_ToolPick.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &) const) &IGESGraph_ToolPick::OwnCorrect, "Sets automatic unambiguous Correction on a Pick (NbPropertyValues forced to 1)", py::arg("ent"));
cls_IGESGraph_ToolPick.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &) const) &IGESGraph_ToolPick::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESGraph_ToolPick.def("OwnCheck", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGraph_ToolPick::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGraph_ToolPick.def("OwnCopy", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, const opencascade::handle<IGESGraph_Pick> &, Interface_CopyTool &) const) &IGESGraph_ToolPick::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGraph_ToolPick.def("OwnDump", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGraph_ToolPick::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}