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
#include <IGESGraph_LineFontPredefined.hxx>
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
#include <IGESGraph_ToolLineFontPredefined.hxx>

void bind_IGESGraph_ToolLineFontPredefined(py::module &mod){

py::class_<IGESGraph_ToolLineFontPredefined, std::unique_ptr<IGESGraph_ToolLineFontPredefined>> cls_IGESGraph_ToolLineFontPredefined(mod, "IGESGraph_ToolLineFontPredefined", "Tool to work on a LineFontPredefined. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESGraph_ToolLineFontPredefined.def(py::init<>());

// Fields

// Methods
// cls_IGESGraph_ToolLineFontPredefined.def_static("operator new_", (void * (*)(size_t)) &IGESGraph_ToolLineFontPredefined::operator new, "None", py::arg("theSize"));
// cls_IGESGraph_ToolLineFontPredefined.def_static("operator delete_", (void (*)(void *)) &IGESGraph_ToolLineFontPredefined::operator delete, "None", py::arg("theAddress"));
// cls_IGESGraph_ToolLineFontPredefined.def_static("operator new[]_", (void * (*)(size_t)) &IGESGraph_ToolLineFontPredefined::operator new[], "None", py::arg("theSize"));
// cls_IGESGraph_ToolLineFontPredefined.def_static("operator delete[]_", (void (*)(void *)) &IGESGraph_ToolLineFontPredefined::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGraph_ToolLineFontPredefined.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGraph_ToolLineFontPredefined::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGraph_ToolLineFontPredefined.def_static("operator delete_", (void (*)(void *, void *)) &IGESGraph_ToolLineFontPredefined::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGraph_ToolLineFontPredefined.def("ReadOwnParams", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESGraph_ToolLineFontPredefined::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESGraph_ToolLineFontPredefined.def("WriteOwnParams", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, IGESData_IGESWriter &) const) &IGESGraph_ToolLineFontPredefined::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESGraph_ToolLineFontPredefined.def("OwnShared", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, Interface_EntityIterator &) const) &IGESGraph_ToolLineFontPredefined::OwnShared, "Lists the Entities shared by a LineFontPredefined <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESGraph_ToolLineFontPredefined.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &) const) &IGESGraph_ToolLineFontPredefined::OwnCorrect, "Sets automatic unambiguous Correction on a LineFontPredefined (NbPropertyValues forced to 1)", py::arg("ent"));
cls_IGESGraph_ToolLineFontPredefined.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &) const) &IGESGraph_ToolLineFontPredefined::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESGraph_ToolLineFontPredefined.def("OwnCheck", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGraph_ToolLineFontPredefined::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGraph_ToolLineFontPredefined.def("OwnCopy", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, const opencascade::handle<IGESGraph_LineFontPredefined> &, Interface_CopyTool &) const) &IGESGraph_ToolLineFontPredefined::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGraph_ToolLineFontPredefined.def("OwnDump", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGraph_ToolLineFontPredefined::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}