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
#include <IGESBasic_OrderedGroupWithoutBackP.hxx>
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
#include <IGESBasic_ToolOrderedGroupWithoutBackP.hxx>

void bind_IGESBasic_ToolOrderedGroupWithoutBackP(py::module &mod){

py::class_<IGESBasic_ToolOrderedGroupWithoutBackP, std::unique_ptr<IGESBasic_ToolOrderedGroupWithoutBackP, Deleter<IGESBasic_ToolOrderedGroupWithoutBackP>>> cls_IGESBasic_ToolOrderedGroupWithoutBackP(mod, "IGESBasic_ToolOrderedGroupWithoutBackP", "Tool to work on a OrderedGroupWithoutBackP. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def(py::init<>());

// Fields

// Methods
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("ReadOwnParams", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("WriteOwnParams", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, IGESData_IGESWriter &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnShared", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, Interface_EntityIterator &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnShared, "Lists the Entities shared by a OrderedGroupWithoutBackP <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnCorrect, "Sets automatic unambiguous Correction on an OrderedGroupWithoutBackP (Null Elements are removed from list)", py::arg("ent"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnCheck", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnCopy", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, Interface_CopyTool &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnDump", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}