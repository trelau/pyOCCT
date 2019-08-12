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
#include <IGESDimen_GeneralSymbol.hxx>
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
#include <IGESDimen_ToolGeneralSymbol.hxx>

void bind_IGESDimen_ToolGeneralSymbol(py::module &mod){

py::class_<IGESDimen_ToolGeneralSymbol, std::unique_ptr<IGESDimen_ToolGeneralSymbol, Deleter<IGESDimen_ToolGeneralSymbol>>> cls_IGESDimen_ToolGeneralSymbol(mod, "IGESDimen_ToolGeneralSymbol", "Tool to work on a GeneralSymbol. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolGeneralSymbol.def(py::init<>());

// Fields

// Methods
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolGeneralSymbol::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolGeneralSymbol::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolGeneralSymbol::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolGeneralSymbol::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolGeneralSymbol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolGeneralSymbol::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolGeneralSymbol.def("ReadOwnParams", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolGeneralSymbol::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolGeneralSymbol.def("WriteOwnParams", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, IGESData_IGESWriter &) const) &IGESDimen_ToolGeneralSymbol::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolGeneralSymbol.def("OwnShared", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, Interface_EntityIterator &) const) &IGESDimen_ToolGeneralSymbol::OwnShared, "Lists the Entities shared by a GeneralSymbol <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolGeneralSymbol.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &) const) &IGESDimen_ToolGeneralSymbol::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolGeneralSymbol.def("OwnCheck", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolGeneralSymbol::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolGeneralSymbol.def("OwnCopy", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, const opencascade::handle<IGESDimen_GeneralSymbol> &, Interface_CopyTool &) const) &IGESDimen_ToolGeneralSymbol::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolGeneralSymbol.def("OwnDump", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolGeneralSymbol::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}