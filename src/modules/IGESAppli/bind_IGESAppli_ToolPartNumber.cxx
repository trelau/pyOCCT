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
#include <IGESAppli_PartNumber.hxx>
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
#include <IGESAppli_ToolPartNumber.hxx>

void bind_IGESAppli_ToolPartNumber(py::module &mod){

py::class_<IGESAppli_ToolPartNumber, std::unique_ptr<IGESAppli_ToolPartNumber, Deleter<IGESAppli_ToolPartNumber>>> cls_IGESAppli_ToolPartNumber(mod, "IGESAppli_ToolPartNumber", "Tool to work on a PartNumber. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESAppli_ToolPartNumber.def(py::init<>());

// Fields

// Methods
// cls_IGESAppli_ToolPartNumber.def_static("operator new_", (void * (*)(size_t)) &IGESAppli_ToolPartNumber::operator new, "None", py::arg("theSize"));
// cls_IGESAppli_ToolPartNumber.def_static("operator delete_", (void (*)(void *)) &IGESAppli_ToolPartNumber::operator delete, "None", py::arg("theAddress"));
// cls_IGESAppli_ToolPartNumber.def_static("operator new[]_", (void * (*)(size_t)) &IGESAppli_ToolPartNumber::operator new[], "None", py::arg("theSize"));
// cls_IGESAppli_ToolPartNumber.def_static("operator delete[]_", (void (*)(void *)) &IGESAppli_ToolPartNumber::operator delete[], "None", py::arg("theAddress"));
// cls_IGESAppli_ToolPartNumber.def_static("operator new_", (void * (*)(size_t, void *)) &IGESAppli_ToolPartNumber::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESAppli_ToolPartNumber.def_static("operator delete_", (void (*)(void *, void *)) &IGESAppli_ToolPartNumber::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESAppli_ToolPartNumber.def("ReadOwnParams", (void (IGESAppli_ToolPartNumber::*)(const opencascade::handle<IGESAppli_PartNumber> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESAppli_ToolPartNumber::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESAppli_ToolPartNumber.def("WriteOwnParams", (void (IGESAppli_ToolPartNumber::*)(const opencascade::handle<IGESAppli_PartNumber> &, IGESData_IGESWriter &) const) &IGESAppli_ToolPartNumber::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESAppli_ToolPartNumber.def("OwnShared", (void (IGESAppli_ToolPartNumber::*)(const opencascade::handle<IGESAppli_PartNumber> &, Interface_EntityIterator &) const) &IGESAppli_ToolPartNumber::OwnShared, "Lists the Entities shared by a PartNumber <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESAppli_ToolPartNumber.def("OwnCorrect", (Standard_Boolean (IGESAppli_ToolPartNumber::*)(const opencascade::handle<IGESAppli_PartNumber> &) const) &IGESAppli_ToolPartNumber::OwnCorrect, "Sets automatic unambiguous Correction on a PartNumber (NbPropertyValues forced to 4)", py::arg("ent"));
cls_IGESAppli_ToolPartNumber.def("DirChecker", (IGESData_DirChecker (IGESAppli_ToolPartNumber::*)(const opencascade::handle<IGESAppli_PartNumber> &) const) &IGESAppli_ToolPartNumber::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESAppli_ToolPartNumber.def("OwnCheck", (void (IGESAppli_ToolPartNumber::*)(const opencascade::handle<IGESAppli_PartNumber> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESAppli_ToolPartNumber::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESAppli_ToolPartNumber.def("OwnCopy", (void (IGESAppli_ToolPartNumber::*)(const opencascade::handle<IGESAppli_PartNumber> &, const opencascade::handle<IGESAppli_PartNumber> &, Interface_CopyTool &) const) &IGESAppli_ToolPartNumber::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESAppli_ToolPartNumber.def("OwnDump", (void (IGESAppli_ToolPartNumber::*)(const opencascade::handle<IGESAppli_PartNumber> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESAppli_ToolPartNumber::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}