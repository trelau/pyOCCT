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
#include <IGESDraw_ViewsVisibleWithAttr.hxx>
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
#include <IGESDraw_ToolViewsVisibleWithAttr.hxx>

void bind_IGESDraw_ToolViewsVisibleWithAttr(py::module &mod){

py::class_<IGESDraw_ToolViewsVisibleWithAttr, std::unique_ptr<IGESDraw_ToolViewsVisibleWithAttr, Deleter<IGESDraw_ToolViewsVisibleWithAttr>>> cls_IGESDraw_ToolViewsVisibleWithAttr(mod, "IGESDraw_ToolViewsVisibleWithAttr", "Tool to work on a ViewsVisibleWithAttr. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDraw_ToolViewsVisibleWithAttr.def(py::init<>());

// Fields

// Methods
// cls_IGESDraw_ToolViewsVisibleWithAttr.def_static("operator new_", (void * (*)(size_t)) &IGESDraw_ToolViewsVisibleWithAttr::operator new, "None", py::arg("theSize"));
// cls_IGESDraw_ToolViewsVisibleWithAttr.def_static("operator delete_", (void (*)(void *)) &IGESDraw_ToolViewsVisibleWithAttr::operator delete, "None", py::arg("theAddress"));
// cls_IGESDraw_ToolViewsVisibleWithAttr.def_static("operator new[]_", (void * (*)(size_t)) &IGESDraw_ToolViewsVisibleWithAttr::operator new[], "None", py::arg("theSize"));
// cls_IGESDraw_ToolViewsVisibleWithAttr.def_static("operator delete[]_", (void (*)(void *)) &IGESDraw_ToolViewsVisibleWithAttr::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDraw_ToolViewsVisibleWithAttr.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDraw_ToolViewsVisibleWithAttr::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDraw_ToolViewsVisibleWithAttr.def_static("operator delete_", (void (*)(void *, void *)) &IGESDraw_ToolViewsVisibleWithAttr::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("ReadOwnParams", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDraw_ToolViewsVisibleWithAttr::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("WriteOwnParams", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, IGESData_IGESWriter &) const) &IGESDraw_ToolViewsVisibleWithAttr::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("OwnShared", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, Interface_EntityIterator &) const) &IGESDraw_ToolViewsVisibleWithAttr::OwnShared, "Lists the Entities shared by a ViewsVisibleWithAttr <ent>, from its specific (own) parameters shared not implied, i.e. all but the Displayed Entities", py::arg("ent"), py::arg("iter"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("OwnImplied", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, Interface_EntityIterator &) const) &IGESDraw_ToolViewsVisibleWithAttr::OwnImplied, "Lists the Entities shared by a ViewsVisible <ent>, from its specific (own) implied parameters : the Displayed Entities", py::arg("ent"), py::arg("iter"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("DirChecker", (IGESData_DirChecker (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &) const) &IGESDraw_ToolViewsVisibleWithAttr::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("OwnCheck", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDraw_ToolViewsVisibleWithAttr::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("OwnCopy", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, Interface_CopyTool &) const) &IGESDraw_ToolViewsVisibleWithAttr::OwnCopy, "Copies Specific Parameters shared not implied, i.e. all but the Displayed Entities", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("OwnRenew", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, const Interface_CopyTool &) const) &IGESDraw_ToolViewsVisibleWithAttr::OwnRenew, "Copies Specific implied Parameters : the Displayed Entities which have already been copied", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("OwnWhenDelete", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &) const) &IGESDraw_ToolViewsVisibleWithAttr::OwnWhenDelete, "Clears specific implied parameters, which cause looping structures; required for deletion", py::arg("ent"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("OwnDump", (void (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDraw_ToolViewsVisibleWithAttr::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESDraw_ToolViewsVisibleWithAttr.def("OwnCorrect", (Standard_Boolean (IGESDraw_ToolViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_ViewsVisibleWithAttr> &) const) &IGESDraw_ToolViewsVisibleWithAttr::OwnCorrect, "Sets automatic unambiguous Correction on a ViewsVisibleWithAttr (all displayed entities must refer to <ent> in directory part, else the list is cleared)", py::arg("ent"));

// Enums

}